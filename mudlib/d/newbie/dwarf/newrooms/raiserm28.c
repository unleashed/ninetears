/* A temple for raising..
 * Needs money to work...
 * Inherits /std/raiseroom.c that uses the bank-handler to handle accounts.
 * Baldrick.
 */

inherit "/std/raiseroom";
#include "path.h";

object helper;

void setup()
{

    set_short("Raiseroom");
    set_helper_name("shalagha");
    set_long("This is a small temple that is being used to treat and raise "
      "several injured or killed adventurers.  There is an altar on "
      "the eastern wall that has several candles sitting upon it.  "
      "The candles cast an eerie glow on the bodies that are lined "
      "up all around the room.  There is a sign here on the wall.\n\n");
    set_percentage(100);
    set_light(60);
    add_sign("A small sign reads: \"raise playername\" to return them, or yourself from the dead.\n");

   add_item("altar","This is an old wooden altar.\n\n");
   add_item("wall","You look at the wall more closely,but"
      " you dont notice anything special.\n");
   add_item("bodies","These are the bodies of adventurers that"
      " have died recently.\n");
   add_item("candle","These are candles that light up the room.\n");

    add_exit("out",ROOM+"dwarf34.c","door");
}

void reset()
{
    if (!helper)
    {
	helper = clone_object("/baseobs/monsters/healer.c");
	helper->set_name("shalagha");
	helper->set_short("shalagha");
	helper->set_long("An old bearded dwarf, but then, don't they all look like that ?\n");
	helper->move(this_object());
    } /* void reset */ 
    ::reset();
}

void dest_me()
{
    if (helper)
	helper->dest_me();
    ::dest_me();
} /* void dest me */
