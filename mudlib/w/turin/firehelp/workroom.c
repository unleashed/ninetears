#define YO "firehelp"

inherit "/std/room.c";

void setup () {

set_short("Habitacion de aprendizaje de "+capitalize(YO));

set_long("\n  Esta habitacion esta totalmente vacia ya que "+capitalize(YO)+" aun no save hacer objetos. Lo unico que puedes ver es un espejo.\n\n");

add_item("espejo","Te ves a ti mismo y te asustas!.\n");

add_feel("espejo","Al tocar el espejo sientes que esta un poco helado.\n");

add_exit("comun","/w/common","door");

add_exit("sur","/w/firehelp/cocina","door");

}