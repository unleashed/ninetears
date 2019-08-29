
inherit "/std/outside";

void mysetup();

#define NDESCS 5

string * rooms = ({
                 "/d/ss/daggerford/ladyluck.c",
                 "/d/bf/banefall/city/tavern.c",
                 "/d/hoerk/belaern/s_jung/city/shops/tavern.c",
                 "/d/hoerk/belaern/desert/bsand/deadmans.c"
                });
string res = "%^RESET%^";
string blue = "%^RESET%^%^BLUE%^";
string orange = "%^RESET%^%^ORANGE%^";
string gray = "%^RESET%^%^BLACK%^%^BOLD%^";
string red = "%^RESET%^%^RED%^";
string purple = "%^RESET%^%^CYAN%^%^BOLD%^";
string green = "%^RESET%^%^GREEN%^";
string pink = "%^RESET%^%^RED%^%^BOLD%^";
string tailer = "\n";

   string *colors = ({
   blue+"blue",
   green+"green",
   red+"red",
   "%^RESET%^%^MAGENTA%^magenta",
   "%^RESET%^%^ORANGE%^orange",
   "%^RESET%^%^CYAN%^cyan",
   purple+"purple",
   "%^RESET%^%^BLUE%^%^BOLD%^light blue",
   "%^RESET%^%^YELLOW%^%^BOLD%^yellow",
   "%^RESET%^%^GREEN%^%^BOLD%^light green",
   gray+"gray",
   pink+"pink"
      });

string * things = ({"shattered mountain","crystal geode","cloud",
      "iceberg","burning patch of sand","frumious bandersnatch"
   });

string col,plce;
string cola;

string tlong()
{
   string tmp;
   object ob;
   tmp = rooms[random(sizeof(rooms))];
   ob = find_object(tmp);
   if(ob) return ob->query_long();
   else return this_object()->query_long();
}



int testran(int i)
{
   return(random(i));
}
void setup()
{
    mysetup();
    add_exit("spinwise",file_name(this_object()),"door");
    add_exit("antispinwise",file_name(this_object()),"door");
    add_exit("left",file_name(this_object()),"door");
    add_exit("right",file_name(this_object()),"door");
    add_exit("hubwards",file_name(this_object()),"door");
    add_exit("rimwards",file_name(this_object()),"door");
// add exits if you want
   if(!random(3))
   add_clone("/baseobs/monsters/displacer",1);
}
void init()
{
    add_action("do_look","l*ook");
    mysetup();
    ::init();
}
int do_look(string str)
{
    mysetup();
    return 0;
}

void mysetup()
{
   int i,j;
   string xlong;

   i = random(sizeof(colors));
   j = (i+1)%sizeof(colors);
   col = colors[i];
   cola = colors[j];
   plce = things[random(sizeof(things))];
   set_light(50+random(100));
   switch(random(NDESCS))
   {
   case 0:
    xlong = pink+"Pink fishes "+cola+"ly swim in a "+col+" sea.\n"
        "Short "+pink+"pink fins flollop "+cola+"ly in a drunken haze of "+
        col+" cider, for unlike normal seas, this one is at least "
        "20% proof, large icebergs of "+red+" strawberry icecream float "
        "in the warm "+col+" water.\n"
        "The undead Wombat wombling along upside down on the "+cola+
        " surface of the ocean is the only feature to distract from "
        "the idyllic scene.\n";
   break;
   case 1:
    xlong =
        red+"You feel as though you are burning as you stand here "
        "within the mouth of chaos. The "+cola+
        " sky above is harsh in "
        "black and white, sun and antisun chase one another through the heavens "
        "and the sky rotates above you, dividing the heavens in two, "+
        col+" clouds of vapour waft past as you stand here on "
        "a pale "+cola+" "+plce+" at this, the end of all. ";
   break;
   case 2:
    xlong =
        blue+"The sky above is rent by bolts of "+col+" flame "
        "and vast "+col+" clouds "+cola+" blow past, lit by the light of the "+
        col+" sun below "
        "and seemingly pouring light into the "+cola+" antisun "+col+" dimmed in that direction. "
        "Your footing on the dark "+cola+" "+plce+" seems "
        "most insecure, but nothing remains the same in chaos, even this "+
        "will change, "+
        col+" bubbles sweep past distorting the image further.";
    break;
   case 3:
   xlong =
        green+
        "A moment of calm in the sea of chaos, for even chaos obeys it's own "
        "non-rules, your "+col+" "+plce+" floats apparently on a sea of "+
        cola+" flowers. "
        "Cold "+col+" rain "+cola+"ly falls on your upraised face, and as it trickles "
        "down your body to the ground it turns into small "+pink+"pink frogs "+
        cola+"ly leaping happilly off this "+plce+" into oblivion. ";
   break;
   case 4:
   default:
    xlong =
        cola+" smoke blows past making your eyes water, as they clear "
        " you see before you a strange vision.\n"+
        tlong() +
        col +" smoke blows past now, hiding the scene once again."
        "It looks a little strange in shades of "+col+" and "+cola+
        " but this is chaos, what did you expect ?. ";
   }
   set_short("\nChaos\n");
   set_long("\n\n"+xlong+"%^RESET%^\n\n");
}


