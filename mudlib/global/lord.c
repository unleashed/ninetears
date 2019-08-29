inherit "/global/thane";

void move_player_to_start(string bong, int new_pl, int going_invis) {
    cat("doc/LORDNEWS");
    ::move_player_to_start(bong, new_pl, going_invis);
    add_action("emergency_shutdown","shutdown!");
    add_action("promote", "promote");
    add_action("do_demote", "demote");
    add_action("do_heart_beat", "heart_beat");
    add_action("do_blocking","block");
    }

int emergency_shutdown() {
    write("Shutdown en modo emergencia - ACTIVADO_\n");
    call_out("enditall",0);
    log_file("CRASH",this_player(1)->query_cap_name()+" lanza un shutdown de emergencia: "+ctime(time())+"\n");
    return 1;
    }
    
int enditall() {
    shutdown(0);
    return 1;
    }

int do_blocking(string str) { return this_object()->do_block(str); }

int do_heart_beat() {
    heart_beat();
    return 1;
    }

string short(int dark) {
    if(query_invis() == 2) {
	if("/secure/gods"->query_boo(this_player()->query_name())) return "**"+::short(dark)+"**";
	return 0;
	}
    if (query_verb() == "dest") return ""+this_object()->query_name(); // Uh?
    if (query_invis()) if(!this_player() || this_player()->query_creator()) return "*"+::short(dark)+"*";
	else return 0;
    else return ::short(dark);
    return 0;
    }

string long(string name, int dark) {
    if(query_invis() == 2) {
	if("/secure/gods"->query_boo(this_player()->query_name())) return "**"+::long(name, dark)+"**";
	return 0;
	}
    if (query_invis()) if(!this_player() || this_player()->query_creator()) return "*"+::long(name, dark)+"*";
	else return 0;
    else return ::long(name, dark);
    return 0;
    }

int invisible(string str) {
    if(str && str == "1") if(!query_invis()) {
	    tell_object(TO,"Desapareces.\n");
    	    tell_room(ENV(TO),query_cap_name()+" se esfuma en una nube de humo.\n", TO);
            set_invis(1);
	    return 1;
            }
	else {
    	    tell_object(TO,"Ahora eres un poco mas visible.\n");
    	    tell_room(ENV(TO),query_cap_name()+" aparece borrosamente ante tus ojos.\n", TO);
    	    set_invis(1);
    	    return 1;
    	    }
    if(query_invis() == 2) return notify_fail("Ya eres totalmente invisible.\n");

    if(query_invis() || str) {
	tell_object(TO,"Ahora eres totalmente invisible.\n");
	tell_room(ENV(TO),query_cap_name()+" se desvanece por completo.\n", TO);
	set_invis(2);
	return 1;
	}
    tell_object(TO,"Desapareces.\n");
    tell_room(ENV(TO),query_cap_name()+" desaparece en una nube de humo.\n", TO);
    set_invis(1);
    return 1;
    }

int query_lord() { return 1; }

nomask int query_alqui() {
    if("/secure/mudlibber"->query_boo(query_name())) return 1;
    return 0;
    }

nomask int query_demi() {
    if("/secure/lords"->query_boo(query_name())) return 1;
    return 0;
    }

int promote(string str) {
    if (this_player(1) != this_object()) return 1;
    if (!str) return notify_fail("Uso: promote <persona>\n");
    return (int)"/secure/master"->create_creator(str);
    }

nomask int do_demote(string str) {
    if (this_player(1) != this_player()) return 0;
    if (!str) return notify_fail("Uso: demote <persona> <razon>\n");
    return (int)"/secure/master"->demote_creator(str);
    }

string *parse_command_id_list() {
    if (query_invis() == 2) return ({ });
    return ::parse_command_id_list();
    }

string *parse_command_adjectiv_id_list() {
    if (query_invis() == 2) return ({ });
    return ::parse_command_adjectiv_id_list();
    }

string *parse_command_plural_id_list() {
    if (query_invis() == 2) return ({ });
    return ::parse_command_plural_id_list();
    }

string query_object_type() {
    if(query_demi())  return "S";
    if(query_alqui()) return "A";
    return "L";
    }

string query_gtitle() {
    string of_title;

    if(query_female()) {
	if(query_demi()) {
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
    else {
	if(query_demi()) {
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
