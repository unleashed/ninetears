#include "../../path.h"
inherit "/std/shop";
object costurero;
 void reset()
{
   if(!costurero)
     {
       costurero=clone_object(NPC+"costurero_grandhum.c");
       costurero->move(this_object());
    }
    ::reset();
 }
   
 void setup()
  {
   set_short("%^BOLD%^GREEN%^Tienda de klot%^YELLOW%^%^RESET%^");
   set_long("%^BOLD%^GREEN%^Tienda de Klot%^YELLOW%^%^RESET%^\n"
            " Estas en la tienda de klot, una tienda de telas y ropa."
            " Ves montones de ropa y tela, tambien ves un telar y "         
            " un pequenyo mostrador.\n\n  Los comandos son:\n\n"
            "  <%^GREEN%^listar%^RESET%^>   para listar\n"
            "  <%^GREEN%^comprar%^RESET%^>  para comprar\n"
            "  <%^GREEN%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n\n");

    set_light(60);
    add_exit("fuera",ROOMGRAN"GRAN18.c","door");
    set_store_room(ROOMGRAN"almacen.c");
    set_open_condition("holas");
 }
int holas()
 {  
    object *Pelea;
 
    int i;
    if(!costurero) return 0; 
    else{ 
          Pelea=costurero->query_attacker_list();
          for(i=0;i<sizeof(Pelea);i++)
           if(environment(Pelea[i])==environment(costurero))
           return 0;
    } 
    return 1;
}

