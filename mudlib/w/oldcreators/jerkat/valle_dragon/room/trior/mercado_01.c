inherit "/w/jerkat/valle_dragon/room/trior/trior_mercado.c";

void setup()
{	
	desc_room();
	add_exit("norte","w/jerkat/valle_dragon/room/trior/caseta_guardias_03","door");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/mercado_03","road");
	add_exit("este","w/jerkat/valle_dragon/room/trior/mercado_02","road");
	add_exit("sudeste","w/jerkat/valle_dragon/room/trior/mercado_04","road");
}
	