/* Hide in shadows.
   Finally screwed Taniwha 1995
*/
#include "/d/gremios/comandos/tweaks.h"
#define EXTRA_BONUS 5
#define HIDE_SKILL 20
#define COST HIDE_COST
#define SHADOW "/d/gremios/comandos/shadows/hide"

int hide_skill_bonus();

int hide_in_shadows(string str,object hider)
{
    int sk_bon;
    object me;
    object ob;

    if(hider) me = hider;
    else me = this_player();

    if ((int)me->query_gp() < COST)
    {
	tell_object(me,"Estas demasiado cansado para esconderte.\n");
	return 1;
    }
    if ( sizeof( me->query_attacker_list() ) )
    {
	tell_object(me,"Esconderse en mitad de una lucha?? no seas cobarde...!\n");
	return 1;
    }
    if(me->query_guild_name() == "ranger" && !environment(me)->query_outside() )
    {
	write("No hay nada aqui para que un Ranger se pueda esconder.\n");
	return 1;
    }

    if(me->query_light() > 20)  {
	tell_object(me, "Has visto alguna vez una antorcha escondida? pues es lo que "
	  "pareces ahora mismo, imposible esconderse asi.\n");
	return 1;
    }
    me->adjust_gp(-COST);
    sk_bon = (int)me->query_level() + hide_skill_bonus();

    if (sk_bon > random(HIDE_SKILL) && !me->query_hide_shadow())
    {
	ob = clone_object(SHADOW);
	ob->setup_shadow(me);
    }
    tell_object(me,"Te escondes entre las sombras.\n");
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

string help()
{
    return "Sintaxis: Esconderse\n\nPermite esconderte entre las sombras. Esto "
    "quiere decir que escapas a la vista de los otros. Que te escondas realmente "
    "depende de tu nivel y cuesta "+ COST +" punto de guild aunque no consigas ."
    "esconderte.\n"
    "\n\nEjemplo:\n> esconderse\nTe escondes entre las sombras.\n\n";
}

