inherit "/std/guildroom";
#include "path.h"
object sign;
int learn_spell(string name, string file, int min, string type);
init()
{
    ::init();
}

void setup() 
{
    set_short("Haisk Branch : Chapel.");
    set_long("Haisk Branch : Chapel.\n\n"
      "This is a Holy Chapel dedicated to Raisa. "
      "Sylo, the head priestess, is standing near the doorway "
      "to greet and bless visitors to the Chapel. "
      "You have heard that this is the meeting place of the "
      "honorable clerigos of Raisa, and from the number of clerigos, it "
      "appears that that is correct. The Chapel is colorful by dwarven "
      "standards, with bright colors and glowing auras replacing the "
      "usual grey rock. As you step through the doorway you can feel "
      "a sense of calmness and happiness radiating from everywhere. "
      "There is a sign hung to the side of the door. "
      "\n\n");
    set_light(100);
    sign=clone_object("/std/object");
    sign->set_name("sign");
    sign->set_short("sign");
    sign->set_long(
      "A decorative sign hangs on the wall by the entrance.  There is " 
      "some writing on it, like most signs.\n");
    sign->set_read_mess(
      "      _______________________________________________________    \n"
      "     |\\_____________________________________________________/|   \n"
      "     | |                                                   | |   \n"
      "     | |       WELCOME TO THE RAISA GUILD                  | |  \n"
      "     | |                                                   | |   \n"
      "     | |  - Type 'join' to become a member of this guild   | |   \n"
      "     | |  - Type 'info' to get some guild-information      | |   \n"
      "     | |  - Type 'advance <skill>' to advance your levels  | |   \n"
      "     | |  - Type 'cost all' to see how much it will cost   | |   \n"
      "     | |    to improve skills, or 'cost <skill>            | |   \n"
      "     | |  - Type 'pray' to get a list of spells you can    | |   \n"
      "     | |    pray for, or pray <spell> to get a spell       | |   \n"
      "     | |  - Type 'specialize' to specialize on this God.   | |   \n"
      "     | |  - Type 'convert' to convert to Raisa. This must  | |   \n"
      "     | |    be done to learn spells here if you are not a  | |   \n"
      "     | |    member of this guild. If you have already      | |   \n"
      "     | |    converted to another God you can't do this     | |   \n"
      "     | |___________________________________________________| |   \n"
      "     |/_____________________________________________________\\|\n\n");
    sign->move(this_object());
    sign->reset_get();
    hidden_objects += ({ sign });

    set_teaching_person("sylo");
    set_guild("clerigos/raisa.c");
    add_specialization("raisa");

    add_exit("north",VGROOM+"haisk_raiseroom","door");
add_exit("south",VGROOM+"board_room2","door");
    modify_exit("south",({"function","go_south"}));

    //NPC'S
    add_clone(VGCHAR+"sylo",1);
} 
int go_south()
{
    if((string)TP->query_guild_name() != "raisa")
    {
        notify_fail("Raisa forbids you from entering that room.\n");
        return 0;
    }
    return 1;
}
