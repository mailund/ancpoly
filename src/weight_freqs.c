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
#include "io.h"

/* ---- OPTION PARSING -------------------------------------------------- */
const char *argp_program_version = "ancpoly_weight_freqs 0.1";
static char doc[] =
"Program for weighing the allele frequencies in inner nodes based on the \
likelihood of allele counts at the leaves.";

/* The options we understand. */
static struct argp_option options[] = {
    {"variants",    'v', "FILE", 0,
        "Input file for variants." },
    {"frequencies", 'f', "FILE", 0,
        "Input file for sampled frequencies." },
    {"output",      'o', "FILE", OPTION_ARG_OPTIONAL,
        "Output to FILE instead of standard output" },
    { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments
{
    char *variants_file;
    char *frequencies_file;
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
        case 'v':
            arguments->variants_file = arg;
            break;
        case 'f':
            arguments->frequencies_file = arg;
            break;
        case 'o':
            arguments->output_file = arg;
            break;
        
        case ARGP_KEY_END:
            if (!(arguments->variants_file && arguments->frequencies_file)) {
                argp_usage(state);
            }
            break;
            
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
    if (!arguments.variants_file) {
        fprintf(stderr, "You must provide a variants file.\n");
        
    }
    FILE *output = stdout;
    if (arguments.output_file) {
        output = fopen(arguments.output_file, "w");
        if (!output) {
            fprintf(stderr, "Could not open file %s for writing.\n",
                    arguments.output_file);
            exit(1);
        }
    }
    
    if (output != stdout) {
        fclose(output);
    }
    
    return 0;
}
