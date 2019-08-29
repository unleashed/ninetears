inherit "/std/room.c";
void setup()
{
	set_light(100);
	set_short("%^BOLD%^RED%^Corredor%^BLACK%^ de la prision%^RESET%^.");
	set_long("%^BOLD%^RED%^Corredor%^BLACK%^ de la prision%^RESET%^.\n\n"
	"Este es el corredor que lleva a las celdas de la prision de %^YELLOW%^Kryger%^RESET%^."
	"Aqui pagan todos los traidores por sus crimenes cometidos contra"
	"Ninetears.\n\n");
	add_exit("sur","/w/kryger/prision/entrada.c","door");
	add_exit("norte","/w/kryger/prision/corredor2.c","door");
	add_exit("este","/w/kryger/prision/celda2.c","door");
	add_exit("oeste","/w/kryger/prision/celda1.c","door");
}
	