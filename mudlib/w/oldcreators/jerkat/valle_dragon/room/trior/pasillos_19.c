inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("este","w/jerkat/valle_dragon/room/trior/pasillos_18","road");
	add_exit("escaleras","w/jerkat/valle_dragon/room/trior/almenas_10","door");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	