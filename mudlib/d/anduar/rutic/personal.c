inherit "/std/room.c";

int armario=0;

void setup()
{
  set_short("Casa de Rutic: Habitacion");
  set_long("En esta habitacion hay una pequenya cama de madera con una colcha roja, "
  	   "una mesita colocada al lado de la cama y un armario con un cerrojo.\n"); 
  set_light(65);
  
  add_item(({"mesa","mesita"}),"Una mesilla de noche colocada al lado de la cama, sobre ella hay un saco.\n");
  add_item("armario","Un armario que probablemente este lleno de ropa.\n");
  add_item("cerrojo","El armario esta cerrado por un cerrojo.\n");  
  add_item("cama","Una pequenya y comfortable cama con una colcha roja.\n");  
  add_item("saco","Un saco que parece vacio colocado sobre la mesilla.\n");  
         
  add_exit("este","/d/anduar/rutic/casa.c","road");
  
}

void init()
{
   add_action("abrir", "abrir");
   add_action("entrar", "entrar");
   add_action("forzar", "forzar");
   add_action("coger", "coger");   
   ::init();
}  

int abrir(string str)
{
if (str=="armario")
	{	
	tell_object(TP,"Un cerrojo te impide abrirlo.\n");		
	return 1;		
	}
if (str=="saco")
	{
	tell_object(TP,"Abres un poco el saco y te das cuenta de que se abre cuanto quieras, incluso podria entrar una persona aqui.\n");
	return 1;
	}
tell_object(TP,"Abrir que?\n");
return 1;
}
int forzar(string str)
{
if (str=="cerrojo")
{
tell_object(TP,"Despues de examinar el cerrojo te das cuenta de que hay algo magico que "
		"evita que pueda ser forzado.\n");
		return 1;
}
tell_object(TP,"Forzar que?\n");
return 1;
}
int coger(string str)
{
if (str=="saco")
	{
	tell_object(TP,"Intentas coger el saco pero te resulta imposible, parece pesar toneladas... "
	"pero te das cuenta de que su abertura es muy flexible, parece que se pueda abrir mucho.\n");
	return 1;}
return 0;
}
int entrar(string str)
{
int tios,i,numeroroom;
string room;
object *target;

if (str=="saco")
	{
// **********************************************************************		


tios=0;
for (numeroroom=1;numeroroom<10;numeroroom++)
{
room="/d/anduar/rutic/saco"+numeroroom+".c";
target = all_inventory(load_object(room));
 
  for (i=0;i<sizeof(target);i++)
  {   
    if(target[i]->query_player()) 
    { 
    	 tios=tios+1; 
    }   
  } 
}
//if (tios==0 && !TP->query_property("amuleto_kender") && (TP->query_time_on()<-86400))
if (!TP->query_property("amuleto_kender")) // eso era para el time conectado?
{
tell_object(TP,"Entras en el saco.\n");
tell_room(ENV(TP),TP->query_cap_name()+" entra en el saco.\n",TP);
TP->add_timed_property("SACO",1,3600);
TP->add_timed_property("NOKENDER",1,900);
TP->move("/d/anduar/rutic/saco1.c");
TP->look_me();
return 1;
}
tell_object(TP,"Intentas entrar en el saco, pero parece no haber hueco suficiente para ti.\n");
return 1;
// **********************************************************************		
return 1;		
	}
tell_object(TP,"Entrar donde?\n");
return 1;
}
