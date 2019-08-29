// #define SAFE_SNEAK
// uncomment if rooms break
/**** Original code by Unknown ****/
/**** First mod for new FR by Baldrick ****/
/**** Modified by Ilmryn to be realistic ****/
/**** The return 1's are DELIBERATE, thsi was getting into
      recursive loops
      Taniwha 1996
*/       	
#include "tweaks.h"
#include "room.h"
#define SNEAK_SKILL 20
#define COST SNEAK_COST

int sneak(string str, object mee)
{
    int i;
    object me;
    object tmp;
    mixed *dest_dir;
    mixed *dest_other;

    me = mee ? mee : this_player();

    str = me->expand_nickname(str);

    if (!str)  
    {
	write("Syntax: sneak <dir>\n");
	return 1;
    }

    if ((int)me->query_gp() < COST) 
    {
	write("Not enough guild points to sneak.\n");
	return 1;
    }
    if(me->query_guild_name() == "ranger" && !environment(me)->query_outside())
    {
	write("No, sorry, not here.\n");
	return 1;
    }

    if(me->query_light() > 20) {
	tell_object(me, "It would be useless to try to sneak here with "
	  "this light on yourself.\n");
	return 1;
    }

    dest_dir = (mixed *)environment(me)->query_dest_dir();
    dest_other = (mixed *)environment(me)->query_dest_other();
    if (!pointerp(dest_dir)) 
    {
	write("Please contact someone at once.  This room is WRONG!\n");
	return 1;
    }

    if ((i = member_array(str, dest_dir)) == -1 || i%2) 
    {
	write("Helps if you sneak in a direction that exists.\n");
	return 1;
    }
#ifdef SAFE_SNEAK
    tmp = find_object(dest_other[i+1][ROOM_DEST]);
    if(!tmp)
    {
	notify_fail("You failed to sneak "+dest_dir[i]+" try again maybe ?.\n");
	load_object(dest_other[i+1][ROOM_DEST]);
	return 0;
    }
#endif

    me->adjust_gp(-COST);

    if ((int)me->query_level() > random(SNEAK_SKILL))
    {
	if (me->query_hide_shadow())
	    i = (int)environment(me)->do_exit_command(0, 
	      ({ dest_dir[i], "none"}), me, me );
	else
	    i = (int)environment(me)->do_exit_command(0,
	      ({ dest_dir[i], "none"}) );
    }
    else
	i = (int)environment(me)->do_exit_command(0, dest_dir[i]);

    if (!i)
    {
	write("You failed to sneak "+dest_dir[i]+".\n");
	return 1;
    }  

    environment(me)->renew_exits();
    write("You sneak "+str+".\n");
    return 1;
}

string help() 
{
    return 
    "Syntax: sneak <dir>\n\n"
    "Lets you sneak in a direction.  This means that you get no exit or "
    "enter messages.  This relies on the skill other.covert.stealth.  "
    "Bing!  It will not inform you of success or failure and costs "+COST+
    " guild points regardless of if you succeed or not.\n\n"
    "Example : \n"
    "> sneak west\n"
    "Ok, you sneak west\n"
    "[Description of random room eaten by the hairy room descrtipion eater]\n"
    "\nSee also\n"
    "  hide.\n";
}
