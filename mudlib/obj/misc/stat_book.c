/** player stat record book coded by Raskolnikov Sept 1996 **/

#define STATS "/open/stats/"
#define THISOB "/obj/misc/stat_book"
inherit "/std/object.c";

int auto_record, reset_countdown, countdown;
string auto_stat, *autorecording;
object owner;

void create() {
    ::create();
    auto_record = 0;
    autorecording = ({ });
    reset_countdown = 50;
    countdown = 50;
}

void setup() {
    set_name("stat book");
    add_alias("book");
    set_short("Stat Book");
    set_main_plural("Stat Books");
    set_long("Raskolnikov's Book of Stats.\n\n");
    set_read_mess("\nThis book allows the user to record player stats.\n\n"
      "To record a new stat type 'record <name>'\n"
      "To list all stats currently being tracked type 'list stats'\n"
      "To view the totals accumlated for a stat type 'total <name>'\n"
      "To view the totals for all stats type 'total all'\n"
      "To view the last update of stat type 'view <name>'\n"
      "To view the entire record of a stat type 'view <name>'\n"
      "To auto record a stat type 'autorecord <name>'\n"
      "To auto record all stats currently on file type 'autorecord all'\n"
      "To set how often (in HBs) to auto record "
      "(default = 50) type 'howoften <how often>'\n"
      "To list stats currently being auto recorded type 'list "
      "autorecord'\n"
      "To stop autorecording a stat type 'reset <name>'\n"
      "To turn off all autorecording type 'reset autorecord'\n"
      "To get user info type 'getinfo users|autorecording'\n"
    );
    set_heart_beat(1);
    call_out("set_owner", 3);
    reset_drop();
}

void set_owner() {
    owner = environment(this_object());
}

object query_owner() {
    return owner;
}

void record_stat(string name) {
    int i, stat_total, stat_average;
    object *all, *all_players, me;
    mixed thane, mudlibber, lord, god;
    mixed overall_players, overall_total, overall_average;

    if(!name) {
	notify_fail("Stat Book usage for record: record <name>\n");
	return 0;
    }

    me = previous_object();
    thane = "/secure/thanes"->query_of(me->query_name());
    mudlibber = "/secure/mudlibber"->query_boo(me->query_name());
    lord = "/secure/lords"->query_boo(me->query_name());
    god = "/secure/gods"->query_boo(me->query_name());
    if(!thane && !mudlibber && !lord && !god && (me != this_object()) ) {
	notify_fail("You need to at least be a thane to record.\n");
	return 0;
    }
    all = users();
    stat_total = 0;
    all_players = ({ });

    for(i=0;i<sizeof(all);i++) {
	if(!function_exists("query_"+name, environment(this_object()))) {
	    notify_fail("That is not a valid category.  You must enter a "
	      "known player.c query.\nEx. To record total ac "
	      "type 'record total_ac'\n\n");
	    return 0;
	}
	if(!all[i]->query_creator())
	    all_players += ({ all[i] });
    }

    for(i=0;i<sizeof(all_players);i++) 
	stat_total += call_other(all_players[i], "query_"+name);
    stat_average = stat_total / sizeof(all_players);
    write_file(STATS+name, "Total number of players "
      "surveyed : "+sizeof(all_players)+"\nAverage : "+stat_average+"\n"
      "Date and time : "+ctime(time())+"\n", 0);

    if(file_size(STATS+name+"_total") == -1) 
	write_file(STATS+name+"_total",
	  sizeof(all_players)+"\n"+stat_total+"\n", 1);
    else {
	overall_players = read_file(STATS+name+"_total", 1, 1);
	overall_total = read_file(STATS+name+"_total", 2, 1);
	sscanf(overall_players, "%d", overall_players);
	sscanf(overall_total, "%d", overall_total);
	overall_players += sizeof(all_players);
	overall_total += stat_total;
	overall_average = overall_total / overall_players;
	write_file(STATS+name+"_total", 
	  overall_players+"\n"+overall_total+"\n"
	  ""+overall_average+"\n", 1);
    }

    if(me == this_object()) return 1;
    tell_object(this_player(), capitalize(name)+" recorded\n\n");
    this_object()->current_stat(name);
    return 1;
}

void stat_totals(string name) {
    int i;
    string overall_players, overall_average, 
    file, last_update, *files, *stat;

    if(!name) {
	notify_fail("Stat Book usage for totals: total <name>\n");
	return 0;
    }

    if(name == "all") {
	files = get_dir(STATS+"*total");
	printf("%-=*s %-=*s %-=*s", this_player()->query_cols()/3,
	  "Stat", this_player()->query_cols()/3, "Total Players",
	  this_player()->query_cols()/3, "Total Average");
	write("\n");
	for(i=0;i<sizeof(files);i++) {
	    overall_players = read_file(STATS+files[i], 1, 1);
	    overall_average = read_file(STATS+files[i], 3, 1);
	    stat = explode(files[i], "_");
	    stat -= ({ stat[sizeof(stat) - 1] });
	    file = implode(stat, "_");
	    printf("%-=*s %-=*s %-=*s", this_player()->query_cols()/3,
	      file, this_player()->query_cols()/3, overall_players,
	      this_player()->query_cols()/3, overall_average);
	}
	write("\n");
	return 1;
    }

    if(!file_size(STATS+name+"_total")) {
	notify_fail("No such stat on file: "+name+"\n");
	return 0;
    }

    overall_players = read_file(STATS+name+"_total", 1, 1);
    overall_average = read_file(STATS+name+"_total", 3, 1);
    last_update = read_file(STATS+name, file_length(STATS+name), 1);
    tell_object(this_player(), "Total Players Surveyed: "
      ""+overall_players+"\n"
      "Total Average for "+name+": "+overall_average+"\n"
      "Last Update, "+last_update+"\n");
    return 1;
}

void view_stat(string name) {

    if(!name) {
	notify_fail("Stat Book usage for view: view <name>\n");
	return 0;
    }

    if(file_size(STATS+name) == -1) {
	notify_fail("No such stat on file: "+name+"\n");
	return 0;
    }

    tell_object(this_player(), 
      read_file(STATS+name, 1, file_length(STATS+name)) );
    return 1;
}

void current_stat(string name) {

    if(!name) {
	notify_fail("Stat Book usage for current status: "
	  "current <name>\n");
	return 0;
    }

    if(file_size(STATS+name) == -1) {
	notify_fail("No such stat on file: "+name+"\n");
	return 0;
    }

    if(!this_player()) return 1;
    tell_object(this_player(), 
      read_file(STATS+name, (file_length(STATS+name) - 2), 3) );
    return 1;
}

void list_stats(string str) {
    string *files, output;

    if(!str || ((str != "stats") && (str != "autorecord"))) {
	notify_fail("Stat Book usage for list: "
	  "list stats|autorecord\n");
	return 0;
    }

    if(str == "stats") {
	files = get_dir(STATS);
	files -= get_dir(STATS+"*total");
	tell_object(this_player(), "List of Stats accumulated "
	  "thus far:\n\n");
	output = implode(files, "\n");
	printf("%-#*s", this_player()->query_cols(), output+"\n");
	return 1;
    }

    tell_object(this_player(), "Autorecording:\n\n");
    output = implode(autorecording, "\n");
    printf("%-#*s", this_player()->query_cols(), output+"\n");
    tell_object(this_player(), "\n\nevery "+reset_countdown+" HBs.\n");
    return 1;
}

void set_auto_record(string str) {
    int no_auto_record;
    object me;
    mixed thane, mudlibber, lord, god;

    me = this_player();
    thane = "/secure/thanes"->query_of(me->query_name());
    mudlibber = "/secure/mudlibber"->query_boo(me->query_name());
    lord = "/secure/lords"->query_boo(me->query_name());
    god = "/secure/gods"->query_boo(me->query_name());
    if(!thane && !mudlibber && !lord && !god) {
	notify_fail("You need to at least be a thane to "
	  "autorecord.\n");
	return 0;
    }

    if(!str) {
	notify_fail("Stat Book usage for auto record: "
	  "autorecord <name>|all\n");
	return 0;
    }

    if(str == "all") {
	no_auto_record = this_object()->get_user_info("check");
	if(no_auto_record) {
	    notify_fail("Someone is currently autorecording therefore "
	      "you may not.  Type 'getinfo autorecording' to find out "
	      "more details.\n");
	    return 0;
	}
	auto_record = 0;
	autorecording = ({ });
	autorecording = get_dir(STATS);
	autorecording -= get_dir(STATS+"*total");
	auto_record = 1;
	this_object()->add_static_property("autorecording", 1);
	this_object()->list_stats("autorecord");
	return 1;
    }

    auto_stat = str;
    if(file_size(STATS+auto_stat) == -1) {
	notify_fail("No such stat on file: "+auto_stat+"\n");
	return 0;
    }

    if(member_array(auto_stat, autorecording) != -1) {
	notify_fail(capitalize(auto_stat)+" is already being recorded.\n");
	return 0;
    }

    auto_record = 0;
    autorecording += ({ auto_stat });
    auto_record = 1;
    tell_object(this_player(), "Auto record set to record "
      ""+auto_stat+" every "+reset_countdown+" HBs\n");
    return 1;
}

void reset_auto_record(string str) {
    if(!str) {
	notify_fail("Stat Book usage for turning auto record : "
	  "off: reset <name>|autorecord\n");
	return 0;
    }

    if(str == "autorecord") {
	auto_record = 0;
	autorecording = ({ });
	this_object()->remove_property("autorecording");
	tell_object(this_player(), "All auto recording turned off.\n");
	return 1;
    }

    auto_stat = str;
    if(file_size(STATS+auto_stat) == -1) {
	notify_fail("No such stat on file: "+auto_stat+"\n");
	return 0;
    }

    if(member_array(auto_stat, autorecording) == -1) {
	notify_fail("Not currently auto recording "+auto_stat+"\n");
	return 0;
    }

    autorecording -= ({ auto_stat });
    tell_object(this_player(), "Auto recording of "+auto_stat+" "
      "turned off.\n");
    return 1;
}

void set_countdown(string str) {
    int check, param;

    check = sscanf(str, "%d", param);
    if(check != 1) {
	notify_fail("Stat Book usage for setting auto record "
	  "time: howoften <howoften>\n");
	return 0;
    }

    reset_countdown = param;
    if(reset_countdown < 50) {
	notify_fail("The minimum allowable value for how often "
	  "you wish to record a stat is 50 HBs.\n");
	return 0;
    }

    countdown = param;
    tell_object(this_player(), "Autorecording set to "+param+" HBs.\n");
    return 1;
}

void heart_beat() {
    int i;

    if(!auto_record) return 1;
    switch(countdown--) {
    case -1:
	for(i=0;i<sizeof(autorecording);i++) 
	    this_object()->record_stat(autorecording[i]);
	countdown = reset_countdown;
	break;
    }
}

void get_user_info(string str) {
    int i;
    string *user_names, names;
    object *all_obs, *all_users, ob_owner;

    if(!str || ((str != "users") && (str != "autorecording") &&
	(str != "check"))) {
	notify_fail("Stat Book usage for getting user info : "
	  "getinfo users|autorecording\n");
	return 0;
    }

    all_obs = children(THISOB);
    all_users = ({ });
    user_names = ({ });
    for(i=0;i<sizeof(all_obs);i++)
	if(environment(all_obs[i]))
	    all_users += ({ all_obs[i]->query_owner() });

    if(str == "users") {
	for(i=0;i<sizeof(all_users);i++)
	    user_names += ({ all_users[i]->query_cap_name() });
	tell_object(this_player(), "Current Users of Stat Book\n\n");
	names = implode(user_names, "\n");
	printf("%-#*s", this_player()->query_cols(), names+"\n");
	write("\n");
	return 1;
    }

    if(str == "check") {
	for(i=0;i<sizeof(all_obs);i++) {
	    if(all_obs[i]->query_static_property("autorecording") == 1)
		return 1;
	    else return 0;
	}
    }

    for(i=0;i<sizeof(all_users);i++) {
	ob_owner = all_obs[i]->query_owner();
	tell_object(this_player(), ob_owner->query_cap_name()+" is ");
	all_obs[i]->list_stats("autorecord");
    }
    return 1;
}

void init() {
    ::init();
    add_action("record_stat", "record");
    add_action("stat_totals", "total");
    add_action("view_stat", "view");
    add_action("current_stat", "current");
    add_action("list_stats", "list");
    add_action("set_auto_record", "autorecord");
    add_action("reset_auto_record", "reset");
    add_action("set_countdown", "howoften");
    add_action("get_user_info", "getinfo");
}
