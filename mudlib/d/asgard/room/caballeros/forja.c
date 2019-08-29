//.oO JaDe Oo.  Junio'02
inherit "/std/shop";

object herrero;

void reset()
{ 
   if(!herrero)
   {
      herrero=clone_object("/d/asgard/npc/narid.c");
      herrero->move(this_object());
   }
   ::reset();
}
   
void setup()
{
  set_short("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Forja");
  set_long("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Forja\n"
           "Esta sala es la pequenya prisi�n de Narid-Na-Gost, castigado por la Diosa "
           "a forjar poderosos objetos para sus ejercitos hasta el fin de sus d�as. "
           "Observas todo tipo de materiales y multiples estantes y colgadores para "
           "guardar sus creaciones. La sala esta �nicamente iluminada por el fuego de "
           "la fragua.\n\n  Los comandos son:\n\n"
           "  <%^MAGENTA%^listar%^RESET%^>   para listar\n"
           "  <%^MAGENTA%^comprar%^RESET%^>  para comprar\n"
           "  <%^MAGENTA%^examinar%^RESET%^> para examinar un objeto y ver cu�nto vale\n\n");

   set_exit_color("magenta");
   add_exit("este", "/d/asgard/room/caballeros/circulo.c", "door");
   set_store_room("/d/asgard/room/caballeros/almacenh.c");
   add_property("smithy", 1); 
   sell_only();
   set_open_condition("holas"); // ->condicion de abierto  ;)
   
}
int holas()
{  
   object *Pelea;
   int i;
   if(!herrero) return 0; 
   else{ 
         Pelea=herrero->query_attacker_list();
         for(i=0;i<sizeof(Pelea);i++)
          if(environment(Pelea[i])==environment(herrero))
          return 0;
   } 
   return 1;
}