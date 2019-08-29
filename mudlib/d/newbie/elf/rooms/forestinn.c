inherit "std/pub";
#include "pub.h"
#include "path.h"

void setup()
{
    add_menu_item("Cider", ALCOHOL, 20, 10, 10, 10,
      "drink your cider", "drinks a glass of cider");
    add_menu_item("Ale", ALCOHOL, 40, 20, 20, 20,
      "drink a pint of ale", "drinks a pint of ale");
    add_menu_item("Mead", ALCOHOL, 100, 40, 40, 40,
      "hurl down the mead", "hurls down the mead and burps loadly");
    add_menu_item("Wine", ALCOHOL, 500, 200, 200, 200,
      "drinks a glass of exclusive elven wine.",
      "drinks a glass of exclusive wine.");
    add_menu_item("Raisins", FOOD, 10, 4, 10, 0,
      "eat some raisins", "eats some rasins");
    add_menu_item("Stew", FOOD, 200, 50, 150, 0,
      "eat a healthy meal of stew", "eats some stew");
    add_menu_item("Lembas waffers", FOOD, 1000, 150, 500, 0,
      "eat a delicious Lembas waffer", "eats a Lembas waffer");
    add_menu_item("Milk", SOFTDRINK, 6, 2, 5, 5,
      "drink a glass of milk", "drinks a glass of milk");
    add_menu_item("Water", SOFTDRINK, 1, 0, 0, 0,
      "drink a glass of water", "drinks a glass of water");
    add_menu_item("Tea", SOFTDRINK, 3, 0, 1, 1,
      "sip a cup of tea", "sips a cup of tea");
    add_menu_item("Nectar", SOFTDRINK, 30, 5, 15, 15,
      "drink a flask of delicious nectar", "drinks a flask of nectar");

    add_menu_alias("milk", "Milk");
    add_menu_alias("water", "Water");
    add_menu_alias("tea", "Tea");
    add_menu_alias("nectar", "Nectar"); 
    add_menu_alias("raisins", "Raisins");
    add_menu_alias("stew", "Stew");
    add_menu_alias("lembas waffers", "Lembas waffers");
    add_menu_alias("lembas", "Lembas waffers");
    add_menu_alias("cider", "Cider");
    add_menu_alias("ale", "Ale");
    add_menu_alias("mead", "Mead");
    add_menu_alias("wine", "Wine");

    add_property("no_undead",1); set_short("Realm of the Elf:  High Forest Winehouse");

    set_long("\n   Realm of the Elf:  High Forest Winehouse\n\n"
      "     You are inside a beautiful elfin inn. This Inn is "
      "used as a meeting place for young adventuring elves. "
      "The inside of the inn is decorated with lovely crafted furniture "
      "and some engravings on the walls. There is a menu hanging behind "
      "the bar.\n ");

    add_exit("out", ROOM+"center", "door");

    add_item(({"wall","walls"}),
      "The walls is decorated with pictures "
      "of ancient elfin kings and heroes.\n");
    add_item(({"engraving","engravings"}),
      "These engravings depict the adventures and lives of "
      "ancient elfin kings and heroes.\n");
    add_item(({"furniture","furnitures"}),
      "The furniture here is crafted by elfin artists. "
      "The tables and chairs look as though they were shaped out of a "
      "single piece of wood.\n");
    add_item(({"people", "patrons"}),
      "There are no patrons here at the moment.\n");
    add_item("bar",
      "The bar is made of oak.\n");
    add_item("menu",
      "Since there's writing on it they probably think you can read it.\n");

    set_light(60);
    set_zone("pub");
    add_clone(CHAR+"celeb.c",1);
}
