//Valar Diciembre 02
   inherit "/std/tienda";

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Armeria%^RESET%^");
    set_long ("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon: %^RED%^ Armeria%^RESET%^\n\n"
           "Estas en la armeria mas famosa de Keroon donde puedes encontrar las mas exquisitas "
           "y prestigiosas armas. En el fondo de la tienda puedes ver escondido al tendero tras"
           " la puerta vigilandote con ojor firmes.\n\n");

   set_dependiente("/d/keroon/keroon/mercado/npcs/dabad-dinal.c");

   set_tipo("armeria");

   set_exit_color("red");

   add_exit("fuera","/d/keroon/keroon/mercado/keroon_151.c","door");

   //suministro
   add_suministro("/baseobs/armas/espada_ancha",2);
   add_suministro("/baseobs/armas/cimitarra",3);
   add_suministro("/baseobs/armas/hacha",2);
   add_suministro("/baseobs/armas/daga",1);
   add_suministro("/baseobs/armas/maza",2);

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
   add_cartel("cartel");

   prohibir_venta();


}
