// Sinister Abril 2000

#include "path.h"
inherit "/std/underground";
void setup() {
   set_light(20);
   set_short("Calle de la %^BOLD%^%^RED%^Sangre%^RESET%^");
   set_long(":P\n");
   
   add_exit("norte",CIUDAD"ci_17","path");
   add_exit("sudeste",CIUDAD"ci_19","path");
      
}
