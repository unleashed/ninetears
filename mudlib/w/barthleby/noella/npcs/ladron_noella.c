#include "/w/barthleby/path.h"

inherit "/obj/monster";

#define ROBAR "/std/commands/steal.c"

void setup()
{
   set_name("ladron");
   set_short("ladr�n");
   add_alias("ladron");
   set_al(700);
   set_gender(1);
   set_main_plural("ladrones");
   add_plural("ladrones");
   
   set_random_stats(12,16);
   set_cha(12+random(4));
   set_guild_ob("/std/guilds/rogues/thief");
   set_race_ob("/std/races/human");
   set_level(8+random(6));
   set_long("Es uno de los muchos ladrones que se encuentran en esta zona. "
            "Est� aqu� probablemente para intentar robarle el dinero al "
            "primero que pase. No tiene pinta de conseguir mucho dinero al "
            "cabo del d�a a juzgar por lo delgado que est�.\n");
   load_a_chat(20,
   ({
      1, "'Lamentareis profundamente haber osado atacarme.",
      1, "'Muere, bastardo!!!.",
   }));
   add_clone(ARMA+"pu�al", 1);
   add_clone(ARMADURA+"cuero", 1);
   add_clone(ARMADURA+"capa", 1);
   adjust_money(random(6), "gold");
   TO->init_equip();
}

void init()
{
   ::init();
   add_known_command("robar");
}

void event_enter(object quien, string mensaje, object donde)
{
   if (!quien->query_corpse())
      call_out("robar", random(5), quien);
   ::event_enter(quien, mensaje, donde);
}

void robar(object quien)
{
   if (quien)
   {
      if (environment(quien)!=environment(this_object())) return;
      if (quien->query_name()=="ladron") return;
      if (!interactive(quien)) return;

      ROBAR->steal("coins a "+quien->query_name(), this_object());
   }
}
