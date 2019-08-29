#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Esta es una senda muy estrecha. No encuentras manera de forzar una via "
    "en ninguna direccion excepto hacia el oeste o el sudoeste.  Miras arriba "
    "y ves un nido en una rama alta de uno de los grandes arboles. "
    "\n\n");
    add_item("nido","Es el nido de una de esas aves que has oido de vez en "
    "cuando en tus incursiones por la jungla. Esta hecho con pequenyas ramitas, "
    "como suele ser lo habitual, esta lo suficientemente alto para estar a salvo "
    "de posibles predadores. "
    "\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"j11.c","path");
    add_exit("sudoeste",HAVMAND+"j13.c","path");

    ::init();
}


