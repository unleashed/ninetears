/* Surge, basically a modifided haste.   Shaper, june 96  */

#include "/d/gremios/comandos/tweaks.h"

#define SURGE_SHADOW "/d/gremios/comandos/shadows/surge_sh.c"
#define SP_NAME "Agitarse"
#define GP_DIVIDER 2

inherit "/std/spells/patch.c";

void make_spell(object caster, int duration);

string help() 
{
    return
    "\n\n"
    "Nombre: "+SP_NAME+"\n"
    "Coste en Pg: Nivel del player/"+GP_DIVIDER+"\n"
    "Descripcion: \n"
    "Esto es una habilidad que solo poseen los guerreros Drow que les permite "
    "conseguir gran cantidad de anedralina, esto solo puede ser hecho en medio de un combate.  "
    "Esta habilidad permite moverse mas rapido en un periodo de tiempo "
    "determinado.\n\n";
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
	tell_object(caster,"Mientras no estes en peligro, tu cuerpo "
	  "no puede generar suficiente anedralina para que te agites.\n");
	return 1;
    }
    if ((int)my_caster->query_gp() < GP_COST ) {
	tell_object(my_caster,"Estas demasiado cansado para agitarte.\n");
	return 1;
    }

    if (my_caster->query_timed_property("SURGE_LOCKOUT")) {
	tell_object(my_caster, "No crees que tu cuerpo resistira otra "
	  "subida de anedralina por ahora.\n");
	return 1;
    }

    if ( caster->query_slow_spell() )  {
	caster->dispell_time_spell();
	return 1;
    }

    if ( caster->query_time_spell() ) {
	tell_object(caster, "Tu ya estas agitado.\n");
	return 1;
    }

    if ( caster->query_hold_spell() || caster->query_pacify_spell() )
    {
	tell_object(caster, "No puedes agitarte ahora.\n");
	return 1;
    }

    if(caster->query_property("noguild") || environment(caster)->
      query_property("noguild"))
    {
	tell_object(caster,"Algo te sucede, pero no puedes agitarte ahora.\n");
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


    tell_room(environment(caster), caster->query_cap_name()+
      " de repente comienza a ponerse nervioso.\n", caster);
    tell_object(caster, "Notas como fluye tu anedralina por todo tu cuerpo, y "
      "comienzas a moverte mas rapido.\n\n");
    tell_room(environment(caster), caster->query_cap_name()+
      " de repente se mueve mucho mas rapido de lo normal!\n",
      ({ caster }) ); 

    caster->add_timed_property("haste_on", 1, duration);

    shad = clone_object(SURGE_SHADOW);
    shad->setup_shadow(caster); 

    return;
}

