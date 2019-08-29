#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
{
   object objeto;
   set_name("Popi");
   set_short("Popi L'Abrah");
   set_al(250);
   set_gender(1);
   set_main_plural("popis");
   add_plural("abrahs");
   set_wimpy(0);
   set_race_ob("/std/races/human");
   set_random_stats(15, 18);
   set_str(25);
   set_dex(18);
   set_con(18);
   set_cha(15+random(3));
   set_level(20+random(10));
   set_long("Era el cliente m�s habitual del local hasta que muri� su anterior propietario y debido "
   "a su inevitable amistad con �l y a que ya no recordaba donde viv�a ni de donde era, fue nombrado "
   "�nico heredero de la taberna. Algo que el acepto de muy buen grado, viendo en ello la posibilidad "
   "de beber cuanto quisiese.\n");

   adjust_money(random(100), "silver");
   set_aggressive(0);
   load_chat(50,
      ({
            1, "'Los trobadores son el alma del local. Hace tiempo yo era uno de ellos... creo.",
            1, "'Si vienes aqu� a protestar por el ru�do del local recuerda que no deber�as haber constru�do tu casa tan cerca.",
            1, "'No me mires con esa carita, o pagas o no hay bebidas!.",
            1, "'Hip!! dec�as? Hip!!.",
	    1, ":limpia la barra."
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
   return ::attack_by(atacante);
}
