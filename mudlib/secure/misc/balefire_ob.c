/** Balefire object for Balefire spell by Malik (mage decimation) **/

inherit "/std/object.c";

#define ROUNDS 5

int damage, round, hb;
object target;


void setup_balefire(int num, object ob){
   damage = num;
   target = ob;
   round = 0;
   target->add_property("BALEFIRE_ON",damage);
   reset_drop();
   reset_get();
   set_heart_beat(1);
} /* setup_balefire() */


void destruct_balefire(){
   if(target) target->remove_property("BALEFIRE_ON");
   destruct(this_object());
}


void init(){
   ::init();
   if(!target && this_player()){
      if(this_player()->query_property("BALEFIRE_ON")){
         target = this_player();
         setup_balefire(target->query_property("BALEFIRE_ON"),target);         
      }
   }
} /* init() */ 


void heart_beat(){
   int dam;

   if(!target){
      destruct_balefire();
      return;
   }

   hb++;
   if(hb < 2 && round != 0) return;
   hb = 0;

   if(round == ROUNDS || target->query_dead() ||
      environment(this_object()) != target){

      destruct_balefire();
      return;
   }
   

   dam = damage;


   tell_object(target,"You scream in agony as your flesh drips burning "
    "from your shriveling body.\n");
   tell_room(environment(target),target->query_cap_name()+
    " screams in agony as "+target->query_possessive()+
    " burning flesh liquifies and drips from "
    +target->query_possessive()+" withering body.\n",target);

   dam /= round + 1;

   if(dam < 20) dam = 20;

   target->adjust_hp(-dam);
   round++;
} /* heart_beat() */


