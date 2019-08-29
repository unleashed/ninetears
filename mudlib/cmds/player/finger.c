#include <standard.h>
#include <cmd.h>
 
inherit CMD_BASE;
  
string strip(string instr);
 
void setup() { position = 0; }
 
string query_usage() { return "command"; }


int cmd(string str, object me) {
    string ret;


    if (!str) {
	object *obs;
        string type;
	int i;

        obs = users();

	// cambiar write por efun pa los colores
	TP->do_efun_write(sprintf("%-12.12s    %-20.20s %-20.20s %-20.20s\n", "Nombre", "Nombre Real", "Domicilio", "Cumplea�os"));
	for (i=0;i<sizeof(obs);i++) {
    	    string euid;
	    string rnstr;
	    string pname;

	    if (obs[i]->query_invis() && !this_player()->query_creator())  continue;
            if ((int)obs[i]->query_invis() > 1 && !this_player()->query_god()) continue;
            type = (obs[i]->query_earmuffs() ? "e" : " ");
	    euid = geteuid(obs[i]);

            type = (obs[i]->query_object_type());

	    rnstr = obs[i]->query_real_name();
            pname = obs[i]->query_name();
	    if(rnstr && rnstr[0..0] == ":")
            if(!"/secure/master"->valid_read("/players/"+pname[0..0]+"/"+pname,geteuid(this_player(1))))
            rnstr = "-";

    	    TP->do_efun_write(sprintf("%-12.12s %2.2s %-20.20s %-20.20s %-20.20s\n",(obs[i]->query_invis()?"("+obs[i]->query_name()+")":(string)obs[i]->query_name()),type,(rnstr?rnstr:"-"),((ret = (string)obs[i]->query_where())?ret:"-"),((ret = (string)obs[i]->query_birthday())?ret:"-")));
	    }
        return 1;
	}

    str = (string)this_player()->expand_nickname(str);
    if(ret = (string)"/secure/finger"->finger_info(str)) {
	TP->do_efun_write(ret);
	return 1;
	} 
/*  else if (me->query_creator() &&  sscanf(str, "%s@%s", mud, mud) == 2) {
	"/net/intermud3/daemon/finger"->do_finger(str);
	return 1;
	} */
    else return notify_fail("Nadie con el nombre " + CAP(str) + " ha visitado Ninetears.\n");
    } /* finger() */

// ^G es pitido?
string strip(string instr) {
   instr = replace_string(instr,"","");
  return replace_string(instr,"%^","");
}
