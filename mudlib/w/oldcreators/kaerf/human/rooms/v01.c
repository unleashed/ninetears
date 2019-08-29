#include "path.h"
inherit "std/pub";
#include "pub.h"

object kel;
void setup()
{
    add_property("no_undead",1);
    set_short("Isla de Havmand: Taverna");
    set_light(LIGHT-20);
    set_long("\nIsla de Havmand: Taverna.\n\n"
    "   Esta es una tosca taverna, tiene una larga barra de madera muy gastada y "
    "con grandes muescas, y hay varias mesas llenas de polvo en una esquina. Unas "
    "pocas botellas de aspecto antiguo lucen tras la barra en un estante, pero la sensacion "
    "en general es de negligencia. "
    "\n\n");
    add_item("bar","Una larga barra recorre todo un extremo del local en la pared norte. "
    "Esta llena de polvo y tiene varias muescas por todas partes, recuerdo de otros tiempos.\n");
    add_item(({"mesa","mesas"}),"Un grupito de mesas polvorientas situadas en una esquina. "
    "Estan hechas de madera, te preguntas que habran hecho con las sillas, (si es que "
    "alguna vez las hubo).\n");
    add_item(({"botella","botellas"}),"Varias botellas hechas de cristales coloreados en distintos "
    "tonos, no puedes ver lo que contienen.\n");
    add_item("estante","Un largo estante sujeto a la pared tras la barra.\n");
    add_item("polvo","El polvo lo cubre todo, alguien deberia limpiar esto.\n");

    add_exit("este",HAVMAND+"t03.c","path");
    add_exit("abajo",HAVMAND+"v07.c","path");

   add_menu_item("Sidra", ALCOHOL, 30, 15, 15, 15,
      "Te escancias unos culinos", "se escancia unos culinos de sidra");


   add_menu_item("Jugo de carne", FOOD, 100, 100, 100, 0,
      "Tomas una racion de sabroso jugo con tropiezos",
      "come una generosa racion de jugo de carne");

   add_menu_item("Te", SOFTDRINK, 5, 0, 1, 0,
      "tomas una taza de te caliente", "toma una taza de te humeante");

   add_menu_item("Cafe", SOFTDRINK, 10, 1, 3, 0,
      "tomas una taza de cafe", "toma una taza de cafe");

   add_menu_alias("sidra","Sidra");
   add_menu_alias("sidrina","Sidra");
   add_menu_alias("sidruca","Sidra");
   add_menu_alias("jugo","Jugo de carne");
   add_menu_alias("carne","Jugo de carne");
   add_menu_alias("jugo de carne","Jugo de carne");
   add_menu_alias("jugo carne","Jugo de carne");
   add_menu_alias("Jugo","Jugo de carne");
   add_menu_alias("te","Te");
   add_menu_alias("cafe","Cafe");


   set_zone("pub");

}

void reset()
{
   if(!kel)
   {
      kel = clone_object(CHARS+"oldman.c");
      kel->move(this_object());
   }

}
void dest_me()
{
    if(kel) kel->dest_me();
    ::dest_me();
}

