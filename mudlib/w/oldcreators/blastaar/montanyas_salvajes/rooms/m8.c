#define CREATOR "Blastaar"
inherit "/std/room.c";
void setup() {
set_short("%^BLACK%^BOLD%^Minas%^RESET%^ de %^BOLD%^Acero");
set_long("Oyes el sonido de acero golpeando acero "
"parece que hay bastante actividad por aqui, amen de un intenso "
"olor a sudor y a excrementos, probablemente los orcos "
"hayan estado torturando a los sufridos mineros exclavos que "
"aqui se encuentran.\n\n");
set_light(30);
add_exit("noroeste","/w/blastaar/montanyas_salvajes/rooms/m5.c","door");
add_exit("sur","/w/blastaar/montanyas_salvajes/rooms/min1.c","door");
add_exit("este","/w/blastaar/montanyas_salvajes/rooms/min2.c","door");
add_exit("oeste","/w/blastaar/montanyas_salvajes/rooms/min3.c","door");
}
