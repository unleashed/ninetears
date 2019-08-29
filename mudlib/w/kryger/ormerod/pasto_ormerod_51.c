inherit "/std/room.c";
#include "../../path.h"

void setup()
{
	set_short("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Sur%^RESET%^.");
	set_long("%^GREEN%^Pastos: %^RESET%^CYAN%^Zona Sur%^RESET%^.\n\n Estamos en una gran "
	"extension de terreno verde, es ideal para que pasten los animales, "
	"podemos observar un gran rebanyo de ovejas, y una manada de vacas cerca"
	"del rebanyo, hay unos mayorales cuidandolas montados en unos fuertes "
	"caballos.Los pastores llevan perros para poder controlar mejor el rebanyo."
	"Te das cuenta de que estos pastos estan muy transitados por este tipo de "
	"ganado. \n");
	add_property("luz_real",50);
	set_zone("pastos_ormerod");
	add_clone(NPC+"ganadero_ormerod.c",1);
	add_clone(NPC+"ganadera_ormerod.c",1);
	add_exit("norte",ROOMORM"pasto_ormerod_52.c","door");
	add_exit("oeste",ROOMORM"pasto_ormerod_46.c","door");
}