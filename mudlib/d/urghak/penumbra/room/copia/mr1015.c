#include "../path.h"

inherit ROOM+"segundonivel.c";

void setup()
{
  add_property("luz_real",50);
  set_short("Segundo nivel de Penumbra: Calle de la Discordia");
  set_long("Segundo nivel de Penumbra: Calle de la Discordia\n\n"
  "     La calle de la Discordia m�s bien podr�a ser llamada callej�n. "
  "Corre paralela al t�nel central del segundo nivel de la ciudad, "
  "y en su mayor�a est� compuesta de salas comerciales. La mayor�a "
  "de los que paran por aqu� son mercaderes y comerciantes, tanto "
  "duergar como goblinoides.\n\n");
  add_exit("noroeste", ROOM+"p2010.c", "path");  
  add_exit("sudoeste", ROOM+"mr1004.c", "path");  
  if (!random(4)) add_clone(NPC+"mercaderduergar.c",random(2)+1);
  if (!random(3)) add_clone(NPC+"misc1ernivel.c",random(2)+1);
  set_zone("penumbra_tp");
}