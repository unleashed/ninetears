/* Player.c once upon a time DW's.
 * messed with by a lot of people.
 *  > Mostly Timion <
 * Oct '95: Baldrick added the external command handler by Chrisy and
 * removed a lot from this file.
 */
#include "library.h"
#include "tune.h"
#include "login_handler.h"
#include "drinks.h"
#include "weather.h"
#include "log.h"
#include "cmd.h"
#include "commands.h"
#include "timestuff.h" // Anirudh

inherit "/global/line_ed";
inherit "/global/auto_load";
inherit "/global/events";
inherit "/global/log";
inherit "/global/spells";
inherit "/global/help";
inherit "/global/more_string";
inherit "/global/finger";
inherit "/global/pweath";
inherit "/std/living/living";
inherit "/std/living/handle";
inherit "/global/psoul";
inherit "/global/guild-race";
inherit "/global/drunk";
// Externalized - Radix
//inherit "/global/last";
inherit "/global/more_file";
inherit "/global/path";
inherit "/global/consent";   // Added by Wonderflug, august 95.
inherit "/global/henchmen";  // Raskolnikov (for Radix) Oct 96

#include "money.h"
#include "post.h"
#include "mail.h"
#include "player.h"

// Taniwha 14/09/1995 how long shall we disable guild commands and spells after login
#define LOGINLOCK 20
#define START_POS "/d/ss/daggerford/ladyluck"
#define STD_RACE "/std/races/human"
// OMIQ handler added by Timion to prevent Con Loss and Immort login.
#define OMIQ_HAND "/global/omiq"
#define FLAG_GAME "/d/omiq/flag/master_control"
#define IDENTD "/net/identd"

static int last_command, net_dead;
static int save_counter, hp_counter, combat_counter;
static int hidden;
int hb_counter;
string *auto_load, last_on_from, last_pos;
mixed *money_array;
string title, extra_title;
int headache, max_headache, time_on, monitor;
int invis, *saved_co_ords, ed_setup, start_time;
int creator, app_creator, last_log_on;
static object snoopee;
int registrated;
static int no_heal;  /* Hamlet */
string ident;  /* Hamlet */
static int ontime; /* Hamlet */
string *henchmen_load; //Raskolnikov

void set_creator(int i);
void start_player();
void run_away();
void set_title(string str);
void public_commands();
int save_me();
int save();
void set_desc(string str);
string query_title();
int query_creator();
static void set_name(string str);
int check_dark(int light);
int adjust_level(int i);
int query_level();
int really_quit();
int set_invis(int i);
static string *attackers,*attacked;
// Taniwha 1997 userp() *spits*
int query_player() { return 1;}

int test_add(object ob,int flag)
{
    string prop;
    if( !::test_add(ob,flag)) return 0;
    if(this_object()->query_creator()) return 1;
    // Please forgive this next one....
    if( explode(file_name(ob),"/")[1] == "grimbrand") return 1;
    if( explode(file_name(ob),"/")[0] == "w") return 0;
    if(ob->query_spell()) return 1; // so spell effect items will still work. 
    if(sizeof(deep_inventory(TO)) + sizeof(deep_inventory(ob)) > 50)
    {
	tell_object(this_object(),"You are carrying too much and overbalance.\n");
	return 0;
    }
    if(query_property("NOMULTI")) // "bad site" check
    {
	prop = ob->query_property("NOMULTI");
	if(stringp(prop) && prop != query_name())
	    return 0;
	ob->add_static_property("NOMULTI",query_name());
    }
    return 1;
}

// Taniwha 1997.
// Nasty code to take care of multiplayers
void attack()
{
    int i;
    object ob,*olist;
    string ip;
    ::attack();
    ip = query_property("NOMULTI");
    if(!stringp(ip)) return;
    if(this_object()->query_dead()) return;
    if(TO->query_property("pacified") || TO->query_level() < 5) return;
    if(!ETO->query_property("nocast"))
    {
	olist = all_inventory(ETO);
	for(i = 0; i < sizeof(olist); i++)
	{
	    ob = olist[i];
	    if(ob && ob->query_property("NOMULTI") == ip)
	    {
		if(ob->query_property("pacified")) continue;
                if(ob->query_dead()) continue;
		attack_ob(ob);
	    }
	}
    }
}
void attack_ob(object ob)
{
    // added the if's.. Baldrick.

    /*
	if (!attacked)
	  attacked=({ });
    */
    if(ob && interactive(ob) && member_array((string)ob->query_name(),attackers) == -1)
    {
	if(!pointerp(attacked)) attacked = ({ });
	attacked += ({ (string)ob->query_name() });
    }
    ::attack_ob(ob);
}

void attack_by(object ob)
{
    /*
	if (!attackers)
	  attackers=({ });
    */
    if(ob && interactive(ob) && member_array((string)ob->query_name(),attacked) == -1)
    {
	if(!pointerp(attackers)) attackers = ({ });
	attackers += ({ (string)ob->query_name() });
    }
    ::attack_by(ob);
}

string * query_player_attackers() { return attackers; }
string * query_players_attacked() { return attacked; }
void create() 
{
    int *i,j,k;

    if (name)
    {
	event (children("/global/lord"), "inform", this_player()->query_name()+
	  " called create() on "+name, "person_cheat");
	return ;
    }
    level = 0;
    living::create();
    events::create();
    pweath::create();
    psoul::create();
    line_ed::create();
    consent::create();   // Added by Wonderflug, august 95
    henchmen::create(); //Raskolnikov
    add_property("determinate", "");
    spells::create();
    money_array = ({ });
    time_on = time();
    start_time = time();
    seteuid("PLAYER");
    registrated = 0;
    attackers = ({ });
    attacked = ({ });

    Str = 13;
    Dex = 10;
    Int = 11;
    Con = 11;
    Wis = 10;
    Cha = 10; 

    set_thac0(200);
    max_social_points = 10;
    desc = 0;
    add_property("player", 1);
    cols = 79;
    rows = 24;
    verbose = 1;
    last_log_on = time();
    ontime = time();
    save_counter = 0;
    hp_counter = 0;
    race_ob = RACE_STD;
    sscanf(file_name(this_object()), "%s#", my_file_name);
    if(OMIQ_HAND->flag_in_progress())
	call_out("give_me_armband",5);
} /* create() */

int query_x_time_on() { return time_on; }
/* Naah, I don't like it.. Baldrick.
void set_x_time_on(int i) { time_on = i; }
*/

/* 3rd arg isn't actually used here.  only in creator.c */
void move_player_to_start(string bong, int newp, int going_invis) {
    int tmp;
    object money;
    mapping mail_stat;
    string s;
    if (file_name(previous_object())[0..13] != "/secure/login#") {
	notify_fail("You dont have the security clearance to do that.\n");
	return ;
    }
    /* some stupid test to make sure that the previous object is /secure/login. */
    seteuid("Root");
    set_name(bong);
    //  if (query_property("guest"))

    log_file("ENTER", sprintf("Enter : %15-s %s (guest)[%d] [%s]\n",
	name, ctime(time()), time(),
	(query_ip_name()?query_ip_name():query_ip_number())));
    /*
      else
	log_file("ENTER", sprintf("Enter : %15-s %s[%d]\n",
		   name, ctime(time()), time()));
    */
    if(OMIQ_HAND->flag_in_progress() && 
       (file_size("/save/playertmp/"+name+".o") > 0)) {
      tell_object(this_object(), "Restoring your flag game temporary" 
                                 "character...\n");
      restore_object("/save/playertmp/"+name,1);
    }
    else
      restore_object("/players/"+name[0..0]+"/"+name,1);

    /* Hamlet added this.  For logging on invis */
    if(going_invis != -1)
	set_invis(going_invis);

    // Aragorn fix
    colour_map = 0;
    set_short(capitalize(name));
    if (!cols) cols = 79;
    add_property("determinate", "");
    if (this_player()->query_creator())
	seteuid(name);
    else
	seteuid("PLAYER");
    write("You last logged in from "+last_on_from+".\n");
    last_on_from = query_ip_name(this_object())+" ("+
    query_ip_number(this_object())+")";
    // Taniwha 1996, unused
    //bonus_cache = ([ ]);
    //level_cache = ([ ]);
    if (time_on < -500*24*60*60)
	time_on += time();
    if (time_on > 0)
	time_on = 0;
    time_on += time();
    guild_joined += time();
    start_player();
    if(!msgin || msgin[0] != '@')
	msgin = msgout = mmsgin = mmsgout = 0;
    if(!msgin)
	msgin = "@$N arrives from $F.";
    if(!msgout)
	msgout = "@$N leaves $T.";
    if(!mmsgin)
	mmsgin = "@$N appears out of the ground.";
    if(!mmsgout)
	mmsgout = "@$N vanishes in a puff of smoke.";
    cat("doc/NEWS"); 
    if(file_size("/doc/NEWS.OMIQ") > 0)
	cat("/doc/NEWS.OMIQ");

    "/global/do_chat"->init_player_channels(query_property("channels"));

    if (!last_pos || (my_file_name == "/global/player" && last_pos[0..1] == "/w")
      || catch(call_other(last_pos, "??")))
    {
	last_pos = "/room/raceroom";
	move(last_pos);
    }
    else
    {
	move(last_pos);
	/*
	 * Set the old co ord if one does not already exist.  Otherwise don't
	 * destroy the already existing nameing scheme.
	 */
	if (!last_pos->query_co_ord() && saved_co_ords)
	    last_pos->set_co_ord(saved_co_ords);
    }
    event(users(), "inform", query_cap_name() +
     " enters " + (query_property("guest")?"as a guest of ":"") + mud_name() +
         (newp ? " (%^BLUE%^BOLD%^New player%^RESET%^)":""),
      "logon");

    if(this_object()->query_creator())    
	event(users(), "inform", query_cap_name() +
	  " enters " + (query_property("guest")?"as a guest of ":"") + mud_name()+
	  (newp ? " (%^BLUE%^BOLD%^New player%^RESET%^)":""),
	  "immort_logon");

    if(this_object()->query_invis() < 2)
    {
// Unless you pass WHO logged on, this is useless
	event(environment(this_object()),"login",this_object());
	//event(environment(this_object()),"login");
	say(query_cap_name()+" enters the game.\n", 0);
    }
    if (verbose)
	command("look");
    else
	command("glance");
    last_pos->enter(this_object());
    if (query_property(PASSED_OUT_PROP))
	call_out("remove_property", 10+random(30), PASSED_OUT_PROP);
    curses_start();
    mail_stat = (mapping)POSTAL_D->mail_status(query_name());
    if(mail_stat["unread"]) {
	if(mail_stat["total"] == 1)
	    write("\n        >>> Your only mail is unread! <<<\n");
	else write("\n        >>> "+mail_stat["unread"]+" of your "+
	      mail_stat["total"]+" letters are unread. <<<\n");
    }
    if (query_dead()) {
	money = clone_object(DEATH_SHADOW);
	money->setup_shadow(this_object());
    }
    if(query_old_property("noregen"))
	DEATH_CHAR->person_died(query_name());
    exec_alias("login","");
    last_log_on = time();
    ontime = time();
    //online_time_exceeded();  /* This just resets stuff here */
    LOGIN_HANDLER->player_logon(bong);
    if (my_file_name != "/global/player")
	if (file_size("/w/"+name+"/"+PLAYER_ERROR_LOG) > 0)
	    write("You have ERRORS in /w/"+name+"/"+PLAYER_ERROR_LOG+"\n");

	/* ident stuff.  -- Hamlet */
    if(!catch(load_object("/net/identd")))
	IDENTD->do_ident(this_object(), this_object());
} /* move_player_to_start() */

void setup_money();

void start_player() {
    object money;
    int lockout;
    if (app_creator && my_file_name != "/global/player") {
	this_player()->all_commands();
	this_player()->app_commands();
    }
    if (creator && my_file_name != "/global/player") 
	this_player()->wiz_commands();
    reset_get();
    enable_commands();
    public_commands();
    parser_commands();
    handle_commands();
    force_commands();
    race_guild_commands();
    soul_commands();
    event_commands();
    finger_commands();
    communicate_commands();
    consent_commands();      // Added by Wonderflug, August 95.
    living_commands();
    spell_commands();
    logging_commands();
    weather_commands();
    editor_commands();
    set_living_name(name);
    set_no_check(1);
    set_con(Con);
    set_str(Str);
    set_int(Int);
    set_dex(Dex);
    set_wis(Wis);
    set_cha(Cha);
    reset_all();
    current_path = home_dir;
    //spells::init_spells();
    // call_out("setup_money",2);  This was needed for money, but it breaks stuff.
    setup_money();
    call_out("do_load_auto", 0);
    // Taniwha was here, 14/09/95
    add_timed_property("loading",1,50); // if they ain'
    // Helpless (relatively) for a while after you log in, you can run... but you can't hide.
    // Added to make it very undesirable to log out
    if( query_property("pacify_on") ) lockout = LOGINLOCK * 10;
    else lockout = LOGINLOCK;
    add_timed_property("noguild",1,lockout);
    add_timed_property("nocast",1,lockout);
    birthday_gifts(); /* check if birthday today and give gifts */
    set_heart_beat(1);
    if (wimpy > 100)
	wimpy = 25;
} /* start_player() */

void setup_money()
{
    object money;
    // Done here after encumberance is set up
    money = clone_object(MONEY_OBJECT);
    money->set_money_array(money_array);
    money->move(this_object());

}

/* Ok.. the big question is: will the  reset() be called ?
 * Baldrick Feb '94
 * it does, but not in lord.c and those..
 */

void reset()
{
    if(save_counter > 0)
    {
	update_tmps();
	save();
    }
    else
	++save_counter;
} 


// Aragorn testing
void do_auto_equip() 
{
    if((string)this_object()->query_property("autoequip") == "yes")
	this_object()->do_equip();
}

int do_load_auto() { 
    load_auto_load(auto_load, this_object());
    set_henchmen(load_auto_load(henchmen_load,environment(this_object())));
    remove_timed_property("loading");
    call_out("do_auto_equip",3);
} /* do_load_auto() */

int is_player() {
    if (my_file_name == "/global/player") return 1;
    else return 0;
}

void public_commands() {
    add_action("do_clear_screen","clear");
    add_action("help_func","help");
    add_action("restart_heart_beat", "restart");
    // Externalized - Radix
    add_action("stop","stop");
    add_action("invent","inventory");
    add_action("invent","i");
    add_action("brief_verbose","brief");
    add_action("brief_verbose", "verbose");
    add_action("save","save");
    add_action("quit","quit");
    add_action("review", "review");
    add_action("examine","ex*amine");
    add_action("monitor", "mon*itor");
    add_action("do_refresh", "refresh");
    add_action("do_retire", "retire");
    /* Adding RD & Chrisy's command handler. Baldrick oct '95 */
    add_action("do_cmd", "*", A_P_CMD);
} /* public_commands() */

/* The do_cmd is a part of the external command handling system.
 * Made by Chrisy and gotten from RD. oct '95.
 */   
int do_cmd(string tail)
{
    string verb, t;

    sscanf(tail, "%s %s", verb, t);
    if(!verb)
	verb = tail;

    return (int)CMD_HANDLER->cmd(verb, t, this_object());
}/* do_cmd() */

int invent() 
{
    write(query_living_contents(1));
    return 1;
}

int glance(string arg)
{
    // Externalized - Radix
    if(!arg) return do_cmd("glance");
    return do_cmd("glance " +arg);
}

int look_me(string arg)
{
    // Externalized - Radix
    if(!arg) return do_cmd("look");
    return do_cmd("look " +arg);
}

int setmin(string str) 
{
    msgin = str;
    return 1;
}

int setmout(string str)
{
    msgout = str;
    return 1;
}

int setmmin(string str)
{
    mmsgin = str;
    return 1;
}

int setmmout(string str)
{
    mmsgout = str;
    return 1;
}

int review() {
    write("Entry  : " + extract(msgin, 1) + "\n");
    write("Exit   : " + extract(msgout, 1) + "\n");
    write("MEntry : " + extract(mmsgin, 1) + "\n");
    write("MExit  : " + extract(mmsgout, 1) + "\n");
    write("Editor : " + editor + "\n");
    return 1;
}

int examine(string arg) {
    return look_me("at "+arg);
}

string short(int dark) {
    string str;

    if (!interactive(this_object()))
    {
	str = "The net dead statue of ";
	// Added by Radix .. they still have to go thru really_quit()
	call_out("quit",0);
    }
    else
	str = "";
    return str+::short(dark);
}

/* This is my way to get rid of the stupid set_level thingie.. 
 * Baldrick. */
int adjust_level(int i)
{
    /* Added so that no players can go over a certain level without being
     * registrated. Baldrick may '95
     */
    if (level>=9 && !registrated)
	return 0;
    /* Those over lvl 100 is either immortals or cheat.. 
     * Noone needa it anyway.
     * Baldrick.
     */
    if ((level + i) > 100) {
	notify_fail("Forget it.\n");
	return 0;
    }

    if (guild_ob)
	guild_ob->new_levels(i, this_object());
    // Not sure if I need to call anything at all in the race object..
    //race_ob->new_levels;
    // This calls a recalc function in stats.c 
    level += i;
    this_object()->recalc_stats(i);
}


int brief_verbose(string str) {
    if (str == "on")
	verbose = (query_verb() == "verbose");
    else if (str == "off")
	verbose = (query_verb() == "brief");
    else if (str) {
	notify_fail("Usage: "+query_verb()+" <on/off>\n");
	return 0;
    } else
	verbose = !verbose;

    if (verbose)
	write ("You are in verbose mode.\n");
    else
	write("You are in brief mode.\n");
    return 1;
}

int query_verbose()
{
    return verbose;
}

nomask int save() 
{
    if (my_file_name == "/global/player" || query_verb() == "save")
	tell_object(this_object(), "Saving...\n");
    save_me();
    return 1; 
}

/** Henchmen stuff, Raskolnikov for Radix **/
void henchmen_owner_leave()
{
    int i;
    object *mons = this_object()->query_henchmen();

    mons -= ({ 0 });

    for(i=0;i<sizeof(mons);i++)
	catch(mons[i]->owner_left());

    return;
}

void henchmen_save()
{
    int i;
    object *obs = this_object()->query_henchmen();

    obs -= ({ 0 });

    for(i=0;i<sizeof(obs);i++)
	catch(obs[i]->save_my_data());
    henchmen_load = create_auto_load(obs);

    return;
}
int save_me() 
{
    object ob;
    mixed old;

    if (query_loading() || query_property("loading"))
    {
	return;
    }

    if (query_property("guest")) {
	write("But not saving for guests... sorry.\n");
	return ;
    }

    // Fix by Wonderflug.  Saving object is a bad idea.
    if ( name == "object" )
	return ;
    if ((ob = present("Some Money For Me", this_object())))
	money_array = (mixed *)ob->query_money_array();
    else
	money_array = ({ });
    if( guild_ob && ( (file_size(guild_ob) > 0) || 
	(file_size(guild_ob+".c") > 0) ) )
	guild_ob->player_save();
    if (race_ob)
	race_ob->player_save();
    old = geteuid();
    if (environment())
	last_pos = file_name(environment());
    else
	last_pos = "/room/raceroom";
    auto_load = create_auto_load(all_inventory());
    henchmen_save();
    saved_co_ords = (int *)last_pos->query_co_ord();
    time_on -= time();
    guild_joined -= time();
    // ntime_last_saved -= time();
    seteuid("Root");
    if(OMIQ_HAND->flag_in_progress() &&
//          OMIQ_HAND->is_playing_flag(this_object())) {
            1) {
      tell_object(this_object(), "Saves during the flag game are" 
                                 "temporary...\n");
      catch(save_object("/save/playertmp/"+name,1));
    }
    else
      catch(save_object("/players/"+name[0..0]+"/"+name,1));
    seteuid(old);
    time_on += time();
    guild_joined += time();
    // ntime_last_saved += time();
    /* Time-limit check.  Hamlet */
    /*
    if(!query_static_property("QUITTING") && online_time_exceeded())
    {
      tell_object(this_object(),"Your time-limit has been exceeded.  "
		  "Quitting...\n");
      call_out("quit",10);
    }
    */
} /* save_me() */

int quit()
{
    int foo;
    if (query_loading() || query_property("loading"))
    {
	notify_fail("Still loading equipment, wait until it's finished.\n");
	return 0;
    } 
    tell_object(this_object(),"Quitting.\n");
    if (foo = this_object()->query_fighting())
    {
	tell_object(this_object(),"You are in a fight, this will take "
	  "some time.\n");
	save();
	call_out("really_quit", query_level()*foo);
    }
    else
	this_object()->really_quit();
    return 1;
} /* quit */

int really_quit()
{
    object *ob, money;
    object frog, frog2;
    int i;

    // Taniwha 30-01-96 see if Flugs fix works
    traverse_timed_properties();
    last_log_on = time();
    /* Hamlet added next line */
    this_object()->adjust_online_time(time() - ontime);

    /* This should send the time the player was on to an object which
       keeps track of total hours played (non-immortal)
       Anirudh - March 17, 1996 */
    if (!this_object()->query_creator())
	TIMEKEEPER->add_time(time() - ontime);

    log_file("ENTER", sprintf("Exit  : %15-s %s[%d]\n", name, 
	ctime(time())+ (query_property("guest")?"(guest)":""), time()));
    catch(editor_check_do_quit());
    //write("Thanks for playing see you next time.\n");
    tell_object(this_object(),"Thanks for playing, see you next time.\n");
    if(this_object()->query_invis() < 2)
	say(query_cap_name()+" left the game.\n");
    if(query_name() != "object")
    {
	event(users(), "inform", query_cap_name() + " left the MUD", "logon");
	if ( this_object()->query_creator() )
	    event(users(), "inform", query_cap_name() + 
	      " left the MUD", "immort_logon");
    }

    LOGIN_HANDLER->player_logout(query_name());
    if (race_ob)
	catch(race_ob->player_quit(this_object()));
    if (guild_ob)
	catch(guild_ob->player_quit(this_object()));
    curses_quit();
    add_static_property("QUITTING",1);
    save_me();
    saving_henchmen();
    henchmen_owner_leave();
    /* get rid of the money....
     * we dont want them taking it twice now do we?
     */
    if ((money = present("Some Money For Me", this_object())))
	money->dest_me();
    frog = first_inventory(this_object());
    while (frog) {
	frog2 = next_inventory(frog);
	if (frog->query_auto_load() ||
	  frog->query_static_auto_load())
	    frog->dest_me();
	frog = frog2;
    }
    transfer_all_to(environment());
    ob = all_inventory(this_object());
    for (i=0;i<sizeof(ob);i++)
	ob[i]->dest_me();
    dest_me();
    return 1;
} /* really quit() */

int query_drunk()
{
    if (query_volume(D_ALCOHOL)>200)
	return 1;
    return 0;
}

string query_title() { return title; }
void set_title(string str) { title = str; }

string query_extitle() { return extra_title; }
void set_extitle(string str) { extra_title = str; }

/* Add by Baldrick.
 * May '95
 */
int query_registrated() {return registrated;}

void set_registrated(int i)
{
    /*
      if (previous_object()->query_high_programmer())
	{
	registrated = i;
	}
       else
	{
	notify_fail("You'r not allowed.\n");
	return 0;
	}
    */
    registrated = i;
    return;
}

static void set_name(string str) {
    if (name && name != "object")
	return ;
    name = str;
    set_living_name(name);
    set_main_plural(name);
} /* set_name() */


// this used to all be in long(), moved here by Radix, MArch 1996
string query_description()
{
    string s = "You see "+this_object()->query_cap_name();
    if (this_object()->query_female())
	s += " the female ";
    else 
	s += " the male ";
    s += this_object()->query_race_name();

    if (extra_title)
	s += " ("+extra_title+"), \n";
    else
	s += ",\n";
    if((race_ob) && (!desc))
	s += (string)race_ob->query_desc(this_object());
    if (desc && desc != "")
	s += query_cap_name() + " " + desc+"\n";
    return s;
}

string long(string str, int dark) {
    string s;

    if (str == "soul") {
	return (string)"/obj/handlers/soul"->query_long();
    }
    if (str == "sun" || str == "moon" || str == "weather") {
	return weather_long(str);
    }
    if (this_player() != this_object())
	if(!this_player()->query_hidden())
	    tell_object(this_object(), this_player()->query_cap_name()+" looks at you.\n");

	//   if(this_object()->query_hidden()) 
	//       return("You do not think that the "+str+" is here.\n");
    if (this_object()->query_dead())
    {
	s = "You see a shadow of " + this_object()->query_cap_name() +
	"'s former self.\n";
	return s;
    }

    // Made this its own function... Radix, March 1996

    s = (string)this_object()->query_description();
    s += capitalize(query_pronoun())+" "+health_string()+".\n";
    s += calc_extra_look();
    s += weather_extra_look();
    s += query_living_contents(0);
    return s;
} /* long() */
/* second life routine... handles the player dieing. */

int second_life() 
{
    string str;
    int i, no_dec;
    object tmp;

    //make_corpse()->move(environment());
    str = query_cap_name() + " killed by ";
    if (!sizeof(attacker_list))
	str += this_player()->query_cap_name()+" (with a call)";
    else
	for (i=0;i<sizeof(attacker_list);i++)
	    if (attacker_list[i]) 
	    {
		str += attacker_list[i]->query_name()+"<"
		+geteuid(attacker_list[i])+">";
		attacker_list[i]->stop_fight(this_object());
		no_dec += interactive(attacker_list[i]);
	    }
    secure_log_file("DEATH", ctime(time())+": "+str + "\n");
    // log_file("DEATH2",str+" : "+sprintf("%O\n",previous_object(-1)));
    event(users(), "inform", str, "death");
    attacker_list = ({ });
    for (i=0;i<sizeof(call_outed);i++)
	call_outed[i]->stop_fight(this_object());
    call_outed = ({ });

    say(query_cap_name()+" dies(sigh).\n");
    save_me();
    DEATH_CHAR->person_died(query_name());
    hp = 0;
    gp = 0;
    total_xp -= xp;
    xp = 0;
    if (!no_dec) 
    {
	contmp = -2;
	strtmp = -2;
	dextmp  = -2;
	inttmp = -2;
	wistmp = -2;
    }
    tmp = clone_object(DEATH_SHADOW);
    tmp->setup_shadow(this_object());
    return 1;
} 

void remove_ghost() 
{
    // Neg. con isn't doing anything, maybe this will work- Radix
    if(this_object()->query_real_con() < 1) 
    {
	tell_object(this_object(),"Something is wrong... your "
	  "constitution is too low.\n");
	return;
    }
    this_object()->set_dead(0);
    this_object()->remove_property("OMIQ_KILLED");
    // disabled 28/09/95 Taniwha, too many bugs, we can do without the hassles for now.
    if(this_player() && this_player()->query_creator()) {
	log_file("RESURRECT",ctime(time())+": "+this_player()->query_cap_name()+
	  " resurrected "+this_object()->query_cap_name()+".\n");
    }
    else {
	if(!OMIQ_HAND->omiq_in_progress())
	    if(this_object()->query_level() > 9) this_object()->adjust_con(-1);
    }
    tell_object(this_object(), "You reappear in a more solid form.\n");
    say(query_cap_name() + " appears in more solid form.\n");
    this_object()->dest_death_shadow();
    if( hp <= 0) hp = 3;

    if(OMIQ_HAND->flag_in_progress())
	call_out("give_me_armband",2);
    // Taniwha, just to avoid a few problems with being raised and dying from HP later
    save();
}

/* Hamlet -- this is so noncombat rooms can keep players from healing */
void set_no_heal() { no_heal = 1; }
void set_heal() { no_heal = 0; }

int query_hb_counter()
{
    return hb_counter;
}

int query_hb_diff(int oldc)
{
    if(hb_counter > oldc) return hb_counter - oldc;
    else return oldc - hb_counter;
}


static int hb_num;

/*
 * the heart beat. bounce what does this do? we arent going to tell you
 */

void heal_hp(int i)
{
    if(i && query_hp() < query_max_hp() && query_hp() >= 0 && !no_heal)
	hp++;
    return;
}
void heal_gp(int i, int intox)
{
    if(i && intox < 200 && query_gp() < query_max_gp() && !no_heal)
	gp++;
    return;
}
void heart_beat() 
{
    int i, intox;

    flush_queue();
    intox = query_volume(D_ALCOHOL);
    hb_counter++;
    // Taniwha 1997, racial effects
    if(race_ob && !(hb_counter & 31) ) race_ob->race_heartbeat(TO);
// Quark, adding heart beat to curses.
    if(!(hb_counter & 31)) TO->curses_heart_beat();

    /* Added a combat_counter, so the combat aren't that quick. */
    if (drunk_heart_beat(intox) && time_left > 0 && combat_counter >= 2) 
    {
	attack();
	do_spell_effects(attackee);
	if (sizeof(attacker_list)) 
	    time_left -= (int)environment()->attack_speed();
	combat_counter = 0;
    } /* If drunk_heart... */
    combat_counter++;

    if (!interactive(this_object()) ) 
    {
	if (name == "guest" || name == "root") 
	{
	    say(query_cap_name()+" just vanished in a puff of logic.\n");
	    quit();
	} 
	else 
	if (!net_dead) 
	{
	    say(query_cap_name()+" goes white, looks very chalky and turns into a "+
	      "statue.\n");
	    event(users(), "inform", query_cap_name() + " has lost " +
	      query_possessive() + " link", "link-death");
	    save_me();
	    this_object()->quit();
	    /* 
	    for (i=0;i<sizeof(attacker_list);i++)
	      attacker_list[i]->stop_fight(this_object());
	    */
	    net_dead = 1;
	}
     /*  Idling out annoys me.  Removing it.   Benedick -- Feb. 4, 1998
    } else {
	net_dead = 0;
	if (query_idle(this_object()) > MAX_IDLE)
	    if(my_file_name != "/global/god" && my_file_name != "/global/demi" &&
	      my_file_name != "/global/lord" )
	    {
		say(query_cap_name()+" has been idle for too long, "+query_pronoun()+
		  " vanishes in a puff of boredom.\n");
		write("You idled out sorry.\n");
		quit();
		return ;
	    }
	    else
	    {
		if(this_object()->query_invis() < 2)
		    tell_object(this_object(),"You've idled too long, setting you"
		      " to invis 2.\n");
		this_object()->set_invis(2);

	    }
        End of Idle Code, I hope.  */
	last_command = time() - query_idle(this_object());
    }


if(hp_counter >= 4 && "/global/omiq.c"->omiq_in_progress())
{
	heal_hp(1);
	heal_gp(1, intox);
}
    /* I've made this to hopefully be easier to add to later 
       - Radix : Dec 29, 1996
       Drow and duergar on surface heal 1/2 as fast if light < 20 
       no heal if light > 20
	- Timion : November 08, 1997
	All players heal faster during Capture the Flag.
    */
    if(hp_counter >= 15)
    {
	if("/global/omiq.c"->flag_in_progress())
	{
	  heal_hp(5);
	  heal_gp(5, intox);
	  hp_counter = -15;
	}
	else
	if(query_race() != "drow" && query_race() != "duergar")
	{
	    heal_hp(1);
	    heal_gp(1, intox);
	    hp_counter = 0;
	}
	else
	{
	    if(!environment()->query_underground())
		//       if(member_array(domain_origin(ENV(TO)), ({"bf","newbie"})) <0)
	    {
		if(environment()->query_light() < 20)
		{   
		    heal_hp(1);
		    heal_gp(1, intox);
		    hp_counter = -15;
		}
		else 
		{
		    heal_hp(0);
		    heal_gp(0, intox);
		    hp_counter = -15;
		}
	    }
	    else
	    {
		heal_hp(1);
		heal_gp(1, intox);
		hp_counter = 0;
	    }
	}
    }
    hp_counter++;

    /* handle intoxication dispersion by our selves...
     * they just handle hp recival and sp recival...
     */
    if(headache)
	if (!--headache)
	{
	    tell_object(this_object(), "Your headache disapears.\n");
	    headache = 0;
	}

    if (intox) 
    {
	if (!(intox-1)) 
	{
	    headache = 15;
	    tell_object(this_object(),"You get a splitting headache, be happy.\n");
	    hp -= 2;
	    if (hp<1)
		hp = 1;
	}
    }
    if (++hb_num%8)  // How about half as fast?
    {
	social_points++;
	if(social_points > max_social_points)
	    social_points = max_social_points;

	if (hb_num > 500)
	{
	    if(max_social_points < 1000)
		max_social_points++;
	    hb_num = 0;
	}
    }
    if (sizeof(attacker_list) && wimpy && hp < max_hp*wimpy/100)
	run_away();
    update_volumes();
}  /* Void heart_beat */

int query_monitor() { return monitor; }

void display_monitor(int i)
{
    string COLOR = "%^RED%^";
    if(!monitor) return;
    if(i) COLOR = "%^GREEN%^";
    tell_object(this_object(),COLOR+sprintf("HP: %d GP: %d\n",hp,gp)+
      "%^RESET%^\n");
    return;
}

int monitor(string str) 
{
    if (!str)
	monitor = !monitor;
    else if (str == "on")
	monitor = 1;
    else if (str == "off")
	monitor = 0;
    else {
	notify_fail("Syntax: monitor <on/off>\n");
	return 0;
    }
    if (monitor)
	write("Your hit point monitor is on.\n");
    else
	write("Your hit point monitor is off.\n");
    return 1;
}

void run_away() 
{
    mixed *direcs;
    int i, bong;

    if ( this_object()->query_property(PASSED_OUT_PROP) )
    {
	tell_object(this_object(),"You're in no condition to run away, alas.\n");
	return ;
    }
    direcs = (mixed *)environment()->query_dest_dir();
    while (!bong && sizeof(direcs)) 
    {
	i = random(sizeof(direcs)/2)*2;
	bong = command(direcs[i]);
	if (!bong)
	    direcs = delete(direcs, i, 2);
	else
	    write("Your feet run away with you.\n");
    }
    if (!bong)
	write("You tried to run away, but no matter how much you scrabbled you "+
	  "couldn't find any exits.\n");
}

/* why have invis here ? have to find out  that Baldrick. */

int set_invis(int i) 
{
    if(!previous_object()->query_lord())
    {
	if(i)
	    invis = 1;
	else 
	    invis = 0;
    }
    else
	invis = i;
}

nomask int query_invis() { return invis; }

int help_func(string str) 
{
    string rest;
    mixed i;

    if (!str) return do_help(0);
    if (sscanf(str, "spell %s", rest) == 1) 
    {
	i = help_spell(rest);
	if (i) 
	{
	    write(i);
	    return 1;
	}
	notify_fail("No such spell as '"+rest+"'\n");
	return 0;
    }
    if (sscanf(str, "command %s", rest) == 1) 
    {
	i = help_command(rest);
	if (i) 
	{
	    write(i);
	    return 1;
	}
	notify_fail("No such command as '"+rest+"'\n");
	return 0;
    }
    i = do_help(str); /* calling /global/help.c */
    if (!i)
	if ((i = help_spell(str)))
	    write(i);
    if (!i)
	if ((i = help_command(str)))
	    write(i);
    if(str == "guild" && query_guild_ob() )
	write(query_guild_ob()->help());
    return i;
}

int query_wizard() { return creator; } /* need this for the gamed driver */
int query_app_creator() { return app_creator; }

int stop(string str)
{
    write("Stopping fights, takes some time.\n");
    call_out("really_stop", 50, str);
} /* stop */

int really_stop(string str) 
{
    int i;
    object *obs;

    if (!str) 
    {
	obs = attacker_list + call_outed;
	if (!sizeof(obs)) 
	{
	    notify_fail("Not fighting anyone.\n");
	    return 0;
	}
	for (i=0;i<sizeof(obs);i++)
	    stop_fight(obs[i]);
	write("Stopped fighting "+query_multiple_short(obs)+".\n");
	return 1;
    }

    obs = find_match(str, environment());
    if (find_living(str))
	obs += ({ find_living(str) });

    if (!sizeof(obs)) 
    {
	notify_fail("Cannot find "+str+"\n");
	return 0;
    }
    for (i=0;i<sizeof(obs);i++)
	stop_fight(obs[i]);
    write("Ok, stopped hunting "+str+"\n");
    return 1;
}

int query_time_on() { return time_on - time(); }
/* why have a guild joined time ? Baldrick */
int query_last_joined_guild() { return guild_joined - time(); }

int check_dark(int light) 
{
    int i;

    if(this_object()->query_dead())
	return 0;
    if (race_ob)
	return (int)race_ob->query_dark(light);
    return 0;
}

int query_level() { return level; }

int restart_heart_beat() 
{
    if (query_heart_beat(this_object()))
    {
	/* This should be removed at the end of april '96.. 
	 * The gp thingie that is. 
	 * Baldrick, march '96.
	 */
	write("Naah, you don't need it.\n");
	adjust_gp(-(level / 2));
	return 1;
    }
// Taniwha, avoids the lockup case. HB restarts, buggy spell/command kills it again
   catch(this_object()->flush_spell_effects());
    set_heart_beat(1);
    write("Ok, heart_beat restarted.\n");
    return 1;
}

void set_snoopee(object ob) { snoopee = ob; }
object query_snoopee() { return snoopee; }

void set_creator(int i) 
{
    /* who the hell is putting coment on this ???
       Next time I'll dest the sucker for good when I find out.. 
       Baldrick..*/
    if (file_name(previous_object()) != "/secure/master") 
    {
	write("Illegal attempt to set creator!\n");
	log_file("ILLEGAL", this_player(1)->query_name()+" Illegal attempt to "+ 
	  "set_creator at "+ctime(time())+" from "+
	  file_name(previous_object())+"\n");
	return 0;
    }
    write("You are now a creator.\n");
    creator = i;
    app_creator = i;
    home_dir = "/w/"+name;
    save_me();
}

int query_prevent_shadow(object ob) {
    if (function_exists("query_prevent_shadow", ob) ||
      function_exists("query_name", ob) ||
      function_exists("query_creator", ob) ||
      function_exists("query_app_creator", ob) ||
      function_exists("query_hidden", ob) ||
      function_exists("dest_me", ob) ||
      function_exists("save_me",ob))
	return 1;
    return 0;
}

/* Including new hack for parse_command ;) */
move(object dest, string msgin, string msgout) {
    int i;
    object env;

    if ((env = environment()))
	WEATHER->unnotify_me(environment());
    i = ::move(dest, msgin, msgout);
    if (environment())
	WEATHER->notify_me(environment());
    if (!i)
	me_moveing(env);
    return i;
}

static int do_refresh(string str) 
{
    if(!this_object()->query_creator())
    {
	write("For various reasons, refresh has been removed.\n"
	  "Please use the retire command, \"help retire\" for more "
	  "info.\n");
	return 1;
    }
    if (!str || str != "me") {
	notify_fail("Please read the docs before using this command.\n");
	return 0;
    }
    write("WARNING!  Make sure you have read the docs before doing this!\n\n"+
      "Are you sure you wish to refresh yourself? ");
    input_to("refresh2");
    return 1;
}

static int refresh2(string str) {
    str = lower_case(str);
    if (str[0] != 'n' && str[0] != 'y') {
	write("Pardon?  I do not understand.  Do you want to refresh yourself? ");
	input_to("refresh2");
	return 1;
    }
    if (str[0] == 'n') {
	write("Ok, not refreshing.\n");
	return 1;
    }
    write("Doing refresh.\n");
    if (query_dead())
    {
	//remove_property("dead");
	set_dead(0);
	this_object()->dest_death_shadow();
    }
    /* Removing the guildchannel */
    if(guild_ob) // Taniwha 1995
	remove_property("chan_" + guild_ob->query_name());
    level = 0;
    Str = 10;
    Con = 10;
    Int = 10;
    Wis = 10;
    Dex = 10;
    Cha = 10;
    set_max_hp(3); // Taniwha, give them a break :), random(3) includes 0
    set_max_gp(1);
    inttmp = dextmp = wistmp = strtmp = contmp = 0;
    guild_ob = 0;
    group_ob = 0;
    race_group_ob = 0;
    map_prop = ([ ]);
    timed_prop = ([ ]);
    add_property("determinate","");
    // Taniwha 1996 skills level_cache bonus_cache commented out as skills not used NOW
    //skills = ({ });
    spells = ([ ]);
    /* No skills in this version..
    known_commands = ({sklls", "consider", "bury", }); 
    */
    known_commands = ({ "consider", "bury", "rearrange"}); 
    languages = ({ "common", this_object()->query_race() });
    minor_spheres = ({ });
    major_spheres = ({ });
    neutral_spheres = ({ });
    guild_ob = 0;
    xp = 0;
    //level_cache = ([ ]);
    //bonus_cache = ([ ]);
    gr_commands = ([ ]);
    race_guild_commands();
    this_object()->add_known_command("rearrange");
    // Hmmm, maybe not use a catch.. 
    //"/obj/handlers/bank_handler"->refresh_account(this_object()->query_name());
    "/obj/handlers/god_handler"->remove_sacrifices(this_object());
    this_object()->clear_deity();
    set_thac0(200);
    move("/room/raceroom");
    command("look");
    set_extreme_str(0); // Taniwha, this slipped though, Nov 1995
    write("Done.\n");
    reset_all();
    // reset_bon_stats();    Don't wanna do this.
    say(query_cap_name()+" refreshes "+query_objective()+"self.\n");
    return 1;
}

/* for creators who are playing as players */
int query_creator_playing() { return creator; }

int query_max_languages() 
{
    return (query_int()/3);
}

int teach_language(object *obs, string str)
{
    int nb, i;
    object *taught;

    taught = ({ });
    if(member_array(str, query_languages()) == -1)
	return 0;
    nb = sizeof(obs);
    if(!nb)
	return 1;
    for(i=0;i<nb;++i)
    {
	if(!living(obs[i]))
	    continue;
	if(member_array(str, (string *)obs[i]->query_languages()) != -1)
	{
	    write(obs[i]->query_cap_name()+" knows "+str+" already.\n");
	    continue;
	}
	if(obs[i]->query_max_languages()<=
	  sizeof((string *)obs[i]->query_languages()))
	{
	    write(obs[i]->query_cap_name()+" can't learn more languages.\n");
	    tell_object(obs[i], query_short()+" tries to teach you '"+str+"', "+
	      "but you aren't intelligent enough to learn another language.\n");
	    continue;
	}
	taught += ({ obs[i] });
    }
    nb = sizeof(taught);
    if(!nb) 
	return 1;
    for(i=0;i<nb;i++) 
    { 
	taught[i]->add_language(str);
	write("You teach "+taught[i]->query_short()+" '"+str+"'.\n");
    }
    return 1;
} /* teach_language */

string query_object_type()
{
    if (creator)
	return "A"; 
    return " ";
} /* query_object_type() */

static int do_clear_screen() {
    if( this_player(1) != this_player() )  return 0;
    tell_object(this_object(),sprintf("%c[H%c[2J",27,27));
    return 1;
}

int query_statue() { return !interactive(this_object()); }


/* Add of Retire.
 * Baldrick, march '94
 */
int do_retire() 
{
    "/obj/handlers/god_handler"->remove_high_priest(this_object()->query_name(),this_object()->query_deity());
    // should probably do a more secure check, but the retire has a password.
    "/secure/master"->try_retire();
    return 1;
} /* void do_retire */

// Coded the 5th of may 1994 by Begosh@RotD
// Receiver for the chat

void receive_message( string str, string mclass)
{
    strlen(mclass) ?
    receive("\n"+this_object()->fix_string(mclass + str + "\n",strlen(mclass))):
    receive("\n"+TO->fix_string(str+"\n"));
    /*
	strlen( mclass ) ? receive( sprintf("%s%*=-s\n", mclass,
	    cols-strlen(mclass), str) ) : receive( str );
    */
} /* recieve_message */


/* This is an attempt to make it illegal to set_short on playerobjects.
 * Baldrick, aug '94
 */

void set_short(string moo)
{
    if (living(previous_object()))
    {
	tell_object(previous_object(), "Boo! Not legal anymore.\n");
	return;
    }
    ::set_short(moo);
}

/* Starting to implement hiding in a better fashion than the hack the hide
 * has been until now.
 * Baldrick, aug '95
 */
void set_hidden(int i)
{
    hidden = i;
}

int query_hidden()
{
    // return hidden;
    // until the above works...
    if(this_object()->query_invis()||this_object()->query_hide_shadow())
	return 1;
    return 0;
}

/* void idle_out. Used by /obj/handlers/timed. 
 * instead of idleroutines in heart_beat.
 * Gotten from RD.
 * Not too sure it's better... but we'll try it.
 * baldrick, oct '95
 */
void idle_out() 
{
    if ((time() - last_command < MAX_IDLE) ||
      (my_file_name == "/global/god" || my_file_name == "/global/demi" ||
	my_file_name == "/global/lord"
	|| sizeof(users()) < 3) && interactive(this_object())) 
    {
	return ;
    }
    tell_room(environment(this_object()), capitalize(name) +
      " has been idle for too long, " + this_object()->query_pronoun()+
      " vanishes in a puff of boredom.\n", ({this_object()}));
    tell_object(this_object(),"You idled out sorry.  Come back again!\n");
    /* chaned from really_quit() to quit() to see if the players will be able to
     * bomb out goine net dead.. 
     */
    quit();
} /* idle_out() */

/* Hamlet -- Flag game thing.  Nice and short.  Just calls handler */
void give_me_armband() {
    FLAG_GAME->assign_team(this_object());
}

/* Hamlet, Jan 1996.  The two hooks needed it internalize identd stuff */
void receive_ident_data(string id, string hosttype) {
    if(file_name(previous_object())[0..10] != "/net/identd")
	return;

    if( id != "!error!" )
	ident = id;
    else
	ident = 0;
    /* Some of the punt code will go here. */
}

string query_ident() {
    if(!"/secure/master"->query_lord(geteuid(previous_object())))
	return 0;
    return ident;
}

/* Hamlet, Feb 1996.  -- These two are needed for time_limit stuff */

nomask void set_ontime(int i)  {  ontime = i;  }
nomask int query_ontime() {  return ontime;  }
int query_prevent_reload_object() { return 1; }
