inherit "/w/jerkat/valle_dragon/room/trior/trior_mercado.c";

void setup()
{	
	desc_room();
	add_exit("norte","w/jerkat/valle_dragon/room/trior/mercado_02","road");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/mercado_06","road");
	add_exit("oeste","w/jerkat/valle_dragon/room/trior/mercado_03","road");
	add_exit("noroeste","w/jerkat/valle_dragon/room/trior/mercado_01","road");
}
	