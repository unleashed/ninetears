inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);

// mirar para que sirve el do_desc(1) este...  //

add_exit("noreste","w/jerkat/valle_dragon/room/valle_03","road");
add_exit("sur","w/jerkat/valle_dragon/room/valle_01","road");
add_clone("/w/jerkat/valle_dragon/nopc/mosquito",2);
}
