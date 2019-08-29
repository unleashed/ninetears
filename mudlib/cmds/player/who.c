/* Who.c, once upon in /global/finger.c 
 * made splitted by Ducky, some changes by Baldrick and Aragorn.
 * Externalized by someone@RD.
 * Moved back to FR and Fr'ized by Baldrick. oct '95
 */

// Color added by Radix ... splish splash
// Damned Hide command, fixed for players and immortals, Radix 1996
/* For an overall ~12% increase, you get who sorted - Radix 1996
   - ie with 25 users, it's about 8k cpu cycles sorted, normally 7k
   Nevertheless, will improve greatly if sorted the FINAL string
   array, instead of doing the obs first
*/
// Added race option, and cleaned up the 'logon the unknown's - Radix
/* Added -c (Columns) option - Radix : 3/3/97
 * Oh, and CPU usage is *far* less using -c option (versus sorted above)
 */
// Expanded the races to incorporate all the new ones - Radix : Oct 7, 97

#include <runtime_config.h>
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

static string *races =
({ "drow","duergar","dwarf","elf","gnome","goblin","half-elf",
  "ilythiiri","duck","giant","kender","troll","frog","varniad",
  "half-orc","halfling","human","lizard-man","orc" });

void setup()
{
    position = 0;
}

string query_usage()
{
    return "command";
}

// Sorted and race functions - Radix 1996
int compare_obs(object ob1, object ob2)
{
    string s1 = ob1->query_name();
    string s2 = ob2->query_name();
    if(s1 == s2) return 0;
    if(s1 > s2) return 1;
    return -1;
}
int query_valid_race(string race)
{
    return member_array(race,races) != -1;
}
int compare_race(object ob, string str)
{
    return ob->query_race() == str;
}

string who_string(int width, int cre, string str, object me)
{
    object *arr;
    int i, c, p;
    int number, creators, what;
    int f = 0;  // formated?
    string s,  nam, imm,play,prt;
   mixed tmp;
    string ttl = "======]  %^GREEN%^" + mud_name() + "%^RESET%^  [======";

    // Radix...
    if(str && str[0] == '-')
    {
	if(str[1] == 'c')
	{
	    str = str[3..20];
	    if(str == "")
		str = 0;
	    f++;
	}
    }
    arr = users();
    if(str && query_valid_race(str))
    {
	arr = filter_array(arr,"compare_race",this_object(),str);
	str = "players";
    }
    if(str && str == "immortals"[0..sizeof(str)-1])
	arr = users();
    else
	arr = sort_array(arr,"compare_obs",this_object());
    s = "";
    c = p = 0;
    imm = play = "";
    prt = "\n";
    //prt += sprintf("%|*'-'s\n", width+18, ttl);
    prt += sprintf("%|*'-'s\n", width+4, ttl);
    prt +=  sprintf("%|*s\n", width, ctime(time()), width);
    for(i=0;i<sizeof(arr);i++)
    {
	if(arr[i]->query_short() == "logon") 
	    continue;
	if(arr[i]->query_creator())
	{
	    if(!(tmp = arr[i]->query_short()))
		continue;
	    if(arr[i]->query_invis() > 1) 
		if(!this_player()->query_lord()) 
		    continue;
	    if(cre && arr[i]->query_invis() == 1)
		tmp = "*"+arr[i]->query_short()+"*";
	    if(cre && arr[i]->query_invis() == 2)
		tmp = "**"+arr[i]->query_short()+"**";
	    if(!cre && arr[i]->query_invis() == 1) 
		continue;
	    c = 1;
	    s = "";
	    nam = tmp;
	    if(f != 1)
	    {
		if(cre && (tmp = arr[i]->query_in_editor()))
		{
     if(stringp(tmp))
		    s += "(Editing: "+(string)tmp+") ";
		}
		if(tmp = arr[i]->query_gtitle())
		    s += tmp;
		if(tmp = arr[i]->query_title())
		    s += ", "+tmp;
		if(tmp = arr[i]->query_extitle())
		    s += " ("+tmp+")";
		if(query_idle(arr[i]) > 120)
		    s += " (Idle: "+(query_idle(arr[i])/60)+")";
		imm += sprintf("%s %*-=s", nam, width-13, s)+"%^RESET%^\n";
	    }
	    else
	    {
		imm += sprintf("%s,", nam);
	    }
	    if(!arr[i]->query_invis() || cre)
	    {   
		creators++;
	    }
	}
	else 
	{
	    if(!(tmp = arr[i]->query_short()))
		continue;
	    p = 1;
	    if(f == 1 && tmp[0..8] == "Ghost of ")
		tmp = "Ghost "+tmp[9..25];
	    nam = tmp;
	    if(f != 1)
	    {
		s = "";
		if(arr[i]->query_property("guest"))
		    s += " guest of FR-MUD";
		if(arr[i]->query_female())
		    s += " the female ";
		else 
		    s += " the male ";
		if(tmp = arr[i]->query_race_name())
		    s += tmp;
		if(tmp = (string)arr[i]->query_extitle())
		    s += " ("+tmp+")";
		if(query_idle(arr[i]) > 120)
		    s += " (Idle: " + (query_idle(arr[i])/60) + ")";
		play += sprintf("       %*-=s", width-10, nam+s)+"%^RESET%^\n";
	    }
	    else
	    {
		play += sprintf("%s,", nam);
	    }
	    if(!arr[i]->query_invis())
		number++;
	}
    }
    if(!str)
	what = 0;
    else 
#ifndef STRICT_MUD
    if(str == "immortals"[0..sizeof(str)-1])
	what = 1;
    else 
    if(str == "players"[0..sizeof(str)-1])
	what = 2;
    else
	return "Usage: who [-c] [immortals | players | <race>]\n"
	"Example: who -c dwarf\n";
    if(what != 2)
    {
	if(!c && what == 1)
	    return "%^WHITE%^There are no immortals online.%^RESET%^\n";
	if(c)
	{
	    ttl = "] %^BOLD%^WHITE%^Immortals%^RESET%^ [";
	    //prt += sprintf("%*'-'|s\n",width+24, ttl);
	    prt += sprintf("%*'-'|s\n",width+2, ttl);
	    if(f == 1)
		prt += format_page(explode(imm, ","), 4);
	    else
		prt += imm;

	}
    }
#endif

    if(what != 1)
    {
	if(!p && what == 2)
	    return("There are no players online.\n");
	if(p)
	{
	    ttl = "]%^BOLD%^WHITE%^ Players%^RESET%^ [";
	    //prt += sprintf("%*'-'|s\n", width+24, ttl);
	    prt += sprintf("%*'-'|s\n", width+3, ttl);
	    if(f == 1)
		prt += format_page(explode(play, ","), 4);
	    else
		prt += play;
	}
    }
#ifdef STRICT_MUD

    if(number == 1)
	tmp = "> You are the only mudder online right now. <";

    else 
	tmp = "> There are "+query_num(number, 100)+" player"+(number<2?"":"s")+
	" on " + mud_long_name() + " right now. <";

#else

    if(number + creators == 1)
	tmp = "> You are the only mudder online right now. <";
    else 
    if(!creators)
	tmp = "> There are "+query_num(number,100)+" player"+
	(number<2?"":"s")+" on " + mud_name() + " MUD right now. <";
    else 
    if(!number)
	tmp = "> There are "+query_num(creators, 100)+" immortal"+
	(creators<2?"":"s")+" on " + mud_name() + " MUD. <";
    else
	tmp = "> There are "+query_num(creators, 100)+" immortal"+
	(creators<2?"":"s")+" and "+query_num(number, 100)+ " player"+
	(number<2?"":"s")+" on " + mud_name() + " MUD. <";
#endif
    prt += sprintf("%*'-'|s\n", width+0, tmp);
    return prt;
} /* who_string() */

static int cmd(string str, object me) {
    me->do_efun_write(who_string((int)me->query_cols(),
	(int)me->query_creator(),str, me));
    me->set_trivial_action();
    return 1;
} /* do_who() */

