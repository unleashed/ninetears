inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("sudeste","w/jerkat/valle_dragon/room/trior/pasillos_15","road");
	add_exit("sudoeste","w/jerkat/valle_dragon/room/trior/pasillos_17","road");
	add_exit("dentro","w/jerkat/valle_dragon/room/trior/torre/torre_03","door");
}
	