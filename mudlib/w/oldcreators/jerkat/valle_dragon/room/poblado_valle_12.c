inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1);
add_exit("este","w/jerkat/valle_dragon/room/poblado_valle_13","road");
add_exit("sur","w/jerkat/valle_dragon/room/poblado_valle_17","road");
add_exit("oeste","w/jerkat/valle_dragon/room/poblado_valle_11_entrada","door");
add_clone("/w/jerkat/valle_dragon/nopc/hab_valle",random(2));
}