/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/monster";

#define ROBAR "/std/commands/steal.c"


int oculto;
#define SOMBRA "/std/commands/shadows/hide.c"
object sombra;
int i;


void setup() {    
      set_name("ladron");
      set_short("ladron");
      set_main_plural("ladrones");
      add_plural("ladrones");
      set_random_stats(6, 18);

   set_guild_ob("/std/guilds/rogues/asesino");

   switch(random(10)){
     case 0:      
      set_race_ob("/std/races/human");      
      set_race("humano");
     break;
     case 1:      
      set_race_ob("/std/races/dwarf");      
      set_race("enano");
     break;
     case 2:      
      set_race_ob("/std/races/elf");      
      set_race("elfo");
     break;
     case 3:      
      set_race_ob("/std/races/lizard-man");      
      set_race("hombre-lagarto");
     break;
     case 4:      
      set_race_ob("/std/races/halfling");      
      set_race("halfling");
     break;
     case 5:      
      set_race_ob("/std/races/lizard");      
      set_race("hombre-lagarto");
     break;
     case 6:      
      set_race_ob("/std/races/drow");      
      set_race("drow");
     break;
     case 7:      
      set_race_ob("/std/races/orc");      
      set_race("orco");
     break;
     case 8:      
      set_race_ob("/std/races/goblin");      
      set_race("goblin");
     break;
     case 9:      
      set_race_ob("/std/races/duergar");      
      set_race("duergar");
     break;}

      set_long("Este es un ladron "+this_object()->query_race()+", no deja de echarle el ojo a "
               "los bolsillos de los que pasan por aqui, deberias tener ciudado con el.\n");
      adjust_money(1+random(10),"copper");

      set_level(5+random(3));

      do_command("speak common");
      load_chat(10, ({
        1, "'A ti aun no te he robado nunca, no?\n",
        1, ":parece que se ha enamorado de tu bolsillo, no le quita ojo.\n",
        1, ":intenta pasar desapercibido para robar a alguien.\n",
        1, ":esconde su daga.\n",
      }));
      load_a_chat(30, ({
        1, "'Mmm, me gusta eso que llevas!",
        1, "'Hay alguien detras tuya!",
        1, "'Si no me lo dan, lo tendre que robar.",
        1, ":intenta escabullirse por algun lado."
      }));

      add_clone(BRETHEM+"equipo/daga",1);
      add_clone(BRETHEM+"equipo/cuero",1);
      ::init_equip();
      
   if (!random(1))
   {
      sombra=clone_object(SOMBRA)->setup_shadow(this_object());
      add_property("oculto",1);
   }
   else oculto=0;


}

void event_enter(object quien, string mensaje, object donde)
{
   if (query_property("oculto")) call_out("emboscada2", 3, quien);

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




void emboscada2(object quien)
{
   call_out("emboscada", 1, quien);
}

void emboscada(object quien)
{
   if (environment(quien)!=environment(this_object()) ||
   !query_property("oculto")) return;
   if (quien->query_name()=="ladron" || quien->query_corpse()) return;
   if (random(20)>=quien->query_cha())
   {
      remove_property("oculto");
      tell_object(quien, "Un ladron oculto cerca se abalanza "
      "sobre ti por la espalda y notas como te clava algo punzante.\n");
      tell_room(environment(this_object()), "Un ladron oculto cerca"
      "se abalanza sobre "+quien->query_cap_name()+
      ", clavandole algo que parece una daga por la espalda.", quien);
      sombra->dest_hide_shadow();
      quien->adjust_hp(-10-random(25));
      attack_ob(quien);
   }
   else
   {
      oculto=0;
      tell_object(quien, "\nConsigues ver a tiempo un ladron intentando "
      "atacarte por la espalda para robarte y paras su ataque.\n");
      tell_room(environment(this_object()), "Un ladron intenta atacar "
      "a "+quien->query_cap_name()+" por la espalda para robarle, pero consigue "
      "parar el ataque.\n", quien);
      quien->attack_ob(this_object());
   }
}
 


