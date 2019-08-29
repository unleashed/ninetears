// Dagda 17/02
inherit "/obj/monster";
#define NUMATAC  2
#define DANYO random(10)+10

object dier;

void init()
{
 ::init();
 call_out("approach",0,TP);
 add_attack_spell(75,"gcritico", ({"/std/commands/gcritico","gcritico",1,0}));
 add_attack_spell(10+roll(2,10),"desarmar",({"/std/commands/desarmar","disarm",1,1}));
 add_attack_spell(50, "berserk",({"/std/commands/go_berserk_arturo","go_berserk", 0,0}));
}

void setup()
{
   set_name("mercenariodeturkhun");
   set_short("Mercenario de Abarrach");
   add_alias("mercenario");
   set_main_plural("Mercenarios de Abarrach");
   add_plural("mercenarios");
   set_race("Humano");
   set_race_ob("/std/races/human");
   set_guild_ob("/std/guilds/warriors/fighter");
   set_long("Es un humano fornido, un renegado de Zumelzu que ha sido contratado para "
   	    "trabajar como guardian de la puerta de la ciudad de Abarrach. Su odio "
   	    "a Durin, y su buen sueldo, hacen que sea una autentica fiera, y que no "
   	    "abandone su puesto a no ser que este muerto.\n");
   set_random_stats(18,18);
   set_cha(random(6)+20);
   set_str(40);
   set_level(55+random(5));
   set_align(0);
   set_gender(1);
   add_clone("/d/turkhun/items/maza_mercader.c", 2);
   add_clone("/baseobs/armours/great_helm",1);
   add_clone("/baseobs/armours/rings",2);
   add_clone("/baseobs/armours/amulet",1);
   add_clone("/baseobs/armours/pendant",1);
   add_clone("/baseobs/armours/shoes",1);
   add_clone("/baseobs/armours/belt",1);
   add_property("nodisarm",1);
   add_property("no_noquear",1);
   init_equip();
   
   load_chat(50, 
   ({ 1, "'Uuuummmmmmmm!!",
      1, "'no te fies de nadie aqui!!",
      1, ":patea el suelo produciendo un gran estruendo.",
      1, "'reniega de tus amos! liberate! y seras bienvenido aqui!!",
   }));
}

void approach(object ob)
{
if(ob->query_property("bando")>1)
 {
  do_command("protect ebandar");
  do_command("defend ebandar");
  TO->attack_ob(ob);
 }
}


void do_death(object ob)
{
   write_file("/d/turkhun/logs/mercenario_puerta.txt","Mercenario matado por %^BOLD%^YELLOW%^"+TP->query_cap_name()+"%^RESET%^ el %^BOLD%^YELLOW%^"+ctime(time())+"%^RESET%^.\n");
   return (::do_death(ob)); 
}

void event_death(object muerto) {

	dier = muerto;  
	if (dier->is_player())
	write_file("/d/turkhun/logs/mercenario_mata.txt","Mercenario ha matado a %^BOLD%^YELLOW%^"+muerto->query_cap_name()+"%^RESET%^ el %^BOLD%^YELLOW%^"+ctime(time())+".%^RESET%^\n");
}

void attack_by(object atacante)
{
   atacante->add_timed_property("enemigo_turkhun", 1, TIEMPO);
   return ::attack_by(atacante);
}
