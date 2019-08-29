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
add_clone("/d/asgard/npc/joyera.c",1);
add_exit("workroom","/w/monhal/workroom.c","door");
add_exit("sur","/w/monhal/camino/camino2.c","road"); 
add_smell("suelo"," Es un olor desconocido pero nada agradable.");
}