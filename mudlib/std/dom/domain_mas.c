/* Standard domain master object
 * Radix May 10, 1996
 */
 
int open_read = 1;
string DOM_LORD, DOMAIN;
mapping perms;
 
void set_domain(string dom) { DOMAIN = dom; }
void set_domain_lord(string lord) { DOM_LORD = lord; }
void set_open_read(int i) { open_read = i; }
int query_open_read() { return open_read; }
void set_permissions(mapping p) { perms = p; }

int query_prevent_shadow() { return 1; }
 
mixed members;
 
void create() 
{
   int i;
   mapping map;
 
   members = ([ ]);
   perms = ([ ]);
   seteuid("/secure/master"->creator_file(file_name(this_object())));
   restore_object(file_name(this_object()), 1);
   if (pointerp(members)) 
   {
      map = ([ ]);
      for (i=0;i<sizeof(members);i++)
         map[members[i]] = "No Project";
      members = map;
   }
} /* create() */
 
void save_me() {
  seteuid("/secure/master"->get_root_uid());
  save_object(file_name(this_object()), 1);
  seteuid("/secure/master"->creator_file(file_name(this_object())));
} /* save_me() */
 
string query_dom_lord() { return DOM_LORD; }
 
varargs int query_dom_manip(string euid) 
{
   if(!euid) euid = geteuid(this_player(1));
   if((euid == query_dom_lord()) ||
      (master()->query_lord(euid) &&
      "/secure/master"->high_programmer(geteuid(this_player()))))
   return 1;
   if(lower_case(euid) == DOMAIN)  return 1;
   return 0;
}
 
int valid_read(string *path, string euid, string funct) 
{
   if(query_open_read()) return 1;
 
   if(query_dom_manip(euid))
     return 1;
   
   return (members[euid] != 0);
} /* valid_read() */
 
int valid_write(string *path, string euid, string funct) 
{
   if(query_dom_manip(euid))
     return 1;
   if(path[2]=="master" || path[2]=="master.c" || path[2]=="master.o")
     return 0;
   if(euid == "Dom: "+DOMAIN) return 1;
   if(!members[euid]) return 0;

   // Okay, we have a member (non Thane/Lord).. check sub-dir access
   if((level = get_permissions(path,euid,funct)) > 0)
} /* valid_write() */
 
void dest_me() { destruct(this_object()); } 
 
/* please note the + ({ })... this is for security reasons.
 */
string *query_members() { return keys(members) + ({ }); }
 
int add_member(string name) 
{
   if(!query_dom_manip(geteuid(this_player(1)))) return 0;
   if(members[name]) return 0;
   members[name] = "newbie";
   save_me();
   return 1;
} /* add_member() */
 
int remove_member(string name) 
{
   int i;
 
   if(!query_dom_manip(geteuid(this_player(1)))) return 0;
   if(!members[name]) return 0;
   members = m_delete(members, name);
   save_me();
   return 1;
} /* remove_member() */
 
int set_project(string name, string pro) 
{
  if(!query_dom_manip(geteuid(this_player(1)))) return 0;
  if(!members[name]) return 0;
  if(!pro || pro == "") pro = "project unset";
  members[name] = pro;
  save_me();
  return 1;
} /* set_project() */
 
int query_member(string name) 
{
   return !undefinedp(members[name]) || name == DOM_LORD;
} /* query_member() */
 
string query_project(string name) 
{
   if(!members[name])
      return "project unset";
   return members[name];
} /* query_project() */
 
void smart_log(string error, string where) 
{
   write_file("d/"+DOMAIN+"/player_reports", error);
} /* smart_log() */
 
string log_who(string where) 
{
   return DOM_LORD;
} /* log_who() */
 
string author_file(string *str) 
{
   switch (str[1]) 
   {
      case "fr" : 
         return DOM_LORD;
      default: return "baldrick";
   }
} /* author_file() */
 
int path_comp(string *a, string *b)
{
   int i;

   if(!a || !b) return 0;
   if(sizeof(a) != sizeof(b)) return 0;

   for(i=0; i<sizeof(a); i++)
      if(a[i] != b[i]) 
         return 0;
   
   return 1;
}
