// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Tras volver a cambiar de direccion "
   "observas como a los lados del camino hay 3 gigantescas estatuas de unos "
   "Trolls, quizas sean trolls, pero nunca nadie ha oido hablar de trolls "
  "fuera de Golthur, asi que lo mas seguro que sean estatuas.");
   add_exit("este"   ,REAL"real42.c","road");
   add_exit("southwest"     ,REAL"real40.c","road");
   set_light(65);
   crea_bichos();
}
