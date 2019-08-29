inherit "/std/spells/base.c";
void setup()
{
   set_spell_name("Energy Drain");
   set_spell_level(7);
   set_sphere("necromantic");
   set_target_type("one");
   set_range(0);
   set_help_desc(
      "When this spell is cast, all skills of the target, are subject "
      "to being lowered.  This is the reverse of restore."
      );
   set_gp_cost(0);
// set_gp_cost(14);
   set_casting_time(2);
   set_rounds(({"round1","round2"}));
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
   write("removed due to abuse.\n");
   return 0;
   tell_object(caster,"You begin to pray to "+capitalize(caster->query_deity())+
      ".\n");
   tell_room(environment(caster),caster->query_cap_name()+" seems to be "
      "praying to someone.\n",caster);
   return 0;
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
   int drain;
   int stat;
   int adj;
   write("removed due to abuse.\n");
   return 0;
   if(caster->query_timed_property("energy_drained"))
   {
      notify_fail("It too soon to cast that spell again "
         "the negative energy might stress your body.\n");
      return -1;
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
   if(target->query_deity()==caster->query_deity())
   {
      tell_object(caster,target->query_cap_name()+" follows "
         "the same deity that you do.  You can't drain "+
         target->query_objective()+".\n");
      return -1;
   }
   if(!quiet)
   {
      tell_object(caster,"You focus negative energy to cast the spell.\n");
      tell_object(caster,"You touch "+target->query_cap_name()+
         " draining "+target->query_objective()+" with the energy.\n");
      tell_object(target,caster->query_cap_name()+" touches you, "
         "causing you to feel drained.\n");
      tell_room(environment(caster),caster->query_cap_name()+
         " touches "+target->query_cap_name()+" causing "+
         target->query_cap_name()+" to look drained.\n",
         ({caster,target}));
   }
   switch(caster->query_sphere_level("necromantic"))
   {
      case "major":
         drain=caster->query_level()/4;
         if(drain>18)
            drain=18;
         break;
      case "neutral":
         drain=caster->query_level()/6;
         if(drain>18)
            drain=18;
         break;
      case "minor":
         drain=caster->query_level()/8;
         if(drain>18)
            drain=18;
         break;
      default:
         drain=0;
         break;
   }
   caster->add_timed_property("energy_drained",1,1000);
   if(target->query_tmp_str()>=0)
   {
      if(drain>target->query_str()-3)
         target->adjust_tmp_str(-target->query_str()-3);
      else
         target->adjust_tmp_str(-drain);
      return 0;
   }
   if(target->query_tmp_dex()>=0)
   {
      if(drain>target->query_dex()-3)
         target->adjust_tmp_dex(-target->query_dex()-3);
      else
         target->adjust_tmp_dex(-drain);
      return 0;
   }
   if(target->query_tmp_con()>=0)
   {
      if(drain>target->query_con()-3)
         target->adjust_tmp_con(-target->query_con()-3);
      else
         target->adjust_tmp_con(-drain);
      return 0;
   }
   if(target->query_tmp_int()>=0)
   {
      if(drain>target->query_int()-3)
         target->adjust_tmp_int(-target->query_int()-3);
      else
         target->adjust_tmp_int(-drain);
      return 0;
   }
   if(target->query_tmp_wis()>=0)
   {
      if(caster->query_guild_name()!="taniwha"&&
         caster->query_guild_name()!="Grimbrand"&&
         caster->query_guild_name()!="timion"&&
         caster->query_guild_name()!="virga"&&
         caster->query_guild_name()!="Cyrcia"&&
         caster->query_guild_name()!="hokemj")
      {
         if(drain>target->query_wis()-3)
            target->adjust_tmp_wis(-target->query_wis()-3);
         else
            target->adjust_tmp_wis(-drain);
         return 0;
      }
   }
   if(target->query_tmp_cha()>=0)
   {
      if(drain>target->query_cha()-3)
         target->adjust_tmp_cha(-target->query_cha()-3);
      else
         target->adjust_tmp_cha(-drain);
      return 0;
   }
}
