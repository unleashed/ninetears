// Aokromes, Julio de 1999
#include "../path.h"
inherit REAL+"afueras.c";
object tablon;

void setup()
{
   set_short("%^RED%^%^BOLD%^Real Camino de Anduar a Dendara%^RESET%^");
   set_long("Estas en una amplia calzada de 10 metros de ancho que va desde "
   "Anduar a la noble ciudad de Dendara, hacia el este parte la calzada que "
   "se dirige a la noble ciudad de Takome, atravesando el bosque de Orgoth, "
   "hacia el norte se dirige la ruta a Dendara, atravesando multiples campos "
   "velocidad y cada cierto tiempo hay unas curiosas marcas en los lados.\n");
   add_exit("east",CARRETERA+"c2","road");
   add_exit("norte",REAL+"real1.c","road");
   add_exit("sur",ANDUAR+"puerta0013","road");
   set_light(65);
   crea_bichos();
}

void dest_me()
{
   destruye_bichos();
   ::dest_me();
}


void reset()
{
   ::reset();
}

