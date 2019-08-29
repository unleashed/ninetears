#include "/obj/vegetation/tree.h"
#define TYPE "pine"
#define SPECIES "white pine"
#define TYPE_PLURAL "pine trees"
#define SPECIES_PLURAL "white pine trees"
/* NB : all the ages are by default defined in 'tree.h' */
#define LEAF_INDEX 300
#define FRUIT_INDEX 5
#define FRUIT_NAME "cone"
#define FRUIT_PLURAL "cones"
#define MY_NAME "/obj/vegetation/pine"
#define MAX_PLANTS 60

#undef ADJECTIVE_LIST
#define ADJECTIVE_LIST ({ "pine", "white" })
#include "/obj/vegetation/basic.c"
