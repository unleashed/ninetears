// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";
object verja;


void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Jardin%^RESET%^");
   set_long("Estas en una pequenya zona verde en la ancestral ciudad de "
        "Anduar, aqui los mas mayores del lugar se reunen a descansar y a "
        "contar batallas sobre las viejas eras. Observas que casi todos "
        "sus habitantes son humanos, aunque se puede ver algun que otro enano "
        "o elfo. Hay una tapa metalica en el suelo.\n");
   add_exit("norte",   ANDUAR"cruce0713.c","road");
   add_exit("noroeste",ANDUAR"cruce0712.c","road");
   add_exit("noreste",ANDUAR"cruce0714.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}

void reset()
{
   ::reset();
   if(!verja)
    {
verja=clone_object(ANDUAR"verja");
verja->move(this_object());
    }
}

void dest_me()
{
   if(verja) 
      verja->dest_me();
   ::dest_me();
   destruye_bichos();
}

void init()
{
   ::init();
   add_action("cloaca", "levanta*r");
   add_action("cloaca", "quita*r");
   add_action("abrir","abrir");
}

void cloaca(string tapa)
{
   if (!tapa || tapa!="tapa")
   {
      this_player()->notify_fail(query_verb()+" que?\n");
      return 0;
   }
   write("\nLevantas la tapa sigilosamente y te introduces dentro de las "
   "cloacas, no sin antes tapar de nuevo el agujero para evitar que alguien "
   "caiga dentro.\n");
   say(this_player()->query_cap_name()+" levanta algo sigilosamente y se "
   "mete por un agujero.\n");
   this_player()->move(CLOACAS"c64.c");
   this_player()->look_me();
   return 1;
}

int abrir(string str)
{
 if (str == "verja")
  {
  write("Abres la verja y entras en la parte rica de Anduar.\n");
  tell_room(environment(TP),TP->query_cap_name()+" abre la verja que separa "
   "la parte rica de la ciudad y entra en ella.\n",TP);
  TP->move(load_object(ANDUAR+"cc0913.c"));
  tell_room(environment(TP),TP->query_cap_name()+" entra a la zona "
  "rica.\n",TP);
   this_player()->look_me();
  return 1;
  }
 notify_fail("Que pretendes abrir?.\n");
 return 0;
}
