#include "../path.h"
inherit "/std/room";
void setup()
{
  set_short("Gremio de %^ORANGE%^Brujos%^RESET%^: Primer Circulo%^RESET%^");
  set_long("Gremio de %^ORANGE%^Brujos%^RESET%^: Primer Circulo%^RESET%^\n\n"
           "Te encuentras en el primer piso de la Torre de los Brujos de "
           "Urghak. El circulo exterior del gremio es usado para diversas funciones. "
           "Puedes ver a diversos eruditos debatiendo y estudiando en mesas y estudios "
           "dispuestos a lo largo de todo el circulo. Tambien observas lugares donde "
           "se han realizado todo tipo de rituales. "
           "Las paredes y el suelo parecen estar formados "
           "de oro, pero cuando te acercas descubres que tan solo es madera "
           "dotada de alguna cualidad magica que le da esta curiosa apariencia.\n");
  set_light (50);
  set_exit_color("orange");
  add_exit("noroeste", GREMIO+"piso1_7.c", "corridor");
  add_exit("noreste", GREMIO+"piso1_9.c", "corridor");
  add_exit("norte", GREMIO+"piso1_4.c", "corridor");
  add_exit("abajo", GREMIO+"entrada.c", "stair");
}
