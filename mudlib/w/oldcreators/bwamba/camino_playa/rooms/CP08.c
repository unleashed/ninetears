inherit "/std/outside.c";
 void setup()
{
set_short("%^YELLOW%^Camino a la playa%^RESET%^");
set_long("%^YELLOW%^Camino a la playa%^RESET%^\n\n Estas en un"
    " camino que se dirige a una playa, el camino esta bastante "
    "deteriorado por el paso continuo de viajeros,a los lados del"
    "camino puedes observar varias dunas de arena y al fondo el "
    "mar con la isla de Krystibal.\n\n");
          
set_light(30);
set_zone("camino_playa");
add_clone("/w/huascar/bosquemalditio/npc/culebra.c",3);
add_clone("/w/huascar/bosquemaldito/npc/sanguijuela.c",2);
add_exit("sudoeste","/w/bwamba/camino_playa/rooms/CP07.c","road"); 
add_exit("noreste","/w/bwamba/camino_playa/rooms/CP09.c","road");
}