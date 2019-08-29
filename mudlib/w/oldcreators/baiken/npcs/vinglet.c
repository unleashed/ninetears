//Rutseg 23-IX-2001

#include "../path.h"
#define ALMACEN "/d/oficios/guerreros/elfos/gremio/almacen.c"
inherit "obj/monster";

void setup()
{
	set_name("vinglet");
	set_short("Vinglet el armero");
	add_alias("vinglet");
	add_alias("armero");
	add_alias("elfo");
	add_plural("elfos");
	set_main_plural("Armeros");
	set_long("Es un alargado elfo de mediana edad. Pese a ello puedes observar en su mirada "
		"la sabiduria de aquel que ha viajado por largos caminos fijandose y aprendiendo de "
		"todo lo que veia alli por donde pasaba. Con el tiempo regreso al hueco en el arbol "
		"y se ha dedicado desde entonces a proveer de armamento basico al gremio que le vio "
		"crecer.\n");
	set_race("Elfo");
  set_guild_ob("/std/guilds/warriors/Edhil_faroth");
	set_guild("Edhil_faroth");
	set_random_stats(12,17);
	set_str(17);
	set_level(16);
	adjust_money(random(20),"plate");
	add_clone("/baseobs/armours/leather",1);
	add_clone("/baseobs/weapons/long_sword",1);
	init_equip();
	load_chat(70,
		({
			1,"'Mis armaduras son excelentes para moverse agilmente, tanto en el bosque como en el campo de batalla.\n",
			1,"'Soy sin duda el mejor a la hora de forjar el %^BOLD%^laen%^RESET%^.\n",
			1,"'Traeme dos pedruscos de %^BOLD%^laen%^RESET%^ y uno de %^YELLOW%^mithril%^RESET%^ y yo forjare para ti una espada de %^BOLD%^Laen%^RESET%^.\n",
			1,"'El %^BOLD%^laen%^RESET%^ es un mineral dificil de encontrar, aunque me han llegado rumores de que los mineros de Lord Sharanos han encontrado algo del precioso mineral.\n"
		}));
	set_aggressive(0);
	add_hated("raza","Drow");
}
void init()
{
	::init();
	add_action("entregar_mineral","entregar");
	add_action("forjar_arma","forjar");
}
int entregar_mineral(string str)
{
	object *mineral;
	if(!str)
	{ notify_fail("Entregar que?.\n"); return 0; }
	if(str=="laen" || str=="mithril")
	{ notify_fail("Entregar "+str+" a quien?.\n"); return 0; }
	if(str=="laen a vinglet" || str=="laenes a vinglet" || str=="laens a vinglet")
	{
		mineral= find_match("minerales_laenes",TP);
		if(!sizeof(mineral))
		{ notify_fail("No tienes laen a tu disposicion para entregar a Vinglet?.\n"); return 0; }
	}
	if(str=="mithril a vinglet" || str=="mithriles a vinglet")
	{
		mineral= find_match("mithriles",TP);
		if(!sizeof(mineral))
		{ notify_fail("No tienes mithril a tu disposicion para entregar a Vinglet?.\n"); return 0; }
	}
	if(sizeof(mineral))
	{
		mineral[0]->move(load_object(ALMACEN));
		tell_object(TP,"Entregas a Vinglet un "+mineral[0]->query_name()+".\n");
		tell_room(TO,CNAME+" entrega a Vinglet un "+mineral[0]->query_name()+".\n",TP);
		TO->do_say("Perfecto, "+mineral[0]->query_name()+" sera muy util para hacer armas y armaduras.\n");
		ALMACEN->almacenar();
		write_file(LOGS+"forja.log",CNAME+" almaceno un "+mineral[0]->query_short()+" en "+ctime(time())+".\n");
		return 1;
	}
	else
	{ notify_fail("Entregar que a quien?.\n"); return 0; }
	notify_fail("Se ha producido un error en la entrega de mineral.\n");
	return 0;
}
int forjar_arma(string str)
{
	object almacen,*mineral,mithril;

	if(!str)
	{ notify_fail("Sintaxis: forjar <nombre_arma/armadura>\n"); return 0; }
	almacen= load_object(ALMACEN);
	if(str=="espada de laen" || str=="espada laen")
	{
		mineral= find_match("mithriles",almacen);
		if(!sizeof(mineral))
		{ notify_fail("Vinglet no puede forjar una Espada de %^BOLD%^Laen%^RESET%^, porque no tiene suficiente mithril.\n"); return 0; }
		mithril= mineral[0];
		mineral= find_match("minerales_laenes",almacen);
		if(sizeof(mineral)<2)
		{ notify_fail("Vinglet no puede forjar una Espada de %^BOLD%^Laen%^RESET%^, porque no tiene suficiente laen.\n"); return 0; }
		mineral[0]->dest_me();
		mineral[1]->dest_me();
		mithril->dest_me();
		almacen->almacenar();
		TP->do_say("Forja para mi una Espada de %^BOLD%^Laen%^RESET%^.\n");
		TO->do_say("De acuerdo, forjare para ti una hermosa Espada de %^BOLD%^Laen%^RESET%^.\n");
		tell_room("Vinglet se va hacia su horno frio, y empieza a dar golpes sobre los minerales.\n");
		call_out("forjando",6,"espada laen");
		TP->add_timed_property("passed out","Estas embobado mirando como Vinglet forja su obra de arte.\n",6);
		return 1;
	}
	else
	{ notify_fail("Vinglet no puede forjarte "+str+"\n"); return 0; }
}
void forjando(string arma)
{
	switch(arma)
	{
		case "espada laen":
		default:
			tell_object(TP,"Tras lo que parecen horas de intenso trabajo, Vinglet extrae una preciosa Espada de %^BOLD%^Laen%^RESET%^ de su horno y te hace entrega de ella.\n");
			tell_room(ENV(TO),"Tras lo que parecen horas de intenso trabajo, Vinglet extrae una preciosa Espada de %^BOLD%^Laen%^RESET%^ de su horno y le hace entrega de ella a "+CNAME+".\n",TP);
			if(TP->query_max_weight()-TP->query_loc_weight()<200)
			{
				tell_object(TP,"Llevas mucho peso y la Espada de %^BOLD%^Laen%^RESET%^ se te cae al suelo.\n");
				clone_object(ARMAS+"espada_laen")->move(ENV(TP));
			}
			else
				clone_object(ARMAS+"espada_laen")->move(TP);
			TO->do_say("Ten, aqui tienes esta magnifica espada, perfecta para recibir encantamientos o luchar en el campo de batalla.\n");
			write_file(LOGS+"espada_laen.log","El "+TP->query_guild_name()+", "+TP->query_level()+" nivel, "+TP->query_cap_name()+", fabrico una espada de laen el "+ctime(time())+".\n",0);
			write_file(LOGS+"forja.log",CNAME+" retiro 2 %^BOLD%^laen%^RESET%^ y 1 %^YELLOW%^mithril%^RESET%^ en "+ctime(time())+".\n");
			break;
	}
}
void event_enter(object ob, string mensaje, object donde)
{
	if(ob->query_property("bando")>1 || ob->query_timed_property("odiado_ARBRE") && ob->query_guild_name()!="Edhil Faroth")
		TO->attack_ob(ob);
	::event_enter(ob, mensaje, donde);
}
void attack_by(object ob)
{
	if(ob->query_property("bando")==1 && !ob->query_property("odiado_ARBRE"))
		ob->add_timed_property("odiado_ARBRE",1,2000);
	return ::attack_by(ob);
}