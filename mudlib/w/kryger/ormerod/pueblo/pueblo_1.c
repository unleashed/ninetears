inherit "/std/room.c";

void setup ()
{
	set_short("%^BOLD%^BLUE%^Calle Principal %^RESET%^.");
	set_long("%^BOLD%^BLUE%^Calle Principal %^RESET%^.\n\n"
	"Estamos en una de las calles de Ormerod, vemos que las casas estan echas "
	"de madera vieja, tiene todo el aspecto de ser un pueblo ganadero, "
	"es apreciable por las huellas y los excrementos de animales en el centro "
	"de la calle. En uno de los ladoes vemos a dos aldeanos discutiendo por "
	"algo.");
	set_light(100);

	add_clone("/w/kryger/ormerod/npc/aldeano.c",1);
	add_exit("norte","/w/kryger/ormerod/pueblo/pueblo_2.c","door");
	add_exit("este","/w/kryger/ormerod/pueblo/pueblo_3.c","door");
	add_exit("noreste","/w/kryger/ormerod/pueblo/pueblo_4.c","door");
	add_exit("sudoeste","/w/kryger/ormerod/caminos/camino_9.c","door");
}