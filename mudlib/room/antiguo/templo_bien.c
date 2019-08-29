inherit "/std/outside.c";

void setup()

{
	set_light(80);
    set_short("%^BOLD%^Templo Blanco %^RESET%^: Entrada");
    set_long("%^BOLD%^Templo Blanco %^RESET%^: Entrada\n\n"
        "Un gran templo se cierne sobre ti. La luz lo envuelve "
	"haciendo de el un lugar que parece especialmente protegido. "
	"Al norte observas el camino que te ha traido hasta aqui, "
	"que contrasta con la alegria de este edificio.\n\n");

set_exit_color("white");
add_exit("norte", "/room/camino/caminito02", "road");
add_exit("arriba", "/room/sacrifice/templo_bien", "door");
}
