// Aokromes
#include "../path.h"
inherit ANDUAR+"rica.c";

object agband;

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Jardin%^RESET%^");
   set_long("Estas en una pequenya zona verde en la ancestral ciudad de "
        "Anduar, aqui los mas mayores del lugar se reunen a descansar y a "
        "contar batallas sobre las viejas eras. Observas que casi todos sus "
        "habitantes son humanos, aunque se puede ver algun que otro enano o "
        "elfo.\n");
   add_exit("norte"   ,ANDUAR"cc1113.c","road");
   add_exit("sudoeste",ANDUAR"cruce1312.c","road");
   add_exit("sur"     ,ANDUAR"cruce1313.c","road");
   add_exit("sudeste" ,ANDUAR"cruce1314.c","road");
   base_desc();
   set_zone("Anduar");
   crea_bichos();
}

void reset()
{
   if(!agband)
    {
      agband=new("/d/oficios/wizards/agband/agband.c");
      agband->move(this_object());
    }
   ::reset();
}

void dest_me()
{
   if(agband) 
      agband->dest_me();
   ::dest_me();
   destruye_bichos();
}
