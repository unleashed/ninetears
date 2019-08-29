//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup()
{
  set_short("%^BOLD%^%^BLACK%^Templo de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Altar");
  
  set_long("%^BOLD%^%^BLACK%^Templo de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Altar\n\n"
           "Te encuentras en la sala de rituales del Templo. Observas que la sala, en "
	   "realidad todo el templo, parece no tener techo, o por lo menos no alcanzas a  "
	   "ver donde terminan las irregulares paredes circulares. Las manchas de sangre "
	   "reseca dan al lugar un aire macabro y enfermizo. El olor a muerte est� atenuado "
	   "por un dulz�n aroma a incienso y almizcle. Tienes la sensaci�n de que si escucharas "
	   "con atenci�n podr�as o�r los gritos de terror de las v�ctimas que sirvieron de "
	   "ofrendas en los m�ltiples rituales celebrados aqu�. En esta estancia parece detenerse "
           "el tiempo y no puedes apartar la mirada del altar y del inquietante ojo esmeralda que "
           "flota sobre �l.\n\n");
  
  set_light(50);
  
  add_clone("/d/asgard/item/ojo.c",1);
  add_clone("d/asgard/item/altar.c",1);
  
  set_exit_color("magenta");

  add_exit("oeste","/d/asgard/room/templo/entrada.c","corridor");
  
  add_item("techo","No logras ver el final de las sinuosas paredes y lo �nico que consigues "
                   "es que tu mirada se pierda en la inmensa oscuridad.\n");
  
}


void init()
{
  add_action("sacrificio","sacrificar");
  ::init();
}

int sacrificio(string str)
{
  int j;
  object *lista;
 
  if(str=="gema")
  {   
   lista=all_inventory(TP);  
    notify_fail("No tienes ese objeto.\n");			 
    for (j=0;j<sizeof(lista);j++)  { 
        
        if (lista[j]->query_name("gema")=="gema")  {
     	
        if( this_object()->query_timed_property("SACR")==0 ){
	
	this_object()->add_timed_property("SACR",1,1000);
	
	modify_item("altar","El Altar est� cubierto de sangre. Parece que se ha realizado "
                    "un sacrificio recientemente.\n");
	tell_object(this_player(),"Muestras tu sacrificio al Ojo Esmeralda y lo depositas "
                    "sobre el altar.\n");
	tell_room(this_object(),this_player()->query_cap_name()+" muestra su sacrificio "
		  "al Ojo Esmeralda y lo deposita en el altar.\n",this_player());
	tell_room("El Ojo se ilunima y deja caer una l�grima con un brillante destello esmeralda.");
		
	clone_object("/w/jade/items/anillo.c")->move(this_object());
	lista[j]->dest_me();
	
	return(1);
      }
     
      tell_object(this_player(),"Se ha realizado un sacrificio recientemente. "
                                 "El Ojo esta satisfecho.\n");
      return(1);
    }
  }  

  notify_fail("Eso no parece ser del agrado del Ojo Esmeralda.\n");
  return(0);
  }
}

