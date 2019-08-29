#include "path.h"
inherit "/std/room";
 
 
void setup()  
   {set_light(90);
set_short("Gate of Fire");
set_long("\nGate of Fire.\n\n"+
   "   The great gate of fire flares up before your eyes.  "+
	"Bars of fire dance up before you, lacing the huge arch of the "+
	"mountain entrance with a web of flame.  Unlike most gates, "+
	"no guards stand watch--the fire people trust in their goddess' "+
	"magical flames to keep out all but her most loyal.  Although "+
	"the fire people can pass untouched through this burning portal, "+
	"you fear that without the benediction of Immakala, you will "+
	"not pass through unscathed.  The mountain road winds down "+
	"to your south, and northwards the gate of fire shimmers with "+
	"scorching radiance.\n");
add_item(({"gate", "fire", "bars", "flames"}), "You peer closer at "+
	"the bars of fire blocking your entrance, then quickly step back "+
	"from the terrible heat.  The fiery bars are too close together "+
	"for you to squeeze through without burning yourself.\n");
add_item("arch", "The mountain entrance is carved out of the stone "+
	"rock face.  The red-veined black stone arch is carved with "+
	"a bold yet elegant script.  The glow from the fiery gate "+
	"illuminates the letters with dancing red light.  It reads, "+
	"IMMAKALA, GODDESS OF THE DANCING FLAMES, DEVOURER OF EARTH "+
	"AND TREES, CREATOR OF THE BURNING MOUNTAINS, LADY OF THE FOUR "+
	"PRIMAL FIRES, YOUR GLORY SHINES ETERNALLY WITHIN.'\n");
add_item(({"ground", "floor"}), "The hard volcanic stone is covered "+
	"with sparkling gold-touched red tiles.  The tiles reflect the "+
	"fiery light from the glowing walls, flickering beneath you as "+
	"you walk along./n");
add_item("walls", "The walls of this cavernous room glow a bright red, "+
	"magically illuminating the room with a bloody radiance.\n");
    
add_exit("north", ROOM+"square01.c", "road");
modify_exit("north", ({ "function", "exit_func" }) );

add_exit("south", ISLAND+"road01.c", "path");
   }
 
int exit_func() {
int hp, damage;
hp=(int)this_player()->query_hp();
damage=hp/3;
this_player()->adjust_hp(-damage);
write("Unbearable heat stabs through your body as you leap through "+
	"the Fire Gate, landing on the other side writhing in pain, skin "+
	"sizzling, your eyelashes and eyebrows charred into dust.\n");
return 1;
}
