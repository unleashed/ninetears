inherit "/std/room";
#include "path.h"
 
void setup() {
  set_light(75);
  set_short("Gnarlwood Forest:  Entrance to the Magically Stolen Woodland");
  set_long("\n   Gnarlwood Forest:  Entrance to the Magically Stolen Woodland.\n\n"
           "     The natural beauty and danger that the caves "
           "embody fades from your memory as you stare at the "
           "ghoulish scene before you.  The cave breaks suddenly "
           "into a once-flourishing forest that stretches through the "
           "cavern for seemingly acres and acres.  No cracks in the "
           "roof allow sunlight or fresh rain water to nourish these "
          "plants, and yet the forest appears undisturbed and growing "
          "in some twisted sense of the world.  Trees that were planted "
          "by past surface-dweller generations now adapt eerily and "
          "unattractively to an area where sunshine is but a mere "
          "memory."
          "\n\n");

   add_item("cave", "The cold brown stone seems almost inviting now, as "
          "you step away from the cavern.  At least in the cavern, you knew "
          "what you could expect...\n");
 
   add_item(({"forest","area"}),
            "Trees that look too pale, too awful to be considered simply "
            "diseased stretch all around you, their branches and trunks "
            "bending and entangling themselves grotestequely as they strain for "
            "sunlight. Lesser foliage climbs the tree trunks in vain, searching "
            "for the outdoors at a higher level.\n");
   add_item(({"plant","plants"}),
            "Stark white plants without a trace of chloryphyl spread "
            "across the forest bottom, unable to grow or flower without "
            "the needed water and sunlight.\n");
   add_item(({"tree","trees"}),
            "Pine trees and strong maples were once a staple of strong and "
            "straight wood from this forest; now the trees are as curved as "
            "slithering worms and pale in color.\n");
 
   add_item(({"roof","ceiling"}),
            "You search the ceiling above you for a crack, a break, a cleavage "
            "that could have caused such a large portion of land to be dropped underground.  "
            "but the rocks spread above you seamlessly.  This forest was brought here by "
            "no natural power, but by evil magic.\n");
 
   add_exit("west",HERE+"ef13.c","path");
   add_exit("north",HERE+"con04","path");
   add_property("no_undead",1);
 
}

