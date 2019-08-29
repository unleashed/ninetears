
inherit "/std/outside";
object guard;

void setup() {
   set_short("South of Daggerford City Gates");
   set_light(80);
   set_long("You are standing outside the southern gate of Daggerford.  "+
            "The path leading up to this gate seems fairly well-travelled, "+
            "although not as much so as the western gate.\n\nCarried on the "+
            "wind are incomprehensible sounds of loud conversation, "+
            "punctuated by the rhythmic pounding of metal on metal.\n\n");
   add_item(({"gates","city gates","gate","city gate"}),
            "The massive gate into the city stands open, as always, silently "+
            "bidding you to enter this peaceful place.\n");
   add_exit("east","/d/ss/daggerford/outside/out4.c","corridor");
   add_exit("west","/d/ss/daggerford/outside/out2.c","corridor");
   add_exit("in","/d/ss/daggerford/sgate.c","corridor");
   //add_exit("southwest","/d/omiq/quests/graveyard/yardent.c","road");
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
 
