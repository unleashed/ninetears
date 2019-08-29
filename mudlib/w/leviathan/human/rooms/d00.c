#include "path.h"
inherit "/std/outside";
void setup()
{
    add_property("no_undead",1);
    set_light(LIGHT);
   set_short("Isla de Havmand: Embarcadero.");
   set_long("\nIsla de Havmand : Embarcadero\n\n"
    "Originalmente, este discreto embarcadero de madera fue usado para la carga "
    "y descarga de materiales para el castillo y su poblado, pero ha estado "
    "en desuso por mucho tiempo. Muchas de sus tablas estan podridas y en varias "
    "zonas ni siquiera queda rastro de ellas. "
    "\n\n");
    set_night_long("\n   Isla de Havmand: Embarcadero.\n"
    "Tus pisadas resuenan secamente sobre las tablas de madera de este pequenyo "
    "embarcadero, pero debes tener cuidado de no pisar en alguna zona donde la madera "
    "esta quebradiza o en el hueco donde no quedan ni tablas siquiera. El agua, "
    "abajo, destellea suavemente. "
    "\n\n");
    add_item(({"tabla","tablas"}),"Largas tablas de madera usadas como placas del piso en la "
    "construccion de este embarcadero, muchas de ellas estan rotas.\n");
    add_item("agua","El agua,de un azul profundo, lame los postes del embarcadero.\n");
    add_smell("aire","El aire es de un olor salado.\n");
    add_item("embarcadero","Esta hecho de tablas y postes de madera.\n");
    add_sound("pisadas","Tus pisadas resuenan en las tablas de madera.\n");

}
void init()
{
    add_exit("este",HAVMAND+"t01.c","path");

    ::init();
}
