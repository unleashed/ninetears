inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/pasillos_01","road");
	add_exit("noreste","w/jerkat/valle_dragon/room/trior/pasillos_03","road");
	add_exit("dentro","w/jerkat/valle_dragon/room/trior/torre/torre_01","door");
}
	