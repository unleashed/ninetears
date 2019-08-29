/* Alterations by Hamlet, Jan 1996 */
#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup() {
  position = 2;
}

static int cmd(string str, object me) {
  object ident_cmd;
  string name;

  name = me->expand_nickname(str);
  if (!find_player(name)) {
    notify_fail("Cannot find "+name+".\n");
    return 0;
  }
  if (ident_cmd = clone_object("/net/ident_cmd")) 
    ident_cmd->do_ident(name, me);

  return 1;
} /* cmd() */
