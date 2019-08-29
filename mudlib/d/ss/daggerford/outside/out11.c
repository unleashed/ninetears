
inherit "/std/outside";

void setup() {
   set_short("North of Daggerford");
   set_light(80);
   set_long("The trail around the city seems much more pleasant here.  "+
            "The stone walls of the city are completely overgrown with "+
           "ivy.  A low cut stump is the only legacy left behind by a once "+
           "magnificent tree.\n\n");
   add_item("ivy","The ivy is very thick and healthy.  You might be able "+
            "to take a back door into the city by climbing it...\n");
   add_item(({"tree","trees","branch","branches"}),"There are a few tree "+
            "branches laying on the ground here next to a low cut stump.  "+
            "It looks as if someone has recently harvested a once large "+
            "and magnificent tree.  Sad, eh?\n\n");
   add_exit("east","/d/ss/daggerford/outside/out10.c","corridor");
   add_exit("west","/d/ss/daggerford/outside/out12.c","corridor");
}

void init() {
   ::init();
// Taniwha 1995
// Untill there's a back door to banefall this STAYS out
   //add_action("climb","climb");
   //add_action("newjump", "jump");
}

climb(string str) {
   if(str == "ivy" || str == "walls" || str == "wall") {
      write("\n\nYou scrabble on the wall for a bit, but the ivy is just "+
            "not quite as stong as it seemed.  It won't hold your weight.\n\n");
   }
   else
   if(str == "trees" || str == "tree" || str == "branch" || str == "branches") {
      write("You can't climb what you can't reach.  You could try to jump "+
            "and catch a branch, perhaps...\n");
   }
   else
   {
      write("Climb a what?  How exactly does one do such a thing?\n");
   }
   return 1;
}

jump() {
   if(this_player()->query_dex() >= 15) {
      write("With a silent whisper, you leap straight up and catch hold of "+
            "a low-hanging branch.  You flip yourself up into the tree and "+
            "cat-walk along the branch until you drop into the city on the "+
            "other side of the wall.  The Russian judge gives you a 9.5 !\n\n");
   }
   else
   if(this_player()->query_dex() >= 10) {
      write("You leap several times, finally managing to grab onto an "+
            "overhead branch.  You struggle to lift yourself into the trees, "+
            "but cannot get a good hold.  You finally inch your way, hand "+
            "over hand, along the branch until you reach the other side of "+
            "the wall.\n\nJust as you clear the wall, you slip and land in "+
            "a clearing, flat on your butt.  The resounding clatter was "+
            "most definitely heard by any passers-by, so I hope you weren't "+
            "trying to sneak in...\n\n");
   }
   else
      write("You leap and jump and skip and hop, but you are just too clumsy "+
            "to snag the branches and hold on.  It looks like you'll have "+
            "to use the front door like a normal person.\n\n");
   call_out("wait",10);
   if(this_player()->query_dex() >= 10) {
      write("After crawling and clambering for quite some time, you finally "+
            "emerge into the street, leaving the garden behind you.\n\n");
      say(this_player()->query_cap_name()+" suddenly leaps up into the trees "+
          "and vanishes from sight!\n");
      this_player()->move("/d/ss/daggerford/farmer3.c");
      this_player()->look_me();
      say("You leap in surprise as "+this_player()->query_cap_name()+
          " crawls out from the bushes behind you.\n");
   }
   return 1;
}

wait() {
   return 1;
}

int newjump()
   {write("You jump up into the air expecting the branch you have "+
       "become accustomed to climbing, but unfortunately, it appears "+
      "as if someone has chopped down the tree.  Once a secret entrance "+
      "into the city, apparently, it became too popular.\n\n");
     say(this_player()->query_cap_name()+ " leaps up into the air and comes down again.\n\n");
return 1;
}
