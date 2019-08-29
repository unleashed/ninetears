// Tienda. Gestur '97

#include "../path.h"

inherit "/std/shop";

object barrachina;

void setup()
{
  set_short("%^CYAN%^%^BOLD%^La tienda de Lord Kalar%^RESET%^");
  set_long("Has entrado a la tienda de Lord Kalar, aqui puedes comprar "
  "y vender toda clase de objetos que tengan algun valor. Los "
  "comandos son:\n\n"
  "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
  "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
  "  <%^MAGENTA%^vender%^RESET%^>   para vender\n"
  "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n"
"  <%^MAGENTA%^valorar%^RESET%^>  para valorar un objeto sin venderlo.\n\n");

        set_light(60);
        add_exit("fuera", ANDUAR"ao1607", "door");
        set_store_room(ANDUAR"almacen");
       set_open_condition("holas"); // ->condicion de abierto  ;)
   
//add_clone("/d/anduar/npcs/rutic.c",1);
}
int holas()
{  
   object *Pelea;
   int i;
   if(!barrachina) return 0; 
   else{ 
         Pelea=barrachina->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(barrachina))
          return 0;
   } 
   return 1;
}

void reset()
{
   call_out("barrachina",1);
   ::reset();
}

void barrachina()
{
   if (!barrachina)
   {
      barrachina=new(ANDUAR"npcs/lord_kalar");
      barrachina->move(this_object());
      if (environment(this_player())==environment(barrachina))
      {
         say(barrachina->query_cap_name()+" sale del almacen y se dirige al "
         "mostrador.\n");
         write(barrachina->query_cap_name()+" sale del almacen y se dirige al "
         "mostrador.\n");
      }
   }
}
