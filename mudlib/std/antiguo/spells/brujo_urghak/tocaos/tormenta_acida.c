#include <spells.h>
inherit BASES+"area";

void create()
{
  NOMBRE	= "Tormenta acida";
  NIVEL		= 7;
  RES = TIPO 	= "acid";
  SIZE_D	= 6;
  MAX_D		= 0;
  CANCION	= "'majos areos corrosiv'";
  ESCUELA	+= ({"elemental agua"});
  ::create();
}
