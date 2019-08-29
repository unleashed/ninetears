/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("enano");
   add_alias("Cautivo");
   set_short("Enano Cautivo");
   set_long("   Es un enano de aspecto robusto.  Como la mayoria "
            "de enanos, este parece fuerte y pendenciero.  Te mira "
            "con desprecio y odio absoluto."
            "\n\n");
   set_main_plural("Cautivos");
   set_gender(1);
   set_race("enano");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(random(10), "plata");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move_(this_object());
   this_object()->init_equip();
 
  add_language("comun");
  do_command("speak comun");
  load_chat(30,({
     1, "' Los Duergas no saben con quien se meten al encerrarme aqui.",
     1, ":te sonrie en una mueca de desprecio.",
     1, "'Tu eres apenas un pasatiempo para mi.",
 
  }));
 
  load_a_chat(25, ({
     1, ":jura hacerte sufrir lentamente.",
     1, "'Aaah, me gustaria que nos vieramos en igualdad de condiciones.",
     1, ":te escupe a los pies.",
     1,"'No he soportado esta prision para ser muerto por un pelele.",
 
  }));
}
