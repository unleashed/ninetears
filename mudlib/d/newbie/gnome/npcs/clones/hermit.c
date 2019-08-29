inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("hermit");
	set_short("Hermit");
  set_race("dwarf");
  set_gender(1);
	set_long("This is an old and dirty hermit.  His frail old "
		"body is covered with thick brown hair.  He looks "
		"tired and hungry."
		"\n\n");

     load_chat(200,
     ({
      1, "Hermit says :'I am so hungry.'",
      1, "Hermit looks at you expectantly.",
      1, "Hermit rubs his stomach and grumbles.",
      1, "Hermit searches around the room a bit.",

     }));
  load_a_chat(100,
	({
    1, "You will never learn!",
    1, "You have made a big mistake!",
	1, "Leave me alone!",
	1, "Get out of here, NOW!",
	}) );
  set_guild_ob("/std/guilds/warriors/fighter");
  set_level(8);
  set_wimpy(0);
   clone_object(WEAPON + "drift_wood.c")->move(this_object());
   clone_object(ARMOR + "cloak2.c")->move(this_object());
   command("equip");
}
void do_death(object att)
  {
	tell_object(att, "The hermit grabs the parchment from the floor "
		"and rips it to shreads.  \nJust before he dies, he throws "
		"the pieces into the fire."
		"\n\n");
  ::do_death(att);
}
