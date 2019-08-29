#include "path.h"
#include "pub.h"
inherit "std/pub";



void setup()
{
    add_menu_item("Kender Berrywine", ALCOHOL, 60, 10, 10, 100,
      "chug the light and fruity Berrywine.\n You feel all giggly",
      "chugs the light and fruity Berrywine and starts giggling insanely");
    add_menu_item("Kenderbrew", ALCOHOL, 10, 1, 10, 1200,
      "suck down the Kenderbrew.\n Your stomach tells you this was a big mistake",
      "sucks down a pint of Kenderbrew and turns green");
    add_menu_item("Kenderummy", ALCOHOL, 30, 6, 200, 400,
      "drink a Kenderummy rather quickly.\n Maybe you should have had a Kenderginanrummy instead",
      "turns a Kenderummy bottom up, and winces");
    add_menu_item("Kender Krossaint", FOOD, 60, 5, 200, 0,
      "chomp on a buttery, delicate Krossaint", "chomps on a buttery, delicate Krossaint");
    add_menu_item("Water", SOFTDRINK, 1, 0, 0, 0,
      "drink some water","drinks some water");
    add_menu_item("Milk", SOFTDRINK, 1, 5, 0, 0,
      "drink some yummy milk","drinks some yummy milk");
    add_menu_alias("water", "Water");
    add_menu_alias("milk", "Milk");
    add_menu_alias("bread","Kender Krossaint");
    add_menu_alias("berrywine","Kender Berrywine");
    add_menu_alias("wine","Kender Berrywine");
    add_menu_alias("kenderbrew","Kenderbrew");
    add_menu_alias("brew","Kenderbrew");
    add_menu_alias("beer","Kenderbrew");
    add_menu_alias("kenderummy","Kenderummy");
    add_menu_alias("rummy","Kenderummy");
    add_menu_alias("rum","Kenderummy");
    set_short("Journey's Beginning");
    set_long("Highlo: Journey's Beginning.\n"
      " This dimly lit, noisy pub doesn't look like much, but "
      "it is infamous throughout the Mithril Mountains for its "
      "steady customers- the child-like Kender. Rumors say that "
      "many an adventurer has entered this tavern rich, and "
      "left a poor man. Although that could be attributed to the "
      "potent drinks served within. The bar itself hugs the "
      "north wall, handcrafted from heavy mahogany. The walls are covered with scrawlings handwriting, "
      "so tinily written it almost looks as though the walls are "
      "painted black. The tables around the bar are only two and "
      "a half feet high, as is the bar. However, there are some larger "
      "ones for the bigger customers. The bar is bustling at almost "
      "all hours, kept open to accommodate the different races that "
      "patronize it. More likely, though, it is kept open so the "
      "Kender can socialize all night."
      "\n\n");

    set_race_pref("kender", 75);
    add_exit("southwest",ROOMS+"center.c","path");
    set_light(60);
    add_item("bar"," The bar is handcrafted of dark brown mahogany, and "
      "is covered with quite a few stains. The stools attached to it are small, "
      "but look sturdy. You admire the shiny brass footrail, and peruse "
      "the menu.\n");
    add_item(({"table","tables"})," The tables are hammered hastily "
      "together in the Kender tradition, using wooden nails. "
      "The owners of the bar apparently EXPECT fights.\n");
}
