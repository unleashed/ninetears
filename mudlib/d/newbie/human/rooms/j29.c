#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The oppressive jungle canopy opens up here, and you can see the sky. "
    "A breeze blows gently through as well, making this area a lot drier "
    "than the thicker jungle below. The sounds of the forest below are "
    "fainter, but another familliar sound is getting stronger. "
    "The small rocks to the northeast have given way to quite substantial "
    "boulders here. "
    "\n\n");
    add_item("boulders",
    "The boulders are a slightly reddish gray apart from "
    "areas where they have been chipped. There, they are a bright "
    "red. "
    "\n");
    add_feel(({"rock","boulders"}),"The boulders are very harsh on your hands "
    "and they crumble slightly as you run your hand over the surface. ");
    add_sound("jungle","The bird sounds from the jungle are fainter, but "
    "clearer here, no longer muffled by the canopy, you can hear individual "
    "bird songs. "
    "\n");
    add_sound(({"familliar","sea","air","all"}),"You can hear the sound of pounding "
    "surf faintly as it's brought to you on the breeze. "
    "\n");
    add_feel(({"breeze","air"}),"It's cool, fresh, and very pleasant after the harsh "
    "smells of rotting vegetation from the jungle below. There's a faint "
    "tang of salt air and freedom on the breeze which appeals as well. "
    "\n");
}
void init()
{
    add_exit("northeast",HAVMAND+"j28.c","path");
    add_exit("northwest",HAVMAND+"h00.c","path");

    ::init();
}





