//Room b�sica para el ayuntamiento de Faeleen, para hacer las pruebas pertinentes

#include "../../path.h"
inherit "/std/room.c";

setup()
{
   set_short("%^BOLD%^%^BLUE%^Ayuntamiento de Faeleen%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^Ayuntamiento de Faeleen%^RESET%^ \n\n"
            "	Este �s el ayuntamiento provisional de la ciudad de Faeleen. Esta a la espera de "
            "ampliacion, pero deberia contener todos los elementos esenciales de cualquier ayuntamiento"
            " del continente.\n\n");
   add_exit("fuera",CIUDAD"cnorte_0.c","door");
}