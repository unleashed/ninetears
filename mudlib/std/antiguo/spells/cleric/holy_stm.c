
/*** Holy Storm Spell ***/
/*** Coded by:  Taniwha ***/
/* Adapted to base spell Wonderflug 96 */
#define TYPE "magical"
#define SIZE_OF_DICE 6
#define save_type "magical"
inherit "/std/spells/base.c";

string *badguys = ({ "Cyrcia","Grimbrand" });
int round1(object caster, mixed target, mixed out_range, int time, int quiet,int al);

void setup()
{
  set_spell_name("Holy Storm");
  set_spell_level(7);
  set_school("healing");
  set_target_type("all");
  set_range(2);
  set_line_of_sight_needed(0);
  set_help_extras(
    "Damage Type: " TYPE "\n"
    "WARNING: Alignment dependent damage\n"
    "Saving Throw: None");
  set_help_desc("This spell will summon a storm of magic. "
    "All living objects in range will be affected .");
  set_gp_cost(10);
  set_casting_time(3);
  set_rounds( ({ "round0","round0","round0" }) );
}
int round0(object caster, mixed target, mixed out_range, int time, int quiet)
{
    if(member_array((string)caster->query_guild_name(),badguys) >= 0)
        round1(caster,target,out_range,time,quiet,1);
    else
        round1(caster,target,out_range,time,quiet,-1);

}
int round1(object caster, mixed target, mixed out_range, int time, int quiet,int al)
{
  int damage;
  int i,j,dice;
  string str;

  if(!sizeof(target)) 
  {
    tell_object(caster, "There is noone here by that name.\n");
    return -1;
  }

  dice = SIZE_OF_DICE;
  // Only offensive spell they get :)
  if(caster->query_guild_name() == "hokemj") dice += random((int)caster->query_cha()/3);


  if ( !quiet && !time )
  {
    tell_room(environment(caster), caster->query_cap_name()
      + " chants, 'Deus Ire'.\n", ({caster,target}));
    tell_object(caster, "You chant, 'Deus Ire'.\n");
  }
  
  for ( i=sizeof(target)-1; i>=0; i-- )
  {
    j = al * target[i]->query_align();
    if(j < 100 )
    {
        target[i]->attack_by(caster);
        damage = roll(3, dice);
        damage = cleric_fix_damage(caster,target[i],damage,save_type);
        target[i]->spell_damage(target[i],damage,TYPE,caster);
        tell_object(target[i], "A storm of magic blasts you!.\n");
        if(!target[i])
            target = delete(target, i, 1);
    }
    else if( j > 100)
    {
        damage = -(roll(1, dice));
        damage = cleric_fix_damage(caster,target[i],damage,save_type);
        target[i]->spell_damage(target[i],damage,TYPE,caster);
        tell_object(target[i], "Magic blasts and heals you!.\n");
    }
    else tell_object(target[i],"A Magic storm rages around you, but you are strangely unaffected.\n");
  }
  tell_room(environment(caster), caster->query_cap_name() + 
    " envelopes "+(str = query_multiple_short(target))+
    " within a storm of magic!\n", ({caster,target}));
  tell_object(caster, "You envelope " + str + " in a Holy Storm!\n");
  return 0;
}



