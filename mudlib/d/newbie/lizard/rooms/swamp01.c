#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You tread deeper into the gloomy swamp. "
      "Dark, mangled trees close about you, further diminishing the already scarce light. "
      "Their dead leaves litter the squalid ground. "
      "The muddy path continues ahead of you to a dreary pond. "
      "The water is a green poisonous muck with an unholy steam hanging on its surface. "
      "The trees inhabiting it have long since died from their prolonged stay in the poisonous waste.\n\n");
    set_light(80);
    add_item("path","You are on a muddy path leading down to a murky swamp. "
      "Your feet stick in the mud as you walk, making little thooking sounds as you pull your foot out.\n\n");
    add_item("trees","The trees in this area are nothing but skeletons, grim reminders of the once thriving forest.\n\n");
    add_item("swamp","The path leads up to a murky swamp. "
      "The water is a putrid muck, poisonous and devoid of life.\n\n");
    add_exit("northwest",ROOMS+"lizard18.c","path");
    add_exit("southeast",ROOMS"swamp02.c","path");
}
