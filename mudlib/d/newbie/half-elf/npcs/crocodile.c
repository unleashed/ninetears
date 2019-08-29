inherit "/obj/monster.c";

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

void setup()
{
   set_name("crocodile");
   set_short("crocodile");
   set_long("A huge crocodile floating in the water.\n");

    set_main_plural("crocodiles");
    add_plural("crocodiles");
    set_gender(0);    
    set_str(17);

    set_level(3);
    set_max_hp(5);
    set_wimpy(0);
    load_chat(20,({
      1,"@snaps it teeth at you",
      1,"@yawns tiredly",
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
            "headbutt" : ({ AN+" gives "+DN+" a BONK\n",
                            "You give "+DN+" a big BONK on the head\n",
                            AN+" gives you a big BONK on the head, You feel invalid\n" })
           ]);
}
           
