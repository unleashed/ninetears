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
add_clone("/w/huascar/bosquemalditio/npc/mapache.c",1);
add_clone("/w/huascar/bosquemaldito/npc/mariposa.c",4);
add_exit("este","/w/bwamba/camino_playa/rooms/CP11.c","road"); 
add_exit("oeste","/w/bwamba/camino_playa/rooms/CP13.c","road");
add_exit("altar","/w/bwamba/camino_playa/rooms/altar.c","door");
}