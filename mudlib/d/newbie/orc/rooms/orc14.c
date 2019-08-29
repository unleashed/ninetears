#include "path.h"
inherit CASTLE+"baseroom.c";
 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Tunnel");
set_light(40);
   set_long("\n   Realm of the Orc:  Tunnel.\n\n"
   "The tunnel ends here, the phosphorescent slime on the walls outlines "
   "a carving on the wall. It's somewhat worrying that the carving appears to "
   "move as you stand here. "
   "The floor is rough and you'll need to be careful to avoid tripping. "
   "The roof and walls of the tunnel are covered with a slick sheen of water "
   "fortunately the water seems to drain through the floor somehow. "
   "\n\n");
   add_smell("air","You choke, and decide that breathing any more of the must air in here than you can absolutely help is a bad idea.\n");
add_item(({"eye","carving"}),"The carving appears to be a bold, dwarf warrior.  Unfortunately, "
	"the orcs have cloven his head in two, and have scrawled foul writing "
	"upon him.  You think that, of old, he was guarding something, or was "
	"constructed as a warning.  "
   "It's quite difficult to tell as the wall is covered with moss and slime. "
   "The glowing eye appears to be a red gem of some kind, set into the wall. "
   "\n");
add_item("writing", " Piss on the dwarves!!! KILL THEM ALL!! ");
add_item("slime","\n"
" Ooo, it's SLIME!! \n");
add_item("gem","This gem will not come out, it kinda looks like "
        "a button now that you have looked closer.\n");
add_item(({"walls","walls","ground","ceiling"}),
" The room seemed to have some significance to its origanl inhabitants. It has a carving in it.\n\n");
add_exit("south",CASTLE +"orc18","door");
//add_exit("north",CASTLE +"orc08","door");
}
void init()
{
   ::init();
   add_action("do_press","press");
}
int do_press(string str)
{
   if(str == "gem")
   {
      tell_object(this_player(),"The wall rotates with astonishing silence and rapidity, and hurls you into the next room.!\n");
tell_room(this_object()," \n"
"  You turn around when you hear stone moving across stone only to see dust descending from the ceiling. \n");

      this_player()->move(CASTLE+"orc08");
      this_player()->look_me();
   return 1;
   }
   return 0;
}

