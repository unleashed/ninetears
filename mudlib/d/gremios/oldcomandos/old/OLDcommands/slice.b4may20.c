
#include "/d/gremios/comandos/tweaks.h"
/* Slice Taniwha 1995
 * An attack specific to drow warriors, since it can be used while IN combat
 * it should do less than backstab or slice
 * It is based on level AND dexterity
 * The number of extra attacks are (DEX / 9)* 3
 * at this stage
 * Frequency of use is (SLICE_LOCKOUT - level)  (SLICE_LOCKOUT noninally 40)
 * Cost is 1 GP/level
 * Use it too soon and you drop your weapons
 */


int slice(string str, object doer) {
   int skill,s1,i;
   int j;
   int damage;
   int bonus;
   object me;
   object *weap;
   object *vlist;
   object victim;

   me = doer ? doer : this_player();
   if (!str)
   {
      notify_fail("You are you trying to slice?\n");
      return 0;
   }

   weap = (object *)me->query_weapons_wielded();
   vlist = find_match(str, environment(me));
   if(!sizeof(vlist))
   {
      notify_fail("Fantasizing about sliceing someone?  Try someone that is here.\n");
      return 0;
   }

   victim = vlist[0];
   if(victim->query_property("dead"))
   {
      tell_object(me,"Attacking up a ghost ?.\n");
      return 1;
   }
   if(victim->query_property("pacify_on"))
   {
      tell_object(me,"Nah, this ones way too harmless to attack ?.\n");
      return 1;
   }
   if(victim == me)
   {
      notify_fail("Slicing yourself? that's bright.\n");
      return 0;
   }
   if(me->query_property("slicing"))
   {
      tell_object(me,"You do not have the skill to slice your opponent so soon.\n");
      return 1;
   }
   me->add_timed_property("slicing",1,(SLICE_LOCKOUT - (int)me->query_level())/2);
   if((int)me->adjust_gp(-SLICE_COST) == -1)
   {
	tell_object(me,"You don't have enough energy to slice!  Try again later.\n");
      return 1;
   }
   if(!sizeof(weap))
   {
      tell_object(me,"Slice with what?\n");
      return 1;
   }
   
   if(!(int)me->query_property("slicing") )
   {
      me->adjust_gp(-(int)me->query_max_gp());
     return 1;
   }
   tell_object(victim,(string)me->query_cap_name()+" twirls his blades "
	"and , before you can dodge, attacks.\n");
   tell_object(me,"You dazzle "+(string)victim->query_cap_name()+
	" with your bladework.\n");
   victim->attack_by(me);
   bonus = ((int)me->query_level()/3)+2;
   me->adjust_tmp_tohit_bon(bonus);
    me->adjust_tmp_damage_bon(bonus/2);
   for(i=0; i <((int)me->query_dex()+(int)me->query_level())/SLICE_DIV; i++)
   {
	weap[0]->weapon_attack(victim,me);
   if(sizeof(weap) > 1) weap[1]->weapon_attack(victim,me);
   }
   me->adjust_tmp_tohit_bon(-bonus);
    me->adjust_tmp_damage_bon(-bonus/2);
   return 1;
}

string help(string str) {
  return
"Syntax: slice <person>\n\n"
"Slice is a Drow Warrior attack based on their skill with bladework. "
"The higher the level, and the higher the dexterity, the more damage "
"you will do. "
   "\n";
}

