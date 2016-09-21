#ifndef trees_h
#define trees_h

/* The tree we are working with is: 
 
   (bonobo,((verus,ellioti),(troglodytes,schweinfurthii)))
 
   which has 9 nodes when leaves are included.

 */
#define NO_NODES 9
#define NO_VARIANTS 4  // we work with single nucleotide variants only for now
#define NODE_VARIANT_INDEX(NODE,VARIANT) ((NODE)*NO_VARIANTS) + (VARIANT)

typedef double frequencies_t[NO_NODES*NO_VARIANTS];

#define NO_BRANCHES 8 // for a rooted tree we have one branch less than the number of nodes
typedef double branch_lengths_t[NO_BRANCHES];


#endif /* trees_h */
