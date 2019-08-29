/* Finger of Death.
   Made by Baldrick June 1993.
   Mods for FR jan '95, by the same nerd.
   Uses saving throw to balance the spell. But it should be *very* high level
   To get it:
   Have fun with it.

   Wonderflug's Modifications:
   -- basically rewrote the thing.  Fixed the save formulas for resistances,
   -- Added a casting delay and new messages.
   -- Made it run off the heartbeat.

   Adapted to base spell, Wonderflug 95.
*/

inherit "/std/spells/base.c";

void setup() 
{
  set_spell_name("Finger of Death");
  set_spell_level(9);
  set_school("invocation");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell kills the one you manage to touch; "
    "if the victim is powerful enough it may survive.");

  set_gp_cost(40);
  set_casting_time(4);
  set_rounds(
    ({
      "round1",
      "round2",
      "round3",
      "round4"
    }) );
}
 
int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{     
  int check;
  int achit, THAC0, defenderac, result;

  if ( !target )
  {
    tell_object(caster, "Your target isn't here.\n");
    tell_room(environment(caster), caster->query_cap_name()+" looks "
      "rather confused and curses, the glow around "+
      caster->query_possessive()+" hand dissappearing.\n", caster);
    return -1;
  }

  if (!living(target))
  {
    tell_object(caster,"Why kill something already dead?\n");
    return -1;
  }

  if (target->query_creator())
  {
    tell_object(caster,"You don't think it is wise to kill an Immortal.\n");
    return -1;
  }

  if (target->query_dead())
  {
    tell_object(caster, target->query_cap_name() + " is already dead.\n");
    return -1;
  }

  if (target->query_pacify_spell())
  {
    tell_object(caster, target->query_cap_name()+
      " looks too harmless to kill.\n");
    return -1;
  }

  target = check_melee_protector(target, caster);

  THAC0 = (int)caster->query_thac0();
  achit = ((int)caster->query_level() + roll(1,20) - THAC0);
  defenderac = ((int)target->extra_bonus("defend") + (int)target->query_level()
    - (int)target->query_total_ac());

  achit = achit * ( (100 - (int)target->query_property("magical")) / 100 );

  result = (achit - defenderac);
  if (result < 0)
  {
    tell_object(target, "You notice "+caster->query_cap_name()+
      " tries to touch you with a vilely glowing finger, but misses.\n");
    caster->attack_ob(target);
    tell_object(caster, "You try to reach for your victim, but miss.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " reaches toward "+target->query_cap_name()+", but misses, and the "
      "glow around "+caster->query_possessive()+" hands fades.\n",
      ({ caster, target }) );
    target->attack_by(caster);
    return 1;
  }

  if(target->query_property("pacify_on"))
  {
    tell_room(environment(caster),"The Gods step in to save the life of "+
      target->query_cap_name()+", who is harmless.\n");
    return 1;
  }

  tell_object(caster,"You touch "+target->query_cap_name()+" and "+
    target->query_pronoun()+" screams horribly as "+
    target->query_possessive()+" life ends.\n");
  tell_room(environment(caster), (string)caster->query_cap_name() 
    +" touches "+(string)target->query_cap_name()+" and the poor victim "
    "screams horribly and dies.\n", ({ target, caster }) );
  tell_object(target, "You feel utter pain as "+ 
    (string)caster->query_cap_name()+" touches you, and then nothing..\n\n");
  target->do_death(caster);

  return 1;
}




int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !quiet )
  {
    tell_object(caster, "You chant in a foul tongue.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " chants in a foul tongue.\n", caster);
  }
  return 1;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !quiet )
  {
    tell_object(caster, "You raise your hand up high, your chanting "
      "reaching a crescendo.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " raises "+caster->query_possessive()+" hand up high, the chanting "
      "reaching a crescendo.\n", caster );
  }
  return 1;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !quiet )
  {
    tell_object(caster, "Your hand starts to glow with an evil light, "
      "pulsing green and blue.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      "'s hand starts to glow with an evil light, pulsing green and "
      "blue.\n", caster);
  }
  return 1;
}

