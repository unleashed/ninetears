inherit "std/room";
#define PATH "/doc/races/"

setup() 
{
  string human, halfelf, elf, halfling, orc, halforc, lizardman;
  string gnome, dwarf, goblin, drow,duergar;

// added by Radix for "no new" players from the site.
// REAL ugly but works  (:   2-20-95
   //clone_object("/room/start/nonew")->move(this_object());
// following added by Radix the ra//ceroom fixer
// disallow all combat in here, should anyhow   4-7-95

   add_property("no_undead",1);
  set_light(75);
  set_short("The Hall of Creation");
  set_long(
"Your immaterial form has found it's way to the Hall of Creation.  Here, you "
"will determine in part what you will become by selecting your race.  You "
"immediately notice several large statues supporting the high-arched ceiling "
"here.  Depicted herein are all the races: Drow, Duergar, Dwarf, Elf, Half-Elf, Gnome, "
"Goblin, Halfling, Human, Lizard-Man, Orc, and Half-Orc.\n\n"
"You think that if you examined a statue, you might find out more about what "
"that Race represents.\n\n"
"When you have chosen your race after careful research (For you will only be "
"allowed to choose -once-!) you must type:\n"
"\n"
"become <race>       For Example: become human\n\n");
add_item("statue","The statues are beautifully carved of solid granite, each "
"one respresenting a race that you might choose to become.  If you would like "
"to learn more about a particular race, you must examine one specifically, "
"For example: exa human    -or-   exa drow.\n");
add_item("hall","The Hall of Creation is where all new mortals begin the "
	"shaping of their lives.\n");
add_item("ceiling","The arched ceiling is painted with portraits of all the "
	"ruling dieties and Gods.\n");

  human = read_file(PATH+"human");
  halfelf = read_file(PATH+"half-elf");
  elf = read_file(PATH+"elf");
  drow = read_file(PATH+"drow");
  dwarf = read_file(PATH+"dwarf");
  gnome = read_file(PATH+"gnome");
  halfling = read_file(PATH+"halfling");
  halforc= read_file(PATH+"half-orc");
  orc= read_file(PATH+"orc");
  goblin = read_file(PATH+"goblin");
  lizardman = read_file(PATH+"lizard-man");
   duergar = read_file(PATH+"duergar");

  add_item("human", human);
  add_item("half-elf", halfelf);
  add_item("elf", elf);
  add_item("drow", drow);
  add_item("dwarf", dwarf);
  add_item("gnome", gnome);
  add_item("halfling", halfling);
  add_item("half-orc", halforc);
  add_item("orc", orc);
  add_item("goblin", goblin);
  add_item("lizard-man", lizardman);
  add_item("duergar",duergar);
}

int no_kill(string str) { return 1; }

void init()
{
  ::init();
  add_action("do_become", "be*come");
   add_property("nocast",1);
   add_property("noguild",1);
  /* Mask the action rearrange */
  add_action("do_rearrange", "rearrange");
   add_action("no_kill","at*tack");
   add_action("no_kill","kill");
}

int do_rearrange()
  {

   tell_object(this_player(),"Not allowed here, select a race and leave first.\n");
   return 1;
} /* do rearrange */

int do_become(string str)
{
 object me;
 string race;
   string robj;
 string startplace;
 int i;
 
 me = this_player();
 str = lower_case(str);
 
 /* The players should be able to pick a race only once.
  * Fixed by Baldrick, dec '94
  */

 /* Just for betatesting, you have to be "registrated" to be able to get
  * out of this room.
  * Baldrick, sept '95
  */

/*
  if (!me->query_registrated())
    {
    notify_fail("You have to be registrated, ask a Thane or higher for it.\n");
    return 0;
    }
*/

   robj = (string)me->query_race_ob();
   if( !( robj == "/std/races/unknown" || robj == "std/races/unknown" ) )
   if ((string)me->query_race_ob() != "std/races/unknown")
   {
/*  Commenting out level dependency  --Benedick 
   if(me->query_level() < 5)
*/
      startplace = "/room/entryroom.c";
/*
   else startplace = "/d/ss/swamp/sw2.c"; // Taniwha 1995, higher level players NOT to newbie zones
*/
   notify_fail("Your race has not been altered.\n");
   me->move(startplace);
   this_player()->do_cmd("look");
    return 0;
   } /* in (me */

   switch(str)
   {
   case "human":
   case "half-orc":
   case "half-elf":
   case "halfling":
   case "dwarf":
   case "drow":
   case "duergar":
   case "elf":
   case "orc":
   case "lizard-man":
   case "gnome":
   case "goblin":
      race = str;
   break;
   default:
      return 0;
   break;
 }
 if(race)
 {
   say(this_player()->query_cap_name()+" enters the "+race+" statue and "
    "disappears.\nA new "+race+" statue suddenly appears.\n", this_player());
   me->set_race_ob("/std/races/"+race);
   write("\nMoving you to the Entry Hall...\n\n");
   startplace = "/room/entryroom.c";
   // me->move("/room/start/"+race);
   me->move(startplace);
   this_player()->do_cmd("look");
   startplace->add_equipment();
   switch(race)
   {
      case "half-elf":
         me->add_language("human");
         me->add_language("elf");
      break;
      case "half-orc":
         me->add_language("human");
         me->add_language("orc");
      break;
      default:
         me->add_language(race);
      break;
   }
   return 1;
 }
 notify_fail("No such race, try again.\n");
 return 0;
}
