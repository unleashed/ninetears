// Aokromes

inherit "/std/shop";
#include "path.h"

object tendero;

void setup() {

   set_exit_color("red");
   set_light(50);  
   set_short("%^YELLOW%^Grupo comercial Comellas%^RESET%^");
   set_long("Has entrado a la tienda de del senyor Comellas, aqui puedes "
   "comprar y vender toda clase de objetos que tengan algun valor. Los "
   "comandos son:\n\n"
   "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
   "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
   "  <%^MAGENTA%^vender%^RESET%^>   para vender\n"
"  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n"
"  <%^MAGENTA%^valorar%^RESET%^>  para valorar un objeto sin venderlo.\n\n");
   add_exit("sudeste",CARRETERA"pos_5.c","door");
set_store_room("/d/anduar/carretera/rooms/almacen1.c");

}

int abierto()
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

void reset()
{
   call_out("tendero",1);
   ::reset();
}
 void tendero()
  {
   if (!tendero)
    {
tendero = clone_object("/d/anduar/carretera/rooms/npcs/tendero");
    tendero->move(this_object());
   }
  }
