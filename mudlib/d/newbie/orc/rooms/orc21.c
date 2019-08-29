//COBRA
#include "path.h" 

 inherit CASTLE+"baseroom.c";
 void setup() { my_setup();
   add_property("no_undead",1);
	set_short("Realm of the Orc:  Cliff"); 
	set_light(40); 
        set_long("\n   Realm of the Orc:  Cliff.\n\n"
                 "     You are now standing on the edge of the cliff and "
		 "to the north is there a HUGE tower.  You have an excellent "
		 "view from here and you can see a lot of the area around "
		 "the cliff.  You wonder why there is so little vegitation "
	         "here. The ground is covered with several rotten corpses "
		 "and you begin to feel ill and want to throw up. "
		 "\n\n");


add_item("tower", " \n"
"  The tower has many spires all grasping toward the heavens. "
"The spires are long and look fiendish as if they have some evil purpose.\n");
	add_item("corpse", "These are the corpses of previous adventures that "
                      "didn't know how dangerous the tower was and "
                      "got themselves killed.\n");

	add_item(({"drawbrigde", "brigde"}), "The drawbrigde is the only way "
           "to the tower. It's looks old and well used. "
           "But you can still use it to enter the "
           "tower.\n\n");

	add_item("path", "This is the path that leads down from the mountain, "
			 "it's pretty hard to climb down from here so you "
			 "must watch your steps.\n\n");

	add_smell(({"air","corpse"}), "The air smells rotten just because of "
		       "the dead bodys here, you wish that you would "
		       "have a mask to cover your mouth with.\n\n");


	add_exit("north",CASTLE +"orc19","path"); 
	add_exit("down",CASTLE +"orc23","path"); 
}
