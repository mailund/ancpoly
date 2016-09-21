/*
 * freq-sampler.c
 *
 * Samples allele frequencies over a tree from a WF with mutations model.
 * Writes the sampled frequencies to file to be handled by the inference
 * program.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include "trees.h"
#include "sampling.h"
#include "io.h"

/* ---- OPTION PARSING -------------------------------------------------- */
const char *argp_program_version = "ancpoly_sample_freqs 0.1";
static char doc[] =
"Program for sampling a number of trees with allele frequencies in \
inner nodes.";

/* The options we understand. */
static struct argp_option options[] = {
  {"no_samples",  'n', "N",    0,  "Number of samples to make (default 1000)." },
  {"output",      'o', "FILE", 0,  "Output to FILE instead of standard output" },
  { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
  int no_samples;
  char *output_file;
};

/* Parse a single option. */
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
  /* Get the input argument from argp_parse, which we
     know is a pointer to our arguments structure. */
  struct arguments *arguments = state->input;

  switch (key)
    {
    case 'n':
      arguments->no_samples = atoi(arg);
      break;
    case 'o':
      arguments->output_file = arg;
      break;

    /* FIXME: handle model parameter input. */

    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

static struct argp argp = { options, parse_opt, 0, doc };
/* ---- OPTION PARSING DONE --------------------------------------------- */

int main(int argc, char *argv[])
{
    struct arguments arguments;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    // We sample into this tree and write it out.
    frequencies_t tree;

    // Parse options.
    unsigned int no_samples = 1000;
    if (arguments.no_samples > 0) no_samples = arguments.no_samples;

    FILE *output = stdout;
    if (arguments.output_file) {
        output = fopen(arguments.output_file, "w");
        if (!output) {
          fprintf(stderr, "Could not open file %s for writing.\n",
                  arguments.output_file);
          exit(1);
        }
    }

    // FIXME: figure out how to set these; as options or from a file.
    branch_lengths_t mutation_branch_lengths;
    branch_lengths_t drift_branch_lengths;

    // Now sample the frequencies over the tree...
    for (unsigned int i = 0; i < no_samples; ++i) {
        sample_frequencies(tree, mutation_branch_lengths, drift_branch_lengths);
        write_frequencies(output, tree);
    }

    if (output != stdout) {
        fclose(output);
    }

    return 0;
}
