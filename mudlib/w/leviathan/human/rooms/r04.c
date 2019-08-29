#include "path.h"
inherit HAVMAND+"rock.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Rocks\n\n"
    "   Las rocas afiladas te recuerdan que esta isla fue una vez un volcan en "
    "activo. Al sur esta la agradable playa de arena blanca, y al norte y al este "
    "solo hay mar. Una estrella marina reposa en un hueco de la roca lleno de agua, "
    "y hay montones de crustaceos aferrandose a las rocas. "
    "\n\n");
    add_item("estrella","Una pequenya estrella con sus cinco apendices reposa en su piscinita particular.\n");
    add_item("hueco","Es un pequenyo hueco en la roca lleno de agua marina "
    "que se renueva cuando una ola se estrella con mas fuerza de la habitual.\n");
    add_item("crustaceos","Mejillones, berberechos, bigaros....\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"r03.c","path");
    add_exit("sur",HAVMAND+"b01.c","path");

    ::init();
}
