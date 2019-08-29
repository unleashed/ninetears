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
  "ellas se tornan duras como el granito. Qui�n sabe qu� malignas "
  "creaciones esconden. Al sur se encuentra una salida que conduce "
  "a la entrada del gremio.\n\n");
  
  add_exit("sur", ROOM+"entrada1.c", "corridor");
  add_exit("abajo", ROOM+"entrada3.c", "stairs");
  
  // modify_exit("abajo", ({"function", "mareo"}));
  
  set_zone("guild_shamanes");
}

int mareo()
{
  tell_object(TP, "Comienzas a descender por estas infinitas Escaleras, "
  "percatandote de que parecen alargarse cada vez m�s conforme "
  "avanzas.\n");  
  return 1;
}
