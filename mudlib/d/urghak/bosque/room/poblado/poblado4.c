// Xerxes '02

#include "../../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^BOLD%^Atalayas %^BLACK%^de %^GREEN%^Urghak%^RESET%^");
   set_long("%^BOLD%^Atalayas %^BLACK%^de %^GREEN%^Urghak%^RESET%^\n\n"
            "Las atalayas de Urghak son la unica baza defensiva del poblado "
            "de Urghak. La estructura esta compuesta por dos torres de vigia "
            "desde las que se informa de los posibles avances de enemigos y "
            "por un porton. Toda esta estructura se aprovecha de la particular "
            "configuracion del terrero, que se eleva formando una pendiente "
            "escarpada, por lo que ni siquiera es necesario el uso de murallas "
            "para complementar la defensa. El -posible- unico punto debil es "
            "el porton, que no parece ser muy resistente.\n");
   set_light(80);

   add_exit("oeste", POBLADO + "poblado5.c", "path");
   add_exit("este", POBLADO + "poblado3.c", "path");
   add_exit("norte", POBLADO + "poblado13.c", "path");
   add_exit("sur", POBLADO + "poblado8.c", "path");
      
   set_zone("bosque_urghak");
}