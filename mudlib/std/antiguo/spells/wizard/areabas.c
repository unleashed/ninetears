/*** Made an inheritable base file Taniwha 1995 ***/
/*** ->base spell, wonderflug ***/

string SP_NAME = "fireball";
int GP_COST = 6;
string TYPE = "fire";
int SIZE_OF_DICE =  6;
string save_type = "fire";
int ADJ_COST;
int maxlevel = 10;
string chant_message = "Majos areos pyros";

inherit "/std/spells/base.c";

void setup()
{
  set_spell_name(SP_NAME);
  set_spell_level(3);
  set_sphere("invocation");

  set_target_type("many");
  set_range(0);

  set_help_desc("This spell envelopes a group of enemies in "+TYPE+
    "The damage caused is equal to the level of the caster *"+
    SIZE_OF_DICE+", with a maximum at level "+maxlevel+".");

  set_gp_cost(GP_COST);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int damage;
  string str;
  int NO_OF_DICE;
  int j;
  int i;

  NO_OF_DICE = caster->query_level();
  if(NO_OF_DICE == 0)
    NO_OF_DICE = 1;
  if (NO_OF_DICE > 10)
    NO_OF_DICE = 10;
  
  str = (string)caster->query_cap_name();
  if((i = member_array(caster, target)) != -1)
    target = delete(target, i, 1);
  
  if(!sizeof(target))
  {
    tell_object(caster, "There is noone here by that name.\n");
    return -1;
  }
   
  if ( !quiet )
  {
    tell_room(environment(caster),
      str + " chants \""+chant_message+"\".\n", caster);
    tell_object(caster, "You chant \""+chant_message+"\".\n");
  }
  
  for ( i=0; i<sizeof(target); i++ )
    if(target[i])
    {
      target[i]->attack_by(caster);
      damage = roll(NO_OF_DICE, SIZE_OF_DICE);
      damage = wiz_fix_damage(caster,target[i],damage,save_type);
      target[i]->spell_damage(target[i],damage,TYPE,caster);
      tell_object(target[i], str + " envelopes you with a "+SP_NAME+"!\n");
      tell_room(environment(target[i]), target[i]->query_cap_name()+
        " is enveloped in a "+SP_NAME+"!\n", target[i]);
    }
  
  if ( sizeof(out_range) )
    tell_object(caster, "Alas, "+query_multiple_short(out_range)+
      " got away.\n");
 
  return 0;
}


