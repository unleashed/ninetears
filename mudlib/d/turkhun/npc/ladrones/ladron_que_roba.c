inherit "/obj/monster";
#define ROBAR "/std/commands/steal.c"

void setup()
{
   set_name("ladron");
   set_short("ladron");
   set_al(700);
   set_gender(1);
   set_main_plural("ladrones");
   add_plural("ladrones");
   set_random_stats(12,16);
   set_cha(12+random(4));
   set_dex(19);
   set_guild_ob("/std/guilds/rogues/thief");
   set_race_ob("/std/races/human");
   set_race("Humano");
   set_level(18+random(6));
   set_long("Te encuentras frente a un experto ladron que ha sabido "
   "subsistir a la difil vida de una persona de su condicion gracias "
   "a su experiencia en este arte.\n");
   set_max_hp(200);
   load_a_chat(20,
   ({
      1, "'Lamentareis profundamente haber osado atacarme.",
      1, "'Muere, bastardo!!!.",
   }));
   add_clone("/baseobs/weapons/dirk", 1);
   add_clone("/baseobs/armours/leather", 1);
   add_clone("/baseobs/armours/cape", 1);
   adjust_money(random(6), "gold");
   init_equip();
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
  
      ROBAR->steal("coins a "+quien->query_name(), this_object());
   }
}
