// Vilat 02.11.2002 - Indentando y metiendo cosas nuevas

#include "move_failures.h"
#define TIME_DIV 10
#define PASSED_OUT "passed out"

void handle_commands() {
	add_action("take", "coger");
    	add_action("take", "get");
    	add_action("give", "dar");
    	add_action("give", "poner");
    	add_action("drop_ob", "dejar");
	}

int give(string str, string verb, object *bing, string bing2, int blue) {
    	string person,
    	thing,
    	sh, con;

    	int i, j, tot, max;

    	object *obs,
    	*per,
    	*ret,
    	*fail;

    	if (!str && !verb) return notify_fail("Uso: "+query_verb()+" <objeto> <a/en/sobre> <objeto>\n");

    	if ((verb?verb:query_verb()) == "dar") con = " a ";
    	else con = " en ";

    	if (bing) {
		obs = bing;
		thing = bing2;
		j = blue;
    		}
	else {
		if (sscanf(str, "%s a %s", thing, person) != 2) if (sscanf(str, "%s en %s", thing, person) != 2) if (sscanf(str,"%s sobre %s", thing, person) != 2) return notify_fail("Uso: "+query_verb()+" <objeto> <a/en/sobre> <objeto>\n");

		obs = find_match(person, ({ this_object(), environment() }));
		for (i=0;i < sizeof(obs); i++) if (obs[i]->query_hide_shadow() || obs[i]->query_hidden()) {
			obs -= ({obs[i]});
			i--;
			}
		if (!sizeof(obs)) return notify_fail("No encuentras a "+person+" para "+query_verb()+" nada.\n");
		per = obs;
    		}

    	if (!per) per = ({ });
    	for (;j<sizeof(per);j++) {
		if (per[j] == this_object()) continue;
		obs = find_match(thing, this_object());
		obs -= ({ per[j] });
		if (!sizeof(obs)) {
	    		write("Nada que "+query_verb()+con+per[j]->short()+".\n");
	    		continue;
			}
		ret = ({ });
		fail = ({ });
		for (i=0;i<sizeof(obs);i++) {
	    		if(!obs[i]->query_property("cursed")) {
				if (obs[i]->query_in_use() && obs[i]->query_holdable() ) this_object()->unhold_ob(obs[i]);
				if ( obs[i]->query_in_use() && obs[i]->query_wearable() ) this_object()->unwear_ob(obs[i]);
				}
	    		if( obs[i]->query_in_use() || obs[i]->query_property("cursed") ) fail += ({ obs[i] });
	    		else if( ((int)obs[i]->move(per[j])) == MOVE_OK ) {	/* property static... pa ke? xD */
				if(!interactive(per[j]) && interactive(this_object())) obs[i]->add_static_property("pc_gave_npc",1);
				ret += ({ obs[i] });
				tot += (int)obs[i]->query_weight();
	    			}
	    		else fail += ({ obs[i] });
			}

		if (sizeof(ret)) {
	    		sh = query_multiple_short(ret);
	    		write("Das "+sh+con+(string)per[j]->short()+".\n");
			if(!this_object()->query_hide_shadow() && !this_object()->query_hidden()) say(capitalize((string)this_object()->short())+" da "+sh+con+(string)per[j]->short()+".\n", ({ per[j] }) );
	    		per[j]->event_say(this_object(), capitalize((string)this_object()->short())+" te da "+sh+con+"ti.\n", ({ }));
	    		max = (int)per[j]->query_max_weight();

	    		if(max > 0) {
				if(tot > max) tot = max;
				max = (tot * 100)/max;

				switch(max) {
					case 0..25:
		    			break;
					case 95..100:
		    			tell_room(environment(),per[j]->short()+" sucumbe ante el peso de la carga.\n", per[j] );
		    			tell_object(per[j],"Sucumbes ante el peso de la carga.\n");
		    			break;
					default:
		    			tell_room(environment(),per[j]->short()+ ({
						" se ve medianamente incomodado por la carga.\n",
						" hace un gran esfuerzo para soportar la carga.\n",
						" resuella ante el elevado peso de la carga.\n"
		      				})[(max/25)-1], ({ per[j] }) );
		    			tell_object(per[j], ({
						"Te ves algo incomodado por la carga.\n",
						"Haces un nimio esfuerzo para soportar la carga.\n",
						"Con un poco de esfuerzo consigues aguantar la carga.\n"
		      				})[(max/25)-1]);
						}
				this_object()->add_timed_property(PASSED_OUT,"Todavia estas manejando tus cosas.\n",(max/TIME_DIV < 2) ? 1:(max/(TIME_DIV*2)));
	    			}
			this_object()->adjust_time_left(-tot/TIME_DIV);
			if (this_object()->query_time_left() < 0) this_object()->set_interupt_command("get_put_interupt", this_object(),({ tot, ret, query_verb(), con, per, j, thing }));
			}
		if (sizeof(fail)) write("No has podido "+query_verb()+" "+query_multiple_short(fail)+con+per[j]->short()+".\n");
    		}
    	return 1;
	}

int drop_ob(string str) {
    	int i, num;
    	object *ob, *ret, *fail;
    	string sh;

    	if (!str) return notify_fail("Uso: "+query_verb()+" <objeto(s)>\n");

    	if(this_object()->query_property("loading")) return notify_fail("Tu equipo esta todavia en el limbo, es un poco dificil dejar ahora algo.\n");

    	ob = find_match(str, this_object());
    	if (!sizeof(ob)) return notify_fail("No encuentras "+str+" para dejar.\n");

    	ret = ({ });
    	fail = ({ });
    	for (i=0;i<sizeof(ob);i++) {
		if (!ob[i]->short()) continue;
		if(!ob[i]->query_property("cursed")) {
	    		if (ob[i]->query_in_use() && ob[i]->query_holdable() ) this_object()->unhold_ob(ob[i]);
	    		if ( ob[i]->query_in_use() && ob[i]->query_wearable() ) this_object()->unwear_ob(ob[i]);
			}
		if( !ob[i]->query_property("cursed") && !ob[i]->query_in_use() && ob[i]->move(environment()) == MOVE_OK) ret += ({ ob[i] });
		else fail += ({ ob[i] });
    		}

  	if (sizeof(ret)) {
		sh = query_multiple_short(ret);
		if (!this_object()->query_hidden()) say(capitalize((string)this_object()->short())+" deja "+sh+".\n");
		write("Dejas "+sh+" en el suelo.\n");
    		}
    	if (sizeof(fail)) write("No puedes dejar "+query_multiple_short(fail)+".\n");
    	num += sizeof(fail)+sizeof(ret);
    	if (!num) return notify_fail("No puedes dejar "+str+".\n");
    	return 1;
	}

// y si estoy escondido?
int take(string str, string verb, object *bing, string bing2, int blue) {
    object *dest, *obs, *fail, *ret_a;
    mixed *ret;
    string s2, sh;
    int i, num, j, cap, perc, we, tot, max;

    /* Added to get rid of one more auto_load bug..
     * Baldrick, nov '94
     */
    if (this_object()->query_loading() ||
      this_object()->query_property("loading"))
    {
	notify_fail("Debes esperar a que todo tu equipo haya sido transferido desde el limbo.\n");
	return 0;
    }
    if (!str && !verb) {
	notify_fail("Uso: "+query_verb()+" <objeto> [de <objeto>]\n");
	return 0;
    }
    cap = (int)this_object()->query_max_weight()+1;
    if (verb) {
	dest = bing;
	i = blue;
	str = bing2;
    } else {
	dest = ({ environment() });
	if (sscanf(str, "%s de %s", str, s2) == 2) {
	    /* since we only allow one lvl anyway... (*/
	    dest = find_match(s2, ({ environment(), this_object() }));
	    if (!sizeof(dest)) {
		notify_fail("No puedes encontrar "+s2+" aqui.\n");
		return 0;
	    }
	}
	i = 0;
    }
    for (;i<sizeof(dest);i++) {
	if (dest[i]->cannot_get_stuff())
	    continue;
	obs = find_match(str, dest[i]);
	ret = ({ ({ }), ({ }), ({ }), ({ }), ({ }), });
	ret_a = ({ });
	fail = ({ });
	tot = 0;
	for (j=0;j<sizeof(obs);j++)
	    if (obs[j]->move(this_object()) == MOVE_OK) {
		if ((perc = (we = (int)obs[j]->query_weight())*100/cap) >= 95)
		    ret[4] += ({ obs[j] });
		else
		    ret[perc/25] += ({ obs[j] });
		tot += we;
		ret_a += ({ obs[j] });
	    } else if (!living(obs[j]))
		fail += ({ obs[j] });
	for (j=0;j<sizeof(ret);j++)
	    if (sizeof(ret[j])) {
		sh = query_multiple_short(ret[j]);
		write(({ "Coges", "Coges con un poco de dificultad",
		    "Coges forzadamente",
		    "Coges con mucha dificultad",
		    "Usas toda tu fuerza para coger dificilmente" })[j]+
		  " "+sh+" de "+(string)dest[i]->short()+".\n");
		if (!this_object()->query_hidden())
		    say((string)this_object()->query_cap_name()+" "+
		      ({ "coge", "coge con un poco de dificultad",
			"coge forzadamente",
			"coge con mucha dificultad",
			"usa toda su fuerza para coger dificilmente"})[j]+
		      " "+sh+" de "+(string)dest[i]->short()+".\n");
		num += sizeof(ret[j]);
	    }
	if (tot) {
	    /*
			this_object()->adjust_time_left(-tot/TIME_DIV);
			if (this_object()->query_time_left() < 0) {
			    this_object()->set_interupt_command("get_put_interupt", this_object(),
			      ({ tot, ret_a, "get", "from", dest, i, str }));
			}
	    */
	    max = (int)this_object()->query_max_weight();
	    if(max && tot)
	    {
		if(tot > max) tot = max;
		tot = (tot * 100)/max;

this_object()->add_timed_property(PASSED_OUT,"Todavia estas manejando tu equipo.\n",(tot/TIME_DIV) < 2 ? 1 : tot/(TIME_DIV * 2));
	    }
	}
	if (sizeof(fail))
	    write("No puedes coger "+query_multiple_short(fail)+".\n");
	num += sizeof(fail);
    }
    if (!num) {
	notify_fail("Nada que "+query_verb()+".\n");
	return 0;
    }
    return 1;
}

void get_put_interupt(int left, mixed arg) {
    	int tot, j, i, weight;
    	object *obs, *per;
    	string sh, thing, sh2;

    	per = arg[4];
    	j = arg[5];
    	thing = arg[6];
    	obs = arg[1];
    	if (left > 0) {
		object dest;
		tot = arg[0] - left;
		if (arg[2] != "get") dest = this_object();
		else dest = per[j];

		for (i=0;i<sizeof(obs);i++) {
	    		weight = (int)obs[i]->query_weight();
	    		if (tot - weight < 0) {
				if (!i) sh = "none of the above";
				else sh = query_multiple_short(obs[0..i-1]);
				sh2 = query_multiple_short(obs);
				for (;i<sizeof(obs);i++) obs[i]->move(dest);
				write("Your interupted "+arg[2]+"ing "+sh2+" "+arg[3]+" "+per[j]->short()+", only "+arg[2]+"ing "+sh+".\n");
				say(this_object()->query_cap_name()+" is interupted "+arg[2]+"ing "+sh2+" "+arg[3]+" "+per[j]->short()+", only "+arg[2]+"ing "+sh+".\n");
				return ;
	    			}
	    		tot -= weight;
			}
		write("Hmmm...  here,,,?\n");
		return ;
    		}
    	if (j < sizeof(per)) {
		switch (arg[2]) {
			case "give" :
			case "put" :
	    		give(0, arg[2], per, thing, j+1);
	    		break;
			case "get" :
	    		take(0, arg[2], per, thing, j+1);
	    		break;
			}
    		}
	}
