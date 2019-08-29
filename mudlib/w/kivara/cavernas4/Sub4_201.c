// Made by Kivara  17/10/2002
  

#include "path.h"
inherit SUB4+"sub4_main2.c";

void setup() {

  do_desc(1,1);
add_exit("noroeste",SUB4+ "Sub4_180.c","standard");
add_exit("sudoeste",SUB4+ "Sub4_218.c","standard");
}
