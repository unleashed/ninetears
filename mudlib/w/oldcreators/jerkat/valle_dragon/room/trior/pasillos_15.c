inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("este","w/jerkat/valle_dragon/room/trior/pasillos_14","road");
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/pasillos_16","road");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	