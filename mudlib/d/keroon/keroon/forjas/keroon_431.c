// Made by Thalos  01/04/02
// Forjas

inherit "/std/suboscuridad";
#include "../../path.h"

void setup() {

   set_zone("forjas");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^YELLOW%^: Forjas%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^YELLOW%^: Forjas%^RESET%^.\n\n""Estas en las forjas de Keroon, aqui es donde se procesan los diversos minerales que se extraen de las minas para convertirlos en materiales ya aprovechables. Esta ubicada en la zona pobre debido a que por su peligro de incendio se considero que era el mejor sector para su ubicacion. En el suelo puedes ver railes para las vagonetas, asi como poleas y cabestrantes para facilitar su movimiento hasta los hornos.Aqui el calor resulta casi insoportable por la proximidad de los grandes fuegos que alimentas los hornos.""\n\n");
add_item(({"rail","railes"}),"Son unos railes de hierro, en excelente estado de conversacion por el continuo paso de las vagonetas.\n"); 
add_item(({"vagoneta","vagonetas"}),"Son unas vagonetas, dedicadas al transporte de los materiales extraidos de las diversas zonas de las minas, hasta loshornos para su fundicion.\n"); 
add_item(({"polea","poleas"}),"Son unas poleas dedicadas a coger la vagoneta y elevarlas hasta la posicion idones para descargar su contenido en los hornos.\n"); 
add_item(({"cabestrante","cabestrantes"}),"Son unos cabestrantes utilizados para mover pacilmente las vagonetas hasta las poleas.\n"); 
add_item(({"horno","hornos"}),"Son unos grandes hornos, dedicados exclusivamente a la fundicion de minerales, estan alimentados por unos grandes fuegos que hacen que el ambiente sea seco y muy caluroso.\n"); 
add_clone(NPCSFORJAS+"forjas.c",random(3));
add_exit("oeste",FORJAS+"keroon_430.c","standard");
add_exit("norte",FORJAS+"keroon_406.c","standard");
add_exit("este",FORJAS+"keroon_432.c","standard");
}
