inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);

// mirar para que sirve el do_desc(1) este...  //

add_exit("norte","w/jerkat/valle_dragon/room/valle_13","road");
add_exit("sudoeste","w/jerkat/valle_dragon/room/valle_11","road");
add_clone("/w/jerkat/valle_dragon/nopc/mosquito",random(2));
}
