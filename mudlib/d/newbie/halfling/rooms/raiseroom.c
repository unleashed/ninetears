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
    set_helper_name("Alana");
    set_short("Island of Maroek:  Raiseroom");
    set_save_file(file_name(this_object()));
    set_long("\nIsland of Maroek:  Raiseroom.\n\n"
      "     This small chapel is for the brave halflings defeated in battle to come for a "
      "second chance.  The room is peaceful atmosphere of this building is that of peace and "
      "tranquility.  You feel totally at ease here.  There is also a sign on the wall beside "
"the alter in the center of the chapel.  Oddly enough humans tend to the needs of the "
"sick, injured, and the dead.\n");
    set_percentage(100);
    set_light(60);

    add_smell(({"air","room","here"}),"The room has the sweet smell of incense in the air.\n");
    add_item("alter","The altar is made of fine oak and stands three feet high.  Candles adorn "
      "the sides of the altar, adding light to this dim atmosphere.\n");
    add_item(({"candle","candles","light"}),"The candles are barely sufficient to light the "
      "small room, but add to the feeling of mystery surrounding the mysterious healers that "
      "work their miracles here.\n");
    add_item(({"healer","healers","alana"}),"Healers walk to and fro in this room.  Obviously "
      "talented, Alana stands overseeing all that is done in the room.  Her eyes a pale green "
      "and long strands of red hair occasionaly slip from her hooded robe as she goes about "
      "her duties here.\n");
    add_sign("+------------------------------+\n"
"|                              |\n"
"| Island of Maroek:  Raiseroom |\n"
"|If dead, type 'raise <player>'|\n"
      "+------------------------------+"
      "\n\n");


add_exit("west",ROOMS+"half5.c","door");
}

void reset()
{
    if (!helper)
    {
	helper = clone_object("/baseobs/monsters/healer");
	helper->move(this_object());
    }
    helper->set_name("alana");
    helper->set_gender(2);
    helper->set_short("Alana");
    helper->set_long("A slender young woman, Alana's form is mostle hidden beneath her"
      "hooded robe.  From what you can see though, she is unearthly beautiful, with pale green "
      "eyes and strands or red hair straying from beneath her robe.  She seems almost too "
      "young to have such a serious duty, but she handles it quite well.\n");
} /* void reset */ 

void dest_me()
{
    if (helper)
	helper->dest_me();
    ::dest_me();
} /* void dest me */
