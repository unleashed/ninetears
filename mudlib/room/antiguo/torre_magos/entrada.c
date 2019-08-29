inherit "/std/room.c";

void setup()

{
    set_short("%^BLUE%^Torre de Magos: Piso inferior%^RESET%^");
    set_long("%^BLUE%^Torre de Magos: Piso inferior%^RESET%^\n\n"
        "Te encuentras en el bajo de esta bella torre. Una "
	"tenue aura azul la envuelve, protegiendola magicamente de "
	"de las inclemencias naturales y tal vez de algun que otro "
	"intruso. Parece que aqui ensenyan el arte de la Magia.\n\n");

    set_light(80);
set_exit_color("magenta");

add_exit("sudeste", "/room/camino_avalon/camino05", "door");
add_exit("arriba", "/room/guildmagos/barracks", "door");
}
