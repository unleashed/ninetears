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
  return "\nSyntax:  turn <target1>,<target2>,...\n"
    "Cost: "+TURN_GP_COST+" GP\n\n"
    "  This command lets you bring forth the wrath of your god against "
    "undead creatures.  Depending on the level of the priest, a "
    "netherworld creature may be destroyed completely, turned (ie, "
    "forced to run away), simply cowed into not fighting, or "
    "enraged.  In order to focus the power of your god, a holy "
    "symbol is needed.  Once an attempt has been made to turn a creature, "
    "further attempts will usually fail. "
    "\n\n";
}

int turn(string str, object me)
{
  int i, lev, t_wis, t_lev;
  string has_symbol,guild;
  object *ob, *items;
  object turner;

  turner = me ? me : this_player();
  t_wis = (int)turner->query_wis();
  t_lev = (int)turner->query_level();
  guild = (string)turner->query_guild_name() ;
  if(guild == "taniwha") t_lev += 8;
  /* added by Raskolnikov for knights...*/
  if((guild == "antipaladin") || (guild == "paladin")) t_lev -= 3;

  str = turner->expand_nickname(str);

  if (!str)
  {
    notify_fail("Syntax: turn <target>\n");
    return 0;
  }

  has_symbol = "frooble";
  items = all_inventory(turner);
  for (i=0;i<sizeof(items);i++)
    if ((string)items[i]->query_name() == "holy symbol")
      has_symbol = (string)items[i]->query_property("faith");

  if (has_symbol=="frooble")
  {
    notify_fail("You need a holy symbol of your faith to turn undead.\n");
    return 0;
  }
  if (has_symbol != (string)turner->query_guild_name() )
  {
    tell_object(turner, "You are stricken by balefire for using an "
      "instrument of another faith!\n");
    tell_room(environment(turner), "A bolt of balefire comes out of "
      "nowhere and strikes "+turner->query_cap_name()+"!\n",
      turner);
    turner->set_gp(0);
    turner->adjust_hp( -(random(20))-10 ,turner);
    return 1;
  }

  ob = (object*)find_unique_match(str, environment(turner));

  if (!sizeof(ob))
  {
	notify_fail("Your target is not here.\n");
	return 0;
  }
  if ((int)turner->query_gp() < TURN_GP_COST )
  {
    notify_fail("You don't have the energy to turn any undead "
      "right now.\n");
    return 0;
  }

  turner->adjust_gp(-TURN_GP_COST);
  tell_room(environment(turner), "\n"+turner->query_cap_name()+
    " raises a holy symbol and calls down the wrath of "+
    turner->query_possessive()+" god!\n", turner);
  tell_object(turner, "You raise your holy symbol and call down the wrath "
    "of "+turner->query_guild_name()+"!\n");

  for (i=0;i<sizeof(ob);i++)
  {
    if (!living(ob[i]) || ob[i]->query_dead() || ob[i] == turner )
      continue;

    if (ob[i]->query_property("turned_by_"+turner->query_name()) )
    {
      tell_room(environment(turner), ob[i]->query_cap_name()+
        " howls in rage and attacks "+turner->query_cap_name()+"!\n",
        turner);
      tell_object(turner, ob[i]->query_cap_name()+ " howls in rage at "
        "your attempt to turn it again and \nattacks you!\n");
      ob[i]->attack_ob(turner);
      continue;
    }
    if ((lev = ob[i]->query_property("undead")))
    {
      switch( (t_wis + t_lev) - (lev + TURN_BASE + random(16) ))
      {
       /* anti's get a shot at control too...Rask */
        case 10..5000:
            if(((guild == "Cyrcia") || (guild == "antipaladin")) && (int)turner->query_alignment() > 10000)
      	 {
				tell_room(environment(turner),ob[i]->query_cap_name()+
			     " bows to a greater evil.\n");
				ob[i]->stop_fights();
				turner->add_follower(ob[i]);
            ob[i]->stop_fight(turner);
            turner->stop_fight(ob[i]);
         ob[i]->set_friend(turner);
			 }	
          else
			 {
          	tell_room(environment(turner), ob[i]->query_cap_name()+
            	" is utterly destroyed!\n",turner);
          	turner->adjust_xp((int)ob[i]->query_kill_xp()/TURN_DESTROY_XP,ob);
          	ob[i]->dest_me();  /* utter destruction leaves no corpse :) */
			 }
          break;
        case 5..9:
          tell_room(environment(turner),ob[i]->query_cap_name()+
            " is turned away!\n");
          turner->adjust_xp((int)ob[i]->query_kill_xp()/TURN_AWAY_XP,ob);
          ob[i]->run_away();
          ob[i]->stop_fight(turner);
          turner->stop_fight(ob[i]);
          break;
        case 0..4:
          tell_room(environment(turner), ob[i]->query_cap_name()+
            " cowers from the power but holds its ground.\n");
          ob[i]->stop_fight(turner);
          turner->stop_fight(turner);
          break;
        default:
          tell_room(environment(turner), ob[i]->query_cap_name()+
            " laughs defiantly and attacks "+turner->query_cap_name()+"!\n", 
            turner);
          tell_object(turner, ob[i]->query_cap_name()+" laughs defiantly and "
            "attacks you!\n");
          ob[i]->attack_ob(turner);
          break;
      }
      if (ob[i])
        ob[i]->add_timed_property("turned_by_"+turner->query_name(), 
          1, TURN_LOCKOUT);
    }
    else
    {
      tell_object(turner,ob[i]->query_cap_name()+" is not undead.  "+
        ob[i]->query_cap_name()+" gets mad and attacks you.\n");
      tell_room(environment(turner), ob[i]->query_cap_name()+
        " notices "+turner->query_cap_name()+" using a holy symbol at "+
        ob[i]->query_objective()+".\n"+ob[i]->query_cap_name()+" gets mad "
        "and attacks "+turner->query_objective()+".\n", turner);
      ob[i]->attack_ob(turner);
    }
  }  
  return 1;
}
