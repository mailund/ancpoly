
#include "sampling.h"
#include "stdio.h"

void sample_frequencies(frequencies_t tree,
                        branch_lengths_t mutation_branch_lengths,
                        branch_lengths_t drift_branch_lengths)
{
    for (unsigned int node = 0; node < NO_NODES; ++node) {
        for (unsigned int variant = 0; variant < NO_VARIANTS; ++variant) {
            tree[NODE_VARIANT_INDEX(node, variant)] = (double)node;
        }
    }
}
