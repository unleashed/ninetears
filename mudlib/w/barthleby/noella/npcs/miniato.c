#include "/w/barthleby/path.h"

inherit "/obj/monster";

void setup()
  {
   set_name("miniato");
   set_short("Miniato");
	add_alias("miniato");
   set_long("Este es Miniato, uno de los habitantes m�s populares de Noella. Viste una especie "
   "de traje confeccionado a base de sacos viejos. Su largo pelo negro y sucio apenas deja ver "
   "una peque�a parte de su cara. Es un personaje que puede resultar bastante simp�tico, "
   "aunque en ocasiones puede llegar a ser muy pesado.\n");
   set_main_plural("Miniatos");
   add_plural("miniatos");
   set_race_ob("/std/races/human");
   set_gender(1);
   set_random_stats(17,18); 
   set_str(18+random(10));
   set_max_hp(300);
   set_hp(300);
   set_wimpy(95);
   set_level(10+random(10));
   add_property("electrical",50);
   add_property("cold",50);
   add_property("fire",50);
   add_property("acid",50);
   add_property("air",50);
   add_property("stone",50);
   add_property("poison",50);
   add_property("magical",50);
   add_move_zone("noella");
   set_kill_xp(0);
   set_aggressive(0);
   load_chat(80,
   ({
      1, "'Os sobra alguna moneda?",
      1, "'Necesito unas monedas para comer algo.",
      1, "'Ser�a usted tan amable de comprarme algo de comer?",
      1, "'Por favor no se vaya, atiendame un minuto.",
      1, "'La juventud de ahora no tiene respeto por nada.",
      1, "'Dame algo o atente a las consecuencias!",
      1, ":muestra sus bolsillos vac�os.",
      1, ":pone sus manos sobre su estomago mirandote con cara de pena.",
      1, ":baja su cabeza y dice algo ininteligible.",
   }));
   load_a_chat(80,
   ({ 1, "'Yo no quer�a! Yo no quer�a!!!",
      1, "'Esto no quedar� as�!!!",
      1, ":esta cada vez m�s y m�s nervioso.",
   }));

add_clone(ARMADURA+"manto", 1);
TO->init_equip();
}

void event_enter(object quien, string mensaje, object donde)
{
   if (quien->query_corpse()) call_out("coger1", 2);
   ::event_enter(quien, mensaje, donde);
}

void coger1()
{
   do_command("coger todo de cuerpos");
   call_out("coger2", 8);
}

void coger2()
{
   do_command("get all");
   call_out("run_away", 4);
}


