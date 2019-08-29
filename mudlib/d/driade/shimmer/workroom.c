/* Shimmer 20/02/2002 */

#define CREATOR "shimmer"

#include "/d/driade/shimmer/path.h"

inherit "/std/room.c";



void setup()
{
   set_short(CREATOR+"'s workroom");

   set_long("\n%^BOLD%^YELLOW%^Habitacion de%^RESET%^ %^BOLD%^BLUE%^"+CREATOR+"%^RESET%^.\n\n"
      " Estas en una sala grande, amplia y bien iluminada, puedes ver varios portales magicos en la pared "
      "del norte, cada uno de ellos lleva a una de las zonas de Shimmer, el Creador. A tu derecha puedes ver "
      "una gran vitrina de un metal opaco, cubierta por una cristalera. A la izquierda hay una mesa de billar y una "
      "pequenya bolera, asi como algunas maquinas recreativas. (Shimmer viciao !!!).  "
      "Colgadas del techo puedes ver varias maquetas de aviones antiguos y en el centro mismo una pantalla panoramica Sony, "
      "con DVD incluido. :P.\n Hay una cama de agua enorme en el medio de la habitacion y montones de braguitas y sujetadores "
      "por todos lados. Piensas que esto es el paraiso, y que Shimmer es el mejor :P  "
      "\n\n");

   // sets the level of light in the room.   "help light" for details
   set_light(80);

   //add_item() is used to describe ALL nouns you have in descriptions
   add_item("cama","Una enorme cama de agua, esta cubierta de lenceria femenina y puedes ver a dos rubiazas "
      "entre las sabanas esperando por alguien. (Iluso :), esperan por Shimmer.\n");

   add_item("portales","Cuando te acercas a los portales puedes ver como si una imagen se generara en tu mente y te "
      "transportaras al lugar a donde apuntan.\n");

   add_item("paint","The entire room has been painted with a new "+
      "coat of paint.  The paint upon the walls reflects light from "
      "lamp hanging from the center of the room.\n");

   // you can also give many items the same description
   add_item(({"furniture","desk","chair"}),"Facing you against "
      "the far wall, a large desk and chair are set.  The desk and "+
      "chair have a large layer of dust covering their entire "
      "surface.  The chair has nearly worn through and perhaps "
      "is in need of repair.\n");

   add_item(({"ceiling","lamp","small lamp"}),
      "Hanging from the center of the room's ceiling, a small "
      "oil lamp burns continuously emitting ample lighting for "
      "for the room.\n");

   //SENSES by Sojan.  This adds even more life to your rooms
   add_smell(({"room","workroom","air"}),"Here we put what the "
      "player would get when they typed 'smell room'  They should "
      "smell the paint in the air of course.\n");

   add_feel("desk","Here we would put what the player would "
      "get when they typed 'touch desk'\n");

   add_taste("paint","You lick the paint from the wall and soon "
      "realize this was a major mistake...  get this by typing "
      "'taste paint'\n");

   add_sound(({"room","workroom"}),"You hear a rumbling noise "+
      "coming from above.  Get this by typing 'listen room'\n");

   //Remember, when describing your future rooms, always describe
   //everything as richly as possible (not half-baked like these)

   //The following is used to "clone" objects into rooms.
   //These objects can range from NPCs and monsters to weapons.
   //A seperate file (much like this workroom) will be required
   //so we use the function add_clone to bring them into your rooms.

add_clone("/obj/misc/button.c",1);
add_clone(EQUIPO+"gran_espada_shimmer.c",10);
add_clone(EQUIPO+"",1);
add_clone("/obj/misc/button.c",1);




   //Here are the exits from your room
   //add_exit(direction, destination, type)
   //direction - What they must type to leave that direction
   //destination - The room they will be moved to
   //type - The exit type, can be "path","corridor","door"...
   //Read /doc/roomgen/exit_type_help for more info.

add_exit("common","/w/common","door");
add_exit("entryroom","/room/entryroom.c","door");


add_exit("arco",         HAGN+"arco_desolacion.c","standard");
add_exit("arbol",        HAGN+"arbol_ameline.c","standard");
add_exit("zhyrkhom",     ZHYRKHOM+"camino_minas8.c","standard");
add_exit("bosque",       BOSQUEHARAK+"bos1.c","standard");
add_exit("harak",        HARAK+"lad1.c","standard");
add_exit("caminosur",    CAMSUR+"cam65.c","standard");
add_exit("mud",          DRIADE+"entryroom.c","standard");
add_exit("brethem",      BRETHEM+"estatualeon.c","standard");
  
 //This is something neat, adds an exit IN the common to this room.

   "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");

}

// This ends the basic workroom.
// For a workroom with added features such as add_action()'s
// look at workroom2.c 
// This should be in your work directory as well...
