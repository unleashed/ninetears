inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("darklor");
	set_short("Darklor");
  set_race("dwarf");
  set_gender(1);
	set_long("This is Darklor a large and muscular Dwarf.  He is "
		"is quite a sight to see standing in the glow of the "
		"forge.  As you look into his eyes, you can instantly "
		"tell that this Dwarf has gone completely mad.  "
		"He is well known for his abilities in the making of "
		"weapons.  Wonder if he can use them as well.\n");

  load_a_chat(20,
	({
	1, "DIE TRAITOR!!!!!",
	1, "Leave me alone!",
	1, "Get out of here, NOW!"
	}) );
  set_guild_ob("/std/guilds/warriors/fighter");
  set_level(15);
  set_wimpy(0);
   clone_object(WEAPON+"short_sword.c")->move(this_object());
    clone_object(ARMOR+"chainmail.c")->move(this_object());
    clone_object(ARMOR+"large_shield.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
