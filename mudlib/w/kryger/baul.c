inherit "/std/vaults/vault_room.c");
void setup ()
{
	set_short("%^BOLD%^RED%^Baul de %^YELLOW%^Kryger%^RESET%^.");
	set_long("%^BOLD%^RED%^Baul de %^YELLOW%^Kryger%^RESET%^.\n\n"
	"Este es el baul personal de %^BOLD%^YELLOW%^Kryger%^RESET%^.Aqui"
	"guarda todos los objetos que ha robado a los mortales e inmortales,"
	"incluso podemos apreciar algun objeto divino");
	set_light(100);
	set_save_file("/w/kryger/logs/save");
	set_vault_log("/w/kryger/logs/baul.c)");
	set_admins( ({"kryger"}) );
	
	add_exit("fuera","/w/kryger/workroom.c","door");
}