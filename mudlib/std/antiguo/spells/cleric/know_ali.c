/* Detect alignment. For priests.
   Made by Baldrick July 1993.
   This spell detects the alignment of a player or NPC.
   Have fun with it.
   Extended Taniwha 1995

   ->Base spell, Wonderflug 96
*/

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Know Alignment");
  set_spell_level(2);
  set_sphere("clericdivination");

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell detects the alignment of a player or NPC."
    "  Note that the amount of information you receive improves"
    " as your level increases.");

  set_gp_cost(4);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  string retv;
  string deity,mydeity;
  int i;

  if ( !target )
  {
    tell_object(caster,
      "Your spell failed ... there is nobody of that name here.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_object(caster, "You chant, 'ethos deus beleah'.\n");
    tell_room(environment(caster), caster->query_cap_name()+
      "chants, 'ethos deus beleah'.\n", caster);
  }

  tell_object(caster, "You call upon the gods to help you detect the "
    "alignment of "+target->query_cap_name()+".\n");
  tell_object(target, caster->query_cap_name()+" seems to stare intently "
    "at you, and you feel stripped and naked under the gaze.\n");
  tell_room(environment(caster), caster->query_cap_name()+" stares intently "
    "at "+target->query_cap_name()+".\n", ({ caster, target }) );

  i = target->query_align();
  retv = "You feel that "+target->query_cap_name()+" is morally "+
    (string)target->query_align_name(i)+".\n";
  deity = target->query_deity();
  mydeity = caster->query_deity();
  switch ( (int)caster->query_level() )
  {
    /* yes, these are supposed to be fall-through, no breaks. */
    case 21..1000:
      i = target->query_deity_status(mydeity);
      retv += "Is"+target->query_deity_string(i)+mydeity+".\n";
    case 16..20:
      i = target->query_deity_status(deity);
      retv += "Is"+target->query_deity_string(i)+deity+".\n";
    case 11..15:
      retv += "Is a follower of "+deity+".\n";
    case 6..10:
      i = target->query_ethics();
      retv += "And is ethically "+target->query_ethical_name(i)+".\n";
  }

  tell_object(caster, retv);
  return 1;
}
