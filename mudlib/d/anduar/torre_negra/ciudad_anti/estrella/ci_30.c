// Sinister Abril 2000

#include "path.h"
inherit "/std/underground";
void setup() {
   set_light(20);
   set_short("Calle de Cain");
   set_long(":P\n");
   
   add_exit("sudeste",CIUDAD"ci_28","path");
   add_exit("noroeste",CIUDAD"ci_31","path");
      
}
