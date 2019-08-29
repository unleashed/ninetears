/*          Animate Dead By Falco               */ 
/*        Hacked to bits by Alansyn             */ 
/* Modified text to suit Ducky's guild by Ducky */ 
 /* hmm fixed by Shauri (problems in array's between others) */ 
 
#include "path.h"; 
#include "/std/spells/base.c"; 
#define SKEL "/obj/chars/skeleton.c" 
#define ZOMB "/obj/chars/zombie.c" 
#define JUJU CHAR+"juju.c" 
#define GHOUL CHAR+"gh_lord.c" 
 
void setup() 
{    set_spell_name("Animate Dead"); 
   set_spell_level(3); 
   set_sphere("necromantic"); 
   set_help_desc( 
      "This spell allows the caster to call upon the forces of evil Ducky " 
      "to animate several corpses in the room.  The number and type " 
      "depends on the caster's level and proficiency with necromancy.  " 
      "Casting this spell has a negative effect on the alignment of " 
      "the caster." 
      ); 
   set_target_type("none"); 
   set_gp_cost(10); 
   set_casting_time(1); 
   set_rounds( ({"round1"}) ); 
} 
int round1(object caster, mixed target, mixed out_range, int time, int quiet) 
{ 
   int count=0; 
   int good=0; 
   int clevel=caster->query_level(); 
   int align=caster->query_alignment(); 
   int level; 
   object *dead=allocate(12); 
 /* 
   switch(caster->query_sphere_level("necromantic")) 
   { 
      case "major": 
         level=clevel; 
         break; 
      case "neutral": 
         level=clevel/2; 
         break; 
      case "minor": 
         level=clevel/3; 
         break; 
      default: 
         level=0; 
         break; 
   } 
 */ 
   level=clevel; 
   if(caster->query_timed_property("animate_dead_on")) 
   { 
      tell_object(caster,"You can not animate dead again, so soon.\n"); 
      return -1; 
   } 
   target = find_match("corpses",environment(caster)); 
   if(!sizeof(target)) 
   { 
      tell_object(caster,"There are no dead to animate.\nYou feel the " 
                  "power of "+MASTER+" compelling you to kill someone.\n"); 
      caster->adjust_hp(random(10)); 
      return -1; 
   } 
   if(!quiet) 
   { 
      tell_room(environment(caster),caster->query_cap_name()+ 
         "chants, 'mortis anima est'.\n",({caster,target})); 
      tell_object(caster,"You chant, 'mortis anima est'.\n"); 
   } 
    tell_room(environment(caster), caster->query_cap_name()+ " chants " 
      "an evil prayer, and the dead rise to follow 
"+caster->query_objective()+".\n", 
      ({caster,target}) ); 
 
   if(align<0) 
      good=1; 
 
while(level>1 && count<12 && count<sizeof(target)) 
   { 
      if (good)  
        write("You feel a terrible dread as you realize your terrible 
mistake:\n" 
              "You called upon the power of "+MASTER+" while good aligned!\n"); 
 
      if(level>19) 
      { 
         if (align<1000)  
           dead[count]=clone_object(JUJU); 
         else 
           dead[count]=clone_object(GHOUL); 
 
         dead[count]->move(environment(caster)); 
         level-=4; 
      } 
 
      else if(level>14) 
      { 
         if (align<1000)  
           dead[count]=clone_object(ZOMB); 
         else 
           dead[count]=clone_object(JUJU); 
 
         dead[count]->move(environment(caster)); 
         level-=4; 
      } 
      else 
      { 
         dead[count]=clone_object(SKEL); 
         dead[count]->move(environment(caster)); 
         level-=2; 
      } 
      target[count]->dest_me(); 
      count++; 
      dead->set_aggressive(0); 
      dead->do_command("follow "+caster->query_name()); 
      if (!good) 
         dead->do_command("protect "+caster->query_name()); 
      else 
         dead->attack_ob(caster); 
      dead->set_join_fights(0); 
   } 
   caster->adjust_align(100); 
   caster->add_timed_property("animate_dead_on",1,100+clevel*10); 
   call_out("wear_off",100+clevel*10,dead,count); 
} 
 
int wear_off(object *dead, int count) 
{ 
   for(int i=0;i<count;i++) 
   { 
      if(dead[i]) 
         dead[i]->do_death(); 
   } 
} 
 
