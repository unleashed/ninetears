inherit "/w/jerkat/valle_dragon/room/trior/torre/trior_interior_torre.c";

void setup()
{	
	desc_room();
	add_exit("noreste","w/jerkat/valle_dragon/room/trior/torre/nivel5/torre_01","road");
	add_exit("sudeste","w/jerkat/valle_dragon/room/trior/torre/nivel5/torre_03","road");
	add_exit("fuera","w/jerkat/valle_dragon/room/trior/torre/nivel5/centro","door");
}
	