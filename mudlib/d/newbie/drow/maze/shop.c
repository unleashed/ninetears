#include "path.h"
inherit "std/shop";
 
int query_underground() { return 1; }

void setup() {
  set_short("Realm of the Drow:  Captive's Exchange");
  set_long("\n   Realm of the Drow:  Captive's Exchange.\n\n"
          "     A hidden hole beneath one of the ever-winding staircases, "
          "the cave is occupied by one of the maze caretakers.  Although "
          "little emphasis is placed on rules in your home city of Banefall, "
          "it is more than obvious that the guard is operating stealthily and "
          "that the house he serves would not approve of him providing captives "
          "and young drow alike with weapons -- in exchange for exorbidant prices "
          "that line his pockets.  Overturned "
          "stones serve as crude racks for a variety of equipment and "
          "items that have been stolen from dead corpses and are marked "
          "far higher than they seem worth.  Unfortunately, it is one of the "
          "few options available for the equipment one needs just to survive here.\n\n"
           "Use \"list\" to get a list of what is for sale, "
                   "\"browse\" to look at an object before you buy it, and  "
           "\"value\" to value your object before you \"sell\" it."
           "\n\n");
 
  set_light(30);
   add_exit("east", MAZE+"maze06", "corridor");
   add_exit("west",MAZE+"maze10","corridor");
 set_item_table(MAZE+"SHOP_TABLE.c");
set_store_room(MAZE+"store.c");
  add_property("smithy", 1);
 
  // ok, here comes the hotstepper..eh, I mean the messages...
  set_sell_message(({"The guard tells you with a sneer: I'm afraid I can only give "
                     "you $money$ for it.\n\nYou give $ob$ to the "
                     "greedy guard.\n",
                  "$client$ sells "
                   "$ob$ \n"}));
  set_buy_message(({"With a glint of avarice, the prison guard tells you: That will be $money$. "
                  "Leave now before I kill you to get it back.\n",
                    "$client$ buys $ob$.\n"}));
  set_value_message("The guard tells you:I will give you "
             "$money$ for that.\n");
  set_browse_message("The guard sighs with forced patience and says: Must you touch every "
             " $ob$ before you purchase one? "
           " Well, here it is but be quick about it...\nThe prison guard gives "
          "you a $ob$.\nYou take a closer look at it:\n\n$extra$\n"
           "The guard grabs the $ob$ and says: Enough! Do you have $money$ "
           "to pay for it?\n");
     clone_object(WEAPON+"dagger")->move(our_storeroom);
     clone_object("/baseobs/armours/cloak")->move(our_storeroom);
     clone_object("/baseobs/armours/leather")->move(our_storeroom);
     clone_object("/baseobs/armours/ringmail")->move(our_storeroom);
     clone_object("/baseobs/armours/med_shield")->move(our_storeroom);
     clone_object("/baseobs/armours/cloak")->move(our_storeroom);
     clone_object("/baseobs/armours/leather")->move(our_storeroom);
}

