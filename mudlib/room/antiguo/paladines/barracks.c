
/* North and South exits made selective by Grimbrand on 26 January 1993 */
/* Tightened up by Fengarance sometime in June 1995  */
 
inherit "/std/guildroom";
#include "path.h"

object guildmaster;
object knight1, knight2, sign;
object CREATE();
 
void setup () 
{
    set_short("%^BOLD%^WHITE%^Sala de entrenamiento\n\n%^RESET%^");
    set_long("%^BOLD%^WHITE%^Sala de entrenamiento\n\n%^RESET%^");
    sign = add_sign("Un gran cartel cuelga de una pared en un lateral del la estancia "
            "es posible que te interese leerlo.\n", 
            "           ________________________________________  \n"+
            "           |______________________________________/|| \n"+
            "           ||                                      || \n"+
            "           ||        Bienvenido al guild!          || \n"+
            "           ||                                      || \n"+
            "           ||   -- Escribe 'join' para ser un      || \n"+
            "           ||      miembro del guild.              || \n"+
            "           ||   -- Para mas informacion sobre los  || \n"+
            "           ||      paladines, teclea 'info'.       || \n"+
            "           ||   -- Para avanzar niveles teclea     || \n"+
            "           ||      'advanzar'.                     || \n"+
            "           ||   -- Para saber cuanta experiencia   || \n"+
            "           ||      necesitaras para avanzar otro   || \n"+
            "           ||      nivel, teclea 'coste'.          || \n"+
            "           ||                                      || \n"+
            "           ||______________________________________|| \n"+
            "           |/______________________________________\\| \n\n");
   
    set_light (60);
   
    add_exit ("sur", "/room/paladines/hall", "corridor");
    add_exit ("norte", "/room/paladines/armory", "corridor");
    add_exit ("sudeste","/room/paladines/recibidor.c","corridor");
    modify_exit("norte", ({"function", "knight_test"}));
    modify_exit("sur", ({"function", "knight_test"}));
    
    set_guild("guerreros/paladin");
//    add_specialization("paladin");
    add_clone("/baseobs/guildmasters/patric",1);
    add_clone("/baseobs/guildmasters/grunico",1);
    set_teaching_person("patric");
}

void reset()

{int i;

        if (!guildmaster) {
                guildmaster = clone_object("/baseobs/guildmasters/patric.c");
                guildmaster->move(this_object());
        }

/*    if(!knight1)
       {knight1 = CREATE();
        knight1->move(this_object());
       }
    if(!knight2)
       {knight2 = CREATE();
        knight2->move(this_object());
       }
  */ }
 
/*
object CREATE()
   {object ob;
    ob = clone_object("/obj/monster");
    ob->set_name("Caballero");
    ob->set_short("Caballero");
    ob->set_main_plural("caballeros");
    ob->add_alias("caballero");
    ob->add_plural("caballeros");
    ob->set_long("A large stern looking fighter.  He looks "+
                 "sternly at you.\n");
    ob->set_race("human");
    ob->set_guild("/d/gremios/guerreros/paladin");
    ob->add_attack_spell(100, "cargar", ({"/d/gremios/comandos/carga", "carga",0,1}));
    ob->add_attack_spell(100, "desarmar", ({"/d/gremios/comandos/disarm", "desarmar",0,1}));
    ob->add_attack_spell(70, "curar heridas criticas",
    ({"/d/gremios/hechizos/paladin/curar_heridas_criticas", "cast_spell",3,0}));
    ob->add_attack_spell(100, "disipar magia",
    ({"/d/gremios/hechizos/paladin/disipar_magia", "cast_spell",3,0}));
    ob->add_attack_spell(60, "plegaria",
    ({"/d/gremios/hechizos/paladin/plegaria", "cast_spell",3,0}));
    ob->add_attack_spell(60, "bendicion",
    ({"/d/gremios/hechizos/paladin/bendicion", "cast_spell",3,0}));
    ob->set_level(75 + random(5));
    ob->set_gender(1+random(2));
    ob->set_thac0(5);
    ob->set_str(25);
    ob->set_dex(18);
    ob->move(this_object());
    ob->set_max_hp(1500);
    ob->set_hp(1500);
//
//    ob->add_loved("guild","/d/gremios/guerreros/paladin");
//    ob->set_aggressive(1);

    clone_object("/baseobs/weapons/long_sword")->move(ob);
    clone_object("/baseobs/shields/corporal")->move(ob);
    clone_object("/baseobs/armours/fullplate")->move(ob);
    clone_object("/baseobs/armours/amulet")->move(ob);
    clone_object("/baseobs/armours/bracers")->move(ob);
    clone_object("/baseobs/armours/ring")->move(ob);
    clone_object("/baseobs/armours/helmet")->move(ob);



    ob->do_command("equip");
    return ob;   
   }
 
void dest_me ()
   {if(knight1)
        knight1->dest_me();
    if(knight2)
        knight2->dest_me();
    if(sign)
       sign->dest_me();
   }
*/ 
int knight_test()
   {


        if (!guildmaster) {
                notify_fail("Te aprovechas de que no esta Patric para colarte en el gremio de Paladines.\n");
                return 1;
        }
        else
        {
                if((string)(this_player()->query_guild_ob()) != "/d/gremios/guerreros/paladin")
                {
                        notify_fail("Patric te impide la entrada al gremio.\n");
                        return 0;
                }
                else
                {
                        return 1;
                }

	}



   }
