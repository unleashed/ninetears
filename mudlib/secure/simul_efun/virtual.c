#include "/include/virtual.h"

object virtual_find_object(string name) {
  object ob;
  return find_object(name);
} /* find_object() */

string virtual_file_name(object ob) {
  string name;
  int i;
  if(!ob) return 0;
  if (name = (string)ob->query_property("virtual name"))
    return name;
  name = file_name(ob);
  if (sscanf(name, "%s#%d", name, i) == 2)
    return name+".c#"+i;
  return name+".c";
} /* file_name() */
