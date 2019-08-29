// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";
object guardian;

void setup()
{
   set_short("%^YELLOW%^Interior de Anduar: Puerta Oeste%^RESET%^");
   set_long("Estas en una de las 4 puertas de Anduar, esta se guarda la "
   "salida a Kheleb-Dum. puedes ver muchas casas en casi todas las "
   "direcciones. Hay un murmullo constante de la gente que pasea por las "
   "calles. Observas que casi todos sus habitantes son humanos, aunque se "
   "puede ver algun que otro enano o elfo que parecen haber venido a comerciar.\n");
   add_exit("norte"   ,ANDUAR"oe1201.c","road");
   add_exit("fuera"   ,ANDUAR"puerta1300.c","road");
   add_exit("este"    ,ANDUAR"cg1302.c","road");
   add_exit("sur"     ,ANDUAR"oe1401.c","road");
   modify_exit("fuera", ({"function", "go_in", "message", " $N sale de Anduar por "
             "la puerta."}));
   base_desc();
   set_zone("anduar");
}

void reset()
{
   ::reset();
   if (!guardian)
   {
      guardian=new(ANDUAR+"npcs/guardian_puerta");
      guardian->move(this_object());
   }
}
int go_in()
{
   object ob;
   
   ob=this_player();
   
   if (guardian && ob->query_timed_property("guardias_anduar"))
   {
      if (!ob->query_dead())
      {
         notify_fail("El guardian te bloquea la salida.\nEl guardian dice: "  
                      "Por encima de mi cadaver!\n");
      say(ob->query_cap_name()+" intenta salir de la ciudad, pero el "
      "guardian se lo impide.\n");
      return 0;
      }
      return 1;
   }
   
   if (!guardian)
   {
      write("Al no estar el guardian de la puerta, nada te impide pasar.\n");
      return 1;
   }
   else
   {
      write("El guardian de la puerta te sonrie al ver que eres una persona "
            "pacifica.\n");
      return 1;
   }
}

void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
