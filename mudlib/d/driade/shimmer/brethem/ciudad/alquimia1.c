/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "/std/shop";

object tendero;

void setup()
{
   set_short("%^BOLD%^RED%^Tienda de Samand el Alquimista%^RESET%^");
   set_long("%^BOLD%^RED%^Tienda de Samand el Alquimista%^RESET%^\n\n"
            "Esta es la tenda del alquimista Samand, un viejo elfo que lleva toda "
            "su vida entre la harina y la levadura. Aqui puedes comprar los "
            "panes y tartas que el prepara:\n\n"
            "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
            "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
            "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver "
            "cuanto vale.\n\n");
   set_light(60);

   add_exit("fuera", BRETHEM + "gen5.c", "door");

   set_store_room(BRETHEM +"almacen_alquimista_samand");

   set_open_condition("ALQUIMISTA");
   sell_only();
}

void init() {
  ::init();
  add_action("list", "listar");
  add_action("buy", "comprar");
  add_action("buy", "tomar");
  add_action("browse", "valorar");
  add_action("do_read","read");
}




void reset()
{
   ::reset();
   if (!tendero)
   {
      tendero=new(BRETHEM+"npcs/samand.c");
      tendero->move(this_object());
   }
}

void dest_me()
{
   if (tendero) tendero->dest_me();
   ::dest_me();
}

int ALQUIMISTA()
{  
   object *Pelea;
   int i;
   if(!tendero) return 0;
   else{ 
         Pelea=tendero->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(tendero))
          return 0;
   
   } 
   return 1;
}

