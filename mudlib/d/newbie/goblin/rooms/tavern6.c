//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
#include "pub.h"
inherit "std/pub";
mixed top_list, top_deaths;
void add_to_list(object ob);

object gnash;

void reset()
{
   if(!gnash)
      {
      gnash = clone_object(CHAR+"gnash.c");
      gnash->move(this_object());
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
   add_menu_item("Mush", FOOD, 20, 1, 10, 6,
      "eat some mush", "eats some mush");
   add_menu_item("Rat stew", FOOD, 200, 4, 150, 0, 
      "eat a nasty bowl of rat stew", "eats some rat stew");
   add_menu_item("Roasted rat", FOOD, 1000, 7, 500, 0, 
      "eat a whole roasted rat", "eats a whole roasted rat");
   add_menu_item("Water", SOFTDRINK, 1, 0, 0, 0,
      "drink a glass of water", "drinks a glass of water");
   add_menu_alias("water", "Water");
   add_menu_alias("mush", "Mush");
   add_menu_alias("rat stew", "Rat stew");
add_menu_alias("stew","Rat stew");
   add_menu_alias("roasted rat", "Roasted rat");
   add_menu_alias("rat", "Roasted rat");
   add_menu_alias("beer", "Beer");
   add_menu_alias("ale", "Ale");
   add_menu_alias("whisky", "Whisky");
   add_menu_alias("whiskey", "Whisky");
   add_menu_alias("mead", "Mead");
set_short("Realm of the Goblin:  Headless Dwarf Tavern");
set_long("\nRealm of the Goblin:  Headless Dwarf Tavern\n\n"
  "This tavern is crowded with very drunk goblins, most of which "
   "are passed out on the floor. The tavern is run by G'nash, when he is "
   "sober anyway. There is a bar and some stools in the back of this cave where "
   "you can purchase some food or drink. There is a small menu above the "
  "bar.\n\n");
add_property("no_undead",1);

	add_exit("north", ROOM+"ngob5.c", "door");

   set_light(60);
   set_zone("pub");

	add_item("bar","The bar stretches along the western wall and "
		"is covered with empty mugs and the remains of food "
		"items that are served here.  Behind the bar sits a menu "
		"next to the shelves where the various containers of "
		"the drinks are located.  "
		"\n\n");
	add_item("table","The tables are covered with empty beer mugs "
		"and plates of scraps from what must have been a great "
		"feast.\n\n");
	add_item(({"mugs","beer mugs"}),"The mugs are empty.  The number "
		"of drunken Goblins here is probably the reason.\n\n");
	add_item(({"plates","scraps"}),"The plates are covered with "
		"the bones of some animal.  It must have been some " 
		"good eating, because there is not much left.\n\n");
	add_item(({"fireplace","hearth"}),"This seems to be a popular "
		"place to chase away the cold.  There are a number of "
		"drunken customers sitting on the hearth there in front "
		"of the fireplace.  They are all talking, singing, "
		"drinking, and generally having a good time.  This "
		"merriment makes you feel right at home.  \n\n");
	add_item(({"wall","relics"}),"The walls in this tavern are "
		"covered with old relics from the days when this area "
		"was heavily mined for jewels and ore.  Today there are "
		"few left who do this sort of thing.  You can see picks "
		"shovels, torches, and other items.  They are all in "
		"very bad shape and attached to the walls.  \n\n");
	add_item(({"pick","shovel","torch","torches"}),"These items "
		"are attached to the wall.  They cannot be removed.\n\n");
}

int dest_me()
{
   if (gnash)
      gnash->dest_me();
   ::dest_me();
}

