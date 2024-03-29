inherit "/global/wiz_file_comm";

#define NO_SWAP
#define ECHO_ALLOWED

void load_login();
#ifndef NO_SWAP

 // string o_type, g_title;

static string omsgin, omsgout, ommsgin, ommsgout;
static int oxp, omax_deaths=18, odeaths;
static mixed *oskills;
static mapping oprop;
static mapping ospells;

/* I wonder if I don't use static in these definitions, will it be saved in
 * player.o ? Baldrick. 
 * Yup, I'll learn.. :=)*/
nomask int query_lord() { return 0; } // Taniwha 1995
nomask int query_demi() { return 0; } // Taniwha 1995

int look_me(string str) {
  if (!str && environment())
    write(virtual_file_name(environment()) + "\n");
  return ::look_me(str);
} /* look_me() */

int do_glance(string str) {
  if (!str && environment())
    write(virtual_file_name(environment()) + "\n");
  return ::do_glance(str);
} /* do_glance() */

static void swap_entryexit() 
{
  string tmin, tmout, tmmin, tmmout;
  int txp, tdeaths, tmax_deaths;
  mixed tskills, tprop, tspells;

  tmin = msgin;
  tmout = msgout;
  tmmin = mmsgin;
  tmmout = mmsgout;
  msgin = omsgin;
  msgout = omsgout;
  mmsgin = ommsgin;
  mmsgout = ommsgout;
  omsgin = tmin;
  omsgout = tmout;
  ommsgin = tmmin;
  ommsgout = tmmout;
  txp = xp;
  xp = oxp;
  oxp = txp;
  tskills = skills;
  skills = oskills;
  oskills = tskills;
  tspells = spells;
  spells = ospells;
  ospells = tspells;
  tdeaths = deaths;
  deaths = odeaths;
  odeaths = tdeaths;
  tmax_deaths = max_deaths;
  max_deaths = omax_deaths;
  omax_deaths = tmax_deaths;
}
#else
void swap_entryexit() {
}
#endif


void move_player_to_start(string bong, int new_pl, int going_invis) {
  string temp;

  if(!sscanf(file_name(previous_object()), "/secure/login#%s", temp))
    return 0;
  cat("doc/CREATORNEWS");
  ::move_player_to_start(bong, new_pl, going_invis);

  if(query_invis())
    tell_object(this_object(), "===> Actualmente estas INVISIBLE! <===\n");
  swap_entryexit();
#ifndef NO_SWAP
  xp = oxp;
#endif
  add_action("visible", "vis");
  add_action("invisible", "invis");
  load_login();
   /* Added by Asmodean cause Aragorn taught him how :) */
   /* Taking it out, doesn't work.  Wonderflug dec 95
   enable_wizard();
    */
  enable_wizard();
}



void load_login(){
string *strs;
int n;
if(read_file("/w/"+name+"/.login")){
strs=explode(read_file("/w/"+name+"/.login"),"\n");
for(n=0;n<sizeof(strs);n++)
command(strs[n]);

}
}
string short(int dark) {
  if (query_invis())
    if(!this_player() || this_player()->query_creator())
      return "*"+::short(dark)+"*";
    else
      return 0;
  else
    return ::short(dark);
}

string combat_short(int dark) {
	short(dark);
}

int visible() {
  if(!query_invis()) {
    notify_fail("Ya estas visible.\n");
    return 0;
  }
	// no se si interesa informar *erroneamente claro xD* sobre esto
	//event(users(), "inform", this_player()->query_cap_name + " entra en el MUD");
  write("Apareces.\n");
  say(query_cap_name()+" aparece de pronto.\n", this_player());
  set_invis(0);
  return 1;
}

int invisible() {
  if(query_invis()) {
    notify_fail("Ya estas invisible.\n");
    return 0;
  }
  write("You disappear.\n");
  say(query_cap_name()+" desaparece de repente.\n", this_player());
  set_invis(1);
  return 1;
}

void save_me() {
  swap_entryexit();
  ::save_me();
  swap_entryexit();
}

int query_creator() { return 1; }
nomask int query_lord() { return 0; }
// people like to shadow this to snoop the demi channel.... Hpj
int query_app_creator() { return app_creator; }
int query_creator_playing() { return 0; }

string query_gtitle() 
{ 
/*
  if (query_female())
    return "the Student"; 
   else
*/

	switch(TO->QCN) {
		case "Leviathan":
			return "el Senyor de las Bestias de la Suboscuridad";
		case "Jerkat":
			return "la Lady de Trior";
		case "Shimmer":
			return "el Guardian de Hahn";
                case "Xerxes":
                        return "el Siniestro Thane de Urghak";
		case "Enialish":
			return "el Emperador de Elhadrien";
		case "Blastaar":
			return "el Senyor de las Montanyas";
		case "Thalos":
			return "el Lord de las Minas";
		case "Krull":
			return "el Protector de la Dama Oscura";
		case "Vilat":
			return "the Endbringer";
		case "Andorogynus":
			return "el Principe de las Tinieblas";
		case "Aeoris":
			return "el Mudlibber";
                case "Huascar":
                        return "the Fastest Coder";
                case "Flangerant":
                	return "el Escriba de los Dioses";
		case "Sharka":
			return "el General de los Ejercitos del Bien";
		case "Kivara":
			return "el Patron de Guerreros";
	}

  if (query_female())
    return "la Aprendiz"; 
  return "el Aprendiz"; 
}

string query_object_type() {
  return "B";
}  /* query_object_type() */

