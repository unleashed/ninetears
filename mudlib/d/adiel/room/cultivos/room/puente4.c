inherit "/std/outside.c";
 void setup()
{
set_short("%^BOLD%^%^BLUE%^Puente sobre el rio. %^RESET%^");
set_long("%^BOLD%^%^BLUE%^Puente sobre el rio. %^RESET%^\n\n Te encuentras"
    " en uno de los puentes situados sobre el rio de Adiel, una obra"
    " sencilla pero bonita a la vez. Este puente permite el trasiego de "
    " gente de una orilla a otra .\n\n");
          
add_clone("/d/adiel/room/cultivos/npc/paseante.c",1);
add_exit("norte","/d/adiel/room/cultivos/room/puente3.c","road");
add_exit("sur","/d/adiel/room/cultivos/room/puente5.c","road"); 
}