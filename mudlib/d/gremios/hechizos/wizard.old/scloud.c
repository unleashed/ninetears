
#include "tweaks.h"
/*** Stinking cloud ***/
/*** Created by Taniwha ***/
 

#define SP_NAME "Stinking cloud"
#define SPELLTYPE "offensive"      
#define TYPE "magical"
#define SIZE_OF_DICE 4
#define save_type "spells"
#define GP STINK_GP
#define LEVEL STINK_LEVEL
#define LOCKOUT "stinking_cloud_cast"

object room;
int hb;

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Invocation\n"
       "Level: "+LEVEL+"\n"
       "Gp Cost: "+GP+"\n"
       "Damage Type: Physical (poison)\n"
       "Saving Throw: Level Constitution and Resist Poison\n"
       "Description: \n"
       "    This spell will fill a room with a cloud of nauseating vapour."
       "Effects are varied, ranging from none to vomiting. "
       "The spell lasts 1 round/level + 2, "
       "until it is dispelled, or until the caster dies or leaves the game. "
       "Also note the caster gets a 10* bonus save, not total immunity. "
       "\n";
}


int cast_spell(string str, object caster)
{
  object my_caster;

  if (caster)
	my_caster = caster;
  else my_caster = this_player();
  
  room = environment(my_caster);  
  if((my_caster->query_timed_property(LOCKOUT)) || 
	(my_caster->query_level()< LEVEL) )
  {
       tell_object(my_caster,"You just can't muster the concentration to "
	"cast yet.\n");
       return 1;
  }
  if( my_caster->query_gp() < GP )
  { 
       tell_object(my_caster, "You are too mentally drained to cast.\n");
       return 1;
  }

  tell_object(my_caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(my_caster),(string)my_caster->query_cap_name()+
     " chants, 'cumulous nasueous'.\n", ({ my_caster }));

  my_caster->adjust_gp(-GP);
  my_caster->add_timed_property(LOCKOUT,1,STINK_LOCKOUT);
  call_out("make_spell",1,my_caster);   
  return 1;
}
int cast(string str)
{
   return(cast_spell(str,this_player()) );
}

void make_spell(mixed tp)
{
   object ob;
   ob = clone_object(SPELLS+"stinker.c");
   ob->move(room);
   ob->set_spell(tp,(tp->query_level()));
   tell_room(room,"A stinking cloud fills the room!\n",({ }) );
}
