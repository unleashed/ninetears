/*** Summon spider poison by Shauri ***/ 
/*** -> base spell by Wonderflug ***/ 
/*** -> base poison mode by Taniwha ***/  
 
#include "/d/gremios/hechizos/cleric/tweaks.h" 
 
inherit "/d/gremios/hechizos/base.c"; 
 
void setup_poison(int, object, object); 
 
void setup() { 
  set_spell_name("Summon spider poison"); 
  set_spell_level(14);   set_sphere("conjuration"); 
 
  set_target_type("many"); 
  set_range(0); 
   
  set_help_desc( 
    "Damage Type: Summon spider poison\n" 
    "Saving Throw: Level Constitution and Resist Poison"); 
  set_help_desc("A little souped up poison cloud spell.\n"); 
 
  set_gp_cost(18); 
  set_casting_time(1); 
  set_rounds( ({ "round1" }) ); 
} 
 
int round1(object caster, mixed target, mixed out_range, int quiet, int time) { 
  int damage,i; 
  object ob; 
  string str; 
 
  if ( wrong_alignment(caster) ) { 
    punish_align(caster); 
    return 0; 
  } 
 
  str = (string)caster->query_cap_name(); 
  if((i = member_array(caster, target)) != -1) 
    target = delete(target, i, 1); 
   
  if(!sizeof(target)) { 
    tell_object(caster, "There is noone here by that name.\n"); 
    return -1; 
  } 
    
 
  if (!quiet) { 
    tell_room(ETO,(string)caster->query_cap_name()+ 
       " chants, \"Toxoplas piser inatum\".\n", ({ caster })); 
    tell_object(caster, "You chant, \"Arachnus toxoplas arol inatum\".\n"); 
  } 
 
/***  
 
   just here, it's posible i dont need check the damage but if 
i need i'll must do one for each pc in room (in for) and it's not 
good (i think) Shauri. 
 
***/ 
 
  damage = (int)caster->query_level()/POISON_MOD; 
  if((string)caster->query_guild_name() == "Cyrcia")  
     damage *= 2; 
  else if((string)caster->query_guild_name() == "Ducky")  
     damage *= 3; 
 
  tell_room(ETO, caster->query_cap_name()+ 
       " looks strangely around the room.\n", ({ caster }) ); 
 
  for ( i=0; i<sizeof(target); i++ ) { 
     if( (int)target[i]->query_property("poisoned") || 
(int)target[i]->query_property("poison") ||  
         (int)target[i]->query_dead() || 
(int)target[i]->query_property("undead") ) { 
         target[i]->attack_by(caster); 
     } else { 
        if( random((int)target[i]->query_level()+(int)target[i]->query_con()) > 
          random((int)caster->query_level()*2) ) { 
           target[i]->add_timed_property("poison",50,(int)caster->query_level() 
* 60); 
           tell_object(target[i], caster->query_cap_name()+" hisses at you 
strangely.  " 
              "Must have been some sort of failed attack.\n"); 
           target[i]->attack_by(caster); 
        } else { 
           // Made this a function - Radix 
           setup_poison(damage,caster,target[i]); 
 
           tell_object(caster, "You blow the poison cloud at 
"+target[i]->query_cap_name()+ 
              ", and watch as the poison enters tortured lungs.\n"); 
           tell_object(target[i], caster->query_cap_name()+" blows a hazy cloud 
at you, " 
              "and you feel something wrong with your lungs!\n"); 
          target[i]->attack_by(caster); 
        } 
     } 
  } 
  return 0; 
} 
 
void setup_poison(int damage, object caster, object target) { 
   object ob = clone_object(SPELLS+"poisoned.c"); 
   target->add_timed_property("poisoned",1,(caster->query_level()*30)); 
   ob->set_get(); 
   ob->move(target); 
   ob->reset_drop(); 
   ob->reset_get(); 
   ob->set_spell(caster,damage); 
   return; 
} 
 
