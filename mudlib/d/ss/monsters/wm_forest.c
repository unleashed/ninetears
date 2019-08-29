#define MONSTER "obj/monster"
#define ARMORY "obj/handlers/armoury"
#define HOSPITAL "/d/ss/monsters/wm_forest"

inherit "std/room";

int *forest_chance, forest_tot_chance;
string *forest_monsters;


object get_monster(string type)
{
   object ob, ob2;
   int temp, rand, loop;
   
   if(!forest_monsters)
      {
      forest_monsters =
      ({
            "badger", "hornet", "kenku", "snake", "owlbear",
            "bugbear", "beetle", "hunter", "centipede", "bear",
            "kobold", "animal", "hermit", "spider","stirge"
       });
   }
   if(!forest_chance)
      {
      forest_chance =
      ({
            10, 5, 10, 10, 5,
            5, 5, 5, 10, 5,
            10, 10, 5, 2, 3
       });
      forest_tot_chance = 100;
   }
   switch(type)
   {
      case "forest":
      rand = random(forest_tot_chance - forest_chance[sizeof(forest_chance) - 1]);
      temp = 0;
      loop = 0;
      while(rand > temp)
      temp += forest_chance[loop++];
      ob2 = get_monster(forest_monsters[loop]);
      ob2->add_move_zone("forest");
      ob2->add_property("monster_type", type);
      return ob2;
     case "beetle":
      ob = clone_object(MONSTER);
      ob->set_name("beetle");
      ob->add_alias("beetle");
      ob->add_adjective("stag");
      ob->add_adjective("large");
      ob->set_short("a large stag beetle");
      ob->set_main_plural("stag beetles");
      ob->set_race("beetle");
      ob->set_level(4+random(5));
      ob->set_wimpy(0);
      ob->set_long("This is a large stag beetle.\n");
      ob->load_chat(2,
         ({
               1, ":crawls away from you.\n",
               1, ":lowers its horn and crawls fast towards you.\n",
               1, ":moves a boulder twice its size.\n",
          }));
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->add_property("monster_type", type);
      return ob;
     case "centipede":
      ob = clone_object(MONSTER);
      ob->set_name("centipede");
      ob->set_short("giant centipede");
      ob->add_adjective("giant");
      ob->add_adjective("black");
      ob->set_main_plural("centipedes");
      ob->add_move_zone("swamp");
      ob->set_long("A giant black centipede.\n");
      ob->set_aggressive(1);
      ob->join_fights("A centipede gleefully crawls into combat.\n");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->set_race("snake");
      ob->set_level(1+random(3));
      ob->set_wimpy(0);
      ob->add_property("monster_type", type);
      return ob;
     case "bear":
      ob = clone_object(MONSTER);
      ob->set_name("bear");
      ob->set_al(-30);
      ob->set_short("black bear");
      ob->add_alias("bear");
      ob->add_adjective("black");
      ob->set_main_plural("black bears");
      ob->set_long("It's one of those black bears that are so common.\n");
      ob->join_fights("A bear bounces into the combat fray.\n");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->set_race("bear");
      ob->set_level(3+random(2));
      ob->set_wimpy(0);
      ob->add_property("monster_type", type);
      return ob;
     case "badger":
      ob = clone_object(MONSTER);
      ob->set_name("badger");
      ob->set_short("badger");
      ob->set_race("badger");
      ob->set_class("badger");
      ob->set_level(3);
      ob->set_long("A badger is a canivorous burrowing animal.\n");
      ob->add_property("monster_type", type);
      return ob;
     case "kobold":
      ob = clone_object(MONSTER);
      ob->set_name("kobold");
      ob->add_adjective("ugly");
      ob->set_race("kobold");
      ob->set_al(-60);
      ob->set_aggressive(1);
      ob->set_level(random(2));
      ob->set_wimpy(0);
      ob->set_short("ugly kobold");
      ob->set_main_plural("ugly kobolds");
      ob->add_plural("ugly kobolds");
      ob->join_fights("An ugly kobold joins the fight.\n");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->set_long("The kobold is a cowardly, sadistic and ugly dog-like humanoid.\n");
      ob->load_a_chat(10,
         ({
               1, "@kick $hcname$"
          }));
      ob->add_property("monster_type", type);
      return ob;
     case "hornet":
      ob = clone_object(MONSTER);
      ob->set_name("hornet");
      ob->add_adjective("black");
      ob->set_race("monster");
      ob->set_short("black hornet");
      ob->set_level(3+random(3));
      ob->set_long("The black hornet is a fantastically large wasp.\n");
      ob->add_property("monster_type", type);
      return ob;
     case "kenku":
      ob = clone_object(MONSTER);
      ob->set_name("kenku");
      ob->set_short("kenku");
      ob->set_race("kenku");
      ob->set_level(4+random(3));
      ob->set_wimpy(0);
      /*
      ob->add_attack("beak", 0, 20, 90, 0, 0, "magic");
      ob->add_attack("beak", 0, 30, 90, 0, 0, "sharp-beak");
      */
      ob->set_long("The kenku is a bipedal, humanoid bird.\n");
      ob->load_chat(5,({1, ":looks eagerly at your purse.\n"}));
      ob->add_property("monster_type", type);
      return ob;
     case "snake":
      ob = clone_object(MONSTER);
      ob->set_name("snake");
      ob->set_short("snake");
      ob->set_al(-30);
      ob->set_main_plural("snakes");
      ob->add_alias("worm");
      ob->set_race("snake");
      ob->set_level(2+random(2));
      ob->set_wimpy(0);
      set_long("This is an agressive large snake.\n");
      ob->set_aggressive(1);
      ob->join_fights("A snake slithers into the fight.\n");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->add_triggered_action("regen", "death", HOSPITAL, "regen_after_death");
      ob->add_property("monster_type", type);
      return ob;
     case "owlbear":
      ob = clone_object(MONSTER);
      ob->set_name("owlbear");
      ob->add_alias("owl");
      ob->add_adjective("feroscious");
      ob->set_al(-80);
      ob->set_race("monster");
      ob->set_level(6+random(4));
      ob->set_wimpy(0);
      ob->set_short("owlbear");
      ob->set_plural("owlbears");
      // ob->add_attack("beak", 0, 30, 160, 0, 0, "sharp-beak");
      set_long("This is ferocious owlbear. It seems to be a crossbreed "+
         "between an owl and a bear.\n");
      ob->load_a_chat(20,
         ({
               1, ":roars loudly.",
               1, ":tries to bite you with its beak.",
          }));
      ob->add_property("monster_type", type);
      return ob;
     case "bugbear":
      ob = clone_object(MONSTER);
      ob->set_name("bugbear");
      ob->add_adjective("large");
      ob->set_race("bugbear");
      ob->set_level(3+random(3));
      ob->set_wimpy(0);
      ob->set_al(-50);
      ob->set_aggressive(1);
      ob->set_long("The bugbear is a large muscular humanoid.\n");
      ob->set_main_plural("bugbears");
      ob->set_short("bugbear");
      ob->load_a_chat(20,
         ({
               1, "'Grrrk ackrrr!\n",
               1, "'Grrrckkarr!\n",
               1, "@growl menacingly $hcname$",
          }));
      ob->add_move_zone("barracks");
      ob->add_property("monster_type", type);
      ARMORY->request_weapon("battle_axe",50+random(70))->move(ob);
      ob->join_fights("A bugbear exclaims: Rakk!.\n");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->init_equip();
      return ob;
     case "hunter":
      ob = clone_object(MONSTER);
      ob->set_name("hunter");
      ob->set_short("hunter");
      ob->add_adjective("forest");
      ob->set_main_plural("hunters");
      ob->set_long("Just a forest hunter.\n");
      ob->set_race("half-orc");
      ob->set_class("fighter");
      ob->set_level(5+random(10));
      ob->set_wimpy(0);
      ob->set_al(-100+random(201));
      ob->adjust_money(random(70), "copper");
      ob->load_chat(5,
         ({
               1, "@search",
               1, "@grunt",
               1, "'These forests are MY hunting grounds!",
               1, "'I hope you haven't come for a deer-hunt.",
               1, "'What are you doing here ?"
          }));
      ob->load_a_chat(30,
         ({
               1, "'Get outta here!",
               1, "@spit $lname$",
               1, "'Ughh!",
               1, "@drool"
          }));
	/* Commented this part out Fen, -CT.
      if(random(2))
    new("/baseobs/armours/leather")->move(ob);
      if(random(4))
         ARMORY->request_armour("soft leather cap", 70+random(30))->move(ob);
      if(random(2))
         ARMORY->request_weapon("short sword", 70+random(30))->move(ob);
      ob->add_property("monster_type", type);
      ob->init_equip();
	Commenting stops here for the equip, Fen  -CT */
      return ob;
     case "animal":
      ob = clone_object(MONSTER);
      ob->set_race("monster");
      ob->set_long("It's just an animal.\n");
      switch(random(6))
      {
        case 0:
         ob->set_name("dog");
         ob->set_short("forest dog");
         ob->add_adjective("forest");
         ob->set_main_plural("dogs");
         ob->set_gender(0);
         ob->set_level(-1+random(2));
         break;
        case 1:
         ob->set_name("boar");
         ob->set_short("wild boar");
         ob->add_adjective("wild");
         ob->set_main_plural("boars");
         ob->set_gender(0);
         ob->set_level(3+random(6));
         break;
        case 2:
         ob->set_name("deer");
         ob->set_short("deer");
         ob->set_main_plural("deer");
         ob->set_gender(0);
         ob->set_level(1);
         break;
        case 3:
         ob->set_name("crawler");
         ob->set_short("carrion crawler");
         ob->add_adjective("carrion");
         ob->set_main_plural("carrion crawlers");
         ob->set_gender(0);
         ob->set_level(2+random(3));
         break;
        case 4:
         ob->set_name("skunk");
         ob->set_short("skunk");
         ob->set_long("It looks very cute with its black'n white pelt.\n");
         ob->add_adjective("cute");
         ob->set_main_plural("skunks");
         ob->set_gender(0);
         ob->set_level(1);
         break;
        case 5:
         ob->set_name("stag");
         ob->set_short("mighty stag");
         ob->add_adjective("mighty");
         ob->set_main_plural("mighty stags");
         ob->set_gender(1);
         ob->set_level(3+random(2));
         break;
         }
      ob->add_property("monster_type", type);
      ob->set_wimpy(0);
      return ob;
     case "hermit":
      ob = clone_object(MONSTER);
      ob->set_name("hermit");
      ob->set_race("human");
      ob->set_level(3+random(7));
      ob->add_alias("man");
      ob->set_al(10);
      ob->set_wimpy(10);
      ob->adjust_money(random(100),"copper");
      ob->set_short("hermit");
      ob->set_long("This is one of the loners who wander the forests of the "+
         "Forgotten Realms.\n");
      ob->add_property("monster_type", type);
      return ob;
     case "spider":
      ob = clone_object(MONSTER);
      ob->set_name("spider");
      ob->add_adjective("huge");
      ob->set_race("spider");
      ob->set_level(2+random(2));
      ob->set_short("a huge spider");
      ob->set_main_plural("spiders");
      ob->add_triggered_action("bing2", "event_death", HOSPITAL, "death");
      ob->set_long("This is a huge spider. Wonder if it's poisonous.\n");
      ob->add_property("monster_type", type);
      return ob;
     case "stirge":
      ob = clone_object(MONSTER);
      ob->set_name("stirge");
      ob->add_adjective("fast");
      ob->set_race("stirge");
      ob->set_al(-20);
      ob->set_short("a stirge");
      ob->set_level(1);
      ob->set_long("The stirge is a mosquito-like bird.\n");
      ob->add_property("monster_type", type);
      return ob;
      default:
      ob = clone_object(MONSTER);
      ob->set_name("failure");
      ob->set_short("failure");
      ob->set_long(file_name(previous_object()));
      ob->set_level(1);
      return ob;
   }
}

void regen_after_death()
{
   object ob, dest;
   string nam;
   
   nam = (string)previous_object()->query_property("monster_type");
   dest = (object)previous_object()->query_property("start location");
   if (!dest)
      return ;
   ob = get_monster(nam);
   dest->add_monster(previous_object(), ob);
   call_out("do_move", 10, ({ ob, dest }) );
}

void do_move(mixed *junk)
{
   if(junk[0])
      junk[0]->move(junk[1]);
}

void death()
{
   call_out("do_pick_up", 0, previous_object());
}

void do_pick_up(object ob)
{
   ob->init_command(":loots the corpse.\n");
   ob->init_command("get all from corpses");
   ob->run_away();
}





