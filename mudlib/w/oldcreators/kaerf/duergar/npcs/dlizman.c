/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("Hombre-lagarto");
   add_alias("cautivo");
   add_alias("Cautivo");
   add_alias("lagarto");
   add_alias("hombrelagarto");
   set_short("Hombre-lagarto Cautivo");
   set_long("   Estas ante un hombre-lagarto.  Ha ido poco a poco "
            "prosperando en un amargo desprecio a los duergar que ha "
            "hervido en su corazon desde que comenzo su cautividad. "
            "Chasquea su larga cola y te sisea a la cara retandote "
            "a atacarle para asi poder cumplir su venganza."
            "\n\n");
   set_main_plural("Cautivos");
   set_gender(1);
   set_race("lizard-man");
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
     1, "' Quissssiera volver a ver el ssssssssssol.",
     1, "'Losssss  duergar desssssconocen el placer de calentarssse al ssssol.",
 
  }));
 
  load_a_chat(25, ({
     1, ":te golpea con un latigazo de su cola.",
     1, "Ahaaa. quieressss aprender a luchar de verdad? obssservame a mi entoncesssssss.",
     1, ":saca su lengua bifida en rapido movimiento.",
     1, "'Ssssere libre al fin... ssssolo debo matarte, lo cual ssssera un placer.",
 
  }));
}
