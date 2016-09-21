
#include "io.h"

void write_frequencies(FILE *output, frequencies_t tree)
{
    for (unsigned int node = 0; node < NO_NODES; ++node) {
        for (unsigned int variant = 0; variant < NO_VARIANTS; ++variant) {
            fprintf(output, "%f ", tree[NODE_VARIANT_INDEX(node, variant)]);
        }
    }
    fprintf(output, "\n");
}
