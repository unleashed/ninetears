/* converted by Malik Nov 97 */

inherit "/d/gremios/comandos/base_command.c";
#include "new_tweaks.h"

void setup(){
   set_command_name("considerar");
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
      if (dlvl != 0 )
         rate = diff*diff/dlvl + 1;
      else
         rate = diff*diff+1;
      switch(rate*mult){

       case -1000..-10:
         mess += "Estas un poco loco si quieres atacar "
          "a "+tar->query_cap_name()+".\n";
       break;
       case -9..-8:
         mess += tar->query_cap_name()+" es el mas fuerte de todos en la region.\n";
       break;
       case -7..-6:
         mess += tar->query_cap_name()+" es mucho mas fuerte que tu.\n";
       break;
       case -5..-4:
         mess += tar->query_cap_name()+" es mas fuerte que tu.\n";
       break;
       case -3..-2:
         mess += tar->query_cap_name()+" es un poco mas fuerte que tu.\n";
       break;
       case -1..1:
         mess += tar->query_cap_name()+" es aproximadamente como tu.\n";
       break;
       case 2..3:
         mess += tar->query_cap_name()+" es un poco mas debil que tu.\n";
       break;
       case 4..5:
         mess += tar->query_cap_name()+" es mas debil que tu.\n";
       break;
       case 6..7:
         mess += tar->query_cap_name()+" es mucho mas debil que tu.\n";
       break;
       case 8..9:
         mess += tar->query_cap_name()+" es tan debil que no vale la pena atacarlo.\n";
         break;
       break;
       case 10..1000:
         mess += "Podrias matar a "+tar->query_cap_name()+" con un "
          "soplido!\n";
       break;
      }
   }
   tell_object(doer,mess);
   return 1;
} /* do_command() */

