                                    
#define CREATOR "Sharka"

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
  set_short("Sala Principal de la Casa de "+CREATOR);

  set_long("\nSala Principal de la Casa de "+CREATOR".\n\n"
     "   Te encuentras en una habitacion que rebosa paz y  "
     "serenidad de principio a fin. Sus muros estan cubiertos "
     "por antiguas runas de un idioma ya desconocido incluso para  "
     "la mayor�a de los Inmortales.  "
     "A traves de una cupula entra la luz que ilumina la sala. "
     "Al profundizar en la habitacion te fijas en que pareces no estar "
     "solo y como si tu cuerpo desprendiese un aura disipando toda la "
     "maldad que pudiera haber en t�.  "
     "\n\n");

  // Nivel de Luz.   "help light" for details
  set_light(60);

  //add_item() is used to describe ALL nouns you have in descriptions
  add_item("cupula","Al mirar hacia arriba comprendes que has hecho un gesto "
     "estupido.  Ahora te duele la cabeza y no puedes ver bien.\n");

  add_item("runas","Al mirar las runas sientes como si se alejasen de "
     "tu cabeza todos tus problemas. Y NI SIQUIERA SABES LO QUE DICEN!!!\n");

  add_item("muros","Los muros son compactos, como si fueran de una sola pieza "+
     "composicion.  El material del que se compone el muro parece favorecer la "
     "iluminacion de la sala.\n");

  // you can also give many items the same description
// Siendo mi primera sala he decidido no introducir demasiados items

  //SENSES by Sojan.  This adds even more life to your rooms
  add_smell(({"habitacion","ambiente","aire"}),"Todo lo que rodea "
     "el entorno de esta habitacion parece ser agradable. Es como "
     "si te encontrases en el paraiso.\n");

  add_feel(({"muros","paredes","pared"}),"Al tocarlo sientes una peque�a descarga que "
     "se adentra en tu cuerpo y lo llena de vida'\n");

  add_taste(({"muros","paredes","pared"}),"Agghh, que asco. Solo a t� se te ocurriria ponerte "
     "a chupetear una pared\n");

  add_sound(({"habitacion","entorno"}),"Escuchas el ruido del aire "+
     "paseando suavemente por la habitacion.  De repente te duermes\n");

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

add_exit("norte","/w/sharka/casa/baul.c","door");
add_exit("este","/w/sharka/casa/bar.c","door");
add_exit("oeste","/w/sharka/casa/banco.c","door");
add_exit("sur","/w/sharka/casa/tablon.c","door");

  //This is something neat, adds an exit IN the common to this room.


  //"/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");
  //"/w/valar/dormitorio.c"->add_exit( CREATOR,"/w/valar/dormitorio.c","door");

}
