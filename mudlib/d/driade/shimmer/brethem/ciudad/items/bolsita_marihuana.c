/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("peta");
   set_short("bolsita con hojas de marihuana");
   add_alias("marihuana");
   set_long("Una pequenya bolsita de tela con unas cuantas hojas de merihuana.\n");
   set_main_plural("Bolsitas con hojas de marihuana");
   add_plural("bolsitas");
   add_plural("bolsitas con hojas de marihuana");
   add_alias("marihuana");
   add_plural("hojas");
   set_weight(5);
   set_value(500000);

}



void init()
{
   ::init();
   add_action("do_liar", "liar");
}

void do_liar(string str)
{
 
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;

   write("Sacas un papelillo de algun lado y con una habilidad pasmosa te lias un canuto que ni el mismisimo Bob Marley hubiese preparado.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " saca un papelillo y coge unas pocas hojas en su mano, al cabo de unos segundos ves que se pone algo en la boca y le da fuego.\n\n"
             "Al cabo de un rato un olorcillo te llega y te das cuenta de que el cabronazo se esta fumando un peta y ni te lo rula.",({this_player()}));

   this_player()->clone_object(BRETHEM+"items/porrito.c",1);
   this_object()->dest_me();
   return 1;


}
