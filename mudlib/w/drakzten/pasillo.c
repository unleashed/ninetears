#define YO "drakztine"

inherit "/std/room.c";

void setup () {

set_short("Pasillo");

set_long(query_short()+"\n Es un pasillo algo angosto pero bien iluminado, tiene algunas antorchas a los costados, es algo extra�o porque no logras ver lo que hay al final.\n\n");

add_item("antorcha","Ves una antorcha comun y corrtiente.\n");

add_feel("antorcha","Quema!! quema muchooo!!.\n");

add_exit("norte","/w/drakzten/cocina","door");

add_exit("sur","/w/drakzten/habitacion","door");

}