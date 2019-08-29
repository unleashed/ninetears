// mago

inherit "/obj/monster";


void setup() {
      int i;
      i = random(20+5);
      set_name("magvs");
      add_alias("mago");
      set_short("Mago errante");
      set_main_plural("Magos errantes");
      set_race("human");
      set_al(-100+random(201));
    //set_class("wizard");
      set_random_stats(6, 18);
      set_level(i);
      set_wimpy(0);
      // ob->add_attack("spell", 0, 80, i*10, 30, 0, "magic");
      set_max_hp(7+i*6);
      set_cha(17);
      new("/baseobs/armours/cloak")->move(this_object());
      set_long("El individuo tiene todo el aspecto de ser un mago. "
         "Quien si no vestiria una larga tunica y luciria una larga "
	"barba blanca ?\n");
      adjust_money(({random(i*5), "copper", random(i), "silver"}));
      add_triggered_action("bing2", "event_death", this_object(), "death");
      this_object()->init_equip();
      new("/baseobs/weapons/quarterstaff")->move(this_object());
      this_object()->init_equip();

} /* setup() */
void init()
{
   ::init();
   add_attack_spell(95, "lightning bolt", ({"/std/spells/wizard/lightning.c", "cast_spell", 0}));
}
