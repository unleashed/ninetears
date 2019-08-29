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
           "dotada de alguna cualidad magica que le da esta curiosa apariencia. "
           "Observas una escalera que conduce a otro piso.\n");
  set_light (50);
  set_exit_color("orange");
  add_exit("sudoeste", GREMIO+"piso1_13.c", "corridor");
  add_exit("sudeste", GREMIO+"piso1_11.c", "corridor");
  add_exit("sur", GREMIO+"piso1_2.c", "corridor");
  add_exit("arriba", GREMIO+"piso2_1.c", "stair");
}
