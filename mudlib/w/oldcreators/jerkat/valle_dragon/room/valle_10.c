inherit "w/jerkat/valle_dragon/room/valle_dragon.c";

void setup()
{
do_desc(1);

// mirar para que sirve el do_desc(1) este...  //

add_exit("noreste","w/jerkat/valle_dragon/room/valle_11","road");
add_exit("sudoeste","w/jerkat/valle_dragon/room/valle_09","road");
}
