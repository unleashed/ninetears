//  Looks like junk... but is MUCH better than straight cloneing
// /std/object for a shovel... IS HOLDABLE....
inherit "/obj/weapon.c";

void setup(){

   set_name("shovel");
   set_short("Shovel");
   set_main_plural("Shovels");
   set_long("\n   This is a large two handed shovel which is used "+
      "to dig through the dirt.  It is put together from a mighty "+
      "wooden rod and metal head which looks quite sturdy."+
      "\n\n");
   set_twohanded(1);
   }
