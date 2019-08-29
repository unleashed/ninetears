#include "../path.h"
inherit "/std/room";
void setup()
{
  set_short("Entrada a la Torre de %^ORANGE%^Brujos%^RESET%^");
  set_long("Entrada a la Torre de %^ORANGE%^Brujos%^RESET%^\n\n"
      "Las dos puertas que protegen la Torre de los Brujos de cualquier posible "
      "indeseable miden casi 3 metros, y parecen estar empotradas en la misma "
      "pared. Al echarte atras y observar la torre, observas lo dificil que es "
      "distinguir los primeros pisos con el tronco de un arbol marchito, "
      "por su color marron y la forma de corteza de las paredes. "
      "Levantando mas tu mirada, observas los pisos superiores, en los que la torre"
      "esta hecha de un siniestro metal oscuro.\n");
  set_light (50);
  set_exit_color("orange");
  add_exit("arriba", GREMIO+"piso1_8.c", "stair");
  add_clone(NPC+"brujo_guardian.c",2);
}
