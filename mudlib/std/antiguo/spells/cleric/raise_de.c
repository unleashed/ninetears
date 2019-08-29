/*** Raise Dead Spell ****/
/*** origional author unknown ***/
/*** modified for use on FR-MUD by Eerevann ***/
/* Adding some nastyness, this makes the spell a more unstable.
 * they may loose a statpoint when they get raised, maybe even a con..
 * lover con, giver bigger chance to loose a stat.
 * Baldrick, jan '95
 */ 
/*** -> base spell, Wonderflug ***/

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Raise Dead");
  set_spell_level(5);
  set_sphere("necromantic");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell raises a ghost from the dead.  It removes "
    "one of their constitution points, unlike resurrect, and turns them "
    "back from being a ghost. If the ghost does not wish to return from "
    "the Halls of the Dead, the spell will fail.");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
 

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if ( !target )
  {
    tell_object(caster, "Your spell failed .. there is nobody of that "
      "name here.\n");
    return -1;
  } 
  if (!target->query_dead())
  {
    tell_object(caster, (string)target->query_cap_name() + 
      " is not dead ... yet.\n");
    return -1;
  }
  if (target->query_property("noregen"))
  {
    tell_object(caster, "Death tells you: HOLD ON, I'M NOT FINISHED "
      "WITH THEM YET.\n");
    return -1;
  }
  if ( !target->query_consent("resurrection") )
  {
    tell_object(caster,"The ghost does not wish to return to the Realms of "
      "the living yet. (see 'help consent')\n");
    return -1;
  }

  tell_object(caster,"You call upon the gods to restore "+
    (string)target->query_cap_name()+" from "+ 
    (string)target->query_possessive() + " immaterial state by hitting "+
    target->query_objective()+" with a lightning bolt..\n");
  tell_object(target, (string)caster->query_cap_name() +
    " summons the gods for you, and incidently hits you with a lightning "
    "bolt.  It doesn't seem to hurt.\n");
  tell_room(environment(caster),(string)caster->query_cap_name() + 
    " stares intently into space, and you hear a vage rumbling in the "
    "distance. Suddenly a lightning bolt sears through the sky and hits "+
    target->query_cap_name()+", restoring "+
    target->query_objective()+" from the dead.\n", ({ caster, target }) );

  target->remove_ghost();

  return 0;
}
