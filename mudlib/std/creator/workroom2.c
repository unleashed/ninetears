/* Additional workroom for newbie Builders.  This one is basically the
 * the same as workroom.c but has stripped out descriptions but added
 * in add_action()'s so you can "move desk" or whatever in your 
 * workrooms.
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

   set_light(80);

   add_clone("/obj/misc/button.c",1);

   add_exit("common","/w/common","door");
  add_exit("entryroom","/room/entryroom.c","door");

   "/w/common.c"->add_exit( CREATOR,"/w/"+CREATOR+"/workroom","door");

}

// Here we put add_action()'s that call whatever funtion you want.
void init()
{
   ::init();
   add_action("clean_desk","clean");
   add_action("move_desk","move");
}

int clean_desk(string str)
{
   if(str == "desk")
   {
      write("You begin to clean the desk and find a newspaper.\n");

      say(this_player()->query_cap_name()+" cleans the desk and finds "
            "a newspaper.\n");

      clone_object("/obj/misc/newcreator_paper.c")->move(this_object());
      return(1);
   }
   notify_fail("Everything in the room seems clean except the desk.\n");
   return(0);
}

int move_desk(string str)
{
   if(str == "desk")
   {
      write("You forcefully move the desk and discover a trap door!\n");

      say(this_player()->query_cap_name()+" moves the desk around.\n");

      add_exit("trap door","/room/void.c","door");

      renew_exits();
      return(1);
   }
   notify_fail("Move what?\n");
   return(0);
}
