// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, Por fin llegas a la entrada del "
   "puente una autentica obra maestra, con runas magicas de origen "
   "desconocido, de una antiguedad tal que nadie recuerda su origen, y los "
   "elfos que pasan por el dicen que las leyendas hablaban de un puente, "
   "anterior a este mundo, de una vida anterior a esta en las cuales inmensas "
   "criaturas que empequenyecian a los mas grandes dragones sobrevolaban el "
   "cielo.");
   add_exit("noreste"   ,REAL"real28.c","road");
   add_exit("oeste"     ,REAL"real26.c","road");
   set_light(65);
   crea_bichos();
}