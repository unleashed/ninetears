/*  Updated and corrected by Grimbrand 2-2-96                             */

#include "path.h"
inherit "obj/monster";

void init() {
    ::init();
    add_action("do_listen","escuchar");
    call_out("first_approach",0,this_player());
}

void setup() {
    set_name("barog");
    add_alias("duergar");
    add_alias("master");
    set_join_fights();
    set_main_plural("masters");
    set_short("barog, Maestro de expediciones de superficie");
    set_long("   Barog Blackfist es el maestro de expediciones de  "
      "superficie.  El ensenya a los Duergar  en la segunda fase "
      "de estudios sobre las variadas  criaturas qe habitan  la "
      "superficie.  El mismo se ha encontrado varias veces "
      "a muchas de esas enormes bestias.\n"
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
    clone_object("/baseobs/weapons/war_hammer.c")->move(this_object());
    clone_object("/baseobs/armours/chainmail.c")->move(this_object());
    init_equip();
}

void first_approach(object ob) {
    if((int)ob->query_level() !=2) 
    {
        do_command("say Vamos!... fuera de aqui ,no tengo tiempo  "
          "que perder contigo.\n"
          "\n");
    }
    if((int)ob->query_level() == 2) 
    {
        do_command("say  Era hora de que  te decidieras a venir!\n");
    }
}

int do_listen(string STR) {
    int lv;
    object me = this_player();
    lv = (int)me->query_level();

    if(STR == "barog") 
    {
        if(lv == 2) 
        {
            do_command("say HUMM, asi que te gustaria saber algo "
              "sobre el mundo de superficie,no? Bien, tal vez tenga "		
              "algo para ti entonces.......heeemmmm\n"
              "Laa superficie es un sitio endiablado e impredecible, "
              "de veras.  Alli, cada dia, una gran orbita de danyina luz "
              "nace en el cielo, cegandote e hiriendote con rabia a cada "
              "movimiento.  Es un milagro que las criaturas que viven "
              "arriba consigan resistir sin ser consumidas por tal mal.\n"
              "Entonces,cuando al fin la bola de fuego se esconde tras el "
              "horizonte, otra nueva aparece a reemplazarla, pero esta "
              "no es realmente de fuego,y nunca es la misma sino que  " 
              "cambia una y otra vez...");
            do_command("say Bien,es una tierra estranya,a cada sitio "
              "que vas es diferente.En algunos sitios hay plantas  de  "
              "gran altura ,que crecen gracias a la luz de fuego del cielo, "
              "y  sitios donde solo veras un terreno plano cubierto de "
              "arena ardiente. Pero incluso peor que eso, hay un sitio  "
              "donde lo unico que puedes ver es agua por todas partes. "
              "Tengo entendido que se puede  viajar sobre ese agua,  "
              "pero es como una invitacion a morir,ya que siempre "
              "intenta arrastrarte hacia sus profundidades.\n" 
              "Ahora, para tus practicas,he retornado de la superficie  "
              "trayendo conmigo algunas criaturas que he capturado. " 
              "Ve por la puerta del Noroeste y comprueba como se "
              "sufre en  la superficie ,si estas lo suficientemente loco "
              "para querer ir.");

            if(this_player()->query_guild_name() == "abathor")
            {
                if((int)this_player()->query_property("BAROG_GOT")!=1)
                {
                    this_player()->add_property("BAROG_GOT", 1);
                    this_player()->adjust_money(3,"platino");
                    return 1;
                }
            }
            return 1;
        }
        do_command("say No tengo motivos para hablarte!\n");
        return 1;
    }
    return 0;
}

