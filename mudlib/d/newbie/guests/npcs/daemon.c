inherit "obj/monster";
 
void init()
  {::init();
       add_attack_spell( 33, "cone of cold",
       ({ "/std/spells/wizard/conecold.c", "cast_spell", 1 }) );
     add_attack_spell(33, "burning hands",
     ({ "/std/spells/wizard/burnhand.c", "cast_spell", 1}));
   call_out("approach", 0, this_player());
   }
void setup ()
 { set_name("daemon");
   add_alias("drow");
    add_alias("Daemon");
     set_race("drow");
    set_main_plural("Daemons");
   add_plural("drows");
   set_short("Daemon");
    set_long("The young drow in flowing robes before you returns "
             "your look of curiousity as he busies himself with "
             "tasks around the room.  As an apprentice to the "
             "powerful devilish wizard who summonned this forest "
             "to the center of the earth, he moves quickly from "
             "one task to another.  Already you notice that he has "
             "the confidence of one who has started to harness his "
             "own magical power.\n");
   set_race("drow");
   set_level(15+random(5));
//set_kill_xp(7000);



   set_gender(1);
   set_wimpy(0);
set_align(400);
set_ethics(-500);

    //set_ac(10*10);
set_guild_ob("/std/guilds/wizards/drowwizard");
        add_property("magical", 50);
     add_property("fire", 50);
   set_random_stats(12,20);
   set_str(12+random(5));
   set_dex(12+random(5));
adjust_money((random(15)),"gold");


   set_con(10+random(3));
   load_chat(30, ({
        1, ":purses his lips.",
       1, ":slowly combines two vials, coughing from the smoke that results.",
1,"'I trust you have enjoyed your stay in our forest.",
        1, "'The wizard Sapphrus will one day claim the whole surface world "
"for the underworld just as he has taken this small forest.",
        1,"'I am indentured and indebted to the evil wizard Sapphrus.  You "
           "will find few mages more evil than he.",
        1,":laughs manically.",
        1,"'To this day, the surface idiots still wonder what act of nature "
           "destroyed their forest.\n",
        1,"'Tis I who monitor the forest, ensuring that it continues to grow "
          "more evil and uglier with every day.",
        1,":smiles proudly.",
        1,"'This forest is the wizard Sapphrus' greatest accomplishment.."
"but will hardly be his only one."
 
        }));
   load_a_chat (30,({
       1,"'You dare fight me,  who is in charge of the entire forest? Fool!",
       1,":points out the foolishness of your hasty decision to fight.",
       1,":rubs his hands in anticipated glee.",
       1,"'You shall be such better sporting game than a mere porcupine.",
       1,":laughs with unabashed enjoyment at your trepidation.",
       1,":accuses you of being not only weak, but foolhardy as well.",
       1,":uncaps a bottle filled with brown liquid.  You suddenly feel ill "
       "as the scent reaches your nostrils."
       }));
  }
 

