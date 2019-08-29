inherit "/std/room";
#include "../path.h"

void setup()
{
  add_property("luz_real",50);
  set_exit_color("red");
  set_short("%^RED%^Circulum Vitiosus%^RESET%^");  
  set_long("%^RED%^Circulum Vitiosus%^RESET%^\n\n"
  "     Te encuentras en el coraz�n del Mal, el gremio de los Shamanes. "
  "No sabr�as decir en qu� plano de existencia se localiza este lugar, "
  "pero la intuici�n te dice que en el mismo Plano Abismal. Aqu� se "
  "ense�an las Oscuras Artes de la shamaner�a. Esta habitaci�n posee "
  "una sobr�a decoraci�n, el suelo esta m�gicamente provisto de un "
  "efecto visual que le da el aspecto de agua, o m�s bien de sangre. "
  "Imbuido de la misma magia, el techo se encuentra modificado, de tal "
  "forma que pareces poder ver un hecat�mbico cielo rojizo. Lo �nico "
  "normal de este lugar parecen ser las paredes, que pos�en multitud "
  "de g�ticos y retorcidos grabados, de tanta meticulosidad que no "
  "eres capaz de identificarlos.\n\n");
  
  add_exit("norte", ROOM+"entrada2.c", "corridor");
  
  set_zone("guild_shamanes");
}
