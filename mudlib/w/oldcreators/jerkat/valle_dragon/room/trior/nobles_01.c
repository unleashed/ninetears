inherit "/w/jerkat/valle_dragon/room/trior/trior_nobles.c";

void setup()
{	
	desc_room();
	add_exit("oeste","w/jerkat/valle_dragon/room/trior/pasillos_05","road");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/nobles_02","road");
	add_exit("escaleras","w/jerkat/valle_dragon/room/trior/almenas_28","door");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	