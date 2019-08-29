// Made by Kivara  17/10/2002

#include "path.h"
inherit SUB4+"sub4_main2.c";
void setup() {

  do_desc(1,1);
add_exit("noroeste",SUB4+ "Sub4_3.c","standard");
add_exit("este",SUB4+ "Sub4_8.c","standard");
add_exit("sudeste",SUB4+ "Sub4_16.c","standard");
}
