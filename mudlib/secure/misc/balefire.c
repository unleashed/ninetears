/** Balefire by Malik. From the school of twin edged things **/
/** that make for non-fun for their user. Mage Decimation  **/

#define SIZE_OF_DICE 4
#define MISFIRE 3
#define BALEFIRE "/std/spells/wizard/balefire_ob.c"

inherit "/std/spells/base.c";

void hit_balefire(object target, object caster);

void setup() {
   set_spell_name("Balefire");
   set_spell_level(15);
   set_school("conjuration");

   set_target_type("one");
   set_range(5);
   set_line_of_sight_needed(0);

   set_help_desc("This spell gathers together a bolt of planar energies "
    "and sends it into your opponent.  The spell was originally developed "
    "by the Ilythiiri and their allies.  It is a horrid spell and rumoured "
    "to have been the ruin of some few Ilythiiri mages who depended on it "
    "overly.\n");

   set_gp_cost(30);
   set_casting_time(1);
   set_rounds( ({ "round1" }) );
} /* setup() */


int round1(object caster,mixed target,mixed out_range,int time,int quiet){
 
   if(!target){
      tell_object(caster,
       "Your spell failed ... there is no one of that name here.\n");
      return -1;
   }

   if(target->query_pacify_spell() || target->query_dead()){
      tell_object(caster, "You can't cast this spell on that one.  "
       "They are harmless.\n");
      return -1;
   }

   if(target == caster){ 
      tell_object(caster, "That _WOULD_ be suicide.\n");
      return -1;
   }

   tell_room(environment(caster),caster->query_cap_name()+
    " gestures at "+target->query_cap_name()+" and a glowing bar "
    "of energy too bright to look at streaks forth.\n", ({caster,target}));
   tell_object(caster, "You summon the bolt of balefire and cast "
    "it at "+target->query_cap_name()+".\n");

   if(random(caster->query_int()+caster->query_level()/8) < MISFIRE){    
      tell_object(caster, "You miscalculated and the bolt of balefire "
       "deflects off of unseen planar edges right back at you!\n");
      tell_room(environment(caster), caster->query_cap_name()+
       "'s bolt of balefire careens around randomly before slamming "
       "back into "+caster->query_pronoun()+".\n",caster);

      hit_balefire(caster,caster);
      return 1;
   }
   
   if(random(caster->query_level()+caster->query_cha()) < MISFIRE){
      caster->adjust_cha(-1);
   }

   tell_object(target,"A glowing bolt of energy slams into you.\n");

   tell_room(environment(target),target->query_cap_name()+
    " is struck by a glowing bolt of energy.\n",target );

   hit_balefire(target,caster);
   return 1;
} /* round1() */


void hit_balefire(object target, object caster){
   int resist,resistcheck,damage,NO_OF_DICE;
   string type;
   object bale;

   NO_OF_DICE = caster->query_level();
   if(NO_OF_DICE < 1) NO_OF_DICE = 1;

   resist = target->query_property("magic");
   type = "magic";

   if(resist > resistcheck = target->query_property("acid")){
      resist = resistcheck;
      type = "acid";
   }

   if(resist > resistcheck = target->query_property("psionic")){
      resist = resistcheck;
      type = "psionic";
   }

   damage = roll(NO_OF_DICE, SIZE_OF_DICE) + NO_OF_DICE;
   damage = wiz_fix_damage(caster,target,damage,type);

   bale = clone_object(BALEFIRE);
   bale->move(target);
   bale->setup_balefire(damage,target);

   return;
} /* hit_balefire() */

