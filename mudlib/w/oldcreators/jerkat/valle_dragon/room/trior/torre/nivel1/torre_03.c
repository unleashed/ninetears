inherit "/w/jerkat/valle_dragon/room/trior/torre/trior_interior_torre.c";

void setup()
{	
	desc_room();
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/torre/nivel1/torre_04","road");
	add_exit("noreste","w/jerkat/valle_dragon/room/trior/torre/nivel1/torre_02","road");
	add_exit("fuera","w/jerkat/valle_dragon/room/trior/torre/nivel1/centro","door");
}
	