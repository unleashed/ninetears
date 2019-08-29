#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("Lel�");
   set_short("Viejo Lel�");
   add_alias("viejo");
   add_alias("Lele");
   add_alias("lel�");
   add_alias("lele");
   set_al(-100);
   set_gender(1);
   set_main_plural("viejos Lel�");
   add_plural("Lel�s");
   add_plural("lel�s");
   add_plural("lel�s");
   add_plural("viejos");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   set_random_stats(15, 18);
   set_str(25);
   set_dex(18);
   set_con(18);
   set_cha(15+random(3));
   set_level(20+random(10));
   set_long("Ante ti se encuentra uno de los humanos m�s viejos de la regi�n. Se trata de "
   "un viejo escu�lido y maloliente con una imperecedera sonrisa en la boca y una enorme y "
   "rojiza nariz.\n");

   adjust_money(random(10), "silver");
   set_aggressive(0);
   load_chat(50,
      ({
            1, "'El vino de mi local es afrodisiaco!.",
            1, "'Los clientes habituales tienen m�s hijos de lo normal.",
            1, "'No deber�as irte sin haber probado alguna de mis exquisitas bebidas.",
            1, ":se bebe un TumbaDios.",
       }));

   objeto=new(ARMA+"baston");
   objeto->move(this_object());
   objeto=new(ARMADURA+"capa");
   objeto->move(this_object());
   TO->init_equip();
}
void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_noella", 1, 300);
   ::attack_by(atacante);
}/*attack_by*/
