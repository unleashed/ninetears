// Modified by Ljen, okt -96

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
    set_short("Castle Of The Green Sun - Raiseroom");
    set_long("This room acts as the chamber of the castle's cleric and as "
             "the raiseroom for those who have died recently and have not "
             "enjoyed enough their life in this plane of the existence.  T"
             "he room itself is like a little cathedral:  stone arches cros"
             "s the room from side to side and there is a small altar at th"
             "e north wall.  There are no rooms in here and the bed of the "
             "cleric is camouflaged in a wardrobe at the west wall.\nThere "
             "is a sign above the altar where there are two candles lightning "
             "the whole room.\n");


    set_percentage(100);
    set_light(60);

    set_save_file(CAST+"collect");
    set_helper_name("zemnen");

    add_sign("A small sign reads: \"raise playername\" to return them, or yourself from the dead.\n");

    add_item("altar","This is an old wooden altar.\n\n");

    add_item(({"arch","arches"}), "The typicall structure made in the "
                                  "truly cathedrals to support the heavy walls"
                                  "\n");

    add_item("candle","These are candles that light up the room.\n");

    add_exit("east",   CAST+"e1.c",   "door");
}

void reset()
{
    if (!helper)
    {
        helper = clone_object("/baseobs/monsters/healer.c");
        helper->set_name("zemnen");
        helper->set_short("Zemnen, Cleric of the White Order");
        helper->set_long("Zemnen is a half elf cleric of the firsts ages, he came here, "
                         "when Etriel left the Realms to retire.  He's knowledge is great " 
                         "and usually gives advices about future.  People of the whole "
                         "keep come here looking for advice.\n");
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

