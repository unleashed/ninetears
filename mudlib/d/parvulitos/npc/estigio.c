#include "./../path.h"

inherit "obj/monster";

void setup()
{
  set_name("estigio");
  add_alias("inmortal");
  set_short("Estigio, el retante");
  set_long("Un viejo inmortal que se encarga de comprobar quien esta preparado para la vida de creador y quien no"
           ". Es el encargado de decirte como salir de aqui.\n "
           "de que no se le paga bien.\n");
  set_random_stats(50,80);
/*  set_race_ob("immortal");
  set_guild_ob("/std/guilds/fighter");*/
  set_str(100);/*para ajustar la fuerza a tu placer*/
  set_dex(110);/*lo mismo en dex...como ves es set_<lo_que_sea>para poner lo que a ti te guste.*/
  set_level(90+random(11));/*ponedlo depues de los stats..pa ke rule bien si no calcula la vida antes del nivel y puede salir con muy poca.*/
  set_main_plural("Estigios");
  set_align(0);
  set_gender(1);
  set_join_fight_mess("Estigio se une al reto con gran placer.\n");
  load_chat(100,
            ({
              1,":Limpia sus espadas retadora con gran enfasis.\n",
              1,"'si quieres que te diga como salir de la zona de aprendices solo tienes que hacerme un more.\n",
              1,"'la vida es dura..no se como me ganastes antes..pero ahora sera distinto..te atreves?\n",
              1,"'al norte hay una armeria, ve y coje el equipo y nos retaremos.\n",
              1,":acaricia a su perro pidiendole algo de calma.\n",
             }));
  load_a_chat(100,
              ({
               1,"'Esta vez ajustaremos cuentas!!!!\n",
               1,"'muedele fuerte la pierna Ambrosio!!!!\n",
               1,"'no te dejare salir vivo de esta sala!!!!\n",
             }));//este  chat lo dice en medio del combate.
  add_known_command("slice");
  add_known_command("surge");
  TO->add_clone(OBJ+"espada_m2",2);
  TO->add_clone(OBJ+"cuero_m2",1);
  this_object()->init_equip();
}

//Esta funcion se activa cuando algo o alguien entra en la room
void event_enter(object objeto, string mess,object objeto2)
{
 if (TP->query_property("reto"))
   {
   say(TO->query_name()+" dice: Ambrosio ataca!!!! Por fin un reto decente!!!.\n");
   TP->attack_by(TO);
   }
 else
   {
   write(" Buenas tardes noble inmortal, preparado para otro duelo?.\n");
   }
}


//ya sabeis mirad los comandos ke hallan pa probarlos.
void init()
{
 ::init();
 add_attack_spell(95,"surge",({"/d/gremios/comandos/surge.c","surge",0}));
 add_attack_spell(70,"slice",({"/d/gremios/comandos/slice.c","slice",1}));
}


//Para salir nada mas simple ke decir 3 veces asin como pone sastamente:decir No hay nada como el hogar!! 
//eso decirlo en la sala del retorno
