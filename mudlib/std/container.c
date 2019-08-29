#include "move_failures.h"
inherit "std/object";
inherit "std/basic/cute_look";

#define MAX_INVENT 40
#define C_CLOSED 1
#define C_TRANS 2
#define C_OPAQUE 1
#define BASE_WEIGHT_REDUCTION 30

static int weight_reduction;
static int max_weight, loc_weight;
static int prevent_insert;

void create() {
  weight_reduction = BASE_WEIGHT_REDUCTION;
  object::create();
} /* create() */

void fix_my_loc_weight();
void set_max_weight(int arg) { max_weight = arg; }
int query_max_weight() { return max_weight; }
int query_loc_weight() { return loc_weight; }
void set_weight_reduction(int arg) { weight_reduction = arg; }

int query_weight() {
  int temp;
  if(living(this_object()))
    temp = this_object()->query_loc_weight();
  else
    temp = this_object()->query_loc_weight()*weight_reduction/100;
  temp += ::query_weight();
  if(temp > 0) return temp;
  else return 0;
}

int add_weight(int n) {

  if (::add_weight(n)) return 1;
  if (!max_weight) return 1;
  if (n + loc_weight > max_weight) return 0;
  loc_weight += n;
  if(environment()) environment()->fix_my_loc_weight();
  return 1;
} /* add_weight() */

/* Oct 1995 -- Hamlet
   This is damn sloppy.  Zillions of things are bugging encumbrance,
   particularly money.  So I'm going to have money call this fcn every
   time something is transacted.  Should fix encumbrance, clearing up
   problems with ANYTHING that might be bugging it.  But boy it's stupid
   to have to do this.  Someone should figure out how to fix the real
   problems.  But not now.  No time.
*/
void fix_my_loc_weight() {
  object *stuff;
  int i;

  stuff = all_inventory(this_object());
  loc_weight = 0;

  for(i=0;i<sizeof(stuff);i++)
    if(!add_weight(stuff[i]->query_weight())) {
// Let's be nice to the player and TELL them when they drop something :)
// Anirudh
      tell_object(this_object(),"You can't hold on to everything "
        "you are trying to carry, you drop "+stuff[i]->
         query_name()+"\n");
      stuff[i]->move(environment(this_object()));
    }
}  

void fix_my_loc_weight_later() {
  call_out("fix_my_loc_weight",2);
  return;
}

int transfer_all_to(object dest) {
  object *ob;
  int i;
 
  ob = all_inventory(this_object());
  ob -= ({ dest });
  for (i=0;i<sizeof(ob);i++)
    ob[i]->move(dest);
  if (first_inventory(this_object())) return 0;
  return 1;
} /* transfer_all_to() */

/* ok modifyed back to using writes... */
string long(string str, int dark) {
  string ret;

  ret = ::long(str);
  ret += calc_extra_look();
  if(this_object()->query_corpse())
    ret += (string)this_object()->query_living_contents(0);
  else
    ret += query_contents(short(dark)+" contains:\n", all_inventory() - 
                          query_labels());
  return ret;
} /* long() */

int test_remove(object ob, int flag) { return 1; }
int test_add(object ob, int flag) { return 1; }
int set_prevent_insert() { prevent_insert = 1; }
int reset_prevent_insert() { prevent_insert = 0; }
int query_prevent_insert() { return prevent_insert; }

varargs int move(mixed dest, mixed messin, mixed messout) {
  if (prevent_insert && loc_weight && !living(dest) && environment(dest))
    return MOVE_INVALID_DEST;
  return (int)object::move(dest, messin, messout);
} /* move() */

object *find_inv_match(string str) {
  return all_inventory(this_object());
} /* find_inv_match() */

mixed stats() {
  return ::stats() + ({
    ({ "loc_weight", query_loc_weight(), }),
    ({ "max_weight", query_max_weight(), }),
  });
} /* stats() */

mixed *query_init_data() {
  return object::query_init_data() + ({
         "max weight", max_weight, "set_max_weight",
         "prevent insert", prevent_insert, "set_prevent_insert",
         });
} /* query_init_data() */

mapping int_query_static_auto_load() {
  mapping tmp;

  tmp = ::int_query_static_auto_load();
  return ([ "::" : tmp, "max weight" : max_weight,
            "prevent insert" : prevent_insert,
    ]);
} /* int_query_static_auto_load() */

mapping query_dynamic_auto_load() {
  return ([ "::" : ::query_dynamic_auto_load(),
            "inv" : 
         "/global/player"->create_auto_load(all_inventory(this_object())-labels),
         ]);
} /* query_dynamic_auto_load() */

void init_dynamic_arg(mapping bing) {
  if (bing["::"])
    ::init_dynamic_arg(bing["::"]);
  if (bing["inv"])
    "/global/player"->load_auto_load(bing["inv"], this_object());
} /* init_dynamic_arg() */

void init_static_arg(mapping bing) {
  if (bing["::"])
     ::init_static_arg(bing["::"]);
  if (!undefinedp(bing["max weight"]))
    max_weight = bing["max weight"];
  if (!undefinedp(bing["prevent insert"]))
    prevent_insert = bing["prevent insert"];
} /* init_static_arg() */

mixed query_static_auto_load() {
  if (file_name(this_object())[0..13] == "/std/container")
    return int_query_static_auto_load();
  return ([ ]);
} /* query_static_auto_load() */
