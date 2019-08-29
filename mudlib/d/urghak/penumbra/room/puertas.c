inherit "/std/suboscuridad.c";

#include "../path.h"

void setup()
{
  add_property("luz_real",50);
  set_short("Entrada a Penumbra: Gran Puerta de la Conquista");
  set_long("Entrada a Penumbra: Gran Puerta de la Conquista\n\n"
  "     El mayor orgullo de los goblins durante el periodo de conquista "
  "de la antigua ciudad enana fue la completa destrucci�n de las Antiguas "
  "Puertas de Acero. La culminaci�n de la manufactura del acero de los enanos "
  "acab� completamente destrozada, y fue posteriormente reconstruida por "
  "los goblins: Dos enormes puertas de obsidiana con infinitos detalles y "
  "grabados que recuerdan la gran victoria frente a los enanos.\n\n");
  add_item("grabados","Multitud de grabados muestran la cruel victoria "
  "sobre las filas enanas.\n");
  add_clone(NPC+"hobgoblinelite",2);
  add_clone(NPC+"ogro",1);
  add_exit("este", ROOM+"tunel008.c", "path");
  add_exit("oeste", ROOM+"tunel010.c", "path");  
}
