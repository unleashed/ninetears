/*** Bearhug ***/
/*** By Wonderflug ***/

inherit "/d/gremios/hechizos/patch.c";
object check_melee_protector(object, object);

#define BEARHUG_GP_ROUND 2
#define BEARHUG_LOCKOUT 20
#define BEARHUG_GRAB_GP 4

#define BEARHUG_HUGGER_SHADOW "/d/gremios/comandos/bearhug_hsh.c"
#define BEARHUG_TARGET_SHADOW "/d/gremios/comandos/bearhug_tsh.c"
#define BEARHUG_HUGGER_OBJECT "/d/gremios/comandos/bearhug_hobj.c"

string help()
{
  return "\nSyntax:  abrazo <objetivo>\n"
    "Coste: "+BEARHUG_GRAB_GP+" GP to start, "+
    BEARHUG_GP_ROUND+" GP per round\n\n"
    "     Bearhug lets you grab an opponent into your arms and try "
    "to squeeze them to death.  While in the bearhug, neither you nor "
    "your opponent may attack or move, and your opponent will take a "
    "small amount of damage.  The bearhugs lasts until you either run "
    "out of GP, 'release' the opponent, or your opponent breaks free. "
    "Stronger and more dextrous opponents will stand a better chance "
    "of breaking free.  Only humanoid creatures can be caught in a "
    "bearhug.\nNote: Chances are a lot of npc's that SHOULD be human "
    "are not right now.  Post on your guild board and/or mail me about "
    "these and we'll try to get them fixed."
    "\n\n";
}

int bearhug(string str, object doer)
{
  int i;
  object *ob;
  object hugger;
  object target;
  object h_shadow, t_shadow;
  object h_obj;

  hugger = doer ? doer : this_player();

  str = hugger->expand_nickname(str);

  if (!str)
  {
    tell_object(hugger,"Sintaxis: abrazo <objetivo>\n");
    return 1;
  }
/*  if(interactive(hugger))
  {
    tell_object(hugger, "Oops! You really don't know what you're doing, "
      "and may as well forget it.\n");
    hugger->remove_known_command("bearhug");
    return 1;
  } */
  if ( hugger->query_property("flipped") )
  {
    tell_object(hugger, "You lack the patience to sit and bearhug "
      "someone in your berserked rage.\n");
    return 1;
  }
  if ( hugger->query_property("bearhug_done") )
  {
    tell_object(hugger, "Your arms are tired from bearhugging already.\n");
    return 1;
  }

  /* Make sure they're not holding anything */
  if ((int)hugger->query_gp() < BEARHUG_GP_ROUND )
  {
    tell_object(hugger,"You don't have the energy to bearhug anything "
      "right now.\n");
    return 1;
  }
  ob = (object*)hugger->query_held_ob();
  if (sizeof(ob) && ( ob[0] || ob[1] ))
  {
    tell_object(hugger,"Como vas a coger a alguien con las manos ocupadas?\n");
    return 1;
  }

  /* Find the target */
  ob = (object*)find_match(str, environment(hugger));

  if (!(sizeof(ob)))
  {
    tell_object(hugger,"Tu objetivo no esta aqui.\n");
    return 1;
  }
  target = ob[0];
  target = check_melee_protector( target, hugger );
  if (target->query_time_spell() || target->query_hold_spell() )
  {
    tell_object(hugger, "No puedes abrazar a "+target->query_cap_name()+
      " ahora mismo.\n");
    return 1;
  }

  hugger->adjust_gp(-BEARHUG_GRAB_GP);
  hugger->add_timed_property("bearhug_done", 1, BEARHUG_LOCKOUT);

  /* Check the race of the target.  Non-humanoid = non-huggable */
  switch( (string)target->query_race() )
  {
    case "duergar":
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
      break;
    default:
      tell_object(hugger, "Intentas en vano abrazar a "+
        target->query_cap_name()+".\n");
      tell_room(environment(hugger), hugger->query_cap_name()+
        " intenta en vano coger a "+target->query_cap_name()+
        ".\n", ({hugger, target}));
      tell_object(target, hugger->query_cap_name()+
        " intenta estupidamente abrazarte.\n");
      target->attack_ob(hugger);
      return 1;
  }

  /* Make a hit roll.  hugger->query_thac0 vs. target->query_total_ac
   * straight and simple.  The 'straight' roll happens at ac 0, which is
   * maybe a little easy.
   */

  if ( random(200) < 
       (int)hugger->query_thac0() - (int)target->query_total_ac() )
  {
    tell_room(environment(hugger), hugger->query_cap_name()+
      " intenta coger a "+target->query_cap_name()+" pero falla.\n",
      ({ hugger, target }) );
    tell_object(hugger, "Intentas abrazar a "+target->query_cap_name()+
      " pero fallas.\n");
    tell_object(target, hugger->query_cap_name()+" intenta abrazarte "
      "pero esquivas sus brazos.\n");
    target->attack_ob(hugger);
    return 1;
  }
  /* Success */
  tell_object(hugger,"Abrazas a "+target->query_cap_name()+" sometiendolo "
    "a una presion mortifera.\n");
  tell_object(target,hugger->query_cap_name()+" te abraza y comienza "
    "a presionarte fuertemente exprimiendo tu vida!\n");
  tell_room(environment(hugger), hugger->query_cap_name()+" atrapa a "+
    target->query_cap_name()+" entre sus poderosos brazos!\n",
    ({ hugger, target }) );

  /* Now clone the shadows and return. */
  h_obj = clone_object(BEARHUG_HUGGER_OBJECT);

  h_shadow = clone_object(BEARHUG_HUGGER_SHADOW);
  h_shadow->setup_shadow(hugger, target, h_obj);

  t_shadow = clone_object(BEARHUG_TARGET_SHADOW);
  t_shadow->setup_shadow(target, hugger, h_obj);

  h_obj->move(environment(hugger));
  h_obj->setup_item(hugger, target);
  h_obj->reset_get();
  h_obj->reset_drop();

  target->add_static_property("noguild", 1);
  target->add_static_property("nocast", 1);
  hugger->add_static_property("noguild", 1);
  hugger->add_static_property("nocast", 1);

  target->attack_by(hugger);

  return 1;
}
