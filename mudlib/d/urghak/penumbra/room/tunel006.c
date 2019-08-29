inherit "/std/suboscuridad.c";

#include "../path.h"

void setup()
{
  add_property("luz_real",50);
  set_short("Tuneles hacia Penumbra");
  set_long("Tuneles hacia Penumbra\n\n     Estos antiguos tuneles "
  "conducen a la ciudad de los goblins, Penumbra. Fueron excavados "
  "anta�o por los enanos, y ahora han sido convertidos en una "
  "grotesca burla de lo que fueron. Los pilares que sostienen el "
  "tunel y que antes eran de reluciente marmol ahora estan cubiertos "
  "por una espesa capa de suciedad y mugre, seguramente mezclada con "
  "la sangre que normalmente se vierte en una sociedad como la de "
  "Penumbra.\n\n");
  add_exit("este", ROOM+"tunel005.c", "path");
  add_exit("oeste", ROOM+"tunel007.c", "path");  
}