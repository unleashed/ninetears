inherit "/w/jerkat/valle_dragon/room/trior/trior_mercado.c";

void setup()
{	
	desc_room();
	add_exit("norte","w/jerkat/valle_dragon/room/trior/mercado_01","road");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/mercado_05","road");
	add_exit("este","w/jerkat/valle_dragon/room/trior/mercado_04","road");
	add_exit("noreste","w/jerkat/valle_dragon/room/trior/mercado_02","road");
	add_clone("w/jerkat/valle_dragon/nopc/hab_trior",random(3));
}
	