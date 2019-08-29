// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";
object guardian;

void setup()
{
   set_short("%^YELLOW%^Exterior de Anduar: Puerta Norte%^RESET%^");
   set_long("Estas en una de las 4 puertas de Anduar, esta es la que se "
   "dirige a Takome puedes ver muchas casas en casi todas las direcciones. "
   "Hay un murmullo constante de la gente que pasea por las calles. Observas "
   "que casi todos sus habitantes son humanos, aunque se puede ver algun que "
   "otro enano o elfo y un puesto de guardia dedicado a evitar que los "
   "delincuentes campen a sus anchas.\n");
   add_exit("oeste"   ,ANDUAR"muralla0005.c","road");
   add_exit("este"    ,ANDUAR"muralla0007.c","road");
    add_exit("norte"  ,REAL+"real0.c","road");
   add_exit("dentro"  ,ANDUAR"puerta0113.c","road");
   modify_exit("dentro", ({"function", "go_in", "message", " $N entra a "
   "Anduar por la puerta."}));
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
      say(ob->query_cap_name()+" intenta entrar en la ciudad, pero el "
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
