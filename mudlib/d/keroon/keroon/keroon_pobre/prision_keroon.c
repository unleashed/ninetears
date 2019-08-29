// Valar 17/12/02


   inherit "/std/cuartel";


void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Prision%^RESET%^");

   set_long("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Prision%^RESET%^.\n\n"
      "   Estas en la prision del Cuartel de la Guardia  de Keroon, aqui es donde van a parar "
      "todos los maleantes y personas indeseables de la ciudad que son capturados por los guardias. "
      "La unica salida se encuentra hacia arriba y tendras que pasar por penurias si lo que quieres "
      "es salir con vida de aqui..\n\n");

   add_item("norte","Carcel.\n");
   add_item("sur","Carcel.\n");
   add_item("este","Carcel.\n");
   add_item("oeste","Carcel.\n");

   add_item("arriba","Cuartel.\n");
   
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
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/sargento_keroon.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");

   set_zone("Keroon");
  add_exit("este","/d/keroon/keroon/keroon_pobre/prision1","door");
   add_exit("oeste","/d/keroon/keroon/keroon_pobre/prision2","door");
   add_exit("norte","/d/keroon/keroon/keroon_pobre/prision3","door");
   add_exit("sur","/d/keroon/keroon/keroon_pobre/prision4","door");
   add_exit("arriba","/d/keroon/keroon/keroon_pobre/cuartel_keroon.c","door");
  
}
