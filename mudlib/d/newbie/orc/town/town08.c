//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit "std/pub";
#include "pub.h"
mixed top_list, top_deaths;
void add_to_list(object ob);

object gorbag;
object globe;

void reset()
{
   if(!gorbag)
      {
      gorbag = clone_object(CHAR+"gorbag");
      gorbag->move(this_object());
   }
   if (!globe)
     {
     globe = clone_object("/obj/misc/globe");
     globe->move(this_object());
     }
}

void setup()
{
   add_menu_item("Beer", ALCOHOL, 20, 2, 10, 10, 
      "drink your beer", "drinks a pint of beer");
   add_menu_item("Ale", ALCOHOL, 40, 3, 20, 20, 
      "drink a pint of ale", "drinks a pint of ale");
   add_menu_item("Mead", ALCOHOL, 100, 4, 40, 40, 
      "hurl down the mead", "hurls down the mead and burps");
   add_menu_item("Whisky", ALCOHOL, 500, 8, 200, 200, 
      "gulp down some boring home-made whisky",
      "gulps down some whisky");
   add_menu_item("Peanuts", FOOD, 20, 1, 10, 6,
      "eat some peanuts", "eats some peanuts");
   add_menu_item("Stew", FOOD, 200, 4, 150, 0, 
      "eat a healthy meal of stew", "eats some stew");
   add_menu_item("Roasted boar", FOOD, 1000, 7, 500, 0, 
      "eat a whole roasted boar", "eats a whole roasted boar");
   add_menu_item("Milk", SOFTDRINK, 6, 1, 5, 5,
      "drink a glass of milk", "drinks a glass of milk");
   add_menu_item("Water", SOFTDRINK, 1, 0, 0, 0,
      "drink a glass of water", "drinks a glass of water");
   add_menu_item("Tea", SOFTDRINK, 3, 0, 1, 1,
      "sip a cup of tea", "sips a cup of tea");
   add_menu_item("Nectar", SOFTDRINK, 30, 1, 15, 15,
      "drink a flask of delicious nectar", "drinks a flask of nectar");
   add_menu_alias("milk", "Milk");
   add_menu_alias("sushi", "Sushi");
   add_menu_alias("water", "Water");
   add_menu_alias("tea", "Tea");
   add_menu_alias("nectar", "Nectar"); 
   add_menu_alias("peanuts", "Peanuts");
   add_menu_alias("stew", "Stew");
   add_menu_alias("roasted boar", "Roasted boar");
   add_menu_alias("boar", "Roasted boar");
   add_menu_alias("beer", "Beer");
   add_menu_alias("ale", "Ale");
   add_menu_alias("whisky", "Whisky");
   add_menu_alias("whiskey", "Whisky");
   add_menu_alias("mead", "Mead");
   set_short("Realm of the Orc:  Gorbag's Tavern");
   set_long("\n   Realm of the Orc:  Gorbag's Tavern.\n\n"
            "     This is a small tavern owned by Gorbag.  "
            "There is not much here to see since the trash and "
            "grime have covered everything up.  There are a number "
            "of Orcs here drinking and talking.  Most of them do "
            "not appear to be too friendly.  The bar is along the "
            "eastern wall and you might be able to wade over to it "
            "and check out the menu.  "
            "\n\n");
   
	add_exit("north", TOWN+"town04.c", "door");
   
   set_light(60);
   set_zone("pub");
   
	add_item("bar","The bar stretches along the eastern wall and "
		"is covered with empty mugs and the remains of food "
		"items that are served here.  Behind the bar sits a menu "
		"next to the shelves where the various containers of "
		"the drinks are located.  "
		"\n\n");
	add_item("table","The tables are covered with empty beer mugs "
		"and plates of scraps from what must have been a great "
		"feast.\n\n");
	add_item(({"mugs","beer mugs"}),"The mugs are empty.  The number "
		"of drunken Orcs here is probably the reason.\n\n");
	add_item(({"plates","scraps"}),"The plates are covered with "
		"the bones of some animal.  It must have been some " 
		"good eating, because there is not much left.\n\n");
}

int dest_me()
{
   if (gorbag)
      gorbag->dest_me();
   if (globe)
     globe->dest_me();
   ::dest_me();
}

