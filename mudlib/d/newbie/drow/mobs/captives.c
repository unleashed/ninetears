#include "path.h"  
  inherit "/obj/monster";
  
  void setup() {
    set_name("captive");
    set_random_stats (6,18);
    set_ethics(-1000);
    set_al (-500);
    set_wimpy(0);
    
    switch (random(6))
     {
     case 0:
      add_alias("dwarf");
      set_short("Dwarf Captive");
      set_long("   A squat dwarven female glares at you. The "
               "rags that once were her clothes are full of filth and "
               "stench. Although the chains still attached to her "
               "ankles attest that she is a prisoner of the drow, "
               "she looks at you with pride and pure disdain.\n");
      set_main_plural("captives");
      set_gender(2);
      set_race("dwarf");
      set_guild("fighter");
      adjust_con(1);
      adjust_dex(5);
      set_level(1+random(2));
      adjust_money(random(5),"silver");
add_clone(OBJ+"short_sword.c",1);
      this_object()->init_equip();
add_clone(ITEM+"shackles.c",1);
      add_language("dwarf");
      load_chat(20, ({
       1, ":sneers at you with hatred.",
       1, "'Have you no sense of decency?",
       1, ":looks you up, then, down, and then laughs uncontrollably.",
       1, ":smirks at you with only a glimmer of fear in her eyes.",
       1, ":gets a faraway look in her eyes.",
       1, "'You drow are good for nothing but ...well, nothing."
      }));

      load_a_chat(30, ({
       1, "'Oh, you big mean drow, able to fight half-dead "
          "prisoners!",
       1, "'I could beat you still chained to the wall!",
       1, ":puts her thumb on her nose and razzes you.",
       1, "'Ha! Are you sure you're using your weapons correctly, "
          "child?",
       1, ":laughs manically.",
       1,"'I've seen rocks that move faster than you!"
      }));
     break;
     
     case 1:
      set_level(3+random(2));
      add_alias("dwarf");
      set_short("Dwarf Captive");
  set_long("   Thin wrinkles of worry and fear line the small dwarf's "
           "face as he warily eyes you over and awaits further insult.  "
           "Torn rags, tied together, form some semblance of a garment. "
           "The bedraggled beard and hopeless eyes bespeak that the "
           "time this dwarf has spent here has worn him down greatly.\n");
      set_main_plural("Captives");
      set_gender(1);      
      set_race("dwarf");
      set_guild("fighter");
      set_aggressive(0);
      this_object()->init_equip();
      add_language("dwarf");
      load_chat(30,({
       1, ":shudders in horror.",
       1, ":stares blankly at your feet.",
       1, ":faints from fatigue and lack of food.",
       1, ":stands unsteadily, leaning on the walls for support.",
       1, ":looks around with eyes void of hope.",
       1, "'Kill me -- I have no power to live or fight any longer.",
       1, ":trembles from all he has endured.",
       1,":sighs with a broken spirit and heavy heart."
      }));
 
      load_a_chat(25, ({
       1, "'If this is the future of the drow race, the surface "
          "can rest easily.",
       1, ":breathes raspily, gasping for air.",
       1, ":screams in pain and clutches his heart.",
       1, "'My god, does the terror never end?",
       1, "'I have no spirit with which to fight you.",
       1,"'Leave me be.  I pose you no threat."
      }));
     break;
     
     case 2:
      set_level(1+random(3));
      add_alias("Captive");
      add_alias("elf");
      set_short("Elf Captive");
      set_long("   A slight elf with stooped shoulders stops his sobbing "
               "long enough to notice you.  His skin stretches tightly "
               "against his skin showing the outline of his gaunt face "
               "and his lack of food.  Clothes that once fit him hang "
               "loosely off his frame.\n");
      set_main_plural("captives");
      set_gender(1);
      set_race("elf");
      set_guild("cleric");
      add_language("elf");
      load_chat(25, ({
       1, ":snivels unattractively.",
       1, ":shows you a small portrait of his wife and four children.",
       1, "'Please save me! I could learn to become drow!",
       1, "'A crumb of bread or sip of water, I beg of you...",
       1, ":apologizes profusely for anything he's ever done to wrong you.",
       1, ":appeals to whatever kindness you might have.",
       1, ":sighs heavily.",
       1, ":clutches at your leg."
      }));
      
      load_a_chat(30, ({
       1, "'By the grace of Hokemj, have you no heart?",
       1, ":sobs weakly.",
       1, ":hugs both your knees, tears streaming down his face.",
       1, "'Please refrain -- I am weak.",
       1, ":tries to persuade you to end your attack.",
       1, ":drops to one knee and begs for mercy."
      }));
     break;
     
     case 3:
      set_level (4+random(2));
      add_alias("Captive");
      add_alias("elf");
      set_short("Elf Captive");
      set_long("   Pointed ears poke through disheveled hair as the elf "
               "returns your stare proudly.  Dark dirt covers his "
               "face and skin, and one might almost mistake him for "
               "a drow from a distance.  The proud look in his eyes and "
               "countenance, however, assure you that he considers himself "
               "high above the drow and that his spirit has not been broken "
               "yet.\n");
      set_main_plural("captives");
      set_gender(1);
      set_race("elf");
      set_guild("cleric");
      adjust_dex(5);
      this_object()->init_equip();
add_clone(ITEM+"shackles.c",1);
      add_language("elf");
      load_chat(25, ({
       1, ":self-consciously adjusts his rags.",
       1, "'The drow have no right to keep me here!",
       1, ":counts the months he has spent here on his fingers and toes.",
       1, "'I am of no use to you or your people.",
       1, "'Who does your decorating? Lizard-men?",
       1, "'My god Timion has abandoned me!",
      }));
      load_a_chat(30, ({
       1,"'Am I kept here to be a mere pawn for your sport?",
       1, "'Pick on someone your own size!",
       1, ":kicks dust at your feet.",
       1, "'You waste your energy, young friend.",
       1, ":doesn't consider you much of a threat.", 
       1, "'You demon! Demons, all of you!",
       1, "'Aah, you'll soon see that my sword is as sharp as my tongue."
      }));
     break;
     
     case 4:
      set_level (6+random(2));
      add_alias("elf");
      add_alias("Captive");
      add_alias("leader");
      set_short("Captive Leader");
  set_long("   The leader of the captives stands before you, her delicate "
           "elfin features hardening as she stares at you with hate and "
           "distrust.  Her armour and clothes are in excellent shape, "
           "although they are slightly too big for her slight frame; the "
           "poor fool she killed for them in this maze of a prison has "
           "no need for them now.  She crosses her arms in front of her "
           "chest, awaiting your next move.\n");
      set_main_plural("Captives");
      set_gender(2);
      set_race("elf");
      set_guild("fighter");
      set_aggressive(0);
      adjust_money(random(30),"silver");
add_clone(WEAPON+"scimitar.c",1);
      this_object()->init_equip();
add_clone(ARMOUR+"chainmail.c",1);
      this_object()->init_equip();
add_clone(ITEM+"shackles.c",1);
      add_language("elf");
      load_chat(30,({
       1, ":scoffs.",
       1, "' The drow will need to do much more than this to break my spirit.",
       1, ":sneers at you with utter disgust.",
       1, "'We shall escape.  We prefer to do it without killing you, "
          "but that is your option.\n",
       1, "'Your people shan't be safe here for long.\n",
       1, "'I have freed most of the captives.  They are gathering "
          "reinforcements for an attack.",
       1, "'You are hardly even a challenge for me."
      }));
      load_a_chat(25, ({
       1, ":points at you, and then at the exit.",
       1, ":draws blood.",
       1, ":gracefully dodges your clumsy attacks.",
       1, "'Aaah, so you've come to fight the weak and oppressed.  So noble.",
       1, ":spits at your feet.",
       1,":taunts you, confident in her strength.",
       1,"'I have not endured this prison to be killed by you.",
      }));
     break;

     case 4:
      set_level (3+random(3));
      add_alias("Captive");
      add_alias("human");
      set_short("Human Captive");
   set_long("   A tall, once-muscular human stands before you.  Strong hands "
            "that are unable to stop shaking cross in front of him, "
            "and you notice a gold ring that marks him as one of the "
            "nobles of the surface world.  Unfortunately, his title "
            "will bring him not fame or land but only more hardship "
            "at the hands of the drow.\n");
      set_main_plural("captives");
      set_gender(1);
      set_race("human");
      set_guild("cleric");
      adjust_con(1);
      adjust_dex(0);
add_clone(OBJ+"dagger.c",1);
      this_object()->init_equip();
add_clone(ITEM+"shackles.c",1);
 
      load_chat(25, ({
       1, ":looks at you uneasily.",
       1, ":shudders from your presence.",
       1, ":daydreams of days spent on the surface at the Lady Luck Tavern.",
       1, "'Aaah..what I would give to see the sun again.",
       1, "'On the surface, that's where true beauty lies.",
       1, "'Once upon a time, I had a glorious tan.",
       1, ":smiles wistfully.",
       1, "'My family would pay quite handsomely for my release."
      }));
      load_a_chat(30, ({
       1, ":mutters curses at you under his breath.",
       1, "'In Daggerford, few would kill a weakened captive.",
       1, "'A spot of mercy! I will do you no harm!",
       1, "'My family will avenge me!",
       1, "'Please, take pity on me.",
       1, ":looks furtively for a way to escape."
      }));
     break;
     
     case 5:
      add_alias("Captive");
      add_alias("human");
      set_short("Human Captive");
      set_long("   Intelligent green eyes peer at you amusedly from "
               "a face otherwise covered in a thick black beard. "
               "The human is clothed in drab clothes, and around his "
               "wrists are broken shackles that you recognize "
               "as a frequent accessory to the captives' outfits. "
               " Vitality still exudes from this prisoner, however, "
               "and you sense that the drow have yet to break his "
               "spirit.\n");
      set_main_plural("captives");
      set_gender(1);
      set_race("human");
      set_guild("wizard");
      adjust_str(4);
      adjust_con(1);
      adjust_dex(2);
      set_level(3+random(3));
add_clone(ITEM+"shackles.c",1);
      load_chat(25, ({
       1, ":laughs amusedly.",
       1, "'It's a bit drafty in here -- do you think you can order me a "
          "blanket?",
       1, "'My toes are right chilly -- be a good knave and fetch me "   
          "some slippers.",
       1, "'Your drow call this a prison? Bah!",
       1, "'I could escape, but the service and accomodations here "
             "are so lovely...",
       1, "'I love what the drow have done to this place.",
       1, "'The early dungeon look is so vogue these days!"
      }));
      load_a_chat(30, ({
       1,"'I hear drow corpses are in great demand these days.",
       1, "'Has no one taught you drow manners yet?",
       1, "'I would rather not dull my blade with this.",
       1, "'Until this attack, I would have recommended Banefall "
          "as a charming vacation spot.",
       1, "'You'll be far more fun to kill than the cave lizards.",
       1,"'You want a captive audience? I'm all yours."
      }));
     break;
     }
  }
