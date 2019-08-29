

/*** Bash Command ***/
/*** Created by Taniwha, June '96 ***/
/*** For Battleragers ***/

/* This looks a lot like a spell underneath, hmm, probably because
 * I hacked a spell apart to make it. :) (c) Flug
 * Me too (c) Taniwha
 */

#define SP_NAME "Bash"
#define SPELLTYPE "Rager"
#define GP_COST 8
#define BASE_RECOVER 10
#define PW_STUN_SHADOW "/d/gremios/comandos/shadows/stun.c"

inherit "/d/gremios/hechizos/patch.c";

string * saveraces = ({ "dwarf","duergar","goblin","halfling","half-elf" });
string * bonusraces = ({ "orc","lizardman","dragon","giant","troll" });
string * bonus_items = ({ "Spiked Platemail","Spiked Helm" });
 /*** help file ***/
string help() {
  return
       "\n\n"
       "Command Name: "+SP_NAME+"\n"
       "Gp Cost: "+GP_COST+"\n"
       "Syntax: bash <target>\n"
       "Description: \n"
       "    This ability lets an irate Duergar rager charge into combat "
       "against a single opponent. "
       "If successful the Duergar will headbutt the victim somewhere in "
       "the vicinity of the beltline, leaving the opponent "
       "severely discomforted for some time. "
       "Note that this command works best against larger opponents, "
       "and being appropriately beweaponed and armoured is advised. "
       "\n\n";
}

mixed spell(string str, object caster);
object get_one_weapon(object me);
void end_charge(object me);

int bash(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  if(cast) caster = cast;
  else caster= this_player();


  if(interactive(caster))
          str = (string)caster->expand_nickname(str);


  ret = spell(str, caster);
  if (stringp(ret) || !objectp(ret) )
  {
      notify_fail(ret);
      return 0;
  }

  tell_object(caster,"You line up your opponent, mentally drawing a couple "
  "of lines between shoulders and toes, and yell the traditional "
  "fear inducing challenge.\n");
  tell_room(environment(caster),caster->query_cap_name()+" shouts:  "
    "DEEDAH DEEDAH DEEDAH DEEDAH !", ({  caster, ret }) );
  tell_object(ret, caster->query_cap_name()+" draws a bead on you "
    "and hurtles head first towards your groin, yelling something "
    "traditionally dwarven.\n");

  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;
  object *weap;
  int bonus,i;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "No way, you are still concussed from the last effort.\n";

  ob = find_one_match(str, environment(caster));
  if ( !ob || ob->query_dead() )
    return "Find something alive.\n";

  if ( ob == caster )
    return "Tricky, really tricky, only elves are flexible or kinky enough to try that!\n";

  if ((int)caster->query_gp() < GP_COST )
    return "The spirit may be willing, but the flesh has had enough for a while.\n";
  else caster->adjust_gp(GP_COST);

  weap = caster->query_weapons_wielded();
  for(i = 0; i < sizeof(weap); i++)
  {
    if(weap[i] &&   weap[i]->query_weapon_type() == "battle axe" )
    {
        bonus ++;
    }
  }
  weap = caster->query_worn_ob();
  for(i = 0; i < sizeof(weap); i++)
  {
     if(weap[i] && member_array(weap[i]->query_name(), bonus_items) > 0)
     {
        bonus ++;
     }
  }

  caster->add_spell_effect(1, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ ob,bonus }));

  return ob;
}

int hb_spell(object me, mixed *params, int time)
{
  int i,mybonus,hisbonus,j;
  object shad;
  int bonus = params[1];
  object him = params[0];
  object *weap;

  if ( me->query_property("noguild") )
  {
    tell_object(me, "You cannot seem to continue your bash right now.\n");
    return 1;
  }
  if ( !him || environment(me) != environment(him) )
  {
     tell_object(me, "Your target saw you coming and legged it!\n");
     return 1;
  }
  mybonus = me->query_level()+me->query_str() + bonus;
  hisbonus = him->query_level()+him->query_dex();
  if(member_array((string)him->query_race(),saveraces) >= 0 ) hisbonus *= 10;
  if(member_array((string)him->query_race(),bonusraces) >= 0) hisbonus /= 10;

  hisbonus *= (100 - (int)him->query_ac() );
  mybonus *= ( 200 - (int)me->query_thac0() );

  if( random(mybonus) > random(hisbonus) )
  {
       j = bonus + random(5);
       tell_object(me,"YES, a good hit, !.\n"+him->query_cap_name()+" falls to the floor in agony.\n");
       tell_room(environment(me), me->query_cap_name()+" headbutts "+
        him->query_cap_name()+" somewhere around the beltline and "+
        him->query_cap_name()+" falls over writhing in agony.\n",({ him,me }),({ me,him}) );
       tell_object(him, "A maddened Duergar headbutts you "
        "just below the belt. IT HURTS!!!!!!!!!!!!!!!!! \n");


       him->add_timed_property("stun_on", 1, j);
       him->add_timed_property("nocast",1, j);
       him->add_timed_property("noguild",1, j);
       him->add_timed_property("passed out",
        "You are still rolling round on the floor recovering from the headbutt, and can't do anything.\n",j);
       shad = clone_object(PW_STUN_SHADOW);
       shad->setup_shadow(him, j);
       him->add_extra_look(shad);

   }
   else
   {
        tell_object(me,"Alas you miss, pity really.\n");
        tell_room(environment(me),me->query_cap_name()+" totally misses his headbutt.\n",({me,him}) );
        tell_object(him,me->query_cap_name()+" just misses you, but scares the hell out of you anyway.\n");
    }
    him->attack_by(me);
    return 1;
}



