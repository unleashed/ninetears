// Gurthang '00
inherit "/obj/monster";
#include "/d/oficios/guerreros/lagartos/npcs/path.h"
#define COLETAZO "/std/commands/coletazo.c"
#define MORDISCO "/std/commands/mordisco.c"
#define DESGARRAR "/std/commands/desgarrar.c"
int done = 0;

int reset_done(){ return done = 0; }
int set_done(){ return done = 1; }
int query_donde(){ return done; }
int combo(object* chu);
void setup()
{
   
  set_name("oxiagon");
  set_short("Oxiagon");
  set_gender(1);
  set_main_plural("Personas parecidas a Oxiagon");
  set_race("Hombre-Lagarto");
  set_race_ob("/std/race/lizard-man");
  set_guild("Guerreros del Pantano");
  set_guild_ob("/std/guilds/warriors/pantanos");
  set_str(35);
  set_con(25);
  set_dex(25);
  set_int(25);
  set_wis(25);
  set_cha(25);
  set_long("Oxiagon es un gran Hombre-Lagarto de mas de dos metros y medio de altura. "
	"Sus escamas son tan duras como el acero y sus dientes "
	"alcanzan los siete centimetros de largo. Se dice que es uno de los "
	"senyores de los pantanos que domina sus territorios con mano dura, "
	"ademas es el patron del gremio de los Guerreros del Pantano, el "
	"es el que ensenya a sus discipulos tecnicas secretas de lucha cuando "
	"estos han alcanzado suficiente experiencia en el combate.\n");
  add_clone(LAGARTO+"yelmo",1);
  add_clone(LAGARTO_ARMA+"tridente",1);
  add_clone(LAGARTO+"armadura",1);
  add_clone("/baseobs/armours/ring",1);
  add_clone("/baseobs/armours/amulet",1);
  add_clone("/baseobs/armours/belt",1);
  add_property("nodisarm",1);
  init_equip();
  TO->do_command("guild on");
  adjust_tmp_damage_bon(15);
  set_level(69);
  add_property("LagartoAntiguo",1);
load_chat(20,
           ({
              1,"'Cuando lleges a un determinado punto de experiencia te ensenyare la tecnica del desgarro.\n",
              1,"'Yo fui entrenado por el Gran Saurio, que ahora esta en letargo en algun lugar de los reinos.\n",
              1,"'Soy uno de los Senyores de los Pantanos!!!\n",
              1,":se pone tenso ensenyando todos sus musculos.",
              1,"'Nuestra piel a base de escamas nos otorga una gran proteccion.\n",
              1,":se sienta en una piedra y no se mueve durante minutos. Parece que este muerto.\n",
              1,"'Mi arma es un regalo del Gran Saurio.\n",
           }));
}

void init()
{
  set_heart_beat(1);
  ::init(); 
}
void heart_beat()
{
   if(TO->query_attacker_list())
   {
      combo(TO->query_attacker_list());
   }
   ::heart_beat(); //MUY importante
   
}
int combo(object* lala)
{
   object chu = lala[random(sizeof(lala))];
   DESGARRAR->do_command(chu,this_object());
        if(!random(3))
           MORDISCO->do_command(chu,this_object());
        if(!random(4))	   
   	   "/std/commands/desarmar.c"->disarm(chu->query_name()); 
	if(!random(3))   
	   COLETAZO->hacer_strike(this_object(),chu);
	return 1;
}	      
void attack_by(object mec)
{
  if(!random(6))
     do_command("guild @[%^GREEN%^Senyor de los %^BLUE%^BOLD%^Pantanos%^RESET%^]: "+mec->query_cap_name()+" esta atacando nuestro guild!!");
  ::attack_by(mec);
}
      
void event_enter(object ob, string mensaje, object donde)
{
  if(living(ob) && (ob->query_guild_ob() == "/std/guilds/warriors/pantanos" ||
     ob->query_guild_name() == "No guild."))
  {
     do_command("'bienvenido, joven aprendiz");
  }
  else if (living(ob))
  {
     do_command("'que hace un bastardo como tu en este gremio!! LARGATE YA!!");
     TO->attack_by(ob);
  }
}
void do_death(object att) 
{ 
        object *snarf; 
        int i; 
 
        snarf=query_attacker_list(); 
 
        for(i=0;i<sizeof(snarf);i++) 
        { 
          write_file("/d/oficios/guerreros/lagartos/npcs/matar_oxia.o", snarf[i]->query_name()+ 
          " ha matado a Oxiagon: "+ctime(time())+".\n"); 
        } 
       ::do_death(att); 
}

//int query_total_ac(){ return -110;}
//int query_res() { return 65; }
