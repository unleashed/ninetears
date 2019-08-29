#include "../path.h"

inherit ROOM+"primernivel.c";

void setup()
{
  add_property("luz_real",60);
  set_exit_color("red");
  set_short("Puente sobre la %^BLACK%^BOLD%^Grieta Eterna%^RESET%^");
  set_long("Puente sobre la %^BLACK%^BOLD%^Grieta Eterna%^RESET%^\n\n"
  "     La Grieta Eterna es un profundo abismo que recorre la ciudad "
  "de noroeste a sudeste, y sobre cuyas cavernas adyacentes fue "
  "construida la misma. Se la llama Eterna porque, realmente, nadie "
  "ha conocido jam�s el fondo de la grieta, pese a que muchos han "
  "acabado muertos all�. En realidad, son dos puentes los que unen "
  "estas dos zonas de la ciudad, el oriental y el occidental.\n");
  add_exit("noreste", ROOM+"pt004.c", "path");
  add_exit("sudoeste", ROOM+"pt002.c", "path");
  if (!random(5)) add_clone(NPC+"misc1ernivel.c",random(3)+1);  
  set_zone("penumbra_tp");
}