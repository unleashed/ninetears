inherit "/std/outside.c";
 void setup()
{
set_short("%^GREEN%^Camino %^RESET%^");
set_long("%^GREEN%^Camino %^RESET%^\n\n Te encuentras"
    " en un camino lugubre y sombrio, la calzada esta muy deteriorada "
    "debido al ir y venir de los agricultores, sus carros y sus animales.\n\n");
          
add_clone("/d/adiel/room/cultivos/npc/rata.c",2);
add_exit("oeste","/d/adiel/room/cultivos/room/camino1.c","road");
add_exit("noreste","/d/adiel/room/cultivos/room/camino3.c","road"); 
}