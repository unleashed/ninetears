/* Rage */

inherit "/std/outside";
#include "path.h"

void setup()
{
    set_light(65);
    set_short("Mystic Street");
    set_zone("pubtrack");
    set_zone("town");
    set_zone("friendly");
    set_long("The earthen clay is dark and red. Its hues resemble the "
      "the blood of your enemies. The clay is mucky and sticks to your boots. "
      "The houses here seem, to withstand time herself, to display "
      "the old world architects wisdom. The street continues to the "
      "west and to the east.\n");

    /*
     add_item("house", "The houses are fashioned in a style similar to the masons "
		  "dVar-Nacht. The subtle hinting of depth in the carved faces "
		  "leads you to believe that this particular mason was a master. "
		  "The doorways are contained in arches. It is Roman basilica "
    "in nature. Many doors line the sides of the buildings, with "
		  "the main entrance at the west side.\n");
    */
    add_exit("east", ROOM+ "m_str1.c", "road");
    add_exit("west", ROOM+ "m_str3.c", "road");

}
void init()
{
    add_action("do_drowlook", "l*ook");

    ::init();
}

int do_drowlook(string str)
{
    if (str == "house")
    {
	if ((string)this_player()->query_race_name() == "drow")
	{
	    write( "These houses are "
	      "are obviously of drow design. The use of spider queen motifs are"
	      "numerous. The style of the design is a bit misleading, it could "
	      "easily be mistaken for somthing less sinister than it is. "
	      "The secret symbols of the drow masons are obvious though. "
	      "The mason, and owner of the house, are powerfull enough to "
	      "flaunt the culture they cam from.");
	    return 1;
	}
	else /* If ((string.. */
	{
	    write( "The houses are fashioned in a style similar to the masons "
	      "dVar-Nacht. The subtle hinting of depth in the carved faces "
	      "leads you to believe that this particular mason was a master. "
	      "The doorways are contained in arches. It is Roman basilica "
	      "in nature. many doors line the sides of the buildings, with "
	      "the main entrance at the west side.\n");
	    return 1;
	} /* else if racename. */
    } /* If (str= */
}
