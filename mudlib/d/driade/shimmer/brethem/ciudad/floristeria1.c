/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "/std/shop";

object tendera;

void setup()
{
   set_short("%^BOLD%^RED%^Tienda de Aura%^RESET%^");
   set_long("%^BOLD%^RED%^Tienda de Aura%^RESET%^\n\n"
            "Esta es la Tienda de Aura, una anciana conocedora de los secretos "
            "ocultos de las plantas y sus mas raras utilidades.\n\n"
            "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
            "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
            "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver "
            "cuanto vale.\n\n");
   set_light(60);

   add_exit("fuera", BRETHEM + "gen19.c", "door");

   set_store_room(BRETHEM +"almacen_tienda_aura");

   set_open_condition("TENDERA");
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
   if (!tendera)
   {
      tendera=new(BRETHEM+"npcs/aura");
      tendera->move(this_object());
   }
}

void dest_me()
{
   if (tendera) tendera->dest_me();
   ::dest_me();
}

int TENDERA()
{  
   object *Pelea;
   int i;
   if(!tendera) return 0; 
   else{ 
         Pelea=tendera->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(tendera))
          return 0;
   } 
   return 1;
}

