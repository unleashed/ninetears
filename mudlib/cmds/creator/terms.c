#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
#define PEOPLER "/obj/handlers/peopler"

void setup()
{
position = 1;
}

static int cmd(string str, object me) {
  return (int)PEOPLER->do_terms(str);
} /* do_people() */

