#include "mail.h"

string title;
string ident;

string apellido,email,guild_ob,race_ob,ciudadania,last_on_from,last_pos;
int creator,start_time,time_on,last_log_on;
mapping aliases;

string make_string(mixed *al) {
    	string str;

    	str = (string)"/global/alias"->alias_string(al);
    	sscanf(str, "%s $*$", str);
    	return str;
	} /* make_string() */

// Esto se usa?
string banish_finger(string name) {
    	string retval;
    	string *file;

    	file = explode(read_file("/banish/"+name+".o"), "\n");
    	retval =  sprintf("%35-s%35-s\n", "Nombre : "+name, "Real name : "+"Baneado");
    	retval += "Realmente muy joven.\n";
    	retval += "Sin cartas.\n";
    	retval += "Sin plan.\nSin futuro.\n";
    	if (this_player()->query_creator()) if (sizeof(file) == 3) retval += implode(file, "\n")+"\n";
	else retval += "Banish info not in the correct format.\n";
    	return retval;
	}

string domain_finger(string name) {
    	string ret, master;

    	master = "/d/"+name+"/master";
    	ret = "El dominio "+name+".\n";
    	ret += "El Thane de este dominio es "+CAP(master->query_dom_lord())+".\n";
    	ret += "Los miembros de este dominio son "+
    	implode((string *)master->query_members(), ", ")+".\n";
    	if (master->query_info()) ret += (string)master->query_info();
    	else ret += "It hasn't been idle.\n";
    	return ret;
	} /* domain_finger() */

string finger_info(string name) {
    	string retval, nick, *bing,buf;
    	object ob;
    	mapping mail_stat;
    	int i;

    	if (nick) name = nick;
    	seteuid("Root");
    	if (file_size("/d/"+name) == -2) return domain_finger(name);
    	if (!"/secure/login"->test_user(name)) return 0;

	apellido=email=guild_ob=race_ob=ciudadania=last_on_from=last_pos=0;
	creator=start_time=time_on=last_log_on=0;
	aliases=([]);

	restore_object("/players/"+name[0..0]+"/"+name,1);

    	retval = "{%^RESET%^ "+CAP(name)+" %^RESET%^CYAN%^}"+(strlen(name)%2?"=":"");
	for(i=longitud(retval)+4+(strlen(name)%2?2:0);i<TP->query_cols();i+=2) retval="="+retval+"=";
	retval="\n%^CYAN%^O"+retval+"O%^RESET%^\n\n";
	retval +=  "%^BOLD%^ - Nombre     :%^RESET%^ "+CAP(name)+(apellido?" "+apellido:"")+"\n";
    	if (email) {
		if (email[0] == ':') {
	    		if ("/secure/master"->valid_read("/players/"+name[0..0]+"/"+name,geteuid(this_player(1)))) retval += "%^BOLD%^ - E-mail     : %^RESET%^"+email[1..strlen(email)-1]+" %^RED%^BOLD%^(oculto)%^RESET%^\n";
			}
		else retval += "%^BOLD%^ - E-mail     : %^RESET%^"+email+"%^RESET%^\n";
		}
      	if(race_ob) retval+= "%^BOLD%^ - Raza       : %^RESET%^"+CAP(race_ob->query_name())+"%^RESET%^\n";
	if (guild_ob && this_player(1)->query_creator()) {
		if( (file_size(guild_ob) > 0) || (file_size(guild_ob+".c") > 0) ) {
			if(!catch(guild_ob->query_short())) retval += "%^BOLD%^ - Gremio     : %^RESET%^"+guild_ob->query_short()+"%^RESET%^\n";
			else retval += "%^BOLD%^ - Gremio     : %^RED%^Erroneo%^RESET%^\n";
			}
		else retval += "%^BOLD%^ - Gremio     : %^YELLOW%^Inexistente%^RESET%^\n";
    		}
    	if(ciudadania) retval += "%^BOLD%^ - Ciudadania : %^RESET%^"+CAP(ciudadania)+"%^RESET%^\n";
	retval+="\n";
	if (creator) {
		bing = get_dir("/d/");
		for (i=0;i<sizeof(bing);i++) if (file_size("/d/"+bing[i]) == -2) {
			if (("/d/"+bing[i]+"/master")->query_dom_lord() != name) {
				bing = delete(bing, i, 1);
		    		i--;
				}
			}
		buf="";
		for(i=0;i<sizeof(bing);i++) {
			if (i<sizeof(bing)-2) buf+=CAP(bing[i])+", ";
			else if(i<sizeof(bing)-1) buf+=CAP(bing[i])+" y ";
			else buf+=CAP(bing[i]);
			}
		if(sizeof(bing)) retval+="  Es %^BOLD%^Thane%^RESET%^ de "+buf+".\n\n";

		bing = get_dir("/d/");
		for (i=0;i<sizeof(bing);i++) if (file_size("/d/"+bing[i]) == -2) {
			if (!("/d/"+bing[i]+"/master")->query_member(name)) {
				bing = delete(bing, i, 1);
		    		i--;
				}
			}
		buf="";
		for(i=0;i<sizeof(bing);i++) {
			if (i<sizeof(bing)-2) buf+=CAP(bing[i])+", ";
			else if(i<sizeof(bing)-1) buf+=CAP(bing[i])+" y ";
			else buf+=CAP(bing[i]);
			}
		if(sizeof(bing)) retval+="  Es %^BOLD%^Miembro%^RESET%^ de "+buf+".\n\n";

		bing = ({ });
		catch(bing = "/d/gremios/master"->query_patronages(name));
		buf="";
		for(i=0;i<sizeof(bing);i++) {
			if (i<sizeof(bing)-2) buf+=CAP(bing[i])+", ";
			else if(i<sizeof(bing)-1) buf+=CAP(bing[i])+" y ";
			else buf+=CAP(bing[i]);
			}
		if(sizeof(bing)) retval+="  Es %^BOLD%^Patron%^RESET%^ de "+buf+".\n\n";

		bing = ({ });
		catch(bing = "/d/ciudades/master"->query_regencias(name));
		buf="";
		for(i=0;i<sizeof(bing);i++) {
			if (i<sizeof(bing)-2) buf+=CAP(bing[i])+", ";
			else if(i<sizeof(bing)-1) buf+=CAP(bing[i])+" y ";
			else buf+=CAP(bing[i]);
			}
		if(sizeof(bing)) retval+="  Es %^BOLD%^Regente%^RESET%^ de "+buf+".\n\n";
		}

	if (start_time) retval += "   Se conecto la primera vez el "+ctime(start_time)+".\n";
    	if ((ob=find_living(name)) && (function_exists("is_player",ob)) && (!ob->query_creator() || !ob->query_invis())) retval += "   Conectado desde "+ctime(last_log_on)+"\n";
    	else retval+="   Se conecto por ultima vez el "+ctime(last_log_on)+".\n";
	time_on = -time_on;
	retval += "   Tiene ";
	if (time_on>2592000) retval += sprintf("%d meses, ",time_on/2592000);
    	if (time_on > 86400) retval += sprintf("%d dias, ", (time_on/86400)%30);
    	if (time_on > 3600) retval += sprintf("%d horas, ", (time_on/3600)%24);
    	retval += sprintf("%d minutos y %d segundos de antiguedad.\n\n", (time_on/60)%60, time_on%60);


    	if (ob && (!ob->query_creator() || !ob->query_invis())) if (interactive(ob)) {
		if (query_idle(ob)) {
	    		retval += "%^BOLD%^ - Inactivo: %^RESET%^";
			retval += (query_idle(ob)/60) ? (query_idle(ob)/60) + " minutos y "+(query_idle(ob)%60)+" segundos.\n" : (query_idle(ob)%60)+" segundos.\n";
			}
		}

    	if ("/secure/master"->query_lord(this_player(1)->query_name()) && last_on_from) retval += "%^BOLD%^ - Ultima IP: %^RESET%^"+last_on_from+"\n";
    	if ("/secure/master"->query_lord(this_player(1)->query_name()) && last_pos) retval += "%^BOLD%^ - Ultima posicion: %^RESET%^"+last_pos+"\n";

    	mail_stat = (mapping)"/obj/handlers/postal_d"->mail_status(name);
	retval+="%^BOLD%^ - Mudmail: %^RESET%^";
    	if (!mail_stat["total"]) retval += "Sin cartas.\n";
    	else {
		retval += ""+mail_stat["total"]+" cartas";
		if (mail_stat["unread"]) retval += ", "+mail_stat["unread"]+" no leidas.\n";
		else retval += ".\n";
    		}

    	if (!mappingp(aliases)) aliases = ([ ]);
    	if (aliases[".proyecto"])retval+="%^BOLD%^ - Proyecto:%^RESET%^\n"+implode(explode(make_string(aliases[".proyecto"]),";"), "\n")+"%^RESET%^\n";
	else retval+="%^BOLD%^ - Sin proyecto%^RESET%^\n";
    	if (aliases[".plan"]) retval += "%^BOLD%^ - Plan:%^RESET%^\n"+implode(explode(make_string(aliases[".plan"]),";"), "\n")+"\n";
	else retval+="%^BOLD%^ - Sin plan%^RESET%^\n";
	retval+="\n";
	buf="{%^BLUE%^BOLD%^ NineTears %^RESET%^CYAN%^}=";
	for(i=16+(strlen(name)%2&&TP->query_cols()%2?2:0);i<TP->query_cols();i+=2) buf="="+buf+"=";
	retval+="%^RESET%^%^CYAN%^O"+buf+"O\n%^RESET%^";
	return retval;
	}
