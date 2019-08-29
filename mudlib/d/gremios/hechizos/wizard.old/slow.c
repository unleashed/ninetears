/*** Slow ***/
/*** By Wonderflug ***/

#include "tweaks.h"

#define SLOW_COST 10
#define SLOW_DURATION_LEVEL 1
#define SLOW_SHADOW "/d/gremios/hechizos/wizard/slow_sh.c"

#define SP_NAME "Slow"
#define GP_COST SLOW_COST
#define ALREADY_CASTING "cast"
#define save_type "spells"

inherit "/d/gremios/hechizos/patch.c";
object shadow;

void make_spell(object caster, object target, int duration);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: \n"
       "Level: 4th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
	"  This spell slows time for the target.  In particular, it "
	"will not be able to attack as often, and any spells cast on "
	"it will last longer than normal.  The slow itself lasts one "
	"round per level of the caster.  \n\n";
}

int cast_spell(string str, object caster)
{
  int cost;
  int new_count;
  int duration, level, duration_bon;
  int i;
  object target, my_caster;

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

  duration = (level*SLOW_DURATION_LEVEL);

  tell_object(my_caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(my_caster), my_caster->query_cap_name()+
	" begins to cast a spell.\n",
     	my_caster);

  my_caster->add_timed_property(ALREADY_CASTING,3,1);
  my_caster->adjust_gp(-GP_COST);
  call_out("make_spell",3,my_caster,str,duration);
  return 1;
}

void make_spell( object caster, object str, int duration )
{
  object* ob;
  object target;
  int j;

  ob = find_match(str, environment(caster));
  if (!sizeof(ob))
  {
        tell_object(caster, "There is nobody of that name here.\n");
        return 1;
  }
  target = ob[0];

/* Destruct a haste if there is one */
  if ( target->query_haste_spell() )
  {
	target->dispell_time_spell();
	return 1;
  }

/* Check there isn't already a slow spell */
  if ( target->query_slow_spell() )
  {
        tell_object(caster,"Your target has already been Slowed.\n");
        return 1;
  }

/* Don't want these two at once I don't think.  Not yet anyway. */
  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
	tell_object(caster,"An enchantment already on the target disrupts "
	  "your spell.\n");
  }

  tell_room(environment(caster), caster->query_cap_name()+
	" chants, 'temporis laggen'.\n", 
	caster);
  tell_object(caster, "You chant, 'temporis laggen'.\n\nYou slow "+
	target->query_cap_name()+".\n");
  tell_object(target, "You feel time turn to mush around you, slowing "
	"your every movement.\n"); 
  tell_room(environment(caster), caster->query_cap_name()+
      " finishes a spell with a gesture at "+target->query_cap_name()+
      ", and "+target->query_possessive()+" movements slow down.\n",
      ({ caster, target}) ); 

  j = duration;
  target->add_timed_property("slow_on", 1, j);
  
  shadow = clone_object(SLOW_SHADOW);
  shadow->setup_shadow(target); 

  return GP_COST;
}

