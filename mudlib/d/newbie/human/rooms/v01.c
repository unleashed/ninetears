#include "path.h"
inherit "std/pub";
#include "pub.h"

object kel;
void setup()
{
    add_property("no_undead",1);
    set_short("Isle of Havmand: Tavern");
    set_light(LIGHT-20);
    set_long("\nIsle of Havmand: Tavern.\n\n"
    "   This is a small seldom used tavern. There is a long bar along one wall, "
    "and several small dusty tables in one corner. A number of murky-looking "
    "bottles sit on a shelf behind the bar, but there is a general feeling of "
    "neglect. "
    "\n\n");
    add_item("bar","A long wooden bar running the entire length of the north wall. "
    "It is very dusty and looks as if it could do with a good clean.\n");
    add_item(({"table","tables"}),"A group of small dusty tables sits in the "
    "corner. They appear to be made from wood, and you wonder where the chairs "
    "are (or even if there were any).\n");
    add_item(({"bottle","bottles"}),"Several bottles made from different colored "
    "glass, they are so dusty it is difficult to see what is in them.\n");
    add_item("shelf","A long wooden shelf hanging from the wall.\n");
    add_item("dust","Thick dust covers everything, adding to the air of neglect.\n");

    add_exit("east",HAVMAND+"t03.c","path");
    add_exit("down",HAVMAND+"v07.c","path");

   add_menu_item("Apple Cider", ALCOHOL, 30, 15, 15, 15,
      "carefully sip the cider", "slowly drinks a glass of cider");


   add_menu_item("Biscuits and Gravy", FOOD, 100, 100, 100, 0,
      "eat a generous portion of biscuits and gravy",
      "eats a generous portion of biscuits and gravy");

   add_menu_item("Tea", SOFTDRINK, 5, 0, 1, 0,
      "drink a cup of tea", "drinks a cup of tea");

   add_menu_item("Coffee", SOFTDRINK, 10, 1, 3, 0,
      "drink a cup of coffee", "drinks a cup of coffee");

   add_menu_alias("apple cider","Apple Cider");
   add_menu_alias("cider","Apple Cider");
   add_menu_alias("apple","Apple Cider");
   add_menu_alias("biscuits and gravy","Biscuits and Gravy");
   add_menu_alias("Biscuits","Biscuits and Gravy");
   add_menu_alias("biscuits","Biscuits and Gravy");
   add_menu_alias("Gravy","Biscuits and Gravy");
   add_menu_alias("gravy","Biscuits and Gravy");
   add_menu_alias("tea","Tea");
   add_menu_alias("coffee","Coffee");


   set_zone("pub");

}

void reset()
{
   if(!kel)
   {
      kel = clone_object(CHARS+"oldman.c");
      kel->move(this_object());
   }

}
void dest_me()
{
    if(kel) kel->dest_me();
    ::dest_me();
}

