inherit "/std/pub";
#include "pub.h";

object globe;

void setup() {
  set_short("Baldricks Private Bar");
 
  set_light(50);

  set_long("This is a small room leading from the SS common room, carefully "+
           "designed for Baldrick by leafstar, the champion bar builder. The bar is "+ 
           "small and seems to only keep ciders, of which it keeps a wide selection.\n");
  
 
  add_item("bar", "The bar on the wall is a small wooden one which looks quite sturdy. There is a small menu  "+
                    "on the wall tho.\n");
  add_item("cider", "This is in 2.25 litre bottles and is for consumption "+     
               "by Baldrick. It looks nice, especially as you can't get in in norway.\n");
  add_item("walls", "These a mahogany panelled to keep everyone in the bar "+     
               "mellowed out....\n");
  
   add_alias("drinks counter", "bar");                 
   add_alias("wall", "walls");
   add_alias("drink", "cider");
    
  add_exit("baldy", "/w/baldrick/workplace/livingroom.c", "door");
  add_exit("common", "/d/ss/common.c", "door");


   add_menu_item("Snakebite", ALCOHOL, 10, 70, 100, 50,
    "drink a long snakebite. Hmm it is poisonous *snigger*",
  "drinks a long snakebite");
   add_menu_item("Cider", ALCOHOL, 10,10, 10, 10,
      "slurp down your cheap no name cider", "hurls down a pint of cheap cider");
   add_menu_item("K", ALCOHOL, 10, 100, 100, 100,
      "drink a bottle of K, hmm it tastes nice", "drinks a full bottle of K down in one");
   add_menu_item("Olde English", ALCOHOL, 10, 50, 40, 50,
      "feel a cool cider taste all down your throat", "drinks a pint of cider");
   add_menu_item("Woodpecker", ALCOHOL, 10, 70, 70, 70,
      "start to drink the woodpecker cider", "starts to drink some cider");
   add_menu_item("Merrydown", ALCOHOL, 10, 200, 200, 200,
      "feel this great drink moving down your body, however having drunk "+
      "so little, it makes you feel very drunk. ", 
      "drinks a pint of Merrydown and goes goggly eyed.");
   add_menu_item("Strongbow", ALCOHOL, 10, 150, 140, 140,   
      "have drunk the Strongbow and it tasted good", "drinks a light coloured drink...it looks like strongbow due to the large arrow in the bar");
   add_menu_item("Super Str Strongbow", ALCOHOL, 10, 400, 400, 400,
      "drank a pint of this and it is allready starting to go to your head",
      "downs a pint of super strength and starts to sway...");
   add_menu_item("Ice Dragon", ALCOHOL, 10, 100, 150, 50,
      "drink a bottle of this nice cool cider", "drink a bottle of dragons");
   add_menu_item("Leafstars Special", ALCOHOL, 10, 300, 200, 200,
      "drink a mixture of spirits. You can taste vodka, whisky and ginger wine in the main",
       "drinks a large glass of a strange coloured liquid, then seem to be on drugs");
   add_menu_item("Spliff", FOOD, 10, 10, 10, 10,
      "smoke the joint and feel your head getting lighter..woah mann!",
      "smokes a joint and mellows out");
   add_menu_item("Womble", FOOD, 10, 10, 10, 10,
      "eat the womble whole, boy it tasted good!", "eats a whole womble. He mustve been hungry");
   add_menu_item("Frog", FOOD, 10, 10, 10, 10,
      "eats a fried frog. Hmm it tastes nice", "fries then eats a whole frog");
   add_menu_item("Duck", FOOD, 10, 10, 10, 10,
      "eat a bit of Ducky. Ducky Screams in pain", "laughs as he eats part of Ducky");
   
   add_menu_alias("snakebite", "Snakebite");
   add_menu_alias("snake", "Snakebite");
   add_menu_alias("cider", "Cider");
   add_menu_alias("house cider", "Cider");
   add_menu_alias("k", "K");
   add_menu_alias("olde english", "Olde English");
   add_menu_alias("olde", "Olde English");
   add_menu_alias("woodpecker", "Woodpecker");
   add_menu_alias("merrydown", "Merrydown");
   add_menu_alias("merry", "Merrydown");
   add_menu_alias("strongbow", "Strongbow");
   add_menu_alias("bow", "Super Strength Strongbow");
   add_menu_alias("super", "Super Strength Strongbow");
   add_menu_alias("ice dragon", "Ice Dragon");
   add_menu_alias("ice", "Ice Dragon");
   add_menu_alias("dragon", "Ice Dragon");
   add_menu_alias("womble", "Womble");
   add_menu_alias("duck", "Duck");
   add_menu_alias("ducky", "Duck");
   add_menu_alias("frog", "Frog");
   add_menu_alias("leafys", "Leafstars Special");
   add_menu_alias("lf", "Leafstars Special");
   add_menu_alias("special", "Leafstars Special");
  add_menu_alias("leafstars special", "Leafstars Special");
   add_menu_alias("joint", "Spliff");
   add_menu_alias("weed", "Spliff");
   add_menu_alias("spliff", "Spliff");
}
   
void reset()
  {
  if (!globe)
    {
    globe = clone_object ("/obj/misc/globe");
    globe->move(this_object());
    }
} /* reset */

void dest_me()
  {
  if (globe)
    globe->dest_me();
  ::dest_me();
}

