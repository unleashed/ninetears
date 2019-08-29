//COBRA
#include "path.h" 
 inherit CASTLE+"baseroom2.c";
void setup() { my_setup();

   add_property("no_undead",1);
set_short("Realm of the Orc:  Staircase"); 
set_light(40); 
        set_long("\n   Realm of the Orc:  Staircase.\n\n"
                 "     You are on the path leading up to the Tower of "
         "Grishnath.  There are some bushes here and some orcs working "
         "on the steps up the mountain. You have an excellent view over "
	    "the area around the mountain from here and when you look down "
	   "you see a little town there, but it difficult to say if there are "
	   "people down there."
	   "\n\n");
	
	add_item(({"orcs","orc"}), "This is some orcs that just want to be "
				   "finished with their work and go away "
				   "from this place again.\n");
   add_item(({"bush","bushes"}),"  These bushes are probably the "
        "only vegitation left on this barren mountainside.  They "
        "too are close to death.  You catch a faint glimpse of "
        "something in there.\n");
	add_item(({"path", "stairs"}), "This path is leading up to the " 
                                       "Tower and down from the Tower. " 
                                       "The stairs here is covered with " 
                                       "dirt, but you can see that it is " 
                                       "roughly made.\n"); 
        add_item("tower", "You turn your eyes to the tower and you know " 
                          "you're looking upon the Tower of Grishnath, "  
                          "home of morbid creatures that haunted your " 
                          "childhood.\n"); 
add_exit("west",CASTLE +"orc25","path"); 
add_exit("southeast",CASTLE +"orc28","path"); 
} 
void init() 
{ 
   ::init(); 
   add_action("do_search","move");
} 
int do_search(string str)
{ 
  if (!str)
   {
   write("\nYou search around but you don't find anything.\n"
       "\n");
   return 1;
    }
  else
   if(str == "bushes") 
   { 
      tell_object(this_player(),"You slip as you scrounge round in the bushes, "
				"and fall backwards through a hatch in the wall.\n"); 
      tell_room(this_object(),(string)this_player()->query_cap_name()+" suddenly "
		"screams, and is gone !\n",({ this_player() }) ); 
      this_player()->move(CASTLE+"orc27"); 
      this_player()->look_me(); 
  return 1;
   } 
  else
  {
   write("You search around but you don't find anything.\n");
  return 1;
  }
} 
