// Made by Thalos  01/04/02
// Area made with the ASCII Mapmaker
// copyright 1999 by Espen Austad
// www.stud.ux.his.no/~austad/mud/mapmaker
// for more info.

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_exit_color("cyan");
   set_light(50);
   set_short("gg");
   set_long("LONG\n\n");

add_exit("norte",MERCADO+"keroon_194.c","standard");
}
