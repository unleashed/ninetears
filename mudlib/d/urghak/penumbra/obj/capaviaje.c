#include "../path.h"

inherit "/obj/armour.c";

void setup()
{
  set_base_armour("capa");
  set_name("capa de viaje");
  set_short("Capa de viaje");
  add_alias(({"capa","viaje"}));
  set_main_plural("Capas de viaje");
  add_plural(({"capas","viajes"}));
  set_long("     Una capa de manufactura Duergar, usada en los viajes "
  "de estos seres debido a su gran resistencia a los elementos hostiles "
  "de la naturaleza. Esta confeccionada con una base de cuero, recubierta "
  "de una lana que no eres capaz de identificar.\n");

}
