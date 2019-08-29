//.oO JaDe Oo.  Junio'02
//Equipo de APoyo --> Valar Octubre 02

inherit "/std/tienda";
 
void setup()
{
  set_short("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Tienda");
  set_long("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Tienda\n\n"
           "Esta es la tienda de joyas y complementos de Asgard. Aqu� los nobles compran sus accesorios y los "
           "objetos decorativos para su hogar. Tambi�n hay una secci�n con baratijas para los ciudadanos "
           "menos pudientes de la ciudad.\n\n"  
           "Los comandos son:\n\n"
           "  <%^ORANGE%^listar%^RESET%^>   para listar\n"
           "  <%^ORANGE%^comprar%^RESET%^>  para comprar\n"
           "  <%^ORANGE%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n\n");

   set_dependiente("/d/asgard/npc/tendera.c");
   
   set_tipo("standard");

   set_exit_color("yellow");
   add_exit ("noroeste", "/d/asgard/room/mercado/armeria.c", "path"); 
   add_exit ("oeste","/d/asgard/room/mercado/mer4.c","path");


   //suministro
   add_suministro("/d/asgard/item/cperlas",3);
   add_suministro("/d/asgard/item/ptopacio",4);
   add_suministro("/d/asgard/item/arubi",5);
   
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
