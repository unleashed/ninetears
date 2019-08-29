inherit "/std/spells/base";
object *weaps;
int num,i;

void setup()
{
  set_spell_name("Random Causality");
  set_spell_level(10);
  set_sphere("chaos");
  set_target_type("one");
  set_range(0);
  set_help_desc(
   "This spell places a chaotic aura around and opponent's weapons.\n"
   "If they attack you and successfully hit you, the damage is\n"
   "instead randomly applied to one of your opponents, even the\n"
   "original attacker.\n");
  set_gp_cost(20);
  set_casting_time(1);
  set_rounds( ({"round1"}) );
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level;
  object shadow;
/**
  if((!target->is_player()) || (target==caster))
  {
    tell_object(caster,
     "You can only cast Random Causality on another player.\n");
    return -1;
  }
**/
  if(!quiet)
  {
    tell_object(caster, "You chant, 'chaoseum invertus'.\n");
    tell_room(environment(caster),
      caster->query_cap_name()+" chants, 'chaosuem invertus'.\n", caster);
  tell_object(caster, "You cast Random Causality upon "+
   target->query_cap_name()+".\n");
  }

  weaps=target->query_weapons_wielded();
  if(!sizeof(weaps))
  {
   tell_object(caster,
   "The power of chaos envelops your target, but dissipates, \n"
    "as "+target->query_pronoun()+" is not wielding a weapon.\n");
  }
  for(i=0;i<sizeof(weaps);i++)
  {
   shadow = clone_object("/std/spells/cleric/rnd_caus_sh.c");
   shadow->setshadow(weaps[i]);
   level = (int)caster->query_level();
   call_out("wear_off", 100 + (level * 10), weaps[i]);
  }
  return 0;
}

void wear_off(object target)
{
  if(target)
  {
     target->destruct_rnd_caus_shadow();
  }
}
