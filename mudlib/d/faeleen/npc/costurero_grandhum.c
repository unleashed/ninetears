#include "../path.h"
inherit "/obj/monster";
void setup()
{
object objeto;
set_name("costurero");
set_short("Klot, el costurero");
set_gender(1);
add_plural("costureros");
set_main_plural("costureros");
set_race("human");
set_wimpy(0);
set_random_stats(15, 18);
set_str(18);
set_level(18+random(3));
set_long("\n Ves a Klot un costurero afeminado que es el"
      " duenyo de esta prestigiosa tienda de tela, lo ves"
      "preocupado por que hace tiempo que nadie va a su tienda. \n\n");
adjust_money(random(5)-1, "oro" );
load_chat(45,
        ({
        1,"' Va comprar algo, forastero?",
        1,"' Me va mal ultimamente el negocio.",
        1," Klot se pone a coser.",
        }));
   add_clone(OBJ+"daga_afilada.c",1);
   add_clone(OBJ+"camisa_pretyus.c",1);
   add_clone(OBJ+"pantalon_pretyus.c",1);
   init_equip();
   }
