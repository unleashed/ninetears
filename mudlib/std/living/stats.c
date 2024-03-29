/* the stat data for the living objects... */

/* Added extra_defendbonus calculations.
 * this will add to the body_ac, right now it's the only
 * body modifier. It is based on DEX
 * Baldrick, arpil '94
 * Also addin attack_bonus.
 * Adding THAC0 here. Skills.c is too heavy already.
 * Adding kill_xp here for now..
 */

#define TABLE "/table/stats_table.c"

int intbon,
dexbon,
conbon,
strbon,
wisbon,
chabon;

int Dex,
Int,
Con,
Str,
Wis,
Cha,
inttmp,
dextmp,
contmp,
wistmp,
strtmp,
extrstrtmp,
chatmp;

int extreme_str, hp_bonus, kill_xp;

nosave int no_check,
tmp_ac_bon,
tmp_damage_bon,
tmp_tohit_bon;

int THAC0;
int damage_bonus, tohit_bonus, magical, body_ac_bon, set_body_ac;

int query_no_check() { return no_check;}
void set_no_check(int i) { no_check = i;}
void calc();

/* This is ugly..
 * But a test right now..
 * This does calculate the adjustments of max_gp & max_hp
 * Baldrick march '95 (last change)
 */
/* DIOS MIOOOO, ESTO NECESITA CAMBIARSE */
void recalc_stats(int i) {
    	object guild_ob;
    	int e, max_gain, foo;
    	calc();
    	if (no_check) return ;
    	guild_ob = (object)this_object()->query_clase_ob();
    	for (e=0;e<i;e++) {
		if(guild_ob) {

			max_gain = (int)guild_ob->query_hp_dice(TO);
			if (TO->query_cha() >= random(200)) max_gain++;
			foo = roll(1, max_gain);
	    		if (foo < 1) foo = 1;
	    		if (foo > max_gain) foo = max_gain;
			foo += guild_ob->query_hp_min(TO);
			// si el hp_bonus es negativo... ainz
			TO->set_max_hp(TO->query_max_hp() + foo + hp_bonus);

			// GPS
			max_gain = (int)guild_ob->query_gp_dice(TO);
			if (TO->query_cha() >= random(200)) max_gain++;
			foo = roll(1, max_gain);
	    		if (foo < 1) foo = 1;
	    		if (foo > max_gain) foo = max_gain;
			foo += guild_ob->query_gp_min(TO);
			TO->set_max_gp(TO->query_max_gp() + foo);

			// EPS
			max_gain = (int)guild_ob->query_ep_dice(TO);
			if (TO->query_cha() >= random(200)) max_gain++;
			foo = roll(1, max_gain);
	    		if (foo < 1) foo = 1;
	    		if (foo > max_gain) foo = max_gain;
			foo += guild_ob->query_ep_min(TO);
			TO->set_max_ep(TO->query_max_ep() + foo);

			// SPS
			max_gain = guild_ob->query_sp_dice(TO);
			if (TO->query_cha() >= random(200) ) max_gain++;
			foo=roll(1,max_gain);
			if (foo<1) foo=1;
			if (foo>max_gain) foo=max_gain;
			foo+=guild_ob->query_sp_min(TO);
			TO->set_max_sp(TO->query_max_sp() + foo);
			}
		else {
	    		this_object()->set_max_hp((int)this_object()->query_max_hp() + roll(1,8) + hp_bonus);
			this_object()->set_max_gp((int)this_object()->query_max_gp() + roll(1,4) );
			this_object()->set_max_ep((int)this_object()->query_max_ep() + roll(1,4) );
			this_object()->set_max_sp((int)this_object()->query_max_sp() + roll(1,5) );
			}
    		} /* for */
	}

void reset_carry_cap()
{
    int old_cap, cap, st;
    object ob, ob1;

    if (no_check) return ;
    old_cap = (int)this_object()->query_loc_weight();
    st = this_object()->query_str(); // fix encumb bug with extreme strength

    if (st < 8)
	cap = 500;
    else if (st > 28)
	cap = 3800+(st-28)*300;
    else
	cap = ({ 500, 550, 600, 650, 750, 850, 950, 1150, 1300, 1450, 1600,
	  1750,1900,2100,2300,2500,2700,2950,3200,3500,3800})[st-8];
    this_object()->set_max_weight(cap);
    if (cap >= old_cap)
	return ;
    ob = first_inventory(this_object());
    while (ob) {
	ob1 = next_inventory(ob);
   if(ob && ob->query_weight() && ! ob->query_property("cursed"))
	    if (!ob->move(environment())) {
		old_cap -= (int)ob->query_weight();
		tell_room(ETO,this_object()->query_cap_name()+" deja "+ob->short()+
		  " sucumbiendo bajo su peso.\n",({TO}));
		tell_object(TO,"Tu falta de fuerza hace que dejes "+ob->short()+".\n");
	    }
	if (cap >= old_cap)
	    return ;
	ob = ob1;
    }
}

void reset_bon_stats()
{
    strbon = 0;
    dexbon = 0;
    conbon = 0;
    intbon = 0;
    wisbon = 0;
    chabon = 0;
}
void reset_thac0()
{
    object gob;
    gob = this_object()->query_guild_ob();
    if(!gob) return;
    THAC0 = (200- (this_object()->query_level() * gob->query_thac0_step()) );
}

void reset_all() {
    /* make sure for reset_all's */
    no_check = 0;
    reset_thac0();
    //reset_hp();
    //reset_gp();
    /* I don't like this! Baldrick. */
    strtmp = 0;
	extrstrtmp = 0;
    dextmp = 0;
    contmp = 0;
    wistmp = 0;
    inttmp = 0;
    chatmp = 0;
    reset_carry_cap();
    calc();
}

int set_str(int i)
{
    Str = i;
    reset_carry_cap();
    calc();
    return 1;
}

int set_con(int i)
{
    Con = i;
    //reset_hp();
    calc();
    return 1;
}

int set_int(int i)
{
    Int = i;
    //reset_gp();
    calc();
    return 1;
}

int set_dex(int i)
{
    Dex = i;
    calc();
    return 1;
}

int set_wis(int i)
{
    Wis = i;
    //reset_gp();
    calc();
    return 1;
}

int set_cha(int i)
{
    Cha = i;
    calc();
    return 1;
}

int set_extreme_str(int i)
{
    extreme_str = i;
    calc();
    return 1;
}

int set_ac(int i) {
    set_body_ac = 100-i;
    return 1;
}

int query_str() { return Str+strtmp+strbon+extreme_str+extrstrtmp; }
int query_int() { return Int+inttmp+intbon; }
int query_dex() { return Dex+dextmp+dexbon; }
int query_wis() { return Wis+wistmp+wisbon; }
int query_con() { return Con+contmp+conbon; }
int query_cha() { return Cha+chatmp+chabon; }

int query_real_str() { return Str; }
int query_real_extreme_str() { return extreme_str; }
int query_real_int() { return Int; }
int query_real_dex() { return Dex; }
int query_real_wis() { return Wis; }
int query_real_con() { return Con; }
int query_real_cha() { return Cha; }

int query_tmp_str() { return strtmp; }
int query_tmp_extreme_str() { return extrstrtmp; }
int query_tmp_int() { return inttmp; }
int query_tmp_dex() { return dextmp; }
int query_tmp_wis() { return wistmp; }
int query_tmp_con() { return contmp; }
int query_tmp_cha() { return chatmp; }

int query_bonus_str() { return strbon; }
int query_bonus_int() { return intbon; }
int query_bonus_dex() { return dexbon; }
int query_bonus_wis() { return wisbon; }
int query_bonus_con() { return conbon; }
int query_bonus_cha() { return chabon; }

int query_extreme_str() { return extreme_str+extrstrtmp; }
int adjust_dex(int i)
{
    Dex += i;
    if (query_dex() < 1)
    {
	write("Sientes como tu poca destreza hace imposible que te muevas, "
	  "y mueres horriblemente.\n");
	this_object()->do_death(this_object());
	return 0;
    }
    calc();
    return Dex;
}

int adjust_con(int i)
{
    Con += i;
    if (query_con() < 1)
    {
	write("Sientes como tu mala salud se deteriora y mueres de forma natural.\n");
	this_object()->do_death(this_object());
	return 0;
    }

    calc();
    return Con;
}

int adjust_str(int i)
{
    Str += i;
    if (query_str() < 1)
    {
	write("No tienes fuerza para vivir y mueres horriblemente.\n");
	this_object()->do_death(this_object());
	return 0;
    }
    reset_carry_cap();
    calc();
    return Str;
}

int adjust_wis(int i)
{
    Wis += i;
    if (query_wis() < 1)
    {
	write("Eres demasiado poco sabio para vivir y mueres.\n");
	this_object()->do_death(this_object());
	return 0;
    }

    calc();
    return Wis;
}

int adjust_int(int i)
{
    Int += i;
    if (query_int() < 1)
    {
	write("Sientes que eres demasiado estupido para estar vivo.\n");
	this_object()->do_death(this_object());
    }
    calc();
    return Int;
}

int adjust_cha(int i)
{
    Cha += i;
    if (query_cha() < 1)
    {
	write("Notas que eres demasiado feo para siquiera estar vivo.\n");
	this_object()->do_death(this_object());
    }
    calc();
    return Cha;
}

int adjust_tmp_int(int i)
{
    inttmp += i;
    if (query_int() < 1)
    {
	write("Sientes que eres demasiado estupido para estar vivo.\n");
	this_object()->do_death(this_object());
    }
    //reset_gp();
    calc();
    return inttmp;
}

int adjust_tmp_dex(int i)
{
    dextmp += i;
    if (query_dex() < 1)
    {
	write("Sientes como tu poca destreza hace imposible que te muevas, "
	  "y mueres horriblemente.\n");
	this_object()->do_death(this_object());
	return 0;
    }
    calc();
    return dextmp;
}

int adjust_tmp_wis(int i)
{
    wistmp += i;
    if (query_wis() < 1)
    {
	write("Eres demasiado poco sabio para vivir y mueres.\n");
	this_object()->do_death(this_object());
    }
    calc();
    return wistmp;
}

int adjust_tmp_str(int i)
{
    strtmp += i;
    if (query_str() < 1)
    {
	write("No tienes fuerza para vivir y mueres horriblemente.\n");
	this_object()->do_death(this_object());
	return 0;
    }
    reset_carry_cap();
    calc();
    return strtmp;
}

int adjust_tmp_extreme_str(int i)
{
    extrstrtmp += i;
    if (query_str() < 1)
    {
	write("No tienes fuerza para vivir y mueres horriblemente.\n");
	this_object()->do_death(this_object());
	return 0;
    }
    reset_carry_cap();
    calc();
    return extrstrtmp;
}

int adjust_tmp_con(int i)
{
    contmp += i;
    if (query_con() < 1)
    {
	write("Sientes como tu mala salud se deteriora y mueres de forma natural.\n");
	this_object()->do_death(this_object());
	return 0;
    }
    calc();
    //reset_hp();
    return contmp;
}

int adjust_tmp_cha(int i)
{
    chatmp += i;
    if (query_cha() < 1)
    {
	write("Notas que eres demasiado feo para siquiera estar vivo.\n");
	this_object()->do_death(this_object());
    }
    calc();
    return chatmp;
}

int adjust_bonus_int(int i)
{
    intbon += i;
    if (query_int() < 1)
    {
	write("Sientes que eres demasiado estupido para estar vivo.\n");
	this_object()->do_death(this_object());
    }
    calc();
    return intbon;
}

int adjust_bonus_dex(int i)
{
    dexbon += i;
    if (query_dex() < 1)
    {
	write("Sientes como tu poca destreza hace imposible que te muevas, "
	  "y mueres horriblemente.\n");
	this_object()->do_death(this_object());
	return 0;
    }

    calc();
    return dexbon;
}

int adjust_bonus_wis(int i)
{
    wisbon += i;
    if (query_wis() < 1)
    {
	write("Eres demasiado poco sabio para vivir y mueres.\n");
	this_object()->do_death(this_object());
    }
    calc();
    return wisbon;
}

int adjust_bonus_str(int i)
{
    strbon += i;
    if (query_str() < 1)
    {
	write("No tienes fuerza para vivir y mueres horriblemente.\n");
	this_object()->do_death(this_object());
	return 0;
    }
    reset_carry_cap();
    calc();
    return strbon;
}

int adjust_bonus_con(int i)
{
    conbon += i;
    if (query_con() < 1)
    {
	write("Sientes como tu mala salud se deteriora y mueres de forma natural.\n");
	this_object()->do_death(this_object());
	return 0;
    }
    //reset_hp();
    calc();
    return conbon;
}

int adjust_bonus_cha(int i)
{
    chabon += i;
    if (query_cha() < 1)
    {
	write("Notas que eres demasiado feo para siquiera estar vivo.\n");
	this_object()->do_death(this_object());
    }
    calc();
    return chabon;
}

void update_tmps()
{
    if ( (extrstrtmp||strtmp||contmp||wistmp||inttmp||dextmp) !=0)
	write("Sientes como tus habilidades se vuelven un poco mas normales.\n");

    strtmp = strtmp/2;
    contmp = contmp/2;
    wistmp = wistmp/2;
    inttmp = inttmp/2;
    dextmp = dextmp/2;
    //reset_hp();
    //reset_gp();
    calc();
    reset_carry_cap();
}

/* Made it an efun */
/* Baldrick.
string stat_string(int i)
  {
  if (i<19)
    return i +"";
  if (i>28)
    return i-10+"";
  if (i==28)
    return "18/00";
  return "18/"+(i-18)+"0";
}
*/

/* Add of Sojans code to get the new combat system working */
/* This will be changed, only one source of bonuses please..
 * Espesially for AC.. */
/* No string bonus, use ints and query directly on the attack / defend bonus */

void set_magical(int mnm)
{
    magical=mnm;
} /* set magical */

int query_magical()
{
    return magical;
} /* query_magical */

int query_hp_bonus()
{
    return hp_bonus;
}

int adjust_tmp_ac_bon(int i)
{
    tmp_ac_bon += i;
    return tmp_ac_bon;
}

int adjust_tmp_damage_bon(int i)
{
    tmp_damage_bon += i;
    return tmp_damage_bon;
}

int adjust_tmp_tohit_bon(int i)
{
    tmp_tohit_bon += i;
    return tmp_tohit_bon;
}

int query_body_ac()
{
    return (int)(set_body_ac + body_ac_bon + tmp_ac_bon);
}

// Raskolnikov for shifters
int query_real_body_ac()
{
    return set_body_ac;
}

int query_damage_bonus()
{
    return damage_bonus + tmp_damage_bon;
} /* int query_dam.. */

int query_tohit_bonus()
{
    return tohit_bonus + tmp_tohit_bon;
} /* query_tohit_bonus */

void set_thac0(int i)
{
    THAC0 = i;
    return;
} /* void set_thac0 */

void adjust_thac0(int i)
{
    THAC0 += i;
    return;
}

int query_thac0()
{
    return THAC0;
}


/* Query_kill_XP... making this extremely simple for now..
 * Will be placed somewhere else later, just to have a constant XP value on
 * monsters and players..
 */

void set_kill_xp(int bing)
{
    kill_xp=bing;
    return;
}

int query_kill_xp()
{
    int xp;
    int lvl;

    if (kill_xp)
	return kill_xp;

    if (!lvl = this_object()->query_level())
	lvl =1;

    xp = lvl * 60;
    return xp;
}

void calc()
{
    object guild_ob;
    /* This will make sure the players die when they reach negative stats..
     * Baldrick, added dec '94
     * the charisma should be able to be negative, but right now it will
     * get rid of smoe bugabusers.
     */
    /* has to be smarter, or in another place
    if (query_con() < 1 || query_dex() < 1 || query_str() < 1 || query_int() < 1
	|| query_wis() < 1 || query_cha() < 1)
      {
      write("Sientes que tu vida es demasiado debil y te es drenada.\n");
      this_object()->do_death(this_object());
      }*/ /* if stats negative, then die..*/


    hp_bonus = TABLE->calc_hp_bonus(query_con());
    /* Won't give non-warriors more than 2 in con bonus.
     */
    /* Not installed yet, but it's ready.. Baldrick, dec '95 */
	// CREO YO Q SI RULA
    guild_ob = (object)this_object()->query_guild_ob();
    if (guild_ob && !guild_ob->query_extra_con_bonus() && hp_bonus > 2)
     hp_bonus = 2;

    damage_bonus = TABLE->calc_damage_bonus(query_str());
    body_ac_bon = TABLE->calc_body_ac(query_dex());
    tohit_bonus = TABLE->calc_tohit_bonus(query_str());
}

int query_tmp_tohit_bon()
{
    return tmp_tohit_bon;
}

int query_tmp_damage_bon()
{
    return tmp_damage_bon;
}

int query_tmp_ac_bon()
{
    return tmp_ac_bon;
}
