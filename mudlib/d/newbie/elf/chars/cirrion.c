inherit "/obj/monster";
#include "path.h";

void setup()
{
    set_name("cirrion");
    set_short("Cirrion");
    set_race("elf");
    set_gender(1);
    set_long("Cirrion the shop keeper.\n");

    load_a_chat(20,
      ({
	1, "DIE TRAITOR!!!!!",
	1, "Leave me alone!",
	1, "Get out of here, NOW!",
      }) );
    set_guild("thief");
    set_random_stats(4,8);
    set_level(20);
    set_max_hp(15);
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
