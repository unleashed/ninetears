private mixed *rest;

/* If anyone can tell me what this does...
 * I would be most apprecative, Pinkfish... Yes yes ok i did write it.
 */
/* muhahaha filtering out parse stuff...Raskolnikov Nov 96 */
// If you're going to fix this, might as get rid of the
// "him", "her", and "it" shit too - Radix
/* Flode - 240897
 * Made find_match varargs with an optional no_hidden -flag
 * If the flag is set, hidden players, hidden npc's and basically
 * any object returning 1 on query_hidden are filtered out.
 */

string *parse_blocks = ({
  "thing",
  "things",
});

private int not_hidden(object ob) { return ob && !ob->query_hide_shadow(); }

varargs mixed find_match(string str, mixed ob, int no_hidden) {
    mixed *arra, test, *ret;
    int i, num, top, bot, bing, j;
    string nick, *bits;
    mapping rabbit;

    if (!ob || intp(ob))
	return ({ });
    if (str == "" || !str)
	return ({ });
    if (stringp(ob)) {
	ob -> dummy();
	ob = find_object(ob);
    }
    if (!pointerp(ob)) {
	ob = (mixed)ob->find_inv_match(str);
	if (!ob)
	    return ({ });
    } else {
	arra = ({ });
	for (i=0;i<sizeof(ob);i++)
	    if ((test = (object *)ob[i]->find_inv_match(str)))
		arra += test;
	ob = arra;
    }
    if(no_hidden)
      ob = filter(ob, "not_hidden", this_object());
    bits = explode(implode(explode(str, " and "), ","), ",");
    ret = ({ });
    for (j=0;j<sizeof(bits);j++) {
	str = bits[j];
	nick = (string)this_object()->expand_nickname(str);
	if (!nick && this_player())
	    nick = (string)this_player()->expand_nickname(str);
	if (nick && nick!="")
	    str = nick;
	if (str == "it" || str == "them" || str == "him" || str == "her") {
	    rest = all_inventory(this_player()) +
	    all_inventory(environment(this_player()));
	    arra = (object *)this_player()->query_it_them();
	    while (i<sizeof(arra))
		if (member_array(arra[i], rest) == -1)
		    arra = delete(arra, i, 1);
		else
		    i++;
	    if (!sizeof(arra))
		continue;
	    if (str == "it") {
		ret += arra[0..0];
		continue;
	    }
	    if (str == "her")
		if (living(arra[0]) && (int)arra[0]->query_gender() == 2) {
		    ret += arra[0..0];
		    continue;
		} else
		    continue;
	    if (str == "him")
		if (living(arra[0]) && (int)arra[0]->query_gender() == 1) {
		    ret += arra[0..0];
		    continue;
		} else
		    continue;
	    ret += arra;
	    continue;
	}
	test = explode(str, " ");
	// Flode added the next line, 120997
	if(!sizeof(test)) test = ({ "" });
	sscanf(test[sizeof(test)-1], "%d", bing);
	test = ({ });
	rest = ({ });
	if (sscanf(str, "%d/%d of %s", top, bot, str) != 3)
	    top = bot = 1;
	if (top <= 0)
	    top = 1;
	if (bot < top)
	    bot = top;
	/* block parse stuff */
	if(member_array(str, parse_blocks) == -1) {
	    parse_command(str,ob,"%i",test);
	    if (!test || !sizeof(test))
		continue;
	    if (bot != top) {
		num = test[0];
		rabbit = ([ ]);
		for (i=1;i<sizeof(test);i++)
		    rabbit[test[i]] = 1;
		arra = query_strange_inventory(keys(rabbit));
		test = ({ });
		for (i=0;i<sizeof(arra);i+=2)
		    test += map_array(arra[i+1],
		      "query_frac_simul_efun_id",
		      this_object(), ({ num, str, 0, sizeof(arra[i+1]),
			top, bot }) );
		arra = test + rest;
		ret += arra;
		continue;
	    }
	    if (test[0] == 1 && bing)
		test[0] = -bing;
	    rabbit = ([ ]);
	    for (i=1;i<sizeof(test);i++)
		rabbit[test[i]] = 1;
	    arra = map_array(keys(rabbit), "query_simul_efun_id",
	      this_object(), ({ test[0], str }));
	    arra += rest;
	    ret += arra;
	}
    }
    if (this_player() && sizeof(ret))
    {
	return this_player()->set_it_them( ret - ({ 0 }) );
    }
    return ret - ({ 0 });
} /* find_match() */

object query_simul_efun_id(object ob, mixed *arr) { 
    mixed ret;
    ret = (mixed)ob->query_parse_id(arr);
    if (!pointerp(ret))
	return ret;
    rest += ret[1..sizeof(ret)];
    return ret[0];
} /* query_simul_efun_id() */

object query_frac_simul_efun_id(object ob, mixed *arr) {
    mixed ret;
    ret = (mixed)ob->query_frac_parse_id(arr);
    if (!pointerp(ret))
	return ret;
    rest += ret[1..sizeof(ret)];
    return ret[0];
} /* query_frac_efun_id() */

int fixup_parse_command(mixed ob) {
    return objectp(ob);
} /* fixup_parse_command() */
