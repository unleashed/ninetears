inherit "/w/jerkat/valle_dragon/room/trior/caseta_guardias.c";

void setup()
{	
	desc_room();
	add_exit("este","w/jerkat/valle_dragon/room/trior/caseta_guardias_04","road");
	add_exit("norte","w/jerkat/valle_dragon/room/trior/caseta_guardias_01","road");
	add_exit("noreste","w/jerkat/valle_dragon/room/trior/caseta_guardias_02","road");
	add_exit("sur","w/jerkat/valle_dragon/room/trior/mercado_01","door");
	add_clone("w/jerkat/valle_dragon/nopc/guardia_trior_dentro",4+random(2));
	set_zone("trior");
}
	