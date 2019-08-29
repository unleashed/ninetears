// arreglar lo de las salidas cavando
inherit "/std/room.c";

void setup()
{
    set_short("%^BOLD%^%^BLUE%^Caverna en el Camino%^RESET%^");
     set_long("%^BOLD%^%^BLUE%^Caverna en el Camino%^RESET%^\n\n"
      "El corredor de la caverna tuerce lentamente. En esta estancia un "
	"fetido olor te llama la atencion. Parece que despues de todo algun "
	"animal aun vive o vivio aqui.\n\n");

    set_light(30);

	add_item("roca", "Una enorme roca situada en la zona noreste de la sala.");
	add_smell(({"fetido", "olor"}), "Un asqueroso olor impregna el suelo. No sabrias si decir que son excrementos o restos putrefactos de cuerpos, ya que no ves ningun hueso.");
	add_exit("oeste", "/room/camino_avalon/hoyo01", "corridor");
	add_exit("sudeste", "/room/camino_avalon/hoyo03", "door");
	modify_exit("sudeste", ({"function", "ver_salida"}));
}

int ver_salida()
{
	tell_object(TP, "De pronto te invade una gran sensacion de peligro.\n");
	return 1;
}
