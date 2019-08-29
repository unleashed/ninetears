inherit "/std/spells/base.c";
void setup()
{
   set_spell_name("Restoration");
   set_spell_level(7);
   set_sphere("healing");
   set_target_type("one");
   set_range(0);
   set_help_desc(
      "When this spell is cast, all skills of the recipient that have "
      "been reduced by some method or another are raised to or close to "
      "normal."
      );
   set_gp_cost(14);
   set_casting_time(2);
   set_rounds(({"round1","round2"}));
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
   tell_object(caster,"You begin to pray to "+capitalize(caster->query_deity())+
      ".\n");
   tell_room(environment(caster),caster->query_cap_name()+" seems to be "
      "praying to someone.\n",caster);
   return 0;
}
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
   int rest;
   int stat;
   int adj;
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
   if(target->query_deity()!=caster->query_deity())
   {
      tell_object(caster,target->query_cap_name()+" does not follow "
         "the same deity that you do.  You can't restore "+
         target->query_objective()+".\n");
      return -1;
   }
   if(!quiet)
   {
      tell_object(caster,"You focus possitive energy to cast the spell.\n");
      tell_object(caster,"You touch "+target->query_cap_name()+
         " infusing "+target->query_objective()+" with the energy.\n");
      tell_object(target,caster->query_cap_name()+" touches you, "
         "causing you to feel invigorated.\n");
      tell_room(environment(caster),caster->query_cap_name()+
         " touches "+target->query_cap_name()+" causing "+
         target->query_cap_name()+" to look invigorated.\n",
         ({caster,target}));
   }
   switch(caster->query_sphere_level("healing"))
   {
      case "major":
         rest=caster->query_level()/4;
         if(rest>18)
            rest=18;
         break;
      case "neutral":
         rest=caster->query_level()/6;
         if(rest>18)
            rest=18;
         break;
      case "minor":
         rest=caster->query_level()/8;
         if(rest>18)
            rest=18;
         break;
      default:
         rest=0;
         break;
   }
   if(target->query_tmp_str()<0)
   {
      if(rest>-target->query_tmp_str())
         target->adjust_tmp_str(-target->query_tmp_str());
      else
         target->adjust_tmp_str(rest);
      return 0;
   }
   if(target->query_tmp_dex()<0)
   {
      if(rest>-target->query_tmp_dex())
         target->adjust_tmp_dex(-target->query_tmp_dex());
      else
         target->adjust_tmp_dex(rest);
      return 0;
   }
   if(target->query_tmp_con()<0)
   {
      if(rest>-target->query_tmp_con())
         target->adjust_tmp_con(-target->query_tmp_con());
      else
         target->adjust_tmp_con(rest);
      return 0;
   }
   if(target->query_tmp_int()<0)
   {
      if(rest>-target->query_tmp_int())
         target->adjust_tmp_int(-target->query_tmp_int());
      else
         target->adjust_tmp_int(rest);
      return 0;
   }
   if(target->query_tmp_wis()<0)
   {
      if(caster->query_guild_name()!="taniwha"&&
         caster->query_guild_name()!="Grimbrand"&&
         caster->query_guild_name()!="timion"&&
         caster->query_guild_name()!="virga"&&
         caster->query_guild_name()!="Cyrcia"&&
         caster->query_guild_name()!="hokemj")
      {
         if(rest>-target->query_tmp_wis())
            target->adjust_tmp_wis(-target->query_tmp_wis());
         else
            target->adjust_tmp_wis(rest);
         return 0;
      }
   }
   if(target->query_tmp_cha()<0)
   {
      if(rest>-target->query_tmp_cha())
         target->adjust_tmp_cha(-target->query_tmp_cha());
      else
         target->adjust_tmp_cha(rest);
      return 0;
   }
}
