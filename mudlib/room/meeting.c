inherit "std/room";

object board;

setup() 
{
  add_property("no_undead",1);
  set_light(75);
  set_short("FR:Illumitech Applicant Meeting Hall");
  set_long("This is the meeting hall of applicants for FR:Illumitech. " +
           "It looks rather comfortable, but seems a place for only a " +
           "temporary stay--until you can find a proper home.  There " +
           "is a bulletin board here, and also a curious portal that " +
           "will let you mill about the sample areas that have been " +
           "created.\n" +
           "WARNING!:  This MUD is -not- designed for players.  Enter " +
           "the portal at your own risk!\n\n");

   add_exit("east","/room/entryroom.c","door");
   add_exit("portal","/d/newbie/nexus.c","portal");
   add_item("hall","This is a meeting hall.\n");
   add_item("home","When you become a creator, you will never "+
            "have to come here again.\n");
   add_item("portal","It's a standard, run-of-the-mill portal.\n");

}

void reset() {
   if(!board) {
     board = clone_object("/obj/misc/board");
     board->set_datafile("playerboard");
     board->move(this_object());
     }
   ::reset();
}
