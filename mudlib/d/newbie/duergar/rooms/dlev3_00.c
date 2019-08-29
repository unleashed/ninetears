/*  Text alterations and additions by Grimbrand 2-2-96                    */

#include "path.h"
inherit "/std/underground";

object *npcs;

/*
void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dmaster02.c");
  npcs[i]->move(this_object());
  }
 }
}
*/

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);
set_short("Realm of the Duergar:  Office of Surface Exploration");
set_long("\n   Realm of the Duergar:  Office of Surface Exploration.\n\n"
	 "     You have entered the office of the Master of Surface "
	 "Exploration.  It is here where you will learn of the various "
	 "creatures that roam the surface of the realms.  The Master, "
	 "has obviously traveled there many times, you judge, by the "
	 "numerous items that could only have come from the sun "
	 "races of the surface.  The desk at one side of the room is "
	 "made completely out of a dark colored wood that you have "
	 "never seen before.  On the desk there are a few baubles as "
	 "well.  Along the walls are several liberated heads of some "
	 "of the evil creatures the Master had met on his "
	 "explorations and covering the floor are the skins of many "
	 "wild surface beasts.\n");

add_item("desk",
	 "   The desk is made out of a very rich and dark colored "
	 "wood.  It is said that such wood only comes from the elvin "
	 "forests of above, and they dont part willingly with their "
	 "beloved trees.\n\n");

add_item("baubles",
	 "   On the desk you see a piece of carved crystal that "
	 "is being used as a paper weight.\n\n");

add_item("heads",
	 "   Along the wall are several stuffed heads that the "
	 "Master has taken.  One looks like the head of a giant snake, "
	 "while the other is the furry head of a great bear.\n\n");

add_item("floor",
	 "   The floor is completely covered with animal skins.  "
	 "some are extremely soft, while others have colorful patterns "
	 "on them.\n\n");

add_exit("northwest",NEWBIE+"dlev3_01","door");
add_exit("southeast",NEWBIE+"main03","door");
modify_exit("northwest",({"function","bouncer"}));
add_clone(DNPC+"dmaster02.c",1);
}
/*
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
*/
 
int bouncer() {
int lv,xp;
object me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv == 2 && xp < 5500) {
write("   The door swings wide at your approach allowing you to pass "
	 "unhindered.\n\n");

tell_room(environment(me), me->query_cap_name()+" walks through the "
	 "northwestern door as it swings wide and then, swiftly, "
	 "it closes behind "+me->query_objective()+".\n\n",
	 ({this_player()}));
	 return 1;
}
notify_fail("It takes you a minute to quit shaking, from having "
	 "walked into the closed door.\n");

tell_room(environment(me), me->query_cap_name()+" shakes like a "
	 "tuning fork after having walked into the closed door.\n",
	 ({this_player()}));
	 return 0;
}
