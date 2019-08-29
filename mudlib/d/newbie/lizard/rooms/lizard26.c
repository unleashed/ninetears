#include "path.h"
inherit ROOM+"baseroom";

void setup()  { my_setup();
set_short("Realm of the Lizard:  Town Square");
set_light(60);
set_long("\nRealm of the Lizard:  Town Square\n\n"
"     You find yourself in the middle of Sisthihs's town square, home of all "
"lizard-men."
" The square is not much more then a large expanse of mud and muck."
" Here is where all young lizards come to begin the journey of life."
" There are many markers here in honor of those that have tried and died."
" You feel honored to be able to walk across the graves of these"
" brave and often young lizards. You are determined to bring"
" honor to your race. There appears to be a shop of some sort to the northeast and to the west lies a tavern."
" To the south is some kind of meeting hall and the southwest road leads to some"
" kind of temple.\n");


add_property("no_undead",1);
add_exit("south",SWAMP +"guild.c","room");
add_exit("north",SWAMP +"lizard24","room");
add_exit("east",SWAMP +"lizard27","room");
add_exit("west",SWAMP +"tavern.c","room");
add_exit("southwest",SWAMP +"raiserm.c","room");
add_exit("northeast",SWAMP +"store.c","room");
add_item("mud","You kneel down to look closer at the mud"
". It seems to be oozing forth out of the ground.\n");
add_item("muck","The muck here appears to be made up of decaying vegatation.\n");
add_item("markers","Looking at the markers gives you a doubling"
" sensation. You realize that many of the markers are here for"
" the memory of ones just like you. Off to the right you notice"
" a fresh marker. As you look closer you notice that there is no grave here"
". The name on the marker is YOUR OWN.\n");
}
