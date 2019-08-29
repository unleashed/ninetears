/*** Spirit Armour Spell ***/
/*** Created by Eerevann Tokani ***/

#include "tweaks.h"

inherit "/std/spells/base.c";

#define SP_NAME "Spirit Armour"
#define GP_COST SPIRIT_ARMOUR_GP_COST
#define save_type "spells"


void setup()
{
  set_spell_name("Spirit Armour");
  set_school("necromancy");
  set_spell_level(3);

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("This spell allows the caster to surround himself with "
    "a portion of his own life essence.  The spirit armour grants "
    "the caster an Armour Class bonus for a limited duration.\n"
    "     When the spell ends, the armour dissipates and the caster "
    "loses a bit of his life essence, suffering 2-8 points of damage "
    "unless a saving throw is succesfully made, which reduces the damage "
    "to one half.  This spell affects the caster ONLY.\n"
    " Note: you will drop all your armour when this spell is cast,"
    " and you cannot wear armour while it is in effect. "
    "Note also that the protection improves with level. "
    " WARNING:  This spell COULD kill you if you take enough "
    "damage to kill yourself when it wears off.\n\n");

  set_gp_cost(SPIRIT_ARMOUR_GP_COST);
  set_casting_time(1);
  set_rounds( ({ "round1" }) );
}

int cast_spell(string str, object who, int quiet)
{
  object caster;
  caster = who?who:this_player();
  if(caster->query_spirit_armour_spell())
  {
    tell_object(caster,"You are already affected by a Spirit "
                "Armour spell.\n");
    return 1;
  }
  return ::cast_spell(str,who,quiet);
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int j;
  object* ob;
  object gob;

  if ( !quiet )
  {
    tell_room(environment(caster),caster->query_cap_name()+
      " chants, 'spiritis solis armanis'.\n", ({caster}));
    tell_object(caster, "You chant, 'spiritis solis armanis'.\n");

  tell_object(caster, "You surround yourself with your own life "
    "essence.\n"); 
  tell_room(environment(caster), (string)caster->query_cap_name()+
    " finishes a spell and a gray mist surrounds "+
    (string)caster->query_objective()+".\n", caster); 
  }

  ob = all_inventory(caster);
  for (j=0;j<sizeof(ob);j++)
    if ( ob[j]->query_armour() && (gob=caster->query_guild_ob()) &&
         !( gob->query_legal_armour( ob[j]->query_armour_name())) )
      caster->drop_ob(ob[j]->query_name());

  tell_object(caster,"Your life essence surrounds you, forcing "
    "off all your weak, material protections.\n");
  
  gob = 0;
  gob = clone_object(SPIRIT_ARMOUR_SHADOW);
  gob->setshadow(caster); 
  caster->add_extra_look(this_object());
  caster->add_timed_property(SPIRIT_ARMOUR_PROPERTY, 1,
	SP_AR_DURATION_BASE+(SP_AR_DURATION_LEVEL_MULT*20));

  return 0;
}


string extra_look()
{
  return "Is surrounded by a swirling gray mist.\n";
}
