
/*** Greymist 1995 ***/
/*** Cure Disease Spell ***/
/*** Tweaked Taniwha 1996 ****/
#include "tweaks.h"
inherit "/std/spells/base.c";
void setup()
{
    set_spell_name("Cure disease");
    set_spell_level(5);
    set_school("healing");
    set_target_type("one");
    set_range(1);
    set_line_of_sight_needed(1);
    set_help_desc("   This spell will cure most diseases, although plague and "
      "a few rare strains may be beyond the scope of this spell.\n"
      "  Clerics with more "
      "powerful healing spheres will have more success with this "
      "spell.\n");

    set_gp_cost(10);
    set_casting_time(1);
    set_rounds( ({ "round1" }) );
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
    int i, j;
    object *stuff;
    /** added to kill parasites (shifter guild) **/
    if(target->query_property("infecting") == 1) {
	tell_room(environment(caster), 
	  caster->query_cap_name()+" summons of all "
	  "of "+caster->query_possessive()+" powers and focuses them "
	  "on "+target->query_cap_name()+"!\n\n");
	target->do_cure(caster);
	return 1;
    }
    if(!quiet)
    {
	tell_room(environment(caster),(string)caster->query_cap_name()+
	  " chants, 'illar camu enufus'.\n", ({target,caster}));
    }
    if(target == caster)
    {
	tell_object(target, "You chant, 'illar camu enufus'.\n");
	tell_object(target, "You cure yourself of disease.\n");
	tell_room(environment(caster),(string)caster->query_cap_name()+
	  " cures "+caster->query_possessive()+"self of disease.\n");
    }
    else
    {
	tell_object(caster, "You chant, 'illar camu enufus'.\n");
	tell_object(target, (string)caster->query_cap_name() +
	  " chants, 'illar camu enufus'.\n");
	tell_object(target, (string)caster->query_cap_name()+
	  " touches you curing you of diseases.\n");
	tell_object(caster, "You cast cure disease at "+
	  (string)target->query_cap_name() + ".\n");
	tell_room(environment(caster),(string)caster->query_cap_name()+
	  " casts a spell and cures "+target->query_cap_name()+
	  " of disease.\n",({target,caster}) );
    }
    stuff=all_inventory(target);
    for(j=0;j<sizeof(stuff);j++)
    {
	/* did interactive check on the off chance there is a player
	   named disease (my luck, there would be) */
	if((stuff[j]->query_name())=="disease")
	    stuff[j]->dest_me();
    }
    target->remove_timed_property("diseased");
    target->remove_static_property("diseased");
    target->remove_property("diseased");
    /*** GIVES EXP TO CASTER EQUAL TO THE VALUE RETURNED ***/
    return 10;
}


