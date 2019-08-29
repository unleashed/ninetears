/*** PACIFY ***/
/*** By Wonderflug ***/

#include "tweaks.h"

#define PACIFY_DURATION_BONUS 1
#define PACIFY_DURATION_BASE 50
#define PACIFY_DURATION_LEVELX 2
#define PACIFY_SHADOW "/std/spells/cleric/pacify_sh.c"

#define OMIQ_HAND "/global/omiq"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Pacify");
  set_spell_level(5);
  set_sphere("plant");

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell pacifies the target, and causes the target to "
    "radiate an aura of good-will, so that no other players may "
    "attack him/her.  All fights with the target are stopped, and "
    "none may be started either by the target or another player "
    "until the spell wears off.  NPC combat will still go on with the "
    "target, however, the target will be unable to cast spells or "
    "use guild commands, and must rely on normal weapon combat.  "
    "The duration for this spell is long, and hokemj priests get a bonus "
    "to the duration.\nThis spell will (somewhat) protect a "
    "newbie from being pk'd, and stop a pk'er from pk'ing.");

  set_gp_cost(10);
  set_casting_time(1);
   set_rounds( ({"round2"}) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(environment(caster), "A feeling of peacefulness and serenity "
    "fills the area.\n", ({ }) );
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration, level;
  object* ob;
  object* atts_list;
  object* call_outed;
  object shad;
  int i;
   if(caster->query_guild_name() == "paladin" && target == caster)
   {
      tell_object(caster,"Craven coward, thou shalt NOT!\n");
      return -1;
   }

  if(OMIQ_HAND->flag_in_progress()) 
  {
    tell_object(caster,"Not during an omiq, sorry.\n");
    return -1;
  }
  if ( wrong_alignment(caster) )
  {
    punish_align(caster);
    return 0;
  }
  if ( !target || !interactive(target) )
  {
    tell_object(caster,"There is no player of that name here.\n");
    return -1;
  }
/* Taniwha 1997, allow self as target
  if ( target == caster )
  {
    tell_object(caster,"You may not cast this spell on yourself.\n");
    return -1;
  }
*/
  if ( target->query_hold_spell() || target->query_pacify_spell() )
  {
    tell_object(caster,"Your target has some enchantment "
      "already that disrupts your spell.\n");
    return -1;
  }

  if ( target->query_time_spell() )
    target->dispell_time_spell();

  level = (int)caster->query_level();

  duration = 0;
  if ( (string)caster->query_guild_name() == "hokemj" )
    duration = level*PACIFY_DURATION_BONUS;
  duration += PACIFY_DURATION_BASE+(level*PACIFY_DURATION_LEVELX);

  if ( !quiet )
  {
    tell_room(environment(caster), caster->query_cap_name()+
      " chants, 'aztak pacifus'.\n", caster);
    tell_object(caster, "You chant, 'aztak pacifus'.\n");
  }

  tell_object(caster, "You pacify "+target->query_cap_name()+".\n");
  tell_object(target, "You feel the violence drain out of you, leaving "
    "a feeling of utter peace \nand calm.\n"); 
  tell_room(environment(caster), caster->query_cap_name()+
    " finishes a spell with a gesture at "+target->query_cap_name()+
    ", and "+target->query_pronoun()+" gets a look of sublime peace "
    "on "+target->query_possessive()+" face.\n", ({caster, target}) ); 

  target->add_timed_property("pacify_on", 1, duration);
  target->add_timed_property("noguild", 1, duration);
  target->add_timed_property("nocast", 1, duration);
  target->add_timed_property("nosteal",1,duration);
  
  shad = clone_object(PACIFY_SHADOW);
  shad->setup_shadow(target); 
  target->add_extra_look(shad);

  atts_list = target->query_attacker_list();
  for (i=0;i<sizeof(atts_list);i++)
  {
    target->stop_fight(atts_list[i]);
    atts_list[i]->stop_fight(target);
  }
  call_outed = target->query_call_outed();
  for (i=0;i<sizeof(call_outed);i++)
  {
    target->stop_fight(call_outed[i]);
    call_outed[i]->stop_fight(target);
  }

  return 0;
}

