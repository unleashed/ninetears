inherit "/w/jerkat/valle_dragon/room/trior/trior_mercado.c";

void setup()
{	
	desc_room();
	add_exit("noreste","w/jerkat/valle_dragon/room/trior/pasillos_01","road");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/mercado_04","road");
	add_exit("oeste","w/jerkat/valle_dragon/room/trior/mercado_01","road");
	add_exit("sudoeste","w/jerkat/valle_dragon/room/trior/mercado_03","road");
}
	