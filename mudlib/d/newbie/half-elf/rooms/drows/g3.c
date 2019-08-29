//Ljen nov -96

inherit"/std/room";
#include "path.h"
object tancren;

void setup()
{

  set_light(70);

  set_short("Drow tunnels");

  set_long("You suddenly enter a small cave inside the tunnels, with"
           " more of the glowing moss on the walls..But as you look in"
           " the corner, you wish it had been darker... "
           " Before your eyes a sad sight occurs. A male"
           " creature sits on the ground, his head between his knees."
           " His body shivers as from cold, but when you come closer"
           " you see that he shivers from pain and fear."
           " This cave makes you sick, as your imagination clearly can"
           " figure out what has happened here. This poor creature is"
           " a prisoner, brutaly captured and ill-treated. Your hate for"
           " these dark cousins, the drows, increases at this sight.\n");

  add_exit("east", DROWS+"h3.c", "path");

  add_item("moss", "Ugly glowing moss, giving a sickly green light\n");

  add_clone(NPC+"tancren.c", 1);

}








