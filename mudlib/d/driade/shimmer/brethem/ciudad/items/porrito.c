/* By Shimmer */

#define CREATOR "shimmer"

#include "../../../path.h"

inherit "/std/object";

void setup()
{
   set_name("peta");
   set_short("porrito");
   add_alias("porro");
   set_long("Es una planta con bonitas hojas verdes y fibrosas.\n");
   set_main_plural("Plantas %^GREEN%^Verdes%^RESET%^");
   add_plural("porritos");
   add_plural("petas");
   add_alias("peta");
   set_weight(5);


}


/*

void init()
{
   ::init();
   add_action("do_fumar", "fumar");
   add_action("do_rular", "rular");
}

void do_fumar(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   
   write("Te pones el porrito en la boca y le metes fuego, pegas un par de profundas caladas y notas como tu cabeza empieza a "
         "balancearse de un lado a otro y tu mirada se pierde, una gran sensacion de calma y placer te llena completamente.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se pone un peta en la boca y le mete fuego, le da un par de caladas y el humo te llega dandote ganas de meterle un par "
             "de caladas tambien.",({this_player()}));
//   this_player()->add_clone(BRETHEM + "items/peta.c",1);
//   this_object()->dest_me();
   return 1;


}

void rular()
{
   ::init();
   add_action("do_rular", "rular");
}

void do_rular(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   
   write("Le metes un par de proundas caladas al peta y se lo rulas a "
         "balancearse de un lado a otro y tu mirada se pierde, una gran sensacion de calma y placer te llena completamente.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se pone un peta en la boca y le mete fuego, le da un par de caladas y el humo te llega dandote ganas de meterle un par "
             "de caladas tambien.",({this_player()}));

   this_object()->dest_me();
   return 1;


}

*/