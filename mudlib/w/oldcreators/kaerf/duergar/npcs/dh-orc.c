/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("medio-orco");
   add_alias("cautivo");
   add_alias("orco");
   add_alias("Cautivo");
   set_short("Medio-Orco Cautivo");
   set_long("   Es un medio-orco.  Tiene la cabeza de un orco y el "
            "cuerpo de un humano, has oido de esta raza que son muy "
            "resueltos en cualquier situacion. Ha estado en cautividad "
            "mucho tiempo, y nada le gustaria mas que causarte dolor."
            "\n\n");
   set_main_plural("Cautivos");
   set_race("half-orc");
   set_gender(1);
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(9,"plata");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, "' Los duergar ni siquiera saben hacer bien las prisiones.",
     1, ":te mira de arriba abajo con disgusto.",
 
  }));
 
  load_a_chat(25, ({
     1, ":babea, disfrutando con la idea de matarte.",
     1, ":habilmente frusta tu ataque.",
     1,"'Si, necesitaba una buena pelea,uno se oxida en estas celdas.",
 
  }));
}
