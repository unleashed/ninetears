inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1); 
add_exit("norte","w/jerkat/valle_dragon/room/poblado_valle_11","road");
add_exit("sur","w/jerkat/valle_dragon/room/poblado_valle_23","road");
add_exit("este","w/jerkat/valle_dragon/room/poblado_valle_17","road");
add_exit("oeste","w/jerkat/valle_dragon/room/poblado_valle_15","road");
}
