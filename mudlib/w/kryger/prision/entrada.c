inherit "/std/room.c";

void setup()
{
	set_light(100);
	set_short("%^BOLD%^RED%^Entrada%^BLACK%^ de la prision%^RESET%^.");
	set_long("%^BOLD%^RED%^Entrada%^BLACK%^ de la prision%^RESET%^.\n\n"
	"Este es el corredor que lleva a las celdas de la prision de %^YELLOW%^Kryger%^RESET%^."
	"Aqui pagan todos los traidores por sus crimenes cometidos contra" 
	"Ninetears.\n\n");
	add_exit("arriba","/w/kryger/workroom.c","door");
	add_exit("norte","/w/kryger/prision/corredor1.c","door");
}
	