// Poblado de Eldenar // by Serl
#include "path.h"
inherit "/std/outside.c";

void setup()
{
    set_short("%^BOLD%^Molino: Repisa de la ventana%^RESET%^");
    set_long("\nTe encuentras en la repisa de la ventana del segundo piso "
        "del molino de Eldenar.\n");
    add_item("ventana","\nUna ventana normal. Parece que esta cerrada.\n");
}

void init()
{
   ::init();
   add_action("romper_cristal", "romper");
   add_action("abrir_ventana", "abrir");
}



int romper_cristal(string str)
{
   if (str == "cristal")
   {
   write("\nAtraviesas el cristal con tu brazo provocandote algunos "
      "cortes en el brazo pero consigues abrir la ventana.\n");
   say(this_player()->query_cap_name()+" atraviesa el cristal con su brazo "
      "haciendose unos cortes en el y consigue abrir la ventana.\n");
   add_exit("dentro",POBLADO"molino5.c","door");
   renew_exits();
   this_player()->adjust_hp(-5);
   return 1;
   }
   notify_fail(" Como no sea el cristal...\n");
   return 0;

}


int abrir_ventana(string str)
{
   if (str == "ventana")
   {
   write("\nIntentas abrir la ventana, pero te das cuenta que es "
      "imposible. Del esfuerzo pierdes el equilibrio y caes al vacio "
      "chocando fuertemente contra el suelo.\n");
   say(this_player()->query_cap_name()+" intenta abrir la ventana pero sus "
      "esfuerzos son inutiles. Del esfuerzo pierde el equilibrio y "
      "cae al vacio chocando contra el suelo fuertemente.\n");
   this_player()->adjust_hp(-50);
   this_player()->move(POBLADO"molino1.c");
   this_player()->look_me();
    this_player()->add_timed_property("passed out","Estas incosciente.\nNo puedes hacer nada.\n",2);
   return 1;
   }
   notify_fail("Abrir que?\n");
   return 0;
}
