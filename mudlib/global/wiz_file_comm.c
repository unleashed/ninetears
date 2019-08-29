// Radix - Added wis_present call to 'cd' allowing 'cd here'
// or any other object, same as 'ed'
// December 15, 1995

//inherit "/std/basic/ls";
inherit "/global/le";
inherit "/global/wiz_object_comm";
inherit "/global/player.c";
inherit "/global/wiz_inter_comm";
inherit "/global/wiz_info_comm";
inherit "/global/wiz_communicate";

#define MASTER "/secure/master"

static mixed in_editor;

varargs object *wiz_present(string str, object onobj, int nogoout);
string desc_object(mixed o);
string desc_f_object(object o);

static void wiz_commands() {
    add_action("update","update");
    add_action("indent", "indent");
    /* This may not work: (baldrick) */
    wiz_object_comm::wiz_commands();
    wiz_info_comm::wiz_commands();
    wiz_communicate::wiz_commands();
} /* wiz_commands() */

/*
** commands in the app_commands will go to all players with
** level >= 20. This includes players who have opted to
** remain players rather than advancing to wizard. As such
** we must be careful in what we place here
*/

static void app_commands() {
    wiz_object_comm::app_commands();
    wiz_info_comm::app_commands();
    wiz_inter_comm::wiz_commands();
} /* app_commands() */

/* These commands go to ALL players. Note that master.c
** gives only limited read/write access to dirs anyway,
** so the apparent security problems are NOT a problem
*/

all_commands() {
    add_action("what_dir","pw*d");  
    //add_action("list_files","ls");
    add_action("change_dir","cd");
    add_action("edit","ed");
    add_action("le", "le");
    add_action("set_home_dir", "homed*ir");
    wiz_object_comm::all_commands();
    wiz_info_comm::all_commands();
} /* all_commands() */

static int do_update(object *ov) {
    string pname, dummy, err;
    int i, j;
    object *invent, rsv, env, dup, loaded;
    /* next three Hamlet's */
    object totell;
    string *load_junk;
    string itemname;
    object thing;

    if (this_player(1) != this_player()) return 0;

    // Easy way to preload something...
    "room/void"->bingle_bingle();

    rsv = find_object("room/void");  /* RSV = Room Slash Void */
    if (!rsv) { /* Die in horror */
	notify_fail("The void is lost!\n");
	return 0;
    }

    for (i = 0; i < sizeof(ov); i++) {
	if (!ov[i]) continue;
	env = environment(ov[i]);
	invent = all_inventory(ov[i]);

	// Added logging of "update <player>"  Radix, Dec 15, 1995
	if(interactive(ov[i]))
	    log_file("MISC",this_player()->query_short()+" UPDATED "+
	      ov[i]->query_short()+" : "+ctime(time())+"\n");

	for (j = 0; j < sizeof(invent); j++)
	{
	    if(interactive(ov[i]) || interactive(invent[j]) )
		invent[j]->move(rsv);
	    else invent[j]->dest_me(); // Taniwha 1995, so rooms stop filling when updated
	}

	pname = file_name(ov[i]);
	if (sscanf(pname, "%s#%d", pname, dummy) != 2) { /* a room ? */
	    /* Next three Hamlet's */
	    load_junk = "/global/auto_load"->create_update_auto_load(ov[i]);
	    totell = environment(ov[i]);
	    itemname = ov[i]->query_short();

	    ov[i] -> dest_me();
	    if (ov[i]) ov[i]->dwep();
	    if (ov[i]) destruct(ov[i]);
	    //            file_size("/secure/master");     Struck me as senseless.
	    /* Uh, you just dested it.  obviously it's not there...
	    if (!ov[i])
		ov[i] = find_object(pname);
	    */
	    catch(call_other(pname, "??"));
	    ov[i] = find_object(pname);
	} else {
	    loaded = find_object(pname);

	    /* Next three Hamlet's */
	    if (loaded) {
		load_junk = "/global/auto_load"->create_update_auto_load(loaded);
		totell = environment(loaded);
		itemname = loaded->query_short();
	    }

	    if (loaded) loaded->dest_me();
	    if (loaded) loaded->dwep();
	    if (loaded) destruct(loaded);

	    /* These are Hamlet's too */
	    catch(loaded = load_object(pname));
	    if(loaded)
		loaded->move(totell);
	    else { /* Damn thing didn't reload... Oops... */
		if(totell) {
		    if(interactive(totell))
			if(strlen(itemname))
			    tell_object(totell,"Oops.  Your "+itemname+" just "
			      "broke.\n");
			else
			    tell_object(totell,"Oops.  Something you had just "
			      "broke.\n");
		    thing = clone_object( "/obj/misc/iou" );
		    thing->add_auto_string( load_junk );
		    thing->move( totell );
		}
	    }

	    catch(dup = clone_object(pname));
	    if (dup && ov[i]) {
		ov[i] -> dest_me();
		if (ov[i]) ov[i]->dwep();
		if (ov[i]) destruct(ov[i]);
		ov[i] = dup;
	    }
	}

	if (!ov[i]) {
	    if(totell) {
		if(interactive(totell))
		    if(strlen(itemname))
			tell_object(totell,"Oops.  Your "+itemname+" just broke.\n");
		    else
			tell_object(totell, "Oops.  Something you had just broke.\n");
		thing = clone_object( "/obj/misc/iou" );
		thing->add_auto_string( load_junk );
		thing->move( totell );
	    }
	    continue;
	}

	for (j = 0; j < sizeof(invent); j++)
	    if (invent[j]) invent[j]->move(ov[i]);

	if (env) ov[i]->move(env);
	write("Updated " + desc_f_object(ov[i]) + ".\n");
    }
    return 1;
} /* do_update() */

int update(string str) {
    string tring, *filenames, err;
    object ob, *val, *obs;
    int loop, loop2;

    notify_fail("No such object.\n");
    tring = str;
    if (!str || str == "here") { 
	str = file_name(environment());
	sscanf(str, "%s#%d", str, loop);
	filenames = ({ "/" + str });
	str = "here";
    }
    else {
	filenames = get_cfiles(str);
    }
    if(sizeof(filenames) == 0) {
	val = wiz_present(tring, this_player());
	if(!sizeof(val)) {
	    notify_fail("No matching objects/filenames\n");
	    return 0;
	}
	return do_update(val);
    }
    obs = ({ });
    for(loop = 0; loop < sizeof(filenames); loop++) {
	str = filenames[loop];
	ob = find_object(str);
	if (!ob) {
	    if(file_size(str) >= 0) {
		if (!(err = catch(str->bing_with_me())))
		    write("Loaded " + str + "\n");
		else
		    write("Failed to load "+str+", error: "+err+"\n");
	    }
	    else {
		val = wiz_present(tring, this_player());
		obs += val;
	    }
	}
	else {
	    obs += ({ ob });
	}
    }
    if (!obs)
	return 0;
    else
	return do_update(obs);
} /* update() */

static int edit(string str) {
    string *filenames, spam, bing;
    object *things;
    int egg;

    if (this_player(1) != this_player()) return 0;

    if (!str) {
	in_editor = "(hidden)";
	ed("frog", "fini_editor");
	return 1;
    }
    /* dodgy idea, but allows 'ed here' or 'ed strawberry' */
    if (sizeof(things = wiz_present(str, this_player()))) {
	spam = file_name(things[0]);
	sscanf(spam, "%s#%d", spam, egg);
        if(spam[0..6] == "/global")
	    filenames = get_files(str);
	else
	if (file_size(spam) < 0)
	    filenames = ({ spam+".c" });
	else
	    filenames = ({ spam });
    } else
	filenames = get_files(str);
    if (!sizeof(filenames)) {
	str = get_path(str);
    } else {
	if (sizeof(filenames) > 0) {
	    str = filenames[0];
	    if (sizeof(filenames) > 1) {
		int loop;

		loop = 0;
		while(loop < sizeof(filenames) && file_size(filenames[loop]) < 0)
		    loop++;
		if(loop >= sizeof(filenames)) {
		    write("No such file.\n");
		    return 0;
		}
		else {
		    str = filenames[loop];
		}
		write("Ambiguous, using : " + str + "\n");
	    }
	}
    }
    if (file_size(str) == -2) {
	write("directory\n");
	return 1;
    }
    in_editor = str;
    if (!MASTER->valid_write(str, geteuid(), "frog"))
	write("[read only] ");
    ed(str, "fini_editor");
    return 1;
} /* edit() */

void set_in_editor(mixed fname) {
    int fsize = strlen(file_name(previous_object()));
    if(file_name(previous_object())[fsize-8..fsize-1] == "/cmds/ed")
	in_editor = fname;
}
mixed query_in_editor() { return in_editor; }

void fini_editor() {
    in_editor = 0;
} /* fini_editor() */

static int what_dir() {
    write(current_path+"\n");
    return 1;
} /* what_dir() */

// Radix - Added wis_present call to 'cd' allowing 'cd here'
// or any other object, same as 'ed'
// December 15, 1995
static int change_dir(string str) {
    string *filenames;
    object *obs = ({ });
    string tmp = 0;
    string *arr = ({ });

    if (this_player(1) != this_player()) return 0;

    if (!str)  {
	if(!home_dir) {
	    notify_fail("No homedir.  Use homedir to set it.\n");
	    return 0;
	}
	str = home_dir;
    }
    filenames = get_files(str);
    if(sizeof(filenames) > 1) {
	notify_fail("Ambiguous directory.\n");
	return 0;
    }
    if(!sizeof(filenames))
    {
	obs = wiz_present(str,this_player());
	if(!sizeof(obs))
	{
	    notify_fail("No such directory.\n");
	    return(0);
	}

	// Added 'cd <immortal>' changes your path to their path
	// Radix
	if(interactive(obs[0]) && obs[0]->query_creator())
	    filenames = get_files(obs[0]->query_path());
	else
	{
	    tmp = virtual_file_name(obs[0]);
	    if(!stringp(tmp))
	    {
		notify_fail("Error: Bad wiz_present call, cd failed.\n");
		return(0);
	    }
	    arr = explode(tmp,"/");
	    str = implode(arr[0..sizeof(arr)-2],"/");
	    filenames = get_files("/"+str);
	}

	// Unlikely a loaded object won't have a dir, but leave it
	// to a bastard to do such things...
	// Radix
	if(!sizeof(filenames))
	{
	    notify_fail("No such directory.\n");
	    return(0);
	}
    }
    str = filenames[0];
    if (file_size(str) != -2) 
	write("Bad directory : " + str + ".\n");
    else
	current_path = str;
    write(current_path+"\n");
    return 1;
} /* change_dir() */

string query_path() { return current_path; }

static int set_home_dir(string str) {
    if (this_player(1) != this_object()) return 0;
    if (str) home_dir = get_path(str);
    write("Home directory set to "+home_dir+".\n");
    return 1;
} /* set_home_dir() */

int query_ed_setup() { return ed_setup; }
void set_ed_setup(int i) { ed_setup = i; }

int review() {
    player::review();
    wiz_info_comm::review();
    return 1;
} /* review() */

