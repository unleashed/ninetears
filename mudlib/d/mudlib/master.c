#define DOM_LORD "god"
#define DOMAIN "mudlib"

int query_prevent_shadow() { return 1; }

/* beware editing this file.
 * Make sure you know what you are doing.  stuffing this up could be
 * fatal in some ways.
 */
mixed members;

void create() {
  int i;
  mapping map;

  members = ([ ]);
  seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
  restore_object(file_name(this_object()), 1);
  if (pointerp(members)) {
    map = ([ ]);
    for (i=0;i<sizeof(members);i++)
      map[members[i]] = "newbie";
    members = map;
  }
} /* create() */

void save_me() {
  seteuid((string)"/secure/master"->get_root_uid());
  save_object(file_name(this_object()), 1);
  seteuid((string)"/secure/master"->creator_file(file_name(this_object())));
} /* save_me() */

/* This is not a good hack, should change it later.. when I move query_god from lord.c to master.c  Baldrick dec '93 */

string query_dom_lord() 
  {
  return DOM_LORD; 
  }

int query_dom_manip()
  {
  if ( (geteuid(this_player(1)) == query_dom_lord()) || 
      (this_player(1)->query_god() && 
       "/secure/master"->high_programmer(geteuid(this_player()))))
    return 1;
  return 0;
  }

int valid_read(string *path, string euid, string funct) {
  int i;

  return 1;
/* to make this house open... Uncomment the next line
 * return 1;
 */
  if (query_dom_manip())
    return 1;
  return (members[euid] != 0);
} /* valid_read() */

int valid_write(string *path, string euid, string funct) {
  int i;
  
  if (query_dom_manip())
    return 1;
  if (path[2] == "master" || path[2] == "master.c" || path[2] == "master.o")
    return 0;
  if (euid == "Dom: "+DOMAIN) return 1;
  return (members[euid] != 0);
} /* valid_write() */

void dest_me() {
  destruct(this_object());
} /* dest_me() */

/* please note the + ({ })... this is for security reasons.
 * If you don't do this the members of your house can be changed at will
 * by any other wizard.
 */
string *query_members() { return keys(members) + ({ }); }

int add_member(string name) {
/* only the lord of the domain can add members to it.
 * BTW... change this if you want, it is a bit constrictive but handy as
 * a start point
 * The God can change it.. Baldy.. 
 */
  if(!query_dom_manip()) return 0;
  if(members[name]) return 0;
  members[name] = "newbie";
  save_me();
  return 1;
} /* add_member() */

int remove_member(string name) {
  int i;
/* see above comment...
 */
  if(!query_dom_manip()) return 0;
  if(!members[name]) return 0;
  members = m_delete(members, name);
  save_me();
  return 1;
} /* remove_member() */

int set_project(string name, string pro) {
  if(!query_dom_manip()) return 0;
  if(!members[name]) return 0;
  if(!pro || pro == "") pro = "project unset";
  members[name] = pro;
  save_me();
  return 1;
} /* set_project() */

int query_member(string name) {
  return !undefinedp(members[name]) || name == DOM_LORD;
} /* query_member() */

string query_project(string name) {
  if (!members[name])
    return "project unset";
  return members[name];
} /* query_project() */

void smart_log(string error, string where) {
  write_file("d/"+DOMAIN+"/player_reports", error);
} /* smart_log() */

string log_who(string where) {
  return DOM_LORD;
} /* log_who() */

string author_file(string *str) {
  switch (str[1]) {
    case "fr" : return DOM_LORD;
    default: return "baldrick";
  }
} /* author_file() */
