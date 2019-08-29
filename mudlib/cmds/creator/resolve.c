/* Hamlet, Jun 1997 - Resolve an IP address from numeric to alphabetic
                      or vice versa.  Needed for testing, mostly.
*/
#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

mapping handles;

void setup() {
  position = 1;
  handles = ([ ]);
}

string query_usage() { return "resolve <address>\n"; }

string query_short_help() {
 return "Resolve converts a numeric IP address to an alphabetic one, "
        "and vice versa.\n\n"
        "Examples:\n"
        "  resolve ns.opup.org\n"
        "  resolve 128.169.92.86\n";
 }

static int cmd(string str, object me) {
  handles[resolve(str, "res_cb")] = me;
  return 1;
} /* cmd() */

void res_cb(string wordaddr, string numaddr, int handle) {
  tell_object(handles[handle], "Resolved: "+ wordaddr + " == " + 
                               numaddr + "\n");

  map_delete(handles, handle);
}
