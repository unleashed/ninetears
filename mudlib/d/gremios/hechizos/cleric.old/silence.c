
#include "tweaks.h"
/*** SILENCE ***/
/*** Created by Wonderflug ***/
 

#define SP_NAME "Silence"
#define SPELLTYPE "offensive"      
#define TYPE "magical"
#define save_type "spells"
#define GP SILENCE_GP
#define LEVEL SILENCE_LEVEL
#define LOCKOUT "cast"

object room;
int hb;

string help() 
{
  return
        "\n\n"
        "Spell Name: "+SP_NAME+"\n"
        "Level: "+LEVEL+"\n"
        "Gp Cost: "+GP+"\n"
        "Description: \n"
	"  This spell makes the recipient unable to speak, shout, or "
	"otherwise use his/her vocal chords.  Most importantly, the "
	"target will not be able to cast spells.  The spell lasts two "
	"rounds per level of the caster.  Note, however, that this spell "
	"will likely not affect NPC's  The saving throw is based "
	"on the target's level and the caster's wisdom.\n"

   "Editors note: Forget the no NPC thingy, should work.\n"
        "\n";
}


int cast_spell(string str, object caster)
{
  object my_caster;
  object* obs;
  object target;

  if (caster)
	my_caster = caster;
  else my_caster = this_player();
  
  room = environment(my_caster);  
  if((my_caster->query_timed_property(LOCKOUT)) || 
	((int)my_caster->query_level()< 2*LEVEL) )
  {
       tell_object(my_caster,"You are already casting a spell.\n");
       return 1;
  }
  if( (int)my_caster->query_gp() < GP )
  { 
       tell_object(my_caster, "You are too mentally drained to cast.\n");
       return 1;
  }

  obs = (object*)find_match( str, environment(my_caster));
   if(!sizeof(obs))
  {
	tell_object(my_caster, "Your target is not here.\n");
	return 1;
  }
  target = obs[0];
  if ( target->query_silence_spell() )
  {
	tell_object(my_caster, "Your target is already silenced.\n");
	return 1;
  }
/*
  if ( !(interactive(target)) )
  {
	tell_object(my_caster, "Your target must be a player.\n");
	return 1;
  }

*/

  tell_object(my_caster,"You start to cast "+SP_NAME+".\n\n");
  tell_room(environment(my_caster),(string)my_caster->query_cap_name()+
	" starts to cast a spell.\n", my_caster);

  my_caster->adjust_gp(-GP);
  my_caster->add_timed_property(LOCKOUT,1,3);
  call_out("make_spell",1,my_caster,target);   
  return 1;
}

int cast(string str)
{
   return(cast_spell(str,this_player()) );
}

void make_spell(object caster, object target)
{
  object ob;

  tell_object(caster, "You chant, 'solus paqua quietum'.\n\n");
  tell_room(environment(caster),(string)caster->query_cap_name()+
	" chants, 'solus paqua quietum'.\n\n", ({ caster }));

  /* saving throw first */
  if ( (int)caster->query_wis() < random((int)target->query_level()) )
  {
	tell_room(room, caster->query_cap_name()+
	  " completes the spell, but nothing seems to happen.\n",
	  ({target, caster}) );
	tell_object(target, caster->query_cap_name()+
	  " completes the spell, then stares intently at you, as if "
	  "\nwondering why nothing happened.\n");
	tell_object(caster, "You complete the spell, but "
	  "apparently "+target->query_cap_name()+" is unaffected.\n");
	return;
  }

  ob = clone_object(SPELLS+"silence_sh.c");
  ob->setup_shadow(target);
  target->add_extra_look(ob);
  target->add_timed_property("silence_on",1,(int)caster->query_level()*2);
  target->add_timed_property("nocast",1,(int)caster->query_level()*2);

  tell_room(room,caster->query_cap_name()+" completes the spell "
	"and "+target->query_cap_name()+"screams silently.\n",
	({ caster, target }) );
  tell_object(caster,"You silence "+target->query_cap_name()+", "
	"and "+target->query_pronoun()+" screams silently at you.\n");
  tell_object(target,caster->query_cap_name()+" completes the spell, "
	"and you feel a tightness in your throat, and you're unable to "
	"say a thing!\n");
}
