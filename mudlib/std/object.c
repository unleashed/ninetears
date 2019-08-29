/*
    /std/object.c 
    Previous hacks by Dank and Pinkfish
    Baldrick cleaned after them.
    Hamlet fixed timed properties.
    Radix made create_me more accurate - 7/96
*/

inherit "/std/basic/property";
inherit "/std/basic/extra_look";
inherit "/std/basic/read_desc";
inherit "/std/basic/misc";
inherit "/std/basic/id";

string create_me;
 
void create() {
  create_me = "Object";
  id::create();
  property::create();
  extra_look::create();
  misc::create();
  read_desc::create();
  seteuid(master()->creator_file(file_name(this_object())));
  // Radix, July 1996
  create_me = master()->get_create_me(create_me);
  this_object()->setup();
}

void set_name(string str) 
{
  if (name && name != "object") return ;
  name = str;
  if (!short_d)
    short_d = str;
  add_plural(pluralize(str));
}

int query_enchant() { return 0; }
status set_enchant(int i) { return 0; }
status query_weapon() { return 0;}
status query_armour() { return 0; }

mixed *stats() {
  return ::stats() + ({
    ({ "name" , name, }),
    ({ "short", short(0), }),
    ({ "plural", query_plural(), }),
    ({ "value", query_value(), }),
    ({ "weight", query_weight(), }),
    ({ "cloned by", create_me, }),
   });
}

mixed *query_init_data() {
   return
      property::query_init_data() +
      extra_look::query_init_data() +
      read_desc::query_init_data() +
      misc::query_init_data() +
      id::query_init_data();
} /* query_init_data() */

/*
 * This is here till I can delete it...  ie the new system is functioning.
 */
mapping int_query_static_auto_load() {
  return ([ "weight" : weight, "light" : light, "short" : short_d, 
            "long" : long_d, "adjective" : adjectives, "alias" : alias, 
            "plural" : plurals, "weight" : weight, "name" : name, 
            "main plural" : plural_d, "value" : value ]);
} /* query_static_auto_load() */

mapping query_dynamic_auto_load() {
  return ([ 
            /*"labels" : "/global/player"->create_auto_load(labels),*/
            "properties" : map_prop,
            "timed"     : freeze_timed_properties(timed_prop), /* Hamlet */
            "read mess" : read_mess,
            "cloned by" : create_me,
          ]);
} /* query_dynamic_auto_load() */

void init_static_arg(mapping bing) {
  if (!undefinedp(bing["name"]))
    set_name(bing["name"]);
  if (!undefinedp(bing["weight"]))
    set_weight(bing["weight"]);
  if (!undefinedp(bing["light"]))
    set_light(bing["light"]);
  if (!undefinedp(bing["short"]))
    set_short(bing["short"]);
  if (!undefinedp(bing["long"]))
    set_long(bing["long"]);
  if (bing["adjective"])
    set_adjectives(bing["adjective"]);
  if (bing["alias"])
    set_aliases(bing["alias"]);
  if (bing["plural"])
    set_plurals(bing["plural"]);
  if (!undefinedp(bing["main plural"]))
    set_main_plural(bing["main plural"]);
  if (!undefinedp(bing["value"]))
    set_value(bing["value"]);
} /* int_init_static_arg() */

mixed query_static_auto_load() {
  if (file_name(this_object())[0..10] == "/std/object")
    return int_query_static_auto_load();
  return ([ ]);
} /* query_static_auto_load() */

void init_dynamic_arg(mapping args) {
/*  if (args["labels"])
    "/global/player"->load_auto_load(args["labels"], this_object());*/
  if (args["properties"])
    map_prop = args["properties"];
  /* Let's restore timed -- Hamlet */
  if (args["timed"])
    timed_prop = thaw_timed_properties(args["timed"]);
  set_read_mess(args["read mess"]);
  create_me = args["cloned by"];
} /* init_dynamic_arg() */

void init_arg(mixed *bing) {
  if (sizeof(bing) < 10)
    return ;
  weight = bing[0];
  light = bing[1];
  short_d = bing[2];
  long_d = bing[3];
  set_adjectives(bing[4]);
  set_aliases(bing[5]);
  set_plurals(bing[6]);
  weight = bing[8];
  set_name(bing[9]);
  map_prop = bing[10];
  value = bing[12];
} /* init_arg() */
 
int query_dead()
{
 return 1;
}

 // The following is from the TMI-2 Lib. Asmodean Put it here
int clean_up()
{
object env, *contents;
int i;

if (userp(this_object())) return 1; /* don't clean_up players */
        env = environment();
        if (env && userp(env)) return 1; /* carried ob */
        if (env && environment(env))
    return (int)environment(env)->clean_up(); /* recurse */
        contents = deep_inventory(this_object());
        if (contents) {
                for (i=0;i<sizeof(contents);i++)
                        if (userp(contents[i])) return 1; /* holding a user */
        }
        if (!env) {
                /* we're a room with no users inside or a lost object */
dest_me();
                return 1;
        }
        return 1; /* try again later... */
}

nomask query_create_me() { return create_me; }
