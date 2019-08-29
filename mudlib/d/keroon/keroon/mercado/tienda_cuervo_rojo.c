//Valar Diciembre 02

inherit "/std/tienda";

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Tienda del Cuervo Rojo%^RESET%^");
   set_long ("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Tienda del Cuervo Rojo%^RESET%^\n\n"
           "Estas en la tienda del cuervo rojo donde puedes comprar toda clase de equipo para "
           "tus incursiones en territorios inhospitos y tus salidas fuera de la ciudad. "
           "seguro que encuentras algo que te sera de utilidad.\n\n"); 

   set_dependiente("herreroqsea");   

   set_tipo("standard");

   set_exit_color("red");

    add_exit("casa_valar","/w/valar/workroom.c","door");
   //suministro
   add_suministro("/",2);
   add_suministro("/",2);
   add_suministro("/",2);
   add_suministro("/",2);
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
