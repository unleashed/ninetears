inherit "/std/room.c";
int luz=0;

void setup()
{
  set_short("Casa de Rutic");
  set_long("Te encuentras en una pequenya gruta que ha sido reformada para "
     "ser habitable, el techo es bastante bajo. La habitacion esta perfectamente "
     "amueblada en preciosa madera de roble. Hay telares de colores vivos "
     "adornando y una lampara de aceite cuelga del techo. En el centro de "
     "la habitacion hay una mesa baja con varias sillas alrededor y sobre ella un candelabro dorado y "
     "un jarron con flores.\n"); 
  set_light(40);
  
  add_item("mesa","Es una mesa de madera de roble bastante mas baja de lo normal.\n");
  add_item(({"telares","telar"}),"Son unos telares de gran tamanyo de colores vivos y finamente rematados.\n");
  add_item("lampara","Una lampara de aceite cuelga del techo.\n");
  add_item("jarron","Es un jarron azul con flores de varios tipos.\n");
  add_item("candelabro","Es un candelabro dorado finamente tallado y con ornamentos de pedreria.\n");
     
  add_exit("fuera","/d/anduar/rutic/entrada.c","road");
  add_exit("oeste","/d/anduar/rutic/personal.c","road");
  add_exit("este","/d/anduar/rutic/cocina.c","road");
  
}

void init()
{
   add_action("tocar","tocar");
   add_action("apagar","apagar");
   add_action("encender","encender");
   add_action("coger","coger");
   ::init();
}  

int tocar(string str)
{
if (str=="telares" || str=="telar")
	{tell_object(TP,"Tocas uno de los telares y te das cuenta de que tiene un tacto extremadamente suave.\n");
	 tell_room(ENV(TP),TP->query_cap_name()+" toca uno de los telares.\n",TP);
	 return 1;
	}
return 0;	
}
int apagar(string str)
{
	if (str=="lampara")	
	{
	if (luz==0){tell_object(TP,"La lampara ya esta apagada.\n"); return 1;}
	tell_object(TP,"Abres la puertecita de cristal de la lampara soplas y la apagas.\n");
	tell_room(ENV(TP),TP->query_cap_name()+" apaga la lampara de aceite.\n",TP);
	ENV(TP)->adjust_light(-40);
	luz=0;
	return 1;
	}
tell_object(TP,"Apagar que?\n");
return 1;
}
int encender(string str)
{if (str=="lampara")	
	{
	if (luz==1){tell_object(TP,"La lampara ya esta encendida.\n"); return 1;}
	tell_object(TP,"Abres la puertecita de cristal de la lampara y la enciendes.\n");
	tell_room(ENV(TP),TP->query_cap_name()+" enciende la lampara de aceite.\n",TP);
	ENV(TP)->adjust_light(40);
	luz=1;
	return 1;
	}
tell_object(TP,"Encender que?\n");
return 1;
	}
int coger(string str)
{
if (str=="jarron")
	{
tell_object(TP,"Cuando vas a coger el jarron te das cuenta de que podrias lastimar alguna de "
		"las fragiles flores y decides no hacerlo.\n");
return 1;		
	}
return 0;
}