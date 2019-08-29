/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("orco");
   add_alias("cautivo");
   add_alias("Cautivo");
   set_short("Orco Cautivo");
   set_long("   De pie ante ti ves un orco babeando.  Lleva ya en  "
            "cautividad mucho tiempo y esta consumido por el odio "
            "que alberga en su interior.  Nada le gustaria mas  "
            "que romperte la cabeza con sus propias manos."
            "\n\n");
   set_main_plural("Cautivos");
   set_gender(1);
   set_race("orc");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(random(3), "plata");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, "' Piensas quedarte ahi todo el dia plantado?",
     1, ":te huele con cara de asco.",
     1, "'No tendria ni para empezar contigo.",
 
  }));
 
  load_a_chat(25, ({
     1, ":enrojece de ira.",
     1, ":babea de placer ante la posibilidad de matarte.",
     1, ":escupe una baba pegajosa que acaba en tu pelo.",
     1,"'Esta noche al fin podre cenar caliente, carne fresca!",
 
  }));
}
