/*  File upgraded by Grimbrand 2-11-96                                  */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("drow");
   add_alias("cautivo");
   add_alias("Cautivo");
   add_alias("hembra");
   set_short("Drow Cautivo");
   set_long("   Ves una hembra drow ,sin casa, que ha sido capturada "
            "en alguna incursion.  El hecho de que no tenga una casa "
            "denota que no es una drow muy poderosa. Si ella hubiera "
            "nacido noble, la habrian entrenado para ser una princesa "
            "de Lolth, convirtiendola en un peligroso adversario."
            "\n\n");
  set_main_plural("Cautivos");
  set_gender(2);
  set_race("drow");
  set_guild("fighter");
  set_random_stats(10,15);
  set_aggressive(0);
  set_level(10);
  set_max_hp(44);
  set_wimpy(0);
  set_al(0);
  set_kill_xp(631);
adjust_money(4+random(4),"plata");
  clone_object("/d/newbie/duergar/weapons/sword.c")->move(this_object());
  this_object()->init_equip();
 
  add_language("comun");
  do_command("speak comun");
  load_chat(50,({
  1, "' Los Duergar deberan hacer mucho mas que esto para quebrar mi espiritu.",
 
  }));
 
  load_a_chat(60, ({
     1, ":clama a su dios Lolth que lance las llamas del infierno sobre ti.",
     1, ":graciosamente esquiva tu torpe ataque.",
     1, "'Aaah, asi que luchas contra el debilitado y oprimido, muy noble.",
     1,":se mofa de ti, confiada en su fuerza.",
 
  }));
}
