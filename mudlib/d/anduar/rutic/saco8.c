inherit "/std/room.c";

void setup()
{
  set_short("Dentro del saco");
  set_long("Te encuentras en un lugar muy extranyo, estas flotando en la nada, "
  	   "y a tu alrededor hay objetos de todo tipo que pasan en todas direcciones "
  	   "pero siempre se mantienen fuera de tu alcance.\n"); 
  set_light(70);  
  add_exit("sur","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("sudoeste","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("oeste","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("noroeste","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("norte","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("noreste","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("este","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("sudeste","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("arriba","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  add_exit("abajo","/d/anduar/rutic/saco"+(random(8)+1)+".c","road");
  
}
void init()
{
::init();
add_action("quit","sigilar");
add_action("quit",({"quit","salir","sal"}));
}

int quit(string str)
{
tell_object(TP,"No es el mejor momento para hacer eso.\n");
return 1;
}

 void event_enter(object target, string MESG, object FROM)
{
call_out("entrar",2,target);
}
int entrar(object target)
{
	
	if (target->query_player() && !target->query_property("SACO"))
	{tell_object(TP,"De repente una fuerza te impulsa hacia arriba...\n");
	TP->move("/d/anduar/rutic/personal.c");
	TP->add_timed_property("passed out","Te encuentras un poco aturdido.\n",7);
	TP->look_me();
	return 1;
	}
	if (target->query_player() && target->query_dead())
	{tell_object(TP,"De repente una fuerza te impulsa hacia arriba...\n");
	TP->move("/d/anduar/rutic/personal.c");
	TP->add_timed_property("passed out","Te encuentras un poco aturdido.\n",7);
	TP->look_me();
	return 1;
	}
	
if (!target->query_property("NOKENDER"))
	{
	if (random(15)==1)
		{
	tell_object(TP,"Notas como tu cuerpo flota en alguna direccion.\n");
	TP->move("/d/anduar/rutic/saco9.c");
	TP->look_me();
	return 1;
		}		
	}
}
