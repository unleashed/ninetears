//  Dwarven Newbie Area:  Created By Mist   Fall 1994
inherit "std/pub";
#include "pub.h"
#include "path.h"
void add_to_list(object ob);


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
set_short("Realm of the Dwarf:  Blind Bat Tavern");
	set_long("\n   Realm of the Dwarf:  Blind Bat Tavern\n\n"
	 "     This is the Blind Bat tavern.  The tavern is large "
		"with several tables scattered about and a brightly "
		"lit fireplace on the north wall.  There are Dwarves "
		"sitting at most of the tables and at the bar tossing "
		"down a few drinks and having a good time.  There are "
		"several more standing around or sitting on the hearth "
		"in front of the fireplace.  Upon the walls of this "
		"establishment are relics from the time when these "
		"people mined this area for precious metals and jewels.  "
		"The bar occupies the western wall and has a menu of "
		"the drinks and foods served here. "
		"\n\n");
   
	add_exit("south", ROOM+"dwarf31.c", "door");
   
   set_light(60);
   set_zone("pub");
   
	add_item("bar","The bar stretches along the western wall and "
		"is covered with empty mugs and the remains of food "
		"items that are served here.  Behind the bar sits a menu "
		"next to the shelves where the various containers of "
		"the drinks are located.  "
		"Hanging on the wall behind the bar is a giant "
		"warhammer that must belong to the owner of the bar.  "
		"\n\n");
	add_item("table","The tables are covered with empty beer mugs "
		"and plates of scraps from what must have been a great "
		"feast.\n\n");
	add_item(({"mugs","beer mugs"}),"The mugs are empty.  The number "
		"of drunken Dwarves here is probably the reason.\n\n");
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
	add_item(({"hammer","warhammer","winged warhammer"}),"This "
		"beautiful hammer is made of wood and metal and has "
		"something different about it that you almost overlook.  "
		"Suddenly, you realize that this is a winged warhammer, "
		"the legendary weapon of only the most skillful of "
		"Dwarves.  That thing might hurt if it hit you.  "
		"\n\n");
add_clone(CHAR+"sharn",1);
}

