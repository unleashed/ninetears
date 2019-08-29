inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("fyodor");
	set_short("Fyodor");
  set_race("gnome");
  set_gender(1);
   set_long("This is Fyodor, the local smith.  He has been"
            " forging weapons in Macedonia for many years.  All"
            " the gnomes have come to recognize his work as the"
            " best possible.\n");

   load_chat(60,
   ({
   1, "Fyodor stares at the wall.",
   1, "Fyodor looks at the lack of goods in the cases and grumbles.",
   1, "Fyodor says, 'Be careful in the tunnels.  They are very"
                    " dangerous to a young sprout like yourself.",
   1, "Fyodor says, 'Watch out for bats.'",
   1, "Fyodor coughs.",
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
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
