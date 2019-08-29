inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("zundrin");
	set_short("Zundrin");
  set_race("dwarf");
  set_gender(1);
   set_long("The tall Dwarven man that stands before you is Zundrin, "
      "the owner of this equipment.  Due to his unusually extreme height "
      "is rumored that he is half human.  However, he refuses to admit "
      "it, even if it is true.  "
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
   clone_object(WEAPON+"war_hammer.c")->move(this_object());
    clone_object(ARMOR+"leather.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
