inherit "/w/jerkat/valle_dragon/room/trior/torre/trior_interior_torre.c";

void setup()
{	
	desc_room();
	add_exit("sudeste","w/jerkat/valle_dragon/room/trior/torre/nivel3/torre_02","road");
	add_exit("sudoeste","w/jerkat/valle_dragon/room/trior/torre/nivel3/torre_04","road");
	add_exit("fuera","w/jerkat/valle_dragon/room/trior/torre/nivel3/centro","door");
}
	