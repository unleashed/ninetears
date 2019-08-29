/* bALdrick was here.
 * Added set_thac0 / adjust THAC0 
 * Removed the skilltree from cost until I know what to do with it.
 * Added exponential XP-cost. june '94.
 * Taniwha 1995 (just), make advance SET thac0 rather than adjust it
   * fixes transition probs from newbie guild and compensates for any thac0
   * accidents
 */

inherit "/std/room";
void clean_up(int flag) { }

#include "skills.h"
#include "tune.h"
#include "money.h"
#include "level_track.h"
#define my_race_ob this_player()->query_race_ob()
#define SPELL_TABLE "/table/spell_table.c"

string our_guild;
object guildmaster;
 
int check_before_join() {
   	return 1;
	}

void create() {
  	::create();
	}

void init() {
  	::init();
   	this_object()->add_property("no_undead",1);
  	add_action("do_join", "join");
  	add_action("do_join", "unirse");
  	add_action("do_join", "alistarse");
  	add_action("do_info", "info");
  	}

int this_guild() {
  	string guild;
  	guild = this_player()->query_guild_ob();
  	if (guild==our_guild) return 1;
	return 0;
      	}

void set_guild(string str) { our_guild = "/rol/gremios/"+str; }
string query_guild() { return our_guild; }

int do_join(string str) {
  	string guild;
  	string race;
	int i=0,a;

  	guild = (string)this_player()->query_guild_ob();
  	race  = (string)this_player()->query_race();
	
	if(!guildmaster) return notify_fail("El guildmaster no est�.\n");

  	if(guild == our_guild) return notify_fail("Ya eres miembro de este gremio.\n");
  	if(guild) return notify_fail("No puedes unirte a este gremio porque ya eres miembro de otro.\n");

  	if(!our_guild->query_legal_race(race)) return notify_fail("Lo siento, pero los de tu raza no son admitidos en este gremio.\n");
	if(TP->query_clase()!=our_guild->query_clase()) return notify_fail("Lo siento, aqui no aceptamos a los de esa clase.\n");
	for(a=0;a<sizeof(our_guild->query_needed_align());a++) if(TP->query_alineamiento()[0]==our_guild->query_needed_align()[a][0]&&TP->query_alineamiento()[1]==our_guild->query_needed_align()[a][1]) i=1;
	if(!i) return notify_fail("Tu alineamiento no es v�lido.\n");

   	if(!TO->check_before_join()) return 0;

  	write("S�lo puedes unirte a un gremio. �Est�s segur"+(TP->query_gender()==2?"a":"o")+"? ");
  	input_to("join2",2);
  	return 1;
	}

int join2(string str) {
  	str = lower_case(str);
  	if (str[0] != 'n' && str[0] != 's') {
    		write("No lo entiendo.  S/N? ");
    		input_to("join2",2);
    		return 1;
  		}
  	if (str[0] == 'n') {
    		write("Vale, has decidido no unirte al gremio "+ our_guild->query_short()+".\n");
    		return 1;
  		}

  	this_player()->set_guild_ob(our_guild);
  	this_player()->race_guild_commands();

  	write("Ahora eres un nuevo miembro del gremio " +our_guild->query_short()+".\n");

  	say(this_player()->query_cap_name()+" se une al gremio "+ our_guild->query_short()+".\n");

  	event(this_object(), "guild_join");
  	event(users(), "inform", this_player()->query_cap_name()+" es un nuevo miembro del gremio "+our_guild->query_cap_name(), "join");

  	return 1;
	}

void set_guildmaster(string bing) { 
    guildmaster=clone_object(bing);
    guildmaster->move(TO);
    }

int do_info() {
	if(!guildmaster) return notify_fail("El guildmaster no est�.\n");
  	write(our_guild->long());
  	return 1;
	}

object query_guildmaster() { return guildmaster; }

