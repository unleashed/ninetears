// Habitante de L'Ouren
#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("habitante");
   set_short("Habitante de L'Ouren");
   set_al(-100);
   set_gender(random(2)+1);
   set_main_plural("habitantes de L'Ouren");
   add_plural("habitantes");
   set_race_ob("/std/races/human");
   set_random_stats(10, 14);
   set_cha(10+random(4));
   set_level(2+random(5));     
   set_long("Es uno de los pocos ciudadanos que habitan la aldea de L'Ouren. Se "
   "trata de un"+(query_gender()==1?" hombre ":"a mujer ")+" de piel notablemente morena "
   "y estatura mediana. Seguramente est� recolectando algo.\n");
   add_move_zone("louren");
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'Me encanta el olor de los laureles",
            1, "'Sab�as que el laurel es un buen condimento para cocidos y asados?.",
            1, ":se duerme en los laureles.",
       }));
       
   objeto=new(ARMA+"baston");
   objeto->move(this_object());
   objeto=new(ARMADURA+"capa");
   objeto->move(this_object());
   TO->init_equip();
}/*setup*/
