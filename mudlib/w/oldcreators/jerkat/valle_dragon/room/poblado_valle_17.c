inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1);
add_exit("norte","w/jerkat/valle_dragon/room/poblado_valle_12","road");
add_exit("sur","w/jerkat/valle_dragon/room/poblado_valle_22","road");
add_exit("este","w/jerkat/valle_dragon/room/poblado_valle_18","road");
add_exit("oeste","w/jerkat/valle_dragon/room/poblado_valle_16","road");
add_exit("arriba","w/jerkat/valle_dragon/room/poblado_cabanya_17","door");
}
