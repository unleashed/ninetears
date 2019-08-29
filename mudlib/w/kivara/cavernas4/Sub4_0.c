// Made by Kivara  17/10/2002

#include "path.h" 

inherit SUB4+"sub4_main12.c";

void setup() {

  do_desc(1,1);
add_exit("sudeste",SUB4+ "Sub4_3.c","standard");
add_exit("sudoeste",SUB4+ "Sub4_1.c","standard");
add_exit("kivara","/w/kivara/workroom.c","standard"); //<--a cambiar, claro
}
