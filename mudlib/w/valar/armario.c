#define CREATOR "valar"


inherit "/std/room.c";
// inherit the file "/std/outside.c" if you want clouds and such.


void setup()
{
   set_short("Armario Secreto");

   set_long("\nArmario de Valar\n\n"
      "   Estas en el armario secreto de Valar, aqui no hay nada importante, "
      "solo es el sitio donde valar guarda su ropa y tu te has metido en el. "
      "No crees que eres un poco rarito? "
      "En el armario te encuentras ropas, armas y armaduras de distintos "
      "tipos y clases, nada mas�."
      "\n\n");

   // sets the level of light in the room.   "help light" for details
   set_light(20);

   //add_item() is used to describe ALL nouns you have in descriptions
   add_item("armas","Nada inusual, tan solo son armas viejas oxidadas.\n");
      
   add_item("armaduras","Una eeplendorosa coleccion de armaduras de todas las "
      "clases y formas.\n");

   add_item("ropas","Ropajes del mas fino estilo, de seda, de cachemir, de "
      "todas las marcas.\n");

   // you can also give many items the same description
   add_item(({"puertas","fondo","madera"}),"El armario esta realizado "
      "con las maderas mas caras y de mejor calidad. Se trata de un mueble "
      "antiguo, del reinado de Enrique IV que le fue arrebatado por una apuesta "
      "que no quiso pagar.\n");

      //SENSES by Sojan.  This adds even more life to your rooms
   add_smell(({"aire","paredes","barniz"}),"El aire huele aun a la "
      "ultima capa de barniz que se le puso al armario, como sigas "
      "respirando te va a dar un subidon que no veas.\n");

   add_feel("paredes","ouch, parece que te has clavado una astilla, "
      "deberias ir al medico a que te la vieran.\n");

      add_sound(({"armario","paredes"}),"Golpeas el armario y escuchas "
      "el sonido hueco del mismo.\n");

   //Remember, when describing your future rooms, always describe
   //everything as richly as possible (not half-baked like these)

   //The following is used to "clone" objects into rooms.
   //These objects can range from NPCs and monsters to weapons.
   //A seperate file (much like this workroom) will be required
   //so we use the function add_clone to bring them into your rooms.

      //Here are the exits from your room
   //add_exit(direction, destination, type)
   //direction - What they must type to leave that direction
   //destination - The room they will be moved to
   //type - The exit type, can be "path","corridor","door"...
   //Read /doc/roomgen/exit_type_help for more info.

   add_exit("fuera","/w/valar/dormitorio.c","door");
  add_exit("casa","/w/valar/workroom.c","hidden");

   //This is something neat, adds an exit IN the common to this room.

   
}

// This ends the basic workroom.
// For a workroom with added features such as add_action()'s
// look at workroom2.c 
// This should be in your work directory as well...
