// Vilat lo reforma pa q veais que curra - 16.11.2002

#include "player.h"
#include "commands.h"

string race_ob, guild_ob, *known_commands, clase_ob;
string ciudadania="Sin Ciudadania";
string group_ob, race_group_ob;
nosave mapping gr_commands;

void race_guild_commands() {
    	int i;

    	if (!known_commands) known_commands = ({ "considerar", "enterrar", });
   	add_action("list_commands", "comandos");

    	if(guild_ob) catch(guild_ob->start_player(this_object()));
    	if(race_ob) catch(race_ob->start_player(this_object()));
    	if(group_ob) catch(group_ob->start_player(this_object()));
    	if(race_group_ob) catch(race_group_ob->start_player(this_object()));
	if(clase_ob) catch(clase_ob->start_player(TO));

    	gr_commands = ([ ]);
    	for (i=0;i<sizeof(known_commands);i++) {
		gr_commands[known_commands[i]] = (string *)COMMAND_SERVER->query_command(known_commands[i]);
		if (!pointerp(gr_commands[known_commands[i]])) continue;
		add_action("do_command", known_commands[i]);
    		}
    	add_action("add_new_command", "Add_New_Command");
	}

int do_command(string str) {
    	if(this_player()->query_dead() || this_player()->query_property("noguild") || environment(this_player())->query_property("noguild") ) {
		tell_object(this_player(),"No puedes hacer eso aqui y ahora.\n");
		return 1;
    		}

    	if (!pointerp(gr_commands[query_verb()])) return 0;

    	if (!gr_commands[query_verb()][1]) return 0;

    	return (int)call_other(gr_commands[query_verb()][0],gr_commands[query_verb()][1], str);
	}

string query_gtitle() {
    	string str;
    	if (guild_ob) if (catch((str = (string)guild_ob->query_title(this_object())))) return "Has a broken guild";
	else return str;
	}

void set_race_ob(string str) {
    	string frog;
    	if(!str) str = "/rol/razas/desconocido";
    	if( sscanf(str, "/%s", frog)==1) str = extract(str, 1);
/*    	if (str[0..strlen("/rol/razas")]!="/rol/razas") {
		write("Path incorrecto.\n");
		return;
    		}*/
    	if(str[0..strlen("/rol/razas/dios")-1] == "/rol/razas/dios" && !"/secure/master"->high_programmer(geteuid())) {
		write("El Cielo se remueve ante tu intento. Te detienes.\n");
		return;
    		}

    	if( (file_size(str) < 1) && (file_size(str+".c") < 1) ) {
		tell_object(this_object(),"El intento de fijar raza no tuvo exito. Diselo a alguien que pueda arreglarlo.\n");
		return;
    		}
	if(race_ob) this_object()->remove_language(race_ob->query_name());
    	race_ob = str;
    	race_ob->start_player(this_object());
    	return;
	}

void set_race(string str) { return set_race_ob("/rol/razas/"+str); }

string query_race_ob() { return race_ob; }

string query_race_name() {
    	if(race_ob) return ((string)race_ob->query_name());
    	else return "Sin Raza.";
	}

string query_race() { return query_race_name(); }

int set_guild_ob(string str) {
    	if(!stringp(str)) {
		guild_ob = 0;
		return 0;
    		}
    	if( (file_size(str) < 0) && (file_size(str+".c") < 0) ) return 0;

    	guild_ob = str;
	return 1;
	}

void set_guild(string str) {
    	if(!set_guild_ob("/rol/gremios/"+str)) return;
    	return;
	}

string query_guild_ob() { return guild_ob; }

string query_guild() {
    	if (guild_ob) return guild_ob[strlen("/rol/gremios/")..];
    	else return ("Sin gremio.");
	}

// nuevo by Tyrael - Ene '02
string query_guild_short() {
    	if (guild_ob) return ((string)guild_ob->query_short());
    	else return ("Sin gremio.");
	}

mapping query_gr_commands() { return gr_commands+([ ]); }

string help_command(string str) {
    	if (!pointerp(gr_commands[str])) return 0;
    	return (string)gr_commands[str][0]->help(str);
	}

int list_commands() {
    	write("Tus comandos actuales son:\n"+sprintf("%-#*s\n",this_player()->query_cols(), implode(m_indices(gr_commands), "\n")));
    	return 1;
	}

string *query_known_commands() { return known_commands+({ }); }

nosave private int allowed_add;

int add_known_command(string str) {
    	mixed tmp;

    	if (member_array(str, known_commands) != -1) return 0;
    	tmp = (mixed *)COMMAND_SERVER->query_command(str);
    	if (!pointerp(tmp)) return 0;
    	known_commands += ({ str });
    	gr_commands[str] = tmp;
    	add_action("do_command", str);
    	return 1;
	}

int remove_known_command(string str) {
    	int i;

    	if ((i = member_array(str, known_commands)) == -1) return 0;
    	known_commands = delete(known_commands, i, 1);
    	gr_commands = m_delete(gr_commands, str);
    	return 1;
	}

int add_new_command(string str) {
    	if (!allowed_add) return 0;
    	add_action("do_command", str);
    	return 1;
	}

void set_group_ob(string str) {
    	string tmp;
	TO->remove_property("clan_title");
    	if(!stringp(str) || !str) {
		group_ob = 0;
		return;
    		}
    	if(sscanf(str,"/%s", tmp) == 1) str = extract(str,1);
    	if(str[0..strlen("std/groups")-1]!="std/groups") {
		write("Illegal path to set_group_ob.\n");
		return;
    		}

    	if(file_size(str+".c") < 1) {
		tell_object(this_object(),"Attempt to set group did not work.  Tell someone who can fix it.\n");
		return;
    		}
    	group_ob = str;
    	group_ob->start_player(this_object());
    	return;
	}

string query_group_title() { return TO->query_property("clan_title"); }

void set_group_title(string title) { TO->add_property("clan_title", title); }

string query_group_ob() {
    	if(file_size("/"+group_ob+".c") < 1) group_ob = 0;
    	return group_ob;
	}

string query_group_name() {
    	if (group_ob) return ((string)group_ob->query_short());
    	else return ("Sin clan.");
	}

void set_race_group_ob(string str) {
    	string tmp;

	TO->remove_property("race_title");
    	if(!stringp(str) || !str) {
		race_group_ob = 0;
		return;
    		}
    	if(sscanf(str,"/%s", tmp) == 1) str = extract(str,1);
    	if(str[0..strlen("std/race_groups")-1]!="std/race_groups") {
		write("Illegal path to set_race_group_ob.\n");
		return;
    		}

    	if(file_size(str+".c") < 1) {
		tell_object(this_object(),"Attempt to set race group (clan) did not work.  Tell someone who can fix it.\n");
		return;
    		}
    	race_group_ob = str;
    	race_group_ob->start_player(this_object());
    	return;
	}

string query_race_group_title() { return TO->query_property("race_title"); }

void set_race_group_title(string title) { TO->add_property("race_title", title); }

string query_race_group_ob() { return race_group_ob; }

string query_race_group_name() {
    	if (race_group_ob) return ((string)race_group_ob->query_short());
    	else return ("Sin grupo racial.");
	}

int set_ciudadania(string str) {
 	if(!str) return 0;
 	ciudadania=str;
 	return 1;
 	}

string query_ciudadania() { return ciudadania; }

int query_relacion(object ob) {
	if(lower_case(ciudadania)=="sin ciudadania"||lower_case(ciudadania)=="destierro") return 0;
	if(file_size("/d/ciudades/"+lower_case(ciudadania)+".c")<1) return 0;
	else return ("/d/ciudades/"+lower_case(ciudadania))->query_relacion(ob);
	}

int fijar_clase_ob(string str) {
    	if(!stringp(str)) {
		clase_ob = 0;
		return 0;
    		}
    	if( (file_size(str) < 0) && (file_size(str+".c") < 0) ) return 0;

    	clase_ob = str;
	return 1;
	}

void fijar_clase(string str) {
    	if(!fijar_clase_ob("/rol/clases/"+str)) return;
    	return;
	}

string query_clase_ob() { return clase_ob; }

string query_clase() {
    	if (clase_ob) return clase_ob[strlen("/rol/clases/")..];
    	else return ("Sin clase.");
	}
