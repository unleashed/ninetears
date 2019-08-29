// arreglar lo de las salidas cavando
inherit "/std/room.c";

void setup()
{
    set_short("%^BOLD%^%^BLUE%^Caverna en el Camino%^RESET%^");
     set_long("%^BOLD%^%^BLUE%^Caverna en el Camino%^RESET%^\n\n"
      "La caverna se extiende con pequenyas entradas de luz, "
	"en torno a dos o tres metros bajo tierra. La zona parece haber "
	"sido el escondrijo de alguna banda de asaltadores en un tiempo "
	"pasado. No parece haber ningun ruido.\n\n");

    set_light(30);

	add_sound("ruido", "No consigues escuchar nada mas que tus propios movimientos.");
    add_exit("sudoeste","/room/camino_avalon/hoyo00","corridor");
	add_exit("este", "/room/camino_avalon/hoyo02", "corridor");
}
