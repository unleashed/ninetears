inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/pasillos_12","road");
	add_exit("sudeste","w/jerkat/valle_dragon/room/trior/nobles_08","road");
	add_exit("sudoeste","w/jerkat/valle_dragon/room/trior/pasillos_14","road");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	