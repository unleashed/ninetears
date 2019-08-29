// Bandido. Gestur 8-10-97

#include "path.h"
inherit "/obj/monster";
int oculto;
#define SOMBRA "/std/commands/shadows/hide.c"
object sombra;
int i;

void setup()
{
   set_name("bandido");
   set_short("bandido");
    set_al(1900);
   set_gender(1);
   set_main_plural("bandidos");
   add_plural("bandidos");
   set_level(5+random(6));
   set_random_stats(12,17);
   set_cha(12+random(5));
   set_guild_ob("/std/guilds/rogues/assassin");
   set_race_ob("/std/races/goblin");
   set_long("Es un bandido de los muchos que se pueden encontrar en esta "
            "zona. Se gana la vida asaltando a las personas y robandole "
            "todas sus pertenencias. Son peligrosos, sobre todo en las "
            "emboscadas.\n");
   load_chat(20,
   ({
      1, "'Dadme vuestro dinero o tendre que quitaros la vida",
      1, ":mira el tamanyo de tu bolsillo.",
   }));
   add_clone(BASEWEAPONS+"dagger", 1);
   add_clone(BASEARMOURS+"leather", 1);
   add_clone(BASEARMOURS+"cloak", 1);
   adjust_money(random(30), "silver");
   if (!random(2))
   {
      sombra=clone_object(SOMBRA)->setup_shadow(this_object());
      add_property("oculto",1);
   }
   else oculto=0;
   init_equip();
}

void init()
{
   add_timed_property("guardias_anduar", 1, 4000000);
   ::init();
}

void event_enter(object quien, string mensaje, object donde)
{
//   if (query_property("oculto")) call_out("emboscada2", 3, quien);
   if (quien->query_corpse()) call_out("coger1", 2);
   ::event_enter(quien, mensaje, donde);
}

void coger1()
{
   i=10;
   do_command("coger todo de cuerpos");
   call_out("coger2", 8);
}

void coger2()
{
   do_command("get all");
   call_out("run_away", 2);
}

/*void correr()
{
   if (i--)
   {
      run_away();
      call_out("correr", 8);
   }
}*/

void emboscada2(object quien)
{
   call_out("emboscada", 1, quien);
}

void emboscada(object quien)
{
   if (environment(quien)!=environment(this_object()) ||
   !query_property("oculto")) return;
   if (quien->query_name()=="bandit" || quien->query_corpse()) return;
   if (random(20)>=quien->query_cha())
   {
      remove_property("oculto");
      tell_object(quien, "Un bandido oculto entre la vegetacion se abalanza "
      "sobre ti por la espalda y notas como te clava algo punzante.\n");
      tell_room(environment(this_object()), "Un bandido oculto entre "
      "la vegetacion se abalanza sobre "+quien->query_cap_name()+
      ", clavandole algo que parece una daga por la espalda.", quien);
      sombra->dest_hide_shadow();
      quien->adjust_hp(-10-random(25));
      attack_ob(quien);
   }
   else
   {
      oculto=0;
      tell_object(quien, "\nConsigues ver a tiempo un bandido intentando "
      "atacarte por la espalda y paras su ataque.\n");
      tell_room(environment(this_object()), "Un bandido intenta atacar "
      "a "+quien->query_cap_name()+" por la espalda, pero consigue "
      "parar el ataque.\n", quien);
      quien->attack_ob(this_object());
   }
}
 
