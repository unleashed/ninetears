inherit "/w/jerkat/valle_dragon/room/trior/torre/trior_caracol_torre.c";

void setup()
{	
	desc_room();
	add_exit("abajo","w/jerkat/valle_dragon/room/trior/torre/nivel4/centro","door");
	add_clone("w/jerkat/valle_dragon/nopc/chevoi.c",1);
}
	