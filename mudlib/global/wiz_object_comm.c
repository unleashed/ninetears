// Radix added logging of "update <player>"   Dec 15, 1995

#define MASTER "/secure/master"
#define PEOPLER "/obj/handlers/peopler"

varargs object *wiz_present(string str, object onobj, int nogoout);
string desc_object(mixed o);
string desc_f_object(object o);

void wiz_commands() {
    add_action("function2","call");
    add_action("parse_frogs", ";*");
    add_action("dest", "destruct");
    add_action("dest", "dest");
    add_action("show_stats", "stat");
    add_action("trans", "trans");
} /* wiz_commands() */

/*
** commands in the app_commands will go to all players with
** level >= 20. This includes players who have opted to
** remain players rather than advancing to wizard. As such
** we must be careful in what we place here
*/

void app_commands() {
    add_action("whereis","donde");
    add_action("get_pathof","pathof");
    add_action("get_creator","coder");
    add_action("get_inv","inv");
    add_action("goback","goback");
    add_action("upgrade_player", "upgrade");
    add_action("find_shadows", "shadows");
    add_action("do_find", "find");
    add_action("do_debug", "dump");
    add_action("do_debug", "debug");
} /* app_commands() */

void all_commands() {
} /* all_obj_commands() */

int whereis(string str) {
    object *ov,e;
    int i;

    notify_fail("Donde esta quien?\n");
    ov = wiz_present(str,this_player());
    if (!sizeof(ov)) return 0;

    for (i = 0; i < sizeof(ov); i++) {
	if (ov[i]->query_invis() > 1) continue;
	if(interactive(ov[i]))
        if(!(this_player()->query_lord() || this_player()->query_thane()))
	   { log_file("LOCATE",this_player()->query_cap_name()+" intento localizar a: "+ov[i]->query_cap_name()+".\n");
	  write("Lo siento, localizar jugadores no te esta permitido.\n");
	continue;
	}
	write(desc_object(ov[i]) + " es : \n");
	e = ov[i];
	while (e = environment(e))
	    write("  en " + desc_f_object(e) + "\n");
    }
    return 1;
} /* whereis() */

/* This is for querying about objects who don't want to be destructed */
nosave object discard_obj;

int affirmative(string s) /* returns true if s is a 'yes' equiv response */
{
    s = lower_case(s);
    return (s == "y" || s == "yes" || s == "ok" || s == "please");
} /* affirmative() */

/* is there an error?  print it */
void handle_error(string erm, string desc) {
    if (erm) {
	write(desc + " failed : " + erm);
    }
} /* handle_error() */

/* added by Dank Mar 3 '93.  also added query_prev() to move.c */
int goback() {
    object ob;
    if (!(ob = this_player()->query_prev()))
	write("Previous location is not valid.\n");
    else
	this_player()->move_player("X",ob);
    return 1;
}


int get_pathof(string str) {
    object *ov;
    int i;

    notify_fail("Pathof what?\n");
    ov = wiz_present(str,this_player());
    if (!sizeof(ov)) return 0;

    for (i = 0; i < sizeof(ov); i++) {
	if (!ov[i]) continue;
	/*
	      if (sizeof(ov) > 1) {
	 */
	write("Path of " + desc_object(ov[i]) + " in " +
	  desc_object(environment(ov[i])) + ":\n");
	/*
	      }
	 */
	write(file_name(ov[i])+ "\n");
    }
    return 1;
} /* get_pathof() */

int get_inv(string str) {
    object *ov, obj;
    int i;

    notify_fail("Inv of what?\n"); /* thanks for the great error message ! */

    if (!str) {
	ov = ({ this_player() });
    } else {
	sscanf(str, "of %s", str);
	ov = wiz_present(str,this_player());
    }
    if (!sizeof(ov)) return 0;

    for (i = 0; i < sizeof(ov); i++) {
	if (!ov[i]) continue;
/*
	if( (interactive(ov[i])) && !(this_player()->query_lord() || this_player()->query_thane()) && !(ov[i]==this_player()))
	{
		log_file("LOCATE",this_player()->query_cap_name()+" intento encontrar el inventario de: "+ov[i]->query_cap_name()+".\n");
		write("Lo siento, no estas permitido a ver el inventario de "+ov[i]->query_cap_name()+".\n");
	continue;
	}
*/
	write("Inv de " + desc_object(ov[i]) + " en " +
	  desc_object(environment(ov[i])) + ":\n");
	obj = first_inventory(ov[i]);
	while (obj) {
	    write("  " + desc_f_object(obj) + "\n");
	    obj = next_inventory(obj);
	}
    }
    return 1;
} /* inv() */

int get_creator(string str) {
    object *ov;
    int i;

    notify_fail("Creator of what?\n");
    ov = wiz_present(str,this_player());
    if (!sizeof(ov)) return 0;

    for (i = 0; i < sizeof(ov); i++) {
	write("Creador de " + desc_object(ov[i]) + ": " +
	  "secure/master"->creator_file (file_name(ov[i])) + ", uid: " +
	  getuid(ov[i]) + ", euid: "+geteuid(ov[i])+"\n");
    }
    return 1;
} /* get_creator() */

nosave object *dest_obj;
nosave int objn, majd;

void ask_dest() {
    if (!pointerp(dest_obj) || objn >= sizeof(dest_obj)) {
	write("No more things to dest.\n");
	dest_obj = 0;    /* wipe array to free memory */
	return;
    }
    write("Dest object " + desc_object(dest_obj[objn]) + " ? ");
    input_to("dest_answer");
    return;
} /* ask_dest() */

void dest_answer(string s)
{
    string err, shrt;

    if (affirmative(s)) {
	if (majd) {
	    shrt = (string)dest_obj[objn]->short();
	    err = catch(dest_obj[objn]->dwep());
	    handle_error(err, "DWEP");
	    if (dest_obj[objn]) {
		write("It REALLY doesn't want to be dested.\n");
		err = catch(destruct(dest_obj[objn]));
		handle_error(err, "destruct()");
	    }
	    majd = 0;
	    if (dest_obj[objn]) write("It didn't dest.\n");
	    else {
		say((string)this_player()->query_cap_name()+" desintegra "+
		  (shrt ? shrt : "algo") +".\n");
		write("Ok.\n");
	    }
	    objn++;
	    ask_dest();
	    return;
	} else {
	    err = catch(dest_obj[objn]->dest_me());
	    handle_error(err, "dest_me");
	    if (dest_obj[objn]) {
		write("This object does NOT want to be dested.  Are you sure? ");
		majd = 1;
		input_to("dest_answer");
		return;
	    }
	    write("Ok.\n");
	    objn++;
	    ask_dest();
	    return;
	}
    } else if (s == "q" || s == "quit") {
	write("Ok.  No more objects will be destd.\n");
	dest_obj = 0;
	return;
    }
    write("Ok.  Not destd.\n");
    objn++;
    ask_dest();
    return;
} /* dest_answer() */

int dest(string str) {
    object *ob;
    int i;
    string qstr, err, shrt, dobj;

    dest_obj = ({ });

    if (!str) {return 0;}

    notify_fail("Can't find " + str + " to dest.\n");

    if (sscanf(str, "query %s", qstr) == 1) {
	dest_obj = wiz_present(qstr, this_player());
	if (!sizeof(dest_obj)) return 0;
	objn = 0;
	majd = 0;	/* MAJOR dest needed */
	ask_dest();
	return 1;
    }

    ob = wiz_present(str,this_player());
    if (!sizeof(ob)) return 0;

    for (i = 0; i < sizeof(ob); i++)
    {
	if(interactive(ob[i]) && (sizeof(ob) !=1 || "/secure/master"->high_programmer(geteuid(ob[i]))))
	{
	    write("You DON'T destruct " + ob[i]->query_cap_name() + ".\n");
	    continue;
	}
	if(interactive(ob[i]) && !(this_player()->query_lord() || this_player()->query_thane()))
	{ log_file("BUSTED",this_player()->query_cap_name()+" intento destruir al jugador "+ob[i]->query_cap_name()+".\n");
	write("Lo siento, no tienes permiso para destruir a "+ob[i]->query_cap_name()+".\n");
	continue;
	}
	catch(shrt = (string)ob[i]->short());
	dobj = desc_object(ob[i]);
	if( ob[i]->query_cap_name() && environment(ob[i]) )
	    log_file("MISC",(string)this_player(1)->query_cap_name()+" dests "+ob[i]->query_cap_name()+
	      " from "+environment(ob[i])->query_name()+" file "+file_name(environment(ob[i]))+"\n");
	err = catch(ob[i] -> dest_me());
	handle_error(err, "dest_me");
	if (ob[i])
	    dest_obj += ({ ob[i] });
	else
	{
	    write("You destruct " + dobj + ".\n");
	    say((string)this_player()->query_cap_name()+" desintegra "+
	      (shrt ? shrt : "algo") + ".\n");
	}
    }
    if (sizeof(dest_obj) > 0) {
	objn = 0;
	majd = 0;
	ask_dest();
	return 1;
    }
    return 1;
} /* dest() */

string desc_object(mixed o){
    string str;

    if (!o) return "** Null-space **";
    if (!catch(str = (string)o->short()) && str) return str;
    if (!catch(str = (string)o->query_name()) && str) return str;
    return file_name(o);
} /* desc_object() */

string desc_f_object(object o){
    string str, tmp;

    str = desc_object(o);
    if (o && str != file_name(o)) {
	if (tmp)
	    str += " (" + tmp + ")";
	else
	    str += " (" + file_name(o) + ")";
    }
    return str;
} /* desc_f_object() */

object *wzpresent2(string str, mixed onobj) {
    int i;
    object *obs, obj, *obs2;
    string s1, s2;

    if (pointerp(onobj)) {
	obs = ({ });
	for(i = 0; i < sizeof(onobj); i++)
	    obs += wzpresent2(str,onobj[i]);
	return obs;
    }

// //
    if (str == "all")
	return all_inventory(onobj);

    /* every fish */

    if (sscanf(str,"every %s",s1) == 1) {
	obs2 = all_inventory(onobj);
	obs = ({ });
	for (i=0;i<sizeof(obs2);i++)
	    if (obs2[i]->id(s1)) obs += ({ obs2[i] });
	return obs;
    }

    obs2 = find_match(str,onobj);
    if(sizeof(obs2)) {
	return obs2;
    }

    if (obj = present(str,onobj)) return ({ obj });
    for (obj = first_inventory(onobj); obj; obj = next_inventory(obj)) {
	s2 = file_name(obj);
	if (sscanf(s2, "%s"+str+"#%d", s1, i)
	  || sscanf(s2, "%s#"+str, s1)) {
	    return ({ obj });
	}
    }
    return ({ });
} /* wiz_present2() */

varargs object *wiz_present(string str, object onobj, int nogoout) {
    /* nogoout is so that it WON'T check the environment of onobj */
    int i,j;
    object ob, *obs, *obs2;
    string s1, s2, *sts;

    if (!str || !onobj) {
	return ({ });
    }

    /* all the simple ones first */

    if(str[0] == '@') {
	if (ob = find_living(
	    (string)this_player()->expand_nickname(extract(str, 1))))
	    return ({ ob });
	notify_fail("Unable to find living object: "+extract(str,1)+".\n");
	return ({ });
    }

    if (str == "me") return ({ this_player() });

    if (str == "here") return ({ environment(this_player()) });

    if (str == "everyone") return users();

    if(str[0] == '/') {
	if (ob = find_object(str)) return ({ ob });
	if (sizeof((sts = (string *)this_object()->get_cfiles(str))))  {
	    obs = ({ });
	    for (i=0;i<sizeof(obs);i++)
		if ((ob = find_object(sts[i])))
		    obs += ({ ob });
	    return obs;
	}
	notify_fail("No loaded object: "+str+".\n");
	return ({ });
    }

    /* (fish) == environment of fish */

    if (str[0] == '(' && str[strlen(str) - 1] == ')') {
	obs = wiz_present(extract(str,1,strlen(str) - 2),onobj);
	if (!sizeof(obs)) return obs;
	for (i = 0; i < sizeof(obs); i++) obs[i] = environment(obs[i]);
	return obs;
    }

    /* handle "fish on fish2" */
	/* Hmm....sounds fishy to me.  Timion 97 */

    if (sscanf(str,"%s on %s",s1,s2) == 2 ||
      sscanf(str,"%s in %s",s1,s2) == 2) {
	obs = wiz_present(s2, onobj);
	if (!sizeof(obs)) return obs;
	obs2 = ({ });
	for (i = 0; i < sizeof(obs); i++) 
	    obs2 += wiz_present(s1,obs[i],1);
	return obs2;
    }

    /* fish and fish2 */

    if (sscanf(str,"%s and %s",s1,s2) == 2) {
	obs = wiz_present(s1, onobj);
	obs2= wiz_present(s2, onobj);
	for (i=0;i<sizeof(obs);i++)  /* remove duplicates ... */
	    if (member_array(obs[i], obs2) < 0) obs2 += ({ obs[i] });
	return obs2;
    }

    /* fish except fish2 */

    if (sscanf(str,"%s except %s",s1,s2) == 2 ||
      sscanf(str,"%s but %s",s1,s2) == 2) {
	obs = wiz_present(s1, onobj);
	obs2= wiz_present(s2, onobj);
	for (i=0;i<sizeof(obs2);i++)
	    while ((j=member_array(obs2[i], obs)) > -1)
		obs = delete(obs,j--,1);
	return obs;
    }

    if (sscanf(str,"player %s",s1)) return ({ find_player(s1) });

    if (!sizeof(obs2 = wzpresent2(str,onobj)) && !nogoout) {
	obs2 = wzpresent2(str, environment(onobj));
    }

    if (sizeof(obs2)) return obs2;

    /* check for a find_match locally */

    obs2 = find_match(str,onobj);
    if (sizeof(obs2) > 0) return obs2;

    /* default to return find_living ...  */

    if (ob = find_living((string)this_player()->expand_nickname(str)))
	return ({ ob });

    return ({ });
} /* wiz_present() */

nomask mixed *parse_args(string str, string close) {
    mixed *args, *m, *m2;
    object *obs;
    string s1, s2, s3, s4, s5, s6, s7;
    int i;
    mapping map;

    args = ({ });
    while (strlen(str)) {
	while (strlen(str) && str[0] == ' ') str = str[1..1000];
	if (!strlen(str) || str[0..0] == close) return ({ args, str[1..1000] });
	switch (str[0]) {
	case '\'' :
	    if (sscanf(str, "'%s'%s", s1, s2) != 2) {
		write("Unterminated string.\n");
		return 0;
	    }
	    args += ({ replace(s1, "\\n", "\n") });
	    str = s2;
	    break;
	case '`' :
	    if (sscanf(str, "`%s`%s", s1, s2) != 2) {
		write("Unterminated string.\n");
		return 0;
	    }
	    args += ({ replace(s1, "\\n", "\n") });
	    str = s2;
	    break;
	case '"' :
	    if (sscanf(str, "\"%s\"%s", s1, s2) != 2) {
		write("Unterminated string.\n");
		return 0;
	    }
	    args += ({ replace(s1, "\\n", "\n") });
	    str = s2;
	    break;
	case '{' :
	    m = parse_args(str[1..1000], "}");
	    if (!m)
		return 0;
	    args += ({ m[0] });
	    str = m[1];
	    break;
	case '[' :
	    str = str[1..1000];
	    map = ([ ]);
	    while (1) {
		m = parse_args(str, ":");
		/* Ok...  if we cannot find another : maybe we are at the end? */
		if (!m) {
		    while (strlen(str) && str[0] == ' ') str = str[1..1000];
		    if (str[0] == ']')
			break;
		}
		if (!(m2 = parse_args(str, ","))) {
		    if (!(m2 = parse_args(str, "]")))
			return 0;
		    if (sizeof(m[0]))
			map[m[0][0]] = (sizeof(m2[0])?m2[0][0]:0);
		    break;
		}
		if (sizeof(m[0]))
		    map[m[0][0]] = (sizeof(m2[0])?m2[0][0]:0);
	    }
	    args += ({ map });
	    break;
	case '|' :
	    if (sscanf(str, "|%s|%s", s1, s2) != 2) {
		write("Unmatched |\n");
		return 0;
	    }
	    obs = wiz_present(str, this_player());
	    if (!sizeof(obs))
		args += ({ this_player() });
	    else if (sizeof(obs) == 1)
		args += ({ obs[0] });
	    else
		args += ({ obs });
	    str = s2;
	    break;
	case '0'..'9' :
	case '-' :
	    if (sscanf(str, "%d%s", i, str) != 2) {
		write("Number expected.\n");
		return 0;
	    }
	    args += ({ i });
	    break;
	default :
	    s2 = s3 = 0;
	    sscanf(str, "%s,%s", s4, s2);
	    sscanf(str, "%s"+close+"%s", s5, s3);
	    if (sscanf(str, "%s->%s", s6, s7) == 2 &&
	      (!s3 || strlen(s5) > strlen(s6)) &&
	      (!s2 || strlen(s4) > strlen(s6))) {
		/* Now we do something trully revolting.... */
		while (s7[0] == ' ') s7 = s7[1..1000];
		if (sscanf(s7, "%s(%s", s1, s7) != 2) {
		    write("'(' expected.\nLine left unprocessed"+s7+"\n");
		    return 0;
		}
		obs = wiz_present(s6, this_player());
		if (!sizeof(obs)) {
		    write("The object "+s6+" needs to exist.\n");
		    return 0;
		}
		m = parse_args(s7, ")");
		if (!m) return 0;
		if (sizeof(m[0]) < 6) m[0] += allocate(6-sizeof(m[0]));
		obs = map_array(obs, "mapped_call", this_object(), ({ s1 })+m[0]);
		if (sizeof(obs) == 1)
		    args += obs;
		else
		    args += ({ obs });
		str = m[1];
		break;
	    } else if (s2 && s3)
		if (strlen(s4) < strlen(s5)) {
		    s1 = ",";
		    str = s4;
		} else {
		    s1 = close;
		    s2 = s3;
		    str = s5;
		} else if (s2) {
		s1 = ",";
		str = s4;
	    } else if (s3) {
		s1 = close;
		s2 = s3;
		str = s5;
	    } else {
		s1 = "";
		s2 = "";
	    }
	    obs = wiz_present(str, this_player());
	    if (!sizeof(obs)) {
		if (str[0] >= '0' && str[0] <= '9' || str[0] == '-') {
		    sscanf(str, "%d%s", i, str);
		    args += ({ i });
		} else 
		    args += ({ replace(str, "\\n", "\n") });
	    } else if (sizeof(obs) == 1)
		args += ({ obs[0] });
	    else
		args += ({ obs });
	    str = s1+s2;
	    break;
	}
	/* Skip rubbish and if we dont have a comma we have finished. */
	while (strlen(str) && str[0] == ' ') str = str[1..1000];
	if (!strlen(str))
	    return ({ args, str });
	if (str[0..0] == close)
	    return ({ args, str[1..1000] });
	if (str[0] != ',') {
	    write("Parse error reading arguments, ',' or '"+close+"' expected.\n");
	    write("Line left unprocessed "+str+"\n");
	    return 0;
	}
	str = str[1..1000];
    }
    return ({ args, str });
} /* parse_args() */

void inform_of_call(object ob, mixed *argv) {
    string str;
    int i;

    str = this_object()->query_cap_name() + " calls " + argv[0] + "(";
    for (i=1; i<sizeof(argv); ) {
	str += replace(sprintf("%O", argv[i]), "\n", " ");
	if (++i < sizeof(argv)) str += ",";
    }
    /* Arggghhh!  This is annoying me.
      ob->event_inform(this_object(), str + ") on you", "call");
     */
} /* inform_of_call() */

nomask mixed mapped_call(object ob, mixed *argv) {
    inform_of_call(ob, argv);
    return call_other(ob, argv[0], argv[1],argv[2],argv[3],
      argv[4],argv[5],argv[6]);
} /* mapped_call() */

/* Free form parse_args code */
nomask int parse_frogs(string str) {
    mixed junk;

    if (this_player(1) != this_object()) return 0;
    /* We are not as such looking for an end thingy of any sort... */
    junk = parse_args(str, ";");
    /* It has already printed an error, so we return 1... */
    if (!junk) return 1;
    log_file("EXECS",(string)this_player(1)->query_cap_name()+" exec'd "+str+"\n");
    write("The line "+str+" Returns: \n");
    printf("%O\n", junk[0]);
    return 1;
} /* parse_forgs() */

nomask int function2(string str) {
    /* call fish(x,y,z) object */
    mixed *args;
    string *s, s1, s2;
    string fn,os, f;
    string *argv;
    object *ov,retobj;
    object fish, shad;
    mixed file;
    int i;

    if (this_player(1) != this_object()) return 0;
    if (!str) {
	notify_fail("USO : call lfun(arg[,arg[,arg...]]) objeto[s]\n");
	return 0;
    }
    log_file("CALLS",(string)this_player()->query_cap_name()+" CALLS "+str+"\n");
    s = explode("&"+str+"&", ")");
    if (sizeof(s) < 2 || sscanf(s[0], "%s(%s", s1, s2) != 2) {
	notify_fail("USO : call lfun(arg[,arg[,arg...]]) objeto[s]\n");
	return 0;
    }
    fn = replace(s1[1..1000], " ", "");
    s[0] = s2;
    args = parse_args(implode(s, ")"), ")");
    if (!args) return 1;
    argv = args[0];
    os = args[1][0..strlen(args[1])-2];
    while (strlen(os) && os[0] == ' ') os = os[1..1000];
    notify_fail("Can't find object "+os+".\n");
    ov = wiz_present(os,this_object());

    if (!sizeof(ov)) return 0;

    if (sizeof(argv) < 6) argv += allocate(6 - sizeof(argv));
    for (i=0; i < sizeof(ov); i++) {
	fish = ov[i];
	while (shad = shadow(fish, 0)) {
	    fish = shad;
	    if (f = function_exists(fn, fish)) file = f;
	}
	if (!file) file = function_exists(fn, ov[i]);
	if (file) {
	    retobj = call_other(ov[i],fn,argv[0],argv[1],argv[2],
	      argv[3],argv[4],argv[5]);
	    inform_of_call(ov[i], ({ fn }) + argv);
	    if ( ov[i] && interactive(ov[i]) && !ov[i]->query_creator() )
		log_file("CALLP",ctime(time())+": "+(string)this_player()->query_cap_name()+" CALLS "+str+" -- player "+(string)ov[i]->query_name()+"\n");
	    write("*** funcion en '"+ desc_object(ov[i])+"' encontrada en "+file+" ***\n");
	    write("Devuelve: ");
	    printf("%O\n", retobj);
		write("A PARTIR DE AHORA, los calls para retocar fichas o dar xp a players seran sancionados.\n");
	} else
	    write("*** funcion en '"+desc_object(ov[i])+"' No encontrada ***\n");
	file = 0;
    }
    return 1;
} /* function2() */

nomask int do_find(string str) {
    string func, thing, s, ping;
    object *obs, fish;
    int i;

    notify_fail("Uso: find funcion() <objeto(s)>\n");
    if(!str) return 0;
    if(sscanf(str, "%s() %s", func, thing) != 2)
	if(sscanf(str, "%s %s", func, thing) != 2)
	    return 0;

    obs = wiz_present(thing, this_object());

    if (!sizeof(obs)) {
	notify_fail("Can't find " + thing + ".\n");
	return 0;
    }
    s = "";
    for (i=0; i < sizeof(obs); i++) {
	if(ping = function_exists(func, obs[i]))
	    s += "*** " + desc_object(obs[i])+": "+func+"() found in " + ping + "\n";
	else
	    s += "*** " + desc_object(obs[i]) + ": " + func + "() not found.\n";
	fish = obs[i];
	while(fish = shadow(fish, 0))
	    if(function_exists(func, fish))
		s += "      Shadowed by " + file_name(fish) + "\n";
    }
    write(s);
    return 1;
} /* do_find() */


int show_stats(string str) {
    object *ob;
    mixed *ob1;
    string s,bing;
    int i,j;

    bing = "";
    ob = wiz_present(str, this_object());
    if (!sizeof(ob)) {
	write("No such object.\n");
	return 1;
    }
    for (j=0;j<sizeof(ob);j++) {
/*
         if(interactive(ob[j]) && !(this_player()->query_lord() || this_player()->query_thane()) && !(this_player() == obj(j))
	{
		log_file("LOCATE",this_player()->query_cap_name()+" tried to Stat "+ob[j]->query_cap_name()+".\n");
		write("You are not allowed to stat "+ob[j]->query_cap_name()+".\n");
	continue;
	}
*/
	ob1 =ob[j]->stats();
	if (!pointerp(ob1))
	    continue;
	s = "";
	for (i=0;i<(sizeof(ob1)-1);i++)
	    if(ob1[i])
		if(ob1[i][0])
		    s += ob1[i][0] + ": "+ob1[i][1]+"\n";
	bing += sprintf("%-*#s\n\n\n", this_object()->query_cols(), s);
    }
    this_object()->more_string(bing);
    return 1;
} /* show_stats() */

int trans(string str) {
    object *obs;
    int i;

    if (this_player(1) != this_object()) return 0;
    if (!str || !(sizeof(obs = wiz_present(str, this_object())))) {
	write("Transport who ?\n");
	return 1;
    }
    for (i=0;i<sizeof(obs);i++) {
	if (environment(obs[i]) == environment()) {
	    write(desc_object(obs[i])+" ya esta aqui.\n");
	    continue;
	}
/*
  if( interactive(obs[i]) && !(this_player()->query_thane() || this_player()->query_lord()) && !(obs[i]->query_property("test_char"))
	{
	log_file("BUSTED",this_player()->query_cap_name()+" tried to illegally trans "+obs[i]->query_cap_name()+".\n");
	write("Sorry, You are not powerful enough to trans "+obs[i]->query_cap_name()+".  Ask a higher ranking immortal.\n");
	continue;
	}
*/
    if(environment(obs[i]))
	log_file("MISC",(string)this_player(1)->query_cap_name()+" trans'd "+
	  obs[i]->query_cap_name()+" from "+file_name(environment(obs[i]))+
	  " to "+file_name(environment(this_player()))+"\n");
	tell_object(obs[i], "Eres transferido magicamente a algun sitio.\n");
	obs[i] -> move_player("X", file_name(environment(this_player())));

	// Radix, December 15, 1995   -  Warn about transing newbies
	if(obs[i]->query_level() < 6 && interactive(obs[i]))
	    write("WARNING:  This could be a newbie.  Removal from a "
	      "newbie area could have serious consequences.\n");
    }
    return 1;
} /* trans() */

int upgrade_player() {
    object ob;

    ob = clone_object("/secure/upgrade");
    ob->new_player(this_object());
    return 1;
} /* upgrade_player() */

int find_shadows(string s) {
    object *objs, *shadows;
    object nobj;
    int i, j;

    if (!s || s == "") s = "me";
    objs = wiz_present(s, this_object());
    if (sizeof(objs) == 0) {
	notify_fail("Can't find object.\n");
	return 0;
    }

    for (i = 0; i < sizeof(objs); i++) {
	shadows = ({ });
	nobj = objs[i];
	while(nobj = shadow(nobj, 0))
	    shadows += ({ nobj });
	if(!sizeof(shadows)) {
	    write(desc_f_object(objs[i]) + " is not being shadowed.\n");
	} else {
	    write(desc_f_object(objs[i]) + " is being shadowed by:\n");
	    for(j=0; j<sizeof(shadows); j++)
		write("    " + file_name(shadows[j]) + "\n");
	}
    }
    return 1;
} /* find_shadows() */

int do_debug(string str) {
    object *obs;

    if(!str) {
	notify_fail("Usage: " + query_verb() + " <objeto>\n");
	return 0;
    }
    if(!sizeof(obs = wiz_present(str, this_object()))) {
	notify_fail("Object " + str + " not found.\n");
	return 0;
    }
    write(debug_info( (query_verb() == "dump"?0:1), obs[0]));
    return 1;
} /* do_debug() */
