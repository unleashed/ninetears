// Spp Mar'98
#define SIMBOLO "simbolo_gestur.c"
#define ITEMS "/d/oficios/clerigos/gestur/obj/"
#define NOMBRE "Shandril"
inherit "/obj/monster";
object simbolo;
void setup()
{
  set_living_name("shandril");
  set_name("shandril");
  add_alias("clerigo");
  add_alias("shandril");
  set_main_plural("clerigas");
  add_plural("clerigas");
  set_short("Shandril");
  set_long("Ante ti puedes ver a una de las mas importantes clerigas "
           "de esta parte del continente. En estos momentos presta sus "
           "servicios de ensenyanza a los clerigos novicios.\n");
  set_race("human");
  set_race_ob("/std/races/human");
 set_language("common");
  set_guild("priest");
  set_guild_ob("/std/guilds/priests/gestur");
  add_property("gestur" ,1);
  set_level(70);
  set_wis(23);
  set_con(18);
  set_str(18);
  set_max_hp(1500);
  set_hp(1500);
  set_max_gp(300);
  set_gp(300);
   add_property("nodisarm",1);
   set_language("common");
   TO->do_command("guild on");
  set_wimpy(0);
  set_gender(2);
    set_alignment(-100);
 
  add_property("fire", 50); 
  add_property("poison", 100); 
  add_property("cold", 50); 
 
  new(ITEMS+"armadura_justicia1")->move(TO);
  add_clone(ITEMS+"botas_negras",1);
  add_clone(ITEMS+"espada_ley",1);
  add_clone(ITEMS+"escudo_justicia",1);
  add_clone(ITEMS+"yelmo_justicia",1);
  
  init_equip(); 
} 
void init()
{
    ::init();
    add_action("do_bow","bow");
    add_action("do_bow","reverencia*rse");
    add_attack_spell( 30, "flamestrike",
      ({"/std/spells/cleric/flamestrike.c","cast_spell",1}));
    add_attack_spell( 80 , "hold person",
      ({"/std/spells/cleric/hold_person","cast_spell",1}));
    add_attack_spell( 10, "heal",
      ({"/std/spells/cleric/heal.c","cast_spell",3}));
    add_attack_spell( 30, "cause critical wounds",
      ({"/std/spells/cleric/cause_cr.c","cast_spell",1}));
    add_attack_spell( 40, "arma ardiente",
      ({"/std/spells/cleric/arma_ardiente.c","cast_spell",3,0}));
    add_attack_spell( 5, "agrandar",
      ({"/std/spells/wizard/agrandar.c","cast_spell",3,0}));
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
  if(this_player()->query_guild_name()!= "Clerigo de Gestur")
  {
    tell_object(this_player(),NOMBRE+" te saluda con la cabeza.\n");
    tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
    return(1);
  }
  if(this_player()->query_timed_property("holy symbol"))
  {
    tell_object(TP,NOMBRE+" te dice: Tan pronto?\n");
    tell_object(TP,NOMBRE+" te dice: Los simbolos sagrados del bien "
                "no son para ser malgastados, vuelve mas tarde.\n");
    return(1);
  }
  tell_room(ETO,TP->query_cap_name()+" saluda a "+NOMBRE+".\n",TP);
  tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);

     tell_object(TP,NOMBRE+" se aproxima a ti y te da algo.\n");
     tell_room(ETO,NOMBRE+" se aproxima y da algo a "+TP->query_cap_name()
               +".\n",TP);
       martillo=new("/d/oficios/clerigos/gestur/obj/simbolo_gestur.c");
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
   do_command("guild @[ %^YELLOW%^La GuildMaster%^RESET%^ ]: "+ob->query_cap_name()+" esta profanando el templo!");
 ::attack_by(ob);
}
   
mixed event_enter(object ob, string mensaje, object donde)
{
  if(living(ob))
    if(ob->query_guild_name() == "Clerigo de Gestur" || ob->query_guild_name()== "No guild.")
    {
      do_command("'Bienvenido al templo de Gestur");
    }
    else
    {
      do_command("'Como Osas profanar este lugar sagrado!!");
      TO->attack_by(ob);
    }
  return ::event_enter(ob,mensaje,donde);
}
 
