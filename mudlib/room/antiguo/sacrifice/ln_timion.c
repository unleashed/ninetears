inherit "/std/sacroom";
 
void setup() {
 
   set_light(50);
  add_property("no_clean_up",1);
 
   set_short("The Cathedral of Lawful Neutral");
 
   set_long("\nThe Cathedral of Lawful Neutral:  Temple of Justice.\n\n"
            "     Overwhelming power nearly drives you to your knees as "
            "you enter this great hall.  The walls are carved of the "
            "rarest form of marble and have been polished smooth as glass. "
            " Immense pillars line the hall holding aloft a massive domed "
            "ceiling over 80 feet above you.  A large dias dominates the "
            "far end of the hall where the altar lies.  Murals line the "
            "ceiling and arches of this great hall each depicting acts "
            "of judgement and justice.  You notice that the unjust tend to "
            "earn rather fatal and violent sentences.  The hair on the "
            "back of your neck begins to tingle and you stop to listen "
            "to mysterious voices and cries echoing through the room.  "
            "The floor is scratched and worn as if millions of people "
            "have been dragged forcibly from the room ... in chains.\n"
            "\n");
 
   add_feel(({"power"}),
            "   Unseen and yet very much felt, the power of this room "
            "nearly drives you to your knees.  Sapping what little "
            "strength you have remaining, the force drives into your soul "
            "digging out the truth and the secrets of your life.\n"
            "\n");
 
   add_feel(({"walls"}),
            "   The walls of this chamber are smooth, cold and incredibly "
            "hard.  They seem to hum with power and echo the agonized "
            "cries of the unjust.\n"
            "\n");
 
   add_sound(({"voices","cries"}),
             "   A shiver runs down your spine as you stop to listen "
             "to the sounds filtering into the room.  The cries of the "
             "unjust seem to echo in from another world ... fear, pain "
             "and agony dominate.  You can tell that no quarter is given "
             "here, no such thing as forgiveness.\n"
             "\n");
 
   add_item(({"power"}),
            "   Unseen and yet very much felt, the power of this room "
            "nearly drives you to your knees.  Sapping what little "
            "strength you have remaining, the force drives into your soul "
            "digging out the truth and the secrets of your life.\n"
            "\n");
 
   add_item(({"walls","marble"}),
            "   The walls of this hall are of the rarest and most pure "
            "form of marble.  Strands of obsidian and gold intermigled "
            "with veins of quartz trace intricate lines through the "
            "stones.  The entire hall looks like it is one piece of rock "
            "as you can find no seams or cracks anywhere in the perfect "
            "surfaces of the stone.\n"
            "\n");
 
   add_item(({"columns","pillars"}),
            "   The columns are evenly spaced forming an line leading "
            "to the dias at the far end of the hall.  Each pillar is of "
            "considerable girth and reaches nearly 80 feet to the large "
            "domed roof above you.  Carved into each pillar is the image "
            "of a blind-folded woman carrying a set of scales symbolizing "
            "the balance of justice.\n"
            "\n");
 
   add_item(({"ceiling","roof","dome","images","murals"}),
            "   Murals hand-painted into the ceiling depict images of "
            "Timion, the Warrior God of Justice, passing judgement over "
            "mortals of this realm.  In most of the images, his justice "
            "is usually quick, severe, ...and very violent.  It is "
            "obvious to you that he does not tolerate injustice or chaos "
            "in any form.  You heed the warnings of these murals and "
            "continue down the hall.\n"
            "\n");
 
   add_item(({"dias"}),
            "   A large stone dias rises out of the floor at the far end "
            "of the hall.  Each step of the platform must be a foot above "
            "the one below it lifting the altar atop it nearly 10 feet "
            "above the floor.\n"
            "\n");
 
   add_item(({"floor"}),
            "  The floor here is worn and scratched.  It looks as though "
            "a multitude of people have passed through this hall, and "
            "countless more were dragged forcibly from the hall in chains "
            "and shackles.  You find yourself hoping that you are allowed "
            "to leave of your own volition.\n"
            "\n");
 
  set_god_here("timion");
  add_exit("north", "/d/aprior/guilds/timion/rooms/temaltar.c", "door");
} /* setup */
