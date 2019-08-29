/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("humano");
   add_alias("cautivo");
   add_alias("Cautivo");
   add_alias("humano");
   set_short("Humano cautivo");
   set_long("   Es un hombre humano.  Ha sido muy golpeado "
            "durante su cautividad, puedes notarlo al verle "
            "moverse con dificultad. Su resolucion es admirable, "
            "tipico en su raza, y ahora esta buscando la forma "
            "de saciar su hambre de venganza y salir de aqui, "
            "te mira como quien encuentra lo que buscaba."
            "\n\n");
   set_main_plural("Cautivos");
   add_plural("humanos");
   set_gender(2);
   set_race("human");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(1,"oro");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, "' Al fin puedo vengarme, preparate a morir.",
     1, "' Ningun castigo de los duergas afecta a mi espiritu.",
 
  }));
 
  load_a_chat(25, ({
     1, "'Bien! veamos que sabes hacer.",
     1, ":te escupe a la cara.",
     1,"'.Cuando acabe contigo usare tu cuerpo como escudo para salir de aqui",
 
  }));
}
