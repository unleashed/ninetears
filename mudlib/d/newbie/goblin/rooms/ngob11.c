// The goblin Newbie Area
// Made by Tek and Allonon May 1995
#include "path.h";

inherit "/std/room";

object *npc;
void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Tunnels");
   set_light(20);
set_zone("newbie_tunnels");
set_long("\nRealm of the Goblin:  Gloomy Tunnels\n\n"
	 "     You are in a dark, damp passage. The walls here are covered "
"with moss and fungus. The sharp rocks get larger here, if you fall"
" you could be really hurt. You smell something strange in the air"
" but whatever the smell is it sends a shiver up your spine."
" You hear several voices to the west.\n\n");
add_property("no_undead",1);
add_sound("voices", " You hear several talking about dinner...old meat");
add_smell("air", "You smell death to the west!!!!!!!!!!!!");
add_item(({"rocks"}),
" These chunks of rock have gotten much larger and are very painful to walk on.\n");
add_item(({"floor"}),
" The floor appears to be littered with large sharp stone chunks.\n");
add_item(({"marks"}),
" These tool marks appear as if they have been here for awhile"
". They look like they were made by the picks you saw so many"
" dwarf slaves carring when you were young.\n");
add_item(({"wall"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("north",ROOM+"ngob10.c","path");
add_exit("west",ROOM+"ngob12.c","path");
// Exits...

     npc= allocate(1);

} /* setup() */



void reset()
{
    int i;
    for(i = 0; i < sizeof(npc); i++)
    {
	if(!npc[i])
	  {
	      npc[i]=clone_object("/d/newbie/goblin/npcs/kobold2.c");
	      npc[i]->move(this_object());
	  }
      }
    }

    void dest_me()
    {
	int i;
	for(i = 0; i < sizeof(npc); i++)
	{
	    if( npc[i] ) npc[i]->dest_me();
	}
	::dest_me();
    }

