inherit "/std/room.c";

void setup()

{

    set_short("FR:Illumitech Entrance");
     set_long("You find yourself in a great hall that looks not unlike most "+
      "entrances to colleges.  Various academic-looking people mill "+
      "about here.  Most of them have the aspect of someone who doesn't "+
      "quite know where to begin or what to do.  Thankfully "+
      "for you, there is a large sign in front of you that might give "+
     "you an idea of what's going on and where to go.\n" +
      "To the west is the meeting-room, and to the east is the post "+
      "office.\n\n");

    set_light(80);
    add_item("sign",
      "  +==========================================================+\n" +
      "  | FR:Illumitech -- Decicated to Mud Instruction and the    |\n" +
      "  |                  Continuing Development of the FR:Mudlib |\n" +
      "  |                                                          |\n" +
      "  | New Applicants:                                          |\n" +
      "  |                Please enter the Post Office (to the east |\n" +
      "  |                of here) and mail Benedick your request   |\n" +
      "  |                to become a student here.  Please include |\n" +
      "  |                your Real Name, Email Address, The name   |\n" +
      "  |                and IP address of the MUD you're normally |\n" +
      "  |                on, What you would like to learn (and how |\n" +
      "  |                much you might know about coding already) |\n" +
      "  |                and lastly how you heard about us.        |\n" +
      "  |                                                          |\n" +
      "  +==========================================================+\n");

add_item("hall","It's a hall, but your eyes are rather drawn to looking "+
   "at the sign.\n");
add_item("people","You see the people are examining the sign.\n");

add_exit("west","/room/meeting","door");
add_exit("east","/room/post","door");

}
