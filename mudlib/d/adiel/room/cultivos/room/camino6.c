inherit "/std/outside.c";
 void setup()
{
set_short("%^GREEN%^Camino %^RESET%^");
set_long("%^GREEN%^Camino %^RESET%^\n\n Te encuentras"
    " en un camino lugubre y sombrio, la calzada esta muy deteriorada "
    "debido al ir y venir de agricultores con sus carros y animales..\n\n");
          
add_exit("noroeste","/d/adiel/room/cultivos/room/camino5.c","road");
add_exit("este","/d/adiel/room/cultivos/room/camino7.c","road"); 
}