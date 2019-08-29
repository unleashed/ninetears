/*** Power Word: Stun ***/
/*** By Wonderflug ***/

#include "tweaks.h"

#define PW_STUN_COST 14
#define PW_STUN_SHADOW "/std/commands/shadows/stun.c"

#define SP_NAME "Power Word: Stun"
#define GP_COST PW_STUN_COST
#define ALREADY_CASTING "cast"
#define save_type "spells"

inherit "/std/spells/patch.c";

mixed find_unique_match(string find, mixed in);

void make_spell(object caster, object target);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Conjuration\n"
       "Level: 7th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
	"  This spell allows you to shout the Stun Power Word.  Everyone "
	"in the room with you will be stunned for 1-5 rounds.  During this "
	"time, they cannot attack, move, or cast spells, and are more "
	"vulnerable to be attacked.\n\n";
}

int cast_spell(string str, object caster)
{
  int cost;
  int new_count;
  int duration, level, duration_bon;
  int i;
  object target, my_caster;

  str = (string)this_player()->expand_nickname(str);

  if (caster)
	my_caster = caster;
  else 
  {
	my_caster = this_player();
	str = (string)my_caster->expand_nickname(str);
  }


  if (my_caster->query_timed_property(ALREADY_CASTING))
  {
	tell_object(my_caster,"You are already casting a spell.\n");
	return 1;
  }
  if ((int)my_caster->query_gp() < GP_COST )
  {
	tell_object(my_caster,"You are too mentally drained to cast "
	  "this spell.\n");
	return 1;
  }

  level = (int)my_caster->query_level();

  if (interactive(my_caster))
    if ( (string)my_caster->query_guild_name() == "conjurer" )
	cost = GP_COST/2;
    else cost = GP_COST;

  tell_object(my_caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(my_caster), my_caster->query_cap_name()+
	" begins to cast a spell.\n",
     	my_caster);

  my_caster->add_timed_property(ALREADY_CASTING,3,1);
  my_caster->adjust_gp(-cost);
  call_out("make_spell",3,my_caster,str);
  return 1;
}

void make_spell( object caster, string str )
{
  object* ob;
  int i, j;
  object* shadows;

  ob = all_inventory( environment(caster) );
  if (!sizeof(ob))
  {
        tell_object(caster, "There is nobody of that name here.\n");
        return 1;
  }
  shadows = allocate(sizeof(ob));

  tell_room(environment(caster), caster->query_cap_name()+
	" shouts: STUN!!\n", caster);
  tell_object(caster, "You shout: STUN!!\n\n");

/* Noguild, nocast, passed out just to make the shadow simpler. */

  for (i=0;i<sizeof(ob);i++)
  {
	if ( ob[i] == caster || !living(ob[i]) || ob[i]->query_property("dead"))
		continue;
	if ( ob[i]->query_time_spell() )
	{
		tell_object(ob[i], "The Power Word destroys your "
		  "enchantment!\n");
		ob[i]->dispell_time_spell();
		continue;
	}
	shadows[i] = clone_object(PW_STUN_SHADOW);
	j = random(5)+1;
  	j = wiz_fix_damage(caster, ob[i], j, "magical");
	if ( j <= 0 || ob[i]->query_hold_spell() || ob[i]->query_pacify_spell())
	{
	  tell_room(environment(caster), ob[i]->query_cap_name()+
	    " resists the effects of the Power Word.\n", ob[i]);
	  tell_object(ob[i],"You resist the effects of the Power Word.\n");
	  continue;
	}

        tell_room(environment(caster), ob[i]->query_cap_name()+" succumbs "
          "to the Power Word and falls over unconscious.\n", ob[i]);
        tell_object(ob[i], "You succumb to Power Word and black out.\n");

  	ob[i]->add_timed_property("stun_on", 1, j);
  	ob[i]->add_timed_property("nocast",1, j);
  	ob[i]->add_timed_property("noguild",1,j);
  	ob[i]->add_timed_property("passed out",1,j);

  	shadows[i] = clone_object(PW_STUN_SHADOW);
  	shadows[i]->setup_shadow(ob[i], j); 
  	ob[i]->add_extra_look(shadows[i]);

	ob[i]->attack_by(caster);
  }

  return GP_COST;
}

