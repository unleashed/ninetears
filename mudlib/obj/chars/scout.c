/* base_scout.c by malik May 97 */
/* modded a bit. Malik, sept 97 */

inherit "/obj/monster.c";

#define ME "/obj/chars/scout.c"

object *people = ({});
object *rep_list = ({});
object *rep_list_temp = ({});
object *tar_list = ({});
object hide;

int hb,
    i,j,k,l;

string *my_friends,
        mssg,
        tar;

mixed *watch_list;
    

void set_my_friends(string str, string str2){
   my_friends = ({str, str2});
}
void set_watch_list(string str, string *list){
   watch_list = ({str, list});
}     

object *query_target_list(){
   tar_list = ({});
   people = users();
   tar = my_friends[0];

   for(i=0;i<sizeof(people);i++){
      switch(tar){
       case "group":
         if(people[i]->query_group_name()==my_friends[1])
            tar_list += ({people[i]});
       break;
       case "race_group":
         if(people[i]->query_race_group_name()==my_friends[1])
            tar_list += ({people[i]});
       break;
       case "guild":
         if(people[i]->query_guild_name()==my_friends[1])
            tar_list += ({people[i]});
       break;
      }
   }
   return(tar_list);
}


void init(){
   ::init();

   add_attack_spell(50, "panic attack",
      ({ME,"panic_attack",0}));
   if(sneaky){
      hide = clone_object("/std/commands/shadows/hide.c");
      hide->setup_shadow(this_object());
   }
}

void event_enter(object guest, string mess){
   if(guest->query_creator()) return;
   if(guest->query_dead()) return;
   if(guest->query_hidden()&&random(guest->query_level())>=
      random(this_object()->query_level())/4) return;

   /* exclude my employers */
   if(my_friends[0]=="group" &&
    guest->query_group_name()==my_friends[1])
      return;
   if(my_friends[0]=="race_group" &&
    guest->query_group_name()==my_friends[1])
      return;
   if(my_friends[0]=="guild" &&
    guest->query_group_name()==my_friends[1])
      return;
   
   if(watch_list[0]=="race"){   
      if(member_array(guest->query_race_name(),watch_list[1])==-1)
         return;
      if(member_array(guest,rep_list)==-1)
         rep_list += ({guest});
   }
}


void do_messaging(string mssg,object *tar_list){
   for(j=0;j<sizeof(tar_list);j++){
      tell_object(tar_list[j],"%^YELLOW%^"+mssg+"%^RESET%^");
   }
}


void heart_beat(){
   ::heart_beat();
   if(sizeof(rep_list)){
      rep_list_temp = rep_list;
      for(l=0;l<sizeof(rep_list);l++){
        if(!rep_list[l]) rep_list_temp -= ({rep_list[l]});
      }
      rep_list = rep_list_temp;
   }

   if(!sizeof(rep_list)){ hb = 0; return; }
   if(sizeof(query_attacker_list())){ hb = 0; return; }
   if(this_object()->query_silence_spell()){ hb = 0; return; }

   hb++;

   if(hb<=6) return;


   mssg = "["+this_object()->query_cap_name()+
      ": "+environment(this_object())->query_short()+
      "] reports :";
   for(k=0;k<sizeof(rep_list);k++){
       mssg+= " "
       +(member_array(explode(rep_list[k]->query_race_name(),"")[0],
       ({"a","e","i","o","u"}))==-1?"a ":"an ")
       +rep_list[k]->query_race_name()
       +(k<=sizeof(rep_list)-2?", ":"")+
       (k>0&&k==sizeof(rep_list)-2?"and":"");
   }
   mssg+= " passed by me.\n\n";
   
   do_messaging(mssg,query_target_list());

   rep_list = ({});
   hb = 0;
}   
      

void missing(string mssg, object *tar_list){
   call_out("do_messaging",15,mssg,tar_list);
}


void do_death(object doer){
   object *killers;
   int a;
   string logmssg;

   mssg = "\n[Contact has been lost with "
      +this_object()->query_cap_name()+
      " from "+ETO->query_short()+".\n\n";

   call_other(ME,"missing",mssg,query_target_list());

   logmssg = file_name(this_object())+"("
    +this_object()->query_level()+") was slain by: ";

   killers = this_object()->query_attacker_list();
   if(!sizeof(killers)&&doer){killers = doer->query_name();}
   for(a=0;a<sizeof(killers);a++){
      logmssg += killers[a]->query_name()+" ";
   }

   logmssg += ctime(time())+"\n";

   log_file("scout_log",logmssg);
   
   ::do_death(doer);
}

void panic_attack(string str, object ob, int q){
   call_out("panic_recover",5,ob,ob->query_wimpy());
   ob->set_wimpy(99);
}

void panic_recover(object ob, int num){
   ob->set_wimpy(num);
}



void setup_scout(){


   TO->set_guild_ob("/std/guilds/warriors/fighter.c");
   TO->set_level(15+random(15));
   TO->set_max_gp(query_max_gp()*2);
   TO->set_gp(query_max_gp());
   TO->set_str(15+random(14));
   TO->set_con(10+random(9));
   TO->set_dex(17+random(2));
   TO->set_int(15+random(4));
   TO->set_wis(15+random(4));
   TO->set_cha(10+random(9));

   TO->set_wimpy(50+random(50));
   TO->set_aggressive(0);

   set_kill_xp(query_kill_xp()/4);

   tar_list = ({});
   rep_list = ({});
   
   set_my_friends("group","Nerdinators");
   set_watch_list("race",({"nerd"}));

   add_timed_property("sense_life", random(2), 20000);
}   

