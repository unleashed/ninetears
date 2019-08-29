inherit "/std/spells/base.c";
void setup()
{
   set_spell_name("Restauracion");
   set_spell_level(7);
   set_sphere("alteracion");
   set_target_type("one");
   set_range(0);
   set_help_desc(
      "Cuando este hechizo se formula, todas las caracteristicas del objetivo "
      "volveran a su estado normal.\n");
      
   set_gp_cost(14);
   set_casting_time(2);
   set_rounds(({"round1","round2"}));
}
int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
   tell_object(caster,"Comienzas a invocar el poder de "+capitalize(caster->query_deity())+
      ".\n");
   tell_room(environment(caster),caster->query_cap_name()+" parece "
      "estar rezando a alguien.\n",caster);
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
         "Tu hechizo falla ... no hay nadie aqui con ese nombre.\n");
      return -1;
   }
   if(target==caster)
   {
      tell_object(caster,"No puedes formular este hechizo sobre ti mismo.\n");
      return -1;
   }
   if(target->query_deity()!=caster->query_deity())
   {
      tell_object(caster,target->query_cap_name()+" no sigue "
         "al mismo Dios que tu. No puedes restaurarle sus caracteristicas.\n");
      return -1;
   }
   if(!quiet)
   {
      tell_object(caster,"Creas un foco de energia positivo para formular el hechizo.\n");
      tell_object(caster,"Tocas a "+target->query_cap_name()+
         " envolviendolo con tu energia.\n");
      tell_object(target,caster->query_cap_name()+" te toca "
         "con su energia positiva provocando la restauracion de tus habilidades.\n");
      tell_room(environment(caster),caster->query_cap_name()+
         " toca a "+target->query_cap_name()+" transmitiendole todo su vigor.\n",
         ({caster,target}));
   }
   switch(caster->query_sphere_level("curadora"))
   {
      case "mayor":
         rest=caster->query_level()/4;
         if(rest>18)
            rest=18;
         break;
      case "neutral":
         rest=caster->query_level()/6;
         if(rest>18)
            rest=18;
         break;
      case "menor":
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
      if(caster->query_guild_name()!="Clerigo de Yvendur")
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
