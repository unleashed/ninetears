inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("parham");
	set_short("Parham");
  set_race("goblin");
  set_gender(1);
set_long("The nasty, ugly, greasy Goblin man that stands before you "
  "is Parham the owner of this shop. He is quite dirty and smelly even for "
  "a goblin. You can hardly stand near him because he smells so bad. "
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
   clone_object(WEAPON+"morning_star.c")->move(this_object());
    clone_object(ARMOR+"leather.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
