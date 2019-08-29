// made by tek

#include "path.h"
inherit CASTLE+"baseroom.c";
string add_long_string;

void setup() {
// Descriptions...
set_short("Realm of the Orc:  Gate");
set_long("\n   Realm of the Orc:  Gate.\n\n"
         "     Here there is a lage gate and a guard post.  This must "
        "be the way out off this town, if only you knew how to "
        "open the gate. From here you can go west through the gate "
        "or east into the town.\n\n");
add_property("no_undead",1);
set_light(45);
add_item("gate","It is really sturdy looking, but it seems to "
        "be made more to keep things in then out. It is locked "
        "tight. Not much chance of opening that.\n\n");

//NPC'S
add_clone(CHAR+"guard2",2);

//exits
   add_exit("east",TOWN+"town04.c","path");

 add_exit ("west", TOWN + "road1.c", "gate");
   modify_exit("west",({"function","go_west"}));
}


int go_west ()
{
 object *stuff;
   if((int)this_player()->query_level() < 5)
   {
      notify_fail("An Orc guard appears, looks you up and down, then rolls on the floor laughing. "
      "When he recovers he snarls at you. \"Go 'way wimp, you too puny for bigs wide world yet.\" "
   "\n");
      return 0;
   }

stuff= find_match("letter", this_player());
   if(sizeof(stuff))
  {
write("You give the letter to the guards and with a grunt "
    "they open the gate and shove you through.\n\n"
     "As you leave the guards take the letter.  "
    "\n\n"
      "Guard says: We need that letter!\n\n"
    "Guard says: And don't come back!\n\n");
stuff->dest_me();
return 1;
   }

else
{

 notify_fail ("You try to open the gate, but it is locked.\n");
 tell_room (environment (this_player ()), this_player () ->
	    query_cap_name () + " tries to go west, but finds the gate "
	    "locked.\n", this_player ());
 return 0;
}
}
