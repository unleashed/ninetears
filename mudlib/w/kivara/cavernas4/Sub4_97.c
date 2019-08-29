// Made by Kivara  17/10/2002
// Area made with the ASCII Mapmaker
// copyright 1999 by Espen Austad
// www.stud.ux.his.no/~austad/mud/mapmaker
// for more info.

#include "path.h"
inherit SUB4+"sub4_main3.c";
void setup() {

  do_desc(1,1);
add_exit("noreste",SUB4+ "Sub4_91.c","standard");
add_exit("este",SUB4+ "Sub4_98.c","standard");
}
