// Xerxes '02

#include "../../path.h"

inherit "/std/outside";

void setup()
{
   set_short("%^ORANGE%^Camino ascendente en la colina%^RESET%^");
   set_long("%^ORANGE%^Camino ascendente en la colina%^RESET%^\n\n"
            "Esta zona del bosque esta libre de la densa vegetacion que "
            "dejas atras, debido a la proximidad de la colina del poblado "
            "de Urghak. El camino, ligeramente cuesta arriba, esta formado, "
            "por ceniza, de la que emergen oscuras plantas.\n");
   set_light(80);
   
   add_item("ceniza","No te atreverias a asegurar que son restos de seres vivos.\n"); 
   
   add_exit("este", POBLADO + "poblado2.c", "path");
   add_exit("oeste", POBLADO + "poblado4.c", "path");

   // add_clone(OBJ + "cabeza.c", 1); No no nooo bad dog BAD DOG!!!
      
   set_zone("bosque_urghak");
}