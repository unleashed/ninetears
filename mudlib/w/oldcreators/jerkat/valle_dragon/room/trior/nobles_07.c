inherit "/w/jerkat/valle_dragon/room/trior/trior_nobles.c";

void setup()
{	
	desc_room();
	add_exit("norte","w/jerkat/valle_dragon/room/trior/nobles_06","road");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/nobles_08","road");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	