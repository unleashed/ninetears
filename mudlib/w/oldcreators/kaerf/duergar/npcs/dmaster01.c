/*   Text upgrade by Grimbrand 2-1-96                              */

#include "path.h"
inherit "obj/monster";

void init() {
    ::init();
    add_action("do_listen","escuchar");
    call_out("first_approach",0,this_player());
}

void setup() {
    set_name("helden");
    add_alias("duergar");
    add_alias("maestro");
    set_join_fights();
    set_main_plural("maestros");
    set_short("Helden, Maestro de Minas");
    set_long("\n     Helden Hewen es el Maestro de la escuela de minas. "
      "El es a quien todos los nuevos duergar deben venir a ver para poder "
      "iniciar sus entrenamientos.\n"
      "\n");
    set_race("duergar");
    set_guild("fighter");
    set_level(35 + random(10));
    set_thac0(6);
    set_max_hp(600);
    set_max_gp(1000);
    adjust_gp(1000);
    set_heart_beat(1);
    set_gender(1);
    set_al(35);
    set_random_stats(20, 28);
    adjust_money(3,"platino");
    clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
    clone_object("/baseobs/armours/chainmail.c")->move(this_object());
    init_equip();
}

void first_approach(object ob) {
    if((int)ob->query_level() > 1) {
        do_command("say Ya has acabado tus pruebas en esta zona, asi que "
          "vete y no mires atras.\n");
    }
    if((int)ob->query_level() == 1) {
        do_command("say Ahh, un nuevo recluta.  Pasa por favor, comenzaremos "
          "tu entrenamiento ahora mismo.\n");
    }
    if((int)ob->query_level() == 0) {
        do_command("say A donde vas muchacho? necesitas ir al guild y avanzar "
          "antes de poder comenzar a entrenarte.\n");
    }
}

int do_listen(string STR) {
    int lv;
    object me = this_player();
    lv = (int)me->query_level();

    if(STR == "helden")
    {
        if(lv == 1)
        {
            do_command("say Muy bien, por donde empiezo? Supongo que tu "
              "preferiras que no te aburra con un largo discurso sino "
              "una rapida y clara explicacion, no?\n\n"
              "   Bien , pues estas de suerte. yo tampoco tengo ganas de "
              "aburrir a los estudiantes, asi que esto es lo que debes "
              "hacer.  Toma este pico, y ve por esa puerta al oeste. "
              "Tras la puerta encontraras algunos cuartos con rocas "
              "esparcidas.  Tendras ke picar las rocas hasta convertirlas "
              "en bloques que podamos usar.\n\n"
              "   Ahora bien, eres libre de salir cuando creas que tu progreso "
              "es satisfactorio... pero si rompes el pico que te he dado! en ese "
              "caso, deberias abandonar y mejor nos eliminas las ratas, ya que un "
              "duergar que no es capaz de conservar su herramienta no es digno de "
              "recibir mis ensenyanzas.\n\n"
              "VAMOS!  el tiempo es oro.....\n"
            );
            if(!this_player()->query_property("got_pick"))
                clone_object(ITEMS+"pick")->move(this_player());

            if(this_player()->query_guild_name() == "Abbadon")
            {
                if((int)this_player()->query_property("got_pick")!=1)
                {
                    this_player()->adjust_money(2,"platino");
                    this_player()->add_property("got_pick", 1);
                    return 1;
                }
            }
            else
            {
                if((int)this_player()->query_property("got_pick")!=1)
                {
                    this_player()->adjust_money(2,"platino");
                    this_player()->add_property("got_pick", 1);
                    return 1;
                }
            }
            return 1;
        }
        do_command("say No tengo mas tiempo que perder contigo!\n");
        return 1;
    }
    return 0;
}
