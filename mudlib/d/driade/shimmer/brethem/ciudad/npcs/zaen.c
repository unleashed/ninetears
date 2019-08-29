/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

void setup() {
      object objeto;
      set_name("Zaen");
      set_short("Zaen el bibliotecario ciego");
      set_al(-60);
      set_gender(1);
      set_main_plural("varios hombres parecidos a Zaen");
      add_alias("zaen");
      add_alias("bibliotecario");
      add_alias("ciego"); 
      add_plural("bibliotecarios");
      set_race_ob("/std/races/elfo");
      set_level(25+random(5));
      set_wimpy(10);
      set_random_stats(12, 18);
      set_long("Zaen es un viejo elfo encargado de la biblioteca de Brethem, a pesar "
               "de su ceguera total se dice que es capaz de utilizar su mente para leer los libros "
               "lleva cientos de anyos ocupandose de esta biblioteca, organizando los tomos y documentos "
               "y ayudando a los que vienen en busca de alguno a encontrarlos o aconsejarlos.\n\n");




      add_clone(BRETHEM + "equipo/baston.c",1);
      add_clone(BRETHEM + "equipo/camisa.c",1);
      add_clone(BRETHEM + "equipo/pantalon.c",1);
      ::init_equip();


      set_aggressive(0);
      adjust_money(random(250), "silver");

      load_a_chat(40,({
        1, "'Bienvenido a la Biblioteca de Brethem. Aqui podras encontrar sabiduria y lectura.",
        1, ":taquetea su mesa buscando algo.",
        1, "'Si buscas algun libro avisame, me los conozco todos casi de memoria.",
        1, ":coge un libro y se pone a �mirarlo?. �un ciego? que cosas",
      }));

      ::init_equip();
}


void attack_by(object atacante)
{
   atacante->add_timed_property("guardias_brethem", 1, 300);
   return ::attack_by(atacante);
}