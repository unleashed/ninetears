
#include "/w/barthleby/path.h"
inherit "/obj/monster.c";


object sombra,arma;
void setup()
{
   set_name("cazador");
   set_short("Cazador de Mu-Bai");
   set_main_plural("Cazadores de Mu-Bai");
   add_plural("cazadores");
   set_long("Es un diestro cazador de Mu-Bai, gobernador de Noella, que se pasea por el bosque "
   "cazando animales para llevar a la mesa de su se�or, aunque a la vez "
   "tambi�n es un fiel servidor del mismo.\n");
   set_al(-500);
   set_gender(1);
   set_random_stats(15,18);
   set_guild_ob("/std/guilds/rogues/assassin");
   set_race_ob("/std/races/human");
   load_a_chat(10,
   ({
      1, "'morir�s cuando sientas mi pu�al en tu coraz�n!",
      1, ":mueve habilmente su pu�al para parar tu estocada",
      1, ":te finta !.",
      1, "'Bastardo que haces en estas tierras! Entregare tu cabeza al gobernador!",
   }));
   arma=clone_object(ARMA+"daga_cazador", 1);
   arma->move(TO);
   add_clone(ARMADURA+"cuero", 1);
   add_clone(ARMADURA+"manto", 1);
   adjust_money(random(30), "silver");
   init_equip();
   set_level(10+random(5));
}
