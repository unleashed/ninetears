//Valar Diciembre 02
   inherit "/std/tienda";

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Local Abandonado%^RESET%^");
    set_long ("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon: %^RED%^ Local Abandonado%^RESET%^\n\n"
           "Esta tienda esta abandonada. Aqui podrias poner tu negocio y ganar dinero con ello. "
           "La tienda tiene grandes dimensiones y aunque un poco abandonada podrias sacar "
           "provecho de ella. Para mas informacion contactar con el Thane encargado.\n\n");

   set_dependiente("/d/keroon/keroon/mercado/npcs/dabad-dinal.c");

   set_tipo("standard");

   set_exit_color("red");

   add_exit("fuera","/d/keroon/keroon/mercado/keroon_196.c","door");

   //suministro --> EL suministro dependera de lo q le vendan
   
   
   //ajustes de precios
   add_ajuste("raza","duergar",100);//Duergar al 100%

   //Permisos de compra
   restringir_permitidos();
   add_permitido("ciudad","Keroon");
   add_permitido("raza","duergar");
   add_permitido("gremio","battleranger");
   add_permitido("alineamiento","Legal Malvado");
   add_permitido("alineamiento","Neutral Malvado");

   //Cartelito
   //add_cartel("cartel");

   


}
