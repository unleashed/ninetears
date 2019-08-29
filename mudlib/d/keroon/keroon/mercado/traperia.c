//Valar Diciembre 02
   inherit "/std/tienda";

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Trapero Patatero%^RESET%^");
    set_long ("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon: %^RED%^ Trapero Patatero%^RESET%^\n\n"
           "Esta tienda se dedica a la compra - venta de cualquier tipo de objetos. Podras encontrar"
           " articulos a un precio mas razonable que en otras tiendas, siempre y cuando alguien lo "
           "haya vendido antes. Sobre la procedencia del equipo lo mejor es no hablar.\n\n");

   set_dependiente("/d/keroon/keroon/mercado/npcs/dabad-dinal.c");

   set_tipo("standard");

   set_exit_color("red");

   add_exit("fuera","/d/keroon/keroon/mercado/keroon_195.c","door");

   //suministro --> EL suministro dependera de lo q le vendan
   
   
   //ajustes de precios
   add_ajuste("raza","duergar",200);//Duergar al 200%

   //Permisos de compra
   restringir_permitidos();
   add_permitido("ciudad","Keroon");
   add_permitido("raza","duergar");
   add_permitido("gremio","battleranger");
   add_permitido("alineamiento","Legal Malvado");
   add_permitido("alineamiento","Neutral Malvado");

   //Cartelito
   add_cartel("cartel");

   


}
