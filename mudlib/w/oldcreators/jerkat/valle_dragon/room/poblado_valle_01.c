inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1);
add_exit("sur","w/jerkat/valle_dragon/room/poblado_valle_01","road");
add_exit("sudoeste","w/jerkat/valle_dragon/room/poblado_valle_03","road");
add_exit("este","w/jerkat/valle_dragon/room/poblado_valle_02_entrada","road");
add_clone("/w/jerkat/valle_dragon/nopc/hab_valle",random(3));
}