inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1);
add_exit("este","/w/jerkat/valle_dragon/room/poblado_valle_07","road");
add_exit("sur","/w/jerkat/valle_dragon/room/poblado_valle_12","road");
add_exit("oeste","/w/jerkat/valle_dragon/room/poblado_valle_09_entrada","door");
add_clone("/w/jerkat/valle_dragon/nopc/hab_valle",random(2));
}
