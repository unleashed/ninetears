 /*** Feeblemind Spell by Shauri ***/ 
 /*** 22-10-96 ***/ 
 
#define SP_NAME         "Feeblemind" 
#define STILLCASTING    "stillcasting" 
 
#define PW_STUN_SHADOW "/std/commands/shadows/stun.c" 
 
inherit "/std/spells/base.c"; 
 
void setup() 
{ 
  set_spell_name("Feeblemind"); 
  set_sphere("all"); 
  set_spell_level(17); 
 
  set_target_type("one"); 
  set_range(0); 
  set_line_of_sight_needed(0); 
 
  set_help_desc("\n     This spell will send a wave of mental " 
         "energy through the victim, blocking up his mind and " 
         "destroying some of the knowledge the victim had.\n"); 
 
  set_gp_cost(15); 
  set_casting_time(1); 
  set_rounds(  
   
     ({ "round1" })  
  ); 
} 
 
int check_align(object caster) { 
   if(caster->query_align() < 0 ) return 0; 
   
  return 1; 
} 
 
int round1(object caster, mixed target, mixed out_range, int time, int quiet) 
{ 
   int j,duration; 
   int NO_OF_DICE; 
   int level; 
   object shad; 
   string *spells; 
   mapping map; 
 
   
  if (!target) { 
    tell_object(caster, 
      "Your spell failed ... there is no one of that name here.\n"); 
    return -1; 
  } 
 
                                /*** only for evil people ***/ 
  if ( !check_align(caster) ) { 
    tell_object(caster, 
      "Your spell failed ... being good, you cannot harness the evil "  
       "powers of this wicked spell.\n"); 
    return 0; 
  } 
 
  if(target == caster) { 
    tell_object(target, "Wouldn't that be suicide?\n"); 
    tell_room(ETO,(string)caster->query_cap_name()+ 
      " stops casting.\n",target); 
    return -1; 
  } 
 
  if(!quiet) { 
    tell_object(caster, "You chant, 'Messum maksum mindum'.\n"); 
    tell_room(ETO, (string)caster->query_cap_name()+  
       " chants, 'Messum maksum mindum'.\n",({caster})); 
  } 
 
 
   NO_OF_DICE = caster->query_level(); 
   if(NO_OF_DICE == 0) 
      NO_OF_DICE = 1; 
 
   if(NO_OF_DICE+random(5)+1 < (int)target->query_level()) {  
      tell_object(target, (string)caster->query_cap_name()+ 
         " enters your mind. You feel a light headache, but manage to " 
         "fight off the attack, and "+caster->query_cap_name()+ 
         " loses "+caster->query_possessive()+" concentration.\n"); 
 
      tell_object(caster, "You cast "+SP_NAME+" at "+ 
         (string)target->query_cap_name() + " but you fail.\n"); 
    
      tell_room(ETO, (string)caster->query_cap_name()+ 
      "stares at "+ (string)target->query_cap_name()+ " firmly with a " 
      "strange look in his eyes but loses "+caster->query_possessive()+ 
      " concentration.\n", 
                 ({target,caster}) ); 
 
    target->attack_by(caster); 
    return 0; 
 
   }    
 
 
   tell_object(target, (string)caster->query_cap_name()+ 
      " pierces your mind. You get a bad headache " 
      "and seem to have forgotten something.\n"); 
    
   tell_object(caster, "You cast "+SP_NAME+" at "+ 
     (string)target->query_cap_name() + 
     " and pierce his mind.\n"); 
    
   tell_room(ETO, (string)caster->query_cap_name()+ 
      " stares firmly at "+(string)target->query_cap_name()+" with " 
      "a strange look in his eyes, penetrating "+ 
      (string)target->query_cap_name()+"s mind.\n", 
                 ({target,caster}) ); 
 
 
//  caster->add_timed_property(STILLCASTING,1,2); 
 
   map=target->query_spells(); 
   spells=keys(map); 
   if(sizeof(spells)) { 
 //      "/global/spells.c"->remove_spell(spells[random(sizeof(spells))]); 
   target->remove_spell(spells[random(sizeof(spells))]); 
   } 
   duration=random(4)+1; 
   j = cleric_fix_damage(caster, target, duration, "magical"); 
    target->add_timed_property("stun_on", 1, j); 
    target->add_timed_property("nocast",1, j); 
    target->add_timed_property("noguild",1, j); 
    target->add_timed_property("passed out", 
     "You can't do anything.\n",j); 
   shad = clone_object(PW_STUN_SHADOW); 
   shad->setup_shadow(target, j); 
 
   target->attack_by(caster); 
 
   return 0; 
} 
 
