// Drakull, El senyor vampiro
// 7/ 98

inherit "/obj/monster";

void setup() {
      set_name("drakull");
      add_alias("vampiro");
      set_al(-100);
      set_short("Drakull");
      set_race("human");
      set_language("common");
      set_level(45+random(5));
      set_max_hp(500);
      set_wimpy(10);
      set_gender(1);
//      set_kill_xp(5000);
      add_alias("guardian");
      set_random_stats(16, 18);
      set_long("es el amo del castillo. es muy, muy "
	 "antiguo y parece muy fuerte.\n");
      adjust_money(5,"gold");

} /* setup() */

void init()
{
   ::init();
   add_attack_spell(85, "lightning bolt", ({"/std/spells/wizard/lightning.c",
   "cast_spell", 0}));
   add_attack_spell(15, "vampiric touch", ({"/std/spells/wizard/vamp_touch.c",
   "cast_spell", 0}));
}
