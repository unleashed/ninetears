//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Dead End");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Dead End\n\n"
	 "     This is a dead end in the tunnel.  There is no way "
		"to go further south because the river takes up the "
		"entire cave.  You dare not try to go against the "
		"strong current, you will be swept over the falls for "
		"sure.  Back in a corner sits a bright campfire.  "
		"There is also a straw mat up against the wall.  "
		"A small piece of parchment lies partially buried "
		"in the sand here.  "
		"It looks as though someone might live here.  "
		"The only exit is the path to the north.  "
		"\n\n");
     add_item("river","The river comes out of a small cave to the "
            "north and goes over the waterfall to the south.  "
          "\n\n");
	add_item(({"falls","waterfall"}),"You cannot clearly see the "
		"waterfall from here, but you can hear it."
		"\n\n");
	add_sound(({"falls","waterfall"}),"The sound of the falls is not as "
		"loud here due to the distance but it still hurts your "
		"ears a little."
		"\n\n");
	add_item("sand","The sand here is just a very thin coating that "
		"covers the cave floor.  It must have been created by "
		"the sheer power of the river chiping away at the rocks."
		"\n\n");

	add_item(({"campfire","fire"}),"This is a bright fire set back "
		"into a small hole in the cave wall.  It adds a bit of "
		"warmth to the cold, damp cave.  "
		"\n\n");
	add_item(({"mat","straw mat"}),"The straw mat must serve as a "
		"bed for the old hermit.  It is positioned up against "
		"fairly close to the fire, but not too close.  It does "
		"not really look comfortable.  "
		"\n\n");
   add_item(({"parchment","old parchment"}),"This is an old piece of "
      "parchment lying half buried in the sand.  It has some writing "
      "on it.  It looks very fragile so you should handle it very "
      "carefuly.\n\n");
add_exit("north",ROOM+"dwarf42","path");
add_clone(CHAR+"hermit.c",1);
}
void init(){
     add_action("give_me","give");
     add_action("get_me","get");
      ::init();
      }

int give_me(string str){
     object *stuff;
     int d=0;
     int c;
     if(str == "bread to hermit"){
          stuff = all_inventory(this_player());
          for(c=0; c<sizeof(stuff);c++)
          {
               if(stuff[c]->query_name()=="loaf of bread")
               {
                    ++d;
                    write("The hermit takes the bread and eats it "
                          "very quickly.  He thanks you with a smile "
                          "and goes over to the straw mat and lays "
                          "down.\n\n");
                          this_player()->add_property("bread",1);
                    stuff[c]->dest_me();
                    return 1;
               }
          }
     }
}

int get_me(string str)
   {
   if(str == "parchment")
      {
	if(present("hermit"))
         {
         if(this_player()->query_property("DWARVEN_ROPE"))
            {
            write("The hermit says, 'There is nothing else you can "
                  "learn here.  Go forth and use the knowledge you have.\n");
            this_player()->remove_property("bread");
            return(1);
            }
         else
         {
         if(this_player()->query_property("bread"))
            {
            write("You get the parchment while the hermit is sleeping.\n");
            clone_object(MISC + "parchment.c")->move(this_player());
            this_player()->remove_property("bread");
            return(1);
            }
         else
            {
            write("The hermit steps in front of you and doesn't allow "
                  "you to reach the parchment.\n");
            return(1);
            }
         }
         }
      else   
         {
         write("The parchment has been totally destroyed by the hermit. "
               " It is worthless.\n");
         return(1);
         }
      }
   }


