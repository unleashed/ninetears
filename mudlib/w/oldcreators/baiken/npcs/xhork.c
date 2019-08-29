// kok Jun'01 lo dopo un poco Aok XD (palabra poderosa matar) XD
#define NOMBRE "Xhork"
inherit "/obj/monster";
object simbolo;
void setup()
{
  set_living_name("xhork");
  set_name("xhork");
  add_alias("clerigo");
  set_main_plural("clerigos");
  add_plural("clerigos");
  set_short("Xhork");
  set_long("Te encuentras ante uno de los mas fieles seguidores de Oskuro, ha "
       "sido adoctrinado por el Archiprelado en la fe a Oskuro para que la "
       "divulge por los reinos. Para iniciar tan importante mision ha creado "
       "un templo para que acudan los nuevos fieles y ensenyarles los poderes "
       "que su Dios puede condederles.\n");
  set_race("human");
  set_race_ob("/std/races/human");
  set_guild("priest");
  set_guild_ob("/std/guilds/priests/oskuro");
  add_property("oskuro" ,1);
   set_language("common");
  set_level(70);
  set_wis(23);
  set_con(18);
  set_str(18);
  set_max_hp(1500);
  set_hp(1500);
  set_max_gp(300);
  set_gp(300);
   TO->do_command("guild on");
  set_wimpy(0);
  set_gender(2);
    set_alignment(100);
   set_language("common");
   add_property("nodisarm",1);
 
  add_property("fire", 50); 
  add_property("poison", 100); 
  add_property("cold", 50); 
 
  load_chat(30,
   ({
    1, "'Los antipaladines son nuestros mejores aliados, ayudales en todo y "
       "no les ataques, ellos te recompensaran!",
    1,"'Los caballeros de la Rosa Negra son la guardia de nuestro soberano "
      "Lord Sharanos, si creces lo suficiente tal vez puedas formas parte de "
      "ellos, ni que decirte que no deves atacarles.",
    1,"'Arrodillate ante mi, para que te de un regalo de nuestro senyor!",
    1, "'Si atacas a un antipaladin perderas probablemente tus poderes!",
   }));
  add_clone("/baseobs/armours/rings",1);
  add_clone("/baseobs/armours/amulet",1);
  add_clone("/baseobs/armours/pendant",1);
  add_clone("/std/spells/items/sym_oskuro.c",1);
  add_clone("/baseobs/armours/fullplate",1);
  add_clone("/baseobs/armours/great_helm",1);
  add_clone("/baseobs/armours/belt",1);
  
  init_equip(); 
} 
void init()
{
    ::init();
    add_action("do_bow","bow");
    add_action("do_bow","reverencia*rse");
    add_action("do_fiel", "arrodillarse");
    add_attack_spell( 30, "flamestrike",
      ({"/std/spells/cleric/flamestrike.c","cast_spell",1}));
    add_attack_spell( 80 , "hold person",
      ({"/std/spells/cleric/hold_person","cast_spell",1}));
    add_attack_spell( 10, "heal",
      ({"/std/spells/cleric/heal.c","cast_spell",3}));
add_attack_spell( 30, "cause critical wounds",({"/std/spells/cleric/cause_may.c","cast_spell",1}));
    add_attack_spell( 40, "arma ardiente",
      ({"/std/spells/cleric/arma_ardiente.c","cast_spell",3,0}));
    add_attack_spell( 5, "agrandar",
      ({"/std/spells/wizard/agrandar.c","cast_spell",3,0}));
    add_attack_spell( 1, "absolucion",
     ({"/std/spells/wizard/pw_die.c","cast_spell",1,1}));
}
int do_bow(string str)
{
  object martillo;
  
  str = capitalize(lower_case(str));
  if(str!=NOMBRE)
  {
    notify_fail("Reverenciarte ante quien?\n\n");
    return 0;
  }
    if(this_player()->query_guild_name()!= "Clerigo de Oskuro")
  {
    tell_object(this_player(),NOMBRE+" te saluda con la cabeza.\n");
    tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
    return(1);
  }
  if(this_player()->query_timed_property("holy symbol"))
  {
    tell_object(TP,NOMBRE+" te dice: Tan pronto?\n");
   tell_object(TP,NOMBRE+" te dice: Los simbolos sagrados del mal "
                "no son para ser malgastados, vuelve mas tarde.\n");
    return(1);
  }
  tell_room(ETO,TP->query_cap_name()+" saluda a "+NOMBRE+".\n",TP);
  tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
     tell_object(TP,NOMBRE+" se aproxima a ti y te da algo.\n");
     tell_room(ETO,NOMBRE+" se aproxima y da algo a "+TP->query_cap_name()
               +".\n",TP);
       martillo=new("/d/oficios/clerigos/oskuro/obj/simbolo_oskuro.c");
     martillo->move(TP);
     if (environment(martillo)!=TP)
     {
        write("No puedes cargar el martillo y se te cae al suelo.\n");
        martillo->move(ETO);
     }
     this_player()->add_timed_property("holy symbol",1,1800);
  return(1); 
}
void attack_by(object ob)
{
 object protector;
 if(interactive(ob) && !present("acolito"))
  for (int i=0;i<3+random(3);i++)
  {
   protector=clone_object("/d/oficios/clerigos/npc/acolito");
   protector->move(environment(TO));
   protector->do_protect("shandril");
  }
  if(!random(6))
   do_command("guild @[ %^BLACK%^%^BOLD%^El GuildMaster%^RESET%^ ]: "+ob->query_cap_name()+" esta profanando el templo!");
 ::attack_by(ob);
}
   
mixed event_enter(object ob, string mensaje, object donde)
{
  if(living(ob))
     if(ob->query_guild_name() == "Clerigo de Oskuro" || ob->query_guild_name()== "No guild.")
    {
      do_command("'Bienvenido al templo de Oskuro");
      return ::event_enter(ob,mensaje,donde);
    }
    else
    {
    if(ob->query_dead())
    {
      return ::event_enter(ob,mensaje,donde);
    }
    else
    {
      do_command("'Como Osas profanar este lugar sagrado!!");
      TO->attack_by(ob);
      return ::event_enter(ob,mensaje,donde);
    }
}
  return ::event_enter(ob,mensaje,donde);
}
 
int do_fiel(string str,object ob)
{
  object insignia; 
   if(str!="xhork")
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
