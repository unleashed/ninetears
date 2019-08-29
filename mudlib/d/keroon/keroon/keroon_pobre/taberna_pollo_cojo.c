//Valar cocinero 13/12/2002 Muy de noche

 //#include "../../path.h" --> Como no rula lo kito ale
  inherit "/std/hostal";
    void setup() 
{
              set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Taberna del Pollo Cojo%^RESET%^");
               set_long("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^RED%^: Taberna del Pollo Cojo%^RESET%^\n\n"
              "Estas en la Taberna del Pollo Cojo, famosa por sus delicias cocineras cuyo secreto"
              " solo conoce el propio cocinero. Mas vale que comas lo que pidas si no quieres entrar "
              "a formar parte del menu del dia (El cocinero es muy suspicaz).\n\n");

              add_item(({"pared","suelo",}),"La estancia esta hecha con tablones podridos sacados de Valar sabra donde.");

  // Las cosas especiales de las tabernas
add_exit("este","/d/keroon/keroon/keroon_pobre/keroon_23.c","standard");
    add_exit("fuera","/d/keroon/keroon/keroon_pobre/keroon_38.c","standard");

             set_dependiente("/d/keroon/keroon/mercado/npcs/thano.c");

             add_cartel(); 

             add_plato("/baseobs/platos/higado"); 
             add_plato("/baseobs/platos/chupito");
             add_plato("/baseobs/platos/licoralgas");
             add_plato("/baseobs/platos/sesos");
             add_plato("/baseobs/platos/ron");
             add_plato("/baseobs/platos/lechelagarta");

     set_calidad(2); // Los "tenedores" del local, de 0 (antro) a 5 (restaurant de lujo)

     // Los ajustes, prohibiciones y permisiones
        add_ajuste("raza","duergar",100);

     //Permisos de compra
       restringir_permitidos();
      add_permitido("raza","inmortal");
       add_permitido("ciudad","Keroon");
       add_permitido("raza","duergar");
       add_permitido("gremio","battleranger");
       add_permitido("alineamiento","Legal Malvado");
       add_permitido("alineamiento","Neutral Malvado");


     }
