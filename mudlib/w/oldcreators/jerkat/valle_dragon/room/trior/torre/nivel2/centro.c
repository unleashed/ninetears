inherit "/w/jerkat/valle_dragon/room/trior/torre/trior_caracol_torre.c";

void setup()
{	
	desc_room();
	add_exit("arriba","w/jerkat/valle_dragon/room/trior/torre/nivel3/centro","door");
	add_exit("abajo","w/jerkat/valle_dragon/room/trior/torre/nivel1/centro","door");
	add_exit("dentro","w/jerkat/valle_dragon/room/trior/torre/nivel2/torre_02","door");
}
	