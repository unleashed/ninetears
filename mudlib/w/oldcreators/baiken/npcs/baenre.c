//Lummen '98
#define SYMBOL "simbolo_lloth.c" 
#define TRANSFORM "/std/spells/esferas/llamada/sym_spell.c"
#define HANDLER "/d/casas/handler/casas_drow.c"
inherit "/obj/monster"; 
int atacada=0; 
// Retocada junto con los demas guildmaster de Tz para atacar a los no drow
// Vaeleth 2K 
 
void event_enter(object ob,string mensaje)
{
   if(ob->is_player() && ob->query_race_name() != "Drow"
      && !ob->query_death() && !ob->query_timed_property_exists("aranya_baenre"))
   {
      tell_room(ENV(TO),"Baenre dice: Por Lloth morireis infames... como osais"
                       " profanar el mas sagrado de los lugares...\n\n");
      attack_ob(ob);
      ob->add_timed_property("aranya_baenre",1,1000);      
      call_out("sacar_aranya",10, ob);
   }
   if(ob->is_player() && ob->query_race_name()== "Drow"
      && ob->query_cap_name() == HANDLER->query_matrona( HANDLER->winner_house() ) )
      tell_object(ob, "Baenre dice: Bienvenida a este impio lugar que su gremio es, "
                     "que la bendicion de Lloth contigo permanezca "+ob->query_cap_name()+" "
                     "y que a nuestros enemigos de la superficie le ayude a exterminar, oh! "
                     "poderosa Matrona entre las Matronas y Senyora de Tzerneelle'Dol.\n");
}
 
void event_person_tell(object ob, string start, string mess, string lang) 
{
   string auxstr, dest_str; //string con los desterrados
   if((ob->query_guild_ob() == TO->query_guild_ob() || ob->query_creator()) && mess == "desterrados")
   {
      dest_str="";
      foreach (auxstr in HANDLER->query_desterrados()) dest_str+=auxstr+", ";
      tell_object(ob, "Baenre te dice: Lloth ha condenado al peor de los castigos a los "
                      "siguientes proscritos: "+dest_str+" .\n");
   }
}
 
void sacar_aranya(object ob)
{
   object aranya;
   aranya=new("/std/spells/objetos/sym_lloth.c");
   aranya->move(ETO);
   aranya->setup_spell(TO);
   aranya->attack_ob(ob);
}
 
void heart_beat()
{
  /* Mmmmm no le mola la luz :) y se pondra oscuro :) */   
  if(ETO->query_light()>10)
  {
     tell_room(ETO,"La oscuridad parece cernirse alrededor de Baenre cuando "
                   "el poder de Lloth fluye atraves suya, manifestando su "
                   "voluntad.\n\n");
     TO->adjust_light(-10); 
  }
  
  ::heart_beat();
}
 
void init() 
{ 
  ::init(); 
  set_heart_beat(1);
   
  add_action("do_bow","bow"); 
  add_action("do_bow","reverencia");
  add_attack_spell( 70, "terremoto", 
        ({"/std/spells/cleric/quake.c", "cast_spell", 1,1}) ); 
  add_attack_spell( 80, "paralizar", 
        ({"/std/spells/cleric/hold_person.c", "cast_spell", 0}) ); 
  add_attack_spell( 60, "lepra", 
        ({"/std/spells/cleric/withering.c", "cast_spell", 0}) ); 
  add_attack_spell( 65, "curar heridas criticas", 
        ({"/std/spells/cleric/heal.c", "cast_spell", 3,1}) ); 
  add_attack_spell( 60, "silence", 
        ({ "/std/spells/cleric/silence.c", "cast_spell", 0,1 }) ); 
  add_attack_spell( 60, "columna de fuego", 
        ({ "/std/spells/cleric/flamestrike.c", "cast_spell", 1 }) ); 
  add_attack_spell( 60, "carne a piedra", 
        ({ "/std/spells/cleric/fleshts.c", "cast_spell", 1 }) ); 
  add_attack_spell( 10, "aullido infernal",
   ({ "/std/spells/cleric/demon_howl.c","cast_spell",2}) );
  
}
  
void setup() 
{ 
    set_name("baenre"); 
    add_alias("baenre"); 
    add_alias("cleriga"); 
    set_main_plural("clerigas"); 
    add_plural("baenres"); 
    set_living_name("baenre");
 
    set_short("Gran Sacerdotisa Baenre"); 
    set_long("Te encuentra frente a la Gran Sacerdotisa Baenre, la encargada "
    "de administrar el guild de las Clerigas de Lloth, siendo esta una de "
    "sus mas fieles seguidoras."
    " Su mirada imprenetable te congela el alma. Su pelo blanco le "
    "cuelga por uno de los lados. Una mueca insana en su rostro y una maldad "
    "palpable hacen honor a su nombre. A pasado por encima de mucha gente "
    "para llegar a este puesto y no parece querer dejarlo. Su tunica, tan "
    "vieja como ella misma, y su fiel latigo, de multiples cabezas de "
    "serpientes y especializado en picar las zonas espcialmente mas "
    "dolorosas. Su habilidad con los hechizos es unica y su velocidad es "
    "asombrosa. Que decir que pocos han sobrevivido a su ataque.");
    set_race_ob("/std/races/drow");
    set_race("Drow"); 
    set_guild_ob("/std/guilds/priests/lloth");  
    set_wis(30); 
    set_dex(19); 
    set_str(27); 
    set_con(17);  
    set_cha(20);
    set_max_gp(750); 
    set_gp(500); 
    set_gender(2); 
    set_al(700); 
    set_max_hp(2000);
    set_hp(2000);
        
   add_property("magical", 85); 
   add_property("poison", 100); 
   add_property("cold", 50); 
   add_property("electrical", 80); 
   add_property("fire", 70); 
   add_property("acid", 100); 
   add_property("air", 30); 
  
   add_clone("/d/oficios/clerigos/lloth/items/admesh.c", 1); 
   add_clone("/d/oficios/clerigos/lloth/items/whip.c", 1); 
   add_clone("/std/spells/items/"+SYMBOL, 1); 
   TO->init_equip();
   TO->do_command("guild on");
   set_level(75);
   load_chat(60,
    ({
      1, "'Las Clerigas de Lloth somos las unicas que podemos exterminar "
         "la bondad de la faz de los reinos.",
      1, "'Haz el mal sin importar a quien.",
      1, ":sonrie demoniacamente.",
      1, ":mira con orgullo su poderoso Latigo de Serpientes." ,
      1, "'Lloth es la unica diosa. Adorala y conseguiras el poder absoluto.",
      1, "'La Superficie no nos beneficia pero Lloth siempre estara contigo.",
      1, "'Lloth es Omnipotente y su poder no tiene limites!!!.",
      1, "'La sangre que clama Lloth es la de nuestros ilusos primos de la"
          " superficie.",
   }) );
   load_a_chat(60,
    ({
       1,":levanta sus manos hacia el cielo realizando una plegaria en un "
         "tono de susurro invocando el poder y la proteccion de Lloth.",
    }));
} 
 
int do_bow(string str) 
{ 
   object holy; 
  if(str!="baenre" && str!="Baenre") 
     return 0; 
  if(TP->query_guild_name() != "Cleriga de Lloth") return 0;
  if ( (int)this_player()->query_level() < 5 ) 
  { 
    write(this_object()->short()+" dice: Lo siento, pero tu poder "
    "no es suficiente para poder poseer el Simbolo Sagrado.\n");
    return 1; 
  } 
   if(!(int)this_player()->query_property("holy symbol")) 
   { 
      holy = clone_object("/std/spells/items/simbolo_lloth"); 
      holy->move(this_player()); 
      this_player()->add_timed_property("holy symbol",1,1800); 
      
  tell_room(environment(this_object()),(string)this_object()->query_cap_name()+
      " mira profundamente a "+this_player()->query_cap_name()+" e inicia una "
    "plegaria a la Diosa Lloth. Acto seguido le entrega el Simbolo Sagrado.\n",
      ({ this_player() }) ); 
      write((string)this_object()->query_cap_name()+" inicia una plegaria a "
      "Lloth mientras te da el Simbolo Sagrado del guild.\n");
   } 
   else 
   { 
      write(this_object()->query_cap_name()+" te dice: Deberas volver otro "
      "dia en el que Lloth escuche tus plegarias.\n");
   } 
   return 1; 
} 
 
void do_death(object att) 
{ 
        object *snarf; 
        int i; 
 
        snarf=query_attacker_list(); 
 
        for(i=0;i<sizeof(snarf);i++) 
        { 
          write_file("/d/oficios/clerigos/lloth/npc/matar_baenre.txt", snarf[i]->query_name()+ 
          " ha matado a Baenre: "+ctime(time())+".\n"); 
               snarf[i]->remove_timed_property("aranya_baenre");
        } 
       ::do_death(att); 
} 
 
void attack_by(object ob)
{
  if(!atacada)
  {
 
  TO->do_command("guild Socorro me esta atacando "+ob->query_cap_name()+"!!!\n");
 TO->do_command("guild Venid al templo a ayudarme rapido !!!\n");  
   atacada=1;     
  }
 ::attack_by(ob);  
}
