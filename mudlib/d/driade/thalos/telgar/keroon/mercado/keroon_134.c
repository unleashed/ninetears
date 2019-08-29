// Made by Thalos  01/04/02
#include "../../path.h"

inherit "/std/shop";


object tendero;

void setup()
{
   set_short("%^BOLD%^RED%^Tienda de yelmos y escudos de Taruzun%^RESET%^");
   set_long("%^BOLD%^RED%^Tienda de yelmos y escudos de Taruzun%^RESET%^\n\n"
            "Esta es la tienda de yelmos y escudos de Taruzun,aqui podras encontrar "
            "los mejores escudos y yelmos de fabricacion duergar de la zona,ves que la"
            "mercancia se encuentra apilada por doquier, no te resultara dificil encontrar"
            " algo de tu agrado siempre que puedas permitirte el precio:\n\n"
            "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
            "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
            "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver "
            "cuanto vale.\n\n");
   set_light(60);

add_exit("sur",MERCADO+"keroon_151.c","standard");


   set_store_room(MERCADO +"almacen_escudos");

   set_open_condition("TENDERO");
   
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
      tendero=new(NPCS+"taruzun.c");
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
