#define CREATOR "Blastaar"
inherit "/std/room.c";
void setup() {
set_short("Cavernas de la %^RED%^BOLD%^Montanya %^GREEN%^Salvaje");
set_long("Delante de ti se expanden grandes cuevas que van hacia todas "
"direcciones.El olor es nauseabundo y contienes la respiracion."
"Oyes ruidos procedentes del interior de la gruta."
"Seguramente son Trasgos u Orcos que habitan por estos parajes.\n");
set_light(30);
add_exit("norte","/w/blastaar/montanyas_salvajes/rooms/m3.c","door");
add_exit("oeste","/w/blastaar/montanyas_salvajes/rooms/m4.c","door");
add_exit("este","/w/blastaar/montanyas_salvajes/rooms/m5.c","door");
add_exit("fuera","/w/blastaar/montanyas_salvajes/rooms/m1.c","door");
}
