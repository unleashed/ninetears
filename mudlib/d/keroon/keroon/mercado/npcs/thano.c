  // Valar Enero 2003
   //Posadero
#include "../../../path.h"
   inherit "/obj/civil";
   
void setup() {
set_name("Thano");
set_short("Thano");
set_gender(1);
set_main_plural("Thano y compa�ia");
add_alias("thano");
add_alias("posadero");
add_plural("posaderos");
set_race_ob("/std/races/duergar");
set_level(25+random(5));
set_wimpy(10);
set_random_stats(12, 18);
set_long("El rudo propietario de la taberna del Pollo Cojo. Y tiene muy mala leche.\n");
set_aggressive(0);
adjust_money(random(5), "oro");

add_clone("/w/aprendizaje/jamonero",1);
init_equip();

}

void attack_by(object atacante)
{
atacante->add_timed_property("guardias_keeron", 1, 600);
return ::attack_by(atacante);
}
