#include "/w/barthleby/path.h"

inherit "/obj/monster";



void setup() {
      set_name("mercader");
      set_short("mercader de Noella");
      add_alias("noella");
      add_alias("Noella");
      set_race_ob("/std/races/human");
      add_alias("human");
      set_main_plural("mercaderes de Noella");
      add_plural("mercaderes");
      add_plural("humanos");
      set_al(-10);
      set_random_stats(8, 17);
      set_cha(8+random(8));
     set_level(15+random(5));
set_gender(1);
      set_wimpy(5);
      adjust_money(random(50),"silver");
      set_long("Es un mercader que parece haber recorrido una gran distancia "
      "para dirigirse a Noella, lo m�s seguro que venga a vender alguna "
      "exotica mercancia y comprar otras para venderlas en su ciudad de "
      "origen.\n");
      load_chat(10, ({ 1, "'Disculpe caballero sabr�as vos si la ciudad de "
      "Noella queda muy lejos de este lugar?",
      1, "'Ser�a usted tan amable de indicarme una posada en la cual "
      "alojarme en Noella?",
      1, "'Esta nueva ruta es m�s segura que la antigua, ya que los ladrones "
      "no abundan tanto como en aquella.",
   }));
   add_clone(ARMADURA+"capa",1);
   init_equip();
}/*setup*/
