inherit "/global/wiz_file_comm";

void load_login();

void create() {
    ::create();
    creator = 1;
    app_creator = 1;
    }

void move_player_to_start(string bong, int new_pl, int going_invis) {
    cat("doc/CREATORNEWS");
    cat("doc/LORDNEWS");
    creator = 1;
    app_creator = 1;
    ::move_player_to_start(bong, new_pl, going_invis);

    if(query_invis()) tell_object(this_object(), "===> Estas en modo INVISIBLE! <===\n");
    add_action("emergency_shutdown","shutdown!");
    add_action("visible", "vis");
    add_action("invisible", "invis");
    add_action("promote", "promote");
    add_action("do_demote", "demote");
    add_action("do_heart_beat", "heart_beat");
    add_action("do_blocking","block");
    //add_action("hide_me", "hide");
    // Test fn by Aragorn
    add_action("do_alsetting","doalign");
    /* Added by Asmodean cause he learned it from Aragorn */
    call_out("load_login",0);
} /* move_player_to_start() */

// Radix... who was the nimrod who moved the commands to externals?
// The same one who did a log_file() before the shutdown(0) maybe ?
// Hope call_out's never fail :P

int emergency_shutdown()
{
   write("This is going to shutdown the mud _immediately_\n");
   call_out("enditall",0);
   log_file("CRASH",this_player(1)->query_cap_name()+
      "shutdown the MUD in an emergency! "+ctime(time())+"\n");
   return 1;
}
int enditall() {
   	shutdown(0);
	return 1;
	}

// Added by Radix (So I lied, we could dest'em instead)
int do_blocking(string str)
{
    return this_object()->do_block(str);
}

void load_login(){
    string *strs;
    int n;
    if(read_file("/w/"+name+"/.login")){
	strs=explode(read_file("/w/"+name+"/.login"),"\n");
	for(n=0;n<sizeof(strs);n++) TO->process_input(strs[n]);
    }
}

int do_heart_beat() {
    heart_beat();
    return 1;
} /* do_heart_beat() */

string short(int dark) {
    if(query_invis() == 2)
    {
	if("/secure/gods"->query_boo(this_player()->query_name()))
	    return "**"+::short(dark)+"**";
	return 0;
    }
    if (query_verb() == "dest")
	return ""+this_object()->query_name();
    if (query_invis())
	if(!this_player() || this_player()->query_creator())
	    return "*"+::short(dark)+"*";
	else
	    return 0;
    else
	return ::short(dark);
    return 0;
} /* short() */

string long(string name, int dark)
{
    if(query_invis() == 2)
    {
	if("/secure/gods"->query_boo(this_player()->query_name()))
	    return "**"+::long(name, dark)+"**";
	return 0;
    }
    if (query_invis())
	if(!this_player() || this_player()->query_creator())
	    return "*"+::long(name, dark)+"*";
	else
	    return 0;
    else
	return ::long(name, dark);
    return 0;
} /* long() */

nomask int visible() {
    if(!query_invis()) {
	notify_fail("Ya eres visible.\n");
	return 0;
    }
    write("Apareces.\n");
    say(query_cap_name()+" aparece de la nada.\n", this_player());
    set_invis(0);
    return 1;
} /* visible() */

nomask int invisible(string str)
{
    // Flode, 120997 - Added the possibility to go from invis 2
    // to invis 1 the hard way
    if(str && str == "1")
      if(!query_invis())
      {
        write("Desapareces.\n");
        say(query_cap_name()+" se esfuma en una nube de humo.\n", this_player());
        set_invis(1);
        return 1;
      }
      else
      {
        write("Ahora eres un poco mas visible.\n");
        say(query_cap_name()+" es ahora un poco mas visible.\n", this_player());
        set_invis(1);
        return 1;
      }
    if(query_invis() == 2)
    {
	notify_fail("Ya eres totalmente invisible.\n");
	return 0;
    }

    if(query_invis() || str)
    {
	write("Ahora eres totalmente invisible.\n");
	say(query_cap_name()+" desaparece en una nube de humo.\n", this_player());
	set_invis(2);
	return 1;
    }

    write("Desapareces.\n");
    say(query_cap_name()+" desaparece en una nube de humo.\n", this_player());
    set_invis(1);
    return 1;
} /* invisible() */

int query_creator() { return 1; }
int query_lord() { return 1; }

nomask int query_alqui() {
    if("/secure/mudlibber"->query_boo(query_name())) return 1;
    return 0;
    }

nomask int query_demi() {
    if("/secure/lords"->query_boo(query_name()))
	return 1;
    return 0;
}

nomask int promote(string str) {
    if (this_player(1) != this_object())
	return 1;
    if (!str) {
	notify_fail("Uso: promote <persona>\n");
	return 0;
    }
    return (int)"/secure/master"->create_creator(str);
} /* promote() */

nomask int do_demote(string str) {
    if (this_player(1) != this_player())
	return 0;
    if (!str) {
	notify_fail("Sintaxis: demote <persona> <razon>\n");
	return 0;
    }
    return (int)"/secure/master"->demote_creator(str);
} /* do_demote() */

int query_creator_playing() { return 0; }

void dest_me() {
    /*
    if (!this_player(1) || (this_player(1) != this_object() &&
	!this_player(1)->query_lord()))
    {
      write("You can't do that!\n");
      return ;
    }
    */
    ::dest_me();
} /* dest_me() */

string *parse_command_id_list() {
    if (query_invis() == 2)
	return ({ });
    return ::parse_command_id_list();
} /* parse_command_id_list() */

string *parse_command_adjectiv_id_list() {
    if (query_invis() == 2)
	return ({ });
    return ::parse_command_adjectiv_id_list();
} /* parse_command_id_list() */

string *parse_command_plural_id_list() {
    if (query_invis() == 2)
	return ({ });
    return ::parse_command_plural_id_list();
} /* parse_command_id_list() */

string query_object_type() {
    if(query_demi())  return "S";
    if(query_alqui()) return "A";
    return "L";
} /* query_object_type() */

string query_gtitle()
{
    string of_title;

    if(query_female())
    {
	if(query_demi())
	{
	    of_title = "/secure/lords.c"->query_boo(name);
	    return "la Semidiosa de" + of_title;
	}
	
	if(query_alqui()) {
	    of_title="/secure/mudlibber"->query_boo(name);
	    return "la Alquimista de"+of_title;
	    }
	of_title="/secure/coordinadores"->query_boo(name);
	return "la Lady de"+of_title;
    }
    else
    {
	if(query_demi())
	{
	    of_title = "/secure/lords.c"->query_boo(name);
	    return "el Semidios de" + of_title;
	}
	
	if(query_alqui()) {
	    of_title="/secure/mudlibber"->query_boo(name);
	    return "el Alquimista de"+of_title;
	    }
	of_title="/secure/coordinadores"->query_boo(name);    
	return "el Lord de"+of_title;
    }
}
