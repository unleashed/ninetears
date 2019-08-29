inherit "std/pub";
#include "path.h"
#include "pub.h"

void setup()
{
    add_menu_item("Beer", ALCOHOL, 20, 10, 10, 10,
      "slurp down your beer", "hurls down a pint of beer");
    add_menu_item("Stout", ALCOHOL, 100, 50, 50, 50,
      "drink a meal of thick black beer", "drinks a stout");
    add_menu_item("Malt whisky", ALCOHOL, 200, 100, 100, 100,
      "feel a gentle burning down your throat", "drinks a shot of whisky" );
    add_menu_item("Dwarven spirits", ALCOHOL, 500, 200, 200, 200,
      "start to drink the Dwarven spirits. Suddenly it "
      "stops in your throat, then gathers speed and shoots into your stomach",
      "starts to drink some spirits, stop confusedly and grins foolishly");
    add_menu_item("Chili nuts", FOOD, 50, 5, 20, 0,
      "eat some very strong chili nuts", "eats some red peanuts");
    add_menu_item("Toast", FOOD, 100, 10, 40, 0,
      "eat a delicious toast", "eats a toast. Mmm it smells good.");
    add_menu_item("Spiced Potatoes", FOOD, 20, 15, 60, 0,
      "eat some tasty spiced potatoes", "eats some spiced potatoes");
    add_menu_alias("beer", "Beer");
    add_menu_alias("house beer", "Beer");
    add_menu_alias("house", "Beer");
    add_menu_alias("stout", "Stout");
    add_menu_alias("black beer", "Stout");
    add_menu_alias("whisky", "Malt whisky");
    add_menu_alias("malt", "Malt whisky");
    add_menu_alias("malt whisky", "Malt whisky");
    add_menu_alias("dwarven", "Dwarven spirits");
    add_menu_alias("dwarven spirits", "Dwarven spirits");
    add_menu_alias("spirits", "Dwarven spirits");
    add_menu_alias("chili", "Chili nuts");
    add_menu_alias("chili nuts", "Chili nuts");
    add_menu_alias("toast", "Toast");
    add_menu_alias("potatoes", "Spiced Potatoes");
    add_menu_alias("spiced potatoes", "Spiced Potatoes");

    set_short("Thraddash's Pub");
    set_long(
      "You have entered Thraddash's Pub, a local gathering place for the "
      "people of Belgar's Haven. The place is quiet and clean, though few "
      "people are here at the moment. The place has only a few decorations, "
      "all nautical in design...on one wall hangs a painting of a magnificent "
      "sailing ship, and a large ship-in-a-bottle sits on the bar. Other than "
      "that, the place is rather dull. A large menu has been hung on one wall "
      "for you to read.\n");

    add_property("no_undead",1);
    add_exit("west", HERE+"street1", "door");

    add_item("painting",
      "The painting shows a large vessel, in full sail during a storm. The "
      "craft's crew scuttles about on the deck, and the captain stands on "
      "the sterncastle bravely enduring the rain and wind. The title of the "
      "painting is, 'Endurance'.\n");
    add_item(({"ship", "bottle", "ship-in-a-bottle", "ship in a bottle"}),
      "This interesting item is a model ship, stowed inside a large glass "
      "bottle meant to hold many gallons of ale. You have no idea how the "
      "ship got inside the bottle. Perhaps a drink would help you figure it "
      "out...\n");
    set_light(60);
    add_clone(NPCS+"thraddash.c",1);

}

