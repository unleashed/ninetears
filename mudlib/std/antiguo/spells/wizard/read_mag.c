/*** Read Magic Spell ***/
/*** Created by Cadogan, but hell if I know how it works ***/
/*** To base spell, Wonderflug 96, well copied from his, anyway ***/


#define SP_NAME "Read Magic"
#define GP_COST 10
#define SPELLTYPE "misc"

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name("Read Magic");
  set_school("magical");
  set_spell_level(10);

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell allows you to read magic for a limited "
                "duration.\n");

  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );

}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{


  if ( !quiet )
  {
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " chants, 'magius powers into me'.\n", ({caster}));
    tell_object(target, "You chant, 'magius powers into me'.\n");
  }
  
  {

    tell_object(target, "You cast Read Magic upon yourself.\n");
    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a spell upon "+caster->query_objective()+"self.\n",target);
  }
  
/*
  else
  {

    tell_object(caster, "You cast Read Magic on "+
      (string)target->query_cap_name() + ".\n");

    tell_room(environment(caster),(string)caster->query_cap_name()+
      " casts a Read Magic spell upon "+target->query_cap_name()+".\n",
      ({caster}) );
  }
*/

  caster->add_static_property("read_magic", 100);
  return 0;
}

