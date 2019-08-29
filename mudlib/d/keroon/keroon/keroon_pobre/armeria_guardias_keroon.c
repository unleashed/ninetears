//Valar Diciembre 02
   inherit "/std/tienda";

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Armeria de la Guardia%^RESET%^");
    set_long ("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon: %^RED%^ Armeria de la Guardia%^RESET%^\n\n"
           "Esta armeria pertenece a la Guardia de Keroon. En ella puedes encontrar el equipo basico"
           "que llevan los guardias de Keroon sin tener que estas partindoles el culo. De este modo "
           "ellos tambien se pueden ir sacando unas pelillas para tomarse algo.\n\n");

   set_dependiente("/d/keroon/keroon/mercado/npcs/dabad-dinal.c");

   set_tipo("armeria");

   set_exit_color("red");

   add_exit("este","/d/keroon/keroon/keroon_pobre/cuartel_keroon.c","door");

   //suministro
   add_suministro("//d/keroon/keroon/keroon_pobre/equipo/brazalete_guardia.c",2);
   add_suministro("/d/keroon/keroon/keroon_pobre/equipo/capa_capitan.c",3);
   add_suministro("/d/keroon/keroon/keroon_pobre/equipo/cota_guardia.c",2);
   add_suministro("/d/keroon/keroon/keroon_pobre/equipo/hacha_guardia.c",1);
   add_suministro("/d/keroon/keroon/keroon_pobre/equipo/latigo.c",2);

   //ajustes de precios
   add_ajuste("raza","duergar",200);//Duergar al 100%

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
