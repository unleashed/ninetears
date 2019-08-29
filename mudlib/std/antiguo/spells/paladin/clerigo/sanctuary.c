inherit "/std/spells/base";

void setup()
{
  set_spell_name("Sanctuary");
  set_spell_level(3);
  set_sphere("protection");
  set_target_type("one");
  set_range(0);
  set_help_desc(
   "This spell places a magical aura around the caster that forces anyone\n"
   "attacking them to make a saving throw or the attacker will suddenly\n"
   "ignore the caster for the duration of the spell.\n");
  set_gp_cost(10);
  set_casting_time(1);
  set_rounds( ({"round1"}) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level;
  object shadow;
  if(target !=caster)
  {
    tell_object(caster,
     "You can only cast Sanctuary on yourself.\n");
    return -1;
  }
  if(target->query_sanc())
  {
    tell_object(target,
      "You are already protected by Sanctuary.\n");
    return -1;
  }
  if(!quiet)
  {
    tell_object(caster, "You chant, 'prot me'.\n");
    tell_room(environment(caster),
      caster->query_cap_name()+" chants, 'prot me'.\n", caster);
    tell_object(caster,  "You cast Sanctuary upon yourself.\n");
  }

  shadow = clone_object("/std/spells/cleric/sanctuary_sh.c");
  shadow->setshadow(caster);
  level = (int)caster->query_level();
  call_out("wear_off", 100 + (level * 10), caster);
  return 0;
}

void wear_off(object target)
{
  if(target)
  {
     target->destruct_sanct_shadow();
    tell_object(target, "Your Sanctuary wears off.\n");
  }
}
