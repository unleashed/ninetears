#include "/w/barthleby/path.h"

inherit "/obj/monster";


void setup()
{
  set_name("rata mutante");
  set_short("rata mutante");
  add_alias("mutante");
  set_long("Esta no es una rata comun, de pelo negro con mechas azules y verdes, ojos rojos y grandes dientes amarillos, "
          "consigue auyentar a cualquier animal del lugar con su metro y medito de largo. Es un "
          "animal realmente agresivo que ha sufrido una extra�a mutaci�n.\n");
  set_main_plural("ratas mutantes");
  add_plural("ratas");
  add_plural("mutantes");
  set_gender(0);
  set_random_stats(7,10);
   set_align(100);
  set_str(15);
  set_wimpy(0);
  set_max_hp(this_object()->query_hp()*2);
   set_level(8+random(2));
   load_a_chat(80,
   ({ 1, "'iiiiiiiiiiiiiik ,iiiiiiiiiiiiiiiiik!!!!!",
      1, ":te ense�a sus ensangrentados colmillos.",
      1, ":eriza sus pelos y mueve su larga cola de forma amenazadora.",
   }));
} 
