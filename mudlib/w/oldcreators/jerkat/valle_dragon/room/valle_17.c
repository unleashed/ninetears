inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);
add_exit("norte","w/jerkat/valle_dragon/room/valle_16","road");
add_exit("sur","w/jerkat/valle_dragon/room/valle_18","road");
add_clone("/w/jerkat/valle_dragon/nopc/mosquito",random(2));
}
