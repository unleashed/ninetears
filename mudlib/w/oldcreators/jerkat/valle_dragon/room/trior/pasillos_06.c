inherit "/w/jerkat/valle_dragon/room/trior/trior_pasillos.c";

void setup()
{	
	desc_room();
	add_exit("oeste","w/jerkat/valle_dragon/room/trior/pasillos_03","road");
	add_exit("norte","w/jerkat/valle_dragon/room/trior/pasillos_04","road");
	add_exit("sudeste","w/jerkat/valle_dragon/room/trior/pasillos_08","road");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",2);
}
	