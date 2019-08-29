
#define BARD "/std/guilds/rogues/assassin"
#define WIZARD "/std/guilds/wizards/general_mage"
#define THIEF "/std/guilds/rogues/thief"
#define CLERIC "/std/guilds/cleric.c"
#define FIGHTER "/std/guilds/warriors/fighter"

inherit "/std/room";
// Newbie guild, Free and it bases your throws on the guild that approximates
// your stats
int clean_up_room(int flag) { return 1; }
object find_guild(object player);
int calc_xp(object guild, int lvl);

/* bALdrick was here.
 * Taniwha followed
 * take a guess at what guild they may end up in and use that for XP calcs
*/

object board;


#define my_race_ob this_player()->query_race_ob()


void setup()
{
  set_short("A guild Room");
  set_long("Its a guild room.\n");
}

void reset() {
  if(!board) {
    board = clone_object("/obj/misc/board");
    board->set_datafile("playerinfo");
    board->move(this_object());
  }
   ::reset();
}

void dest_me() {
  if(board)
    board->dest_me();
  ::dest_me();
}

int do_info(string str)
{
    write(
    "Welcome to your guild.\n You can advance here for free "
    "once you obtain the required experience at each level.\n"
    "Once you reach level 5 you will have to find your way "
    "out into the big wide world and join another guild "
    "to advance further.\n"
    "Advance to level 1 requires no XP, but you may wish "
    "to consider using the \"rearrange\" command first. "
    "Your stats rolls here are influenced by your current "
    "stats based on a best guess of which guild they would "
    "be suited for in later life.\n"
    "Note that there is no long term advantage in the stats "
    "rolls gained here, after time they will tend to approach "
    "the average for your final guild.\n"
    "Not all the guilds outside here will be easy "
    "to find, however most of the basic guilds are "
    "represented in Daggerford and Banefall.\n"
    );
    return 1;
}
int do_cost(string str)
{
    int lvl,total_xp;
    object guild;
    lvl = (int)this_player()->query_level();
    guild=find_guild(this_player());
    switch(lvl)
    {
    case 0:
        write("It will cost you nothing to advance to level 1.\n"
        "You may want to read the \"info\" first however.\n");
        return 1;
    break;
    case 1..4:
        total_xp = calc_xp(guild,lvl);
        write("It will cost you "+total_xp+" XP to advance here.\n");
   break;
   default:
       write("You can advance no further here, time to find your "
       "way out into the wide world adventurer.\n");
   break;
   }
   return 1;
}



void init() {
  ::init();
   this_object()->add_property("no_undead",1);
  add_action("do_advance", "ad*vance");
  add_action("do_info", "inf*o");
  add_action("do_cost", "co*st");
} /* init() */

// Oh joy, Oh bliss, try to work out what sort of rolls they should get
// a couple of points , this doesn't need to be great, just close enough
// to give them an edge
// Also if you don't re-arrange you'll probably get fighter like stats
// This may give mages who arrange late an edge, their subsequent rolls
// will suck tho. so eventually it works out.

object find_guild(object player)
{
   int str,cha,xint,con,wis,dex;
    object guild;
    string gname;
// ignore con, it's universal
    str = player->query_str();
    dex = player->query_dex();
    xint = player->query_int();
    wis = player->query_wis();
    cha = player->query_cha();
//    con = player->query_con();
    if( (cha > dex) &&(cha > xint) && (cha > wis) && (cha > str) )
    {
        gname = BARD;
    }
      else if( (xint > dex) &&  (xint > cha)&& (xint >wis) && (xint >str) )
    {
        gname = WIZARD;
    }
    else if( (wis > dex) && (wis > cha) && (wis > xint) && (wis > str) )
    {
        gname = CLERIC;
    }
    else if( dex > str)
    {
        gname = THIEF;
    }
    else gname = FIGHTER;
    if(this_player()->query_creator())
    {
        write("Base guild is "+gname+"\n");
    }
    guild = find_object(gname);
    if(!guild) guild = new(gname);
    return guild;
}

int calc_xp(object guild,int lvl)
{
   int i,xp_cost;
  float xp;
  
  xp_cost = (int)guild->query_xp_cost();  /* How much xp/lvl it will cost */
  xp = xp_cost;
  /* This function is exponential, I think it can be done easier..*/

  for (i=2;i<=lvl;i++)
  {
    switch(i)
    {
    case 0..5:
      xp *= 1.9;
    break;
    case 6..10:
      xp *= 1.5;
    break;
    default:
      xp *= 1.1;
    break;
    }
  }

  xp_cost = xp;
  return xp_cost;
}


int do_advance() 
{
  int cost,i,lvl,total_xp;
  object guild;


  lvl = (int)this_player()->query_level();
  guild=find_guild(this_player());
  switch(lvl)
  {
  case 0:
    total_xp = 0;
  break;
  case 1..4:
    total_xp = calc_xp(guild,lvl);
    if(((int)this_player()->query_xp()) < (total_xp+1))
    {
      notify_fail("Your lack of experience prevents you from advancing.\n");
      return 0;
    }
  break;
  default:
     write("You can advance no further here, time to find your "
    "way out into the wide world adventurer.\n");
    return 1;
  break;
  }
  this_player()->adjust_level(1);
  this_player()->adjust_xp(-total_xp);
  /* Ok, calculate the new (if new) THAC0 here: */
  if (!(lvl % (int)guild->query_thac0_step()) )
         this_player()->adjust_thac0(-1);
  write("You advance to level "+(lvl+1)+".\n");
  say(this_player()->query_cap_name()+" advances "+
  this_player()->query_possessive()+" level.\n");
  this_player()->save();
  guild = 0;
  return 1;
} /* do_advance() */
