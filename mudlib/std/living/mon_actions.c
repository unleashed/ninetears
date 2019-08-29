#define MONSTER_HAND "/obj/handlers/monster_handler"
mixed *spells;

void create() {
  spells = ({ });
}

void do_shadow() {
  int i, num;
  object ob;
  string fname;
  mixed myeuid;

/* do we wint the sleaze of the year award???? */
  this_object()->shadow_death();
  fname = (string)MONSTER_HAND->query_shadow_name();
  myeuid = geteuid(this_object());
  seteuid("Root");
  rm(fname+".c");
  for (i=0;i<sizeof(spells);i+=2)
    write_file(fname+".c",
               "inherit \"/std/trigger/"+spells[i]+"\";\n");
  write_file(fname+".c", read_file("/std/living/mon-shadow.c"));
  ob = clone_object(fname);
  ob->setup_shadow(this_object());
  rm(fname+".c");
  seteuid(myeuid);
}

int add_triggered_action(string name, string trigger, mixed ob,
                         string func) {
  /* Sorry, nope, this is all gone.  Wonderflug '96
  int i, j;

  if ((i=member_array(trigger, spells)) == -1) {
    spells += ({ trigger, ({ name, ({ ob, func }) }) });
    do_shadow();
  } else if ((j=member_array(name, spells[i+1])) == -1)
    spells[i+1] += ({ name, ({ ob, func }) });
  else
    spells[i+1][j+1] = ({ ob, func });
  * Now to log an error instead.
  */

  string fix;

  log_file("NPCSTOFIX", file_name(this_object())+" tried to add "
    +trigger+".\n");
  if ( !objectp(ob) ) ob = load_object(ob);
  if ( !function_exists(func, ob) )
    fix = "Just take out the add_triggered_action.  It never did a damn "
      "thing for this monster anyway.\n";
  else switch( trigger )
  {
    case "death": 
      fix = "Change the name of "+func+"() to be "
        "second_life()\n";
      break;
    case "enter": 
      fix = "Change the name of "+func+"() to be event_enter()\n";
      break;
    case "event_death":
      fix = "Change the name of "+func+"() to be event_death()\n";
      break;
    case "event_fight":
      fix = "Change the name of "+func+"() to be event_fight_in_progress()\n";
      break;
    case "exit":
      fix = "Change the name of "+func+"() to be event_exit()\n";
      break;
    case "fight":
      fix = "Change the name of "+func+"() to be event_pub_brawl()\n";
      break;
    case "light_change":
      fix = "Change the name of "+func+"() to be event_light_change()\n";
      break;
    case "player_say":
      fix = "Change the name of "+func+"() to be event_person_say()\n";
      break;
    case "player_tell":
      fix = "Change the name of "+func+"() to be event_player_tell()\n";
      break;
    case "pub_brawl":
      fix = "Change the name of "+func+"() to be event_pub_brawl(), and "
        "remove the third parameter to the function; wherever the third "
        "parameter is needed previous_object() may be used instead.\n";
      break;
    case "say":
      fix = "Change the name of "+func+"() to be event_say()\n";
      break;


    case "goto_co_ord":
    case "goto_destination":
    case "goto_player":
    case "spell_effects":
    default:
      fix = "This trigger is no longer supported.  Whine enough and it "
        "may be.\n";
  }
 
  log_file("NPCSTOFIX", "  Fix: " + fix );

}

int remove_trigger(string name) {
  int i;

  if ((i=member_array(name, spells)) == -1)
    return 0;
  spells = delete(spells, i, 2);
  if (!sizeof(spells))
    this_object()->shadow_death();
  else
    do_shadow();
  return 1;
}

int remove_triggered_action(string trigger, string name) {
  int i, j;

  if ((i=member_array(trigger, spells)) == -1)
    return 0;
  if ((j=member_array(name, spells[i+1])) == -1)
    return 0;
  spells[i+1] = delete(spells[i+1], i, 2);
  if (!sizeof(spells[i+1]))
    remove_trigger(trigger);
  return 1;
}

mixed *query_actions(string trigger) {
  int i;

  if ((i=member_array(trigger, spells)) == -1)
    return ({ });
  return spells[i+1];
}

// Taniwha, 1995, it's in /global/spells.c
//mixed *query_spells() { return spells; }
