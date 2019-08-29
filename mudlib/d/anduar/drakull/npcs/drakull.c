// Marzo del 99 Drakull nueva version

#define SLICE   "/std/commands/slice.c"

inherit "/obj/monster";
static int ene=0;

object ob;

void setup() {
  set_name("Drakull el vampiro");
  add_alias("drakull");
  add_alias("vampiro");
  set_al(10000);
  set_short("Drakull el vampiro");
  set_race("human");
  set_language("common");
  set_level(45+random(5));
   set_max_hp(5000);
  set_gender(1);
  add_alias("guardian");
  set_random_stats(16, 18);
  set_long("Ante ti observas, impotente una colosal criatura, lo menos 2 metros "
  "y cuarto de altura, unas garras, de un aspecto tan terrorifico que tienen "
  "aspecto de poder cortar el mejor acero, unos colmillos tan largos que "
  "podrian atravesarte la mano, unos ojos tan misteriosos que podrian "
  "desnudarte el alma.\n");
  adjust_money(5,"gold");
  add_clone("/w/aokromes/tluz",1);
  add_clone("/w/aokromes/espada",2);
  init_equip();
  set_join_fight_mess("Observas como a drakull se le empiezan a ver las venas "
  "sus ojos se vuelven rojos, como crece hasta los dos metros y medio.\n");
} /* setup() */

void init()
{
  ::init();
  add_attack_spell(5, "lightning bolt", ({"/std/spells/wizard/lightning.c","cast_spell", 0}));
  add_attack_spell(95, "vampiric touch", ({"/std/spells/wizard/vamp_touch.c","cast_spell", 0}));
}

void attack_by(object atacante)
{
   ene++;
   SLICE->slice(atacante->query_name(),TO);
::attack_by(atacante);
}
