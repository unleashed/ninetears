// Grope (around in the dark)
// For blind players to find their way.
// Quark, April 97

#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
void setup() {
    position = 0;
    }

string query_usage() {
    return "tantear";
    }

string query_short_help() {
    return "Sirve para tantear por la sala en busca de salidas.";
    }

int cmd(string arg, object me) {
    mixed *exits, exit;
    object *contents;
    int i,j;

    i = random(10);

// if(!me->query_property("BLIND")) return 0;

    if(me->query_property("JUST_SEARCHED")) return notify_fail("Espera un poco.\n");
 
    me->add_timed_property("JUST_SEARCHED",1,1);

    if(i<3) {
	contents = all_inventory(environment(me)); 
	j = random(sizeof(contents));
	if(interactive(contents[j])) {
    	    tell_object(me, "Palpas a "+contents[j]->query_cap_name()+".\n");
    	    tell_object(contents[j],me->query_cap_name()+" te palpa.\n");
    	    tell_object(environment(me),me->query_cap_name()+" palpa a "+contents[j]->query_cap_name()+".\n",({ me, contents[j]}));
    	    }
        else if(contents[j]->query_npc()) {
            tell_object(me, "Parece que "+contents[j]->query_cap_name()+" se ha tomado a mal que le toquetees.\n");
	    tell_object(environment(me),"�"+me->query_cap_name()+" choca con "+contents[j]->query_cap_name()+", quien se lo toma a mal y ataca!\n",({ me, }));
    	    contents[j]->attack_ob(me);
    	    }
        else {
            tell_object(me,"Descubres "+contents[j]->query_cap_name()+".\n");
	    tell_object(environment(me),me->query_cap_name()+" choca contra "+contents[j]->query_cap_name()+".\n");
	    }      
        return 1;
	}
    else {
	exits = environment(me)->query_dest_dir();  
	if(sizeof(exits)) {
	    exit = exits[(random(sizeof(exits)/2))*2];
	    tell_object(me, "Palpas a tu alrededor y descubres una salida hacia "+exit+".\n");
    	    return 1;
    	    }
	}
    return notify_fail("No encuentras nada.\n");
    }
