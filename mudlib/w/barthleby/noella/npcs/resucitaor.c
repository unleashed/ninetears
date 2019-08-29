
inherit "/obj/monster";

#include "/w/barthleby/path.h"

setup()
{
   set_name("picon");
   set_short("Picon");
   add_alias("picon");
   set_main_plural("personas que se parecen mucho a Picon");
   set_long("Picon es un viejo Cl�rigo capacitado por las artes divinas en "
   "devolver las almas a su forma mortal. Es un humano de apariencia amable y "
   "juvenil.\n");
  set_race("human");
  set_race_ob("/std/races/human");
  set_random_stats(12,18);
  set_cha(20);
  set_gender(1);
  set_level(10);
  load_chat(40, ({
      1, "'Los a�os pasan muy rapidamente, y las cosas cambian con ellos.",
      1, "'Recuerdo cuando era ni�o...",
      1, "'Las historias pasadas me fascinan.",
      1, ":se rasca la barbilla.",
    }));
} /* setup */
void event_enter(object ob, string mensaje, object donde)
{
   string sexo, fem;

   if ((int)ob->query_timed_property("guardias_noella"))
   {
      if (ob->query_dead())
         do_command("'Nunca te deber�as haber quebrantado las leyes de Noella.");
      else
         do_command("'Ahora ser�s perseguido por toda Noella, para hacerte pagar tu osad�a.");
   }
   else
   {
     if (!ob->query_dead())
     {
       if(ob->query_gender() == 2)
       {
          sexo = "se�ora";
          fem = "a";
       }
       else
       {
          sexo = "maese";
          fem = "o";
       }
       do_command("'Bienvenid"+fem+" al Templo "+sexo+" "+ob->query_cap_name()+".");
     }
   }
   ::event_enter(ob, mensaje, donde);
}/*event_enter*/

