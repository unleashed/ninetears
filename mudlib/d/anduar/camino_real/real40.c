// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, En los lindes observas un grupo de "
   "pequenyos arboles de aspecto humanoide, los rumores dicen que son humanos "
   "que desafiaron a un antiguo poder y el mismo como castigo los condeno a "
   "ser arboles por el resto de la eternidad.");
   add_exit("noreste"   ,REAL"real41.c","road");
   add_exit("sur"     ,REAL"real39.c","road");
   set_light(65);
   crea_bichos();
}
