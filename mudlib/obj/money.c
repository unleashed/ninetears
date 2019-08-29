/* Altered August 1995 - January 1996 by Hamlet
   Added weight and shortcut ways to say 'platinum coins'.
   Added the cute little 'look coin' thingy.
*/
inherit "/std/object";
#include "move_failures.h"
#include "money.h"
#define WEIGHTDIV 2

mixed *money_array;
nosave int dont_join;

int query_number_coins();

void create() {
  money_array = ({ });
  ::create();
  set_name("moneda");
  add_alias("Some Money For Me");
  add_plural("monedas");
  set_main_plural("monedas");
  add_plural("monedas");
  add_property("determinate", "");
  add_property("no one",1);
  add_property("money",1);
}

void init() {
  add_action("do_help", "help");
}

int do_help(string str) {
  mixed *values;
  int i;

  if (!str || str != "monedas")
    return 0;
  write("Valor de las monedas.\n");
  values = (mixed *)MONEY_HAND->query_values();
  str = "";
  for (i=0;i<sizeof(values);i+=2)
    str += sprintf("%10-s : %4d %s\n", values[i], values[i+1], values[0]);
  printf("%-*s\n", this_player()->query_cols(), str);
  return 1;
}

varargs int adjust_money(mixed amt, string type) {
  int i, val;

  if (pointerp(amt)) {
    for (i=0;i<sizeof(amt);i+=2)
      adjust_money(amt[i+1], amt[i]);
    return 1;
  }
  if (!stringp(type) || !intp(amt))
    return 0;
  /* Let's not allow unknown money types - Hamlet */
  if (member_array(type,(mixed *)MONEY_HAND->query_values()) == -1)
    return 0;

  if(environment(this_object()))
    if(interactive(environment(this_object()))) {
      val = (int)MONEY_HAND->query_value(type);
      catch(MONEY_TRACKER->update_statistics(val*amt,
            environment(this_object())));
    }
  if ((i=member_array(type, money_array)) == -1) {
    add_adjective(type);
    add_plural(type+"s");
    add_plural("m"+type[0..0]+"s");
	add_plural("monedas de "+type);
    add_alias(type);  /* 'dar 10 platino a Hamlet' */
    add_alias("m"+type[0..0]);  /* 'dar 10 mp a Hamlet' */
    if(type == "platino") {
      add_alias("plat");  /* 'dar 10 plat a Hamlet' */
      add_plural("plats");
      add_adjective("plat");
    }
/* order - highest value to the left of money_array */
    for(i=0; i<sizeof(money_array); i+=2) {
      val = (int)MONEY_HAND->query_value(money_array[i]);
      if((int)MONEY_HAND->query_value(type) > val) break;
    }

    money_array = money_array[0..(i-1)] + ({ type, amt }) +
       money_array[i..sizeof(money_array)];
  } else {
    money_array[i+1] += amt;
    if (money_array[i+1] <= 0) {
      remove_adjective(type);
      /* More Hamlet junk */
      remove_plural(type+"s");
      remove_plural("m"+type[0..0]+"s");
	remove_plural("monedas de "+type);
      remove_alias(type);
      remove_alias("m"+type[0..0]);
      if(type == "platino") {
        remove_alias("plat");
        remove_plural("plats");
        remove_adjective("plat");
      }
      money_array = delete(money_array,i,2);
      set_weight(query_number_coins()/WEIGHTDIV); /* Hamlet */
      return 0;
    }
  }

  set_weight(query_number_coins()/WEIGHTDIV); /* Hamlet */
  return money_array[i+1];
}

mixed *query_money_array() { return money_array; }

void set_money_array(mixed *arr) {
  int i;
  mixed *newarr = ({ });

  if(stringp(arr))
    return;

  for(i=0;i<sizeof(arr);i+=2)
    if (member_array(arr[i],(mixed *)MONEY_HAND->query_values()) != -1)
      newarr += ({ arr[i], arr[i+1] });

  money_array = newarr;
  adjectives = ({ }); /* clear them... */
  alias = ({ "Some Money For Me" }); /* clear these too */
  plurals = ({ "monedas" }); /* clear these too */

  for (i=0;i<sizeof(money_array);i+=2) {
    add_adjective(money_array[i]);
    add_plural(money_array[i]+"s");
    add_plural("m"+money_array[i][0..0]+"s");
	add_plural("monedas de "+money_array[i]);
    add_alias(money_array[i]); /* Give 30 platinum to someone - Hamlet */
    add_alias("m"+money_array[i][0..0]); /* give 30 pc to Hamlet */
    if(money_array[i] == "platino") {
      add_alias("plat");  /* give 30 plat to Hamlet */
      add_plural("plats");
      add_adjective("plat");
    }
  }
  set_weight(query_number_coins()/WEIGHTDIV); /* Hamlet */
}

string *half_short() {
  string *retval;
  int i;

  retval = ({ });
  for (i=0;i<sizeof(money_array);i+=2)
    if (money_array[i+1] > 1)
      if (this_player() != environment() && money_array[i+1] > 10)
        retval += ({ "algunas monedas de "+money_array[i] });
      else
        retval += ({ money_array[i+1]+" monedas de "+
                           money_array[i] });
    else if (money_array[i+1] == 1)
      retval += ({ "1 moneda de "+money_array[i] });
  return retval;
}

// has to be toketeado para ke kambie el orden y no se repita lo d moneda
string short(int dark) {
  mixed retval;

  retval = half_short();
  if (!sizeof(retval))
    return 0;
/*
  if (sizeof(retval) == 1)
    return retval[0] + " moneda"+(retval[0]==1?"":"s");
  return implode(retval[0..sizeof(retval)-2], ", ")+
         " y "+retval[sizeof(retval)-1] + " moneda"+
         (retval[sizeof(retval)-1]==1?"":"s");
*/
  if (sizeof(retval) == 1)
	return retval[0];
  return implode(retval[0..sizeof(retval)-2], ", ")+
	" y "+retval[sizeof(retval)-1];

}
/*
string *pretty_short(int dark) {
  return half_short();
}
*/

string long(string str, int dark) {
  string ret = "Al observar la monedas puedes ver ";

    ret += ({ "al temido brujo Xerxes."
            , "la silueta de Flangerant, el Escriba de los Dioses."
            , "a Tyrael, Dios de lo visible y lo invisible."
            , "a Jade, la Dama Oscura."
            , "a Grimfang, Se�or de los Ejercitos del Norte."
            , "a Vilat, el oscuro Se�or del Inframundo. "
            , "que en realidad la moneda es mas falsa que un billete de 3 euros."
            , "que el dinero no da la felicidad, pero contribuye sobremanera."
    	    , "a Leviathan, Se�or de Se�ores, en su Trono de Poder."
	    , "que venimos del polvo y en polvo nos convertiremos."
          })[random(10)];
  ret += "\n";
  return ret;
}

object new_money_object(int num, string type) {
  int i;
  object ob;

  if (!sizeof(money_array))
    return 0;
  if (!type)
    i = 0;
  else if ((i = member_array(type, money_array)) == -1)
    return 0;
  if (num > money_array[i+1])
    num = money_array[i+1];
  ob = clone_object(MONEY_OBJECT);
  ob->adjust_money(num, type);
  money_array[i+1] -= num;
  if (money_array[i+1] <= 0)
    money_array = delete(money_array, i, 2);

  /* Weight stuff -- Hamlet */
  set_weight(query_number_coins()/WEIGHTDIV);

  return ob;
}

varargs int move(mixed dest, mixed messin, mixed messout) {
  int j;
  object ob, mon;
  object from_where;
  from_where = environment();
  if(!from_where) from_where=
        find_player(query_property("clonedin"));

  if(environment() ) environment()->fix_my_loc_weight_later();
  j = (int)::move(dest, messin, messout);
  if (j != MOVE_OK)
    return j;
  if (objectp(dest))
    ob = dest;
  else {
    ob = find_object(dest);
    if (!ob) {
      call_other(ob, "??");
      ob = find_object(dest);
    }
  }
  remove_alias("Some Money For Me");
  remove_call_out("move");
  if (ob && (mon = present("Some Money For Me", ob)) && !dont_join) {
    for (j=0;j<sizeof(money_array);j+=2)
      mon->adjust_money(money_array[j+1], money_array[j]);
    dont_join = 1;
    move("/room/void","","");
     if(from_where)
      if(interactive(from_where))
      catch(MONEY_TRACKER->update_statistics(-query_value(),
          from_where));
    call_out("dest_me",0);
    return MOVE_OK;
  }
  add_alias("Some Money For Me");
  if(ob&&interactive(ob)) {
    catch(MONEY_TRACKER->update_statistics(query_value(),ob));
    }
     if(from_where)
      if(!dont_join)
      catch(MONEY_TRACKER->update_statistics(-query_value(),
          from_where));
  set_weight(query_number_coins()/WEIGHTDIV);
  if(environment() ) environment()->fix_my_loc_weight_later();

  return MOVE_OK;
}

object query_parse_id(mixed *arr) {
  int i, j, num, l;
  string s1, *bit;
  int n1;
  object ob;
  string cn1;

  if(this_player() && this_player()->query_name() == "hamlet")
    tell_object(this_player(),sprintf("%O\n",arr));

  if (arr[0] == 0) {
    bit = explode(arr[1], " ");
/* Not entirely positive what this did, but changes required its removal.
   I added some of this carp back below.
   - Hamlet

    if (bit[sizeof(bit)-1] != "coins")
      if (environment() != this_player())
        return this_object();
      else
        return 0;
    if (sizeof(bit) == 1)
      return this_object();
*/

    if(bit[0] == "monedas")
      return this_object();

    if(bit[0] == "all") {
      if(environment(this_object()) != this_player())
        return this_object();
      else
        return 0;
    }

    switch(bit[0]) {
      case "plat" : bit[0] = "platino"; break;
      case "mp"   : bit[0] = "platino";  break;
      case "mo"   : bit[0] = "oro";  break;
      case "me"   : bit[0] = "esta�o";  break;
      case "ma"   : bit[0] = "argento";  break;
      case "mc"   : bit[0] = "cobre";  break;
    }

    i = member_array(bit[0], money_array);
    if (i == -1)
      return 0;
    num = money_array[i+1];
    s1 = money_array[i];
    money_array = delete(money_array, i, 2);
    remove_adjective(s1);
    remove_plural(s1+"s");
    remove_plural("m"+s1[0..0]+"s");
    remove_alias(s1);
    remove_alias("m"+s1[0..0]);
    if(s1 == "platino") {
      remove_alias("plat");
      remove_plural("plats");
      remove_adjective("plat");
    }
    ob = clone_object(MONEY_OBJECT);
    ob->set_money_array(({ s1, num }));


    /* Weight stuff.  -- Hamlet */
    set_weight(query_number_coins()/WEIGHTDIV);

        ob->add_property("clonedin",environment()->query_name());
    ob->do_move_call_out(environment());
    return ob;
  }
/* assume if they are after a particular one they are not interested in
 * us... */
  if (arr[0] <= 0 || !sizeof(money_array))
    return 0;
  i = -1;

  bit = explode(arr[1]," ");
  for(l=0;l<sizeof(bit);l++) {
    switch(bit[l]) {
      case "plat"  : bit[l] = "platino"; break;
      case "mp"    : bit[l] = "platino";  break;
      case "mo"    : bit[l] = "oro";  break;
      case "me"    : bit[l] = "esta�o";  break;
      case "ma"    : bit[l] = "argento";  break;
      case "mc"    : bit[l] = "cobre";  break;
      case "plats" : bit[l] = "platinos";  break;
      case "mps"   : bit[l] = "platinos";  break;
      case "mos"   : bit[l] = "oros";  break;
      case "mes"   : bit[l] = "esta�os";  break;
      case "mas"   : bit[l] = "argentos";  break;
      case "mcs"   : bit[l] = "cobres";  break;
    }
  }
/*

  if(this_player()->query_name() == "hamlet")
    tell_object(this_player(),sprintf("%O\n",arr));
*/

  arr[1] = implode(bit," ");

  for (j=0;j<sizeof(money_array);j+=2)
    /* This next line looks moronic, but trust me, it skirts a known sscanf()
       bug.
    */
    if (sscanf(arr[1], "%s "+money_array[j],cn1)) {
      i = j;
      sscanf(cn1,"%d",n1);
      if(n1 > 0)
        arr[0] = n1;
  }

  if(i == -1) {
    for(j=0;j<sizeof(money_array);j+=2)
      if(money_array[j] == arr[1][0..strlen(money_array[j])-1])
        i = j;
  }

  if (i == -1) {
    i = member_array("cobre",money_array);
    if (i == -1)
      i = 0;
  }

  if( (arr[1][strlen(arr[1])-5..strlen(arr[1])-1] == "monedas") &&
      (n1 <= 0) )
    arr[0] = money_array[i+1];

  if (arr[0] >= money_array[i+1]) {
    num = money_array[i+1];
    remove_plural(money_array[i]+"s");
    remove_plural("m"+money_array[i][0..]+"s");
    remove_alias(money_array[i]);
    remove_alias("m"+money_array[i][0..0]);
    if(money_array[i] == "platino") {
      remove_alias("plat");
      remove_plural("plats");
      remove_adjective("plat");
    }
    remove_adjective(money_array[i]);
  }
  else
    num = arr[0];
  money_array[i+1] -= num;
  arr[0] -= num;
  ob = clone_object(MONEY_OBJECT);
  ob->set_money_array( ({ money_array[i], num }) );


  /* Weight stuff.  -- Hamlet */
  set_weight(query_number_coins()/WEIGHTDIV);

        ob->add_property("clonedin",environment()->query_name());
  ob->do_move_call_out(environment());
  return ob;
}

/* you cannot sell money... */
int do_not_sell() { return 1; }
void do_move_call_out(object ob) { call_out("move",0,ob); }

int query_value() { return (int)MONEY_HAND->query_total_value(money_array); }

int query_number_coins()
{
  int i, tot;

  if(!sizeof(money_array)) return 0;
  for(i=1;i<sizeof(money_array);i+=2)
    tot += money_array[i];
  return tot;
}
