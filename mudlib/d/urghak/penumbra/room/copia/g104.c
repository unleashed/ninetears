#include "../path.h"

inherit ROOM+"primernivel.c";

void setup()
{
  add_property("luz_real",50);
  set_short("Primer nivel de Penumbra: %^BOLD%^Puesto de Guardia%^RESET%^");
  set_long("Primer nivel de Penumbra: %^BOLD%^Puesto de Guardia%^RESET%^\n\n"
  "     Esta sala es el hogar de la Guardia de Penumbra. La sobria "
  "decoraci�n de la sala consiste en una gran colecci�n de cabezas "
  "de bandidos, forajidos, ladrones y asesinos. La parte preferida "
  "de la colecci�n de la Guardia es la innumerable cantidad de "
  "cabezas de enanos que resistieron escondidos en las cuevas de "
  "Urghak. Gran multitud de armas, armaduras y escudos est�n "
  "esparcidos y mal colocados por doquier.\n\n");
  add_exit("norte", ROOM+"g102.c", "path");
  set_zone("penumbra_tp");
}