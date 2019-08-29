// Coded by Ralkor 6/96
// Tweaked by Alansyn
inherit "/std/spells/base.c";
void setup()
{
   set_spell_name("Holy Prayer");
   set_spell_level(7);
   set_sphere("guardian");
   set_target_type("one");
   set_range(0);
   set_line_of_sight_needed(0);
  add_property_to_check("SymbolTrans_on");
   set_help_desc("This spell creates an aura of evil which enshrouds "
      "the caster and protects him/her from attacs.  The caster will "
      "also get a small bit of combat help from this spell as well.");
   set_gp_cost(14);
   set_casting_time(2);
   set_rounds( ({ "round1","round2" }) );
   set_help_extras(0);
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
   tell_object(caster, "You pray to your diety for ultimate power.\n");
   tell_room(environment(caster), caster->query_cap_name()+
     " looks to be praying to someone.\n", caster);
   return 0;
}
 
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
   int level=caster->query_level();
   if (target != caster)
   {
      tell_object(caster,
         "You may not use this spell on anyone else.\n");
      return -1;
   }
   if (target->query_property("holy_prayer_on"))
   {
      tell_object(caster,
         "Sorry, not so fast, wait a bit and Grimbrand may respond.\n");
      return 0;
   }
   if ( !quiet )
   {
      tell_room(environment(caster),(string)caster->query_cap_name()+
         " chants, 'dynis es rockis'.\n", ({caster}));
      tell_object(caster, "You chant, 'dynis es rockis'.\n");
      caster->add_timed_property("holy_prayer_on",1,100+level*10);
   }
   if(target == caster)
   { 
      tell_object(target, "Grimbrand inspires you for your loyalty.\n");
      tell_room(environment(caster),(string)caster->query_cap_name()+
         "chants in Duergar asking Grimbrand for inspiration "+
         target->query_objective()+"self.\n",caster);
   }
   target->adjust_tmp_tohit_bon(level);
   target->adjust_tmp_damage_bon(level/10);
   target->adjust_tmp_ac_bon(level*2);
   target->add_extra_look(this_object());
   call_out("wear_off",100+level*10,target, level);
   return 0;
}
int wear_off(object target, int level)
{
  if(target)
  {
    tell_object(target, "You feel more vulnerable.\n");
    target->remove_extra_look(this_object());
    target->remove_static_property("harmour_on");
   target->adjust_tmp_tohit_bon(-level);
   target->adjust_tmp_damage_bon(-level/10);
   target->adjust_tmp_ac_bon(-level*2);
    tell_object(target, "Your Prayer of Holyness wears off.\n");
  }
   return 1;
}
 
string extra_look()
{
  return "%^BOLD%^BLACK%^Is enshrouded by a very dull, aura of evil.%^RESET%^\n";
}
