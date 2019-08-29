// Viajero. Gestur
#include "/w/barthleby/path.h"
inherit "/obj/monster";

void setup()
{
   object objeto;
   set_al(-150);
   set_gender(random(2)+1);
   if (query_gender()==1)
   {
      set_name("viajero");
      set_short("viajero cansado");
      set_main_plural("viajeros cansados");
      add_alias("cansado");
      add_plural("cansados");
      add_plural("viajeros");
      set_long("Es un viajero con aspecto de estar cansado. Tal vez est� "
               "tratando de llegar a Noella a pie.\n");
   }
   else
   {
      set_name("viajera");
      set_short("viajera cansada");
      set_main_plural("viajeras cansadas");
      add_alias("cansada");
      add_plural("cansadas");
      add_plural("viajeras");
      set_long("Es una viajera con aspecto de estar cansada. Tal vez est� "
               "tratando de llegar a Noella a pie.\n");
   }
   add_alias("humano");
   add_plural("humanos");
   set_race_ob("/std/races/human");
   set_wimpy(15);
   set_random_stats(12, 18);
   set_cha(12+random(5));
   set_level(4+random(15));
   set_aggressive(0);
   load_chat(30,
      ({
            1, "'No recuerdo que la �ltima vez me costase tanto trabajo llegar a Noella.",
            1, ":resopla de cansancio.",
       }));

   objeto=new(ARMA+"baston");
   objeto->set_name("baston");
   objeto->add_alias("baston");
   objeto->add_alias("bast�n");
   objeto->set_short("bast�n para andar");
   objeto->set_main_plural("bastones para andar");
   objeto->add_plural("bastones");
   objeto->set_long("Es un bast�n usado por las personas con dificultades "
                    "para andar o simplemente para cansarse menos. Por "
                    "su forma puede ser utilizado como arma.\n");
   objeto->set_genero(0);
   objeto->move(this_object());
   objeto=new(ARMADURA+"capa");
   objeto->move(this_object());
   this_object()->init_equip();
   add_move_zone("sendas");
}/*setup*/
