// Sinister Abril 2000

#include "path.h"
inherit "/std/underground";
void setup() {
   set_light(20);
   set_short("Anillo de los %^BOLD%^%^RED%^Condenados%^RESET%^");
   set_long(":P\n");
   
   add_exit("norte",ANILLO"an_81","path");
   add_exit("sur",ANILLO"an_79","path");
add_exit("este",CIUDAD"ci_40","path");
      
}
