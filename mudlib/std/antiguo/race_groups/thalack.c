inherit "/std/race_group.c";

setup()
{
   set_name("Casa de Thalack");

   set_short("Casa de Thalack");

}

int query_legal_race(string race)
{
	switch(race) {
		case "Inmortal":
		case "inmortal":
		case "Immortal":
		case "immortal":
		case "Drow":
		case "drow":
		case "God":
		case "god":
			return 1;
	}
	return 0;
}

int query_channel() { return(1); }

int query_drow_house() { return 1; }
