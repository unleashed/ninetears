/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"


inherit BRETHEM+"pub";

#include "pub.h"

object barman;

mixed top_list, top_deaths;
void add_to_list(object ob);

object barman;





void setup() {
   set_light(80);
   set_exit_color("cyan");
   set_short("%^BOLD%^RED%^Taberna del Refugio%^RESET%^");
   set_long("%^BOLD%^RED%^Taberna del Refugio%^RESET%^\n\n"
            "Es una pequenya taberna cuadrada, a un lado puedes ver la barra, cargada con botellas "
            "de cientos de bebidas distintas, la mayoria de ellas alcoholicas. Aqui suelen venir los "
            "pescadores y marineros a beber despues de las jornadas de trabajo. "
            "labores atendiendo a los clientes y limpiando las mesas sin dejar de moverse.\n\n");  


   add_item("barra",
      " Por esta barra han pasado mas bebidas en un dia que todas "
      " las que has podido beber en tu vida.\n");   



   add_menu_item("Aguardiente Marino", ALCOHOL, 20, 2, 10, 10,
      "te bebes una gran jarra de aguardiente marino, extraido de las algas", "se bebe una jarra de "+
      "aguardiente de un trago");

   add_menu_item("Cerveza de Brethem", ALCOHOL, 100, 3, 50, 50,
      "bebes una jarra de cerveza destilada en la propia taberna", "se bebe una jarra de cerveza de la casa");

   add_menu_item("Garrafon del 15", ALCOHOL, 300, 6, 100, 100,
      "sientes un escalofrio mientras te bajas una botella de garrafon, a saber que lleva..", "bebe una "+
      "botella de gararfon a morro" );

   add_menu_item("Vino de la Casa", ALCOHOL, 900, 15, 350, 350,
      "te estremeces al tragar el vaso de vino que preparan aqui "+
	"sabe a rayos", 
      "se bebe un vaso de vino de la casa y su rostro se vuelve palido y"+
	"comienza a ponerse verde");

   add_menu_item("Algas Fritas", FOOD, 50, 1, 20, 0,
      "te comes un plato de crujientes algas fritas", "se come un plato de crujientes algas fritas");

   add_menu_item("Pescados Podridos", FOOD, 100, 2, 40, 0,
      "te comes unos asquerosos pescaditos podridos", "se come unos asquerosos pescaditos podridos.");

   add_menu_item("Sopa de Espinas", FOOD, 200, 4, 100, 0,
      "te comes un plato de sopa de espinas de pesacdo", "se come un plato de sopa de espinas de pescado");



   add_menu_alias("aguardiente", "Aguardiente Marino");
   add_menu_alias("marino", "Aguardiente Marino");

   add_menu_alias("cerveza", "Cerveza de Brethem");
   add_menu_alias("brethem", "Cerveza de Brethem");

   add_menu_alias("garrafon", "Garrafon del 15");
   add_menu_alias("15", "Garrafon del 15");
   add_menu_alias("garrafon del 15", "Garrafon del 15");

   add_menu_alias("vino", "Vino de la Casa");
   add_menu_alias("vino de la casa", "Vino de la Casa");

   add_menu_alias("algas", "Algas Fritas");
   add_menu_alias("algas fritas", "Algas Fritas");

   add_menu_alias("pescados", "Pescados Podridos");
   add_menu_alias("podridos", "Pescados Podridos");
   add_menu_alias("pescados podridos", "Pescados Podridos");

   add_menu_alias("sopa", "Sopa de Espinas");
   add_menu_alias("espinas", "Sopa de Espinas");
   add_menu_alias("sopa de espinas", "Sopa de Espinas");


   set_co_ord( ({ -3, -4, 0 }) );

   set_open_condition("PANADERO");



   add_clone(BRETHEM+"npcs/pescador",random(5)-1);
   add_clone(BRETHEM+"npcs/marinero",random(5)-1);
   

add_exit("fuera",    BRETHEM + "bandor6.c","standard");


}


void init() {
  ::init();
  add_action("buy", "comer");
  add_action("buy", "tomar");
  add_action("buy", "jalar");
  add_action("buy", "comprar");
  add_action("do_read","read");
}






void reset()
{
   ::reset();
   if (!barman)
   {
      barman=new(BRETHEM+"npcs/jhus");
      barman->move(this_object());
   }
}

void dest_me()
{
   if (barman) barman->dest_me();
   ::dest_me();
}

int PANADERO()
{  
   object *Pelea;
   int i;
   if(!barman) return 0; 
   else{ 
         Pelea=barman->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(barman))
          return 0;
   } 
   return 1;
}

