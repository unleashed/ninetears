#define BASESTAT 15

#define CHARISMA_SAVE 12
int bard_fix_damage(object caster,object victim,int damage,string type);

int wiz_fix_damage(object caster,object victim,int damage,string type)
{
   if(caster->query_guild_name() == "bard") return bard_fix_damage(caster,victim,damage,type);
   damage = (damage * (int)caster->query_int())/BASESTAT;
   damage = (damage * (100-(int)victim->query_property(type)))/100;
   // LUCK! Taniwha 1995
   if((damage < 0) && (random(victim->query_cha()) > CHARISMA_SAVE)) damage = damage / 2;
   return damage;
}
int bard_fix_damage(object caster,object victim,int damage,string type)
{
   damage = (damage * (int)caster->query_cha())/BASESTAT;
   damage = (damage * (100-(int)victim->query_property(type)))/100;
   // LUCK! Taniwha 1995
   if((damage < 0) && (random(victim->query_cha()) > CHARISMA_SAVE)) damage = damage / 2;
   return damage;
}
int cleric_fix_damage(object caster,object victim,int damage,string type)
{
   int align;
   if((string)caster->query_guild_name() == "paladin")
   {
       align = (int)victim->query_align();
       /* harm good */
       if((damage < 0) && (align < 0)) return 0;
       /* heal evil */
       if((damage > 0) && (align > 0)) return 0;
   }
   if((string)caster->query_guild_name() == "antipaladin")
   {
       align = (int)victim->query_align();
       /* harm evil */
       if((damage < 0) && (align > 0)) return 0;
       /* heal good */
       if((damage > 0) && (align < 0)) return 0;
   }
   damage = (damage * (int)caster->query_wis())/BASESTAT;
   damage = (damage * (100-(int)victim->query_property(type)))/100;
   // LUCK! Taniwha 1995
   if((damage < 0) && (random(victim->query_cha()) > CHARISMA_SAVE)) damage = damage / 2;
   return damage;
}
mixed find_unique_match(string find,mixed inx)
{
mixed *olist;
   int i,j;
   olist = find_match(find,inx);
   for(i = 0; i < sizeof(olist); i++)
   {
      for(j = sizeof(olist)-1; j > i; j--)
      {
         if(olist[j] == olist[i]) olist = delete(olist,j,1);
      }
   }
   return olist;
}
mixed find_one_match(string find,mixed inx)
{
mixed *olist;
   int i,j;
   olist = find_match(find,inx);
   if ( sizeof(olist) < 1 )
      return 0;
   else
      return olist[0];
}
/* Checks if ob is the correct alignment for doing whatever they're doing */
int wrong_alignment(object ob)
{
  switch( (string)ob->query_guild_name() )
  {
    case "paladin":
      if ( (int)ob->query_align() > 0 )
        return 1;
      break;
    case "antipaladin":
      if ( (int)ob->query_align() < 0 )
        return 1;
      break;
    default:
      break;
  }
  
  return 0;
}
/* For (good)naughty (anti-)paladins who try to use their abilities */
int punish_align(object ob)
{
  tell_object(ob, "Thou dost feel disgracefully impure, and feel a loss "
    "of thy confidence.\n");
  ob->set_xp(0);
  return 1;
}
/* For 'touch' spells, protectors need to be taken into account. */
object check_melee_protector(object victim, object doer)
{
  object prot;
  if ( (prot=victim->query_protector() ) &&
     environment(prot) == environment(victim) &&
     prot->query_protect_valid(doer, victim) )
  {
    tell_object(prot, "You protect "+victim->query_cap_name()+" from the attack.\n");
    tell_object(victim, prot->query_cap_name()+" valiantly protects you.\n");
    tell_object(doer, prot->query_cap_name()+" jumps in the way of your target and "
      "takes the brunt of your attack!\n");
    tell_room(environment(victim), prot->query_cap_name()+" valiantly protects "
      +victim->query_cap_name()+" from "+doer->query_cap_name()+".\n",
      ({ doer, victim, prot }) );
    return prot;
  }
  return victim;
}

