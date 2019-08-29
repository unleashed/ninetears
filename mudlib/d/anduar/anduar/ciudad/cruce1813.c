// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

object verja;

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Jardin%^RESET%^");
   set_long("Estas en una pequenya zona verde en la ancestral ciudad de "
        "Anduar, aqui los mas mayores del lugar se reunen a descansar y a "
        "contar batallas sobre las viejas eras. Observas que casi todos sus "
        "habitantes son humanos, aunque se puede ver algun que otro enano o "
        "elfo. Al norte observas una reja que separa la zona rica de la "
        "ciudad de la demas.\n");
// add_exit("norte"   ,ANDUAR"cruce1713.c","road");
   add_exit("sudoeste",ANDUAR"cruce1912.c","road");
   add_exit("sur"     ,ANDUAR"cruce1913.c","road");
   add_exit("sudeste" ,ANDUAR"cruce1914.c","road");
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
  add_action("abrir","abrir");
}

int abrir(string str)
{
 if (str == "verja")
  {
  write("Abres la verja y entras en la parte rica de Anduar.\n");
  tell_room(environment(TP),TP->query_cap_name()+" abre la verja que separa "
   "la parte rica de la ciudad y entra en ella.\n",TP);
  TP->move(load_object(ANDUAR+"cruce1713.c"));
   this_player()->look_me();
  tell_room(environment(TP),TP->query_cap_name()+" entra a la zona "
  "rica.\n",TP);
  return 1;
  }
 notify_fail("Que pretendes abrir?.\n");
 return 0;
}
