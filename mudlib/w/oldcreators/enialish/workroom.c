#define CREATOR "enialish"
inherit "/std/room.c";
void setup() {
set_short("%^BOLD%^GREEN%^Estancias%^WHITE%^ de %^CYAN%^Enialish"
"%^WHITE%^: Sala de Trabajo%^RESET%^");
set_long("\n%^BOLD%^GREEN%^Estancias%^WHITE%^ de %^CYAN%^Enialish"
"%^WHITE%^: Sala de Trabajo%^RESET%^\n\n"
"Te encuentras en las estancias de Enialish, el elfo inmortal. "
"Ante tus ojos se extiende una gran sala de resplandeciente marmol blanco "
"decorada con runas doradas a lo largo de las paredes. Una gran mesa de "
"fina caoba se encuentra en el centro de la sala y sobre ella diversos "
"planos y mapas escritos en algun arcano idioma. En una de las paredes "
"tambien puedes observar una gran estanteria llena de algunos de los tomos "
"mas antiguos que tus ojos han podido contemplar. La sensacion de paz y "
"tranquilidad que sientes aqui es indescriptible.\n");
add_exit("comun", "/w/common","door");
add_exit("elhadrien", "/d/driade/elhadrien/rooms/exterior/entrada","door");
set_light(60);
add_item("runas","La runas de las paredes parecen algun tipo de antigua "
"escritura elfica. No puedes descifrarlas y dudas de que alguien "
"con menos de mil anyos pueda hacerlo pero supones que se trata de algun "
"tipo de proteccion magica o algo por el estilo.");
add_item("mesa","En ella ves planos, mapas y apuntes sobre los proyectos "
"que Enialish esta estudiando en estos momentos. Parecen que estan escritos "
"en la misma lengua que las runas de las paredes, ya que no entiendes nada "
"de lo que pone.");
add_item("tomos","Todo el saber del mundo se encuentra en estos libros, "
"pero es un conocimiento al que nunca podras aspirar.");
}
