// Made by Thalos  01/04/02
//jardines reales

inherit "/std/underground";
#include "../../path.h"

void setup() {

   set_zone("jardines""keroon_rico");
   set_exit_color("cyan");
   set_light(50);
   set_short("%^BOLD%^CYAN%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Plazoleta de los Jardines Reales%^RESET%^");
   set_long("\n%^BOLD%^CYAN%^Ciudad de %^BLACK%^Keroon%^GREEN%^: Plazoleta de los Jardines Reales%^RESET%^.\n\n""Estas en un coqueta plazoleta dentro de los jardines reales, en esta plazoleta los duergars de clase pudientas se dedican a pasear y descansar de sus tribulaciones diarias, mientras sus hijos se dedican a jugar en las amplias avenidas. Puedes ver un estatua enclavada en su centro rodeada de varias gradas repletas de asientos, asi como un pequenyo escenario donde los duergars pueden disfrutar de conciertos de musica asi como de obras de teatro.""\n\n");
   add_item("suelo", "Ves una alfomra de cuidados musgos y liquenes de diversos colores con algunas setas y hongos dispersos alrededor de un camino empedrado cuidado con gran esmero.\n");   
   add_item("escenario", "Es un escenario construido en marmol donde los mejores artistas duergars dan representaciones y conciertos.\n");   
   add_clone(ITEMSJARDINES+"estatua.c");
add_clone(NPCSJARDINES+"bixos_jardines.c",random(5)); 
   
add_exit("oeste",JARDINES+"keroon_221.c","standard");
add_exit("este",JARDINES+"keroon_223.c","standard");
}
