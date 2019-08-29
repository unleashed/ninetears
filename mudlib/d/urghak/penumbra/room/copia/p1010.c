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
  "tribus. Desde el noreste se oyen gritos y el entrechocar de "
  "los filos de las espadas.\n\n");
  add_item("grieta","La Grieta Eterna... un profundo abismo sin fin "
  "conocido.\n");
  add_exit("noroeste", ROOM+"p1009.c", "path");
  add_exit("este", ROOM+"p1011.c", "path");  
  add_exit("noreste", ROOM+"b1000.c", "path");  
  add_clone(NPC+"esclavo.c",random(3));
  if (random(100) > 30) add_clone(NPC+"misc1ernivel.c",random(3));
}
