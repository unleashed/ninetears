inherit "/w/jerkat/valle_dragon/room/trior/torre/trior_exterior_torre.c";

void setup()
{	
	desc_room();
	add_exit("dentro","w/jerkat/valle_dragon/room/trior/torre/centro","door");
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/torre/torre_01","road");
	add_exit("sudoeste","w/jerkat/valle_dragon/room/trior/torre/torre_03","road");
}
	