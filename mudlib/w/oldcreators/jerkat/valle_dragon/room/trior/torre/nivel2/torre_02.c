inherit "/w/jerkat/valle_dragon/room/trior/torre/trior_interior_torre.c";

void setup()
{	
	desc_room();
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/torre/nivel2/torre_01","road");
	add_exit("sudoeste","w/jerkat/valle_dragon/room/trior/torre/nivel2/torre_03","road");
	add_exit("fuera","w/jerkat/valle_dragon/room/trior/torre/nivel2/centro","door");
}
	