// Poblado de Eldenar // by Serl
#include "path.h"
inherit "/std/room.c";

void setup()
{
    set_short("%^YELLOW%^Torre de Eldenar: Habitacion de Insle%^RESET%^");
    set_long("\nEsta es la habitacion de Insle, Senyor de Eldenar. "
         "Es una habitacion bastante grande, con una cama pegada a "
         "una de las paredes. Otra pared esta llena de armarios y en "
         "el centro de la habitacion una mesa redonda de madera con "
         "unos sillones alrededor. En un rincon de la habitacion hay "
         "un escritorio lleno de papeles y sobres.\n");
    add_clone(NPC"insle.c",1);
    add_exit("abajo",POBLADO"torre5.c","door");
}
