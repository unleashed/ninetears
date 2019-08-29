/* source file -- Gallery of Rogues*/
#include "path.h"

inherit "/std/room";
inherit "/d/ss/daggerford/thieves/vguild.c";
 
int check_member(string str);
object thief;

void setup()
{
  set_short("Gallery of Rogues");
  set_long("Into the underground depths stretches a magnificent "+
    "gallery.  Raw oaken timbers span the ceiling high "+
    "overhead.  The air is musty yet dry and is reminiscent of "+
    "ash.  Two sturdy iron-bound doors flank each side of this "+
    "intersection.  To each side of the doors, a small lit torch "+
    "sits within a sconce. On the walls to each side is a "+
    "remarkably old tapestry.\n");
  set_light(70);
  set_zone("guild");

  set_save_file("/d/ss/daggerford/thieves/black_masks");
  add_item( ({"timbers", "beams", "rafters"}),
    "The rafters are as solid as a the rock above them and as "+
    "big as a stone giant's arm.\n");
  add_item( "doors",
    "Each door is layered with iron plate with a small "+
    "sliding embrasure so that other people can see into "+
    "the hallway.\n");
  add_item( ({"torch", "torches" }),
    "They look just like ordinary torches.  You don't "+
    "need them.\n");
  add_item( ({"tapestry", "tapestries"}),
    "One of the tapestries portays a beggar sitting against "+
    "a wall while the legs of a small crowd passes before "+
    "One hand is outstretched while the other is stashing "+
    "a gold bracelet.\n\nThe other tapestry portrays a street "+
    "swindler, his victim, and onlookers.  In his back pocket "+
    "is the Jack of Spades.\n");
  add_exit("west", ROOM + "quarters", "door");
  add_exit("east", ROOM + "board", "door");
  add_exit("north", ROOM + "under", "corridor");
  add_exit("south", ROOM + "hall2", "door");
     modify_exit("east", ({"function", "LEV_TEST"}));
}

void reset()
{
  if (!thief)
  {
    thief = HOSPITAL->get_monster("thief");
    thief->move(this_object());
  }
}
int LEV_TEST()
   {if(!check_member((string)(this_player()->query_name())))
        {notify_fail("You are not permitted to enter the board room "+
         "because you are not a member of the Black Masks.  Contact someone "+
         "in the guild about getting added to the roster.\n\n");
         say(this_player()->query_cap_name()+" tries to enter the "+
      "room east of here, but the door wont budge.\n\n");
    return 0;
    }
    return 1;
   }

