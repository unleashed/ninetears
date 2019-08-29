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
add_property("no_undead",1); 
	
	set_short("Cabin of Sarissa");
	
	set_save_file(ROOMS +"collect");
  
	set_helper_name("Sarissa");

	set_long("\n Cabin of Sarissa \n\n"
       "	You've entered the cabin of Sarissa. This is"
       " where you can return to the realms of living. Sarissa "
	"is one of few being able to restore the power of living "
	"and will gladly help you out when in need. "
	"   Her cabin is entirely decorated with shapes and carvings "
	"seeming like some sorts of bodytransformations. You also "
	"notice a shrine in the left corner and a table by the stony "
	"fireplace right infront of you.\n\n");

	set_percentage(100);
	set_light(60);

	add_item("shrine", "A small altar to Hokemj sits in the corner.  There"
       " are several lit candles around the shrine, but it"
       " really doesn't attract your attention when you first"
       " enter the room. \n");

	add_sign("/---------------------------------------------\\\n" 
	         "|                                             |\n" 
        	 "|          Sarissa the bodymender's           |\n" 
	         "|                                             |\n" 
	         "|     Type raise <ghost> to raise someone.    |\n" 
	         "|_____________________________________________|\n" 
	         "\n\n");

       add_exit("south",ROOMS + "h3.c", "door");
}

void reset()
  {
  if (!helper)
    {
	helper = clone_object("/baseobs/monsters/healer");
	helper->move(this_object());
	helper->add_property("no_undead",1); set_short("Max");
	helper->set_name("sarissa");
	helper->set_long("Sarissa\n\n"
      "   Sarissa, an elder elven woman. 'Strange', you think, "
      "'so much vividness in her eyes'. Opps, was that a wink? "
      "    Standing there, by the fireplace, making some sort of "
      "texture on a piece of leather, she really seems to form "
      "a quite sweet and profound smile. Even though she appearently is in "
      "her older days, her soul still seems to glow with strong " 
      "vividness and warmth.\n\n");
	helper->set_level(14);
        helper->set_guild("hokemj");
    }
} /* void reset */ 

void dest_me()
  {
  if (helper)
    helper->dest_me();
   ::dest_me();
} /* void dest me */
