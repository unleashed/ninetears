/* A temple for raising..
 * Needs money to work...
 * Inherits /std/raiseroom.c that uses the bank-handler to handle accounts.
 * Baldrick.
 */

#include "path.h"
inherit "/std/raiseroom";

object helper;

void setup()
  {
   set_helper_name("shaman");
set_short("Realm of the Orc:  Temple of the Dead");
set_save_file("collect");
   set_long("\n   Realm of the Orc:  Temple of the Dead.\n\n"
            "     You cautiously take a peek inside.  You see several "
            "orcs dressed "
"in feathers and beads dancing and chanting around a dead orc. "
"They seem very intent in changing the status of the fallen orc. "
"To one side of the temple you see the not-so successful attempts "
"of raising the dead.\n\n");
 
add_item("corner", "  You see the unproductive attempts "
"at trying to persuade the gods for the return of life.\n\n");
add_item("bodies", " Hmmm, yep, they're dead alright.\n\n");
add_sound("chanting", " ooo, you thought it sounded bad outside!!\n\n\n"
"  Your ears began to bleed....\n");

  set_percentage(100);
  set_light(60);

    add_smell("air","There is a pleasant smell of roses in the air.\n");
add_item("shrine", "A small altar to Tymora sits in the corner.  There"
	" are several lit candles around the shrine, but it"
	" really doesn't attract your attention when you first"
	" enter the room. \n");
add_item(({"cot", "cots"}), "Uncomfortable looking wooden tables where the"
	" bodies are placed for examination and treatment. \n");
add_item(({"healer", "healers"}), "Stern looking individuals who spend their"
	" days raising people from the dead.  They move about the"
	" room, their movements fluid and purposeful.  They are busy"
	" people, and don't look like they smile often. \n");
  add_sign("/---------------------------------------------\\\n" 
           "|                                             |\n" 
           "|        Orc Temple: Raiseroom                |\n"
           "|                                             |\n" 
           "|     Type raise <ghost> to raise someone.    |\n" 
           "|_____________________________________________|\n" 
             "\n\n");


   add_exit("north",TOWN+"town06.c","path");
}

void reset()
  {
  if (!helper)
    {
   helper = clone_object("/baseobs/monsters/healer");
    helper->move(this_object());
    }

  helper->set_name("Orc Shaman");
  helper->set_short("Orc Shaman");
helper->add_alias("shaman");
helper->set_long("The orc male that stands before is a shaman to the "
  "orc god Maglubiyet. He attends to the wounds of the many "
  "orc adventurers. It is said that he can even bring some back "
   "from the dead.\n\n");
} /* void reset */ 

void dest_me()
  {
  if (helper)
    helper->dest_me();
} /* void dest me */
