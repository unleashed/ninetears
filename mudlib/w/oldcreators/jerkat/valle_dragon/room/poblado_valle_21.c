inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1); //
add_exit("norte","w/jerkat/valle_dragon/room/poblado_valle_18","road");
add_exit("oeste","w/jerkat/valle_dragon/room/poblado_valle_22","road");
add_exit("este","w/jerkat/valle_dragon/room/poblado_valle_20","road");
add_clone("/w/jerkat/valle_dragon/nopc/hab_valle",random(2));
}
