/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit "/std/shop";

object panadero;

void setup()
{
   set_short("%^BOLD%^RED%^Panaderia de Llov%^RESET%^");
   set_long("%^BOLD%^RED%^Panaderia de Llov%^RESET%^\n\n"
            "Esta es la panaderia de Llov, un viejo humano que lleva toda "
            "su vida entre la harina y la levadura. Aqui puedes comprar los "
            "panes y tartas que el prepara:\n\n"
            "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
            "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
            "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver "
            "cuanto vale.\n\n");
   set_light(60);

   add_exit("fuera", BRETHEM + "gen6.c", "door");

   set_store_room(BRETHEM +"almacen_panaderia_llov");

   set_open_condition("PANADERO");
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
   if (!panadero)
   {
      panadero=new(BRETHEM+"npcs/llov");
      panadero->move(this_object());
   }
}

void dest_me()
{
   if (panadero) panadero->dest_me();
   ::dest_me();
}

int PANADERO()
{  
   object *Pelea;
   int i;
   if(!panadero) return 0; 
   else{ 
         Pelea=panadero->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(panadero))
          return 0;
   } 
   return 1;
}

