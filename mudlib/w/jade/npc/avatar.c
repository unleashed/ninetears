//.oO JaDe Oo.  Junio'01
inherit "obj/monster";

void init()
{
 ::init();
 add_attack_spell(75,"Proyectil magico menor", ({"/std/spells/escuelas/invocacion/proy_magico_menor.c","proy_magico_menor",1}));
}

void setup()
{
  set_name("avatar");
  set_short("Avatar Oscuro");
  set_main_plural("Avatares Oscuros");
  add_plural("avatares");
  set_long("Seres incorporeos, brumas oscuras de pura maldad, los Avatares de Jade "
           "lucharan hasta la muerte si su ama lo ordena. Poderosos nigromantes y habiles "
           "con las armas, constituyen sin lugar a dudas una temible amenaza.\n");
  set_race_ob("/std/races/human");
//  set_guild_ob("/std/guilds/wizards/general_mage.c");
  set_level(50);
  set_gender(1);
  set_random_stats(17, 18);
  set_cha(18);
  set_align(2000);
  set_aggressive(2);
  set_join_fight_mess("Avatar sisea: "+
        "SsssSsssSSsSsometete a mi ama o muere!\n");
  add_sphere("abjuracion", "mayor");
  add_sphere("invocacion","mayor");
  add_spell("Proyectil magico menor", "proy_magico_menor.c");
  add_timed_property("magical",45,900000000);
  add_timed_property("mental",75,900000000);
  add_timed_property("electrical",25,900000000);
  add_timed_property("poison",95,900000000);
  load_chat(10,
  ({
     1, ":flota a tu alrededor.",
     1, ":levanta sus incorporeos brazos y clama por su alma.",
     1, "'Solo sirvo a la Dama Oscura.",
     1, "'Protegere a mi Senyora con mi vida.",
     1, ":se desvanece.",

  }));
  
 add_clone("/baseobs/armours/platemail.c",1);
 add_clone("/baseobs/armours/great_helm.c",1);
  add_clone("/w/jade/weapon/vara.c",1);
 this_object()->init_equip();
  add_property("nodisarm",1);
}


void event_enter(object ob, string mess, object from)
 {
if (ob->query_cap_name()=="Jade" || ob->query_cap_name()=="Tyrael" ||  ob->query_cap_name()=="Caballero" || ob->query_cap_name()=="Avatar") return ;
   
     TO->attack_ob(ob);
     ::event_enter(ob,mess,from);
 }
