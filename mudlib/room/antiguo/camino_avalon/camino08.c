inherit "/room/camino_avalon/camino_avalon";

void setup()
{
	do_desc(1);
add_exit("noroeste","/room/camino_avalon/camino07","road");
add_exit("este","/room/camino_avalon/camino09","road");
add_exit("norte", "/room/guild_khazads", "door");
}
