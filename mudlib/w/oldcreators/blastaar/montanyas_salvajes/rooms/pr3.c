inherit "/std/room.c";

void setup()  {

set_short("Camino al%^CYAN%^ Lago%^RESET%^");
set_long("Este pedregoso camino fue hecho por los humanos que vivian en la ciudad "
"antanyo cuando aun iban al lago a descansar. "
"Despues de la invasion de orcos y criaturas demoniacas el lugar "
"a quedado abandonado, a excepcion de extranyas criaturas que habitan en el lago....\n");
set_light(50);
add_exit("este","/w/blastaar/montanyas_salvajes/rooms/pr2.c","door");
add_exit("oeste","/w/blastaar/montanyas_salvajes/rooms/pr4.c","door");

}
