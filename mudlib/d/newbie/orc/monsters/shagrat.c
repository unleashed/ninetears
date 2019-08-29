inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("shagrat");
	set_short("Shagrat");
  set_race("orc");
  set_gender(1);

   set_long("This is Shagrat, the smithy who owns this shop.  He is "
             "a short, stocky, male Orc with a look of anger in his "
             "eyes.  He looks ready to take your order.  "
             "\n\n");
  load_a_chat(20,
	({
	1, "'DIE TRAITOR!!!!!",
	1, "'Leave me alone!",
	1, "'Get out of here, NOW!",
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
