/*** Mystical Heal Spell by Shauri ***/ 
/*** -> base spell by Wonderflug   ***/ 
 
#define MYSTIC_HEAL_SHADOW "/w/shauri/code/ducky/spells/mystic_heal_shadow.c" 
inherit "/std/spells/base.c"; 
 
void setup() 
{ 
   set_spell_name("Mystic heal"); 
   set_sphere("healing"); 
   set_spell_level(6); 
 
   set_target_type("one"); 
   set_range(0); 
   set_line_of_sight_needed(0); 
 
   set_help_desc("This spell heals one quickly, but unlike other " 
     "healing spells, the effects are not permanent."); 
 
   set_gp_cost(5); 
   set_casting_time(1); 
   set_rounds( ({ "round1" }) ); 
} 
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet) 
{ 
   object ob; 
   int level=0; 
 
   if(wrong_alignment(caster)) { 
      punish_align(caster); 
      return 0; 
   } 
 
   if(!target) { 
      tell_object(caster, 
         "Your spell failed ... there is no one of that name here.\n"); 
      return -1; 
   } 
  
   if(target->query_mystic_heal_spell()) { 
      tell_object(caster, 
         "The target is already healed by this spell.\n"); 
      return -1; 
   } 
 
   if(!quiet) { 
      tell_room(ETO,(string)caster->query_cap_name()+ 
         " chants, 'mystiz healorum'.\n", ({target,caster})); 
      tell_object(target, "You chant, 'mystiz healorum'.\n"); 
   } 
 
   if(target == caster) { 
      tell_object(caster, "You cast Mystic heal upon yourself.\n"); 
      tell_room(environment(caster),(string)caster->query_cap_name()+ 
         " casts a spell upon "+caster->query_objective()+"self.\n",caster); 
   } else { 
      tell_object(target, (string)caster->query_cap_name()+ 
         " mumbles a harsh chant at you, healing you using " 
         "mystic powers.\n"); 
    
      tell_object(caster, "You mumble a harsh chant at "+ 
         (string)target->query_cap_name()+" healing "+ 
         target->query_objective()+".\n"); 
    
      tell_room(ETO,(string)caster->query_cap_name()+ 
         " scares at "+target->query_cap_name()+" chanting harshly.\n", 
         ({target,caster}) ); 
   } 
   level=(int)caster->query_level(); 
   ob=clone_object(MYSTIC_HEAL_SHADOW); 
   ob->setup_shadow(target); 
   target->add_extra_look(ob); 
   target->add_timed_property("mystic_heal_on",1,level); 
 
   return 0; 
} 
 
