inherit "/std/spells/base.c";


void setup()
{
    set_spell_name("Shadow Sin");
   set_spell_level(4);
   set_sphere("necromantic");
   set_target_type("one");
   set_range(0);
   set_help_desc(
	"This spell summons a number of shadows from the Negative"
	" Material Plane.  These shadows swarm over the target,"
	" each draining a small amount of life and mental energy."
	"  A tiny portion of the life drained is funneled back to"
	" the caster.  The efforts of opening a gateway to the"
	" Negative Material Plane will exhaust the caster, wiping away"
	" all knowledge of the spell \"Heal\".\n"
      );
   set_gp_cost(8);
   set_casting_time(2);
   set_rounds(({"round1","round2"}));
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
	tell_object(caster, "A lightless gate appears before you.\n");
	tell_room(environment(caster), "A lightless portal"
		" appears before "+caster->query_cap_name()+".\n",
		caster);
   return 0;
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
	int shadow_num;
	int level;
	int drain;

	level = caster->query_level();
	shadow_num = (3 + (random(level)));
	if(shadow_num > 20)
	{
		shadow_num = 20;
	}

   if(!target)
   {
      tell_object(caster,
         "Your spell failed ... there is no one of that name here.\n");
      return -1;
   }
   if(target==caster)
   {
      tell_object(caster,"You can't cast this spell on yourself.\n");
      return -1;
   }
	tell_object(caster, "The Darkness within the gate begins to move..\n\n");
	tell_object(caster, "You complete your spell, and"
		" "+shadow_num+" shadows rise out of the darkness, swarming"
		" over "+target->query_cap_name()+"!\n");
	tell_object(target, caster->query_cap_name()+
		" completes "+caster->query_possessive()+" spell, and"
		" "+shadow_num+" beings of shadow swarm over you,"
		" their cold touch draining you"
		" of energy!\n");
	tell_room(environment(caster), caster->query_cap_name()+
		" completes "+caster->query_possessive()+
		" spell, and "+target->query_cap_name()+
	" is engulfed in shadows!\n", ({caster, target}));


	switch(caster->query_sphere_power("necromantic"))
   {
      case "major":
	  drain = shadow_num * 3;
         break;
      case "neutral":
	  drain = shadow_num * 2;
         break;
      case "minor":
	  drain = shadow_num;
         break;
      default:
	drain = shadow_num;
         break;
   }
target->adjust_hp(-drain);
target->adjust_gp(-shadow_num);
caster->adjust_hp(shadow_num);
target->attack_by(caster);
caster->remove_spell("heal");
}
