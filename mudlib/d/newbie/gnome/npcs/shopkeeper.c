inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("dahl");
	set_short("Dahl");
  set_race("gnome");
  set_gender(2);
set_long("This is Dahl, a petite female gnome that has spent all "
         "of her life in Shadow Valley.  Her parents were founders "
         "of this small shop, but at a young age Dahl started "
         "working here, so now she knows every fine detail about its "
         "operation.  As a matter of fact, it is very rare to see "
         "her parents at work.  "
      "\n\n");

  load_a_chat(20,
	({
	1, "DIE TRAITOR!!!!!",
	1, "Leave me alone!",
	1, "Get out of here, NOW!",
	}) );
  set_guild_ob("/std/guilds/warriors/fighter");
  set_level(8);
  set_wimpy(0);
   clone_object(WEAPON+"lsword.c")->move(this_object());
    clone_object(ARMOR+"leather.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
