#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("Epos");
   set_short("Epos el pirata");
   set_al(250);
   set_gender(1);
   set_main_plural("eposes");
   add_plural("piratas");
   add_alias("epos");
   set_race_ob("/std/races/human");
   set_wimpy(0);
   set_random_stats(15, 18);
   set_str(25);
   set_dex(18);
   set_con(18);
   set_cha(15+random(3));
   set_level(20+random(10));
   set_long("Uno de los m�s grandes piratas y contrabandistas que surcaron los mares de anta�o. "
   "Se vi� envuelto en serios problemas con la justicia por culpa de oscuros asuntos que ya nadie "
   "recuerda y finalmente decidi� abrir esta taberna en Noella, cosa que no le impidi� seguir "
   "haciendo de las suyas.\n");

   adjust_money(random(100), "silver");
   set_aggressive(0);
   load_chat(50,
      ({
            1, "'Me he visto obligado a cambiarle el nombre varias veces al local para evadir impuestos.",
            1, "'Me encantaria volver a encontrarme con el viejo Kornell y tener ulgunas palabras acerca de mi barco.",
            1, "'Alto! No eres tu uno de los hijos de Kornell!.",
            1, "'Beber para recordar, beber para olvidar... beber es bueno para todos, incluso para mi bolsillo.",
	    1, ":limpia la barra."
       }));
       
   objeto=new(ARMA+"baston_a_dos_manos");
   objeto->move(this_object());
   objeto=new(ARMADURA+"manto");
   objeto->move(this_object());
   TO->init_equip();
}
void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_noella", 1, 300);
   ::attack_by(atacante);
}/*attack_by*/
