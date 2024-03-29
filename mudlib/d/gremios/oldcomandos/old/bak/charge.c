/*** Charge Command ***/
/*** Created by Wonderflug, June '95 ***/
/*** For Paladins and Anti-Paladins ***/

/* This looks a lot like a spell underneath, hmm, probably because 
 * I hacked a spell apart to make it. :)
 */

#define SP_NAME "Charge"
#define SPELLTYPE "knight"
#define CHARGE_START_GP 2
#define CHARGE_WARCRY_GP 1
#define CHARGE_HIT_GP 5
#define CHARGE_WEAP_GP 5
#define CHARGE_UNARMED_GP 5
#define BASE_RECOVER 10

inherit "/d/gremios/hechizos/patch.c";

/* find_unique_match() does a find match that ensures the returned
	object list contains no duplicates
	find_one_match() returns only the first matched object
*/
mixed find_unique_match(string find,mixed in);
mixed find_one_match(string find,mixed in);

 /*** help file ***/
string help() {
  return
       "\n\n"
       "Command Name: "+SP_NAME+"\n"
       "Gp Cost: Up to 18\n"
     "Syntax: charge <target>\n"
       "Description: \n"
       "    This ability lets a knight charge into combat against a single "
       "opponent.  A knight's charge is a grand thing, full of challenges "
       "and warcries, culminating in a massive series of blows attempting "
       "to drive the opponent into submission.  This usually leaves the "
       "knight winded and unable to charge again for several minutes.\n\n";
}

mixed spell(string str, object caster);
object get_one_weapon(object me);
void end_charge(object me);

int charge(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  if(cast) caster = cast;
  else caster= this_player();

  if(interactive(caster))
	  str = (string)caster->expand_nickname(str);

  if ( wrong_alignment(caster))
    return punish_align(caster);
  ret = spell(str, caster);
  if (stringp(ret) || !objectp(ret) )
  {
	 notify_fail(ret);
	 return 0;
  }

  tell_object(caster,"You bellow out thy challenges to the cravenly "+
    ret->query_cap_name()+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" bellows "
    "out a challenge to "+ret->query_cap_name()+".\n", ({  caster, ret }) );
  tell_object(ret, caster->query_cap_name()+" bellows out a challenge "
    "to you, calling your family very nasty names.\n");

  ret->attack_by(caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;
  object weap;
  int damage_bonus;
  int recover_time;
  int total_time;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "Mighty though thou art, only the Gods Themselves couldst "
      "attempt yet another charge at such a time as it be.\n";
  
  ob = find_one_match(str, environment(caster));
  if (!sizeof(ob) || !ob->query_living() )
    return "Begging thine pardon, but mayhap trying a worthy foe NEARBY "
      "would be to a higher purpose, Sir Knight.\n";
  else ob=ob[0];

  if ( ob == caster )
    return "Milord!  Suicide be but for the most craven cowards!\n";
 
  if ((int)caster->query_gp() < CHARGE_START_GP )
    return "Thy bones cry out with weariness at the merest thought "
      "of performing thine mighty charge.\n";
  else caster->adjust_gp(-CHARGE_START_GP);

  damage_bonus = (int)caster->query_level()/3 + 2;
  recover_time = BASE_RECOVER - (int)caster->query_level()/2;
  total_time = recover_time + 5;

  caster->add_spell_effect(total_time, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ total_time,ob,damage_bonus }));

  return ob;
}

int hb_spell(object me, mixed *params, int time)
{
  int i;
  int damage;
  int total_time = params[0];
  int damage_bonus = params[2];
  object him = params[1];
  object* weap;

  switch( total_time - time )
  {
    case 0:
      if ( !him || environment(me) != environment(him) )
      {
        tell_object(me, "Thy target hast played the coward and run off!\n");
        call_out("end_charge",0,me);
        return 1;
      }
      if ( (int)me->query_gp() < CHARGE_WARCRY_GP ) 
      { 
        tell_object(me, "Thou hast grown too weary from issuing thine " 
          "challenge to continue thy charge.\n"); 
        tell_room(environment(me), me->query_cap_name()+" tries to " 
          "shout something else but nothing comes out but a squeak.\n", me); 
        call_out("end_charge",0,me); 
        return 1;
      }  
      else me->adjust_gp(-CHARGE_WARCRY_GP);

      tell_object(him, me->query_cap_name()+" shouts some deafening "
        "nonsense as "+me->query_pronoun()+" charges at you!\n");
      tell_object(me, "You shout a deafening warcry as you begin "
        "thine charge.\n");
      tell_room(environment(me),  me->query_cap_name()+" shouts "
        " deafeningly as "+me->query_pronoun()+" charges toward "+
        him->query_cap_name()+".\n", ({ me, him }) );
      return 1;

    case 1:
      if ( !him || environment(me) != environment(him) )
      {  
        tell_object(me, "Thy target hast played the coward and run off!\n"); 
        call_out("end_charge",0,me); 
        return 1; 
      }  

      if ( (int)me->query_gp() < CHARGE_HIT_GP ) 
      { 
        tell_object(me, "Thou hast grown too weary from issuing thine " 
          "warcry to continue thy charge.\n"); 
        tell_object(him, me->query_cap_name()+" charges at you but "
          "seems to tire out before reaching you.\n");
        tell_room(environment(me), me->query_cap_name()+" charges at "+ 
          him->query_cap_name()+" but seems to tire out and stops.\n",
          ({ me, him }) );
        call_out("end_charge",0,me); 
        return 1;
      }  
      else me->adjust_gp(-CHARGE_WARCRY_GP);

      if ( random(20) < -damage_bonus + 
           (int)me->query_thac0() + (int)him->query_body_ac() )
      {
        tell_object(me, "The vile cur dodges out of thine way and you "
          "miss thine charge!\n");
        tell_object(him, "You dodge out of the way of "+me->query_cap_name()+
          "'s charge.\n");
        tell_room(environment(me), me->query_cap_name()+" charges at "+
          him->query_cap_name()+" but misses.\n", ({ me, him }) );
        call_out("end_charge",0,me);
        return 1;
      }
      tell_object(me, "You crash into "+him->query_cap_name()+" with a "
        "magnificent crunch of bones and armour!\n");
      tell_object(him, me->query_cap_name()+" crashes into you with a "
        "painful crunch of bones and armour!\n");
      tell_room(environment(me), me->query_cap_name()+" crashes into "+
        him->query_cap_name()+" with a sickening crunch of bones and "
        "armour!\n", ({ me, him }) );
      damage = 0;
      damage = random((int)me->query_level()) + damage_bonus;
      him->adjust_hp(-damage,me);
      return 1;

    case 2:
      if ( !him || environment(me) != environment(him) )
      {  
        tell_object(me, "Thy target hast played the coward and run off!\n"); 
        return 1; 
      }  
      weap = get_one_weapon(me);
      if (!weap) return 0;
      if ( (int)me->query_gp() < CHARGE_WEAP_GP )  
      {  
        tell_object(me, "Thou art too weary to smite thine opponent with "
          "thy weapon.\n");  
        tell_object(him, me->query_cap_name()+" lowers "+
          me->query_possessive()+" weapon tiredly, thankfully not on "
          "your head.\n");
        tell_room(environment(me), me->query_cap_name()+" looks tiredly at "+ 
          him->query_cap_name()+" and lowers "+me->query_possessive()+
          " weapon regretfully.\n",
          ({ me, him }) );   
      /* don't end_charge, just let the next ones fail out too */
        return 1;
      }   
      else me->adjust_gp(-CHARGE_WEAP_GP);

      if ( random(20) < -damage_bonus +
           (int)me->query_thac0() + (int)him->query_body_ac() )
      {
        tell_object(me, "You bring thy weapon down to smite "+
          him->query_cap_name()+" but miss!\n");
        tell_object(him, "You barely dodge out of the way of "
          "a crushing blow from "+me->query_cap_name()+".\n");
        tell_room(environment(me), me->query_cap_name()+" barely "
          "dodges a huge blow from "+him->query_cap_name()+".\n",
          ({ me, him }) );
        call_out("end_charge",0,me);
        return 1;
      }

      tell_object(me, "You bring thy weapon down and decimate the heathen "+
        him->query_cap_name()+"!\n");
      tell_object(him, me->query_cap_name()+" brings "+me->query_possessive()+
        " weapon down on you in a crushing blow!\n");
      tell_room(environment(me), me->query_cap_name()+" delivers a "
        "crushing blow to "+him->query_cap_name()+"!\n", ({ him, me }) );
      damage = 0;
      damage = weap->query_damage_roll();
      damage *= ((int)me->query_level()/10 + 1);
      damage += damage_bonus;
      him->adjust_hp(-damage,me);
      return 1;

    case 3:
      if ( !him || environment(me) != environment(him) )
      {  
        tell_object(me, "Thy target hast played the coward and run off!\n"); 
        return 1; 
      }  
      if ( (int)me->query_gp() < CHARGE_UNARMED_GP )  
      {  
        return 0;
      }   
      else me->adjust_gp(-CHARGE_UNARMED_GP);

      tell_object(me, "You deliver a few close blows as you get up from "
        "your charge.\n");
      tell_object(him, me->query_cap_name()+" smacks you as "+
        me->query_pronoun()+" finishes the charge.\n");
      tell_room(environment(me), me->query_cap_name()+" smacks "+
        him->query_cap_name()+" as "+me->query_pronoun()+" backs off "
        "after the charge.\n", ({ me, him }) );
      for (i=0;i<(int)me->query_level()/10+1;i++)
        me->unarmed_attack(him, me);
      return 1;

    default:
      return 0;
  }
 
  return 1;

}

void end_charge(object me)
{
  me->remove_spell_effect(SP_NAME);
}

object get_one_weapon(object me)
{
  object* ob = me->query_held_ob();
  if (ob[0]) return ob[0];
  else if (ob[1]) return ob[1];
  else return 0;
}
