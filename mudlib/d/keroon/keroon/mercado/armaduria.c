//Valar Diciembre 02
   inherit "/std/tienda";

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Armaduras%^RESET%^");
    set_long ("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon: %^RED%^ Armaduras%^RESET%^\n\n"
           "Una modesta tienda de armaduras, aunque algo sospechosa porque existen rumores de "
           "obtienen su equipo de los cadaveres de las victimas de una banda de asesinos de la"
           " ciudad. Por si acaso vigila tu espalda.\n\n");

   set_dependiente("/d/keroon/keroon/mercado/npcs/dabad-dinal.c");

   set_tipo("standard");

   set_exit_color("red");

   add_exit("fuera","/d/keroon/keroon/mercado/keroon_149.c","door");

   //suministro
   add_suministro("/baseobs/armaduras/armadura_completa",2);
   add_suministro("/baseobs/armaduras/armadura_campanya",3);
   add_suministro("/baseobs/armaduras/cota_de_anillas",2);
   add_suministro("/baseobs/armaduras/cuero_endurecido",4);
   

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
