inherit "/std/outside.c";
 void setup()
{
set_short("%^GREEN%^Camino %^RESET%^");
set_long("%^GREEN%^Camino %^RESET%^\n\n Te encuentras"
    " en un camino lugubre y sombrio, la calzada esta muy deteriorada "
    "debido al ir y venir de los agricultores ,sus carros y sus animales .\n\n");
          
add_clone("/d/adiel/room/cultivos/npc/abeja.c",1);
add_exit("norte","/d/adiel/room/cultivos/room/acueducto1.c","road");
add_exit("sudoeste","/d/adiel/room/cultivos/room/camino2.c","road");
add_exit("sudeste","/d/adiel/room/cultivos/room/camino4.c","road"); 
}