#include "../path.h"

inherit ROOM+"primernivel.c";

void setup()
{
  add_property("luz_real",60);
  set_short("Primer nivel de Penumbra: Salas de la Guerra");
  set_long("Primer nivel de Penumbra: Salas de la Guerra\n\n"
  "     Las Salas de la Guerra son el principal sistema de "
  "organizaci�n de la defensa de la ciudad. Aqu� son entrenados "
  "los guerreros goblinoides desde el principio, y donde los grandes "
  "caciques de la guerra se reunen para debatir temas de "
  "importancia. Este complejo de cavernas es de forma oval, "
  "con multitud de peque�as salas donde entrenan multitud "
  "de goblins, hobgoblins y gnolls.\n");
  if (!random(6)) add_clone(NPC+"misc1ernivel.c",random(3));  
  if (!random(3)) add_clone(NPC+"entrenador.c",random(2)+1);  
  add_exit("norte", ROOM+"b1006.c", "path");
  add_exit("sudoeste", ROOM+"b1008.c", "path");
  set_zone("penumbra_sg");
}