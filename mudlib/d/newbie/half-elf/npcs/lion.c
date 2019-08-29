inherit "/obj/monster.c";

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

void setup()
{
   set_name("lion");
   set_short("lion");
   set_long("A a huge lion, he has a nasty grin..\n");

    set_main_plural("lions");
    add_plural("lions");
    set_gender(0);    
    set_str(7);

    set_level(3);
    set_max_hp(5);
    set_wimpy(0);
    load_chat(20,({
      1,"@growls at you",
      1,"@sneers at you",
      1,"@looks at you with hunger",
    }));
}

mapping valid_attack()
{
   return([
          "punch" : ({ AN+" pierces "+DN+"'s eye with its claw\n",
                       "You pierce "+DN+"'s eye with your claw\n",
                       AN+" pierces your eye with its claw\n" }),
          "kick"  : ({ AN+" bites "+DN+"'s ear with the claw\n",
                       "You bite "+DN+"'s ear with the claw\n",
                       AN+" bites your ear with the claw\n" }),
           "knee" : ({ AN+" moves fastly around "+DN+" causing small cuts on the feet with its claws.\n",
                       "You move fastly around "+DN+" making small cuts on the feet with your claws\n",
                       AN+" moves fastly around you causing small cuts on your feet with its claws\n" }),
            "headbutt" : ({ AN+" gives "+DN+" a BONK\n",
                            "You give "+DN+" a big BONK on the head\n",
                            AN+" gives you a big BONK on the head, You feel invalid\n" })
           ]);
}
           
