inherit "/std/outside.c";
#include <path.h>
void setup() { 
set_short("Entrada a la zona de "+CREATOR+".");

  set_long("De repente todo gira a tu alrededor y cuando te recuperas "
      "te encuentras al aire libre, en una curiosa estancia circular "
      "en el centro puedes ver una fuente de la cual mana un agua "
      "diafana e inmaculada.\n"
      "La estancia es muy luminosa ,circular, y tiene como limites unos "
      "tupidos setos de color verde de unos tres metros de altura, el "
      "suelo esta esculpido en granito.\n "	
      "Se respira gran paz y tranquilidad.\n");

   // Es luminoso no? pero tampoco tanto ;P
   set_light(70);

   // Vamos a ver... la decoracion no es lo mio... pero en fin ;P

   add_item("fuente","Es una preciosa fuente, de la cual mana "
      " un agua limpia y clara, en el fondo hay monedas.");

   add_item(({"setos","seto"}),"son unos setos verdes que delimitan la estancia,"
      " cuando te acercas a ellos te da la sensacion de que tienen vida "
      " propia.");

   add_item("suelo","el suelo es bastante llamativo parece como si estuviese "
      "esculpido directamente en una gran roca de granito.");

   add_item("agua","pues parece agua normal, eso si... muy limpia.\n");

   // q pasa si toco aqui mama? AAAGGGHHHH enchufe propina el golpe mortal a ninyo

   add_smell(({"estancia","aire"}),"El olor es semejante al de una noche de"
        " primavera, es un olor fresco y que te llena el corazon.");

   add_smell("agua","no te ensenyaron en la escuela que el agua es inodora?");
   add_taste("agua","no te ensenyaron en la escuela que el agua es insipida?");	
   add_feel("agua","vaya... parece que moja.");
   add_sound(({"agua","fuente"}),"el agua cae a borbotones del chorro principal de "
       "la fuente.");

  add_sound("estancia","No hay el mas minimo ruido, excepto el viento y el agua"
	     " de la fuente.");
	
   add_feel("suelo","es un suelo de granito, bastante suave pero granito no "
        "obstante.");

   //En el futuro, tus habitaciones deben de poseer descripciones completas
   //sin que puedan quedarse a medias...
   //Para incluir objetos en las habitaciones se usara el comandor "clone".
   //Estos objetos pueden ser armas, npcs...                                     
   //En general se encontraran el ficheros diferentes a los que hacemos una
   //llamada con la funcion add_clone(dir,num).


   //add_exit(direccion, destino, tipo)

   add_exit("comun","/w/common","door");

   //Esto es necesario para anyadir la salida de common a tu habitacion

   "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
   set_zone("ather");




}
void init()
{
::init();
   add_action("beber","beber");	
   add_action("echar",({"poner","echar"}));
}

int echar(string str)
{
if ((str=="moneda en fuente") || (str=="moneda a fuente"))
	{
	say(this_player()->query_cap_name()+" tira una moneda a la fuente.\n");	
	say("Ves aparecer varias extranyas puertas en los setos\n");
	write("Tiras una moneda a la fuente.\n");
	write("En los setos comienzan a formarse unas extranyas puertas\n");
        add_item(({"puerta","portal"}),"Son una especie de portales"
		   " dimensionales, a traves de los cuales no puedes"
		   " nada en absoluto.\n");
        add_exit("este","/w/ather/gnorks.c","door");
	add_exit("oeste","/w/ather/laberinto.c","door");
	add_exit("norte","/w/ather/silencio.c","door");
	renew_exits();
	return(1);
	}
	return(0);
}

int beber(string str)
{
if(str=="agua")

	{
	tell_object(TP,"Te acercas y bebes un poco de agua.\n");
	tell_room(TP->query_cap_name()+" se acerca a la fuente y bebe un poco de agua.\n",({TP}));	
	tell_room("De repente en la estancia aparece una figura semi-transparente\n");
        new("/w/ather/druida.c",1)->move(TO);
	return(1);
	}	
	return(0);
}

// fin (de la primera parte)  
                                  
