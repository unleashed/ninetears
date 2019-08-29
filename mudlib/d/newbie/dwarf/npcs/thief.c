inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("thief");
	set_short("Thief");
  set_race("elf");
  set_gender(1);
   set_long("This small cocky little elf must be a thief.  He "
            "seems to be looking at your purse.  \n");
 set_main_plural("thieves");
 add_plural("thieves");

  load_chat(20,
	({
   1,"Thief tries to sneak around behind you.",
   1,"Thief moves in towards you, but jerks away when you see him.",
   1,"Thief motions towards your purse.",
	}) );
  set_guild_ob("/std/guilds/rogues/thief");
  set_level(2);
  set_wimpy(0);
   clone_object(WEAPON+"dagger.c")->move(this_object());
    clone_object(ARMOR+"leather.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
