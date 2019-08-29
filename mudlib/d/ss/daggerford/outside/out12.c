
inherit "/std/outside";

void setup() {
   set_short("Northwest of Daggerford");
   set_light(80);
   set_long("The northwestern corner of Daggerford is home to the imposing "+
            "Tower of Delfen.  The mighty mage of the Swordsea makes his "+
            "home there and teaches the way of the Weave to his chosen "+
            "pupils.\n\n");
   add_item(({"tower","city tower","northwestern tower","delfen's tower",
              "Delfen's tower","tower of delfen","tower of Delfen",
              "Tower of Delfen"}),"This tower is made of blackest obsidian.  "+
              "Rumor would have you believe that it was constructed in the "+
              "earliest days of the city's birth by creatures from another "+
              "reality entirely.  Delfen was already a powerful sorcerer at "+
              "that time...at least several centuries ago.\n\n");
   add_exit("south","/d/ss/wilderness/daggerford.c","corridor");
   add_exit("east","/d/ss/daggerford/outside/out11.c","corridor");
}
