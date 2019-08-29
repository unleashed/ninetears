inherit "/obj/monster";
#include "path.h"
/* changed from /w/devoe to /d/of by Jedi 5/11/93 */
object nweap,narm,ob;
void setup()
{
 object weapon, armour;
   set_name("faeyn");
   add_alias("treant");
add_alias("oak");
   set_short("Faeyn the Treant");
	set_long("This is Faeyn the Treant.  He advises the elves "
		"on living peacefully in the forest.  He is as strong as "
		"an oak, partly because he is an oak.\n");
   set_race("treant");
   set_guild("fighter");
 set_random_stats(10,18);
  set_str(18);
   set_level(20);
   adjust_money(10,"silver");
   set_gender(1);
   set_al(50);
	weapon = clone_object("/baseobs/weapons/short_sword.c");
	armour = clone_object("/baseobs/armours/studded.c");
   weapon->move(this_object());
   armour->move(this_object());
   init_equip();
}

void init()
{
 ::init();
 add_action("sword","sword");
 add_action("armour","armour");
 call_out("first_approach",0,this_player());
}

int sword()
{
	if(!this_player()->query_property("newbiesword")) {
	nweap=clone_object("/baseobs/weapons/short_sword.c");
 nweap->move(this_player());
 notify_fail("Faeyn says: You can wound many a creature with this."
    "\n");
	tell_room(this_player(),"Faeyn shakes a branch and gives "
		"you a sword.\n");
	this_player()->add_property("newbiesword",1);
 return 0;
	}
	else {
		notify_fail("Faeyn says: I have already given you a sword.\n");
	return 0;
	}
}

int armour()
{
	if(!this_player()->query_property("newbiearmour")) {
	this_player()->add_property("newbiearmour",1);
	narm=clone_object("/baseobs/armours/studded.c");
 narm->move(this_player());
 notify_fail("Faeyn says: This should give you some protection.\n");
 return 0;
	}
	else {
		notify_fail("Faeyn says: I have already given you armour.\n");
		return 0;
	}
}
int first_approach(object ob)
 {
	write("A majestic oak comes to life and addresses you.\n");
 do_command("'I am Faeyn, leader of these woods.  These once peaceful "
  "woods have become infested with evil.  Please help us destroy the "
   "enemies of the forest!  Type 'sword' and/or 'armour' and I will fetch it from our "
   "stockpile for you.\n");
 }


int event_person_say(object ob,string str, string mess)
{
	string s1;
   string *messes;
   messes = explode(mess," ");
   if(member_array("poison",messes) != -1)
   {
		do_command("'The only poisonous creatures in this woodland "
			"are the wood imps.  There poison can be "
			"deadly to an adventurer like you.  However "
		"far to the north, near the entrance to the "
		"evil part of the forest the imps call home, "
		"grows a bush in a strange glade.  The berries "
		"of this bush will give your body resistance "
			"to the wood imp poison when eaten.\n");
		do_command("'I strongly suggest you seek out this bush "
			"before doing combat with the imps.\n");
return(1);
	}
	
}
