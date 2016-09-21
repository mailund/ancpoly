//
//  sampling.h
//  Ancestral Polymorphism
//
//  Created by Thomas Mailund on 06/09/16.
//  Copyright © 2016 Thomas Mailund. All rights reserved.
//

#ifndef sampling_h
#define sampling_h

#include "trees.h"

void sample_frequencies(frequencies_t tree,
                        branch_lengths_t mutation_branch_lengths,
                        branch_lengths_t drift_branch_lengths);

#endif /* sampling_h */
