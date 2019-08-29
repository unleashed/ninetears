#define CREATOR "jade"

inherit "/std/room.c";

void setup()
{
  set_short("%^BOLD%^%^BLACK%^Cripta de %^GREEN%^JaDe%^RESET%^");
  
  set_long("Al entrar en la inquietante oscuridad de esta sala percibes "
	   "que nada bueno se alberga en su interior. Sin animo de indagar "
	   "demasiado, echas una ojeada a tu alrededor. Paredes de una rara "
	   "piedra negra que parecen absorber la luz, unos estantes con libros, "
	   "tarros y diversos objetos cubiertos de polvo, una mesa con complicados "
           "instrumentos cuya utilidad no logras adivinar y una vieja silla "
	   "de hueso es todo lo que alcanzas a ver. Pero, sin duda, el altar que se "
           "encuentra en el medio de la sala y el ojo esmeralda que flota sobre el, "
           "es lo que mas te llama la atencion.\n\n");
  
  set_light(50);
  
  add_item(({"pared","paredes"}),"Son de piedra y completamente negras. Nunca antes viste una "              "piedra asi.\n");

  add_item(({"estante","estantes"}),"De madera negra, viejos y polvorientos.\n");
  
  add_item(({"libro","libros"}),"Las cubiertas y los lomos son de piel humana. Estan escritos "
            "en una lengua que desconoces completamente.\n");

  add_item(({"tarro","tarros"}),"Contienen diversos animalillos y trozos de cuerpos "                         "mutilados.\n");  

  add_item("silla","Esta hecha con huesos, pero desconoces de que tipo de criatura "                         "proceden.\n");

  add_item("mesa","De madera negra, bastante bien conservada.\n");

  add_smell(({"habitacion","aire"}),"El aire de esta habitacion es muy denso.\n");
  
  add_sound("habitacion","Susurros,siseos,gemidos... Las almas torturadas claman su"                         "libertad.\n");
  
  add_clone("/w/jade/items/ojo.c",1);
  add_clone("/w/jade/items/altar.c",1);
  add_clone("/w/jade/npc/caballero.c",random(3));
  add_clone("/w/jade/npc/avatar.c",random(3)); 

    add_exit("comun","/w/common","door");
  "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
  "/w/common.c"->renew_exits();
    add_exit("sala","/w/jade/animas.c","door");
  renew_exits();
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
	
	modify_item("altar","El Altar esta cubierto de sangre. Parece que se ha realizado "
                    "un sacrificio recientemente.\n");
	tell_object(this_player(),"Muestras tu sacrificio al Ojo Esmeralda y lo depositas "
                    "sobre el altar.\n");
	tell_room(this_object(),this_player()->query_cap_name()+" muestra su sacrificio "
		  "al Ojo Esmeralda y lo deposita en el altar.\n",this_player());
	tell_room("El Ojo se ilunima y deja caer una lagrima con un brillante destello esmeralda.");
		
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

