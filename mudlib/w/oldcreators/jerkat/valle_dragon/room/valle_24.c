inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);
add_exit("sudeste","w/jerkat/valle_dragon/room/valle_25","road");
add_exit("oeste","w/jerkat/valle_dragon/room/valle_23","road");
add_clone("/w/jerkat/valle_dragon/nopc/mosquito",random(2));
}
