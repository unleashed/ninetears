
inherit "/std/room.c";
#include "path.h"

void setup () {
set_short("Realm of the Dwarf:  The Smithy");
set_light(40);
        set_long("\n   Realm of the Dwarf:  The Smithy\n\n"
         "     This looks as is it was once a shop where you could "
                "have a weapon custom made by an expert smithy.  But "
                "now the shop is in really bad shape.  The counter "
                "and racks have begun to rot and a thick layer of "
                "dust covers everything in the room.  In the center "
                "of the room sits a forge that is in supprisingly "
                "good shape compared to the other things in the room.  "
                "The forge is ablaze with a hot fire, almost if it was "
                "currently being used.  "
                "\n\n");
        add_item(({"counter","rack"}),"The counter and the racks are "
                "old and rotting.  They are covered with a thick layer "
                "of dust.\n\n");
        add_item("forge","The forge is in good shape and apparently, "
                "in use.  The fire coming from it is hot.  \n\n");
        add_item("fire","The flames dance out of the forge and sway "
                "before your eyes.  Your eyes follow the flames for "
                "a few seconds and you begin to feel the warmth "
                "of the fire.  Your eyelids start to get heavy.  As "
                "your head begins to fall you awaken with a start. \n\n");
	add_exit("north",ROOM+"dwarf12","path");
	add_clone(CHAR+"darklor.c",1);
}
