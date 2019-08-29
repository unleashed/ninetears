#include "path.h"
inherit "/std/room";

object booklet;

void setup()
{
        set_short("Dwarf Kitchen.");

        set_long("This is a tiny room which serves as a kitchen for "
                "the dwarfen family which used to live here. There is "
                "a pile of ashes in the middle of the room where the food "
                "was obviously cooked. There are a few Large pans hanging up "
                "on one wall. There is a small food cupboard in the corner. "
                "There is a small battered booklet on the table.\n");
                                                       
        add_property("no_undead",1); set_light(80); 

        add_item("Ashes", "These are the remnants of a large fire.\n");

        add_item("Pans", "These are large and well burn't.\n");

        add_item("Cupboard", "This is a simple let large food Cupboard "
                 "(closed).\n");

        add_alias("pan", "Pans");
        add_alias("pans", "Pans");
        add_alias("Pan", "Pans");
        add_alias("cupboard", "Cupboard");
        add_alias("ashes", "Ashes");
        add_alias("ash", "Ashes");
        add_exit("east", PATH+"dwarf.c","door");
}
void reset()
{
        if(!booklet)
	{
        return;
        booklet = clone_object("/std/object");
        booklet->set_name("booklet");
        booklet->set_main_plural("booklets");
        booklet->set_short("booklet");
        booklet->set_long("This is a help Booklet. Upon reading it you "
                "see various helpful commands......\n "
                "1) Type help or help <topic> for general help.\n "
                "2) Score brings up your score.\n "
                "3) Skills brings up your current skill levels.\n "
                "4) To Communicate try Chat, tell, say or Shout.\n "
                "5) Who brings up a list of current mudders.\n "
                "6) Wield <weapon>, wear <armour> are needed to equip yourself.\n "
                "7) Search or Search <item> will search an area or specific item.\n "
                "This is about it...enjoy the MUD.\n");
        booklet->set_weight(5);
        booklet->set_value(0);
        booklet->move(this_object());
        } /* if (!booklet) */
  } /* void reset() */

void dest_me ()
  {
  if (booklet) 
    booklet->dest_me();
  } /* dest_me */
