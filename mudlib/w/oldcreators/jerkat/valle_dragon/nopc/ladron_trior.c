// Ladron. Jerkat 20-03-02

inherit "/obj/monster";
#define ROBAR "/d/gremios/comandos/steal.c"

void setup()
{
   if (random(2)==1)
   	{
   	set_name("ladron");
   	set_short("ladron");
   	add_alias("Ladron");
   	set_al(700); // hay que buscar el malo y tal
   	set_gender(1);
  	set_main_plural("ladrones");
   	add_plural("Ladrones");	
   	}   		
   else
   	{
   	set_name("ladrona");
   	set_short("ladrona");
   	add_alias("Ladrona");
  	set_al(700); // hay que buscar el malo y tal
   	set_gender(0);
  	set_main_plural("ladrones");
  	add_plural("Ladrones");
   	add_plural("ladronas");
   	add_plural("Ladronas");
   	}
   set_random_stats(12,16);
   set_cha(14+random(4));
   set_guild_ob("/d/gremios/picaros/thief");
   set_race_ob("/std/races/human");
   set_level(8+random(6));
   set_long("Es uno de los muchos ladrones que se encuentran en el mercado. "
            "Esta aqui probablemente para intentar robarle el dinero al "
            "primero que pase. No tiene pinta de conseguir mucho dinero al "
            "cabo del dia a juzgar por lo delgado que esta.\n");
   load_a_chat(20,
   ({
      1, "'Lamentareis profundamente haber osado atacarme.",
      1, "'Muere, bastardo!!!.",
   }));
   /*
   add_clone(BASEWEAPONS+"dirk", 1);
   add_clone(BASEARMOURS+"leather", 1);
   add_clone(BASEARMOURS+"cape", 1);
   */
   adjust_money(random(10), "gold");
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
      if (!interactive(quien)) return;

      ROBAR->steal("coins a "+quien->query_name(), this_object());
   }
}
