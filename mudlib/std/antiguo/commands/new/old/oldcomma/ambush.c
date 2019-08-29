#include "tweaks.h"

#define LOCK_PROP "ambushing"

/** Ambush.c by Taniwha, with a spot of help from Ilmryn. **/
/** This is a very nasty attack command, designed for the Assassin's guild
    ONLY.  It is made pretty nasty because Assassins are killers, and they 
    are supposed to kill in one shot.  Since we can't do anything that nasty
    here, we decieded on a high damage command that does it's damage with a 
    single attack.  It maybe attempted with any weapon, and the damage is 
    level of the user, divided by 2, times the damage roll of the weapon 
    , and all of this randomized.  The damage multiplier stops going up at
    level 20, for a max multiplier of 10.  While testing it at level 10 the
    damage ranged from 15-30, and at level 30 the damage was around 50.  This
    was ALL well below the damage capable of being done by a wizard of equal
    or lower level.  Also of note is the fact that if the user is listed in
    the attacking list then they suffer damage.  Even if they have stopped,
    but are being hunted by a monster or character for 3 screens ago, they
    get damaged, and obviously fail the ambush.  This should be more than
    adequate balancing for the capabilities of this command.  ****/



static int already_attacking(object me,object victim)
{
int i;
   object *list;
   list = (object *)me->query_attacker_list();
   if(sizeof(list)) return 1;
   list = (object *)victim->query_attacker_list();
   for(i = 0; i < sizeof(list); i++)
   {
      if(list[i] == me ) return 1;
   }
   return 0;
}
int ambush_damage(object weapon,object me,object victim)
{
   int lvl;
   int dam;
   dam = (int)weapon->query_damage_roll()+ (int)me->query_damage_bonus();
   lvl = (int)me->query_level();
// tell_object(me,"Weapon damage is "+dam+"\n");
// Removed the level limit, choped it at assasins hp instead
   lvl = lvl/2 +1;
   dam = 1+(random(dam*lvl))/1;
   dam = dam > me->query_hp() ? me->query_hp() : dam;
   dam = dam < lvl ? lvl : dam;
   if(dam > (int)victim->query_max_hp() ) dam = (int)victim->query_max_hp()+1;
   return dam;
}
int ambush(string str,object x) {
   int skill,s1,i;
   int gp_cost;
   int damage;
   object me;
  object aweap;
   object *weap;
   object *vlist;
   object victim;

   if(x) me = x;  
   else me = this_player();
   if (!str)
   {
     	tell_object(me,"You are you trying to ambush?\n");
        return 1;
   }
/*
   // Old test when some thieves had ambush
   if(interactive(me && ((string)me->query_guild_name() != "assassin")
   {
      tell_object(me,("Ambush is for assassins, you are not that, so the command is hereby removed from you.\n");
      me->remove_known_command("ambush");
   }
   return 1;
*/
  weap = (object *)me->query_held_ob();
  if ( weap[0] ) aweap=weap[0];
  else if ( weap[1] ) aweap=weap[1];
  else aweap=0;
   vlist = find_match(str,environment(me));
   if(!sizeof(vlist))
   {
	tell_object(me,"Fantasizing about ambushing someone?  Try someone that is here.\n");
        return 1;
   }
   victim = vlist[0];
   if(victim == me)
   {
      tell_object(me,"Ambushing yourself? that's bright.\n");
      return 1;
   }
   if(victim->query_property("dead"))
   {
      tell_object(me,"Attacking up a ghost ?.\n");
      return 1;
   }
   gp_cost =  (int)me->query_level() * 2;
   if(gp_cost > 50) gp_cost = 50;
   if((int)me->adjust_gp(-gp_cost) == -1)
   {
      tell_object(me,"You don't have enough energy to ambush! Try again later.\n");
       return 1;
   }
  if ( weap[0] && weap[1] )
   {
     tell_object(me,"You try to make your ambush with weapons all wrong for the "
        "job, and you screw it up severely.\n");
     victim->attack_by(me);
     return 1;
   }
  if (!aweap)
   {
      tell_object(me,"Ambush with what?\n");
      return 1;
   }
   if(me->query_property(LOCK_PROP))
   {
      tell_object(me,"You don't feel calm enough to ambush.\n");
      victim->attack_by(me); /* I MAY remove this later */
      return 1;
   }
   me->add_timed_property(LOCK_PROP,100,AMBUSH_LOCKOUT);
   damage = ambush_damage(aweap,me,victim);
   if( (int)victim->query_property("sense_life"))
   {
      tell_object(me,"Your intended victim seems to have spotted you readying your weapons, perhaps running may be a good idea. ?\n");
       tell_object(victim,"You spot "+me->query_cap_name()+" eyeing you speculatively.\nYou ready your weapons and attack in a burst of fury!\n");
      victim->attack_by(me);
      return  1;
   }
   if(already_attacking(me,victim))
   {
      tell_object(me,"Ooops "+(string)victim->query_cap_name()+
	" sees you coming, and turns in time to land a solid blow on you first.\n");
      tell_object(victim," "+(string)me->query_cap_name()+
	" suddenly makes a strange move, and then leaps at you.  You manage "
	"to spin around in time and land a vicious blow on them.\n");
	me->adjust_hp(-damage/2, victim);
   }
   else
   {
      victim->adjust_hp(-damage, me);
      tell_object(victim,(string)me->query_cap_name()+" hits you "
	"totally unexpectedly with a vicious blow.\n");
      tell_object(me,"You catch "+(string)victim->query_cap_name()+
	" flat footed with your ambush "
        "\n");
   }
   victim->attack_by(me);
   return 1;
}

string help(string str) {
  return
"Syntax: ambush <person>\n\n"
"Ambush is a nastier version of the backstab command.  It takes into account "
"the assassin's detailed knowledge of the body, and of the art of killing.  "
"Combining this with the element of surprise, it is deadly.  But because it "
"takes total concentration, you must be at absolute peace with yourself to "
"succeed, if not your opponent will most likely see you coming, and turn your "
"attack back upon you.\n";
}
