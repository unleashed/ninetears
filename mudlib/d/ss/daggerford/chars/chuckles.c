/*****************************************************
*   Chuckles, fencer of 'found' goods.   - Telluride *
******************************************************/
#define MONEYMAN "/obj/handlers/money_handler"
#define ARMORY "obj/handlers/armory"
inherit "/obj/monster";
int ran_mouth;

int idle_time;       /* how long picking nose */
string general_dir;  /* which direction have I been going in */
int price;
object mail,sword,cloak;

int buy(string s);
int price(string s);
void ssay(string s);

void setup() {


  ran_mouth=0;
  price=0;
  idle_time=0;
  general_dir="e";
  set_short("Chuckles the Fencer");
  add_alias("grifter");
  set_name("chuckles");
  set_long("A man experienced in all of the facets of property reallocation, \n"+
           "Chuckles is one of the major outlets for stolen material in this\n"+
           "area.  People from all walks of life often approach Chuckles to\n" +
           "'purchase' or 'price' his wares.\n");
  set_gender(1);
  set_race("human");
  set_race_ob("/std/races/human");
  set_guild("thief");
  set_level(10);
  give_money(15,5,"silver");
  set_al(10);
  sword=clone_object("/w/brebane/weap/lsword.c");
  sword->move(this_object());
  mail=clone_object("/w/brebane/arm/chain.c");
  mail->move(this_object());
  command("equip");

  load_a_chat(40,({
    1,"'Hey watch it!  You'll damage the merchandise",
    1,"'Are you the guy I sold that watch to?  I swear to God I thought it" +
      " was a real Vorpal Blade + 5!",
    1,"'Are you sure you don't need a set of cufflinks?"}));

}

void init() {
  ::init();
  add_action("buy","purchase");
  add_action("price","price");
}

int look_around(object room);
string find_exit(string *dirs);

string *exit_exists(string *dirs) {
  string *d;
  int i;

  d=({});
  for (i=0;i<sizeof(dirs);i+=2)
    if ((file_size(dirs[i+1]+".c")!=-1)||(file_size(dirs[i+1])!=-1)) {
      d+=({dirs[i]});
      d+=({dirs[i+1]});
    }
  return d;
}

void chuckles_brain(mixed n) {
  string *dirs;
  string *findirs;
  object room;
  string test;
  int i;

  idle_time+=1;
  room=environment();
  if (random(100)<20)
    i=look_around(room);

  dirs=(string *)room->query_dest_dir();
  findirs=exit_exists(dirs);
  if (sizeof(findirs)) {
  if ((idle_time >10) && (random(100)<50)) {
    if (((i=member_array(general_dir,findirs))== -1) || (random(100)<30)) {
      general_dir=findirs[random(sizeof(findirs)/2)*2];
    }
    else {
      command(findirs[i]);

      ran_mouth=0;
      idle_time=0;
    }
}
  }
}

int mine(object ob) {
  return (ob==sword || ob==mail || ob==cloak);
}
     
void heart_beat() {

  ::heart_beat();
 set_heart_beat(1);  /* Keep em awake */
  chuckles_brain(({0}));
}

int valid_inventory(object *inv) {

  int yes;
  int i;

  yes=0;
  for (i=0;i<sizeof(inv);i+=1)
    if ((((string)inv[i]->query_name()) != "coin") && !mine(inv[i]))
      yes=1;
  return yes;
}

int get_inv_index(object *inv) {

  int i;

  i=random(sizeof(inv));

  while (((string)inv[i]->query_name() == "coin") || mine(inv[i]))
    i=random(sizeof(inv));
}

void living_weenies(object doofus) {
  object *inv;
  string dname;
  string *poor;
  string message;
  string *mess;
  string money;
  int which,value;

  mess=({
    "Hey %s, you look like you need a %s.\n     For you, only %s.\n",
    "%s, I've got just what you've been lookin' for.\n A brand new %s.  Real cheap at %s.\n",
"Hey %s, I'll bet you've never seen a %s that looks this nice.\n      And for only %s.\n"});

  inv=all_inventory(this_object());
  if ((int)doofus->query_property_exists("bought_last") && (random(100)<20) && !ran_mouth) {
    ssay("Hey, " + (string)doofus->query_cap_name() + ", how was that " +
        (string)doofus->query_property("bought_last") + " I gave you?\n");
        ran_mouth=1;
    doofus->remove_property("bought_last");
}

  if ((valid_inventory(inv)) && !ran_mouth) {
    which=get_inv_index(inv);
    value=(int)inv[which]->query_value();
    value=value - (value/5);
    dname=capitalize((string)doofus->query_name());
    money=(string)MONEYMAN->money_string(MONEYMAN->create_money_array(value));

    if ((random(100)<10) && (this_object() != doofus)) {
       message=sprintf(mess[random(sizeof(mess))],dname,(string)inv[which]->query_short(),money);
      ssay(message);
       idle_time=4;
       ran_mouth=1;
    }
  }
}


void handle_stiff(object stiff) {

  object *inv;
  int i;

  do_command("take all from corpse");
  inv=all_inventory(this_object());
  for (i=0;i<sizeof(inv);i+=1)
    if ((int)inv[i]->query_value() < 200) {
      drop_ob(inv[i]->query_name());
  }
}

int look_around(object room) {

  object *inv;
  int i;
  string s1,s2;

  inv=all_inventory(room);
  if (sizeof(inv)) {
    for (i=0;i<sizeof(inv);i++) {
      if (!living(inv[i])) {  /* don't want people now */
        if (random((int)inv[i]->query_value()) > 200)
          do_command("take "+inv[i]->query_name());
        if (sscanf(inv[i]->query_short(),"corpse of %s",s1)==1) {
          if (!ran_mouth) {
            ran_mouth=1;
	  ssay("Awww. Poor " + capitalize(s1) + ".\n");
          }
	  handle_stiff(inv[i]);
          idle_time=9;
	}
      }
      else
        living_weenies(inv[i]);
    }
    return 1;
  }
  else
    return 0;
}

int price(string s) {

  string mon,mess;
  object asker;
  string *reply;
  int value;
  object *match;

  reply = ({
    "For you, only %s.\n",
    "Well, I have a special today.  Only %s.\n",
    "I want %s for that.\n"});

  idle_time=0;
  asker=this_player();

  if (!s || s=="")
    tell_object(asker,"Usage: price <object>\n  Tell how much Chuckles is willing to take for <object>\n");
  else {
    match=find_match(s,({this_object()}));
    if (!sizeof(match))
      buy(s);
    else {
      if (mine(match[0]))
        ssay("That's mine bozo.  It's not for sale.\n");
      else {
	value=(int)match[0]->query_value();
	value=value - (value/5);
	mon=(string)MONEYMAN->money_string(MONEYMAN->create_money_array(value));
	mess=sprintf(reply[random(sizeof(reply))],mon);
        tell_room(environment(),(string)asker->query_cap_name() +
         " asks chuckles about a " + (string)match[0]->query_short() + ".\n");
	ssay(mess);
      }
    }
  }
  return 1;
}
int buy(string s) {
  object *match;
  int value;
  object buyer;
  string who;
  string *nothere;
  string *poor;

  nothere= ({
    "Hey pal, only what you see.\n",
    "I ain't got any of those, bonehead.\n",
    "Are you tripping?  I ain't got one.\n"});

  poor = ({
    "Hey you honker, you ain't got the cash for that.\n",
    "Hey man, you need more money.  Get a job or something.\n",
    "What, you think I'm the Salvation Army?  Come back when you have enough money.\n"});

  buyer=this_player();
  if (!s || s=="")
    tell_object(buyer,"Usage:  purchase <object>\n");
  else {
    idle_time=0;
    who=(string)buyer->query_cap_name();
    match=find_match(s,({this_object()}));
    say(who + " asks Chuckles about for " + s + ".\n");
    if (!sizeof(match))
      ssay(nothere[random(sizeof(nothere))]);
    else {
      if (mine(match[0])) 
	ssay("Thats mine bozo. It's not for sale.\n");
      else {
	if (MONEYMAN->query_total_value(buyer->query_money_array()) < match[0]->query_value())
	  ssay(poor[random(sizeof(poor))]);
	else {
	  match[0]->move(buyer);
	  value=(int)match[0]->query_value();
	  value = value - (value/5);
	  buyer->pay_money(MONEYMAN->create_money_array(value));
	  this_object()->adjust_money(MONEYMAN->create_money_array(value));
	  who=sprintf("Chuckles gives you the %s.\n",match[0]->query_name());
	  tell_object(buyer,who);
	  say("Chuckles gives something to " + buyer->query_name());
          if ((int)buyer->query_property_exists("bought_last"))
            buyer->remove_property("bought_last");
            buyer->add_property("bought_last",(string)match[0]->query_short());
            ran_mouth=1;
	}
      }
      
    }
    
  }
  return 1;
}

void ssay(string s) {

  event(environment(),"say",query_cap_name() + " says: " + s,({}));
}
void chuckles_do(string str) {
  command(str);
}

adjust_hp(int num) {
  set_heart_beat(1);
  ::adjust_hp(num);
}
