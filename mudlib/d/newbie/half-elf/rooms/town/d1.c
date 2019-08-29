//Ljen -97, and Taniwha helped :)
//Coded by Yalaba on the 29th of August of '96

inherit "/std/outside";
#include "path.h"
int banana;


void init(){
    ::init();
    add_action("take_from","take");
    add_action("do_crawl", "crawl");


}
void take_from(string str){
   object ob;

    if (str !="banana"){notify_fail("You want to take what ?\n");return 0;}
    if (str =="banana"){
	if(banana > 3) 
	{
	    notify_fail("All the bananas are gone.!\n");
	    return 0;
	}
	write("You take a banana from the tree\n");
	tell_room(environment(this_player()),this_player()->query_cap_name()+" takes "
	  "a banana from the banana tree, fumbles and it falls to the ground\n",({this_player()}) );
	ob = new(ITEMS+"banana");
	ob->move(TO);
         banana++;
    }
}
void reset()
{
   banana--;
      ::reset();
}

void setup(){
    set_short("Jungle Town - orchard");

    set_long(" This is the eastern part of the fruit orchard in the town." 
      " It is small, but still"
      " it provides the inhabitants with all that they need."
      " The largest tree is actually a banana tree, it is the largest"
      " you ever have seen. The birds are singing and it smells"
      " delicious of fruit and earth. Truly a wonderful place.\n"
      "%^YELLOW%^Banana %^BOLD%^GREEN%^Tree%^RESET%^ is here\n");
    set_light(80);


    add_clone(NPC+"h_elf",1);

    add_item("banana tree","One of the largest banana trees you have"
      " ever seen. It looms over you and the leaves are slowly"
      " moving in the wind, as to invite you to taste a fruit."
      " It is surrounded by dense bushes, one looks a bit strange..\n");
    
    add_item("bush", "A small bush, with small markings on the branches."
	     " Seems like someone have been crawling through it somehow.\n");
    add_item(({"branches","branch"}),"Now you really can see that someone " 
		"has been crawling through here.\n");
    add_exit("south", TOWN+"d2"   ,  "path");
    add_exit("west" , TOWN+"c1"   ,  "path");


}


void do_crawl(string str)
{
	if(str !="bush")
           {
               notify_fail("You want to crawl where?\n");
               return 0;
           }
        if(str =="bush")
           {
               write("\nAs you squeeze your body under the bush you suddenly"
	             " fall down in a dark and moist cavern.. "
	             " This doesn't seem like a good place to be... \n\n\n\n");
	       this_player()->move(DROW+"a2.c");
               this_player()->look_me();
	       return 1;
           }
}

