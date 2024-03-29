//.oO JaDe Oo.  Junio'02 

//Equipo de APoyo --> Valar Octubre 02
inherit "/std/tienda";


void setup()
{
  set_short("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Armer�aa");
  set_long("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Armer�a\n\n"
           "Esta es la armer�a de Asgard, famosa por sus armas y armaduras m�gicas. "
           "Observas gran variedad de extra�os materiales de los que desconoces su "
           "procedencia. Una gran fragua arde incombustible en el centro, avivada por un "
           "enorme fuelle. Oyes el repiqueteo constante de los armeros trabajando.\n\n"  
           "Los comandos son:\n\n"
           "  <%^ORANGE%^listar%^RESET%^>   para listar\n"
           "  <%^ORANGE%^comprar%^RESET%^>  para comprar\n"
           "  <%^ORANGE%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n\n");


   set_dependiente("/d/asgard/npc/armero.c");   
   
set_tipo("armeria");
   
   set_exit_color("yellow");
   add_exit ("noreste", "/d/asgard/room/mercado/ropa.c", "path"); 
   add_exit ("sudeste","/d/asgard/room/mercado/comp.c","path");
   
   
   //suministro
   add_suministro("/d/asgard/weapon/corruptora",2);
   add_suministro("/d/asgard/shield/portador",2);
   add_suministro("/d/asgard/armour/ira",2);
   add_suministro("/baseobs/weapons/bastard_sword",5);
   
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
   
   prohibir_venta();
   
   
}
