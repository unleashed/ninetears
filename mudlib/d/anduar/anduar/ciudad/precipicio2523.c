// Aokromes
#include "../path.h"
inherit ANDUAR+"cityroom.c";

void setup()
{
   set_short("%^YELLOW%^Ciudad de Anduar: Grieta del Olvido%^RESET%^");
   set_long("Estas en la ancestral ciudad de anduar, a ambos lados de la "
   "calzada observas unas viviendas de disenyo estrambotico en la parte "
   "delantera una sequoya decora el jardin, en el cual un gorrion esta posado "
   "en una rama mientras es observado por una noble que pasea por el mismo "
   "entre petunias. A salvo gracias a una alta verja que rodea la propiedad. "
   "Y una tapa metalica en el suelo lleva al algun sitio.");
   add_item(({"metalico", "tapa"}), "Es algo que parece la tapa de alguna "
   "cloaca o algo parecido.\n");
   add_exit("noreste" ,ANDUAR"precipicio2424.c","road");
   add_exit("oeste"   ,ANDUAR"cruce2522.c","road");
   base_desc();
   set_zone("anduar");
   crea_bichos();
}

void init()
{
   ::init();
   add_action("cloaca", "levanta*r");
   add_action("cloaca", "quita*r");
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
   this_player()->move(CLOACAS"c1.c");
   this_player()->look_me();
   return 1;
}
