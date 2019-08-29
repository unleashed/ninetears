inherit "/std/sacroom";


void setup() {
   add_property("no_clean_up",1);
   set_god_here("virga");
   set_short("%^BOLD%^%^CYAN%^Shrine of Virga%^RESET%^");
   set_light(60);
   set_long("\n%^BOLD%^%^CYAN%^Shrine of Virga%^RESET%^\n\n"
       "     As you step off the bridge, your eyes are drawn to "
       "a round, domed building with gleaming, white marble pillars.  "
       "Up close, the structure appears much larger than you first "
       "thought.  Stepping inside, you see long, wide, steep steps "
       "that sweep all the way around the shrine.  Every twenty feet "
       "or so there are half-steps separating each of the steeper "
       "ones, allowing easier access to the altar in the pit at the "
       "bottom.  The air is charged with the power and awe inspiring "
       "self-righteousness that is the essence of Virga.  The open "
       "structure seems to radiate outwardly all the goodness and "
       "serenity that the goddess represents.  But beneath the "
       "veneer of serenity, you recognize the iron will that promises "
       "to someday overwhelm all the forces of chaos and evil in the "
       "realms.\n\n");
  add_item("steps", "Large steep steps that also serve as benches "
       "for when the followers of Virga wish to meet and share "
       "the trials and tribulations of their lives with each other "
       "and Virga, herself, spiral all the way around the building.  "
       "Every 20 feet, these steep steps are punctuated with smaller, "
       "shallower steps that allow one to safely descend to the pit.\n");
  add_item("pillar", "Large, gleaming white marble pillars intricately "
       "carved to display the stars, the moon and the scales of justice "
       "support the domed roof of this open structure.\n");
  add_item(({"dome","roof"}), "The domed roof of the shrine is somehow "
       "translucent from the inside.  You can see clearly, the sky "
       "beyond.\n");
  add_item("sky", "Peering up through the dome, you see the sky, "
       "in all its infinity looking back at you.\n");
  add_feel("air", "The air is alive with the power and majesty of "
       "Virga.\n");
  add_item("pit", "At the bottom of the steps, you see the pit that "
       "serves as the altar to Virga.\n");
                                           
       
    add_exit("north","/d/um/village/park/bridge01.c","path");
    add_exit("south","/d/um/village/park/bridge02.c","path");
}
