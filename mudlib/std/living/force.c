/* code to handle forcing.   The method used will be to ask the object to
 * do the command.  While this is similar to the original method of doing this
 * it will be used to be more in the style of asking things to do things,
 * rather than the making things do things without asking them first. */

#define FORCE_COST 1
#define ILLEGAL_FORCE ({ "alias", "unalias", "mv", "mkdir", "call", "rm", \
                         "force", "kill", "gauge", "exec", "promote", \
                         "new_domain", "rmdir", "cd", "history", "echoall", "shout" })

nosave string fname;
nosave int no_force_me;


void force_commands() {
  sscanf(file_name(this_object()), "%s#", fname);
  if(!this_object()->query_property("npc") &&
     this_object()->query_property("force") || fname == "/global/lord")
    add_action("do_force", "forzar");
  if(fname == "/global/lord")
    add_action("no_force", "noforzar");
} /* force_commands() */

nomask int no_force(string str) {
  if(fname!="/global/lord")
    return 0;
  if(str == "on") {
    no_force_me = 1;
    write("Ok.\n");
    return 1;
  }
  if(str == "off") {
    no_force_me = 0;
    write("Ok.\n");
    return 1;
  }
  write("Forcing you is currently ");
  if(no_force_me) {
    write("disabled.\n");
  }
  else {
    write("enabled.\n");
  }
  return 1;
} /* no_force() */

int do_force(string str) {
  string who, what;
  object *obs, ob;
  int i;

  if(fname == "/global/player" && !this_player()->query_property("force")) {
    notify_fail("Tu, mero mortal, no puedes hacer eso.\n");
    return 0;
  }
  if(!str || sscanf(str, "%s %s", who, what) != 2) {
    notify_fail("Uso : forzar <person> <command>\n");
    return 0;
  }
  if(this_player()->adjust_social_points(-FORCE_COST) < 0) {
    notify_fail("Insufficient social points.\n");
    return 0;
  }
  who = (string)this_player()->expand_nickname(who);
  who = lower_case(who);
  obs = find_match(who, environment(this_object()));
  if (!sizeof(obs))
    if (!(ob = find_living(who))) {
      notify_fail("No such living thing.\n");
      return 0;
    } else
      obs += ({ ob });
  for (i=0;i<sizeof(obs);i++)
    if(!obs[i]->do_force_on_me(what))
      write(capitalize(who) + " didn't want to do that.\n");
  write("Ok.\n");
  return 1;
} /* do_force() */

int do_force_on_me  (string str) {
  string temp1, temp2;
  object forcer;

  forcer = this_player(1);
  if(!forcer) {
    forcer = previous_object();
  }
/*
  if(!this_object()->query_property("npc")) {
 */
    log_file("FORCE", ctime(time()) + " " + forcer->query_name() + " " +
                      this_object()->query_name() + " : " + str);
/*
  }
 */
  tell_object(this_object(), forcer->query_cap_name() +
        " intenta forzarte a hacer " + str + "\n");
  if (no_force_me || TO->query_creator()) {
    event(users(), "inform", forcer->query_cap_name()+" fuerza a "+this_object()->query_name()+" a hacer "+str+" (fallo)", "force");
    log_file("FORCE", " (failed)\n");
    return 0;
  }
  if(!sscanf(str, "%s %s", temp1, temp2)) {
    temp1 = str;
  }
/* Delete this at your own peril */
  if (member_array(temp1, ILLEGAL_FORCE) != -1 &&
      !"secure/master"->god(geteuid(forcer))) {
    event(users(), "inform", forcer->query_cap_name()+" forces "+this_object()->query_name()+" to "+str+" (failed)", "force");
    log_file("FORCE", " (failed)\n");
    return 0;
  }
  command(str);
   if(forcer)
  event(users(), "inform", forcer->query_cap_name()+" forces "+this_object()->query_name()+" to "+str, "force");
  log_file("FORCE", " (succeeded)\n");
  return 1;
} /* do_force_on_me() */
