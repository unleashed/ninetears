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
   set_helper_name("june");
  set_short("Isle of Havmand: Raiseroom");
  set_save_file(file_name(this_object()));
    set_long("\nIsle of Havmand: Raiseroom.\n\n"
    "   This is the room you come to when you are dead and wish to get raised. "
    "It is a quiet, peaceful room, and in contrast to the rest of the village, "
"it has been well-maintained. The walls and floor have been freshly "
   "scrubbed, and there is a pleasant odor in the air.\n"
         "If you want to get raised, you might want to look at the"
	 " sign first. \n\n");
  set_percentage(100);
  set_light(60);

    add_smell("air","There is a pleasant smell of roses in the air.\n");
add_item("shrine", "A small altar to Hokemj sits in the corner.  There"
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
           "|        Isle of Havmand: Raiseroom           |\n" 
           "|                                             |\n" 
           "|     Type raise <ghost> to raise someone.    |\n" 
           "|_____________________________________________|\n" 
             "\n\n");


   add_exit("east",HAVMAND+"t07.c","door");
}

void reset()
  {
  if (!helper)
    {
   helper = clone_object("/baseobs/monsters/healer");
    helper->move(this_object());
    }
   helper->set_name("june");
   helper->set_gender(2);
   helper->set_short("June");
   helper->set_long("A tall middle aged woman with dark hair and eye's "
   "of such a dark brown they appear black. She looks a little weird, but "
   "ghosts can't afford to be picky.\n");
} /* void reset */ 

void dest_me()
  {
  if (helper)
    helper->dest_me();
   ::dest_me();
} /* void dest me */
