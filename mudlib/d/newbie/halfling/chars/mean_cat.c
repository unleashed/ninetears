
#include "path.h";
inherit "obj/monster.c";
void setup(){
set_name("cat");
set_short("Wild Cat");
set_long("On a cat scale, this thing is catzilla.  The cat is mangy and unclean, "
"but is about the size of your above-average dog.  Her claws are sunk into the "
"ground as it readies to pounce on you.\n");
 
set_random_stats(3,5);
set_level(1+random(2));
set_gender(2);
}
