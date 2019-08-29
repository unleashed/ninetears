inherit "/global/wiz_file_comm";

#define ECHO_ALLOWED

void load_login();

int query_creator() { return 1; }

int look_me(string str) {
    if (!str && environment()) write(virtual_file_name(environment()) + "\n");
    return ::look_me(str);
    }

int glance(string str) {
    if (!str && environment()) write(virtual_file_name(environment()) + "\n");
    return ::glance(str);
    }
    
void move_player_to_start(string bong, int new_pl, int going_invis) {
    string temp;

    if(!sscanf(file_name(previous_object()), "/secure/login#%s", temp)) return 0;
    cat("doc/CREATORNEWS");
    ::move_player_to_start(bong, new_pl, going_invis);

    if(query_invis()) tell_object(this_object(), "Est�s %^RED%^BOLD%^INVISIBLE%^RESET%^\n");

    call_out("load_login",0);
    enable_wizard();
    add_action("visible","vis");
    add_action("invisible","invis");
    }

void load_login(){
    string *strs;
    int n;
    if(read_file("/w/"+name+"/.login")) {
        strs=explode(read_file("/w/"+name+"/.login"),"\n");
	for(n=0;n<sizeof(strs);n++) TO->process_input(strs[n]);
        }
    }
    
string short(int dark) {
    if (query_invis()) if(!this_player() || this_player()->query_creator()) return "*"+::short(dark)+"*";
	else return 0;
    else return ::short(dark);
    }

string combat_short(int dark) {	short(dark); }

int visible() {
    if(!query_invis()) return notify_fail("Ya eres visible.\n");
    tell_object(TO,"Apareces.\n");
    tell_room(ENV(TO),query_cap_name()+" aparece de pronto.\n", TO);
    set_invis(0);
    return 1;
    }

int invisible() {
    if(query_invis()) return notify_fail("Ya eres invisible.\n");
    tell_object(TO,"Desapareces.\n");
    tell_room(ENV(TO),query_cap_name()+" desaparece de repente.\n", TO);
    set_invis(1);
    return 1;
    }

string query_gtitle() { 
    if(query_female()) return "la Creadora"; 
    return "el Creador"; 
    }

string query_object_type() { return "B"; }