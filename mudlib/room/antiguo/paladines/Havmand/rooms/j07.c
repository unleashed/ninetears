#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Jungla\n\n"
    "Estas en una parte de la jungla en la que lo unico que ves son arboles "
    "y mas arboles. El suelo esta lleno de las hojas caidas formando una  "
    "alfombra mullida. "
    "\n\n");
    add_item(({"hojas","hoja"}),"Pilas de hojas caidas se amontonan en el suelo, "
    "No tienen ninguna utilidad, piensas, ademas estan humedas. "
    "\n");
    add_item(({"arbol","arboles"}),"Grandes arboles se elevan ante ti,sus ramas "
    "te impiden mas que retazos del cielo."
    "\n");
}
void init()
{
    add_exit("norte",HAVMAND+"j06.c","path");
    add_exit("sur",HAVMAND+"j09.c","path");
    add_exit("este",HAVMAND+"j08.c","path");
    add_exit("oeste",HAVMAND+"t04.c","path");

    ::init();
}


