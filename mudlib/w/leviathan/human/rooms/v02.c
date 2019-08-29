#include "path.h"
inherit "/std/shop";
void setup()
{
    add_property("no_undead",1);
    set_short("Isla de Havmand: Tienda");
    set_light(LIGHT);
    add_exit("este",HAVMAND+"t04.c","path");
    set_long("\nIsla de Havmand: Tienda.\n\n"
    "   Estas en una pequenya tienda que no parece hacer grandes negocios precisamente, "
    "normal teniendo en cuenta que los pocos que aun habitan esta isla son pobres.\n "
    "   Escribe \"listar\" para ver las maravillas que estan en venta, "
	 "\"ojear\" para ver el objeto que te interesa, \"valorar\" "
	"para saber lo que te darian por algo que poseas si lo quieres \"vender\" y por ultimo \"comprar\" "
    "para comprarnos alguna de nuestras gangas.\n\n");
   //set_open_condition("do_check");
    set_store_room(HAVMAND+"storeroom.c");

   add_clone(CHARS+"woman",1);
   set_item_table(HAVMAND+"SHOP_TABLE");

}
void init() {
::init();
add_action("do_check", "comprar");
add_action("do_check", "ven*der");
}

int do_check(string str)
{
   if(!present("Anciana"))
   {
      notify_fail("Lo siento, no hay quien pueda atenderte en estos momentos.\n");
        return 0;
   }
   return(1);
}



