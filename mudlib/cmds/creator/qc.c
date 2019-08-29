#include <standard.h>
#include <cmd.h>
#define OBTRACK "/obj/handlers/item_info"

inherit CMD_BASE;

void setup()
{
   position = 1;
}

string query_short_help()
{
   return "Usage: qc <object>\n\n"
      "All items, item containers, weapons, and armours must be "
      "Quality Checked.  Use of this command stores your name "
      "and marks this object as acceptable material for " +
      mud_name() + ".  Permissions are very restricted in ability "
      "to use this command.\n\n"
      "See also:\n"
      "   comment, info, armours, weapons, containers, items\n\n";
}
static int cmd(string str, object ob)
{
   object itm, *obs;
   if(!ob) return;
   if(!OBTRACK->query_qc_perms(geteuid(ob))) 
   {
      notify_fail("You do not have permission to QC items.\n");
      return 0;
   }
   if(!str)
   {
      notify_fail("Syntax: qc <object>\n");
      return 0;
   }
   obs = this_player()->wiz_present(str,this_player());
   if(!sizeof(obs))
   {
       notify_fail("Could not find "+str+".\n");
       return 0;
   }
   if(sizeof(obs) > 1)
      tell_object(ob,"Only doing the first object...\n");
   itm = obs[0];
   if(itm->query_item_container())
   {
      OBTRACK->qc_item_container(itm);
      return 1;
   }
   return 1;
}
