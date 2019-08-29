
#include "tweaks.h"
/*** Cloud of confusion ***/
/*** Created by Taniwha ***/
 

#define SP_NAME "Cloud of Confusion"
#define SPELLTYPE "offensive"      
#define TYPE "magical"
#define SIZE_OF_DICE 4
#define save_type "magical"
#define GP CONFUSE_GP
#define LEVEL CONFUSE_LEVEL
#define LOCKOUT "cloud_of_confuse_cast"

object room;

string help() {
       return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "School: Invocation\n"
       "Level: "+LEVEL+"\n"
       "Gp Cost: "+GP+"\n"
       "Damage Type: Physical (disorientation)\n"
       "Saving Throw: Level\n"
       "Description: \n"
       "    This spell will fill a room with a cloud of narcotic vapour."
       "Effects are varied. The spell lasts 1 round/level + 2, "
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
	((int)my_caster->query_level()< LEVEL) )
  {
       tell_object(my_caster,"You just can't muster the concentration "
	 "to cast yet.\n");
       return 1;
  }
  if( my_caster->query_gp() < GP )
  { 
       tell_object(my_caster, "You are too mentally drained to cast.\n");
       return 0;
  }
  tell_object(my_caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(my_caster),(string)my_caster->query_cap_name()+
      " chants, 'cumulous confundere'.\n", ({ my_caster }));

  my_caster->add_timed_property(LOCKOUT,1,CONFUSE_LOCKOUT);
  my_caster->adjust_gp(-GP);

  call_out("make_spell",1,my_caster); 
  return 1;
}

int cast(string str)
{
   return(cast_spell(str,this_player()));
}

void make_spell(mixed tp)
{
   object ob;
   ob = clone_object(SPELLS+"confuse.c");
   ob->move(room);
   ob->set_spell(tp,2+(int)tp->query_level());
   tell_room(room,"A cloud of narcotic vapour fills the room!\n",({ }) );
}


