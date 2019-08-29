#include "path.h"
inherit HAVMAND+"pirate.c";
void setup()
{
    
   set_light(LIGHT);
    set_short("Isle of Havmand: Pirate Camp.\n");
    set_long("\nIsle of Havmand: Pirate Camp.\n"
    "   This part of the campsite is just off the beach and is a little tidier "
    "than the rest. Several large shells have been brought up from the beach "
    "for no obvious reason other than that they look nice. There is another "
    "hammock hanging between two trees and it looks as if someone has made "
    "an effort to keep this part of the camp reasonably clear of rubbish. "
    "\n\n");
    add_item("shells","Large, colorful conch shells are arranged just to look "
    "nice.\n");
    add_item("hammock","A string hammock, this one looks like it has been mended "
    "with vines cut from the surrounding jungle.\n");
    add_item("vines","Long string-like vines grow from some of the trees. If you "
    "could get hold of one, it would probably be really useful.\n");
    add_item("trees","Jungle trees, they grow very close together, and two of them "
    "have been used to hang a hammock from.\n");

}
void init()
{
    add_exit("west",HAVMAND+"p04.c","path");
    add_exit("east",HAVMAND+"b04.c","path");
    add_exit("northwest",HAVMAND+"p03.c","path");

    ::init();
}
