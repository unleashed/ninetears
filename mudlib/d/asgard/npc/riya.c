//.oO JaDe Oo.  Noviembre'02
inherit "/obj/entskill";

//void init()
//{
// ::init();
 
// add_attack_command(50, "drenar", "/d/gremios/comandos/drain", "drenar" ,3);
// add_attack_command(80, "cargar", "/d/gremios/comandos/carga", "carga" ,3);
 
//}
void setup()
{
  set_name("riya");
  set_short("Riya");
  set_long("Riya, Sacerdotisa Suprema del Caos.\n"
           "Una altiva y bella mujer que parece estar completamente en calma, pero cuando te "
  	   "mira a los ojos sabes que tras esa aparente fragilidad se esconde un tremendo " 
  	   "poder. Su lisa cabellera casta�a cae sobre sus hombros delicadamente y sus fr�os ojos "
  	   "almendrados te miran desnudando tu alma. No te dejes enga�ar por su aparente inocencia, " 
  	   "pues no dudar� un instante en acabar con tu vida si fuera necesario.\n");
  set_race("human");
  set_race_ob("/std/races/human");
  set_guild("clerigos/sacerdotecaos");
  set_guild_ob("/d/gremios/clerigos/sacerdotecaos");
  set_level(80);
  set_gender(2);
  set_str(30);
  set_int(50);
  set_cha(30);
  set_wis(80);
  set_dex(40);
  set_con(25);
  set_max_hp(2000);
  set_hp(2000);
  set_max_gp(2000);
  set_gp(2000);
  set_align(10000);
  set_aggressive(0);
  set_join_fight_mess("Riya exclama: "+
        "Sucumbe ante el Caos!\n");
  add_property("magical",75);
  load_a_chat(10,
  ({
     1, "'No escapar�s!",
     1, "'Condenar� tu alma!",
    
  }));
  load_chat(10,
  ({
     1, ":dice pausadamente: La senda del Caos es poderosa, pero no dejes que ese poder controle tus actos.",
     1, ":te mira friamente, escrutando tu alma.",
     1, ":levanta la palma de su mano y de ella brota una peque�a llama azulada.",
     1, ":dice: Tu alma debe estar en armon�a con tu cuerpo para poder canalizar todo tu poder.",
     1, ":dice seriamente: Una vez elegida la senda del Caos, no podr�s abandonarla, o la ira de JaDe caer� sobre ti.",
     1, ":dice friamente: No oses traicionar a La Dama Oscura.",
     1, ":dice: Se aproximan tiempos oscuros... Debemos estar preparados para la lucha.",

  }));
  

  add_clone("/d/asgard/item/tiara.c",1);
  add_clone("/baseobs/armours/amulet",1);
  add_clone("/baseobs/armours/bracers",1);
  add_clone("/baseobs/armours/ring",1);
  
  this_object()->init_equip();
  add_property("nodisarm",1);
  add_property("nosteal", 1);
  add_property("NO_BUDGE", 1); 

  add_skill_entrenable("concentracion",0,100,"general");
//  add_skill_entrenable("aplastar",0,100,"guerrero");
//  add_skill_entrenable("cazar",0,100,"general");
//  set_coste(random(5));
}


//void event_enter(object ob, string mess, object from)
// {
//if(lower_case(ob->query_race())!="humano"&&ob->query_alineamiento()[1]!=-1) return ; 
//     TO->attack_ob(ob);
//     ::event_enter(ob,mess,from);
// }
