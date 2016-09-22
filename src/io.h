#ifndef io_h
#define io_h

#include <stdio.h>
#include "trees.h"

void write_frequencies(FILE *output, frequencies_t tree);
void read_frequencies(FILE *input, frequencies_t tree);


#endif /* io_h */
