
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

// Read n doubles from input file. Returns 0 if successful and != 0 otherwise.
// FIXME: Better error handling would probably be good here.
static int read_doubles(FILE *input, double *buffer, unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i) {
        int error_code = fscanf(input, "%lf", &buffer[i]);
        if (error_code) return error_code;
    }
    return 0;
}

void read_frequencies(FILE *input, frequencies_t tree)
{
    read_doubles(input, tree, NO_NODES*NO_VARIANTS);
}

