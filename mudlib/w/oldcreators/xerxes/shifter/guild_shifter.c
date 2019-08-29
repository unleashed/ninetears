inherit "/std/guildroom";

object guildmaster;

void setup()
{
  set_short("Gremio de %^BLACK%^BOLD%^Shapeshifters%^RESET%^");
  set_long("En pruebas");
  set_light (50);
//  add_clone(CHAR+"knight.c",2);
//  add_clone("/baseobs/monsters/warrior.c",2);
  set_exit_color("blue");
//  add_exit ("west", DAGG+"drill2", "door");
//  add_exit("north", ROOM+"stair2.c", "corridor");
  add_exit("sudeste", "/room/entryroom", "door");
  set_guild("other/shifter");
set_teaching_person("patric");
}

void reset()
{
	if (!guildmaster) {
		guildmaster = clone_object("/baseobs/guildmasters/patric.c");
		guildmaster->move(this_object());
	}
}

int do_join(string str)
{
	if (!guildmaster) {
		notify_fail("No hay nadie que te pueda alistar al gremio en este momento.\n");
		return 0;
	}
	if (guildmaster->query_fighting()) {
		notify_fail("El guildmaster no te puede alistar, esta ocupado pensando en sus enemigos.\n");
		return 0;
	}
	this_player()->set_kill_xp((this_player()->query_level() / 2) * 1000000);
	return ::do_join(str);
}

int do_advance(string str)
{
/*	if (!guildmaster) {
		notify_fail("No has notado que tu maestro... no esta?\n");
		return 0;
	}*/
/*	if (guildmaster->query_fighting()) {
		notify_fail("Tu guildmaster esta mas preocupado en matar a sus enemigos.\n");
		return 0;
	}*/
	if (::do_advance(str)) {
		this_player()->set_kill_xp((this_player()->query_level() / 2) * 1000000);
		return 1;
	}
	return 0;
}
