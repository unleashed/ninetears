/*** Haste ***/
/*** By Wonderflug ***/

#include "tweaks.h"

#define HASTE_COST 5
#define HASTE_DURATION_LEVEL 1

#define HASTE_SHADOW "/std/spells/wizard/haste_sh.c"
//#define HASTE_SHADOW "/d/bf/banefall/fixes/new/haste_sh.c"

#define SP_NAME "Surge"
#define GP_COST HASTE_COST
#define ALREADY_CASTING "cast"
#define save_type "spells"

inherit "/std/spells/patch.c";
object shadow;

void make_spell(object caster, object target, int duration);


string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
       "This is a skill of the Drow Warrior that allows him to get a burst "
       "of adrenaline.  This allows for quicker movements over a period of "
       "time.  After they use this skill, it leaves a warrior tired and "
       "quiet weak for sometime.\n\n";
}

int surge(string str, object caster)
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
	tell_object(my_caster,"You are already trying to surge.\n");
	return 1;
  }
  if ((int)my_caster->query_gp() < GP_COST )
  {
	tell_object(my_caster,"You are too mentally drained to "
	  "surge.\n");
	return 1;
  }

  level = (int)my_caster->query_level();

  duration = (level*HASTE_DURATION_LEVEL);

  tell_object(my_caster,"You start to "+SP_NAME+".\n");
  tell_room(environment(my_caster), my_caster->query_cap_name()+
	" seems to be focusing "+my_caster->query_objective()+"energry.\n",
     	my_caster);

  my_caster->add_timed_property(ALREADY_CASTING,3,1);
  my_caster->adjust_gp(-GP_COST);
  str = (string)my_caster->query_name();
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
        return;
  }
  target = ob[0];

/* Destruct any current slow */
  if ( target->query_slow_spell() )
  {
        target->dispell_time_spell();
	return;
  }

/* Check for a haste or other (TBD) time spell */
  if ( target->query_time_spell() )
  {
	tell_object(caster, "Your target is already Hasted.\n");
	return;
  }

/* Don't want these two at once I don't think.  */
  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
	tell_object(caster, "You cannot Haste yourself right now.\n");
	return;
  }

  tell_room(environment(caster), caster->query_cap_name()+
	" suddenly becomes very flushed.\n", 
	caster);
  tell_object(caster, "You feel a surge of adrenaline.\n\n");
  tell_object(target, "You feel your pulse quicken and you seem to be moving "
	"much faster than you were.\n");
  tell_room(environment(caster), caster->query_cap_name()+
      " suddenly is moving much faster than normal!\n",
      ({ caster, target}) ); 

  j = duration;
  target->add_timed_property("haste_on", 1, j);
  
  shadow = clone_object(HASTE_SHADOW);
  shadow->setup_shadow(target); 

   return;
}

