
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("spider");
set_short("Baby Spider");
set_long("This is a baby spider.  This does not mean that the spider "
   "is small, however.  This is just a baby version of the typical "
   "giant spider that are found in other parts of the realms.  It"
   " is quite huge to you, and you see venemous saliva dripping "
   "from its jaws as it advances on you slowly.\n");
set_random_stats(3,10);
set_str(17);
set_level(8);
set_al(0);
set_gender(0);
}
