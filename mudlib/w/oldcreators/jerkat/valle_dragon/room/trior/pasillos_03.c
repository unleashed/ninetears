inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("sudoeste","w/jerkat/valle_dragon/room/trior/pasillos_02","road");
	add_exit("este","w/jerkat/valle_dragon/room/trior/pasillos_06","road");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",2);
}
	