// Sinister Abril 2000

#include "path.h"
inherit "/std/underground";
void setup() {
   set_light(20);
   set_short("Calle de la Ira");
   set_long(":P\n");
   
   add_exit("norte",CIUDAD"ci_90","path");
   add_exit("sur",CIUDAD"ci_48","path");
      
}