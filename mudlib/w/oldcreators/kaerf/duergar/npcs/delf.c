/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("elfa");
   add_alias("cautiva");
   set_short("elfa cautiva");
   set_long("   Tienes ante ti una joven mujer elfa.  Sus rasgos  "
            "delicados se transforman cuando te mira de forma airada. "
            "Su aspecto parece fragil pero blande una pesada espada "
            "que parece manejar con soltura.  Notas un ardiente deseo "
            "mirandola, pero una chispa mortal en sus ojos te detiene."
            "\n\n");
   set_main_plural("Cautivas");
   set_gender(2);
   set_race("elf");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(3,"oro");
   clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
   this_object()->init_equip();
 
  add_language("comun");
  do_command("speak comun");
  load_chat(30,({
     1, "' Los duergar nunca seran una raza superior.",
     1, "' Tu gente ya no estara segura en este lugar nunca mas.",
     1, "' Apenas representas peligro para mi.",
 
  }));
 
  load_a_chat(25, ({
     1, ":te apunta con el dedo, y luego senyala la salida.",
     1, ":esquiva habilmente tu torpe embestida.",
     1, "'hmmm... el valiente duergar ataca a los debilitados prisioneros,orgulloso?",
     1, ":se mofa en tus narices,confiada en su habilidad y fuerza.",
     1, "' No he luchado mil batallas para acabar mis dias en esta prision.",
 
  }));
}
