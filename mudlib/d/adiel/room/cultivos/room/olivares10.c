inherit "/std/outside.c";
 void setup()
{
set_short("%^GREEN%^Olivares. %^RESET%^");
set_long("%^GREEN%^Olivares %^RESET%^\n\n Te encuentras"
    " en una plantacion de olivares a las afueras de Adiel, esta zona causa un gran  "
    "contraste con los otros cultivos de la zona debido a lo seco del terreno, ya que ."
    "solo recibe agua de la acequia. El olor a olivo es fuerte y penetrante "
    " y te ves tentado de coger algunas olivas pero posiblemente la presencia "
    "de numerosos agricultores te frene a hacerlo.\n\n");
      
add_clone("/d/adiel/room/cultivos/npc/agricultor.c",1);    
add_exit("norte","/d/adiel/room/cultivos/room/olivares6.c","road");
add_exit("oeste","/d/adiel/room/cultivos/room/acequia6.c","road");
add_exit("noreste","/d/adiel/room/cultivos/room/olivares7.c","road");
add_exit("sur","/d/adiel/room/cultivos/room/olivares13.c","road");
}