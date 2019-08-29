//.oO JaDe Oo.  Junio'02
//Equipo de APoyo --> Valar Octubre 02

inherit "/std/tienda";

void setup()
{
  set_short("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Tienda");
  set_long("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Tienda\n\n"
           "Esta es la tienda de magia y objetos raros de Asgard. Aqu� los aprendices compran los ingredientes "
           "para sus pociones. Tambi�n se puede encontrar gran variedad de objetos extra�os que no sabes muy "
           "bien para que podr�an servir.\n\n"  
           "Los comandos son:\n\n"
           "  <%^ORANGE%^listar%^RESET%^>   para listar\n"
           "  <%^ORANGE%^comprar%^RESET%^>  para comprar\n"
           "  <%^ORANGE%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n\n");

   set_dependiente("/d/asgard/npc/mago.c");
   
   set_tipo("standard");
   
   set_exit_color("yellow");
   add_exit ("noroeste", "/d/asgard/room/mercado/mer3.c", "path"); 
   add_exit ("noreste","/d/asgard/room/mercado/mer4.c","path");

   
   
   //suministro
   add_suministro("/d/asgard/item/pmana",2);
   add_suministro("/d/asgard/item/",4);
   add_suministro("/d/asgard/item/",4);
      
   //ajustes de precios
   add_ajuste("raza","humano",100); //Humanos al 100%
   
   //Permisos de compra
   restringir_permitidos();
   add_permitido("ciudad","Asgard");
   add_permitido("raza","humano");
   add_permitido("gremio","caballerodejade");
   add_permitido("alineamiento","caotico bueno");
   add_permitido("alineamiento","caotico neutral");
   add_permitido("alineamiento","caotico malvado");
   
   //Cartelito
//add_cartel("cartel");
   
prohibir_venta();
   
   
}
