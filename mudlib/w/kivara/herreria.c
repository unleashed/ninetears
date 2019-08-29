//.oO JaDe Oo.  Junio'02
//Equipo de APoyo --> Valar Octubre 02

inherit "/std/tienda";
   
void setup()
{
  set_short("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Herreria");
  set_long("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Herreria\n\n"
           "Esta es la herreria de Asgard, famosa por sus armas y armaduras magicas. "
           "Observas gran variedad de extranyos materiales de los que desconoces su "
           "procedencia. Una gran fragua arde incombustible en el centro, avivada por un "
           "enorme fuelle. Oyes el repiqueteo constante de los herreros trabajando.\n\n"  
           "Los comandos son:\n\n"
           "  <%^ORANGE%^listar%^RESET%^>   para listar\n"
           "  <%^ORANGE%^comprar%^RESET%^>  para comprar\n"
           "  <%^ORANGE%^examinar%^RESET%^> para examinar un objeto y ver cuanto vale\n\n");

   set_dependiente("/d/asgard/npc/herrero.c");
   
   set_tipo("herreria");
   
   set_exit_color("yellow");
   add_exit ("noreste", "/d/asgard/room/mercado/posada.c", "path"); 
   add_exit ("este","/d/asgard/room/mercado/mer3.c","path");
   
   
   //suministro
   add_suministro("/d/asgard/weapon/corruptora",2);
   add_suministro("/d/asgard/shield/portador",2);
   add_suministro("/d/asgard/armour/ira",2);
   add_suministro("/baseobs/weapons/bastard_sword",5);
   
   //ajustes de precios
   add_ajuste("raza","humano",100); //Humanos al 100%
   add_ajuste("gremio","caballerodejade",90);//Caballeros de Jade 90%
   add_ajuste("raza","innmortal",0);//Inmos al 0% del precio :P
   
   //Permisos de compra
   add_permitido("ciudad","Asgard");
   add_permitido("raza","humano");
   add_permitido("gremio","caballerodejade");
   add_permitido("alineamiento","caotico bueno");
   add_permitido("alineamiento","caotico neutral");
   add_permitido("alineamiento","caotico malvado");
   
   //Cartelito
   add_cartel("cartel");
   
   //prohibir_venta()
   
   set_open_condition("holas"); // ->condicion de abierto  ;)
   
}