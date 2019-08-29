inherit "/obj/monster";
#include "../path.h"

int contador=0;

void event_enter(object ob, string mensaje, object donde)
{
   if ((int)ob->query_timed_property("enemigo_antipaladines"))
   {
      if (ob->query_dead())
      {
         do_command("acusar "+ob->query_cap_name());
         do_command("'Eso le pasa a los enemigos de Oskuro.");
      }
      else
      {
        this_object()->attack_ob(ob);
        do_command("say Nosotros no olvidamos a nuestros enemigos.\n");
         do_command("say Por la gloria de Oskuro MUERE!!!!!!.\n");
      }
   }
   ::event_enter(ob, mensaje, donde);
}/*event_enter*/


void setup()
{
        set_name("jinete");
        set_short("Jinete Negro");
        set_long("Este fornido Humano pertenece a un grupo de misteriosos, "
        "humanos que aparecieron recientemente en el Camino Real, aseguran "
        "servir a Oskuro y que el fin esta cerca y que solo aquellos que "
        "adoren a Oskuro sobreviviran, ya que los que no lo hagan, le "
        "serviran para siempre bajo el aspecto de horrendos no-muertos.\n");
        add_alias("humano");
        add_alias("jinete");
        set_main_plural("Jinetes Negros");
        add_plural("negros");
        add_plural("jinetes");
        set_random_stats(17,19);
        set_str(28);
        set_gender(1);
        set_guild("fighter");
        set_guild_ob("/std/guilds/warriors/antipaladin");
        set_race_ob("/std/races/human.c"); 
        adjust_money(5,"silver");
        set_heart_beat(1);
          add_clone("/d/anduar/objetos/armadura",1);
          add_clone("/d/anduar/objetos/escudo",1);
          add_clone("/d/anduar/objetos/lanza",1);
        init_equip();
        set_level(30);
        set_al(760);
    load_chat(40,({
        1,":te observa a traves de su visor.",
        1,":limpia su lanza.",
    }));
    load_a_chat(60,({
        1,"'vas a morir maldito.",
        1,"'gloria a oskuro!!.",
    }));
}

void hacer_montura()
{
        int i;
        object ob;
        tell_room(environment(TO),TO->query_short()+" silba gracilmente y su "
        "montura aparece de entre los matorrales.\n"); 
        ob=clone_object("/d/anduar/npcs/montura");
        ob->move(environment(TO));
         ob->do_command("follow jinetes");
         ob->do_command("protect jinetes");
         TO->do_command("protect caballos");
        return 1;
}

void heart_beat()
{
        if (contador == 7)
        {  
          hacer_montura();
          contador = 8; 
        }
        else if(contador > 7)
                contador = 8;
              else
                contador++;
        ::heart_beat();
        return 1;
}
void attack_by(object atacante)
{
   atacante->add_property("enemigo_antipaladines", 1);
   ::attack_by(atacante);
}/*attack_by*/
