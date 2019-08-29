/* Power word Die.
  Made by Baldrick June 1993.
    Mods for FR jan '95, by the same nerd.
    Uses saving throw to balance the spell. But it should be *very* high level
  To get it:
  Have fun with it.

  Wonderflug's mods:
  --Magic resistance done.   	
  --Check for pacified target.
  --Added a casting delay, some new fancy messages. 
  --Basically rewrote it.

  96, -> base spell.  Wonderflug again
*/

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Power Word Die");
  set_spell_level(7);
  set_sphere("necromantic");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell kills the one you use it at; if the victim is "
    "powerful enough it may survive.");

  set_gp_cost(40);
  set_casting_time(4);
  set_rounds( ({ "round1", "round2", "round3", "round4" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "You start to chant in a hissing, "
    "cursing tongue.\n");
  tell_room(environment(caster), caster->query_cap_name()+" chants "
    "quietly in a hissing, cursing sound.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "Your chanting becomes a vile, twisted "
    "shouting.\n");
  tell_room(environment(caster), caster->query_cap_name()+"'s chant "
    "grows louder, into a foul, twisted shout.\n", caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster, "You cut off abruptly, a pall of silence "
    "drops over the area.\n");
  tell_room(environment(caster), caster->query_cap_name()+" cuts off "
    "abruptly and an ominous silence fills the air.\n", caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int skill;
  int check;
  int cost;
  int c_roll, t_roll;

  if ( !target )
  {
    tell_object(caster,
      "Your spell failed ... there is nobody of that name here.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " looks very confused and curses.\n", caster);
    return -1;
  }

  if (target->query_creator())
  {
    tell_object(caster, "You don't think it is wise to kill an immortal.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " looks very confused and curses.\n", caster);
    return -1;
  }

  if (target->query_dead())
  {
    tell_object(caster, (string)target->query_cap_name()+
      " is already dead.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " looks very confused and curses.\n", caster);
    return -1;
  }

  if (target->query_pacify_spell())
  {
    tell_object(caster, "You don't feel like harming "+
      (string)target->query_cap_name()+", seeing how peaceful "+
      target->query_pronoun()+" is.\n");
    return -1;
  }

  /* here is the "saving throw" I'm trying out */

  c_roll = random( (int)caster->query_level() * (int)caster->query_wis() + 5 );
  t_roll = (int)target->query_level() * (int)target->query_wis();
  if ( c_roll*((100-(int)target->query_property("magical")) / 100 ) < t_roll )
  {
    tell_object(target, "You hear "+(string)caster->query_cap_name()+
      " whisper death to you through the silence.\n");
    caster->attack_ob(target);
    tell_object(caster, "Your word comes out only as a whisper.\n");
    tell_room(environment(caster), caster->query_cap_name()+" whispers "
      "something into the silence to "+target->query_cap_name()+".\n",
      caster);
    return 0;
  }

  if(target->query_property("pacify_on"))
  {
    tell_room(environment(caster),"The Gods step in to save the life of "+
      target->query_cap_name()+" who is harmless.\n");
    return 0;
  }
  tell_object(caster,"You shout into the sudden silence: DIE "+
    target->query_cap_name()+"!\n\nYou call upon the gods to help you kill " +
    target->query_cap_name()+".\n");
  tell_room(environment(caster),(string)caster->query_cap_name() + 
    " shouts in the sudden silence: DIE " +(string)target->query_cap_name() + 
    "!\n", ({ caster }) );
  tell_object(target, "\nYou feel " + (string)caster->query_cap_name() +
    "'s word attack you.\n\nThe powerword killed you.\n\n");
  target->do_death(caster);

  return 0;
}
