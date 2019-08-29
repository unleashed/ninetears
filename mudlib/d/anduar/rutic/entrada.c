inherit "/std/outside.c";

int forzado=0;

void setup()
{
  set_short("Entrada a la casa de Rutic");
  set_long("Te encuentras en un caminito ajardinado que termina en una roca "
     "natural. En la roca hay una pequenya puerta de madera que cierra el acceso "
     "a la casa de Rutic escavada en la roca.\n"); 
  set_light(80);
  add_item("puerta","Una puerta de madera con un gran cerrojo.\n");
  add_item("cerrojo","Un cerrojo de grandes dimensiones, esta claro que quien quiera "
  		     "entrar sin llave tendra que ser muy habil forzando cerraduras.\n");
     
  add_exit("fuera","/d/anduar/bosque_eloras/c7.c","road");
}

void init()
{
   add_action("abrir", "abrir");
   add_action("forzar", "forzar");
   ::init();
}  

int abrir(string str)
{
object *equipo;
int i;
if (str!="cerradura" && str!="cerrojo" && str!="puerta")
{	
 tell_object(TP,"Abrir que?\n");
 return 1;
}	

equipo = all_inventory(TP);
  
  for (i=0;i<sizeof(equipo);i++)
  {  	
        if (equipo[i]->query_name()=="llave rutic")   		
    			{
    			tell_object(TP,"Metes la llave en la cerradura y abres la puerta.\n");
    			tell_room(ENV(TP),TP->query_cap_name()+" abre la puerta con una llave.\n",TP);
    			forzado=1;
			add_exit("puerta","/d/anduar/rutic/casa.c","door");
			renew_exits();
			return 1;    			
    			}
  }
  tell_object(TP,"Abrir... con que?\n");
  return 1;
    
}
int forzar(string str)
{
int nivel=TP->query_level();
int destreza=TP->query_dex();
if (str!="cerradura" && str!="cerrojo")
{	
 tell_object(TP,"forzar que?\n");
 return 1;
}
if (forzado)
{
tell_object(TP,"Para que... si la puerta esta abierta?.\n");
return 1;
}
if (TP->query_guild_ob()!="/std/guilds/rogues/thief")
{
tell_object(TP,"Forzar el que?? Creo que no tienes la habilidad necesaria para hacer eso!!\n");
return 1;
}
if (TP->query_property("intento_abrir"))
	{
	tell_object(TP,"Ahora estas demasiado obcecado con tu anterior fallo... espera un rato.\n");
	return 1;
	}
if (random(nivel+destreza)>30) {forzado=1;
			   add_exit("puerta","/d/anduar/rutic/casa.c","door");
			   renew_exits();
			   tell_object(TP,"Colocas tus instrumentos en la cerradura y enseguida percibes el Click que te indica que tu "
			   		"intento de forzar el cerrojo ha tenido exito.\n");
			   tell_room(ENV(TP),TP->query_cap_name()+" hace algo en el cerrojo y la puerta se abre.\n",TP);
			   return 1;}
TP->add_timed_property("intento_abrir",1,3600);
			   tell_object(TP,"Tras un rato intentando forzar el cerrojo te das cuenta de que tu esfuerzo esta siendo inutil y abandonas.\n");
			   tell_room(ENV(TP),TP->query_cap_name()+" intenta forzar el cerrojo, pero al parecer fracasa.\n",TP);
return 1;
}
