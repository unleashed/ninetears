
inherit "/std/outside";
object guard;

void setup() {
   set_short("Outside Daggerford's Eastern Gates");
   set_light(80);
   set_long("The small and insignificant eastern gate seems to get almost "+
            "no traffic at all.  The sole guard in the guardhouse is fast "+
            "asleep, and the gate (more of a door, really) stands open.  "+
            "You see shadows moving through the gate area, taking care not "+
   "to be seen.  Must be the shady side of town.  A run-down road is off to the east.\n");
   add_item("shadows","The shadows are dark and scary...ooooohhh.\n");
   add_item(({"gates","gate","city gates","city gate","eastern gate"}),
            "This small set of gates is only used by the ruffians living "+
            "in the city.  Since it lies so near the infamous River Road, "+
            "most good citizens avoid it.\n");
   add_exit("north","/d/ss/daggerford/outside/out8.c","corridor");
   add_exit("south","/d/ss/daggerford/outside/out6.c","corridor");
   add_exit("in","/d/ss/daggerford/egate.c","corridor");
   add_exit("east","/d/sf/road/ssrd10.c","road");
    modify_exit("in", ({"function", "go_in", "message",
                "N$N enters the city of Daggerford.\n"}));
   }
 
void reset()
   {if(!guard)
       {guard=clone_object("/d/ss/daggerford/chars/watchman");
        guard->move(this_object());
       }
   }
 
int go_in()
   {string RACE, PL_NAME;
    int i;
    PL_NAME=this_player()->query_cap_name();
    RACE=this_player()->query_race();
    if(RACE=="drow" && guard)
          {notify_fail("The guard steps in front of you before you have a "+
                 "chance to enter the city.\n\nThe Watchman exclaims:  "+
                 "Your filthy race isn't welcome in our city!\n\n");
           tell_room(environment(this_player()), "The Watchman steps "+
                 "forward, blocking the entrance of "+PL_NAME+" into the "+
                 "city.\n\nThe Watchman exclaims:  Your filthy "+RACE+
                 " race isn't welcome in our city!\n\n", ({this_player()}));
           return 0;
          }
    if(guard)
       {tell_object(this_player(), "Expressionless, the gate watchman "+
              "seems to take an inventory of your person before nodding "+
              "his head and motioning you through the gateway.\n");
        tell_room(environment(this_player()), "The gate watchman, after a "+
              "visual inspection, motions "+PL_NAME+" into the city.\n",
              ({this_player()}));
       }
    else
       {tell_object(this_player(), "The inspection you are normally "+
              "accustomed to going through doesn't occur, perhaps because "+
              "the gate watchman appears to be on vacation.\n");
       }
    return 1;
   }
 
