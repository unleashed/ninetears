inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("thrakis");
	set_short("Thrakis");
  set_race("goblin");
  set_gender(1);
     set_long("This is Thrakis the goblin smithy.  He is "
   "lounging around, not really trying to work. "
   "He looks like he was up late last night, probably hanging out in the tavern. "
          "\n\n");

   load_chat(170,
   ({
   1, "Thrakis asks, 'Have you seen the beautiful waterfall near here?'",
   1, "Thrakis says, 'Don't play around in the river.'",
   1, "Thrakis says, 'Watch out for quippers.'",
   }) );
  load_a_chat(20,
	({
	1, "DIE TRAITOR!!!!!",
	1, "Leave me alone!",
	1, "Get out of here, NOW!",
	}) );
  set_guild_ob("/std/guilds/warriors/fighter");
  set_level(8);
  set_wimpy(0);
   clone_object(WEAPON+"short_sword.c")->move(this_object());
    clone_object(ARMOR+"leather.c")->move(this_object());
    clone_object(ARMOR+"helmet.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
