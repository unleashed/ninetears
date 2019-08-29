/*** Create Druidic Staff -- Druids Spell ***/
/*** By Wonderflug ***/

#include "tweaks.h"

inherit "/std/spells/patch.c";

mixed find_one_match(string find,mixed in);

#define SP_NAME "Create Druidic Staff"
#define GP_COST ENCHANT_GP
#define SPELLTYPE "offensive"

string help() 
{
  return
       "\n\n"
       "Spell Name: "+SP_NAME+"\n"
       "Sphere: Druids\n"
       "Level: 3rd\n"
       "Gp Cost: "+GP_COST+"\n"
	"Saving Throw: None\n\n"
        "Description: \n"
	"     This spell will place an enchantment on a staff.  The power "
	"of the enchantment is +1 per 8 levels of the druid, to a maximum "
	"of +5.  Multiple enchants are not cumulative; the most recent "
	"enchant will be the one in effect.  It is rumored that some "
	"special staves will both increase the power of the enchantment "
	"and add some extra abilities and powers over nature.  The "
	"existence of these legendary staves is emphatically "
	"denied in the highest Druidic Circles.\n\n";
}	

mixed spell( string str, object caster );

int cast_spell(string str,object cast)
{
  int skill;
  mixed ret;
  object caster;

  caster = cast ? cast : this_player();

  if(interactive(caster))
	  str = (string)caster->expand_nickname(str);

  ret = spell(str, caster);
  if (stringp(ret))
  {
    notify_fail(ret);
	 return 0;
  }

  tell_object(caster,"You start to cast "+SP_NAME+".\n");
  tell_room(environment(caster),caster->query_cap_name()+" begins to cast "
	"a spell.\n",
	caster);
  return 1;
}

mixed spell(string str, object caster)
{
  mixed ob;

  if ((int)caster->query_spell_effect(SPELLTYPE))
    return "You are already casting an "+SPELLTYPE+" spell.\n";

  ob = find_one_match(str, caster);
  if ( sizeof(ob) )
	ob = ob[0];
  else return "You do not have a "+str+".\n";

  caster->add_spell_effect(4, SPELLTYPE, SP_NAME,
    this_object(), "hb_spell", ({ ob }));
  return 1;
}

int hb_spell(object caster, mixed *params, int time)
{
  int i, j;
  object staff;

  staff = params[0];
  switch( time )
  {
    case 4:
	tell_object(caster, "You draw in power from the world for your "
	  "enchantment.\n");
	tell_room(environment(caster), caster->query_cap_name()+" goes into "
	  "an odd trance-like state.\n", caster);
	return 0;
    case 3:
	tell_object(caster, "You hold the "+staff->query_short()+
	  " out in front of you.\n");
	tell_room(environment(caster),caster->query_cap_name()+
	  " holds a "+staff->query_short()+" out in front of "+
	  caster->query_objective()+".\n", caster );
	return 0;
    case 2:
	tell_object(caster, "You release the "+staff->query_short()+
	  ", and it hovers in the air in front of you.\n");
	tell_room(environment(caster), caster->query_cap_name()+
	  " releases the "+staff->query_short()+" and it hovers in "
	  "mid-air!\n", caster);
    default:
	break;
  }
  if ((int)caster->adjust_gp(-GP_COST)<0)
  {
	tell_object(caster, "You don't have enough power to enchant the "+
	  staff->query_short()+".\n");
	tell_room(environment(caster), caster->query_cap_name()+" sways "
	  "tiredly and the "+staff->query_short()+
	  " drops to the ground.\n", caster);
    	return 0;
  }
  if ( (string)staff->query_base_weapon_type_name() != "staff" )
  {
	tell_object(caster, "You come out of the trance and realize you "
	  "cannot enchant this item!\n\nThe backlash of power whips you.\n");
	tell_room(environment(caster), caster->query_cap_name()+" comes out "
	  "of the trance and glows briefly with power.\n\nThe power goes out "
	  "of control and whips "+caster->query_cap_name()+"!\n\n"+
	  caster->query_cap_name()+" howls with pain.\n", caster);
	caster->adjust_hp(-random(ENCHANT_BACKLASH)-1);
	return 0;
  }

  if ( !staff )
  {
	tell_object(caster, "The object of your enchant seems to have "
	  "disappeared!  Oopsie.\n");
	return 0;
  }

  tell_object(caster, "You come out of the trance and channel your power "
	"into the "+staff->query_short()+".\n");
  tell_room(environment(caster), caster->query_cap_name()+" glows with a "
	"soft blue aura that slowly seeps into the "+staff->query_short()+
	".\n", caster);
  tell_room(environment(caster), "The "+staff->query_short()+" pulses "
	"with a blue radiance that slowly fades away.\n\nThe "+
	staff->query_short()+" drops to the ground.\n");

  i = (int)caster->query_level() / 8;
  if ( i < 1 )
	i = 1;	
  if ( i > 5 )  /* Hmm.. need level 48 for this .. */
	i = 5;	/* Like this'll happen, but just in case. :) */

  staff->set_enchant(i);

  return GP_COST*i;
}
