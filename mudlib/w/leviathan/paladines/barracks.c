/* North and South exits made selective by Grimbrand on 26 January 1993 */
/* Tightened up by Fengarance sometime in June 1995  */
 
inherit "/std/guildroom";
#include "path.h"
 
object knight1, knight2, sign;
object CREATE();
 
void setup () 
   {set_short("Sala de entrenamiento\n\n");
    set_long("Guild de los Paladines.\n\n");
    sign = add_sign("Un gran cartel cuelga de una pared en un lateral del la estancia "
            "es posible que te interese leerlo.\n", 
            "            ________________________________________  \n"+
            "           |\\______________________________________/| \n"+
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
   
    add_exit ("sur", "/w/leviathan/fighter/hall", "corridor");
    add_exit ("norte", "/w/leviathan/fighter/armory", "corridor");
    add_exit ("sureste","/room/recibidor.c","corridor");
    modify_exit("norte", ({"function", "knight_test"}));
    modify_exit("sur", ({"function", "knight_test"}));
    
    set_guild("warriors/paladin");
    add_specialization("paladin");
   }
 
void reset() 
   {int i;
    if(!knight1)
       {knight1 = CREATE();
        knight1->move(this_object());
       }
    if(!knight2)
       {knight2 = CREATE();
        knight2->move(this_object());
       }
   }
 
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
    ob->set_guild("paladin");
    ob->set_level(75 + random(5));
    ob->set_gender(1+random(2));
    ob->set_thac0(5);
    ob->set_str(25);
    ob->set_dex(18);
    ob->move(this_object());
     ob->set_max_hp(700);
     clone_object("/baseobs/weapons/long_sword")->move(ob);
    clone_object("/baseobs/armours/templanza")->move(ob);
    clone_object("/baseobs/armours/fullplate")->move(ob);
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
 
int knight_test()
   {
     if((string)(this_player()->query_guild_ob()) !=
	"/d/gremios/guerreros/paladin")
          {notify_fail("El dios de los paladines se interpone en tu camino "+
                "denegandote la entrada.\n\n");
           tell_room(environment(this_player()),
                this_player()->query_cap_name()+" es empujado hacia fuera por uno "+
                "de los caballeros al haber sido descubierto intentando entrar al guild.\n\n",
                ({this_player()}));
           return 0;
          }
    return 1;
   }
