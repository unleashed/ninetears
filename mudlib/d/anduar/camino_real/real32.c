// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En este punto de la calzada observas "
   "como los constructores se tubieron que desviar, una vez mas para esquivar "
   "una extranya construccion monolitica de origen desconocido, que por "
   "alguna razon prefirieron respetar.");
   add_item("construccion","Una extranya construccion monolitica que parece "
   "apuntar a alguna direccion al suroeste");
   add_exit("noroeste"   ,REAL"real33.c","road");
   add_exit("southeast"     ,REAL"real31.c","road");
   set_light(65);
   crea_bichos();
}