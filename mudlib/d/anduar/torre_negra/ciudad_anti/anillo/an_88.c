// Sinister Abril 2000

#include "path.h"
inherit "/std/underground";
void setup() {
   set_light(20);
   set_short("Anillo de los %^BOLD%^%^RED%^Condenados%^RESET%^");
   set_long(":P\n");
   
   add_exit("este",ANILLO"an_89","path");
   add_exit("sur",ANILLO"an_87","path");
      
}
