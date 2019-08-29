//modified by Ljen nov -96
//Coded by Joram on the 16th of September '96

inherit "/std/room";
#include "path.h"

object ditt, datt;


void setup(){
   set_light(40);
   set_short("Strange Passage Behind Mirror - Dead End");
   set_long("This seems to be the end of the passage.  Looking carefully "
            "at the rocks of the east wall you see one of them which might  "
            "be moved lately.\n");


   add_exit("north",    SECRET+"c3.c",    "path");
 
}
   

void init()
{
   ::init();
   add_action("do_move","move");
   add_action("do_look", "l*ook");
}

int do_move(string str)
{ 
  if(str != "rock")
   {
     return 0;
   }
/*   if(this_player()->query_property("halfelf_newbie_eq"))
   {

      notify_fail("Seems like someone have been here before you, because "
	    "there is nothing to find here.\n");
      tell_room(environment(this_player()), this_player()->query_cap_name() +" looks "
          "confused as nothing happens when "+
          this_player()->query_pronoun()+" moves the rock.\n",({this_player()}));
      return 0;
   }
*/
   if (str = "rock")

   {
      write("You move the red rock from the east wall to the center "
            "of the passage, discovering a small hole on the wall.  "
            "Looking carefully at the hole you find a chainmail and a "
            "broad sword, the two of them are a bit rusty.\n");
    
      tell_room(environment(this_player()), this_player()->query_cap_name()+" moves"
               " the rock and some equipment falls out from it.\n",({this_player()}));   

  ditt= clone_object("/baseobs/weapons/broad_sword",1)->move(this_player());
  datt= clone_object("/baseobs/armours/chainmail", 1)->move(this_player());
/* this_player()-> add_property("halfelf_newbie_eq",1);*/
    
return 1; 

   }
}


int do_look(string str)
{
  if(str == "rock")
  {
     write("You see a red rock that seems a bit loose.."
	   " Looks like it has been moved.\n");
     return 1;
  }

}
