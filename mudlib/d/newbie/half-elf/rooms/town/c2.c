//Ljen -97

#include "path.h"
inherit "std/pub";
#include "pub.h"

void setup()
{
    set_short("Jungle Town Tavern");
   
    set_light(80);
   
    set_long("This is the tavern of the small town."
             " It is a small and quiet place, doesn't seem like"
	     " there are too many visitors. There is a small fireplace"
	     " in the corner, giving some light. The barkeep is a small"
	     " man, with a long white beard, and a tired smile on his face.\n"); 
   
    add_item("bar","A long wooden bar running the entire length of the"
             " north wall. It doesn't seem like it has been cleaned for"
	     " the last year or so.\n");
   
    add_item(({"table","tables"}),"A group of small dusty tables sits in" 
               " the corner. They appear to be made from wood, and you"
               " wonder where the chairs are (or even if there were any).\n");
    
    add_item(({"bottle","bottles"}),"Several bottles made from different" 
               " colored glass, they are so dusty it is difficult"
               " to see what is in them.\n");
   
    add_item("shelf","A long wooden shelf hanging from the wall.\n");
   
    add_exit("east",TOWN+"d2.c","path");

   add_menu_item("Orange Juice", ALCOHOL, 30, 15, 15, 15,
      "carefully sip the juice", "slowly drinks a glass of juice");


   add_menu_item("Fried Banana", FOOD, 100, 100, 100, 0,
      "eat a generous portion of fried banana",
      "eats a generous portion of fried banana");

   add_menu_item("Tea", SOFTDRINK, 5, 0, 1, 0,
      "drink a cup of tea", "drinks a cup of tea");

   add_menu_item("Coffee", SOFTDRINK, 10, 1, 3, 0,
      "drink a cup of coffee", "drinks a cup of coffee");
   add_menu_alias("orange juice","Orange Juice");
   add_menu_alias("juice","Orange Juice");
   add_menu_alias("orange","Orange Juice");
   add_menu_alias("fried banana","Fried Banana");
   add_menu_alias("banana","Fried Banana");
   add_menu_alias("Banana","Fried Banana");
   add_menu_alias("tea","Tea");
   add_menu_alias("coffee","Coffee");



}


