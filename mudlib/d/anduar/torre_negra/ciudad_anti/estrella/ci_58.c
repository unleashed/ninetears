// Sinister Abril 2000

#include "path.h"
inherit "/std/underground";
void setup() {
   set_light(20);
   set_short("Calle de Lameth");
   set_long(":P\n");
   
   add_exit("este",CIUDAD"ci_59","path");
   add_exit("oeste",CIUDAD"ci_57","path");
      
}
