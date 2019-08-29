#include "/d/turkhun/path.h"
#define ARMOUR "/baseobs/armours/"
inherit "/obj/monster";

void init()
{
 ::init();
 call_out("approach",0,TP);
 add_attack_spell(20,"causar heridas serias",({"/std/spells/cleric/cause_sr","cast_spell",0,0}));
 add_attack_spell(20,"causar heridas mayores",({"/std/spells/cleric/cause_may","cast_spell",0,0}));
 add_attack_spell(20,"causar heridas moderadas",({"/std/spells/cleric/cause_md","cast_spell",0,0}));
 add_attack_spell(20,"causar heridas leves",({"/std/spells/cleric/cause_lt","cast_spell",0,0}));
 add_attack_spell(30,"curar heridas leves",({"/std/spells/cleric/cure_lt","cast_spell",3,0}));
}
 
void setup() 
{
 set_name("ebandar");
 set_short("Ebandar el Sabio");
 add_alias("ebandar");
 add_alias("sabio");
 set_long("Ebandar el Sabio es un Clerigo de Lummen, uno de los mejores aprendices "
 	"de Guillermo, que pudo salvar su vida gracias a su sabiduria, y que se refugio "
 	"de las Huestes de Oscuro en esta cripta al igual que los enanos, aqui mantiene viva "
 	"las esperanzas de su pequenyo grupo, cuidando su cuerpo y su alma.\n");
 set_gender(1);
 set_race("elf");
 set_guild_ob("/std/guilds/priests/lummen");
 set_random_stats(16, 18);
 set_str(27);
 set_dex(18);
 set_wis(18);
 set_max_gp(900);
 set_gp(900);
 set_level(50);
 set_max_hp(1500);
 set_hp(1500);
 set_al(1000);
 set_wimpy(0);
 adjust_money(10+random(15),"platinum");
 
 add_property("magical",100);
 add_property("poison",100);
 add_property("fire",50);
 
 add_clone("/d/oficios/clerigos/lummen/items/maza_lummen",1);
 add_clone(ARMOUR+"elfinchain",1);
 add_clone("/d/turkhun/items/yelmo_mithril",1);
 add_clone(ARMOUR+"cape",1);
 add_clone("/std/spells/objetos/simbolo_lummen.c",1);
 init_equip();
}

void approach(object ob)
{
 string raza;
 
 raza=lower_case(ob->query_race());
 if(ob->query_property("bando")>1)
 {
  do_command("say Fuera de mis tuneles!");
  do_command("protect mercenario");
  TO->attack_ob(ob);
 }
}

void attack_by(object player)
{
if(!TO->query_property("leaves_on"))
	"/std/spells/cleric/sym_spell"->cast_spell("",TO,0);

player->add_timed_property("enemigo_turkhun", 1, TIEMPO);
return ::attack_by(atacante);
}


void do_death()
{
   write_file("/d/turkhun/logs/ebandar.txt","Ebandar matado por "+TP->query_cap_name()+" el "+ctime(time())+".\n");
   ::do_death();
}


void event_death(object muerto) {
object dier;
	dier = muerto;  
	if (dier->is_player())
	write_file("/d/turkhun/logs/ebandar_mata.txt","Ebandar ha matado a "+muerto->query_cap_name()+" "+ctime(time())+"\n");
}

void heart_beat()
{
::heart_beat();
}