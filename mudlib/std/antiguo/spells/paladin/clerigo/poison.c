/*** Poison ***/
/*** Created by Taniwha ***/
/*** -> base spell by Wonderflug ***/
 
#include "tweaks.h"

inherit "/std/spells/base.c";

void setup_poison(int, object, object);

void setup()
{
  set_spell_name("Poison");
  set_spell_level(5);
  set_sphere("summoning");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  
  set_help_extras(
    "Damage Type: poison\n"
    "Saving Throw: Level Constitution and Resist Poison");
  set_help_desc("This spell causes the victim lose HP at a rate dependent on "
    " the victims constitution. There is an initial saving throw based "
    " on relative level and constitution. And a 100% save for resist "
    " poison. Note that the intended victim will become immune for a "
    " period if the initial attack fails. "
    " The strength of the poison depends on casters guild and level. "       
    " Cyrcia priests poison is twice as powerful as that of other "
    " priests at the same level. "
    " Neutralize poison will neutralize this spell.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int quiet, int time)
{
  int damage;
  object ob;

  if ( wrong_alignment(caster) )
  {
    punish_align(caster);
    return 0;
  }

  if ( !target )
  {
    tell_object(caster,
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
       " chants, \"Toxoplasmosis\".\n", ({ caster }));
    tell_object(caster, "You chant, \"Toxoplasmosis\".\n");
  }

  if( (int)target->query_property("poisoned") || 
      (int)target->query_property("poison") || 
      (int)target->query_dead() ||
      (int)target->query_property("undead") )
  {
    tell_object(caster,(string)target->query_cap_name()+
      " cannot be poisoned.\n");
    target->attack_by(caster);
    return 0;
  }

  if( random((int)target->query_level()+(int)target->query_con()) >
      random((int)caster->query_level()*2) )
  {
    target->add_timed_property("poison",50,(int)caster->query_level() * 60);
	 if( (string)caster->query_race() != "monster")
	 {
    	tell_object(caster, "Oops your target was unharmed by the attack.\n");
    	tell_object(target, caster->query_cap_name()+" hisses at you strangely.  "
      "Must have been some sort of failed attack.\n");
    	tell_room(environment(caster), caster->query_cap_name()+
      " looks strangely at "+target->query_cap_name()+".\n",
      ({ caster, target }) );
    }
    target->attack_by(caster);
    return 1;
  }

  damage = (int)caster->query_level()/POISON_MOD;
  if((string)caster->query_guild_name() == "Cyrcia") 
    damage *= 2;
   
  // Made this a function - Radix
  setup_poison(damage,caster,target);
  
  	tell_object(caster, "You scratch "+target->query_cap_name()+
    	", leaving a festering, poisoned wound.\n");
  	
	tell_object(target, caster->query_cap_name()+" scratches you, "
    "and a festering wound appears on you!\n");
  tell_room(environment(caster),(string)caster->query_cap_name()+ 
    " scratches and poisons "+(string)target->query_cap_name()+
    " leaving a festering wound.\n",({ caster, target }));
  target->attack_by(caster);

  return 0;
}

// Made this for external calls, yeah yeah, probably shouldn't - Radix
void setup_poison(int damage, object caster, object target)
{
   object ob = clone_object(SPELLS+"poisoned.c");
   target->add_timed_property("poisoned",1,(caster->query_level()*30));
   ob->set_get();
   ob->move(target);
   ob->reset_drop();
   ob->reset_get();
   ob->set_spell(caster,damage);
   return;
}
