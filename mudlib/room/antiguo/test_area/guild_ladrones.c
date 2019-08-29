inherit "/std/guildroom";

object guildmaster;

void setup()
{
  set_short("Gremio de %^YELLOW%^Ladrones%^RESET%^: Entrada");
  set_long("Gremio de %^YELLOW%^Ladrones%^RESET%^: Entrada\n\n"
           "     This is the great training arena of the Daggerford "
           "ability to crush and mangle.  To the north, you can see a stair"
           " well, which leads up to more rooms of the guild.  To the west "
           "a large open faced building.  There is a large sign attached to"
           " a post in the middle of the ground.  Maybe you'd like to get "
           "some more information on this guild about how to join it.\n\n");
  add_sign("A large sign attached to the wall off to the side.  "
           "It has writting scrawled on it in some "
           "red substance (You're sure its just paint).\n",
           "\t________________________________________  \n"
           "\t|\\______________________________________/| \n"
           "\t||                                      || \n"
           "\t||        %^RED%^WELCOME TO THE ARENA%^RESET%^          || \n"
           "\t||                                      || \n"
           "\t||   -- Type 'join' become a member of  || \n"
           "\t||      fighter's guild.                || \n"
           "\t||   -- For more information on the     || \n"
           "\t||      Fighters' Guild type 'info'.    || \n"
           "\t||   -- To advance your levels type     || \n"
           "\t||      'advance'.                      || \n"
           "\t||   -- To see how much it will take    || \n"
           "\t||      out of you to improve yourself  || \n"
           "\t||      type 'cost'.                    || \n"
           "\t||                                      || \n"
           "\t||______________________________________|| \n"
           "\t|/______________________________________\\| \n\n");
  set_light (50);
//  add_clone(CHAR+"knight.c",2);
//  add_clone("/baseobs/monsters/warrior.c",2);
  set_exit_color("green");
//  add_exit ("west", DAGG+"drill2", "door");
//  add_exit("north", ROOM+"stair2.c", "corridor");
  add_exit("noroeste", "/room/test_area/r021", "door");
  set_guild("picaros/ladron");
set_teaching_person("Sternad");
}

void reset()
{
	if (!guildmaster) {
		guildmaster = clone_object("/baseobs/guildmasters/sternad.c");
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
