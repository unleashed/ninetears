inherit "/std/outside.c";
 void setup()
{
set_short("%^GREEN%^Camino %^RESET%^");
set_long("%^GREEN%^Camino %^RESET%^\n\n Te encuentras"
    " en un camino lugubre y sombrio, la calzada esta muy deteriorada "
    "debido al ir y venir de agricultores con sus carros y animales..\n\n");
          
add_clone("/d/adiel/room/cultivos/npc/paseante.c",1);
add_exit("noroeste","/d/adiel/room/cultivos/room/camino21.c","road");
add_exit("sudeste","/d/adiel/room/cultivos/room/camino23.c","road"); 
}