/* Turn */
/* By Wonderflug */
/* Modified for knights by Raskolnikov */

#define TURN_GP_COST 5
#define TURN_BASE 12
#define TURN_DESTROY_XP 5
#define TURN_AWAY_XP 10
#define TURN_LOCKOUT 50

inherit "/d/gremios/hechizos/patch.c";


string help()
{
    return "\nSyntax:  repeler <objetivo1>,<objetivo2>,...\n"
    "Coste: "+TURN_GP_COST+" PGs\n\n"
    "  This command lets you bring forth the wrath of your god against "
    "undead creatures.  Depending on the level of the priest, a "
    "netherworld creature may be destroyed completely, turned (ie, "
    "forced to run away), simply cowed into not fighting, or "
    "enraged.  In order to focus the power of your god, a holy "
    "symbol is needed.  Once an attempt has been made to turn a creature, "
    "further attempts will usually fail.  One should also note that "
    "this command will not overcome many of the undead's natural tendencies.  "
    "this includes any instructions given to it by its creator.\n\n";
    "\n\n";
}

int turn(string str, object me)
{
    int i, lev, t_wis, t_lev, alguien;
    string has_symbol,guild;
    object *ob, *items;
    object turner;

    turner = me ? me : this_player();
    t_wis = (int)turner->query_wis();
    t_lev = (int)turner->query_level();
    guild = (string)turner->query_guild_name() ;
    if(guild == "taniwha") t_lev += 8;
    /* added by Raskolnikov for knights...*/
    if((guild == "caballero de jade") || (guild == "paladin")) t_lev -= 3;

    str = turner->expand_nickname(str);

    if (!str)
    {
	notify_fail("Syntax: repeler <nomuerto>\n");
	return 0;
    }

    has_symbol = "frooble";
    items = all_inventory(turner);
	// y si llevo dos simbolos, uno de mi fe?
    for (i=0;i<sizeof(items);i++)
	if ((string)items[i]->query_name() == "holy symbol")
	    has_symbol = (string)items[i]->query_property("faith");

    if (has_symbol=="frooble")
    {
	notify_fail("Necesitas tu simbolo sagrado para repeler a los no muertos.\n");
	return 0;
    }
    if (has_symbol != (string)turner->query_guild_name() )
    {
	tell_object(turner, "Un fuego divino te quema por usar un "
	  "simbolo de otra fe!\n");
	tell_room(environment(turner), "Aparece fuego a partir de la nada "
	  "rodeando a "+turner->query_cap_name()+", quemandolo ligeramente!\n",
	  turner);
	turner->set_gp(0);
	turner->adjust_hp( -(random(20))-10 ,turner);
	return 1;
    }

    ob = (object*)find_unique_match(str, environment(turner));

    alguien = 0;
    for(i=0;i<sizeof(ob);i++) {
    	if (ob[i]->query_hidden())
    		continue;
    	alguien++;
    	
    }
    if (!alguien)
    {
	notify_fail("Tu objetivo no se encuentra aqui.\n");
	return 0;
    }
    if ((int)turner->query_gp() < TURN_GP_COST )
    {
	notify_fail("No posees la energia para repeler a los no muertos "
	  "ahora mismo.\n");
	return 0;
    }

// mmm, mirar lo de los dioses vs guilds y tal.
    turner->adjust_gp(-TURN_GP_COST);
    tell_room(environment(turner), "\n"+turner->query_cap_name()+
      " alza su simbolo sagrado e invoca la ira de su dios!\n", turner);
    tell_object(turner, "Alzas tu simbolo sagrado e invocas la ira "
      "de los "+CAP(turner->query_guild_name())+"es!\n");

    for (i=0;i<sizeof(ob);i++)
    {
	if (!living(ob[i]) || ob[i]->query_dead() || ob[i] == turner )
	    continue;

	if (ob[i]->query_property("turned_by_"+turner->query_name()) )
	{
	    tell_room(environment(turner), ob[i]->query_cap_name()+
	      " desata su furia y ataca a "+turner->query_cap_name()+"!\n",
	      turner);
	    tell_object(turner, ob[i]->query_cap_name()+ " desata su furia "
	      "al intentar volver a repelerlo\ny te ataca!\n");
	    ob[i]->attack_ob(turner);
	    continue;
	}
	if ((lev = ob[i]->query_property("undead")))
	{
	    switch( (t_wis + t_lev) - (lev + TURN_BASE + random(16) ))
	    {
		/* anti's get a shot at control too...Rask */
	    case 10..5000:
		if(((guild == "Cyrcia") || (guild == "antipaladin")) && turner->query_align_name() == "diabolical")
		{
		    tell_room(environment(turner),ob[i]->query_cap_name()+
		      " muestra sus respetos a una maldad mayor.\n");
		    ob[i]->stop_fights();
		    turner->add_follower(ob[i]);
		    ob[i]->stop_fight(turner);
		    turner->stop_fight(ob[i]);
		    ob[i]->set_aggressive(0);
		    ob[i]->do_command("proteger "+turner->query_name());
		}	
		else
		{
		    tell_room(environment(turner), ob[i]->query_cap_name()+
		      " se esparce en mil pedazos que se evaporan!\n",turner);
		    turner->adjust_xp((int)ob[i]->query_kill_xp()/TURN_DESTROY_XP,ob);
		    ob[i]->dest_me();  /* utter destruction leaves no corpse :) */
		}
		break;
	    case 5..9:
		tell_room(environment(turner),ob[i]->query_cap_name()+
		  " es repelido magicamente!\n");
		turner->adjust_xp((int)ob[i]->query_kill_xp()/TURN_AWAY_XP,ob);
		ob[i]->run_away();
		ob[i]->stop_fight(turner);
		turner->stop_fight(ob[i]);
		break;
	    case 0..4:
		tell_room(environment(turner), ob[i]->query_cap_name()+
		  " se acobarda ante el poder pero rehusa huir.\n");
		ob[i]->stop_fight(turner);
		turner->stop_fight(ob[i]);
		break;
	    default:
		tell_room(environment(turner), ob[i]->query_cap_name()+
		  " se rie desafiante y ataca a "+turner->query_cap_name()+"!\n", 
		  turner);
		tell_object(turner, ob[i]->query_cap_name()+" se rie desafiante y "
		  "te ataca!\n");
		ob[i]->attack_ob(turner);
		break;
	    }
	    if (ob[i])
		ob[i]->add_timed_property("turned_by_"+turner->query_name(), 
		  1, TURN_LOCKOUT);
	}
	else
	{
	    tell_object(turner,ob[i]->query_cap_name()+" no es un no muerto. "+
	      ob[i]->query_cap_name()+" se enfada y te ataca.\n");
	    tell_room(environment(turner), ob[i]->query_cap_name()+
	      " nota el poder del simbolo de "+turner->QCN+" sobre "+
	      ob[i]->query_objective()+".\n"+ob[i]->query_cap_name()+" se enfada "
	      "y ataca a "+turner->query_objective()+".\n", turner);
	    ob[i]->attack_ob(turner);
	}
    }  
    return 1;
}
