inherit "/std/room.c";

void setup ()   {

set_short("Camino a %^BLACK%^BOLD%^Margkhor%^RESET%^");
set_long("Este camino ha sido construido por los antiguos "
"humanos que vivian en Margkhor, por eso parece tan cuidado "
"aunque no obstante, veas que el empedrado ha empezado a "
"saltar por varios sitios.\n");
set_light(50);
add_exit("norte","/w/blastaar/montanyas_salvajes/rooms/cm18.c","door");
add_exit("sur","/w/blastaar/montanyas_salvajes/rooms/cm20.c","door");
}
