
inherit "/std/outside";

void setup() {
   set_short("West of Daggerford");
   set_light(80);
   set_long("The trail around Daggerford leads north towards the western "+
            "gate and south past a tower.  You see fairies flitting about "+
            "over the city wall to your east.\n\n");
   add_item("fairies","These are the postal workers.  They're not like the "+
            "ones you're used to, who often carry guns and shoot people for "+
            "no reason at all.  These are fast, friendly deliverymen.\n\n");
   add_item(({"trail","path"}),"The path around Daggerford has recently "+
            "been completed.  It is intended to replace the old system of "+
            "teleportals.\n\n");
   add_exit("north","/d/ss/wilderness/daggerford.c","corridor");
   add_exit("south","/d/ss/daggerford/outside/out1.c","corridor");
}
