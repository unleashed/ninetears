inherit "/std/outside.c";

#include "../path.h"

void setup() {
   add_property("luz_real",80);
   set_short("Acantilado de los Lamentos: Cerca del Bosque");
   set_long("Acantilado de los Lamentos: Cerca del Bosque\n\n"
      "     El bosque se detiene abruptamente para dar paso a los "
      "Acantilados de los Lamentos, llamados as por los "
      "centenarios sonidos de los Galeb-D'hurs, unos animales semejantes a "
      "las cabras que habitan entre los riscos del lugar. Aqu los "
      "caminos son muy peligrosos, debido a su estrechez, y a que "
      "bordean continuamente una pronunciada pendiente. La cada "
      "desde tan alto sera mortal. El camino toma una "
      "pendiente bastante considerable. Hacia el sudoeste, donde "
      "termina la pendiente, se atisba el bosque de Urghak.\n\n");
   add_item("camino","Los caminos son muy, muy estrechos.\n");
   add_item("abajo","Ves todas las llanuras y las cienagas de "
      "Urghak, que se extienden hasta el horizonte.\n");
   add_exit("sur",ACANTILADO+"acantilado003.c","road");
   add_exit("abajo",ACANTILADO+"acantilado005.c","road");
}
