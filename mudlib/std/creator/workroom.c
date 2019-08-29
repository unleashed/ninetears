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
   set_short(CREATOR+"'s workroom");

   set_long("\nWorkroom of "+CREATOR+".\n\n"
      "   The workroom you find yourself standing in has a new layer "
      "of paint.  A normal assortment of dusty furniture is "
      "arranged around the room.  The most important being the "
      "large desk and old chair against the far wall facing you.  "
      "Hanging from the ceiling, a small lamp gives ample light for "
      "the room.  With some consideration, you decide the room "
      "is in need of cleaning.  "
      "\n\n");

   // sets the level of light in the room.   "help light" for details
   set_light(80);

   //add_item() is used to describe ALL nouns you have in descriptions
   add_item("workroom","The workroom surrounds you with the smell "
      "of a fresh coat of paint.  The walls glisten in the light.\n");

   add_item("wall","All four walls are white frshly coated with "
      "paint.\n");

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

   //Here are the exits from your room
   //add_exit(direction, destination, type)
   //direction - What they must type to leave that direction
   //destination - The room they will be moved to
   //type - The exit type, can be "path","corridor","door"...
   //Read /doc/roomgen/exit_type_help for more info.

   add_exit("common","/w/common","door");
  add_exit("entryroom","/room/entryroom.c","door");

   //This is something neat, adds an exit IN the common to this room.

   "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");

}

// This ends the basic workroom.
// For a workroom with added features such as add_action()'s
// look at workroom2.c 
// This should be in your work directory as well...
