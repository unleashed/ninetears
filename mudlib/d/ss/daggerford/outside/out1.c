
inherit "/std/outside";

void setup() {
   set_short("Southwest of Daggerford");
   set_light(80);
   set_long("You are standing outside the Daggerford city walls, near the "+
            "ancient Tower of Mystics.  You think you hear a buzzing noise "+
            "coming from the inside of the tower, but of course the only "+
            "entrance is inside the city.\n\n");
   add_item(({"daggerford","Daggerford","city","town"}),"The city of "+
            "Daggerford has grown greatly since the days of its youth.  "+
            "It is now a major trade center of the Realms.\n");
   add_item(({"wall","walls"}),"The city walls are old and made of stones.  "+
            "They look rather weak but have never been breached.\n");
   add_item(({"tower","Tower of Mystics","tower of mystics"}),
            "The ancient tower has stood as the cornerstone of Daggerford's "+
            "stability from the very beginning.  It is rumored that the "+
            "tower was actually here before the arrival of the first "+
            "settlers, but that has never been confirmed.\n");
   add_exit("north","/d/ss/daggerford/outside/out13.c","corridor");
   add_exit("east","/d/ss/daggerford/outside/out2.c","corridor");
}
