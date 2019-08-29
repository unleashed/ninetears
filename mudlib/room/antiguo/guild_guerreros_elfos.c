inherit "/std/guildroom";

object guildmaster, tablon;

void setup()
{
  set_short("Gremio de %^GREEN%^Guerreros Elfos%^RESET%^");
  set_long("Gremio de %^GREEN%^Guerreros Elfos%^RESET%^\n\n"
           "     This is the great training arena of the Daggerford "
           "ability to crush and mangle.  To the north, you can see a stair"
           " well, which leads up to more rooms of the guild.  To the west "
           "a large open faced building.  There is a large sign attached to"
           " a post in the middle of the ground.  Maybe you'd like to get "
           "some more information on this guild about how to join it.\n\n");
  add_item("guildhall", "The Guildhall of the Fighters is to the south, "
           "this is where they meet to discuss ideas "
           "(a noticeably unused building).\n");
  add_item("building", "A large open faced building to the north "
           "where the guild members keep their weapons and armors.\n");
  add_sign("A large sign attached to the wall off to the side.  "
           "It has writting scrawled on it in some "
           "red substance (You're sure its just paint).\n",
           "\t ________________________________________  \n"
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
  set_exit_color("white");
//  add_exit ("west", DAGG+"drill2", "door");
//  add_exit("north", ROOM+"stair2.c", "corridor");
  add_exit("sur", "/room/camino_avalon/camino02", "door");
//  modify_exit("south", ({"function", "go_daggfight"}));
  modify_exit("sur", ({"function", "go_daggfight"}));
  set_guild("guerreros/slicerelfo");
	set_teaching_person("Rebaneitor");
}

void reset()
{
	if (!guildmaster) {
		guildmaster = clone_object("/baseobs/guildmasters/rebaneitor");
		guildmaster->move(this_object());
	}
	if (!tablon) {
		tablon = clone_object("/obj/misc/board");
		tablon->set_datafile("guerreros_elfos");
		tablon->move(TO);
	}
}

/*int go_daggfight()
{
  if(this_player()->query_guild_name() != "fighter")
  {
    notify_fail("The door refuses to open for you.\n");
    return 0;
  }
  tell_object(this_player(), "May your sword serve you well.\n");
  return 1;
}*/

int go_daggfight()
{
  if(this_player()->query_guild_name() == "guerrero elfo" && guildmaster)
  {
	if (!guildmaster->query_fighting())
		tell_object(this_player(), "Rebaneitor exclama: Sirva tu espada para tu causa!\n");
  }
  return 1;
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
