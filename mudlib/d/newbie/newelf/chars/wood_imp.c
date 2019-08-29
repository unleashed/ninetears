inherit "/obj/monster";
 
void setup() {
 set_level(5+random(5));
set_random_stats(5,17);
     set_wimpy(10);
     set_name("wood imp");
		add_alias("imp");
     set_short("wood imp");
	set_main_plural("imps");
	set_long("This is an evil looking humaniod.  You recognize "
		"it as a wood imp, a natural enemy of elves.  A race of "
		"mean, poisonous, forest-dwellers.\n");
     set_race("imp");
     set_al(400);
     set_aggressive(1);
     set_max_gp(50);   
     set_gp(50);
     load_a_chat(50,({
       1, ":drools and stares at you hungrily.",
       1, ":jumps up and down in anticipation of eating elf-flesh.",
     }));

	new("/d/newbie/elf/chars/equip/crspear.c")->move(this_object());
	this_object()->init_equip();
}

void attack_by(object AT)	{
	object bite;
	bite=clone_object("/std/spells/cleric/min_poisoned.c");
	bite->move(this_player());
	::attack_by(AT);
}
