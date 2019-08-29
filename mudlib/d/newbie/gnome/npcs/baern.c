inherit "/obj/monster";
#include "path.h";

void setup()
  {
	set_name("baern");
	set_short("Baern");
  set_race("dwarf");
  set_gender(1);
     set_long("This is Baern, Darklor's apprentice smithy.  He is "
          "working as fast as he can to get enough items ready for "
          "sale in the shop.  He has a look of concern on his face.  "
          "\n\n");

   load_chat(170,
   ({
   1, "Baern says, 'Sorry about the selection.  My boss, Darklor "
      "is missing.  We haven't seen him for days.'",
   1, "Baern says, 'I think my boss, Darklor got some sickness and "
      "went crazy.'",
   1, "Baern sighs",
   1, "Baern says, 'The doctors say that there is a cure for the "
      "sickness.  Some kinda moss or something.'",
   1, "Baern stares at the wall.",
   1, "Baern looks at the lack of goods in the cases and grumbles.",
   1, "Baern asks, 'Have you seen the beautiful waterfall near here?'",
   1, "Baern says, 'Don't play around near the whirlpool.'",
   1, "Baern says, 'Watch out for bats.'",
   1, "Baern says, 'Be careful if you cross the old rope bridge.'",
   1, "Baern coughs.",
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
   clone_object("/baseobs/armours/leather.c")->move(this_object());
  command("equip");
} /* setup */



void do_death(object att)
  {
     tell_object(att, "AAARRRRGGGHHH!");
  ::do_death(att);
}
