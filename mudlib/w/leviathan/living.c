/* 
 * Modificado por Oskuro y Spp 5-1-98
 * Guldan & Paris. Ahora si estas con "passed out" (aturdido) la armadura 
 * total te baja en 5. Nov'98
 */
  
#include "living.h"
inherit "/std/living/alignment";
inherit "/std/living/curses";
inherit "/std/living/death"; /* no pun intended.. :=) */
inherit "/std/living/force";
//No se usa para NADA los skills, asi que lo quito (Dimmak)
//inherit "/std/living/skills";
inherit "/std/living/money";
inherit "/std/living/spells";
inherit "/std/living/equip";
inherit "/std/living/gender";
//inherit "/std/living/bando";
inherit "/std/living/stats";
inherit "/std/living/carrying";
inherit "/std/living/health";
inherit "/std/container";

string msgout,
msgin,
mmsgout,
mmsgin;
int verbose, level;
status dead;
//Esto ya no se usa (dimmak & spp 99)
//static mixed *it_them;
static object *followers;
static object *following;
static mixed remember_follow;
mixed attack_data,
attack_name;

// Protoypes.. 
int query_total_ac();

void create() 
{
    equip::create();
    curses::create();
    spells::create();
 
   // No se usan los skills.  
   //skills::create();
    health::create();
    enable_commands();
    attack_name = ({ });
    attack_data = ({ });
    followers = ({ });
    following = ({ });
    max_hp = 1;
    max_gp = 1;
    container::create();
    //it_them = ({ this_object() });
    dead = 0;
} /* create() */

void living_commands() 
{
    add_action("do_equip", "equip");
    add_action("do_equip", "eq*uipar");
    add_action("do_hold", "wi*eld");
    add_action("do_hold", "bla*ndir");
    add_action("do_hold", "ho*ld");
    add_action("do_unhold", "unwi*eld");
    add_action("do_unhold", "enva*inar");
    add_action("do_unhold", "unho*ld");
    add_action("do_wear", "wea*r");
    add_action("do_wear", "pon*erse");
    add_action("do_unwear", "unwea*r");
    add_action("do_unwear", "qui*tarse");
    add_action("do_equip", "eq*uip");
    add_action("follow", "fo*llow");
    add_action("lose", "lo*se");
    add_action("unfollow", "unf*ollow");
    add_action("do_unhold", "env*ainar");
    add_action("do_hold", "emp*unyar");
    add_action("follow", "seg*uir");
    add_action("lose", "perder");
    add_action("lose", "pierde");
    add_action("unfollow", "noseg*uir");
    add_action("follow_dummy", "FOLLOW_DUMMY");
    combat_commands();
    //skill_commands();
} /* living_commands() */

/* Basic stuff, does this thing live or not?
 * Timion added something like this some time ago and I thought it wasn't 
 * nessesary, but it may be?
 */
/* Maybe this should be in health.c or stats.c?
 * Baldrick, aug '95 
 */

void set_dead(status bing)
{
    dead = bing;
    return; 
}

int query_dead()
{
    return dead;
}

/* For compatibility: */

int query_alive()
{
    return !dead;
}

/* move stuff
 */
int test_add(object ob, int flag) { return !flag; }
int test_remove(object ob, int flag) { return !flag; }

static int in_move;

int query_in_move() { return in_move; }

/* thats it... 
 * no need for stupid checking to see if we are attacking something in
 * here stuff.
 */
varargs mixed move_player(string dir, string dest, mixed message,
  object followee, mixed enter) {
    int i, ret, no_see;
    string arr, leave, ppl, my_short;
    object last, *ok_follow, new_env;

    if (!msgout) {
      msgout = "@$N se va hacia el $T.";
         msgin = "@$N llega desde $F.";
    }
    if (!mmsgout) {
	mmsgout = "@$N desaparece en una nube de humo.";
	mmsgin = "@$N aparece del suelo.";
    }
    last = environment();
    if(!this_object()->query_invis()) {
	my_short = (string)this_object()->short();
	if(my_short) my_short = capitalize(my_short);
    }

    if(!my_short || my_short == "" || (stringp(message) && message == "none")) {
	no_see = 1;
    } else if(!dir || dir == "X") { /* we are teleporting */
	leave = implode(explode(mmsgout, "$N"), my_short) + "\n";
	arr = implode(explode(mmsgin, "$N"), my_short) + "\n";
    } else if(!sizeof(followers) && !followee) {
	if (!enter || !pointerp(enter))
	    enter = ({ 0, "alguna parte" });
	if (pointerp(message))
	    message = message[0];
	leave = implode(explode(implode(explode((message?message:msgout), "$N"), 
	      my_short), "$T"), dir)+"\n";
	switch (enter[0]) {
	case 0 :
	    arr = implode(explode(implode(explode(msgin, "$N"), my_short), "$F"),
	      enter[1])+"\n";
	    break;
	case 1 :
	    arr = implode(explode(enter[1], "$N"), my_short)+"\n";
	    break;
	}
    }
    if(arr) ret = move(dest, arr[1..1000], leave[1..1000]);
    else ret = move(dest);

    if(ret) return 0;

    new_env = environment();
    if (interactive(this_object()) && !query_property(UNKNOWN_MOVE_PROP)) {
	if (verbose) {
	    this_object()->ignore_from_history("look");
	    command("look");
	} else {
	    this_object()->ignore_from_history("glance");
	    command("glance");
	}
    }
    if(!dir || dir == "X" || (!sizeof(followers) && !followee)) return 1;
    else if(no_see) return ({});

    in_move = 1;
    ok_follow = ({ this_object() });
    for (i=0;i<sizeof(followers);i++) {
	object *tmp;
	if (followers[i] && (!TO->query_hidden())) {
	    if(environment(followers[i])==last && !followers[i]->query_in_move()) {
		tmp = (object *)followers[i]->do_follow_command(dir);
		followers[i]->reset_remember_follow();
		if(tmp && sizeof(tmp)) {
		    tell_object(followers[i], "Sigues a " + my_short + " hacia el "+dir+".\n");
		    // Spp lo cambia para ver que funcione bien el follow
		    //ok_follow += tmp;
		    ok_follow += ({ followers[i] }) ;
		} else {
		    tell_object(followers[i], "No has podido seguir a " +
		      my_short + " hacia el" +dir+ ".\n");
		}
	    }
	} else {
	    write("Uno de los que te seguian se ha ido o ha muerto horriblemente.\n");
	    followers = delete(followers, i, 1);
	    i--;
	}
    }
    in_move = 0;
    if (followee)
	return ok_follow;
    /*
     * Yes we have to do some silly things for multiple exit and enter
     * messages lest they make no sense.
     */
    ppl = capitalize(query_multiple_short(ok_follow));
    if (pointerp(message))
	message = message[1];
    else
	message = "@$N se va hacia el $T.";
    leave = implode(explode(implode(explode(message, "$N"), 
	  ppl), "$T"), dir) + "\n";
    if (!enter || !pointerp(enter))
	enter = ({ 0, "alguna parte" });
    switch (enter[0]) {
    case 0 :
	arr = "@" + ppl + " llegan desde " + enter[1] + ".\n";
	break;
    case 1 :
	arr = implode(explode(enter[2], "$N"), ppl);
	break;
    }
    event(last, "exit", extract(leave, 1), new_env, ok_follow);
// pos no me que me da a mi que se pasa por el forro los ignore...
// Spp Ene'99
    event(new_env, "enter", extract(arr, 1), last, ok_follow);
    
    if(sizeof(ok_follow) > 1)
	tell_object(this_object(), capitalize(query_multiple_short(ok_follow-
	      ({ this_object() })))+" te sigue" + /* anyade 'n' si te sigue muchos */
	  (sizeof(ok_follow) == 2?"":"n")+".\n");
    return ok_follow;
} /* move_player() */

object *do_follow_command(string dir)
{
    remember_follow = ({ previous_object(), dir });
    this_object()->ignore_from_history("FOLLOW_DUMMY");
    command("FOLLOW_DUMMY");
    return remember_follow;
}

void reset_remember_follow()
{
    remember_follow = 0;
}

int follow_dummy()
{
  // Wonderflug, passed out stops following
  if ( this_object()->query_property("passed out") )
  {
    tell_object(this_object(), "No estas en condiciones de seguir a "
        "nadie.\n");
    return 0;
  }
    // Taniwha, stop it barfing
    if((sizeof(remember_follow) > 1) && remember_follow[0] && remember_follow[1])
	remember_follow = (object *)environment()->do_exit_command(0,
	  remember_follow[1], this_object(), remember_follow[0]);
    if(remember_follow && sizeof(remember_follow)) return 1;
    else return 0;
}

int cannot_get_stuff() { return 1; }

mixed *stats() {
    if (previous_object() != TO && !previous_object()->query_lord() && TO->query_player())
    {
		tell_object(previous_object(),"Espiar jugadores no es tu trabajo.\n");
		return 0;
	}
	
	return container::stats() + ({
    ({ "MAX_HP", max_hp }),
    ({ "HP",  hp }),
    ({ "MAX_GP", max_gp }),
    ({ "GP", gp }),
    ({ "AC Corporal (bonus des) mod.", query_body_ac() }),
    ({ "Modificador Equipo AC.", query_equip_ac() }),
    ({ "AC Total", query_total_ac() }),
    ({ "Bonus de Danyo", query_damage_bonus() }),
    ({ "Bonus a Golpear", query_tohit_bonus() }),
    ({ "Thac0", query_thac0() }),
    ({ "Fue", query_str() }),
    ({ "Int", query_int() }),
    ({ "Des", query_dex() }),
    ({ "Con", query_con() }),
    ({ "Sab", query_wis() }),
    ({ "Car", query_cha() }),
    ({ "Fue tmp", query_tmp_str() }),
    ({ "Des tmp", query_tmp_dex() }),
    ({ "Con tmp", query_tmp_con() }),
    ({ "Int tmp", query_tmp_int() }),
    ({ "Int tmp", query_tmp_wis() }),
    ({ "Cha tmp", query_tmp_cha() }),
    ({ "Fue bonus", query_bonus_str() }),
    ({ "Int bonus", query_bonus_int() }),
    ({ "Des bonus", query_bonus_dex() }),
    ({ "Con bonus", query_bonus_con() }),
    ({ "Sab bonus", query_bonus_wis() }),
    ({ "Car bonus", query_bonus_cha() }),
    ({ "Sexo", query_gender_string() }),
    ({ "Dinero total", query_value() }),
    ({ "Exp", query_xp() }),
    ({ "Exp Total", query_total_xp() }),
    ({ "Alineamiento", query_align_name() }),
    ({ "Playerset Alignment", query_playerset_alname() }),
  }) ; /* change to + equip::stats(); */
}

void dest_me() {
    object *ob;
    int i;

    ob = deep_inventory(this_object());
    for (i=0;i<sizeof(ob);i++)
	if(ob[i])
	    ob[i]->dest_me();
    container::dest_me();
}


// REALLY bogus .. used for "look it" and remembering what "it"
// is (the last thing you've looked at.  Needed environment()
// checks, so Radix was here, Jan 7, 1996
// This is deeply rooted in /secure/simul_efun/find_match.c as well


/*      Ya no se usa Dimmak & Spp 99

mixed *query_it_them()
{
   int i;
   if(!this_object()) return it_them;
   for(i=0; i<sizeof(it_them); i++)
      if(environment(this_object()) != environment(it_them[i]))
         it_them = delete(it_them,i,1);
   return it_them;
}

//Tampoco se usa

mixed *set_it_them(mixed *i) { return (it_them = i); }

*/

int add_follower(object ob) {
    if (ob == this_object())
	return 0;
    if (member_array(ob, attacker_list) != -1)
	return 0;
    if (member_array(ob, followers) == -1)
	followers += ({ ob });
    return 1;
}

int remove_follower(object ob) {
    int i;

    if ((i=member_array(ob, followers)) != -1) {
	followers = delete(followers, i, 1);
	return 1;
    }
    return 0;
}

int add_following(object ob) {
    if (ob == this_object())
	return 0;
    if (member_array(ob, following) == -1)
	following += ({ ob });
    return 1;
}

int remove_following(object ob) {
    int i;

    if ((i=member_array(ob, following)) != -1) 
    {
	following = delete(following, i, 1);
	return 1;
    }
    return 0;
}


// Recodificada por Spp y Oskuro Ene'98
int follow(string str) 
{
  mixed obs;
  object ob;

  if (!str) 
  {
    notify_fail("Sintaxis: seguir <persona>\n");
    return 0;
  }
  if ( this_object()->query_property("just followed and failed") )
  {
    notify_fail("Estas demasiado cansado para intentar seguir a alguien, "
    "prueba mas tarde.\n");
    return 0;
  }
  obs = find_match(str, environment()); //Buscamos al susodicho
  if (!sizeof(obs)) 
  {
    notify_fail("No puedo encontrar a "+str+".\n");
    return 0;
  }
  // Fixing up by Wonderflug, nov '95
  ob = obs[0];
  //Por Dimmak. No se puede seguir a quien esta escondido
  if (ob->query_hide_shadow())
     {
       notify_fail("No puedo encontrar a "+str+".\n");
       return 0;
     }
  if ( !ob->query_consent("seguir") &&
    random((int)ob->query_dex()) < random((int)this_object()->query_dex()) )
  {
    tell_object(ob, this_object()->query_cap_name()+" intenta seguirte, "
	  "pero le das esquinazo.\n");
    this_object()->add_timed_property("just followed and failed", 1, 10);
    notify_fail("Intentas seguir a "+ob->query_cap_name()+", pero "
                "te da esquinazo.\n");
	return 0;
  }
  if ( !ob->add_follower(this_object()) )
  {
    notify_fail("Solo puedes seguir a seres vivos.\n");
    return 1;
  }
  
  add_following(ob);
  
  write("Sigues a "+ob->query_cap_name()+".\n");
  tell_room(environment(this_object()), this_object()->query_cap_name()+
      " sigue a "+ob->query_cap_name()+".\n", ({ ob, this_object() }) );
  tell_object(ob, this_object()->query_cap_name()+" te sigue.\n");
    return 1;
}

int unfollow(string str) 
{
    int i;
    object *ok, *obs;
    string s;

    if (!str) {
	notify_fail("Sintaxis: noseguir <persona>\n");
	return 0;
    }
    obs = find_match(str, environment(),1);
    
    for (i=0;i<sizeof(following);i++)
    	if (following[i])
    		obs += find_match(str, ENV(following[i]),1);
    	else
    		remove_following(following[i]);
    
    if (!sizeof(obs)) {
	notify_fail("No puedo encontrar a "+str+".\n");
	return 0;
    }
    ok = ({ });
    for (i=0;i<sizeof(obs);i++)
    {
      if(obs[i]==TO) continue;    

      if (obs[i]->remove_follower(this_object()))
      {
	   remove_following(obs[i]);
	   ok += obs[i..i];
      }
    }
    if(!sizeof(obs))
    {
      notify_fail("No puedo encontrar a "+str+".\n");
      return 0;
    }
    if (!sizeof(ok)) {
	notify_fail("No estas siguiendo a "+str+".\n");
	return 0;
    }
    write("Paras de seguir a "+(s=query_multiple_short(ok))+".\n");
    tell_room(environment(this_object()),this_object()->query_cap_name()+
    " para de seguir a "+s+".\n",({this_object(),obs}));
    tell_object(obs,this_object()->query_cap_name()+" para de seguirte.\n");
    return 1;
}

int lose(string str) {
    int i;
    object *ok, *obs;
    string s;

    if (!str) {
	notify_fail("Sintaxis: perder <persona>\n");
	return 0;
    }
    if (str == "everyone" || str == "todos" || str == "todas" || str == "all")
	obs = followers;
    else
    {
	obs = find_match(str, environment());
	for (i=0;i<sizeof(followers);i++)
    		obs += find_match(str, ENV(followers[i]),1);
    }
    if (!sizeof(obs)) {
	notify_fail("No puedo encontrar a "+str+" para darle esquinazo.\n");
	return 0;
    }
    ok = ({ });
    
    for (i=0;i<sizeof(obs);i++)
      if(obs[i])
	  if(remove_follower(obs[i]))
	  {
	    obs[i]->remove_following(TO);
	    ok += obs[i..i];
	  }
/* Rectificado por Dimmak. Corrigiendo el bug de buscar sin gastar gps
 *

    if(!sizeof(obs))
    {
      notify_fail("No puedo encontrar a "+str+" para darle esquinazo.\n");
      return 0;
    }
    if (!sizeof(ok)) 
    {
      notify_fail("Aun eres seguido por "+query_multiple_short(obs)+".\n");
      return 0;
    }  */

    if(!sizeof(obs) || !sizeof(ok))
    {
      notify_fail("No puedo encontrar a "+str+" para darle esquinazo.\n");
      return 0;
    }


    write("Das esquinazo a "+(s=query_multiple_short(ok))+".\n");
    tell_room(environment(this_object()),this_object()->query_cap_name()+
    " da esquinazo a "+s+".\n",({this_object(),s}));
    tell_object(s,this_object()->query_cap_name()+" te da esquinazo.\n");
    ok += ({ "ti" });
    for (i=0;i<sizeof(ok)-1;i++)
	tell_object(ok[i], this_object()->query_cap_name()+
	  " da esquinazo a "+query_multiple_short(ok - ({ ok[i] }))+".\n");
    return 1;
}

object query_current_room() { return environment(); }

mixed *query_followers() { return followers; }
mixed *query_following() { return following; }

varargs int adjust_money(mixed amt, string type) {
    return money::adjust_money(amt, type);
} /* adjust_money() */

mixed *query_money_array() { 
    return money::query_money_array();
} /* query_money_array() */

int query_money(string type) { 
    return money::query_money(type);
} /* query_money() */

int query_value() { return money::query_value(); }
query_teleport() {
    if (!msgin) {
	return 0;
    }
    if (!mmsgin) {
	return 1;
    }
}                     
/* AC 100 is the base, all AC is subtracted from this to get the AD&D AC */

// Without this_object()-> /obj/monster.c is ignored - fixed by Radix
int query_total_ac()
{
   int eac = this_object()->query_equip_ac();
   int bac = this_object()->query_body_ac();
   
   if (TO->query_property("passed out")) return 150-eac-bac;
   return 100-eac-bac;
}

// Dec'01 Sedd: posibilidad de escoger la mano con la que se empunya
int do_hold(string woo)
  {
  object *boo;
  int mano;
  int i;
  string *palabras = ({ });

  if (!woo)
    return notify_fail(query_verb() + "que?.\n");
  
  palabras = explode(woo, " ");
  mano = palabras[0]=="derecha"?0:palabras[0]=="izquierda"?1:-1;
  if (mano != -1)
  {
  	palabras -= ({ palabras[0] });
  	woo = implode(palabras, " ");
  }
  // AAArrrggghhhh find_match() doesn't work... -Aragorn
  // boo = find_match(woo, this_object());
  boo = all_inventory(this_object());
  for(i=0;i<sizeof(boo);i++)
    if (!boo[i]->id(woo)) boo[i] = 0;
  boo -= ({ 0 });

  if (!sizeof(boo))
    return notify_fail("No estas cargando " + woo + ".\n");

  // Somewhat nasty but does the trick... -Aragorn
  boo -= (mixed *)this_object()->query_held_ob();
 
  /* Somehow, this is not working.. */
  if (!sizeof(boo))
    return notify_fail("Ya estas empunyando esto!\n");

  if (!boo[0]->query_holdable())
    return notify_fail("No puedes " + query_verb() + " esto.\n");
  
  if (boo[0]->query_in_use())
    return notify_fail("Ya lo estabas utilizando.\n");

  return real_hold_ob(boo[0], mano);
}

int do_unhold(string woo)
  {
  object *boo;
  int i;

  if (!woo)
    return notify_fail("Dejar de sostener que?\n");

  // AAArrrggghhhh find_match() doesn't work... -Aragorn
  // boo = find_match(woo, this_object());
  boo = all_inventory(this_object());
  for(i=0;i<sizeof(boo);i++)
    if (!boo[i]->id(woo)) boo[i] = 0;
  boo -= ({ 0 });


  // As nasty as it gets but I'm just trying to get it to work 
  // right now. Speedups later.
  // -Aragorn
  boo -= (all_inventory(this_object())-(mixed*)this_object()->query_held_ob());

  if (!sizeof(boo))
    {
    notify_fail("Porque intentas envainar algo que no tienes?\n"); 
    return 0;
    }
  // At the moment you can only unhold one thing at the time. -Aragorn
  // unhold_ob (boo);
  return unhold_ob(boo[0]);
}

int do_wear(string woo)
  {
  object *boo;
  int i;
  int size;
  
  if (!woo)
    return notify_fail("Ponerse que?\n");

  // AAArrrggghhhh find_match() doesn't work... -Aragorn
  // boo = find_match(woo, this_object());
  boo = all_inventory(this_object());
  for(i=0;i<sizeof(boo);i++)
    if (!boo[i]->id(woo)) boo[i] = 0;
  boo -= ({ 0 });

  if (!sizeof(boo))
    return notify_fail("No estas cargando esto.\n");

  // Somewhat nasty but does the trick... -Aragorn
  /* what does this do ? Baldy.. 
   * It gives me an error message here, but not in hold.c */
  boo -= (mixed *)this_object()->query_worn_ob();

  if (sizeof(boo))
    {
    if (!boo[0]->query_wearable())
      return notify_fail("Este objeto no puede ser puesto!\n");

    if (boo[0]->query_in_use())
      return notify_fail("Ya esta puesto.\n");
  
    if (size = boo[0]->query_size() == 0)
      return notify_fail("No tiene el tamanyo definido.\n");

    size = size / 2;
    if (size < 1)
      size = 1;

    wear_ob(boo[0]);
    }
  return 1;
}

int do_unwear(string woo)
  {
  object *boo;
  int i;

  if (!woo)
    return notify_fail("Quitarse que?\n");

  // AAArrrggghhhh find_match() doesn't work... -Aragorn
  // boo = find_match(woo, this_object());
  boo = all_inventory(this_object());
  for(i=0;i<sizeof(boo);i++)
    if (!boo[i]->id(woo)) boo[i] = 0;
  boo -= ({ 0 });


  // As nasty as it gets but I'm just trying to get it to work 
  // right now. Speedups later.
  // -Aragorn
  boo -= (all_inventory(this_object())-(mixed*)this_object()->query_worn_ob());

  if (!sizeof(boo))
    {
    notify_fail("Porque quieres quitarte algo que no tienes?\n"); 
    return 0;
    }

  // At the moment you can only unwear one thing at the time. -Aragorn
   unwear_ob(boo[0]);
   return 1;
}

