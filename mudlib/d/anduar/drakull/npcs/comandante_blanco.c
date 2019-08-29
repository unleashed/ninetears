// Comandante de la orden plateada (C) 1999 Aokromes

#include "path.h"
#define SLICE   "/std/commands/slice.c"

inherit "/obj/monster";
static int ene=0;

void setup() {
      set_name("Comandante de la orden plateada");
      add_alias("comandante");
      add_alias("comandantes");
      add_alias("guardian");
      add_alias("guardianes");
      add_alias("plateado");
      add_alias("plateados");
      set_genero(1);
      set_short("Comandante plateado");
      set_main_plural("Comandantes plateados");
      set_race("human");
      set_random_stats(16, 18);
      set_level(50);
      set_max_hp(1000);
      set_str(38);
      set_cha(18);
      add_clone(OBJETOS+"great_twohanded_sword.c",1);
      add_clone(OBJETOS+"placa_plata",1);
      add_clone("/baseobs/armours/cloak",1);
      set_long("Sus manos duras como la roca denotan haber participado en "
        "miles de batallas, el puesto de comandante no lo logra cualquiera "
        "no basta solo ser habil con las armas para ser comandante de un "
        "ejercito tambien hay que ser un habil estratega, y un buen lider \n");
      adjust_money(({random(50), "silver", random(10), "gold"}));
      this_object()->init_equip();

      load_chat(10,
         ({
               1, "'He luchado en las mas grandes batallas junto a Arturo ",
               1, "'Mi trabajo es proteger a mi Lord.",
               1, "'No pongais las manos encima de mi lord o os las vereis "
                  "conmigo y con mis hombres.",
          }));
      load_a_chat(30,
         ({
               1, "'He jurado proteger a mi Lord aun a coste de mi vida.",
               1, "'Nunca deberias de haber desafiado a un caballero de la "
                  "rosa plateada .",
          }));
} /* setup() */

void init()
{
   ::init();
   command("protect dorado");    
   command("protect lord");
}

void attack_by(object atacante)
{
   ene++;
   SLICE->slice(atacante->query_name(),TO);
::attack_by(atacante);
TP->add_timed_property("lord_killer",450);
}
