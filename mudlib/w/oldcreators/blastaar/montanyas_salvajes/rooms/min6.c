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
add_exit("norte","/w/blastaar/montanyas_salvajes/rooms/min4.c","door");
}
