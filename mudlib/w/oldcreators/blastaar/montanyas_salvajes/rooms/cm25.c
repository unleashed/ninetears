inherit "/std/room.c";

void setup ()   {

set_short("Entrada a las Ruinas de %^BLACK%^BOLD%^Margkhor%^RESET%^");
set_long("Esta es la puerta oeste de las ruinas de esta antanyo "
"hermosa y prospera ciudad,ahora derruida por las fuerzas del "
"mal, y tomada en nombre de los demonios del infierno, la "
"ciudad respira un aura de maldad sin igual."
"Las puertas estan medio derruidas pero aun seria necesario "
"otra invasion considerable para tirarlas.. lo que hace de "
"este lugar una zona aun segura para los orcos y trolls que "
"merodean por el lugar y que pueden ser acosados en cualquier "
"momento.\n");
set_light(50);
add_exit("oeste","/w/blastaar/montanyas_salvajes/rooms/cm24.c","door");
add_exit("dentro","/w/blastaar/montanyas_salvajes/rooms/city1.c","door");
add_exit("norte","/w/blastaar/montanyas_salvajes/rooms/mu1.c","door");
add_exit("sur","/w/blastaar/montanyas_salvajes/rooms/mu2.c","door");
}
