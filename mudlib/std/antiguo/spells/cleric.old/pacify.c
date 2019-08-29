/*** PACIFY ***/
/*** By Wonderflug ***/

#include "tweaks.h"

#define PACIFY_GP_COST 10
#define PACIFY_DURATION_BONUS 1
#define PACIFY_DURATION_BASE 50
#define PACIFY_DURATION_LEVEL 2
#define PACIFY_SHADOW "/std/spells/cleric/pacify_sh.c"

#define SP_NAME "Pacify"
#define GP_COST PACIFY_GP_COST
#define ALREADY_CASTING "cast"
#define save_type "spells"

object shadow;

void make_spell(object caster, object target, int duration);

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Plant\n"
       "Level: 5th\n"
       "Gp Cost: "+GP_COST+"\n"
       "Description: \n"
	"  This spell pacifies the target, and causes the target to "
	"radiate an aura of good-will, so that no other players may "
	"attack him/her.  All fights with the target are stopped, and "
	"none may be started either by the target or another player "
	"until the spell wears off.  NPC combat will still go on with the "
	"target, however, the target will be unable to cast spells or "
	"use guild commands, and must rely on normal weapon combat.  "
	"The duration for this spell is long, and tymorans get a bonus "
	"to the duration.\nThis spell will (somewhat) protect a "
	"newbie from being pk'd, and stop a pk'er from pk'ing. \nHighly "
	"subject to change, mail Wonderflug and/or 'spells' with suggestions "
	"and/or complaints regarding this spell.\n\n";
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
	tell_object(my_caster,"You are too mentally drained to "
	  "cast this spell.\n");
	return 1;
  }
  if ( str == (string)my_caster->query_name() )
  {
	tell_object(my_caster,"You may not cast this spell on yourself.\n");
	return 1;
  }

  target = find_player(str);
  if (!(target))
  {
	tell_object(my_caster,"There is no player of that name here.\n");
	return 1;
  }
  if ( environment(target) != environment(my_caster) )
  {
	tell_object(my_caster,"There is no player of that name here.\n");
	return 1;
  }
  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
	tell_object(my_caster,"Your target has some enchantment "
	  "already that disrupts your spell.\n");
	return 1;
  }
  if ( target->query_time_spell() )
	target->dispell_time_spell();

  level = (int)my_caster->query_level();

  duration_bon = 0;
  cost = GP_COST;
  if ( interactive(my_caster) )
    if ( (string)my_caster->query_guild_name() == "tymora" )
    {
	duration_bon = level*PACIFY_DURATION_BONUS;
	cost = GP_COST/2;
    }

  duration = duration_bon + 
	PACIFY_DURATION_BASE+(level*PACIFY_DURATION_LEVEL);

  tell_object(my_caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(my_caster), my_caster->query_cap_name()+
	" begins to cast a spell.\n",
     	my_caster);

  my_caster->add_timed_property(ALREADY_CASTING,3,1);
  my_caster->adjust_gp(-cost);
  call_out("make_spell",1,my_caster,target,duration);
  return 1;
}

void make_spell( object caster, object target, int duration )
{
  object* ob;
  object* atts_list;
  object* call_outed;
  int j;

  tell_room(environment(caster), caster->query_cap_name()+
	" chants, 'aztak pacifus'.\n", 
	caster);
    
  tell_object(caster, "You chant, 'aztak pacifus'.\n\nYou pacify "+
	target->query_cap_name()+".\n");
  tell_object(target, "You feel the violence drain out of you, leaving "
	"a feeling of utter peace \nand calm.\n"); 
  tell_room(environment(caster), caster->query_cap_name()+
      " finishes a spell with a gesture at "+target->query_cap_name()+
      ", and "+target->query_pronoun()+" gets a look of sublime peace "
      "on "+target->query_possessive()+" face.\n",
      target); 


  target->add_timed_property("pacify_on", 1, duration);
  target->add_timed_property("noguild", 1, duration);
  target->add_timed_property("nocast", 1, duration);
  target->add_timed_property("nosteal",1,duration);
  
  shadow = clone_object(PACIFY_SHADOW);
  shadow->setup_shadow(target); 
  target->add_extra_look(shadow);

  atts_list = target->query_attacker_list();
  for (j=0;j<sizeof(atts_list);j++)
  {
	target->stop_fight(atts_list[j]);
	atts_list[j]->stop_fight(target);
  }

  call_outed = target->query_call_outed();
  for (j=0;j<sizeof(call_outed);j++)
  {
	target->stop_fight(call_outed[j]);
	call_outed[j]->stop_fight(target);
  }

  return GP_COST;
}

