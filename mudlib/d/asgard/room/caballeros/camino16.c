inherit "/room/camino_avalon/camino_avalon";

void setup()
{
	do_desc(0);
     set_long("%^CYAN%^Camino en construccion a Avalon: Extremo%^RESET%^\n\n"
      "Has llegado a lo que parece ser el fin provisional del camino, "
	"donde se espera seguir abriendo paso hacia Avalon. Parece que "
	"tendras que volver sobre tus pasos, ya que este lugar estara "
	"bastante abandonado hasta que los elfos prosigan con su "
	"obra.\n\n");

add_exit("oeste","/room/camino_avalon/camino15","road");
add_exit("sur","/d/asgard/room/caballeros/entrada.c","door");
}
