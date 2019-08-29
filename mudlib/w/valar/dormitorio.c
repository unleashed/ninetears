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
   set_short("Dormitorio de Valar");

   set_long("\nDormitorio de Valar.\n\n"
      "   Ves una habitacion tan enorme como no viste ni en los anuncios " 
      "con un amplia cama de 3 x 3 metros, estatuas suyas por toda la "
      "habitacion y cientos de fotos de tias en bolas."
      "Sobre la cama puedes ver un mural que le fue encargado al mismisimo "
      "Miguel Angel. La habitacion esta repleta de mesas, sillas, armarios."
      " En la mesilla de la cama puedes ver una suculenta bandeja de dulces.\n\n");

   // sets the level of light in the room.   "help light" for details
   set_light(40);

   //add_item() is used to describe ALL nouns you have in descriptions
   add_item("mural","Si te fijas bien parece como si el mural "
      "cobrase vida y �Tu estas dentro!.\n");

   add_item("cama","Una enorme cama con sabanas de seda roja, con un "
      "suave tacto. De repente una voz suena en tu cabeza: �No toques mi cama "
      " o moriras\n");

   add_item("fotos","No son mas que las fotos de sus conquistas. "
      "Parece que ya suman mas de un millon XD. Si te fijas bien "
      "descubriras que las fotos venian con el marco (Jeje).\n");
      
   add_item("bandeja","Una bandeja de plata de ley con unos dulces de aspecto "
      "muy apetitoso\n");

   // you can also give many items the same description
   add_item(({"armarios","mesas","mesa","sillas","cortinas"}),"Toda la habitacion "
      "esta finamente decorada con los gustos mas esquisitos y los mas bellos y "
      "comodos muebles.\n");

      //SENSES by Sojan.  This adds even more life to your rooms
   add_smell(({"habitacion","cortinas","cama","aire","ambiente"}),"Todo huele "
      "deliciosamente, parece como si oliese a aquello que mas te gustase, "
      "como si la habitacion estuviera hecha para ti. LA ENVIDIA TE CORROE!!!.\n");

   add_feel("mesa","La mesa tiene un tacto suave y liso, �Si es que esta hecha de marmol!"
      ", como iba a ser si no?\n");

   add_taste("dulces","Sientes un tremendo dolor en el estomago. Has cogido el "
      "dulce prohibido y ahora la ira de Valar caera sobre ti, pero antes te vas corriendo "
      "al banyo porque estas que te cagas encima\n");

   add_sound(({"habitacion","pajaros"}),"Eschucas el dulce trinar de los ruisenyores "
      "en su canto matutino al alba\n");

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

   add_exit("entrada","/w/valar/workroom.c","door");
   add_exit("armario","w/valar/armario.c","hidden");
   add_exit("armadura","w/valar/baularmadura.c","hidden");
   add_exit("armas","w/valar/baularmas.c","hidden");
   //This is something neat, adds an exit IN the common to this room.

   "/w/valar/workroom.c"->add_exit( CREATOR,"/w/valar/workroom.c","door");
}
