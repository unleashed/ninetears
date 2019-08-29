inherit "/std/outside.c";
 void setup()
{
set_short("%^GREEN%^ Cultivos de Adiel %^RESET%^");
set_long("%^GREEN%^Cultivos de Adiel %^RESET%^\n\n Te encuentras"
    " en una gran extension de terreno utilizada por los agricultores de Adiel "
    " para cultivar todo tipo de legumbres, cereales y arboles fruteros."
    " Esta zona de cultivos es de gran importancia para los habitantes de la "
    " ciudad, ya que es la que los abastece de comida y es un lugar donde muy "
    "de vez en cuando se celebran las fiestas campestres.\n\n");
      
add_clone("/d/adiel/room/cultivos/npc/agricultor.c",2);    
add_exit("este","/d/adiel/room/cultivos/room/2cultivo2.c","road");
add_exit("norte","/d/adiel/room/cultivos/room/camino44.c","road");
add_exit("sur","/d/adiel/room/cultivos/room/2cultivo8.c","road");
}