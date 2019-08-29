/* Surge, basically a modifided haste.   Shaper, june 96  */

#include "/d/gremios/comandos/tweaks.h"

#define SURGE_SHADOW "/d/gremios/comandos/shadows/surge_sh.c"
#define SP_NAME "Surge"
#define GP_DIVIDER 2

inherit "/d/gremios/hechizos/patch.c";

void make_spell(object caster, int duration);

string help() 
{
    return
    "\n\n"
    "Spell Name: "+SP_NAME+"\n"
    "Gp Cost: Player's level/"+GP_DIVIDER+"\n"
    "Description: \n"
    "This is a skill of the Drow Warrior that allows him to get a burst "
    "of adrenaline, which can only be done during a fight.  "
    "This allows for quicker movements over a period of "
    "time.\n\n";
}

int surge(string str, object caster)
{
    int GP_COST;
    int new_count;
    int duration;
    int i;
    object *atts;
    object target, my_caster;
    if(!caster) caster = this_player();
    GP_COST = caster->query_level()/GP_DIVIDER;

    my_caster=caster;

    /*  conditions  */
    atts = caster->query_attacker_list();

    if(!sizeof(atts))  {
	tell_object(caster,"Al no estar en peleas tu cuerpo no produce "
	  "la adrenalina suficiente.\n");
	return 1;
    }
    if ((int)my_caster->query_gp() < GP_COST ) {
	tell_object(my_caster,"Te encuentras demasiado cansado para acelerarte.\n");
	return 1;
    }

    if (my_caster->query_timed_property("SURGE_LOCKOUT")) {
	tell_object(my_caster, "Tu cuerpo no resistiria otra descarga de "
	  "adrenalina por ahora, deja que descanse.\n");
	return 1;
    }

    if ( caster->query_slow_spell() )  {
	caster->dispell_time_spell();
	return 1;
    }

    if ( caster->query_time_spell() ) {
	// Y si llevo el haste encima? xD
	tell_object(caster, "Ya estas acelerado.\n");
	return 1;
    }

    if ( caster->query_hold_spell() || caster->query_pacify_spell() )
    {
	tell_object(caster, "No puedes acelerarte en este momento.\n");
	return 1;
    }

    if(caster->query_property("noguild") || environment(caster)->
      query_property("noguild"))
    {
	tell_object(caster,"Algo te impide acelerarte.\n");
	return 1;
    }

    /* end of conditions */


    duration = (int)my_caster->query_level();


    my_caster->adjust_gp(-GP_COST);
    call_out("make_spell",0,my_caster,duration);
    caster->add_timed_property("SURGE_LOCKOUT", 1, caster->query_level());
    return 1;
}


void make_spell( object caster, int duration ) {
    object* ob;
    object shad;


    //tell_room(environment(caster), caster->query_cap_name()+
    //  " suddenly becomes very flushed.\n", caster);
    tell_room(environment(caster), caster->query_cap_name()+
      " empieza a moverse mucho mas rapido de lo normal!\n",
      ({ caster }) ); 
    tell_object(caster, "Sientes una fuerte descarga de adrenalina "
      "y empiezas a moverte mucho mas rapido.\n\n");

    caster->add_timed_property("haste_on", 1, duration);

    shad = clone_object(SURGE_SHADOW);
    shad->setup_shadow(caster); 

    return;
}
