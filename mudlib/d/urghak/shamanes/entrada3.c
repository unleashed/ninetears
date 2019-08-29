inherit "/std/room";
#include "../path.h"

void setup()
{
  add_property("luz_real",50);
  set_exit_color("red");
  set_short("%^RED%^Circulum Vitiosus: Escaleras de la Tortura%^RESET%^");  
  set_long("%^RED%^Circulum Vitiosus: Escaleras de la Tortura%^RESET%^\n\n"
  "     Unas enormes escaleras de entrada circular ocupan la mayor�a "
  "del espacio de este lugar. �stas parecen tener vida propia, y te "
  "atrever�as a decir que no son de madera, ni de cemento, sino de "
  "carne viva. Las escaleras se mueven con un hipn�tico vaiv�n, "
  "semejante a la respiraci�n humana, pero cuando pones un pie en "
  "ellas se tornan duras como el granito. No consigues ver donde "
  "acaban las escaleras, pues tus ojos no son capaces de mirar m�s "
  "hacia arriba. Del este emana la mayor aura de malevolencia que "
  "hayas sentido nunca, a la vez aterradora y gratificante.\n\n");
  
  add_exit("arriba", ROOM+"entrada2.c", "corridor");
  add_exit("este", ROOM+"principal.c", "stairs");
  
  // modify_exit("arriba", ({"function", "mareo"}));  
  
  set_zone("guild_shamanes");
}

int mareo()
{
  tell_object(TP, "Comienzas a ascender por estas infinitas Escaleras, "
  "percatandote de que parecen alargarse cada vez m�s conforme "
  "avanzas.\n");  
  return 1;
}
