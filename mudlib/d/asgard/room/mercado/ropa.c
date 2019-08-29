//.oO JaDe Oo.  Junio'02
//Equipo de APoyo --> Valar Octubre 02

inherit "/std/tienda";

void setup()
{
  set_short("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Tienda");
  set_long("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Tienda\n\n"
           "Esta es la tienda de telas y ropa de Asgard. Aqu� los nobles compran sus finos trajes y los "
           "ajuares para su hogar. Tambi�n hay una secci�n con ropa menos trabajada para los ciudadanos "
           "menos pudientes de la ciudad.\n\n"  
           "Los comandos son:\n\n"
           "  <%^ORANGE%^listar%^RESET%^>   para listar\n"
           "  <%^ORANGE%^comprar%^RESET%^>  para comprar\n"
           "  <%^ORANGE%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n\n");

   set_dependiente("/d/asgard/npc/tendero.c");
   
   set_tipo("standard");
   
   set_exit_color("yellow");
   add_exit ("oeste", "/d/asgard/room/mercado/mer2.c", "path"); 
   add_exit ("sudoeste","/d/asgard/room/mercado/armeria.c","path");
   //set_store_room("/d/asgard/room/mercado/almacenr.c");
   
   //suministro
   add_suministro("/d/asgard/item/vseda",3);
   add_suministro("/d/asgard/item/tlino",4);
   add_suministro("/d/asgard/item/rollo",5);
   
   //ajustes de precios
   add_ajuste("raza","humano",100); //Humanos al 100%
   add_ajuste("gremio","caballerodejade",90);//Caballeros de Jade 90%
   
   //Permisos de compra
   restringir_permitidos();
   add_permitido("ciudad","Asgard");
   add_permitido("raza","humano");
   add_permitido("gremio","caballerodejade");
   add_permitido("alineamiento","caotico bueno");
   add_permitido("alineamiento","caotico neutral");
   add_permitido("alineamiento","caotico malvado");
   
   //Cartelito
   add_cartel("cartel");
   
   //prohibir_venta()
   
   
   
}
