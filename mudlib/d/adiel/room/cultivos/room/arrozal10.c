inherit "/std/outside.c";
 void setup()
{
set_short("%^BOLD%^%^GREEN%^Arrozales. %^RESET%^");
set_long("%^BOLD%^%^GREEN%^Arrozales. %^RESET%^\n\n Te encuentras"
    " en una gran extension de terreno , utilizada para el cultivo del arroz"
    ", debido a la altura de la planta y a lo pantanoso del terreno la vision"
    " y tu velocidad podrian verse mermadas. El cultivo de arroz en Adiel es"
    " muy importante para sus gentes ya que les proporciona alimento en las temporadas"
    "de frio o sequia.\n\n");
          
add_clone("/d/adiel/room/cultivos/npc/agricultor.c",2);
add_exit("este","/d/adiel/room/cultivos/room/arrozal11.c.c","road");
add_exit("oeste","/d/adiel/room/cultivos/room/arrozal9.c","road");
add_exit("sur","/d/adiel/room/cultivos/room/1cultivo11.c","road");
}