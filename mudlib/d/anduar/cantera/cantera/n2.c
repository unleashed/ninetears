// Aokromes
#include "../../path.h"
inherit CANTERA2+"cantera.c";
object golem;

void setup()
{
   set_short("%^CYAN%^BOLD%^Real cantera de Anduar%^RESET%^");
   set_long("Estas en la Real cantera de Anduar, la cual fue utilizada para "
   "proporcionar roca al Real camino, por todos lados observas restos de "
   "las estructuras dedicadas a extraer la roca, en la parte oeste observas "
   "como en medio de los restos de un derrumbe, una galeria se introduce en "
   "el subsuelo.");
    add_exit("oeste"     ,CANTERA3"tunel1.c","road");
   add_exit("southeast" ,CANTERA2"n0-9.c","road");
   add_exit("este"      ,CANTERA2"n1-9.c","road");
   add_exit("northeast" ,CANTERA2"n2-8.c","road");
   modify_exit("oeste", ({"function", "go_in", "message", " $N entra a "
   "la galeria."}));
   set_zone("anduar");
}

void reset()
{
   ::reset();
   if (!golem)
   {
      golem=clone_object(CBICHOS+"golem");
      golem->move(this_object());
   }
}
int go_in()
{
   object ob;
   
   ob=this_player();

   if (!golem)
   {
      return 1;
   }
   else
      {
      notify_fail("El golem te bloquea la salida.\nEl golem dice: "  
                  "Por encima de mi cadaver!\n");
      say(ob->query_cap_name()+" intenta entrar en la galeria, pero el "
      "golem se lo impide.\n");
      return 0;
      }
}

void dest_me()
{
   ::dest_me();
   destruye_bichos();
}
