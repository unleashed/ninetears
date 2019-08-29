/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("goblin");
   add_alias("cautivo");
   add_alias("Cautivo");
   set_short("Goblin Cautivo");
   set_long("   Ante ti tienes un horrible goblin.  Humea un vapor "
            "de sudor sucio y nauseabundo. Te lanza una fea sonrisa  "  
            "como si nada le importara a pesar de su situacion."
	    "\n\n");
   set_main_plural("Cautivos");
   set_gender(1);
   set_race("goblin");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(2,"oro");
   clone_object("/baseobs/weapons/dagger.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, ":muestra sus afilados dientes.",
     1, "' Algun dia nos veremos en distintas circunstancias,y entonces...",
     1, ":te sonrie con desprecio y aversion.",
 
  }));
 
  load_a_chat(25, ({
     1, ":te sisea algo incomprensible.",
     1, ":clama sangre.",
     1,"'Hare con tu piel una alfombra para este nuevo hogar.",
 
  }));
}
