inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/pasillos_09","road");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/pasillos_11","road");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	