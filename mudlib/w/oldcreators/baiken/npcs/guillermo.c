// Pequenya reforma Aokromes Julio 2001
#define SIMBOLO "simbolo_lummen.c" 
#define NOMBRE "Guillermo" 
#define FEAR_SH "/d/oficios/clerigos/lummen/npc/fear_sh.c"
 
inherit "obj/monster"; 
 
void event_enter(object ob, string mensaje, object donde)
{
   string raza, guild;
   if(ob->query_invis())
   return;
   raza  = ob->query_race();
   guild = ob->query_guild_name();
   if (raza == "Goblin" || raza == "Orco" || raza == "Duergar" ||
     raza == "Hombre-Lagarto" || raza == "Medio-Orco" || raza == "Drow" ||
     member_array(ob,query_attacker_list()) != -1)
   {
   this_object()->attack_ob(ob);
   }
   else
   {
   if(interactive(ob) && !ob->query_dead() && ob->query_guild_name() == 
   "Clerigo de Lummen")
   {
   if(!ob->query_property("bendicion_lummen"))
    {
    do_command("'Lummen ha decidido bendeciros a todos los hermanos. "
    "Vuestro dios esta orgulloso, y por ello nos ayuda.");
    tell_object(ob, "Guillermo te bendice en nombre de Lummen.\n");
    tell_room(environment(ob), "Guillermo bendice a "+ob->query_cap_name()+
    " en nombre de Lummen.\n", ob);
    ob->add_timed_property("bendicion_lummen", 1, 300);
   }
  }
 }
}
void init() 
{ 
    ::init(); 
    add_action("do_bow","bow"); 
} 
 
void setup()  
{ 
    set_name("guillermo"); 
    add_alias("clerigo"); 
    set_main_plural("clerigos"); 
    add_plural("guillermos"); 
    set_short("Guillermo el Gran Sacerdote"); 
    set_long("Guillermo es es Gran Sacerdote de la sociedad eclesiastica de "
    "Reinos de Leyenda. Desde hace muchos anyos, su alma, fue dedicada al "
    "completo al estudio y a seguir las doctrinas impuestas por el Dios del "
    "Bien Lummen. su aspecto serio y recto oculta una personalidad amable y "
    "bonachona. Parece una persona benerable y sabia.\n");
    set_race("human"); 
    set_guild("Clerigo de Lummen"); 
    set_guild_ob("/std/guilds/priests/lummen"); 
    add_property("lummenquest" ,1); 
    add_property("nodisarm",1);
    add_property("nosteal",1);
    set_wis(25); 
    set_dex(25); 
    set_con(25); 
    set_cha(25); 
    set_str(25); 
    set_max_gp(900);
    set_gp(900);
    set_wimpy(0); 
    set_gender(1); 
    set_al(-1000); 
    set_level(70); 
    set_max_hp(1000);
    set_hp(1500);
    set_language("common");
    TO->do_command("guild on");

    add_property("fire", 50);
    add_property("poison", 100); 
    add_property("cold", 50); 
    add_property("magical", 50);
    
    add_clone("/d/oficios/clerigos/lummen/items/escudo_justicia",1);
    add_clone("/d/oficios/clerigos/lummen/items/yelmo_justicia",1);         
    add_clone("/d/oficios/clerigos/lummen/items/maza_lummen",1);
    add_clone("/d/oficios/clerigos/lummen/items/amuleto",1);
    add_clone("/d/oficios/clerigos/lummen/items/armadura_justicia",1);
    init_equip(); 
    load_chat(60, ({1, "'Los Clerigos de Lummen somos los unicos que podemos "
    "salvar el mundo de nosotros mismos.",
    1, "'Como Clerigo de Lummen deberas respetar y transmitir todas las "
    "doctrinas que predica el Dios Lummen.",
    1, ":te saluda cordialmente.",
    1,":se atusa la barba." ,
    1, "'Bajo el Templo se encuentra las Catacumbas, lugar donde descansan "
    "los siervos del Dios Lummen.",
    1, "'Para entrar en las Catacumbas deberas encontrar un simbolo que te "
    "abra las puertas.",
    1, "'En las Catacumbas podras aprender aquello que no se ensenya en los "
    "libros, que Lummen te guie.",}) );
} 
 
int do_bow(string str)
{
  object martillo;
  
  str = capitalize(lower_case(str));
  if(str != NOMBRE)
  {
    notify_fail("Reverenciarte ante quien?\n\n");
    return 0;
  }
  if(this_player()->query_guild_name()!= "Clerigo de Lummen")
  {
    tell_object(this_player(), NOMBRE+" te saluda con la cabeza.\n");
    tell_room(ETO, NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
    return(1);
  }
  if(this_player()->query_timed_property("holy symbol"))
  {
    tell_object(TP, NOMBRE+" te dice: Tan pronto?\n");
    tell_object(TP, NOMBRE+" te dice: Los simbolos sagrados del bien "
                "no son para ser malgastados, vuelve mas tarde.\n");
    return(1);
  }
  tell_room(ETO,TP->query_cap_name()+" saluda a "+NOMBRE+".\n",TP);
  tell_room(ETO,NOMBRE+" saluda a "+TP->query_cap_name()+".\n",TP);
  tell_object(TP, NOMBRE+" se aproxima a ti y te da algo.\n");
  tell_room(ETO, NOMBRE+" se aproxima a "+TP->query_cap_name()+" y le da un objeto.\n",TP);
  martillo=new("/std/spells/items/"+SIMBOLO);
  martillo->move(TP);
  if (environment(martillo)!=TP)
     {
        write("No puedes cargar el cetro y se te cae al suelo.\n");
        martillo->move(ETO);
     }
  this_player()->add_timed_property("holy symbol",1,1800);
  return(1); 
} 
 
int atacada=0;
void attack_by(object player)
{
 object protector, sombra, cetropeleas;
 if(!atacada)
  {
   tell_room(environment(TO),TO->query_cap_name()+" empieza a gritar.\n");
   tell_room(environment(TO),TO->query_cap_name()+" saca un objeto de debajo de su armadura.\n");
   cetropeleas=clone_object("/std/spells/items/"+SIMBOLO);
   cetropeleas->move(TO);
    {
    string *doms;
    object *ob;
    int i;
    string str;
    int yep = 0;
    string *bass;
    ob = users();
    for (i=0; i<sizeof(ob); i++) 
    {
     if ((string)ob[i]->query_gender_string() != "blue") 
     {
     str = file_name(environment(ob[i]));
     bass = explode (str, "/");
     doms = get_dir("/d/");
     if (member_array("takome", doms) == -1) { return 0; }
     if (bass[1] == "takome") 
     {
      yep = 1;
      tell_object(find_living(ob[i]->query_cap_name()),"Guillermo grita: Traicion!! "
      "me esta atacando "+player->query_cap_name()+" a mi mis fieles.\n");
      atacada=1;
     }
    }
   }
  if (yep == 0) 
  {
  return;
  }
  return;
  }
  } 
  /*
   if(player->query_align()<-20 && 
      (explode(player->query_guild_ob(),".")[0] == "/std/guilds/priests/lummen" ||
      explode(player->query_guild_ob(),".")[0] == "/std/guilds/warriors/paladin"))
    {
     tell_object(player,"Guillermo te mira, y apesadumbrado al verse atacado por uno "
         "de sus propios alumnos te senyala con un dedo, haciendote sentir realmente "
         "aterrorizado.\n");
     tell_room(ENV(TO),"Guillermo mira apesadumbrado a "+player->query_cap_name()+
         " y cuando le senyala este parece sentir autentico panico.\n\n",player);
     player->add_timed_property("fear",1,1200);
     sombra=clone_object(FEAR_SH);
     sombra->setup_fear_shadow(player);
     player->stop_fight(this_object()); 
     player->do_fear();
    }
   else
    {
      ::attack_by(player);
    }
    */
   if(interactive(player) && !present("acolito"))
    {
     for(int i=0;i<2+random(2);i++)
     {
      protector=clone_object("/d/oficios/clerigos/npc/acolito");
      protector->move(ENV(TO));
      protector->do_protect("guillermo");
     }
    }
   if(TO->query_hp()<700)
       call_out("cura_moderadas",1);
     else if(TO->query_hp()<900)
        call_out("cura_ligeras",1);
     
   call_out("summon_armour",10);
   call_out("summon_hammer",20);
   call_out("summon_globos",30);
   ::attack_by(player);
}

void cura_criticas()
{
   "/std/spells/cleric/cure_cr"->cast_spell("guillermo",TO,0);
}
void cura_serias()
{
   "/std/spells/cleric/cure_sr"->cast_spell("guillermo",TO,0);
}
void cura_moderadas()
{
   "/std/spells/cleric/cure_md"->cast_spell("guillermo",TO,0);
}
void cura_ligeras()
{
   "/std/spells/cleric/cure_lt"->cast_spell("guillermo",TO,0);
}

void summon_hammer()
{
   if(!TO->query_property("hammer_spell"))
   "/std/spells/cleric/spiritual_hammer"->cast_spell("",TO,0);
}
void summon_globos()
{
   if(!TO->query_property("leaves_on"))
   "/std/spells/cleric/sym_spell"->cast_spell("",TO,0);
}
void summon_armour()
{
   if(!TO->query_property("armour_on"))
   "/std/spells/cleric/armadura_esp"->cast_spell("",TO,0);
}
void event_person_tell(object ob, string start, string mess,string lang)
{
   call_out("decir_lista_excomulgados", 0, ob, mess);
   return;
} 
   
   
void decir_lista_excomulgados(object ob, string mess)
{   
   int i;
   string *excomulgados;
   string exc = "";
   if(mess != "excomulgados")
      return;
   
   if(ob->query_guild_ob() != "/std/guilds/priests/lummen.c" &&    
      ob->query_guild_ob() != "/std/guilds/priests/lummen")
   {
      tell_object(ob,"Guillermo te dice: para que quieres saber eso si no eres uno de mis seguidores?\n");
      return;
   }
   
   excomulgados = "/std/spells/bases/excomunion_handler.c"->query_excomulgados_list("lummen");
   if(!sizeof(excomulgados))
   {
      tell_object(ob,"Guillermo te dice: Lummen esta contento, no hay ninguna oveja descarriada de su rebanyo.\n");   
      return;
   }
   
   for(i = 0;i < sizeof(excomulgados); i++)
   {
      exc += "     "+excomulgados[i]+"\n";   
   }
   tell_object(ob,"Guillermo te dice: Los que han renegado de la fe en Lummen son: \n"+exc+"\n");  
   
   return;
}
void do_death(object ob)
{
  object *snarf; 
        int i; 
        snarf=query_attacker_list(); 
        for(i=0;i<sizeof(snarf);i++) 
        { 
          write_file("/d/oficios/clerigos/lummen/guillermo", snarf[i]->query_name()+ 
          " ha matado guillermo: "+ctime(time())+".\n"); 
        } 
  ::do_death(ob);
}
