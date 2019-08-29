
inherit "/std/outside";
void init()
   {::init();
    add_action("THIEF_DOOR", "move");
   }

void setup() {
   set_short("Northeast of Daggerford");
   set_light(80);
   set_long("You must be near the stables.  Either that or you are studying "+
            "for an analgesic commercial and have horses pounding through "+
            "your head.\n\nThe city walls turn rather westward here, but "+
            "begin to wander a bit north towards the old ducal castle.  "+
            "A small hedge runs alongside the wall here.\n\n");
   add_exit("south","/d/ss/daggerford/outside/out7.c","corridor");
   add_exit("west","/d/ss/daggerford/outside/out9.c","corridor");
}
int THIEF_DOOR(string str)
   {if(str != "bush" || (string)this_player()->query_guild() != "thief")
    return 0;
   write("Carefully, you part the shrubbery and descend through "+
    "the secret entrance into the guild.\n\n");
   this_player()->move("/d/ss/daggerford/thieves/hall4.c");
   this_player()->look_me();
   return 1;
   }
