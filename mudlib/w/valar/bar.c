#define CREATOR "valar"
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
   set_short("Bareto");

   set_long("\nValar�s Last Drink.\n\n"
      "   Te encuentras en el bar propiedad de Valar que se ha hecho instalar "
      "en su propia casa. El bar esta iluminado con una luz suave y tenue. Es "
      "un situo pequenyo, tranquilo y acogedor. Tras la barra del bar puedes "
      "ver infinidad de botellas de todos los tipos y clases. Es una equina "
      "puedes ver varios sofas y una television muy grande. Las paredes estan "
      "adornadas con fotografias en blanco y negro de famosos que han pasado por"
      " este mud. En una esquina de la barra puedes ver unos vasos de cristal.\n\n");

   // sets the level of light in the room.   "help light" for details
   set_light(20);

   //add_item() is used to describe ALL nouns you have in descriptions
   add_item("barra","ves una barra de bar larga de unos 5 metros en color "
      "negro.\n");

   add_item("botellas","Ves botellas de licor de clases que nunca habias "
      "imaginado que existiesen. Tambien puedes ver otras mas familiares para"
      " ti.                   "
      "En la primera estanteria hay botellas de Ron, Ginebra, Whisky, Vodka."
      "En la segunda estanteria hay botellas de licores de todos los sabores"
      "En la tercera estanteria hay botellas de Martini, Ponche y otras q no "
      "alcanzas a leer."
      " Por ultimo ves en la estanteria mas alta una seleccion de botellas de "
      "especial calidad reservadas para los mas VIP del mud\n");

   add_item("television","Te fijas bien y no es una television, sino un espejo"
      "magico a traves del cual se puede ver cualquier cosa que este ocurriendo "
      "en el mud en ese preciso momento.\n");
add_item("sofas","Unos sofas de aspecto comodo, hechos en piel negra muy resistente.\n");
   
   // you can also give many items the same description
   add_item(({"vasos","copas","chupitos"}),"Ves en un rincon de la barra una serie de "
      "vasos dispuestos para ser utilizados ya mismo (A que te apetece una copa?).\n");

      //SENSES by Sojan.  This adds even more life to your rooms
   add_smell(({"aire","ambiente"}),"El aire se respira limpio y puro "
      "como si te encontrases en la montanya.\n");

   add_feel("sofas","Te tumbas en el sofa y te sientes comodo como  "
      "nunca. Deberias preguntarle a Valar donde lo compro, es una "
      "buena inversion.\n");

   add_taste("ron","Sientes el suave y dulce sabor del ron recorriendo "
      "tu paladar hasta llegar a tu estomago.\n");
      
   add_taste("ginebra","Ese trago te va a costar caro, se te saltan las "
      "lagrimas. Creo que vas a estar comiendo papillas una temporada.\n");

   add_taste("whisky","Pruebas un buen trago de este whisky especial de la "
      "casa. Nunca probaras uno mejor que este.\n");
      
   add_taste("vodka","Que te voy a decir. Autentico Vodka ruso traido desde la"
      " madre Rusia. Un sabor fuerte y seco a la vez.\n");
   add_taste("martini","Un sabor un tanto amargo, deberias haberlo mezclado con"
      "algo.\n");

   add_sound(({"habitacion","bar"}),"Hey!, estan poniendo tu cancion"
      "favorita. Es que no piensas bailar?.n");

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

  add_exit("fuera","/w/valar/workroom.c","door");
  

   //This is something neat, adds an exit IN the common to this room.
  
}
