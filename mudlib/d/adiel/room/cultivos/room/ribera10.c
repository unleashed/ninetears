inherit "/std/outside.c";
 void setup()
{
set_short("%^CYAN%^ Ribera. Zona de pesca.%^RESET%^");
set_long("%^CYAN%^ Ribera. Zona de pesca%^RESET%^\n\n Te encuentras "
    " en la ribera del rio de Adiel, en esta zona es donde se reunen los"
    " numerosos pescadores de la comarca para pescar , ya que la pesca es"
 "una de las mejores fuentes de abastecimiento alimenticio de la ciudad de Adiel.\n\n");
          
add_clone("/d/adiel/room/cultivos/npc/abeja.c",1);
add_clone("/d/adiel/room/cultivos/npc/pescador.c",3);
add_exit("noroeste","/d/adiel/room/cultivos/room/ribera9.c","road");
add_exit("este","/d/adiel/room/cultivos/room/ribera11.c","road"); 
}