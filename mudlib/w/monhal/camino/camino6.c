inherit "/std/outside.c";
 void setup()
{
set_short("%^YELLOW%^Camino hacia lo desconocido%^RESET%^");
set_long("%^YELLOW%^Camino hacia lo desconocido%^RESET%^\n\n Te encuentras"
    " en un camino lugubre y sombrio, la calzada esta muy deteriorada "
    "ya que al parecer este camino fue escenario de multiples batallas"
    ". Esta desertico y el olor que emana del suelo te hace pensar que nada "
    "bueno ha sucedido aqui.\n\n");
          
set_light(45);
add_clone("/w/monhal/npc/abeja.c",1);
add_clone("/w/monhal/npc/zorro.c",1);
add_exit("norte","/w/monhal/camino/camino5.c","road");
add_exit("sur","/w/monhal/camino/camino7puesto.c","road"); 
}