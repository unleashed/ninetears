/*  Adapted from the original Berserk command, coded by Timion.
 *  Marauder, 11/14/95/
 */
/** converted to base malik oct 97 **/
/** changes for experiment malik **/
                                     
                                     
inherit "/std/commands/base_command.c";
inherit "/std/inventory.c";
                                     
                                     
#include "new_tweaks.h"
                                     
                                     
#define START_GP 5
#define RAGE_GP 1
#define BERSERK_GP 3
#define BERSERKER_HEAL 7
                                     
                                     
void remove_me(object doer);
void property_check(object doer);
                                     
                                     
void setup(){
   set_command_name("berserk");
   guilds = BERSERK_GUILDS; //fighter, rager
   target_type = BERSERK_TYPE;
   lockout = 0;
// reason? you go hyper. can't haste anymore so no need to
// castrate going utterly nuts
   set_help_string(
    "Berserk is the use of violent emotions during combat by fighters.  "
    "Whether this is an adrenaline fueled rush of violence channeled "
    "into your enemies or the total loss of any control and the "
    "possession of your body by your most violent inner emotions.  "
    "The first stage in this rage is a focused violence, more easily "
    "controlled and directed.  The second stage will cause you to attack "
    "anything that can be physically harmed.  The second stage, or full "
    "blown berserk is viewed by many as dangerous and addictive and some "
    "fear ever to tread its dangerous path.  In any event the use of "
    "these emotions does not come without risks.\n\n");
} /* setup() */
                                     
                                     
int go_berserk(string str, object ob){
   return ::exec_command(str,ob);
} /* go_berserk() */
                                     
                                     
int do_command(string str, object doer){
   int ACBONUS,BONUS;
   int time;
   int point;
   int *bstats;
                                     
// this is to eliminate a previous error with prop added
// permanently instead of static.

   if(doer->query_property("berserker_stats") &&
      !doer->query_static_property("berserker_stats")){

      doer->remove_property("berserker_stats");
   }




   if(doer->query_gp() < START_GP){
      tell_object(doer,"You are too exhausted.\n");
      return 1;
   }
   command_cost(START_GP,doer);
                                     
   point = doer->query_property("flipped");
   if(!doer->query_property("berserker_stats")) point = 0;
   if(point == 2){
      tell_object(doer,"You are Berserk! You cannot possibly become "
       "more enraged.\n");
      return 1;
   }
   bstats = doer->query_property("berserker_stats");
   if(!sizeof(bstats)) bstats = ({0,0});
                                     
   doer->adjust_tmp_tohit_bon(-bstats[0]);
   doer->adjust_tmp_damage_bon(-bstats[0]);
   doer->adjust_tmp_ac_bon(-bstats[1]);
                                     
   doer->remove_static_property("berserker_stats");
   end_hb_command(doer);
   remove_me(doer);
   switch(point){
    case 0:
      time = doer->query_level()*3;
      BONUS = adjust_for_skills(doer->query_level()/3+1,doer);
      ACBONUS = adjust_for_skills(10,doer);     
      doer->add_static_property("berserker_stats",({BONUS,ACBONUS}));
      doer->adjust_tmp_tohit_bon(BONUS);
      doer->adjust_tmp_damage_bon(BONUS);
      doer->adjust_tmp_ac_bon(ACBONUS);
      doer->add_timed_property("flipped",1,time);
      tell_object(doer,"You feel your blood boil and the thrill of "
       "combat course through your body.\n");
      tell_room(environment(doer),doer->query_cap_name()+
       " begins to shake with strength and energy.\n",doer);
    break;
    case 1:
      time = doer->query_level();
      BONUS = adjust_for_skills(doer->query_level()/2+5,doer);
      ACBONUS = adjust_for_skills(40,doer);     
      doer->add_static_property("berserker_stats",({BONUS,ACBONUS}));
      doer->adjust_tmp_tohit_bon(BONUS);
      doer->adjust_tmp_damage_bon(BONUS);
      doer->adjust_tmp_ac_bon(ACBONUS);
      doer->add_timed_property("flipped",2,time);
      doer->add_property("flipped_out",1);
      doer->add_property(
       "berserkergang",doer->query_property("berserkergang")+random(2)+1);
      tell_object(doer,"You lose total control attacking everything in "
       "sight with the strength of a god.\n");
      tell_room(environment(doer),doer->query_cap_name()+
       " loses control attacking everything and everyone.\n",doer);
      call_out("remove_me",time,doer);
            call_out("end_hb_command",time,doer);
    break;
   }
    
   setup_hb_command(doer,time+2,({doer}));
   return 1;
} /* do_command() */
                                     

int hb_command(object doer, int time, mixed *params){
   object *cows;
   object co;
   int chance;
                                     
   if(time == 1 || !doer->query_property("flipped")){
      call_out("end_hb_command",0,doer);
      remove_me(doer);
      return 0;
   }

   chance = doer->query_property("berserkergang")-
   2*doer->query_level();


   if(doer->query_haste_spell()){
      doer->destruct_haste_shadow();
      doer->remove_timed_property("haste_on");
      doer->adjust_tmp_str(1);
      doer->adjust_tmp_dex(2);
   }
   if(doer->query_slow_spell() && doer->query_property("flipped")==2){
      doer->destruct_slow_shadow();
      doer->remove_timed_property("slow_on");
   }

   if(doer->query_property("flipped") == 1){
      if(!command_cost(RAGE_GP,doer)){
         call_out("end_hb_command",0,doer);
         remove_me(doer);
         return 0;
      }
      if(!random(2)){
         tell_object(doer,"You rage against your opponents.\n");
         tell_room(environment(doer),doer->query_cap_name()+
          " rages against "+doer->query_possessive()+
          " opponents.\n",doer);
      }
      if(random(5000) < chance){
         tell_object(doer,"You feel yourself losing total control!!!\n\n");
         call_out("do_command",5,"all",doer);
      }
   }
   cows = liv_not_creator_inv(environment(doer));
   if(!sizeof(cows)) cows = ({});
   if(doer->query_property("flipped") == 2){
      if(!command_cost(BERSERK_GP,doer)){
         remove_me(doer);
         call_out("end_hb_command",0,doer);
         return 0;
      }
      doer->adjust_hp(BERSERKER_HEAL,doer);
      if(!random(2)){
         tell_object(doer,"You attack everything in a rage.\n");
         tell_room(environment(doer),doer->query_cap_name()+
          " is in a berserk rage attacking everything!\n",doer);
      }
      foreach(co in cows){
// grrr hack hack hack
         if(!co) continue;
         if(!co->query_dead() && !co->query_pacify_spell() &&
            !co->query_hidden() && !co->query_invis()){
            co->attack_by(doer);
         }
      }
   }
   call_out("property_check",2,doer);
   return 0;
}
                                     
                                     
                                     
void property_check(object doer){
   int chance = doer->query_property("berserkergang");
                                     
   if(!doer->query_property("flipped")){
      call_out("end_hb_command",0,doer);
      remove_me(doer);
      return;
   }

   if(doer->query_timed_property("feared")){
      doer->remove_timed_property("feared");
      if(doer->query_property("flipped") == 1 &&
         random(5000) < chance*50){
         call_out("do_command",0,"all",doer);
         doer->set_wimpy(0);
         tell_object(doer,"As the fear courses through your veins "
          "you become filled with a terrible rage.\n");
         
         return; 
      }
      if(doer->query_timed_property("flipped") == 2){
         doer->set_wimpy(0);
         return;
      }
   }
   if(doer->query_timed_property("hold_person_on")){
      if(doer->query_property("flipped") == 2){
         doer->remove_timed_property("passed out");
         doer->remove_timed_property("noguild");
         doer->remove_timed_property("hold_person_on");
         doer->destruct_hold_person_shadow();
      }
      return;
   }
   if(doer->query_timed_property("stun_on")){
      doer->remove_timed_property("stun_on");
      call_out("end_hb_command",0,doer);
      remove_me(doer);
      doer->remove_timed_property("passed out");
      doer->remove_timed_property("noguild");
      doer->remove_timed_property("nocast");
      return;
   }
   if(doer->query_timed_property("pacify_on")){
      doer->remove_timed_property("pacify_on");
      if(doer->query_property("flipped") == 2 &&
         random(5000) < chance*25){
         doer->remove_timed_property("noguild");
         doer->remove_timed_property("nocast");
         return;
      }
      call_out("end_hb_command",0,doer);
      remove_me(doer);
      doer->remove_timed_property("noguild");
      doer->remove_timed_property("nocast");
      return;
   }
   return;
}
                                     
                                     
                                     
void remove_me(object doer){
   int *bstats = doer->query_property("berserker_stats");
   doer->remove_static_property("berserker_stats");

   if(!bstats) bstats = ({0,0});

   doer->remove_timed_property("flipped");
                                     
   if(doer->query_property("flipped_out"))
      doer->adjust_hp(-doer->query_level()*2,doer);
   doer->remove_property("flipped_out");
   
   doer->adjust_tmp_tohit_bon(-bstats[0]);
   doer->adjust_tmp_damage_bon(-bstats[0]);
   doer->adjust_tmp_ac_bon(-bstats[1]);

   if(bstats[0]){
      doer->adjust_tmp_con(-1);
      tell_room(environment(doer),doer->query_cap_name()+
       " slumps as great emotions leave "+doer->query_possessive()+
       " body.\n",doer);
      tell_object(doer,"You feel exhausted as your rage leaves you.\n");
      bstats = 0;
   remove_call_out("remove_me");
   }
}

