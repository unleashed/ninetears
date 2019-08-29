
/* Modified by Radix - 1996 for FRMud
 * race_ob - the players race
 * guild_ob - the players guild
 * group_ob - Special Interest Groups
 * race_group_ob - Race homeland gatherings, dwarf clans, orc tribes, ...
 */

#include "player.h"
#include "commands.h"

int guild_joined;
string race_ob, guild_ob,  *known_commands;
string group_ob, race_group_ob;
static mapping gr_commands;

void race_guild_commands() 
{
    int i;
    string *bing;
    mapping tmp;

    if (!known_commands)
	known_commands = ({ "consider", "bury", "rearrange", });
    if (!mappingp(gr_commands))
	gr_commands = (mapping)"/std/commands"->query_commands();
    add_action("list_commands", "co*mmands");

    if(guild_ob)
	catch(guild_ob->start_player(this_object()));
    if(race_ob)
	catch(race_ob->start_player(this_object()));
    if(group_ob)
	catch(group_ob->start_player(this_object()));
    if(race_group_ob)
	catch(race_group_ob->start_player(this_object()));

    gr_commands = ([ ]);
    for (i=0;i<sizeof(known_commands);i++) 
    {
	gr_commands[known_commands[i]] = 
	(string *)COMMAND_SERVER->query_command(known_commands[i]);
	if (!pointerp(gr_commands[known_commands[i]]))
	    continue;
	add_action("do_command", known_commands[i]);
    }
    add_action("add_new_command", "Add_New_Command");

} /* race_guild_commands() */

int do_command(string str)   
{
    int i;

    if(this_player()->query_dead() || this_player()->query_property("noguild") 
      || environment(this_player())->query_property("noguild") )
    {
	tell_object(this_player(),"You can't do that here and now.\n");
	return 1;
    }

    if (!pointerp(gr_commands[query_verb()]))
	return 0;

    /* Test.. Baldrick.*/
    if (!gr_commands[query_verb()][1])
	return 0;

    return (int)call_other(gr_commands[query_verb()][0],
      gr_commands[query_verb()][1], str);
} 

string query_gtitle()
{
    string str;

    if (guild_ob)
	if (catch((str = (string)guild_ob->query_title(this_object()))))
	    return "Has a broken guild";
	else
	    return str;
}

void set_race_ob(string str)  
{
    string frog;
    if(!str) str = "/std/races/unknown";
    if( sscanf(str, "/%s", frog)==1)
	str = extract(str, 1);
    if (str[0..strlen("std/races")-1]!="std/races") 
    {
	write("Illegal path to set_race_ob.\n");
	return;
    }
    if(str[0..strlen("std/races/god")-1] == "std/races/god" &&
      !"/secure/master"->high_programmer(geteuid())) {
	write("The heavens rumble and the realms shake. You stop.\n");
	return;
    }

    if( (file_size(str) < 1) && (file_size(str+".c") < 1) ) {
	tell_object(this_object(),"Attempt to set race didn't work.  Tell someone who "
	  "can fix it.\n"); 
	return;
    }
// Taniwha 1997, stop these accumulating on race change
   TO->adjust_bonus_str(-TO->query_bonus_str());
   TO->adjust_bonus_con(-TO->query_bonus_con());
   TO->adjust_bonus_dex(-TO->query_bonus_dex());
   TO->adjust_bonus_cha(-TO->query_bonus_cha());
   TO->adjust_bonus_wis(-TO->query_bonus_wis());
   TO->adjust_bonus_int(-TO->query_bonus_int());
    // Remove the old language if they have one. Flode - 150997
    if(race_ob)
      this_object()->remove_language(race_ob->query_name());
    race_ob = str;
    race_ob->start_player(this_object());
    race_ob->set_racial_bonuses();
    return;
} /* set_race_ob() */

void set_race(string str) {
    return set_race_ob("std/races/"+str);
}

string query_race_ob() { return race_ob; }

string query_race_name() { 
    if(race_ob)
	return ((string)race_ob->query_name()); 
    else
	return "No race.";
}

string query_race() { /* should return the name of our race */
    if(race_ob)
	return (string)race_ob->query_name();
    else
	return "No race.";
} /* query_race() */

void set_guild_ob(string str) {
    if(!stringp(str)) {
	guild_ob = 0;
	return;
    }
    if( (file_size(str) < 0) && (file_size(str+".c") < 0) )
	return; 

    guild_ob = str;
    this_object()->set_extreme_str(0);
    guild_joined = time();
    return;
} /* set_guild_ob() */

void set_guild(string str) {
    if(!set_guild_ob("/std/guilds/priests/"+str))
	if(!set_guild_ob("/std/guilds/other/shapeshift/"+str))
	    if(!set_guild_ob("/std/guilds/rogues/"+str))
		if(!set_guild_ob("/std/guilds/warriors/"+str))
		    if(!set_guild_ob("/std/guilds/wizards/"+str))
			if(!set_guild_ob("/std/guilds/multi/"+str))
			    if(!set_guild_ob("/std/guilds/"+str))
				return;
    return;
}

string query_guild_ob() { return guild_ob; }

string query_guild_name()
{
    if (guild_ob)
	return ((string)guild_ob->query_name());
    else
	return ("No guild.");
}

mapping query_gr_commands() { return gr_commands+([ ]); }

string help_command(string str) {
    if (!pointerp(gr_commands[str]))
	return 0;
    return (string)gr_commands[str][0]->help(str);
} /* help_command() */

int list_commands() {
    write("Your current commands are:\n"+sprintf("%-#*s\n",
	this_player()->query_cols(), implode(m_indices(gr_commands), "\n")));
    return 1;
} /* list_command() */

string *query_known_commands() { return known_commands+({ }); }

static int allowed_add;

int add_known_command(string str) {
    mixed tmp;

    if (member_array(str, known_commands) != -1)
	return 0;
    tmp = (mixed *)COMMAND_SERVER->query_command(str);
    if (!pointerp(tmp))
	return 0;
    known_commands += ({ str });
    gr_commands[str] = tmp;
    allowed_add = 1;
    this_object()->ignore_from_history("Add_New_Command "+str);
    command("Add_New_Command "+str);
    allowed_add = 0;
    return 1;
} /* add_known_command() */

int remove_known_command(string str) {
    int i;

    if ((i = member_array(str, known_commands)) == -1)
	return 0;
    known_commands = delete(known_commands, i, 1);
    gr_commands = m_delete(gr_commands, str);
    return 1;
} /* remove_known_command() */

int add_new_command(string str) {
    if (!allowed_add)
	return 0;
    add_action("do_command", str);
    return 1;
} /* add_new_command() */

// This is for groups such as Blades of Balance, Silver Fists, Hellfire Cult.
// These groups should be highly elite and interacial/interguild.  Should 
// have a special focus or meaning in their organization. - Radix 1996 
void set_group_ob(string str)
{
    string tmp;
    if(!stringp(str) || !str)
    {
	group_ob = 0;
	return;
    }
    if(sscanf(str,"/%s", tmp) == 1)
	str = extract(str,1);
    if(str[0..strlen("std/groups")-1]!="std/groups") 
    {
	write("Illegal path to set_group_ob.\n");
	return;
    }

    if(file_size(str+".c") < 1)
    {
	tell_object(this_object(),"Attempt to set group did not work.  Tell someone who "
	  "can fix it.\n");
	return;
    }
    group_ob = str;
    group_ob->start_player(this_object());
    return;
} /* set_group_ob() */

//string query_group_ob() { return group_ob; }
string query_group_ob()
{
    if(file_size("/"+group_ob+".c") < 1)
	group_ob = 0;
    return group_ob;
}

string query_group_name()
{
    if (group_ob)
	return ((string)group_ob->query_short());
    else
	return ("No group.");
}

// This is for Dwarf clans, Drow houses, Orc tribes...
// Radix 1996
void set_race_group_ob(string str)
{
    string tmp;
    if(!stringp(str) || !str)
    {
	race_group_ob = 0;
	return;
    }
    if(sscanf(str,"/%s", tmp) == 1)
	str = extract(str,1);
    if(str[0..strlen("std/race_groups")-1]!="std/race_groups") 
    {
	write("Illegal path to set_race_group_ob.\n");
	return;
    }

    if(file_size(str+".c") < 1)
    {
	tell_object(this_object(),"Attempt to set race group (clan) did not work.  Tell someone who "
	  "can fix it.\n");
	return;
    }
    race_group_ob = str;
    race_group_ob->start_player(this_object());
    return;
}

string query_race_group_ob() { return race_group_ob; }

string query_race_group_name()
{
    if (race_group_ob)
	return ((string)race_group_ob->query_short());
    else
	return ("No group.");
}

