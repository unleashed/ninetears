#define CREATOR "Blastaar"
inherit "/std/room.c";
void setup() {
set_short("Entrada a la Cueva de la Montanya Salvaje.");
set_long("Delante de ti divisas una lobrega cueva tetrica y oscura "
"atras quedo ya, la frondosa vegetacion de la ladera de la montanya "
"el aspecto de la entrada es siniestro y deprimente.. te preguntas seriamente "
"que abra dentro.\n");
set_light(10);
add_exit("casa","/w/blastaar/casa","door");
add_exit("dentro","/w/blastaar/montanyas_salvajes/rooms/m2.c","door");
add_exit("sur","/w/blastaar/montanyas_salvajes/rooms/cm1.c","door");
 
}
