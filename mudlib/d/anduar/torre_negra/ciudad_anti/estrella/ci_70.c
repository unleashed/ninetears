// Sinister Abril 2000

#include "path.h"
inherit "/std/underground";
void setup() {
   set_light(20);
   set_short("Calle de la Noche");
   set_long(":P\n");
   
   add_exit("noreste",CIUDAD"ci_69","path");
   add_exit("sudoeste",CIUDAD"ci_71","path");
      
}
