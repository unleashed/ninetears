#define YO "drakzten"

inherit "/std/room.c";

void setup () {

set_short("El %^BOLD%^%^RED%^ba�o %^RESET%^de "+capitalize(YO));

set_long(query_short()+"\n Al mirar esta habitacion tus ojos comienzan a contemplar el ba�o mas limpio y bello que has visto en toda tu vida. Tiene un water blanco de la mejor marca un lavamanos de marmol totalmente contemplador. Sientes el agradable aroma del ba�o.\n\n");

add_item("water","Nunca havias visto uno mejor...\n");

add_item("lavamanos","Es muy bello, esta algo mojado...\n");

add_feel("lavamanos","Se te humedese el dedo cuando tocas el lavamanos...\n");

add_smell("habitacion","Sientes el rico aroma de pino.\n");

add_exit("este","/w/drakzten/cocina","door");

}
