inherit "/std/room.c";

void setup ()   {

set_short("Camino a %^BLACK%^BOLD%^Margkhor%^RESET%^");
set_long("Este camino ha sido construido por los antiguos "
"humanos que vivian en Margkhor, por eso parece tan cuidado "
"aunque no obstante, veas que el empedrado ha empezado a "
"saltar por varios sitios.\n");
set_light(50);
add_exit("norte","/w/blastaar/montanyas_salvajes/rooms/cm13.c","door");
add_exit("sudoeste","/w/blastaar/montanyas_salvajes/rooms/cm15.c","door");
}
