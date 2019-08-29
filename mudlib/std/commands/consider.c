/* converted by Malik Nov 97 */

inherit "/std/commands/base_command.c";
#include "new_tweaks.h"

void setup(){
   set_command_name("consider");
   target_type = "many";
   lockout = 0;
} /* setup() */

int consider(string str, object ob){
   return ::exec_command(str,ob);
} /* consider() */

int do_command(object *targets, object doer){
   object tar;
   int rate,diff,mult,dlvl;
   string mess;

   dlvl = doer->query_level();
   mess = "";

   foreach(tar in targets){
      diff = dlvl - tar->query_level();
      (diff < 0 ? mult = -1 : mult = 1);
      rate = diff*diff/dlvl + 1; 
      switch(rate*mult){

       case -1000..-10:
         mess += "You would have to be moderately insane to "
          "attack "+tar->query_cap_name()+".\n";
       break;
       case -9..-8:
         mess += tar->query_cap_name()+" is a lot tougher than you.\n";
       break;
       case -7..-6:
         mess += tar->query_cap_name()+" is much tougher than you.\n";
       break;
       case -5..-4:
         mess += tar->query_cap_name()+" is tougher than you.\n";
       break;
       case -3..-2:
         mess += tar->query_cap_name()+" is slightly tougher than you.\n";
       break;
       case -1..1:
         mess += tar->query_cap_name()+" is about equal with you.\n";
       break;
       case 2..3:
         mess += tar->query_cap_name()+" is slightly weaker than you.\n";
       break;
       case 4..5:
         mess += tar->query_cap_name()+" is weaker than you.\n";
       break;
       case 6..7:
         mess += tar->query_cap_name()+" is much weaker than you.\n";
       break;
       case 8..9:
         mess += tar->query_cap_name()+" is a lot weaker than you.\n";
         break;
       break;
       case 10..1000:
         mess += "You could kill "+tar->query_cap_name()+" with a "
          "needle!\n";
       break;
      }
   }
   tell_object(doer,mess);
   return 1;
} /* do_command() */

