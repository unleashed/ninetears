#include "./../path.h"

inherit "obj/monster";

void setup()
{
  set_name("oswaldo");
  add_alias("inmortal");
  add_alias("segurata");  
  set_short("Oswaldo, el guardaespaldas");
  set_long("Este tio es el encargado de velar por la seguridad de God el Inmortal.\n");
  set_random_stats(50,80);
  set_str(100);/*para ajustar la fuerza a tu placer*/
  set_dex(110);/*lo mismo en dex...como ves es set_<lo_que_sea>para poner lo que a ti te guste.*/
  set_cha(100);
  set_level(70+random(5));/*ponedlo depues de los stats..pa ke rule bien si no calcula la vida antes del nivel y puede salir con muy poca.*/
  set_main_plural("seguratas");
  set_align(0);
  set_gender(1);
  load_chat(100,
            ({
              1,":Limpia sus espadas retadora con gran enfasis.\n",
              1,"'la vida es dura..no se como me ganastes antes..pero ahora sera distinto..te atreves?\n",
              1,":acaricia a su perro pidiendole algo de calma.\n",
             }));
  load_a_chat(100,
              ({
               1,"'A este tio no lo mataran!!!!\n",
               1,"'muedele fuerte la pierna Ambrosio!!!!\n",
               1,"'no te dejare salir vivo si tocas a mi Senyor!!!!\n",
             }));//este  chat lo dice en medio del combate.
  add_known_command("slice");
  add_known_command("surge");
  TO->add_clone("/w/leviathan/uviu/obj/espada_hielo.c",2);
  this_object()->init_equip();
  add_hated("race",({"duergar","drow","goblin","orco"}));
  set_aggressive(0);

}

//Esta funcion se activa cuando algo o alguien entra en la room
void event_enter()
{
   say(TO->query_name()+" dice: Ambrosio ataca!!!! Por fin un reto decente!!!.\n");
   TP->attack_by(TO);
}


//ya sabeis mirad los comandos ke hallan pa probarlos.
void init()
{
 ::init();
 add_attack_spell(55,"surge",({"/d/gremios/comandos/surge.c","surge",0}));
 add_attack_spell(70,"slice",({"std/commands/slice.c","slice",1}));
}

