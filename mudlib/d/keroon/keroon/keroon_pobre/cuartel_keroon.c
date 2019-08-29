// Valar 17/12/02


   inherit "/std/cuartel";
#include "../../path.h"

void setup()
{
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cuartel de la Guardia%^RESET%^");

   set_long("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Cuartel de la Guardia%^RESET%^.\n\n"
      "   Estas en el Cuartel de la Guardia  de Keroon, luegar donde descansa los guardias de "
      "la ciudad y donde se realizan los turnos y planifican las guardias. Esta perfectamente "
      "defendido por numerosos guardias que no te quitan ojo de encima. Arriba se encuentran "
      "las dependencias de los jefazos. Al oeste se encuentra la armeria de la guardia al este "
      "el tablon de anuncios de la ciudad y abajo se encuentran las celdas de prisioneros.\n\n");

   add_item("oeste","Armeria.\n");

   add_item("este","Tablon de notas.\n");

   add_item("abajo","Prision.\n");
   
   add_item("arriba","Oficinas.\n");
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
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");
   poner_guardia("/d/keroon/keroon/keroon_pobre/npcs/guardia_puerta.c");

   set_zone("Keroon");
  add_exit("fuera",KEROONPOBRE"keroon_108.c","door");
//  add_exit("este","","door");
   add_exit("oeste","/d/keroon/keroon/keroon_pobre/armeria_guardias_keroon.c","door");
   add_exit("arriba","/d/keroon/keroon/keroon_pobre/oficina.c","door");
   add_exit("abajo","/d/keroon/keroon/keroon_pobre/prision_keroon.c","door");
  
}
