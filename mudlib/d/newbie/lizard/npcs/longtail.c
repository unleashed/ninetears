inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("longtail");
	set_short("Longtail");
  set_race("lizard-man");
  set_gender(1);
set_long("This is Longtail the apprentice smithy. He is "
          "working as fast as he can to get enough items ready for "
          "sale in the shop.  He has a look of frustration on his face.  "
          "\n\n");

   load_chat(90,
   ({
   1, "Longtail says, 'Sorry about the selection.  My boss, well "
      "is missing.  We haven't seen him for days.'",
  1, "Longtail says, 'My boss went off into the swamp looking for a "
   "lost treasure that the old tales tell about.'",
   1, "Longtail sighs",
   1, "Longtail coughs.",
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
   clone_object(WEAPON+"flail.c")->move(this_object());
    clone_object(ARMOR+"scalemail.c")->move(this_object());
    clone_object(WEAPON+"flail.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
