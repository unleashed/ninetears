// Vilat 19.01.2003
// A ver si apa�o el puto goto

#include <cmd.h>
inherit CMD_BASE;
inherit "/cmds/handlers/wiz_cmd_base";

void setup(){
    position = 1;
    }

int cmd(string str, object me) {
    object dest;
    string nick;
    
    if(!me) me=TP;
    
    if (!str) return notify_fail("Teletransporte a... donde?\n");

    nick = me->expand_nickname(str);
    dest = find_living(nick);
    if (dest) {
	if(dest = environment(dest)) {
	    if (dest == environment(me)) return notify_fail("You look around and realise you are already there.\n");
	    me->move_player("X",dest);
	    return 1;
	    } 
	else return notify_fail(capitalize(nick) + " is not standing in a location.\n");
        }
    else {
	if (!(dest = find_object(str))) {
	    catch(str->lameme_las_botas_xD());
	    dest = find_object(str);
	    }
	if (!dest) {
	    catch((me->query_current_path()+"/"+str)->lameme_las_botas_xD());
	    dest = find_object(me->query_current_path()+"/"+str);
	    }
	if (!dest) return notify_fail("Failed to load " + str + "\n");
	else if(!dest->query_property("location")) return notify_fail("Not a room: " + str + "\n");
	else {
	    if (dest == environment()) {
		notify_fail("You look around and realise you are already there.\n");
		return 0;
		}
	    me->move_player("X",dest);
	    me->set_trivial_action();
	    return 1;
	}
    }
} /* teleport() */

