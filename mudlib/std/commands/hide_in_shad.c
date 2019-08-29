/* Hide in shadows.
   Finally screwed Taniwha 1995
*/
#include "/std/commands/tweaks.h"
#define EXTRA_BONUS 5
#define HIDE_SKILL 20
#define COST HIDE_COST
#define SHADOW "/std/commands/shadows/hide"

int hide_skill_bonus();

int hide_in_shadows(string str,object hider)
{
    int sk_bon;
    object me;
    object ob;

    if(hider) me = hider;
    else me = this_player();

    if ((int)me->query_gp() < COST)
    {
	tell_object(me,"You are too tired to hide.\n");
	return 1;
    }
    if ( sizeof( me->query_attacker_list() ) )
    {
	tell_object(me,"You cannot hide in the middle of a fight!\n");
	return 1;
    }
    if(me->query_guild_name() == "ranger" && !environment(me)->query_outside() )
    {
	write("Ain't nothing round here fit for a Ranger to hide in.\n");
	return 1;
    }

    if(me->query_light() > 20)  {
	tell_object(me, "It would be impossible to hide here with that "
	  "light on yourself.\n");
	return 1;
    }
    me->adjust_gp(-COST);
    sk_bon = (int)me->query_level() + hide_skill_bonus();
   me->add_timed_property("noguild",1,1); /* Spam lock DO NOT REMOVE */

    if (sk_bon > random(HIDE_SKILL) && !me->query_hide_shadow())
    {
	ob = clone_object(SHADOW);
	ob->setup_shadow(me);
    }
    tell_object(me,"You try to hide in the shadows.\n");
    return 1;
}

// Shauri, 23-11-95 updating hide for guilds

int hide_skill_bonus()
{
    int bonus=0;

    switch((string)this_player()->query_guild_name()) {
    case "ranger":
	if(environment(this_player())->query_outside())
	    bonus = EXTRA_BONUS;
	break;
    case "wizthief":
	if((string)environment(this_player())->query_property("location") == "inside")
	    bonus = EXTRA_BONUS;

	else if((int)environment(this_player())->query_light() <= 15)
	    bonus = EXTRA_BONUS;
	break;
    case "bard":
	if((string)environment(this_player())->query_property("location") == "inside") {
	    if(member_array("/std/pub.c",deep_inherit_list(environment(this_player()))) >= 0 ||
	      member_array("bedroom",explode(environment(this_player())->query_long()," ")) >= 0)
		bonus = EXTRA_BONUS;
	}
	break;
    }
    return (bonus);
}

string help()
{
    return "Syntax: hide\n\nAllows you to hide in shadows.  This allows "
    "you to escape glancing eyes. Success is based upon your level "
    "and it costs "+ COST +" guild points regardless of success or failure."
    "\n\nExample:\n> hide\nYou try to hide in the shadows.\n\nSee also: "
    "sneak.\n";
}

