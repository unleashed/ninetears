//Valar Diciembre 02
   inherit "/std/tienda";

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: El Escudero Salvage%^RESET%^");
    set_long ("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon: %^RED%^ El Escudero Salvage%^RESET%^\n\n"
           "Esta tienda destartalada y mugrienta se dedica a la venta de escudos traidos de las "
           "mas lejanas batallas y algunos de fabricacion propia. Aunque sus productos no tengan"
           " muy buen aspecto son de la maxima calidad.\n\n");

   set_dependiente("/d/keroon/keroon/mercado/npcs/dabad-dinal.c");

   set_tipo("armeria");

   set_exit_color("red");

   add_exit("fuera","/d/keroon/keroon/mercado/keroon_150.c","door");

   //suministro
   add_suministro("/baseobs/escudos/escudo_medio",2);
   add_suministro("/baseobs/escudos/esq_peq",3);
   add_suministro("/baseobs/escudos/escudo_medio",2);
   
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
