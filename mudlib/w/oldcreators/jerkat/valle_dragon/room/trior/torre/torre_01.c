inherit "/w/jerkat/valle_dragon/room/trior/torre/trior_exterior_torre.c";

void setup()
{	
	desc_room();
	add_exit("fuera","w/jerkat/valle_dragon/room/trior/pasillos_02","door");
	add_exit("sudeste","w/jerkat/valle_dragon/room/trior/torre/torre_02","road");
	add_exit("sudoeste","w/jerkat/valle_dragon/room/trior/torre/torre_04","road");
}
	