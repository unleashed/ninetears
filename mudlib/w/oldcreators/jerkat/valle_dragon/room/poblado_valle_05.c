inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1);
add_exit("norte","w/jerkat/valle_dragon/room/poblado_valle_02_entrada","road");
add_exit("sur","w/jerkat/valle_dragon/room/poblado_valle_06","road");
add_exit("oeste","w/jerkat/valle_dragon/room/poblado_valle_04","road");
}