#include "path.h"
inherit HAVMAND+"pirate.c";
void setup()
{
    
   set_light(LIGHT);
    set_short("Isla de Havmand: Campamento Pirata.\n");
    set_long("\nIsla de Havmand: Campamento Pirata.\n"
      "   La impenetrable jungla esta al sur, puedes ver varias hamacas "
      "colgando entre algunos arboles. El camino al centro del campamento "
      "esta por el norte y al este ves otra zona del campamento. Esta todo "
      "lleno de basuras, el desorden reina en la plaza. "
    "\n\n");

   add_item("jungla","Montones de arboles creciendo muy apretados unos a otros, sus troncos "
      "ty ramas retorcidas hacen dificil abrirse camino entre ellos. \n");

   add_item("hamacas","Filas de hamacas cuelgan amarradas a los arboles. Su aspecto, "
      "aunque confortable, tambien es de fragilidad y no te atreves a probarlas.\n");

   add_item("basura","Restos de comida, trozos de ropas viejas, botellas vacias, y porquerias "
      "varias estan esparcidas por el suelo, los piratas no parecen gente muy limpia. \n");

}
void init()
{
    add_exit("oeste",HAVMAND+"j18.c","path");
    add_exit("este",HAVMAND+"p05.c","path");
    add_exit("norte",HAVMAND+"p03.c","path");
    add_exit("noroeste",HAVMAND+"p02.c","path");

    ::init();
}
