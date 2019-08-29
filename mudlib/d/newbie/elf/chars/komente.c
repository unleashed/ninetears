#include "path.h"
inherit "obj/monster";
void setup() {
   set_name("komente");
   add_alias("priest");
   set_main_plural("priests");
   add_property("determinate","");
   set_short("Komente the Dark");
	set_long("Komente is a dark looking figure, cowled and mysterious. "
		"It was his leadership which allowed the wood imps to take "
		"over part of the elven forest.\n");
   set_race("drow");
   set_level(5);
   set_wimpy(0);
   set_gender(1);
   set_al(500);
	set_aggressive(1);
	set_con(20);
	set_wis(18);
	set_str(14);
	set_dex(16);
	set_max_hp(30);
	set_hp(30,this_object());
	set_max_gp(200);
	set_gp(200);
	set_guild("cleric");
	load_a_chat(50,({
			1, ":tortures the hapless elf.",
			1, ":cackles in malicious glee.",
		}));

		new("/baseobs/weapons/scimitar.c")->move(this_object());
		new("/d/newbie/elf/chars/equip/darkkey.c")->move(this_object());
		this_object()->init_equip();

}

void init()
{
	::init();
	add_attack_spell (20, "cure light wounds",
			({"/std/spells/cleric/cure_lt.c", "cast_spell", 3 }) );

}
