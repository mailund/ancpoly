/*
 * freq-sampler.c
 *
 * Samples allele frequencies over a tree from a WF with mutations model.
 * Writes the sampled frequencies to file to be handled by the inference
 * program.
 *
 */

#include <stdio.h>
#include "trees.h"
#include "sampling.h"
#include "io.h"

int main(int argc, const char * argv[])
{
    // We sample into this tree and write it out.
    frequencies_t tree;

    // Parse options.
    unsigned int no_samples = 10;             // FIXME
    branch_lengths_t mutation_branch_lengths; // FIXME
    branch_lengths_t drift_branch_lengths;    // FIXME
    FILE *output = fopen("test.txt", "w");    // FIXME

    for (unsigned int i = 0; i < no_samples; ++i) {
        sample_frequencies(tree, mutation_branch_lengths, drift_branch_lengths);
        write_frequencies(output, tree);
    }

    fclose(output);

    return 0;
}
