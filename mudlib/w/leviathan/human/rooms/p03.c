#include "path.h"
inherit HAVMAND+"pirate.c";
void setup()
{
    
   set_light(LIGHT);
    set_short("Isla de Havmand: Campamento Pirata.\n");
    set_long("\nIsla de Havmand: Campamento Pirata.\n"
    "   Estas en el centro del campamento pirata. Hay una gran fogata en el "
    "medio del claro con unas cuantas rocas en circulo rodeandola. Huesos , "
    "botellas vacias y otras basuras estan esparcidos por todo el suelo, es "
    "un sitio desordenado y sucio. "
    "\n\n");
    add_item(({"fuego","fogata"}),"Un amplio circulo de rocas ennegrecidas con "
    "ascuas ardiendo en el centro. Los piratas cocinan aqui su comida, y tienen "
    "sus tertulias en las horas mas frias.\n");
    add_item("huesos","Los huesos de los animales que comen los piratas, simplemente "
    "los tiran cuando ya se han comido la carne. Seria mas higienico si al menos "
    "los hecharan al fuego.\n");
    add_item("botellas","Botellas, ya vacias del alcohol tan apreciado por los piratas.\n");
    add_item(({"roca","rocas"}),"Son rocas colocadas en circulo rodenado la hoguera"
    ".\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"p02.c","path");
    add_exit("sur",HAVMAND+"p04.c","path");
    add_exit("noreste",HAVMAND+"p01.c","path");
    add_exit("sudeste",HAVMAND+"p05.c","path");

   ::init();

}
