// Valar 17/12/02


inherit "/std/suboscuridad";
 //#include"../../path.h" --> desab temporalmente

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Despacho General%^RESET%^");

   set_long("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Despacho General%^RESET%^.\n\n"
      "   Aqui es donde se encuentra el general de la ciudad de keroon. Desde este despacho "
      "coordina los servicios y tropas de toda la ciudad y alrededores. Mejor que no te metas"
      " con el o puedes acabar malamente.\n\n");

   add_item("paredes","Las paredes contienen las imagenes de las personas mas buscadas "
                      "por sus fechorias.\n");
   add_item("suelo","El suelo esta sucio y pegajoso, con numerosas manchas de sangre, sin "
                    "duda por las numerosas peleas que aqui se montan.\n");
                       	              

   add_smell(({"habitacion","ambiente","aire"}),"El ambiente esta enrarecido, por "
      "lo visto aqui no saben lo que es el jabon ni un servicio de limpieza. Ni siquiera"
      "ves una papelera.\n");

   add_taste(({"muros","paredes","pared"}),"Agghh, que asco. Solo a t� se te ocurriria ponerte "
      "a chupetear una pared\n");

   add_sound(({"habitacion","entorno"}),"Los prisioneros no paran de quejarse, oyes mucho "
      "tumulto por el arriba y ruidos de pisadas que hacen crujir el techo.\n");

//   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c",1+random (6));
   
   
   add_clone("/d/keroon/keroon/keroon_pobre/npcs/sargento_keroon.c");
   
   set_zone("Keroon");
  
  add_exit("este","/d/keroon/keroon/keroon_pobre/oficina1.c","door");
   add_exit("oeste","/d/keroon/keroon/keroon_pobre/oficina2.c","door");
    add_exit("abajo","/d/keroon/keroon/keroon_pobre/cuartel_keroon.c","door");
//    add_exit("arriba","/d/keroon/keroon/keroon_pobre/jefazo.c","door");
  
}
