inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);
add_exit("norte","w/jerkat/valle_dragon/room/valle_27","road");
add_exit("sudeste","w/jerkat/valle_dragon/room/valle_29","road");
add_clone("/w/jerkat/valle_dragon/nopc/mosquito",random(2));
}
