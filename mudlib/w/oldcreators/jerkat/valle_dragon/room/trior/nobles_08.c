inherit "/w/jerkat/valle_dragon/room/trior/trior_nobles.c";

void setup()
{	
	desc_room();
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/pasillos_13","road");
	add_exit("norte","w/jerkat/valle_dragon/room/trior/nobles_07","road");
	add_exit("escaleras","w/jerkat/valle_dragon/room/trior/almenas_19","door");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	