inherit "/w/jerkat/valle_dragon/room/trior/trior_mercado.c";

void setup()
{	
	desc_room();
	add_exit("norte","w/jerkat/valle_dragon/room/trior/mercado_03","road");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/mercado_07","road");
	add_exit("oeste","w/jerkat/valle_dragon/room/trior/trior_entrada","door");
	add_exit("este","w/jerkat/valle_dragon/room/trior/mercado_06","road");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	