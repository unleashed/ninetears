inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("noreste","w/jerkat/valle_dragon/room/trior/pasillos_16","road");
	add_exit("oeste","w/jerkat/valle_dragon/room/trior/pasillos_18","road");
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/mercado_10","door");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	