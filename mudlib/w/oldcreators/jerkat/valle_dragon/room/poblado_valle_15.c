inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1); 
add_exit("norte","w/jerkat/valle_dragon/room/poblado_valle_10_entrada","road");
add_exit("sudeste","w/jerkat/valle_dragon/room/poblado_valle_23","road");
add_clone("/w/jerkat/valle_dragon/nopc/hab_valle",random(1));
}
