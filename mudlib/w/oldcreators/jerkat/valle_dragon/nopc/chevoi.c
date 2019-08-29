// Jerkat 2002

inherit "/obj/monster";
 /*
static int ene=0;
object ob;
*/

void setup() {
  set_name("Chevoi");
  add_alias("chevoi");
  // set_al(10000);
  set_short("Chevoi");
  set_race("human");
  set_language("common");
  set_guild("mago de agband");
set_guild_ob("/d/gremios/magos/magobueno");

  set_level(30+random(5));
  set_max_hp(1000);
  set_max_gp(1000);
  set_random_stats(16,18);
  set_gender(1);
  set_long("Estas ante Chevoi, la Persona con mas poder de la Fortificacion."
  " Es de una gran presencia. Es un gran mago. tendras que vigilar con sus hechizos"
  " porque su poder es inimaginable. No se conoce a nadie que le haya atakado y haya"
  " salido vivo de esta habitacion. \n");
  adjust_money(20,"platinum");
  add_clone("/baseobs/armours/leather",1);
  add_clone("/baseobs/weapons/twohanded_staff",1);
  init_equip();
  set_join_fight_mess("Observas como Chevoi empieza a concentrarse para conjurar."
  " Acuta rapido o padeceras su ira.\n");
}

void init()
{
   ::init();
   add_attack_spell(60, "lightning bolt", ({"/d/gremios/hechizos/wizard/lightning.c","cast_spell", 0}));
   add_attack_spell(80, "tormenta acida", ({"/d/gremios/hechizos/mago/tormenta_acida", "cast_spell",1,0}));
   add_attack_spell(10, "horrible marchitamiento", ({"/d/gremios/hechizos/mago/horrible_marchitamiento", "cast_spell",1,0}));
   add_attack_spell(90, "cono de frio", ({"/d/gremios/hechizos/mago/cono_frio", "cast_spell",0,0}));
   add_attack_spell(80, "vampiric touch",({"/d/gremios/hechizos/wizard/vamp_touch.c","cast_spell", 0}));
}
