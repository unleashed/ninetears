#define SLICE   "/d/gremios/comandos/slice.c"

inherit "/obj/monster";

object ob;

void event_enter(object ob, string mensaje, object donde)
{
	if (ob->query_race() == "drow") {
		::event_enter(ob, mensaje, donde);
		return;
	}
	if (ob->query_hidden()) {
		do_command("decir Se intentan infiltrar!!");
		ob->dest_hide_shadow();
	}
	this_object()->attack_ob(ob);
  	::event_enter(ob, mensaje, donde);
}/*event_enter*/

void setup() {
  set_name("drider");
  set_al(10000);
  set_short("Drider");
  set_race("drow");
  set_language("common");
  set_level(32+random(5));
  set_max_hp(181+random(20));
  set_max_gp(150);
//  set_max_sp(100000);
//  set_sp(100000);
  set_random_stats(18, 19);
//  set_ac(-5);
  set_thac0(50);
  set_gender(1);
  add_alias("guardian");
  set_main_plural("Driders");
  add_plural("guardianes");
  add_property("nodisarm", 1);
  set_long("Una sucia criatura cuyo unico fin es vigilar estas cavernas, "
  "disenyada para matar sin piedad.\n");
  adjust_money(random(5) + 1,"platinum");
  add_clone("/baseobs/weapons/bastard_sword",2);
  add_clone("/baseobs/armours/full_plate", 1);
  init_equip();
} /* setup() */

void attack_by(object atacante)
{
	if (!query_property("passed out") && !query_property("slicing")
		&& !query_property("stun on") && !query_property("holied"))
		SLICE->slice(atacante->query_short(),TO);
	::attack_by(atacante);
}
/*
void heart_beat()
{
	object *i;
	if (!query_property("passed out") && !query_property("slicing"))
		if (sizeof(i=query_attacker_list()))
		{
			SLICE->slice(i[random(sizeof(i))]->query_short(), TO);
		}
	::heart_beat();
}
*/
