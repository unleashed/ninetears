// Guardian de la puerta de Gorband

//#include "path.h"

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
   set_guild_ob("/std/guilds/warriors/paladin");
   set_wimpy(0);
   set_random_stats(15, 18);
   set_cha(14+random(6));
   set_con(11+roll(3,2));   
   set_str(19+random(10)); /* Fuerza extrema de los guerreros humanos :) */
                           /* 19 == 18/10 .................. 28 == 18/00 */
   set_level(15+random(10));
   
   set_long("Es uno de los guardianes de la puerta de Gorband. Parece muy fuerte, "
            "osea que no pienses mucho en atacarle. Va fijandose en la "
            "gente que entra y sale de la ciudad para ver si son "
            "delincuentes.\n");

   set_aggressive(0);
   load_chat(30,
      ({
            1, "'No estar�s pensando en entrar en la prisi�n, verdad?",
            1, "'M�tete en problemas y estar� encantado de ayudarte a entrar. Je Je Je!!!",
            1, ":vigila tus movimientos.",
       }));
   load_a_chat(50,
      ({
            1, "'Morir�s por haber intentado entrar aqu�!",
            1, "'A mi la guardia!.",
            1, ":hace una se�al a sus compa�eros para tratar de rodearte.",
       }));
       
   add_clone(ARMA+"bastarda",1);
   add_clone(ESCUDO+"corporal",1);
   add_clone(ARMADURA+"placas",1);
   ::init_equip();
}/*setup*/

void attack_by(object atacante)
{
    atacante->add_timed_property("guardias_gorband", 1, 60);
   ::attack_by(atacante);
}/*attack_by*/
