/*  File upgrade by Grimbrand 2-11-96                                   */

#include "path.h"
inherit "obj/monster";
 
void init() { ::init(); }

void setup() {
   set_name("medio-elfo");
   add_alias("cautivo");
   add_alias("elfo");
   set_short("Medio-elfo Cautivo");
   set_long("   Es un medio elfo.  Esta delgado y tiene el aspecto "
            "enfermizo por el tratamiento recibido durante su cautividad " 
            "Ha jurado volver a su patria algun dia, y matarte a ti "
            "podria ser un buen principio."
            "\n\n");
   set_main_plural("Cautivos");
   set_gender(1);
   set_race("half-elf");
   set_guild("fighter");
   set_random_stats(10,15);
   set_aggressive(0);
   set_level(10);
   set_max_hp(44);
   set_wimpy(0);
   set_al(0);
   set_kill_xp(631);
   adjust_money(3,"oro");
   clone_object("/baseobs/weapons/dagger.c")->move(this_object());
   this_object()->init_equip();
 
  load_chat(30,({
     1, "' Mi dios Timion ha de lanzar su ira contra todos vosotros!",
     1, "' Los torpes duergar nunca series una raza ganadora.",
     1, ":te sonrie ironico con desden.",
 
  }));
 
  load_a_chat(25, ({
     1, "'No es muy noble pelearse con los debiles y oprimidos.",
     1,"'prueba mi daga, ya que tanto insistes.",
 
  }));
}
