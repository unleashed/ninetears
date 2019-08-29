inherit "/std/suboscuridad.c";

#include "../path.h"

void setup()
{
  add_property("luz_real",50);
  set_short("Entrada a Penumbra: Escaleras hacia el Primer Nivel");
  set_long("Entrada a Penumbra: Escaleras hacia el Primer Nivel\n\n"
  "     Escondidas tras las enormes puertas se encuentran es "
  "de la antigua ciudad enana fue la completa destrucci�n de las Antiguas "
  "Puertas de Acero. La culminaci�n de la manufactura del acero de los enanos "
  "acab� completamente destrozada, y fue posteriormente reconstruida por "
  "los goblins: Dos enormes puertas de obsidiana con infinitos detalles y "
  "grabados que recuerdan la gran victoria frente a los enanos.\n\n");
  add_item("grabados","Multitud de grabados muestran la cruel victoria "
  "sobre las filas enanas.\n");
  add_exit("este", ROOM+"puertas.c", "path");
  add_exit("abajo", ROOM+"p1001.c", "path");  
}