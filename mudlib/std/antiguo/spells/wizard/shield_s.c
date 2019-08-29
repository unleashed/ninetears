
#define SHIELDPATH "/std/spells/wizard/shield.c"

string SP_NAME="Shield of fire";
int GP_COST=10;
int SP_LEVEL=8;
int resist = this_player()->query_level()+50;
string TYPE="cold";
string SUB_TYPE="fire";
string chant_message="rizzaz armoum protestus";


inherit "/std/spells/base.c";

void setup()
{
  set_spell_name(SP_NAME);
  set_sphere("summoning");
  set_spell_level(SP_LEVEL);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("This spell conjures a magical shield.  The shield seems to"
	        "provide protection to "+TYPE+" type attacks.  The duration"
		" of the shield depends on the level of the caster.  For "
		"the protection to work, the shield must be held.\n\n");
  set_gp_cost(GP_COST);
  set_casting_time(1);
  set_rounds(({ "round1" }));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object shield;
  int VALUE=0,level=0, duration;
  if(caster->query_timed_property("shield_spell_on"))
  {
    tell_object(caster,"It's too soon for use that spell again.\n");
    return -1;
  }
  if(!quiet)
  {
    tell_object(caster, "You chant, '"+chant_message+"'.\n");
    tell_room(ETO, (string)caster->query_cap_name()+" chants, '"+
                   chant_message+"'.\n",({caster}));
  }
  level=(int)caster->query_level();
  VALUE=25+random(level/2);
  duration = 100+(level*8);
  caster->add_timed_property("shield_spell_on",1,level*20);
  shield = clone_object(SHIELDPATH);
  shield->setup_spell(caster,duration,TYPE,SUB_TYPE, resist);
  shield->move(caster);
  return 0;
}
