/*  Text alterations and additions by Grimbrand 2-3-96                  */

#include "path.h"
inherit "std/shop";

void setup() {

   set_short("Reinado Duergar:  Bentol's -Armas y Herramientas-");
   
   add_property("no_undead",1); set_light(0);
   
   set_long("\n   Reinado Duergar:  Bentol's -Armas y Herramientas-.\n\n"
	    "     Bienvenido a Bentol's!     Desde donde estas ahora "
	    "puedes ver varios montones de equipo variado apilados "
	    "en la parte trasera de la tienda, listos para ser vendidos. "
	    "Un pequenyo mostrador bloquea el paso a la trastienda, puedes "
	    "ver una senyal colgando de la pared.\n"
	    "\n");

   add_property("no_undead",1);

   add_item("senyal","La senyal pone:\n"
	    "Pon \"listar\" para ver los objetos disponibles.\n"
	    "Pon \"vender\" para vendernos un objeto.\n"
	    "Pon \"ojear\" para examinar antes de comprar.\n"
	    "Pon \"comprar\" para comprar objetos.\n\n");

   add_item("mostrador",
	    "   Un simple mostrador que recorre la pared "
	    "del fondo.  Hay una senyal, colgando de la "
	    "pared, sobre el.\n"
	    "\n");

   add_exit("sudoeste",NEWBIE+"main02","door");

  set_item_table(NEWBIE+"shop_tab.c");
set_store_room(NEWBIE+"storerm.c");
}
