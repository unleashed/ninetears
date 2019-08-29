/* Hide in shadows.
   Finally screwed Taniwha 1995
*/
/* Tradusio por Oskuro, Patron del Ladron */
// Modificado por Spp Ene'98

#include "/std/commands/tweaks.h"
#define EXTRA_BONUS 5
#define HIDE_SKILL 20
#define COST HIDE_COST
#define SHADOW "/std/commands/shadows/hide"

int hide_skill_bonus();

string help()
{
    return
    "Comando: Esconderse\n"
    "Coste GP: "+HIDE_COST+"\n"
    "Sintaxis: esconderse <objetivo>\n"
    "Descripcion:\n"
    "    Este comando te permite esconderte entre las sombras y pasar "
    "desapercibido a los ojos de otros jugadores. El exito se basa en "
    "el nivel de aquel que lo intenta. El comando resta los GP tanto "
    "tanto si es fallido como si no.\nEjemplo:\n> esconderse\nIntentas "
    "esconderte entre las sombras.\n\nMirar tambien:\n  sigilar.\n";
}


int hide_in_shadows(string str,object hider)
{
    int sk_bon;
    object me;
    object ob;

    if(hider) me = hider;
    else me = this_player();


    if ((int)me->query_gp() < COST)
    {
	notify_fail("Estas demasiado cansado y no tienes ganas de "
	  "esconderte.\n");
	return 0;
    }
    if ( sizeof( me->query_attacker_list() ) )
    {
	notify_fail("No puedes esconderte en medio de una pelea!\n");
	return 0;
    }
    if(me->query_mirror_spell()>1)
    {
	notify_fail("Intentas esconderte entre las sombras (pero tus imagenes parece que no)\n");
	return 0;
    }
    if(me->query_guild_name() == "ranger" && !environment(me)->query_outside())
    {
	notify_fail("No hay nada por aqui donde un Ranger se pueda esconder.\n");
	return 0;
    }

    if(me->query_light() > 20)
    {
	notify_fail("Seria imposible que te escondieses con esa luz que "
	  "emites. Pareces una antorcha!\n");
	return 0;
    }
    if (me->query_property("recien_descubierto") == ENV(me))
    {
    	notify_fail("Acabas de ser descubierto, espera un poco para volver a esconderte.\n");
		return 0;
    }
    
    me->adjust_gp(-COST);
    sk_bon = (int)me->query_level() + hide_skill_bonus();

    if (sk_bon > random(HIDE_SKILL) && !me->query_hide_shadow())
    {
	ob = clone_object(SHADOW);
	ob->setup_shadow(me);
    }
    tell_object(me,"Intentas esconderte entre las sombras.\n");
    return 1;
}

// Shauri, 23-11-95 updating hide for guilds

int hide_skill_bonus()
{
    int bonus=0;

    switch((string)this_player()->query_guild_name()) {
    case "ranger":
	if(environment(this_player())->query_outside())
	    bonus = EXTRA_BONUS;
	break;
    case "wizthief":
	if((string)environment(this_player())->query_property("location") == "inside")
	    bonus = EXTRA_BONUS;

	else if((int)environment(this_player())->query_light() <= 15)
	    bonus = EXTRA_BONUS;
	break;
    case "bard":
	if((string)environment(this_player())->query_property("location") == "inside") {
	    if(member_array("/std/pub.c",deep_inherit_list(environment(this_player()))) >= 0 ||
	      member_array("bedroom",explode(environment(this_player())->query_long()," ")) >= 0)
		bonus = EXTRA_BONUS;
	}
	break;
    }
    return (bonus);
}
