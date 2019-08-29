// Guardian de la prision de Gorband

#include "/w/barthleby/path.h"

inherit "/obj/monster";

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("guardias_gorband"))
   {
      if (ob->query_dead())
      {
         do_command("laugh "+ob->query_cap_name());
         do_command("'Eso te pasa por atacar a nuestros hombres.");
         ob->remove_timed_property("guardias_gorband");
      }
      else
      {
         this_object()->attack_ob(ob);
         do_command("say Eh, tu! Bastardo! Fuera de aqu�!!!!!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}/*event_enter*/

void setup()
{
   object objeto;
   set_name("guardian");
   set_short("guardi�n de Gorband");
   set_al(-150);
   set_gender(1);
   set_main_plural("guardianes de Gorband");
   add_alias("guardi�n");
   add_alias("guardian");
   add_alias("guardia");
   add_plural("guardias");
   add_plural("guardianes");
   add_plural("guardianes de Gorband");
   add_alias("human");
   set_race_ob("/std/races/human");
   set_race("humano");
   set_guild_ob("/std/guilds/warriors/fighter");
   add_move_zone("prision");
   set_wimpy(0);
   set_random_stats(15, 18);
   set_cha(14+random(6));
   set_con(11+roll(3,2));   
   set_str(19+random(10)); /* Fuerza extrema de los guerreros humanos :) */
                           /* 19 == 18/10 .................. 28 == 18/00 */
   set_level(15+random(10));
   
   set_long("Es un guardi�n de la prisi�n de Gorband Ab-Trabasir. Parece "
   "fuerte y disciplinado o sea que no pienses mucho en atacarle. Su cometido es "
   "vigilar tanto la prisi�n como los reclusos que en ella cumplen condena.\n");

   set_aggressive(3);
   load_a_chat(80,
      ({
            1, "'Morir�s por haber entrado aqu�!",
            1, "'A mi la guardia!.",
            1, ":hace una se�al a sus compa�eros para tratar de rodearte.",
       }));

   add_clone(ARMA+"larga",1);
   add_clone(ESCUDO+"mediano",1);
   add_clone(ARMADURA+"mallas",1);
   add_clone(ARMADURA+"yelmo",1);
   TO->init_equip();
}/*setup*/

void attack_by(object atacante)
{
    atacante->add_timed_property("guardias_gorband", 1, 60);
   ::attack_by(atacante);
}/*attack_by*/
