//Modified by Ljen okt -96
//Coded by Joram on the 16th of September '96

inherit "/std/room";
#include "path.h"

void init(){
   ::init();
   add_action("do_pass","enter");
}


void do_pass(string str){
   if(str="mirror") {
                   write("You step onto the mirror and .....");
                   this_player()->move(SECRET+"c1");
                   this_player()->look_me();
tell_room(environment(this_player()), this_player()->query_cap_name()+" steps into the "
                  "mirror and disappears in it\n", ({this_player()} ));
                   return 1;
                  }
}

void setup(){
   set_short("Castle Of The Green Sun: Lab");
   set_long("The lab room of the red wizard has seen better years.  Today it "
            "is a forgotten room, where the rats and other insects come and go "
            "as they wish.  There is a table at the center of the room on which "
            "you can see the special glasses used by the wizard to create "
            "his potions and scrolls.  On the south wall there is a big glowing "
            "mirror, in each of its sides, there are two torches.\n");

   add_item(({"big mirror","mirror"}), "A strange bronze mirror, which "
                                       "glows with a bright red light. "
 				       "It seems as if you could 'enter' it.\n");
   add_item(({"glass","glasses"}), "They are of different forms and sizes, "
                                   "some of them still have a content, but "
                                   "most have nothing but the rest of some "
                                   "undescriptible substance.\n");

  add_item("table","A big old wooden table, where the wizard used to perform "
                   "his experiments.\n");


   add_item(({"torch","torches"}), "A common torch with a wooden haft and a cloth head "
                     "swet in oil\n");



   set_light(50);


   add_exit("north", CAST+"b4.c", "door");
}

    
