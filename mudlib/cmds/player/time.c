#include <cmd.h>
inherit CMD_BASE;

static int cmd(string str, object me)
{
   tell_object(me,ctime(time())+" Norway/Baldrick Standard\n");
   return 1;
}
