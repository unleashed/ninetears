// Nueva apariencia, retoque, traducci�n y correcci�n ortogr�fica XD .oO JaDe'03 Oo.

#include <runtime_config.h>
#include <standard.h>
#include <cmd.h>
#include <tiempo.h>
inherit CMD_BASE;

nosave string *races =
({ "drow","duergar","enano","elfo","gnomo","goblin","medio-elfo",
  "ilythiiri","duck","gigante","kender","troll","rana","varniad",
  "medio-orco","halfling","humano","hombre-lagarto","orco" });

void setup()
{
    position = 0;
}

string query_usage()
{
    return "command";
}

// Ordenaci�n y funciones de raza - Radix 1996
int compare_obs(object ob1, object ob2)
{
    string s1 = ob1->query_name();
    string s2 = ob2->query_name();
    if(s1 == s2) return 0;
    if(s1 > s2) return 1;
    return -1;
}
int query_valid_race(string race)
{
    return member_array(race,races) != -1;
}
int compare_race(object ob, string str)
{
    return ob->query_race() == str;
}

string who_string(int width, int cre, string str, object me)
{
    object *arr;
    object gob;
    int i, c, p,co;
    int number, creators, what;
    int f = 0, casa = 0, clan = 0;  // f = formated?
    string s,  nam, imm,play,prt;
   mixed tmp;
    string ttl = "{" + ({"%^BOLD%^", "%^BOLD%^%^CYAN%^", "%^BOLD%^%^MAGENTA%^", "%^YELLOW%^", "%^MAGENTA%^"})[random(5)] + " "+
		mud_name() + " %^RESET%^%^CYAN%^}";

    // Radix...
    if(me) co=me->query_cols();
    else co=79;
    if(co%2) co--;
    if(str && str[0] == '-')
    {
	if(str[1] == 'c')
	{
		if (str[1..4] == "clan") {
			clan++;
			str = str[6..23];
		}
		else if (str[1..4] == "casa") {
			str = str[6..23];
			casa = 1;
		}
		else {
	    		str = str[3..20];
  	    		f++;
		}
    		if(str == "")
			str = 0;
	}
    }
  arr = users();
    if(str && query_valid_race(str))
    {
	arr = filter_array(arr,"compare_race",this_object(),str);
	str = "mortales";
    }
    if(str && str == "inmortales"[0..sizeof(str)-1])
	arr = users();
    else
	arr = sort_array(arr,"compare_obs",this_object());
    s = "";
    c = p = 0;
    imm = play = "";
    prt = "\n";
   
    i=longitud(ttl)+4;
    if(i%2) {
	i++;
	ttl+="=";
	}
    for(;i<co;i+=2) ttl="="+ttl+"=";
    ttl="%^RESET%^%^CYAN%^O"+ttl+"O%^RESET%^\n";
    prt += ttl;
    prt +=  sprintf("%|*s", width, CICLO_HANDLER->query_fecha()+"\n", width);
    for(i=0;i<sizeof(arr);i++)
    {
	if(arr[i]->query_short() == "logon") 
	    continue;
	if(arr[i]->query_creator())
	{
	    if(!(tmp = arr[i]->query_short()))
		continue;
	    if(arr[i]->query_invis() > 1) 
		if(!this_player()->query_lord()) 
		    continue;
	    if(cre && arr[i]->query_invis() == 1)
		tmp = "*"+arr[i]->query_short()+"*";
	    if(cre && arr[i]->query_invis() == 2)
		tmp = "**"+arr[i]->query_short()+"**";
	    if(!cre && arr[i]->query_invis() == 1) 
		continue;
	    c = 1;
	    s = "";
	    nam = tmp;
	    if(f != 1)
	    {
		if(arr[i]->query_apellido()&&arr[i]->query_apellido()!="") s+=arr[i]->query_apellido()+" ";
		if(cre && (tmp = arr[i]->query_in_editor()))
		{
     			if(stringp(tmp))
		    		s += "(Editando: "+(string)tmp+") ";
		}
		if(tmp = arr[i]->query_gtitle())
		    s += tmp;
		if(tmp = arr[i]->query_title())
		    s += ", "+tmp;
		if(tmp = arr[i]->query_extitle())
                    s += ", "+tmp;
		if(query_idle(arr[i]) > 120)
		    s += " %^RESET%^%^CYAN%^(Inactivo: "+(query_idle(arr[i])/60)+")";
		imm += sprintf("%s %s", nam, s)+"%^RESET%^\n";
	    }
	    else
	    {
		imm += sprintf("%s,", nam);
	    }
	    if(!arr[i]->query_invis() || cre)
	    {   
		creators++;
	    }
	}
	else 
	{
	    //if(!(tmp = arr[i]->query_short()))
	    if (!(tmp = arr[i]->query_cap_name()))
		continue;
	    p = 1;
	    // kreo k esto no suele ocurrir, cuando f==1? cuando -c?
	    if(f == 1 && tmp[0..8] == "Esp�ritu de ")
		tmp = "Esp�ritu "+tmp[9..25];
		if (arr[i]->query_dead())
			tmp = "Esp�ritu de " + arr[i]->QCN;
	    nam = tmp;
	    if(f != 1)
	    {
		s = "";
		if(arr[i]->query_apellido()&&arr[i]->query_apellido()!="") s+=" "+arr[i]->query_apellido();
		if(arr[i]->query_property("guest"))
		    s += " invitado de Driade";
		if(!(tmp=arr[i]->query_title())) {
			if (arr[i]->query_show_title() && (gob=arr[i]->query_guild_ob())) {
				if(arr[i]->query_female())
			    	s += " la ";
				else 
			    	s += " el ";
				s += gob->query_title(arr[i]);
				s += "%^RESET%^"; // por si acaso
			}
			else {
				if(arr[i]->query_female())
			    	s += " mujer ";
				else 
			    	s += " varon ";
				if(tmp = arr[i]->query_race_name())
			    	s += capitalize(tmp);
			}
		}
		else {
			if(arr[i]->query_female())
			    s += " la ";
			else 
			    s += " el ";
			s += tmp;
			s += "%^RESET%^";
		}
		if(tmp = (string)arr[i]->query_extitle())
                    s += ", "+tmp+"%^RESET%^";
	// aki van casas o clanes
		if ((casa || clan) && arr[i]->query_race() == "drow") {
			string micasa;

			micasa = arr[i]->query_race_group_name();
                        if (micasa != "Sin casa.") {
				string titulin = arr[i]->query_race_group_title();
				if (titulin)
                                        s+= ", " + titulin + " de la "+ micasa;
				else
                                        s+= ", miembro de la "+ micasa;
			}
		}
		else if (clan) {
			string miclan;

			miclan = arr[i]->query_group_name();
			if (miclan != "Sin clan.") {
				//if (arr[i]->query_group_title())
                                        //s+= ", " + arr[i]->query_group_title();
				s+= " del clan "+ miclan;
			}
		}
		if(query_idle(arr[i]) > 60)
		    s += " %^RESET%^%^MAGENTA%^(Inactivo: " + (query_idle(arr[i])/60) + ")";
		play += nam+s+"%^RESET%^\n";
	    }
	    else
	    {
		play += sprintf("%s,", nam);
	    }
	    if(!arr[i]->query_invis())
		number++;
	}
    }
    if(!str)
	what = 0;
    else 
#ifndef STRICT_MUD
    if(str == "inmortales"[0..sizeof(str)-1])
	what = 1;
    else 
    if(str == "mortales"[0..sizeof(str)-1])
	what = 2;
    else
	return "Uso: who [-c | -casa | -clan] [inmortales | mortales | <raza>]\n"
	"Ejemplo: who -c enano\n";
    if(what != 2)
    {
	if(!c && what == 1)
	    return "%^WHITE%^No hay inmortales en Driade en este momento.%^RESET%^\n";
	if(c)
	{
	    ttl="{%^RESET%^%^BOLD%^ Inmortales %^RESET%^%^CYAN%^}";
	    i=longitud(ttl)+4;
	    if(i%2) {
		i++;
		ttl+="=";
		}	
	    for(;i<co;i+=2) ttl="="+ttl+"=";
	    ttl="%^RESET%^%^CYAN%^O"+ttl+"O%^RESET%^\n";
            prt += ttl;
	    if(f == 1)
		prt += format_page(explode(imm, ","), 4);
	    else
		prt += imm;

	}
    }
#endif

    if(what != 1)
    {
	if(!p && what == 2)
	    return("No hay mortales en Driade en este momento.\n");
	if(p)
	{
	    ttl="{%^RESET%^%^BOLD%^ Mortales %^RESET%^%^CYAN%^}";
	    i=longitud(ttl)+4;
	    if(i%2) {
		i++;
		ttl+="=";
		}
	    for(;i<co;i+=2) ttl="="+ttl+"=";
             ttl="%^RESET%^%^CYAN%^O"+ttl+"O%^RESET%^\n";	
	    prt += ttl;
	    if(f == 1)
		prt += format_page(explode(play, ","), 4);
	    else
		prt += play;
	}
    }
#ifdef STRICT_MUD

    if(number == 1)
	tmp = "{%^RESET%^ Est�s solo en la inmensidad de Driade. %^CYAN%^}";

    else 
	tmp = "{%^RESET%^ Hay "+query_num(number, 100)+" mortal"+(number<2?"":"es")+
	" en " + mud_long_name() + " en estos momentos. %^CYAN%^}";

#else

    if(number + creators == 1)
	tmp = "{%^RESET%^ Est�s solo en la inmensidad de Driade. %^CYAN%^}";
    else 
    if(!creators)
	tmp = "{%^RESET%^ Hay "+query_num(number,100)+" mortal"+
	(number<2?"":"es")+" en " + mud_name() + " ahora mismo. %^CYAN%^}";
    else 
    if(!number)
	tmp = "{%^RESET%^ Hay "+query_num(creators, 100)+" inmortal"+
	(creators<2?"":"es")+" en " + mud_name() + " ahora mismo. %^CYAN%^}";
    else
	tmp = "{%^RESET%^ Hay "+query_num(creators, 100)+" inmortal"+
	(creators<2?"":"es")+" y "+query_num(number, 100)+ " mortal"+
	(number<2?"":"es")+" en " + mud_name() + " ahora mismo. %^CYAN%^}";
#endif
    i=longitud(tmp)+4;
    if(i%2) {
	i++;
	tmp+="=";
	}
    for(;i<co;i+=2) tmp="="+tmp+"=";
    tmp="%^RESET%^%^CYAN%^O"+tmp+"O%^RESET%^\n";
    prt += tmp;
       return prt;
} /* who_string() */

int cmd(string str, object me) {
	if (!me->query_creator()) {
		if (me->query_property("noguild") || me->query_property("no_guild")) {
			tell_object(me, "Deber�s esperar un poco.\n");
			return 1;
		}
	}
    me->do_efun_write(who_string((int)me->query_cols(),
	(int)me->query_creator(),str, me));
    me->set_trivial_action();
    return 1;
} /* do_who() */
