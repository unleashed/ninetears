#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsla de Havmand : Senda\n\n"
    "Parece que esto es lo mas al sur que se puede llegar por este camino. "
    "Al este esta la inevitable e incomoda jungla. Al oeste puedes ver una puerta "
    "en el muro del castillo, aunque parece no haber sido usada desde hace "
    "mucho mucho tiempo. "
    "\n\n");
    add_item("puerta","No puedes verla bien desde aqui, pero parece de "
    "una madera muy solida con bandas de metal que la refuerzan.\n");

}
void init()
{
    add_exit("norte",HAVMAND+"t08.c","path");
    add_exit("oeste",HAVMAND+"g00.c","path");
    add_exit("este",HAVMAND+"j15.c","path");

    ::init();
}


