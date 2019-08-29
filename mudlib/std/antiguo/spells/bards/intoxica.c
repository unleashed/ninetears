/***  Intoxicate Spell  ***/
/*** Blame this spell on Caanan ***/
/*** ->base spell, Wonderflug ***/
 
inherit "/std/spells/base.c";
 
#define ALCOHOL 0
#define VOLUME 200
#define LVL_FACTOR 10 
#define MAX_DRUNK 1000

void setup()
{
  set_spell_name("Intoxicate");
  set_spell_level(2);
  set_school("bard");

  set_target_type("one");
  set_range(0);

  set_help_desc("This spell renders the target fairly intoxicated.  "
    "Amount of inebriation increases with level of bard.");
 
  set_gp_cost(4);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{

  if (!target)
  {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }

  if ( !quiet )
  {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " sings:\n\n"   
      "   Twenty-four kegs of the King's finest ale,\n"  
      "   If we drank even one, we'd wind up in jail.\n"
      "   Though we'd be merry, our heads in a sail,\n"
      "   At the last we would find our good lunch in a" 
      " pail.\n", ({target,caster}));
 
    tell_object(caster, "You sing:\n\n" 
      "   Twenty-four kegs of the King's finest ale,\n"  
      "   If we drank even one, we'd wind up in jail.\n"
      "   Though we'd be merry, our heads in a sail,\n"
      "   At the last we would find our good lunch in a" 
      " pail.\n\n");
  }

  if ( target == caster )
  {
    tell_object(target, "You cast Intoxicate upon yourself.\n");
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " casts a spell upon "+target->query_objective()+"self.\n",target);
  }
  else
  {
    tell_object(target, "You feel quite inebriated.  What a lush!\n");
 
    tell_object(caster, "You cast Intoxicate on "+
      (string)target->query_cap_name() + ".\n");
 
    tell_room(environment(caster), target->query_cap_name()+
      " suddenly seems quite the lush.\n", ({target,caster}) );
  }
 
  if ((target->query_volume(ALCOHOL)) < MAX_DRUNK)
  {
    target->adjust_volume(ALCOHOL, 
      VOLUME+((int)caster->query_level()*LVL_FACTOR));
  }

  if ( !interactive(target) )
  {
    tell_room(environment(caster), target->query_cap_name()+
      " doesn't appear too pleased with "+caster->query_cap_name()+
      "'s antics.\n", caster);
    tell_object(caster, target->query_cap_name()+
      " doesn't appear too pleased with your antics.\n");
    target->attack_by(caster);
  }

  return 0;
}
