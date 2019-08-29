/*
 * Changed to maintain an mapping of arrays of everyone on a channel
 * Also performed so major cleanups...more than doubled the efficiency
 *    -- Wahooka April '97
 */

// BUGS de colores en el history y canal sin mensajes solucionados.
// Tyrael - May'02

#include "standard.h"
#include <network.h>

#define GUILD this_player()->query_guild_ob()
#define GROUP this_player()->query_group_ob()
#define RACEG this_player()->query_race_group_ob()  

#define MAX_CHAN_HIST 20

mapping channels = ([ ]), history = ([ ]);

int query_channel_on(object ob, string chan);
int query_channel_permission(object ob, string chan);
varargs void do_channel(string verb, string str, string name, string mud, int flg);

void init_player_channels(string *chans) {
    	int i;
    	for(i=0;i<sizeof(chans);i++) {
		if(!query_channel_permission(this_player(), chans[i])) continue;
		if(!channels[chans[i]]) channels[chans[i]] = ({ });
		if(query_channel_on(this_player(), chans[i])) continue;
		channels[chans[i]] += ({ this_player() });
    		}
    	if(this_player()->query_creator() &&  !query_channel_on(this_player(), "emergencia")) {
		if(!channels["emergencia"]) channels["emergencia"] = ({ });
		channels["emergencia"] += ({ this_player() });
    		}
	}

int query_channel_on(object ob, string chan) {
  	return member_array(ob, channels[chan]) != -1;
	}

int query_channel_permission(object ob, string chan) {
    	switch(chan) {
    		case "cre":
    		case "zonas":
    		case "programacion":
		if(ob->query_creator()) return 1;
    		case "thane":
		if(ob->query_thane()) return 1;
    		case "semidios":
    		case "admin":
		if (ob->query_lord()) return 1;
		case "dios":
		return ob->query_god();
    		default: return 1;
    		}
	}

object *query_who_on(string chan) {
    	object *ret = channels[chan];
    	if(!this_player()->query_lord()) {
		int i;
		for(;i<sizeof(ret);i++)
	    	if(ret[i]->query_invis() == 2) {
			ret -= ret[i..i];
			i--;
	    		}
    		}
    	return ret;
	}

protected void add_history(string chan, string mess) {
  	if(!history[chan]) {
    		history[chan] = ({ mess });
    		return;
  		}
  	if(sizeof(history[chan]) >= MAX_CHAN_HIST) {
    		history[chan] = history[chan][1..] + ({ mess });
    		return;
  		}
  	history[chan] += ({ mess });
	}

string get_history(string chan) {
  	if(!history[chan]) return "No hay mensajes en el canal.\n";
  	return implode(history[chan], "\n");
	}

int do_chat( string str ) {
    	string verb = query_verb();
    	if(!str || str =="") {
		message("Debes especificar un mensaje.\n","",TP);
		return 1;
    		}
    	if(verb == "emergencia") {
		do_channel(verb, str, this_player()->query_cap_name());
		return 1;
    		}

    	if(this_player()->query_property("chan_"+verb) == "nope") {
		message("Tu canal ha sido quitado.\n","",TP);
		return 1;
    		}

	if(verb == "guild" || verb == "gremio") {
		if(!GUILD) {
	    		message("No eres miembro de ningun gremio.\n","",TP);
	    		return 1;
			}
		if(!GUILD->query_channel()) {
	    		message("Tu gremio no tiene esa habilidad.\n","",TP);
	    		return 1;
			}
		verb = (string)GUILD->query_short();
    		}
    	if(verb == "clan" || verb == "group") {
		if(!GROUP) {
	    		message("No eres miembro de ningun clan.\n","",TP);
	    		return 1;
			}
		if(!GROUP->query_channel()) {
	    		message("Tu clan no tiene esa habilidad.\n","",TP);
	    		return 1;
			}
		verb = (string)GROUP->query_name();
    		}
    	if(verb == "race" || verb == "raza") {
		if(!RACEG) {
	    		message("No eres miembro de ningun grupo racial.\n","",TP);
	    		return 1;
			}
		if(!RACEG->query_channel()) {
	    		message("Tu grupo racial no tiene esa habilidad.\n","",TP);
	    		return 1;
			}
		verb = (string)RACEG->query_name();
    		}

    	if(verb == "ciudad") {
		if(!TP->query_ciudadania()||lower_case(TP->query_ciudadania())=="sin ciudadania") {
	    		message("No eres miembro de ninguna ciudad.\n","",TP);
	    		return 1;
			}
		if(lower_case(TP->query_ciudadania())=="destierro") {
	    		message("Los desterrados no teneis canal de ciudad.\n","",TP);
	    		return 1;
			}
		if(file_size("/d/ciudades/"+lower_case(TP->query_ciudadania())+".c")<1) {
			message("Tu ciudadania no es valida.\n","",TP);
			return 1;
			}
		verb = ":"+CAP(lower_case(TP->query_ciudadania()));
    		}

    	if(!query_channel_permission(this_player(), verb)) {
		message("No se te permite usar el canal "+verb+".\n","",this_player());
		return 0;
    		}

    	switch( str ) {
    		case "off" :
		if(!query_channel_on(this_player(), verb)) {
	    		if(verb[0]!=':') message("El canal "+verb+" ya esta apagado!\n","",this_player());
			else message("El canal "+verb[1..]+" ya esta apagado!\n","",this_player());
	    		return 0;
			}
		if(verb[0]!=':') message("Ok, apagas el canal "+verb+".\n","",TP);
		else message("Ok, apagas el canal "+verb[1..]+".\n","",TP);
		this_player()->adjust_property("channels",({verb}),-1);
		channels[verb] -= ({ this_player() });
		return 1;
    		case "on" :
		if(query_channel_on(this_player(), verb)) {
	    		if(verb[0]!=':') message("El canal "+verb+" ya esta abierto!\n","",this_player());
			else message("El canal "+verb[1..]+" ya esta abierto!\n","",this_player());
	    		return 0;
			}
		if(!channels[verb]) channels[verb] = ({ });
		if(verb[0]!=':') message("Ok, abres el canal "+verb+".\n","",TP);
		else message("Ok, abres el canal "+verb[1..]+".\n","",TP);
		if(member_array(verb,this_player()->query_property("channels")) == -1) this_player()->adjust_property("channels",({verb}));
		channels[verb] += ({ this_player() });
		return 1;
    		}

    	if(!query_channel_on(this_player(), verb)) {
		message("No tienes ese canal abierto.\n","",TP);
		return 1;
    		}
    	
  	do_channel(verb, str, this_player()->query_cap_name());
    	return 1;
	}

string get_channel_help(string verb) {
  	string ret;
  	if(!verb) verb = "<canal>";
  	ret = 
   	"'"+verb+" <mensaje>': Mandar un mensaje a toda la gente que escucha el canal.\n"
   	"'"+verb+" ?': Este mensaje de ayuda.\n"
   	"'"+verb+" @': Emote en el canal.\n"
   	"'"+verb+" !': Ver los ultimos "+MAX_CHAN_HIST+" mensajes del canal.\n";
  	ret += "'"+verb+" .': Ver la lista de gente que escucha el canal.\n";
  	return ret;
	}   

#define chan_msg() message(str+"%^RESET%^", name+" "+(flg?"(":"[")+CAP(verb)+(flg?")":"]")\
                    +": ", channels[verb]);\
              add_history(verb, name+" "+(flg?"(":"[")+CAP(verb)+(flg?")":"]")\
               +": "+str+"%^RESET%^");\
               if (!mud) if(verb=="chat"||verb=="intercre") "/net/intercre.c"->transmitir_mensaje(TP,verb,str);
#define check_cmd() if(strlen(str) > 1) { chan_msg(); return; }

varargs void do_channel(string verb, string str, string name, string mud, int flg) {
  	if(sizeof(channels[verb])) channels[verb] -= ({ 0 });
  	else channels[verb] = ({ });

  	if(mud) name = name+"@"+mud;

  	switch(str[0]) {
    		case '!':
      		check_cmd();
		if(verb[0]!=':') message(get_history(verb), "Historia del canal "+verb+":\n", TP);
      		else message(get_history(verb), "Historia del canal "+verb[1..]+":\n", TP);
      		return;
    		case '?' :
      		check_cmd();
      		if(verb[0]!=':') message(get_channel_help(verb), "Ayuda del canal "+verb+":\n", TP);
		else message(get_channel_help("ciudad"), "Ayuda del canal "+verb[1..]+":\n", TP);
      		return;
    		case '@' :
               	if(verb[0]!=':') {
			if (!mud) if(verb=="chat"||verb=="intercre") "/net/intercre.c"->transmitir_mensaje(TP,verb,str);
      			message(name+" "+str[1..]+"%^RESET%^", (flg?"(":"[")+CAP(verb)+(flg?") ":"] "),channels[verb]);
      			add_history(verb,(flg?"(":"[")+CAP(verb)+(flg?") ":"] ")+name+" "+str[1..]+"%^RESET%^");
			}
		else {
      			message(name+" "+str[1..]+"%^RESET%^", (flg?"(":"[")+("/d/ciudades/"+lower_case(verb[1..]))->query_titulo(name)+" de "+CAP(verb[1..])+(flg?") ":"] "),channels[verb]);
      			add_history(verb,(flg?"(":"[")+("/d/ciudades/"+lower_case(verb[1..]))->query_titulo(name)+" de "+CAP(verb[1..])+(flg?") ":"] ")+name+" "+str[1..]+"%^RESET%^");
			}
      		break;
    		case '.' :
      		if(!this_player()) {
        		chan_msg();
        		return;
      			}
		if(verb[0]!=':') message(nice_list(query_who_on(verb)->query_cap_name()), "Gente escuchando el canal "+verb+": ", TP);
		else message(nice_list(query_who_on(verb)->query_cap_name()), "Gente escuchando el canal "+verb[1..]+": ", TP);
      		break;
    		default:
		if(verb[0]!=':') {
      			message(str+"%^RESET%^", name+" "+(flg?"(":"[")+CAP(verb)+(flg?")":"]")+": ", channels[verb]);
			add_history(verb, name+" "+(flg?"(":"[")+CAP(verb)+(flg?")":"]")+": "+str+"%^RESET%^");
			if (!mud) if(verb=="chat"||verb=="intercre") "/net/intercre.c"->transmitir_mensaje(TP,verb,str);
			}
		else {
      			message(str+"%^RESET%^", name+" "+(flg?"(":"[")+("/d/ciudades/"+lower_case(verb[1..]))->query_titulo(name)+" de "+CAP(verb[1..])+(flg?")":"]")+": ", channels[verb]);
			add_history(verb, name+" "+(flg?"(":"[")+("/d/ciudades/"+lower_case(verb[1..]))->query_titulo(name)+" de "+CAP(verb[1..])+(flg?")":"]")+": "+str+"%^RESET%^");
			}
		break;
  		}
	}

int clean_up() { return 0; }
