inherit "/std/outside.c";

void setup()

{
    set_short("Camino a lo desconocido");
     set_long("Camino a lo desconocido\n\n"+
      "Aunque parezca mentiraaaaaaaaa me pongo coloradaaa cuando "+
	"me miraaan, osea jo.\n\n");

    set_light(60);
add_item("camino","Ves un camino estrecho y algo tenebroso, no te imaginas" + 
	" a donde puede llevar.\n");

add_exit("sudeste","/room/camino/caminito02","road");
add_exit("norte","/room/camino/caminito00","road");
add_exit("sur","/room/camino_avalon/camino18","road");
add_exit("oeste", "/room/guildsisinos/barracks", "hidden");
}
