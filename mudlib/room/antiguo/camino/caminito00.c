inherit "/std/bosque.c";

void setup()

{
    set_short("Camino a lo desconocido");
     set_long("Camino a lo desconocido\n\n"+
      "Aunque parezca mentiraaaaaaaaa me pongo coloradaaa cuando "+
	"me miraaan, osea jo.\n\n");

    set_light(60);
add_item("camino","Ves un camino estrecho y algo tenebroso, no te imaginas" + 
	" a donde puede llevar.\n");

add_exit("sur","/room/camino/caminito01","road");
add_exit("noroeste","/room/entryroom","door");
add_exit("este", "/room/guild_battles_duergars", "door");
}
