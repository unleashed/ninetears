#include "../path.h"

inherit ROOM+"segundonivel.c";

void setup()
{
  add_property("luz_real",40);
  set_short("Primer nivel de Penumbra: %^BLACK%^BOLD%^Callej�n de las Sombras%^RESET%^");
  set_long("Primer nivel de Penumbra: %^BLACK%^BOLD%^Callej�n de las Sombras%^RESET%^\n\n"
  "     Este oscuro callej�n es hogar de maleantes y ladrones, y "
  "suele ser un lugar poco aconsejado para quedarse a pasear. Las "
  "paredes y el suelo est�n llenos de basura, sangre y huesos. Todos "
  "cuantos est�n aqu� parecen arder en deseos de matarte, o al menos "
  "de apropiarse de tu bolsa de oro.\n\n");
  add_exit("norte", ROOM+"cs1000.c", "path");  
  add_exit("sudeste", ROOM+"cs1003.c", "path");  
  set_zone("penumbra_cs");
}