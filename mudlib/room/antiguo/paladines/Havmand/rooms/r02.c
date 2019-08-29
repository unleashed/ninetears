#include "path.h"
inherit HAVMAND+"rock.c";

void setup()
{
    
    set_long("\nIsla de Havmand : Rocas\n\n"
    "   Las afiladas rocas estan muy mojadas y resbaladizas, te mueves con cuidado "
    "de no dar un traspies. Las olas al chocar contra las rocas crean nubes de miles "
    "de gotitas de agua salada, empapandolo todo. Al norte puedes ver una hermosa "
    "playa de arena blanca. "
    "\n\n");
    add_item("playa","La arena se extiende al norte hasta donde alcanza la vista.\n");

}
void init()
{
    add_exit("oeste",HAVMAND+"r01.c","path");
    add_exit("norte",HAVMAND+"b05.c","path");

    ::init();
}
