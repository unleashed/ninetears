inherit "w/jerkat/valle_dragon/room/poblado_valle.c";

void setup()
{
do_desc(1);
add_exit("noreste","w/jerkat/valle_dragon/room/poblado_valle_01","road");
add_exit("sudoeste","w/jerkat/valle_dragon/room/poblado_valle_09_entrada","door");
add_exit("este","w/jerkat/valle_dragon/room/poblado_valle_04","road");
}