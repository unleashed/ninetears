
#define SP_NAME           "Rope Knots"
#define GP_COST 	1
#define PROPERTY        "skill_rope_knots"
#define VALUE 		50
#define chant_message	"tannyum rizupis"
 
inherit "/std/spells/base.c";

void setup()
{
  set_spell_name(SP_NAME);
  set_spell_level(2);
//  set_sphere("protection");

  set_target_type("one");
  set_range(0);

  set_help_desc(
    "Add one.\n");

  set_gp_cost(GP_COST);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration;
  int value;
  int level;
 
  if (!target) {
    tell_object(caster,
      "Your spell failed ... there is no one of that name here.\n");
    return -1;
  }
    
  if (!quiet) {
    tell_room(environment(caster), (string)caster->query_cap_name()+
      " chants, '"+chant_message+"'.\n", ({target,caster}));
    tell_object(caster, "You chant, '"+chant_message+"'.\n");
  }
    
  if(target == caster) { 
     tell_object(target, "You feel more skilled.\n");
      tell_room(environment(caster), (string)target->query_cap_name()+" seems tied up in thoughts for a while, but manages to sort it all out\n",({caster,target}));
      tell_room(environment(caster), (string)target->query_cap_name()+" seems tied up in thoughts for a while, but manages to sort it all out\n", target);
  } else {
     tell_object(target, "You feel more skilled.\n");
    tell_object(caster, "You cast "+SP_NAME+" on "+
      (string)target->query_cap_name() + ".\n");
      tell_room(environment(caster), (string)target->query_cap_name()+" seems tied up in thoughts for a while, but manages to sort it all out\n",({caster,target}));
  }
 
  value = 50+VALUE;
  level = (int)caster->query_level();
  duration=20*level;
 
  target->add_timed_property(PROPERTY, value, duration);
  
  return 0;
}
