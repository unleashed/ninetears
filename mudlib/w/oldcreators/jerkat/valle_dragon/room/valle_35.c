inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);
add_exit("sur","w/jerkat/valle_dragon/room/valle_36","road");
add_exit("oeste","w/jerkat/valle_dragon/room/valle_34","road");
add_clone("/w/jerkat/valle_dragon/nopc/mosquito",2);
}
