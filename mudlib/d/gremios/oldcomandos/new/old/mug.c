/*** MuG ***/
/*** By Wonderflug ***/

#define MUG_GP 5
#define MUG_LOCKOUT 50
#define STUN_SHADOW "/d/gremios/comandos/shadows/stun.c"

string help()
{
  return "\nSyntax:  mug <target>\n"
	"Cost: "+MUG_GP+" GP\n\n"
	"     This command lets you try and mug someone.  Mugging "
	"someone constitutes sneaking up behind them and coshing them "
	"over the head with a large blunt weapon, hopefully knocking them "
	"senseless for a few rounds so you can rob them blind while they "
	"recover.  So, you must of course be hidden and be holding a blunt "
	"weapon.  There's such an adrenaline rush associated with doing "
	"this that you can't do it too often."
	"\n\n";
}

int mug(string str, object doer)
{
  int i, damage;
  object *ob;
  object mugger, weap, shad;
  object target;

  mugger = doer ? doer : this_player();

  if (!str)
  {
	tell_object(mugger,"Syntax: mug <target>\n");
	return 1;
  }

  if ((int)mugger->query_property("just mugged"))
  {
	tell_object(mugger, "You're too excited from that last mugging to "
	  "attempt one again.\n");
	return 1;
  }
  if ((int)mugger->query_gp() < MUG_GP )
  {
	tell_object(mugger,"You don't have the energy to mug anyone "
	  "right now.\n");
	return 1;
  }
  if (sizeof(mugger->query_attacker_list()) )
  {
	tell_object(mugger,"Hard to mug someone while you're fighting.\n");
	return 1;
  }
  if ( !mugger->query_hide_shadow() )
  {
	tell_object(mugger,"It'd be a good idea to be hidden first so they "
	  "don't see you coming.\n");
	return 1;
  }

  /* Find the target */
  ob = (object*)find_match(str, environment(mugger));

  if (!(sizeof(ob)))
  {
        tell_object(mugger,"Your target is not here.\n");
        return 1;
  }
  target = ob[0];
  if ( target->query_creator() )
  {
        tell_object(mugger,"Not wise to mug immortals.\n");
        return 1;
  }
  if ( member_array(mugger,target->query_attacker_list()) != -1 )
  {
	tell_object(mugger, "Hard to mug someone you're fighting.\n");
	return 1;
  }

  /* Make sure he's holding a blunt weapon */
  ob = (object*)mugger->query_held_ob();
  if ( !sizeof(ob) || (!ob[0] && !ob[1]) )
  {
        tell_object(mugger,"You try to mug someone with your bare hands, "
          "but it just doesn't work too well.\n");
        tell_room(environment(mugger), mugger->query_cap_name()+" tries to "
          "mug "+target->query_cap_name()+" with "+mugger->query_possessive()+
          " bare hands, and doesn't do too well.\n",
          ({ mugger, target }) );
	tell_object(target, mugger->query_cap_name()+" comes leaping out "
	  "of nowhere at you with "+target->query_possessive()+" bare hands, "
	  "looking somewhat confused.\n");
	target->attack_ob(mugger);
        return 1;
  }

/* attack type returns 2 for blunt weapons.  see /table/weapon_table */
  for ( i=0; i<sizeof(ob); i++)
	if ( ob[i] && (int)ob[i]->query_attack_type() == 2 )
		weap = ob[i];
  if (!weap)
  {
	tell_object(mugger, "You really think next time you should use a "
	  "blunt weapon for this.\n");
	tell_room(environment(mugger), mugger->query_cap_name()+
	  " tries to cosh "+target->query_cap_name()+" over the head "
	  "with a "+ob[0]->query_name()+", of all things.\n",
	  ({ mugger, target }) );
	tell_object(target, mugger->query_cap_name()+" tries to cosh "
	  "you over the head with a "+ob[0]->query_name()+", of all things. "
	  "You almost pity the poor thing.\n");
	target->attack_ob(mugger);
	return 1;
  }

  mugger->add_timed_property("just mugged",1,MUG_LOCKOUT);
  mugger->adjust_gp(-MUG_GP);

  switch( (string)target->query_race() )
  {
	case "human":
	case "orc":
	case "half-elf":
	case "half-orc":
	case "elf":
	case "goblin":
	case "drow":
	case "halfling":
	case "lizard-man":
	case "dwarf":
	case "gnome":
       case "duergar":
		break;
	default:
	  tell_object(mugger, "You try quite unsuccessfully to mug "+
		target->query_cap_name()+".\n");
	  tell_room(environment(mugger), mugger->query_cap_name()+
		" tries to mug "+target->query_cap_name()+" and is "
		"quite unsuccessful.\n", ({mugger, target}));
	  tell_object(target, mugger->query_cap_name()+
		" foolishly tries to mug you.\n");
	  target->attack_ob(mugger);
	  return 1;
  }

  /* Make a hit roll.  mugger->query_thac0 vs. target->query_total_ac - 4
   * straight and simple. 
   */

  //if ( (int)target->query_dex()+random((int)target->query_level()) >
  // Giving a better chance, for now.  Wonderflug, nov '95
  if ( (int)target->query_level() + random(8) >
     random((int)mugger->query_level()+(int)mugger->query_dex()) )
  {
	tell_room(environment(mugger), mugger->query_cap_name()+
	  " tries to mug "+target->query_cap_name()+" but misses.\n",
	  ({ mugger, target }) );
	tell_object(mugger, "You try to mug "+target->query_cap_name()+
	  " but miss.\n");
	tell_object(target, mugger->query_cap_name()+" tries to mug you "
	  "but you dodge out of the way.\n");
	target->attack_ob(mugger);
	return 1;
  }
  tell_object(target,"You feel a sharp crack to the back of your head and "
	"then nothing..\n");
  tell_room(environment(target),mugger->query_cap_name()+" rises up out "
	"of the shadows and coshes "+target->query_cap_name()+" on the "
	"head.\n",
	({ mugger, target }) );
  tell_object(mugger,"You leap out and nail "+target->query_cap_name()+
	" with a satisfying crack to the back of the skull.\n");
  tell_room(environment(target),target->query_cap_name()+" slumps to "
	"the ground in a heap.\n", target);

  damage = (int)weap->query_damage_roll();
  damage += mugger->query_damage_bonus();
  damage *= 2;
  
  target->add_timed_property("passed out",1,damage);
  target->add_timed_property("steal at will",1,damage);
  target->add_timed_property("stun_on",1,damage);

  shad = clone_object(STUN_SHADOW);
  shad->setup_shadow(target);

/* Leave this out for now.. otherwise can't steal from the muggee 
  target->attack_by(mugger);
*/
  target->adjust_hp(-damage*3/2,mugger);
/*
  target->stop_fight(mugger);
  mugger->stop_fight(target);
*/

  mugger->dest_hide_shadow();
  return 1;
}
