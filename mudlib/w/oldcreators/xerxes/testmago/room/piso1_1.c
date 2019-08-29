#include "../path.h"
inherit "/std/room";
void setup()
{
  set_short("Gremio de %^ORANGE%^Brujos%^RESET%^: Primer Circulo%^RESET%^");
  set_long("Gremio de %^ORANGE%^Brujos%^RESET%^: Primer Circulo%^RESET%^\n\n"
           "Te encuentras en el primer piso de la Torre de los Brujos de "
           "Urghak. Este pasillo comunica el salon de Aenima con el circulo "
           "exterior del gremio. Las paredes y el suelo parecen estar formados "
           "de oro, pero cuando te acercas descubres que tan solo es madera "
           "dotada de alguna cualidad magica que le da esta curiosa apariencia.\n");
  set_light (50);
  set_exit_color("orange");
  add_exit("arriba", GREMIO+"main.c", "corridor");
  add_exit("norte", GREMIO+"piso1_2.c", "corridor");
  add_exit("este", GREMIO+"piso1_3.c", "corridor");
  add_exit("sur", GREMIO+"piso1_4.c", "corridor");
  add_exit("oeste", GREMIO+"piso1_5.c", "corridor");
}
