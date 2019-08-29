// Made by Kivara  17/10/2002
  

#include "path.h"
inherit SUB4+"sub4_main2.c";
void setup() {

  do_desc(1,1);
add_exit("noreste",SUB4+ "Sub4_111.c","standard");
add_exit("sur",SUB4+ "Sub4_129.c","standard");
add_exit("sudoeste",SUB4+ "Sub4_128.c","standard");
}
