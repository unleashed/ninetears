// Made by Thalos  01/04/02
#include "../../path.h"

inherit "/std/shop";


object tendero;

void setup()
{
   set_short("%^BOLD%^RED%^Tienda de armas de Dabad-Dinal%^RESET%^");
   set_long("%^BOLD%^RED%^Tienda de armas de Dabad-Dinal%^RESET%^\n\n"
            "Esta es la tienda de armas de Dabad-Dinal,aqui podras encontrar "
            "las mejores armas de fabricacion duergar de la zona,en una esquina"
            "puedes observar un yunque que podras utilizar para reparar el"
            " desgaste de tus objetos por un modico precio:\n\n"
            "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
            "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
            "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver "
            "cuanto vale.\n\n");
   set_light(60);

add_exit("sur",MERCADO+"keroon_150.c","standard");


   set_store_room(MERCADO +"almacen_armas");

   set_open_condition("TENDERO");
   
   add_property("smithy", 1); 
}
void init() {
  ::init();
  add_action("list", "listar");
  add_action("buy", "comprar");
  add_action("buy", "tomar");
  add_action("browse", "valorar");
  add_action("do_read","leer");
}




void reset()
{
   ::reset();
   if (!tendero)
   {
      tendero=new(NPCS+"dabad-dinal.c");
      tendero->move(this_object());
   }
}

void dest_me()
{
   if (tendero) tendero->dest_me();
   ::dest_me();
}

int TENDERO()
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
