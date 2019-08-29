inherit "/obj/monster";
 
#define SIMBOLO "/std/spells/items/simbolo_antipaladin"
#define NOMBRE "Nuggler"
#define DINERO 15
 
object *array;
void setup()
{
  set_name("nuggler");
  set_short(NOMBRE);
  set_long("Este es "+NOMBRE+", el legendario AntiPaladin y el mayor defensor de Oskuro. "
           "Amigo intimo de Tarhilon, fue una de las dos personas que fundaron la Orden "
           "de Paladines de Oskuro, o antipaladines, como tambien se les llama. Ejercitado "
           "como guerrero, entrenado duramente por Arturo, ofrecio su alma y su fe a Oskuro, "
           "y este le ensenyo los Ritos Oscuros. Con Tarhilon , el Paladin, fundaron la Orden, "
           "y tomaron de los Paladines su organizacion y estructura, pero no su fe, que es "
           "la opuesta. El Honor es tan importante para un Paladin como para un AntiPaladin, pero "
           "puedes darte por muerto, si no adoras a Oskuro y te cruzas con el.\n");
  set_main_plural("personas parecidas a Nuggler");
  add_alias("antipaladin");
  add_plural("antipaladines");
  set_gender(1);
  set_aggressive(0);
  set_race("humano");
  set_race_ob("/std/races/human");
  set_guild_ob("/std/guilds/warriors/antipaladin");
  set_str(28);
  set_dex(18);
  set_con(18);
  set_int(18);
  set_wis(18);
  set_cha(20);
  set_gender(1);
  set_aggressive(0);
  set_alignment(10000);
  set_wimpy(0);
  add_property("OSKURO",1);
  set_level(60);
  set_max_hp(query_max_hp()+roll(query_con(),query_level()));
  set_max_gp(query_max_gp()+roll(query_wis(),query_level()));
  adjust_money(1+random(query_level()),"platinum");
  add_property("nodisarm",1);
  add_clone("/baseobs/weapons/bastard_sword.c",1);
  add_clone("/baseobs/armours/fullplate.c",1);
  add_clone("/baseobs/armours/great_helm.c",1);
  add_clone("/baseobs/armours/large_shield.c",1);
  do_command("guild on");
  add_property("no_pobredumbre",1);
  add_property("vision_real",1);
  init_equip();
  array = all_inventory(TO);
  load_chat(20,
  ({1,":te mira con sus ojos furiosos e inyectados en sangre.",
    1,"'debes adorar a Oskuro, $lcname$, siempre premia a los que le sirven "
      "bien.",
    1,"'Los clerigos de Oskuro son nuestros mejores aliados, ayudales en "
      "todo y no les ataques, ellos te recompensaran!",
    1,"'Arrodillate ante mi, para que te de un regalo de nuestro senyor!",
    1,"'Si atacas a un clerigos de Oskuro perderas probablemente tus poderes!",
    1,"'Los caballeros de la Rosa Negra son la guardia de nuestro soberano "
      "Lord Sharanos, si creces lo suficiente tal vez puedas formas parte de "
      "ellos, ni que decirte que no deves atacarles.",
    1,"'Jamas perdones la vida a un Paladin. Matales nada mas verles."
  }));
}
 
void init()
{
   add_attack_spell(40+roll(2,10),"charge",({"/std/commands/charge","charge",1}));
   add_attack_spell(40+roll(2,10),"disarm",({"/std/commands/desarmar","disarm",1}));
   add_attack_spell(40+roll(2,10),"drenar",({"/std/commands/drenar","drain",1}));
   add_action("do_bow", "bow");
   add_action("do_bow", "reverencia");
   add_action("do_fiel", "arrodillarse");
   ::init();
}
 
int do_bow(string str)
{
  object simbolo;
  str = capitalize(lower_case(str));
  if(str!=NOMBRE)
  {
    notify_fail("Saludar a quien?\n");
    return 0;
  }
  if(this_player()->query_guild_name()!= "Antipaladin" ||
     this_player()->query_level()<20)
  {
    tell_object(this_player(),NOMBRE+" te saluda con la cabeza.\n");
    tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
    return(1);
  } 
  if(this_player()->query_timed_property("holy symbol"))
  {
    tell_object(TP,NOMBRE+" te dice: Tan pronto?\n");
    tell_object(TP,NOMBRE+" te dice: Los simbolos sagrados de Oskuro "
                "no son para ser malgastados.\n");
    return(1);
  }
  tell_room(ETO,TP->query_cap_name()+" saluda a "+NOMBRE+".\n",TP);
  tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
  simbolo=clone_object(SIMBOLO);
  if (simbolo && !simbolo->move(this_player()))
  {
    tell_object(TP,NOMBRE+" se aproxima a ti y te da algo.\n");
    tell_room(ETO,NOMBRE+" se aproxima y da algo a "+TP->query_cap_name()
              +".\n",TP);
    this_player()->add_timed_property("holy symbol",1,1800);
  }
  return(1); 
}
 
void event_enter(object quien,string mess)
{
   if(quien->is_player() && !quien->query_dead() && (quien->query_guild_ob() && quien->query_guild_name()!="Antipaladin"))
      TO->attack_ob(quien);
}
 
void attack_by(object ob)
{
   if(member_array(ob,query_attacker_list())==-1)
   do_command("guild Me estan atacando! Venid en mi ayuda antipaladines!");
   ::attack_by(ob);
}
 
int do_fiel(string str,object ob)
{
  object insignia; 
if(str!="nuggler")
  {
    notify_fail("Arrodillarse ante quien?\n");
    return 0;
  }
  ob=find_match("/d/dendara/items/ojo2", TP);
  if(!sizeof(ob))
  {
  insignia=clone_object("/d/dendara/items/ojo2"); 
  insignia->move(TP);
  do_command("'Asi que quieres defender nuestra ciudad he?\n");
  tell_room(environment(TO),TO->query_cap_name()+" dice: Aqui tienes tu "
  "Ojo.\n");
  return 1;
  }
  tell_room(environment(TO),TO->query_cap_name()+" dice: Ya tienes tu "
  "Ojo, algun dia podras tener uno de verdad.\n");
  return 1;
}
