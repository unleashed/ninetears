// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^ORANGE%^Caseta de recoleccion%^RESET%^");

set_long("\n%^ORANGE%^Caseta de recoleccion%^RESET%^.\n\nEsta caseta es la tipica casita que se usa de almacen en los cultivos. Ves que el suelo esta sucio y lleno de sacos de liquenes y hongos. Puedes ver como un guardia vigila atentamente los sacos de viveres. Empiezas a deducir que esta es una de las pocas fuentes de alimentos que tiene la gran ciudad de Keroon.\n\n");
add_item("saco","Hay unos cuantos sacos de viveres empotrados contra la pared. Para ti no te resultan gran cosa pero parece ser que por esta zona son un bien muy preciado.\n");

add_exit("noreste" ,CULTIVOS+"cultivo_27.c","standard");

}






