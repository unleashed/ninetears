//  Dwarven Newbie Area:  Created By Mist   Fall 1994
inherit "std/pub";
#include "pub.h"
#include "path.h"
mixed top_list, top_deaths;
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
set_short("Macedonia:  The Happy Tavern");
set_long("Macedonia:  The Happy Tavern\n\n"
            "     You are overcome by joy and happiness just by"
            " standing in this bar.  In the room there are about"
            " a dozen small tables, each with about 4 chairs. "
            " About 10 feet in front of the southern wall, there"
            " is a bar that stretches the entire length of the"
            " room.  Hanging on the wall beyond the bar, there are"
            " rows of shelves and cabinets filled with several"
            " different types of liquor and non-alcoholic"
             " beverages.  Hanging on the center of this wall"
              " there is a large menu of meals and drinks that"
              " are available.  In the southwest corner, there"
              " is a closed door.  This must lead to the kitchen"
              " area of the tavern.\n\n");
   
        add_exit("north", VALLEY+"gnome14.c", "door");
   
   set_light(60);
   set_zone("pub");
   
}

