inherit "/std/room.c";

void setup ()   {

set_short("Camino a las Montanyas");
set_long("Este sinuoso sendero esta echo a medida "
"que los anyos ha ido pasando gente hacia las "
"tenebrosas montanyas del norte. "
"El escabroso sonido procedente del bosque te "
"hace pensar que no es muy recomendable "
"abandonar el sendero.\n");

set_light(50);
add_exit("este","/w/blastaar/montanyas_salvajes/rooms/cm8.c","door");
add_exit("sur","/w/blastaar/montanyas_salvajes/rooms/enc.c","door");
}
