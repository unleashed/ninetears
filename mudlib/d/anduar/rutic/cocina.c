inherit "/std/room.c";

int armario=0;

void setup()
{
  set_short("Casa de Rutic: Cocina");
  set_long("Esta habitacion parece haber sido disenyada como la cocina, "
  	   "hay una mesa pintada de blanco con varias sillas y armarios del mismo color, "
  	   "un cubo negro con algunos restos de comida en una esquina "
  	   "te hacen pensar que alguien estuvo aqui no hace mucho.\n"); 
  set_light(65);
  
  add_item("mesa","Es una mesa de madera blanca bastante mas baja de lo normal.\n");
  add_item(({"armarios","armario"}),"Son armarios blancos de madera.\n");
  add_item("cubo","Un cubo negro para tirar la basura, esta lleno de comida.\n");  
         
  add_exit("oeste","/d/anduar/rutic/casa.c","road");
  
}

void init()
{
   add_action("abrir", "abrir");
   add_action("cerrar", "cerrar");
   add_action("meter", "meter");
   
   ::init();
}  

int abrir(string str)
{
if (str=="armario" || str=="armarios")
	{
	if (armario==1){tell_object(TP,"Ese armario ya esta abierto.\n"); return 1;}
	tell_object(TP,"Abres el armario, dentro de el hay unos cuantos platos y vasos.\n");
	tell_room(ENV(TP),TP->query_cap_name()+" abre uno de los armarios y mira en su interior.\n",TP);
	armario=1;
	return 1;		
	}
tell_object(TP,"Abrir que?\n");
return 1;
}
int cerrar(string str)
{
if (str=="armario" || str=="armarios")
	{
	if (armario==0){tell_object(TP,"Ese armario ya esta cerrado.\n"); return 1;}
	tell_object(TP,"Cierras el armario.\n");
	tell_room(ENV(TP),TP->query_cap_name()+" cierra uno de los armarios que estaba abierto.\n",TP);
	armario=0;
	return 1;		
	}
tell_object(TP,"Cerrar que?\n");
return 1;
}
int meter(string str)
{
if (str=="mano en cubo")
{ tell_object(TP,"Metes la mano en el cubo y la sacas llena de porqueria... QUE ASCO!!\n");
  tell_room(ENV(TP),TP->query_cap_name()+" mete la mano en el cubo y la saca llena de porqueria... QUE ASCO!!\n",TP);
  return 1;
}
tell_object(TP,"Meter que donde?\n");
return 1;
}