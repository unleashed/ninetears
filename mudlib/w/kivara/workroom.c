#define CREATOR "kivara"
/* New workroom.c for newbie immortals.  Same basic functions
 * as the old one, but isn't going to force the entire mudlib
 * down your throat in comments.
 *
 * Radix : September 27, 1995
 */

inherit "/std/room.c";
// inherit the file "/std/outside.c" if you want clouds and such.


void setup()
{
   set_short("El taller de "+CREATOR);

   set_long("\nEl taller de "+CREATOR+".\n\n"
   	  "   Te encuentras en una estancia pequenya pero acogedora, "
   	  "el lugar de trabajo de Kivara. Esta un poco desordenada, "
   	  "con artilujos y herramientas por todos sitios. La sensacion "
   	  "de desorden es mayor cuando miras la estanteria de madera, "
   	  "llena de libros y hojas. En la pared de la izquierda hay un "
   	  "gran poster y un gran ventanal, por el que entra la clara luz "
   	  "del Sol. En el centro de la habitacion hay una gran mesa de "
   	  "madera de boj finamente decorada, llena de mas papeles escritos "
   	  "en alguna lengua extranya que no logras descifrar.  "
   	  "\n\n");      

   // sets the level of light in the room.   "help light" for details
   set_light(80);

   //add_item() is used to describe ALL nouns you have in descriptions
   add_item("habitacion","La habitacion parece desordenada la primera "
   		"vez que la ves, aunque luego parece que cada elemento haya "
   		"sido colocado en su sitio no por azar, si no siguiendo alguna "
   		"extranya metodologia.\n");

   add_item("pared","Las 4 paredes estan pintadas de un suave color azul "
   		"con algunas manchas de humedad en las esquinas.\n");

   add_item("poster","Se trata de un gran dibujo de la diosa de la "
   		"belleza, Yez. Te parece el ser mas bello que has visto "
   		"nunca.\n");

   // you can also give many items the same description
   add_item(({"estanteria","mueble"}),"Una sencilla estanteria de "
   		"madera de pino llena de libros");
   add_item("mesa","Ves una gran mesa de madera que ocupa la mitad "
   		"de la sala, llena a rebosar de papeles y documentos.");

   add_item("techo","No ves ninguna lampara colgando del techo, cosa "
   		"que no te extranya, ya que Kivara no las necesita debido a la " 
   		"excelente vision nocturna de los elfos");

   //SENSES by Sojan.  This adds even more life to your rooms
   add_smell(({"taller","habitacion","aire"}),"Un intenso olor a "
   		"madera de pino inunda la habitacion.\n");


   //Remember, when describing your future rooms, always describe
   //everything as richly as possible (not half-baked like these)

   //The following is used to "clone" objects into rooms.
   //These objects can range from NPCs and monsters to weapons.
   //A seperate file (much like this workroom) will be required
   //so we use the function add_clone to bring them into your rooms.

   add_clone("/obj/misc/button.c",1);

   //Here are the exits from your room
   //add_exit(direction, destination, type)
   //direction - What they must type to leave that direction
   //destination - The room they will be moved to
   //type - The exit type, can be "path","corridor","door"...
   //Read /doc/roomgen/exit_type_help for more info.

   add_exit("comun","/w/common","door");
  add_exit("entrada","/room/entryroom.c","door");
  add_exit("subcavernas4","/w/kivara/cavernas4/Sub4_0.c","door");
  add_exit("encantes","/w/kivara/encantes.c","door");

   //This is something neat, adds an exit IN the common to this room.

   "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");

}

// This ends the basic workroom.
// For a workroom with added features such as add_action()'s
// look at workroom2.c 
// This should be in your work directory as well...

void init()
{
   ::init();
   add_action("tocar_poster","tocar");
  
}

int tocar_poster(string str)
{
   if(str == "poster")
   {
      write("Cuando acercas tu mano al poster de Yez, una fuerza divina "
      	"te hace retroceder.\n");      
      return(1);
   }
   notify_fail("Tocar que?\n");
   return(0);
}