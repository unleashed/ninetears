// Made by Vulvac 09/11/02

inherit "/std/suboscuridad.c";
#include "../path.h"
void setup() {
set_zone("cultivos");
set_exit_color("green");
set_light(30);	
set_short("%^ORANGE%^Caseta de recoleccion abandonada%^RESET%^");

set_long("\n%^ORANGE%^Caseta de recoleccion abandonada%^RESET%^.\n\nEsta caseta es la tipica casita que se usa de almacen en los cultivos. Ves que el suelo esta sucio. Unicamente ves un gran saco contra una de las paredes. Puedes ver como un guardia vigila atentamente los sacos de viveres. Empiezas a deducir que esta es una de las pocas fuentes de alimentos que tiene la gran ciudad de Keroon. Lo unico que diferencia a esta caseta de todas las demas es que esta completamente abandonada. Parece que su servicio en la zona ya no resulta util.\n\n");
add_item("saco","Ves un gran saco contra la pared, es diferente a los demas. Parece que esta colocado de una forma especifica para algun fin en concreto.\n");

add_exit("sudeste" ,CULTIVOS+"cultivo_8.c","standard");

}
void init()
{
::init();
add_action("mover_saco","mover");
}
int mover_saco(string str)
{
if(str=="saco")
{
write("Mueves con gran esfuerzo el saco levantando gran cantidad de polvo. Parece que has encontrado algo. Delante de ti aparece una puerta muy bien camuflada.\n");
say(this_player()->query_cape_name()+" mueve el gran saco levantando polvo.\n");
add_exit("dentro", CULTIVOS+"cultivo_60.c","standard");
renew_exits();
return(1);
}
notify_fail("Mover que?.\n");
return(0);

}