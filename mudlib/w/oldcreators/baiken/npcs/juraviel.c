//Samagh && Rutseg 2001

inherit "/obj/monster";
#include "../path.h"

setup()
{
  set_name("juraviel");
  set_short("Juraviel");
  add_alias("Edhil_faroth");
  add_alias("edhil");
  add_alias("elfo");
  add_plural("edhils");
  add_plural("elfos");
  add_plural("Edhil_faroths");
  set_long("Juraviel es uno de los mas bellos y atleticos elfos que "
  	"jamas hayas contemplado. Su destreza y habilidad con las armas es conocida "
  	"por todos los Reinos, y sus conocimientos sobre la naturaleza que "
  	"envuelve al mudno de los elfos es muy tenida en cuenta por todos. "
  	"Pese a su aparente juventud, es uno de los elfos mas ancianos de Hitrim, "
  	"mirando sus ojos puedes ver tiempos remotos, incluso antes de que los "
  	"elfos llegaran al bosque de Orgoth, o el Gran Arbol fuera lo que es.\n");
  set_gender(0);
  set_race("Elfo");
	set_race_ob("/std/races/elf");
  set_random_stats(19,20);
  set_str(30);
  set_cha(25);
  set_wis(80);
  set_guild_ob("/std/guilds/warriors/Edhil_faroth");
  set_guild("Edhil_faroth");
  set_level(65);
  set_al(-1000);  
  adjust_money(random(5)+1,"platinum");

  set_max_hp(1000);
  set_max_gp(20000);

  add_timed_property("fire",30,90000);
  add_timed_property("cold",30,90000);
  add_timed_property("air",30,90000);
  add_timed_property("poison",30,90000);
  add_timed_property("electrical",30,90000);
  add_timed_property("magical",30,90000);
  add_timed_property("acid",30,90000);
  add_timed_property("stone",30,90000);

  add_clone(ARMAS+"elf_sword.c",2);
  add_clone(ARMADURA+"malla.c",1);
  add_clone(ARMADURA+"guan.c",1);
  init_equip();
}
void init()
{
	::init();
	add_attack_spell(40,"fuerza_natura",({"/std/commands/edhil/fuerza_natura","fuerza_natura",3,0}));
	add_attack_spell(60,"cazar",({"/std/commands/cazar","hunt",0,0}));
}
void attack_by(object att)
{
	if(att->query_guild_name()=="Edhil Faroth" && !att->query_property("elfo_desterrado"))
		att->add_property("elfo_desterrado",1);
	return ::attack_by(att);
}
void event_enter(object quien,string msg,object donde)
{
	if(quien->query_level()>29 && quien->query_guild_name()=="Edhil Faroth" && !random(5))
	{
		TO->do_command("susurrar "+LC(quien->query_short())+" Hola! Creo que deberias pasarte "
			"por el consejo. Pon tu mano en el tronco y dile al gran arbol que te abra.\n");
	}
}
void event_exit(object quien,string mensaje,object donde)
{
	string habilidad;
	if(quien->query_guild_name()=="Edhil Faroth" && quien->query_player())
	{
		switch(quien->query_level())
		{
			case 10..11: habilidad= "fuerza_natura"; break;
			case 12..15: habilidad= "investigar"; break;
			case 16..19: habilidad= "cazar"; break;
			case 20..29:
				if(!quien->query_known_command("danza") && !quien->query_property("qdanza_info"))
				{
					if(HANDLER_Q_DANZA->query_trama()<2)
					{
						TO->do_command("'Has llegado muy lejos "+quien->query_cap_name()+", pero no se si estas "
							"preparado para aprender los secretos del gremio. Busca a Yavahne, "
							"ha ido al bosque a por hierbas, tal vez puedas aprender mucho de ella.\n");
						if(!HANDLER_Q_DANZA->query_trama())
							HANDLER_Q_DANZA->iniciar_quest();
					}
					else
						TO->do_command("'Has llegado muy lejos "+quien->query_cap_name()+". Mmm... tal vez pueda "
							"Yavahne ensenyarte los secretos del gremio, pero ahora mismo esta con otro Edhil.");
					quien->add_timed_property("qdanza_info",1,100);
				}
				break;
			case 30..36:
				if(habilidad=="rastrear" && !quien->query_known_command("rastrear") && !quien->query_property("rastrear_info"))
				{
					TO->do_command("'Bravo "+quien->query_cap_name()+", has mejorado mucho desde que viniste por primera vez al gremio "
						"para que te entrenara. Creo que estas preparado para conocer al anciano Laidos, el guardabosques. "
						"Viaja al Bosque de Thorin en el Reino de Takome, buscale y dile que te ensenye, podras aprender gandes "
						"cosas de el, es un magnifico maestro.\n");
					TO->do_command("sonreir");
				}
				break;
			//case 37..99: habilidad= "centrar"; break; Rutseg XI-01
		}
		if(!quien->query_known_command(habilidad) && habilidad)
		{
			quien->add_known_command(habilidad);
			write_file(LOGS+habilidad+".log",quien->query_cap_name()+" el "+quien->query_level()+
				" "+quien->query_guild_name()+" nivel, aprendio el comando "+habilidad+" el "+ctime(time())+".\n",0);
			TO->do_command("'Bravo "+CNAME+", como premio a tu "
				"dedicacion y atencion a las artes de los Edhil Faroth creo que estas "
				"preparado para que te ensenye a utilizar la habilidad "+habilidad+".\n");
		}
	}
	return ::event_exit(quien,mensaje,donde);
}