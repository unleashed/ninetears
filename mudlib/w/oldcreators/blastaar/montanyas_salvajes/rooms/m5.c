#define CREATOR "Blastaar"
inherit "/std/room.c";
void setup() {
set_short("Cavernas de la %^RED%^BOLD%^Montanya %^GREEN%^Salvaje");
set_long("Delante de ti se expanden grandes cuevas que van hacia todas "
"direcciones.El olor es nauseabundo y contienes la respiracion."
"Oyes ruidos procedentes del interior de la gruta."
"Seguramente son Trasgos u Orcos que habitan por estos parajes.\n");
set_light(30);
add_exit("oeste","/w/blastaar/montanyas_salvajes/rooms/m2.c","door");
add_exit("este","/w/blastaar/montanyas_salvajes/rooms/m7.c","door");
add_exit("sudeste","/w/blastaar/montanyas_salvajes/rooms/m8.c","door");
}
