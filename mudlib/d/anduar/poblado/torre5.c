// Poblado de Eldenar // by Serl
#include "path.h"
inherit "/std/room.c";

void setup()
{
    set_short("%^YELLOW%^Torre de Eldenar: Segundo piso%^RESET%^");
    set_long("\nEste es el segundo piso de la torre de Eldenar. "
         "La decoracion es similar a la del piso inferior pero "
         "aqui parece mas confortable. Hay unas mesas con unos "
         "sillones alrededor, y el suelo esta cubierto por unas "
         "alfombras en tonos rojizos. Hay una escalera que va "
         "hacia arriba y hacia abajo. Parece muy vigilada "
         "esta habitacion.\n");
    add_clone(NPC"guardia.c",4);
    add_exit("abajo",POBLADO"torre4.c","door");
    add_exit("arriba",POBLADO"torre6.c","door");
}
