/* Flode - 1997
 *
 * Taniwha, stripped back to some basic checks which we'll run on all
 * commands. They are parsed differently from spells to the 
 * set_prop has 2 arguments:
 *     1st: name of property
 *     2nd: error message when you haven't got the property
 *
 * Malik, Sept 97, Major slashing, hacking and reworking.
 *                 should do what it needs to now.
 *
 * flags:
 *   1: allowed on yourself      |  allow_yourself()
 *   2: allowed on dead          |  allow_dead()
 *   4: allowed on pacified      |  allow_pacify()
 *   8: allowed on creators      |  allow_creator()
 *  16: allowed on things        |  allow_thing()
 *  32: ONLY in combat           |  only_combat()
 *  64: NEVER in combat          |  never_combat()
 */

inherit "/std/commands/target.c";

mapping guilds = ([]);
mapping races = ([]);
int flags;
int prior;
int lockout;
int sec_lockout;
string mess;
string sec_lock_prop;
string help_string;
string target_type;
string command_name;
object *target = ({});

void create(){
   seteuid("/secure/master"->creator_file(file_name(this_object())));
   lockout = 1;
   this_object()->setup();
}



void allow_yourself() { flags |=  1; }
void allow_dead()     { flags |=  2; }
void allow_pacify()   { flags |=  4; }
void allow_creator()  { flags |=  8; }
void allow_thing()    { flags |= 16; }
void only_combat()    { flags |= 32; flags &= ~64; }
void never_combat()   { flags |= 64; flags &= ~32; }
void set_flags(int i) { flags = i; }


void set_command_name(string str){
   command_name = str;
}


object *aquire_target(string str,string target_type,object doer){
   object *ob;
   string str1,str2;
   object inwho;

   if(flags & 16){      
        
/* needless to say. having more than one of 'on, in or from' is bad */
      if(strsrch(str," on ") >= 0) // it's an item in someone/something
         sscanf(str,"%s on %s",str1,str2);
      if(strsrch(str," in ") >= 0)
         sscanf(str,"%s in %s",str1,str2);
      if(strsrch(str," from ") >= 0)
         sscanf(str,"%s from %s",str1,str2);
   }
  
   if(target_type == "one"){
      if(!(flags & 16)){
         ob = find_one_match(str, doer);
         if(!sizeof(ob))
            ob = find_one_match(str, environment(doer));
      }
      if(flags & 16){
         inwho = find_one_match(str2,environment(doer)); 
         if(inwho)
            ob = find_one_match(str1,inwho);
      }
   }

   if(target_type == "many"){
      ob = find_unique_match(str, doer);
      if(!sizeof(ob)){
         ob = find_unique_match(str, environment(doer));
      }
   }

   return ob;
} /* aquire_target() */      




int exec_command(string str, object doer){
   object env;
   int i;

   doer = doer ? doer:this_player();
   env = environment(doer);
   if(!env){
      tell_object(doer,"You're nowhere and can't do much right now.\n");
      return 1;
   }

// No need to check the syntax if we're doing other commands

/* was a syntax check in here before, not needed now I hope */

   if(doer->query_property("comm_lockout")||
     doer->query_property(sec_lock_prop)){

      tell_object(doer,"You are not calm enough.\n");
      return 1;
   }
   if(doer->query_property("noguild") ||
    environment(doer)->query_property("noguild") ||
    doer->query_property("passed out")){
      tell_object(doer,"You cannot do this right now.\n");
      return 1;
   }
   doer->add_timed_property("comm_lockout",
    ({env,doer->query_hb_counter()}),lockout );

   if(sec_lock_prop){
      doer->add_timed_property(sec_lock_prop,1,sec_lockout);
   }

   if(target_type == "pass"){
      return this_object()->do_command(str,doer);
   }

   target = aquire_target(str, target_type, doer);

   for(i=0;i<sizeof(target);i++){
      if(living(target[i])){ 
         if(target[i]->query_hide_shadow()||target[i]->query_invis()){
            target[i] = 0;
         }
      }
   }

   target -= ({0});
    
   prior = 0;

   mess = "";

   if(!sizeof(doer->query_attacker_list()) && (flags & 32)){
      mess = "You have no opponent in front of you.\n";
      target = ({});
   }

   if(sizeof(doer->query_attacker_list()) && (flags & 64)){
      mess = "You are fighting right now.\n";
      target = ({});
   }


   for(i=0;i<sizeof(target);i++){

      if(target[i] == doer && !(flags & 1)){
         if(prior < 2){
            mess = "That could hurt.\n";
            prior = 2;
         }
         target[i] = 0;
         continue;
      }
      if(target[i]->query_dead() && interactive(target[i]) && !(flags & 2)){
         if(prior < 1){
            mess = target[i]->query_cap_name()+" is dead.\n";
            prior = 1;
         }
         target[i] = 0;
         continue;
      }
      if(!(flags & 4)){
         if(target[i]->query_property("pacify_on")){
            if(prior < 1){
               mess = target[i]->query_cap_name()+" is harmless.\n";
               prior = 1;
            }
            target[i] = 0;
            continue;
         }
         if(doer->query_property("pacify_on")){
            if(prior < 2){
               mess = "You feel too peaceful to do anything at all.\n";
               prior = 2;
            }
            target[i] = 0;
            continue;
         }
      }
      if(!doer->query_creator() && target[i]->query_creator() &&
         !(flags & 8)){

         if(prior < 2){
            mess = "How dare you attempt this on the immortal "
             +target[i]->query_cap_name()+"!\n";
            prior = 2;
         }
         target[i] = 0;
         continue;
      }
      if(!living(target[i]) && !(flags & 16)){
         if(prior < 1){
            mess = "Try to find something alive.\n";
            prior = 1;
         }
         target[i] = 0;
         continue;
      }

   }

   target -= ({0});

   if(sizeof(target)){ 
      if(target_type == "one")
         return this_object()->do_command(target[0],doer);
      if(target_type == "many")
         return this_object()->do_command(target,doer);
   }

   if(strlen(mess)){
      tell_object(doer,mess);
      return 1;
   }

   else{
      tell_object(doer,""
       +((flags & 16)?"Nothing ":"Noone ")+"here going by that name.\n");
      doer->adjust_gp(-1);
      return 1;
   }
         
} /* exec_command() */


int adjust_for_skills(int i, object user){

   string *list;

/* if it's guild only, guilds["default"]
   has the penalty to be applied to guilds not listed
   note if you use guilds, put in a default for other 
   guilds. lack of a "default" will make non-listed 
   guilds have a multiplier of 0. ie none             */

   if(sizeof(guilds)){
      list = keys(guilds);
      if(member_array(user->query_guild_name(),list) == -1){
         i = i * guilds["default"] / 100;
      }               
      else{
         i = i*guilds[user->query_guild_name()]/100;
      }
   }
                                
/* same for races as guilds */
   if(sizeof(races)){
      list = keys(races);
      if(member_array(user->query_race_name(),list) == -1){
         i = i*races["default"]/100;
      }
      else{
         i = i*races[user->query_race_name()]/100;
      }
   }
   return i;
} /* adjust_for_skills() */


int command_damage(int damage,object attacker,object victim){
   damage = adjust_for_skills(damage,attacker);

// need this be automated? - malik
// damage = property_checks(properties,attacker,victim,damage);
// will put this in soon for priests i assume. - malik
// damage = align_checks(attacker,victim,damage);
        
   if(damage < 0) victim->attack_by(attacker);
   victim->adjust_hp(damage,attacker);

   return damage;
} /* command_damage() */


int command_cost(int cost, object doer){
   if(doer->query_gp()<cost){
      doer->set_gp(0);
      return 0;
   }
   doer->adjust_gp(-cost);
   return 1;
 } /* command_cost() */
   

int command_experience(int xp, object doer){
   int val;
   val = doer->adjust_xp(xp,doer);
} /* command_experience() */


void setup_hb_command(object doer, int rnds, mixed *params){
   doer->add_spell_effect(rnds,
                          "command",
                          command_name,
                          this_object(),
                          "hb_command_check",
                          params);
} /* setup_hb_command() */


int hb_command_check(object doer, mixed *params, int time){
   if(doer->query_property("noguild") ||
      environment(doer)->query_property("noguild"))
 
      return 0;

   return this_object()->hb_command(doer, params, time);
} /* hb_command_check() */



/* NOTICE: if you call end_hb_command. USE CALL_OUT!!!!! */
/* something about deleting effects before they've ended */

void end_hb_command(object doer){
   if(doer->query_spell_effect("command"))


   doer->remove_spell_effect(command_name);
} /* end_hb_command() */


/* Returns 1 if circle is possible,
 * 2 if nothing is possible,
 * 0 if normal backstab possible
 * also used by ambush
 */

int already_attacking(object me,object victim){
 
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   if(sizeof(me->query_attacker_list()))
      return 2;
   return 0;
} /* already_attacking() */


void set_help_string(string str){
   help_string = str;
} /* set_help_string() */


string help(){
   return help_string;
} /* help() */

