/*
 * add_command:
 *   This handles all the cute multiple object parseing stuff.  It is the
 * bit which handles the add_action like things done from all the objects
 * for things such as read and so on.
 */
nosave mapping commands,
               cur_objects;
nosave mixed   *suc_indir;

string create_string(string pattern, mixed *args, int d,
                     int e, string s1, string s2);

void parser_commands() {
  add_action("parse_comm", "*", -1);
}

void create() {
  commands = ([ ]);
  cur_objects = ([ ]);
}

mapping query_p_commands() { return commands; }
mapping query_p_objects() { return cur_objects; }

/*
 * this is called by the object the command is being passed on to find
 * whether or not it succeeded on the objects it was passed... and which
 * ones. This can be passed an object.. or an array of objects.
 * Share and enjoy.
 */
int add_succeeded(mixed ob) {
  int i;

  if (objectp(ob))
    if (member_array(ob, suc_indir) == -1)
      suc_indir += ({ ob });
    else
      return 1;
  else if (!pointerp(ob))
    return 0;
  else for (i=0;i<sizeof(ob);i++)
    if (member_array(ob[i], suc_indir) == -1)
      suc_indir += ({ ob[i] });
  return 1;
}

/*
 * this adds a clever command to the object.
 * Horror stuff, these clever commands, but they dfo a lot of the work
 * for you which is why they were added.
 * For an example look at /std/liquid
 */
int add_command(string command, object ob, mixed format) {
  int j;

/*
 * Set up the format how we want it handled.  You can put an array of
 * format strings to this function.
 */
  if (!format)
    format = ({ "%D" });
  if (stringp(format))
    format = ({ format });
  if (!pointerp(format))
    return 0;
/* check to see if the command exists in the command array */
  if (commands[command]) {
    for (j=0;j<sizeof(format);j++)
      if (commands[command][format[j]]) {
        if (member_array(ob, commands[command][format[j]]) == -1)
          commands[command][format[j]] += ({ ob });
      } else
        commands[command][format[j]] = ({ ob });
/*
 * put the object in the fast find object array.  This is done for the
 * entering and exiting of objects from the players environment.
 */
    if (cur_objects[ob])
      cur_objects[ob] += ({ command });
    else
      cur_objects[ob] = ({ command });
    return 1;
  }
/* New command not yet added. */
  commands[command] =  ([ ]);
  for (j=0;j<sizeof(format);j++)
    commands[command][format[j]] = ({ ob });
/* Add it to our fast find object list */
  if (cur_objects[ob])
    cur_objects[ob] += ({ command });
  else
    cur_objects[ob] = ({ command });
  return 1;
}

/*
 * This is the bit that handles object leaving the environment of the
 * player.
 */
int remove_object(mixed ob) {
  if (objectp(ob) && !cur_objects[ob])
    return 0;
/* called out for umm, eval reasons. */
  call_out("remove_object2", 0, ob);
  return 1;
}

/*
 * The bit that does all the horrible work...
 */
int remove_object2(mixed ob) {
  string ind,
         *bing;
  int i, j;

/* Handle arrays. */
  if (pointerp(ob))
    return sizeof(filter_array(ob, "remove_object2", this_object()));

/* Check to see if our illustious object exists or not. */
  if (!cur_objects[ob])
    return 0;
  for (i=0;i<sizeof(cur_objects[ob]);i++)
    if (commands[(ind=cur_objects[ob][i])]) {
/*
 * Go through all the formats one bye one. Deleteing both this object and
 * any dested ones it runs accross.
 */
      bing = m_indices(commands[ind]);
      for (j=0;j<sizeof(bing);j++)
        if (!sizeof((commands[ind][bing[j]] -= ({ 0, ob }))))
          commands[ind] = m_delete(commands[ind], bing[j]);
/* Check to see if after deleteion of formats if the entire command goes */
      if (!m_sizeof(commands[ind]))
        commands = m_delete(commands, ind);
    }
/* Delete the object from the object table */
  cur_objects = m_delete(cur_objects, ob);
  return 1;
}

/* The dest event :) */
void event_dest_me(object ob) {
/*
 * Don't call this out as otherwise we end up with a 0 which may mess up
 * the mapping a bit.
 */
  if (!cur_objects[ob])
    return ;
  remove_object2(ob);
}

/*
 * Handle leaving.  Check to see if it is me leaving.  If it is, then
 * remove all the objects from the inventory.
 */
void event_exit(object ob, string mess, object dest, object *ignore) {
  if (dest == this_object() || dest == environment())
    return ;
  remove_object(ob);
}

void me_moveing(object from) {
/* Use this so as to get the hidden objects as well. */
  if (from)
    remove_object((object *)from->find_inv_match());
}

/* This is the bit that is add_actioned and does the grunt work */
int parse_comm(string str) {
  int retval;
  mixed *dir, *indir;
  mixed *args, m;
  string s;
  string pattern;
  string verb, noti;
  string s1, s2, *bing;
  int j, q;
  int iI, iD;
  mixed *bity;

/* First split out the verb from the rest of the string */
  if (sscanf(str, "%s %s", verb, str) != 2) {
    verb = str;
    str = 0;
  }
/* check to see if the command exists. */
  if (!commands[verb])
    return 0;
/* Set the the succeeded indirect objects to be the empty set */
  suc_indir = ({ });
  notify_fail(capitalize(verb) + " que?\n");
/*
 * You need to have some arguments, these things only work with object
 * references...
 */
  noti = "";
  if (!str || str == "")
    return 0;
/* Get the list of formats to check */
  bing = m_indices(commands[verb]);
  for (q=0;q<sizeof(bing);q++) {
/* Set the args to all null values */
    args = ({ 0, 0, 0, 0, 0, });
/*
 * Split the pattern up to get the %D and %I positions and substitute them
 * for %s's in the format string.
 */
    pattern = implode((dir = explode("&"+bing[q]+"&", "%D")),
                                     "%s");
    pattern = implode((indir = explode(pattern, "%I")), "%s");
    pattern = pattern[1..strlen(pattern)-2];
/* Do the parse_command check. */
    if (!parse_command(str, environment(this_player()),
              pattern, args[0], args[1],
              args[2], args[3], args[4])) {
      noti += "Syntax: "+verb+" "+replace(bing[q], ({ "%p", "<prep>",
                                       "%I", "<object>",
                                       "%D", "<object>", "'", "" }))+"\n";
      continue;
    }
    iI = iD = 0;
/*
 * Figure out the postion of the %D and the %I in the string, and check to see
 * if the returned args actually match some objects, fail if they do not.
 */
    if (sizeof(dir) > 1)
      dir = find_match((s=args[(iD=sizeof(explode(dir[0], "%"))-1)]),
                        ({ this_object(), environment() }));
    else {
      noti += "Syntax: "+verb+" "+replace(bing[q], ({ "%p", "<prep>",
                                       "%I", "<object>",
                                       "%D", "<object>", "'", "" }))+"\n";
      continue; /* direct object! */
    }
    if (sizeof(indir) > 1)
      indir = find_match((s=args[(iI=sizeof(explode(indir[0], "%"))-1)]),
               ({ this_object(), environment() }) );
    else
      indir = ({ });
/* Bity is the array of succeeded objects. */
    bity = ({ });
    for (j=0;j<sizeof(dir);j++)
      if (dir[j]->short()) /* Object must have a short to be worked on */
/*
 * Check to see if the object is in the list of objects with the command
 * added
 */
        if (member_array(dir[j], commands[verb][bing[q]]) != -1)
/*
 * Do the call checking for return value.  You can return a string or
 * a array to do odd things.  Look at query_multiple_short
 */
          if ((m=(mixed)call_other(dir[j], "do_"+verb, indir,
                                   args[iD], args[iI], args)))
            if (stringp(m) || pointerp(m))
              bity += ({ m });
            else
              bity += ({ dir[j] });
/*
 * Did we suceed?  Big question everyone is asking.
 * Print the fail message if we didn't.
 */
    if (sizeof(bity) != sizeof(dir) || sizeof(suc_indir) != sizeof(indir)) {
      s1 = query_multiple_short(dir - bity);
      s2 = query_multiple_short(indir - suc_indir);
      s = create_string(pattern, args, iD, iI, s1, s2);
      write("No has podido "+verb+" "+s);
      retval++;
    }
/* and continue... */
    if (!sizeof(bity) || (sizeof(indir) && !sizeof(suc_indir)))
      continue;
/* Print our nice success message */
    s1 = query_multiple_short(bity);
    s2 = query_multiple_short(suc_indir);
    s = create_string(pattern, args, iD, iI, s1, s2);
	verb = verb[0..sizeof(verb)-2];
    write(capitalize(verb+"s")+" "+s);
    say(this_player()->query_cap_name()+" "+verb+" "+s);
    retval++;
  }
  if (noti != "")
    notify_fail(noti);
  return retval;
}

/*
 * This horrible bit passes the args and the mutiple shorts to give a
 * nice format string as a message.  This is used to print both errors
 * and fails.
 */
string create_string(string pattern, mixed *args, int d,
                     int e, string s1, string s2) {
  string *bits, s;
  int i;

  pattern = replace(pattern, ({ "'", "", "[", "", "]", "" }));
  bits = explode("*"+pattern, "%");
  s = bits[0][1..10000];
  if (s1 == "") s1 = "(no match)";
  if (s2 == "") s2 = "(no match)";
  for (i=0;i<sizeof(bits)-1;i++)
    if (i == d)
      s += s1+bits[i+1][1..100];
    else if (i == e)
      s += s2+bits[i+1][1..100];
    else
      s += args[i]+bits[i+1][1..100];
  return s+".\n";
}
