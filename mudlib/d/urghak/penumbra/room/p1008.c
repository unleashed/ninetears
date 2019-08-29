inherit "/d/urghak/penumbra/room/primernivel.c";

#include "../path.h"

void setup()
{
  add_property("luz_real",50);
  set_short("Primer nivel de Penumbra: T�nel central");
  set_long("Primer nivel de Penumbra: T�nel central\n\n"
  "     El t�nel principal une todo el entramado de cavernas y grutas "
  "de Penumbra. Se trata de un t�nel que recorre la monta�a de noroeste "
  "a sudeste, y que obtiene esta forma a ra�z de estar bordeando la "
  "Grieta Eterna. Existen numerosas salidas a lo largo del t�nel que dan "
  "con cuevas y propiedades particulares, en las que residen clanes y "
  "tribus. Una escalera desciende al segundo nivel.\n\n");
  add_item("grieta","La Grieta Eterna... un profundo abismo sin fin "
  "conocido.\n");
  add_exit("oeste", ROOM+"p1007.c", "path");
  add_exit("sur", ROOM+"p1009.c", "path");  
  add_exit("abajo", ROOM+"p2018.c", "stairs");  
  if (random(100) > 30) add_clone(NPC+"misc1ernivel.c",random(3));
}