inherit "/obj/monster";

void setup() {
  set_name("Lord oscuro");
  add_alias("lord");
  add_alias("oscuro");
  set_al(1000);
  set_short("Lord oscuro");
  set_race("human");
  set_language("common");
  set_level(30+random(5));
  set_max_hp(1500);
  set_max_gp(2000);
  set_random_stats(36, 48);
  set_gender(1);
  add_alias("guardian");
   set_aggressive(3);
  set_long("Ante ti observas, impotente una colosal criatura, lo menos 4 "
  "metros de altura, de un sexo indefinido, de una edad indeterminada, de "
  "una raza desconocida, de un origen improbable, solo ves unas luces donde "
  "se supone que podrian estar sus ojos, solo que parece tener tres, nunca "
  "habias oido hablar de semejante ser, su origen, seguro que magico.\n");
  adjust_money(50,"platinum");
  add_clone("/d/anduar/drakull/objetos/placa",1);
  init_equip();
} /* setup() */

void init()
{
  ::init();
  add_attack_spell(95, "lightning bolt",
({"/std/spells/wizard/lightning.c","cast_spell", 1,1}));
   add_attack_spell(5, "vampiric
touch",({"/std/spells/wizard/vamp_touch.c","cast_spell", 1,1}));
}
