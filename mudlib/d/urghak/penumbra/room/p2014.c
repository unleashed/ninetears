#include "../path.h"

inherit ROOM+"segundonivel.c";

void setup()
{
  add_property("luz_real",50);
  set_short("Segundo nivel de Penumbra: T�nel central");
  set_long("Segundo nivel de Penumbra: T�nel central\n\n"
  "     El t�nel principal del segundo nivel es mucho m�s ruidoso y "
  "ajetreado que el primero, pues es el nivel con mayor actividad "
  "comercial que hay. Las salas y cuevas de tribus se mezclan ahora "
  "con las tiendas de goblins y mercaderes duergars, que luchan por "
  "obtener mayores clientes y beneficios.\n\n");
  add_exit("sudeste", ROOM+"p2013.c", "path");
  add_exit("oeste", ROOM+"p2015.c", "path");  
  if (!random(4)) add_clone(NPC+"mercaderduergar.c",1);
  if (!random(3)) add_clone(NPC+"misc1ernivel.c",random(3)+1);
  set_zone("penumbra_tp");
}