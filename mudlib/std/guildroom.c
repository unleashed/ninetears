/* bALdrick was here.
 * Added set_thac0 / adjust THAC0 
 * Removed the skilltree from cost until I know what to do with it.
 * Added exponential XP-cost. june '94.
 * Taniwha 1995 (just), make advance SET thac0 rather than adjust it
   * fixes transition probs from newbie guild and compensates for any thac0
   * accidents
 */

inherit "/std/room";
void clean_up(int flag) { }

#include "skills.h"
#include "tune.h"
#include "money.h"
#include "level_track.h"
#define my_race_ob this_player()->query_race_ob()
#define SPELL_TABLE "/table/spell_table.c"

string our_guild,
       guild_path,
       teaching_person,
       parent_guild,
       /* To have spec as an array, a guild can specialize on more gods
        */
       *spec;
 
mixed *spells,
      *commands;

void check_spells_commands(string *sk, int lvl);
int query_specialization(string name);
int this_guild();
string rec_cost(mixed *arr,string path,int depth, string g_o);
int check_before_join()
{
   return 1;
}
int check_before_join1()
{
   return 1;
}


void setup()
  {
  set_short("A guild Room");
  set_long("Its a guild room.\n");
  }

void create() {
  spells = ({ });
  spec = ({ });
  commands = ({ });
  ::create();
} /* create() */

void init() {
  ::init();
   this_object()->add_property("no_undead",1);
  add_action("do_advance", "ad*vance");
  add_action("train","train");
  add_action("do_join", "join");
  add_action("do_info", "inf*o");
  add_action("do_cost", "co*st");
//  add_action("do_specialize", "spe*cialize");
  add_action("do_join", "spe*cialize");
  add_action("do_learn", "learn");
  add_action("do_learn", "pray");
  //add_action("do_leave", "leave");
} /* init() */

int this_guild()
  {
  string guild;

  guild = this_player()->query_guild_ob();
  if ((guild==our_guild) || 
      (query_specialization(guild)))
    {
    return 1;
    }
  else 
    { 
    return 0;
    }
  }

void set_guild(string str) { our_guild = "/std/guilds/"+str; } 
void set_parent_guild(string str) { parent_guild = "/std/guilds/"+str; } 
string query_guild() { return our_guild; }

int do_advance_level() 
{
  string skill;
  string *bits;
  int cost,i,lvl,total_xp,p_val,max_lvl;
  float xp;
  string guild,my_race;
   if(this_object()->check_before_join2()) return 0;
  
  my_race=(string)my_race_ob->query_name();

  lvl = (int)this_player()->query_level();
  guild=this_player()->query_guild_ob();

  if (!guild)             /* Have we joined any guild at all ? */
  {
    notify_fail("If you 'join' you can advance here.\n");
    return 0;
  }

  /* If so, is it this_guild  or a specialization therin ? */
  if (guild != our_guild) 
    {
    notify_fail("You cannot advance here! Go to your own guild.\n");
    return 0;
  }

  /* Hmm... */
 //  !query_specialization(guild))

/* The following bit is removed awaiting code from Dan.  He'll produce code
 * to compute the actual computing of raising in skill-levels.  I've declared
 * string *bits; for dividing up the skill-bits, but can do no more since I
 * honestly don't know how it'll work.
 * 7.1.93: Put back so that we can test other things while waiting.  
 */

  xp = (int)our_guild->query_xp_cost();  /* How much xp/lvl it will cost */

  /* This function is exponential, I think it can be done easier..*/

  for (i=2;i<=lvl;i++)
    {
    if (i <= 5)
      xp *= 1.9;
     else
      {
      if (i <= 10)
        xp *= 1.5;
       else
        xp *= 1.1;
      }
    }

  total_xp = xp;

  if(((int)this_player()->query_xp()) < (total_xp+1))
  {
      notify_fail("Your lack of experience prevents you from advancing.\n");
      return 0;
  }

 /* Checks racial max level */
  ++lvl;
  max_lvl = (int)my_race_ob->query_max_level(guild);
  if (lvl >= max_lvl) 
  {
    notify_fail("You can advance higher than "+lvl+" because you're a "+
                 my_race+".\n");
    return 0;
  }

/*  Monetary payment to advance in level   */
  cost = (int)our_guild->query_advance_cost();
    /* Default cost if not defined.  Thought 500 GP/level was OK  */
  cost *= (lvl);           /* Total monetary cost of advancing */
 
  p_val = (int)this_player()->query_value(); /* How much money do we have */

  if (cost > p_val)  /* What happens if we can't pay */ 
  {
     notify_fail("Due to your sad lack of money the guild refuses to train "
                 "you.  It would have cost you "+
                 MONEY_HAND->money_value_string(cost)+".\n");
     return 0;
  }
// DON"T remove this, player.c blocks the adjust level and they lose the XP and whine mercilessly
  if(!this_player()->query_registrated())
   {
       write("Taniwha tells you: You need to register now, consider your role here, \"describe\" yourself, and ask an immortal to register you.\n");
      return 0;
   }
  this_player()->adjust_level(1);
  this_player()->adjust_xp(-total_xp);
  this_player()->pay_money(MONEY_HAND->create_money_array(cost));
  catch(LEVEL_HAND->level_advanced(this_player()));

  /* Ok, calculate the new (if new) THAC0 here: */
  /* New every level now, this time it uses it to check how many 
   * slots it will decrease.
   * Baldrick, aug '95. 
   */
   
  //if (!(lvl % (int)our_guild->query_thac0_step()) ) 
   //  this_player()->adjust_thac0(-1);
  //this_player()->adjust_thac0( - (int)our_guild->query_thac0_step());
   this_player()->set_thac0( 200 - (this_player()->query_level() * (int)our_guild->query_thac0_step()) );

  write("You advance to level "+lvl+" for "+ 
        MONEY_HAND->money_value_string(cost)+".\n");
  say(this_player()->query_cap_name()+" advances "+
      this_player()->query_possessive()+" level.\n");
  this_player()->save();
  return 1;
} /* do_advance_level() */

/* Here we shall make it possible to advance in their proficiencies..
 * Baldrick may '95.
 */
int do_advance(string str)
  {
  if (!str)
    return do_advance_level();
  /* Here we need smoe really clever bits.. */
 
} /* do_advance.. */

/* Some of the code I planned to use for proficiencies.  Just left some of 
 * it here in case it's of any use to Dank
 * Hmm, not needed yet, Baldrick. 
 */
int train(string str) 
  {
  string skill_name, sk, g_o;
  string *bits;
  int cost, i, lvl, tmp, to, by, max_lvl, total_xp, total_cost, p_val;

  if ((g_o=(string)this_player()->query_guild_ob()) != our_guild && g_o) {
    notify_fail("You cannot train here! Go to your own guild.\n");
    return 0;
  }
  if (!str) {
    notify_fail(sprintf("Syntax: %-*#s\n", this_player()->query_cols(),
        "train <skill>\ntrain <skill> to <level>\n"+
        "\ntrain <skill> by <level>\n"));
    return 0;
  }
  if ((sscanf(str, "%s to %d", sk, to) != 2) &&
      (sscanf(str, "%s by %d", sk, by) != 2)) {
    sk = str;
    by = 1;
  }
  bits = explode(implode(explode(sk, " "), "."), ".");
  if (!(skill_name = (string)SKILL_OB->query_skill(bits))) {
    notify_fail("I am sorry but the skill " + sk + " does not exist.\n");
    return 0;
  }
  lvl = (int)this_player()->query_skill(skill_name);
  if(!by && to) by = to - lvl;
  if(by <= 0) {
    if(by == 0) notify_fail("You are already at level " + lvl + " at " +
        skill_name + ".\n");
    else notify_fail("You cannot regress below your current skill level!\n");
    return 0;
  }
  if ((sizeof(explode(skill_name, "."))-1)*5 > lvl) {
    notify_fail("Not a high enough level in the outer skills to advance "+
                "that yet.\n");
    return 0;
  }
  if (!g_o)
    max_lvl = 5;
  else
    max_lvl = (int)our_guild->query_max_skill_level(skill_name);
  if (lvl >= max_lvl) {
    notify_fail("You cannot advance in that skill any further here.\n");
    return 0;
  }
  if (!g_o)
    cost = DEFAULT_COST; 
  else
    cost = (int)our_guild->query_skill_cost(skill_name);
  cost *= (int)SKILL_OB->query_skill_cost(skill_name);
  cost *= STD_COST/5;
  p_val = (int)this_player()->query_value();
  for (i=0;i<by;i++) {
    tmp = cost * ( ((lvl + i)/LEVEL_DIV) + 1);
    if(this_player()->query_xp() < tmp+total_xp) {
      if(!i) {
        notify_fail("Your lack of experience prevents you improving " +
          sk + ".\n");
        return 0;
      } else {
        write("Your lack of experience prevents you taking all the " +
        "advancement you requested.\n");
      }
      break;
    }
    if (lvl + i >= max_lvl) {
      write("Your guild hasn't the resources to train you as far as "+
            "you requested.\n");
      break;
    }
    if (((tmp/COST_DIV)+total_cost) > p_val) {
      if(!i) {
        notify_fail("Due to your sad lack of money the guild cannot train "+
                    "you in "+sk+", it would have cost you "+
                    MONEY_HAND->money_value_string(tmp/COST_DIV)+".\n");
        return 0;
      } else {
        write("Due to your sad lack of money the guild cannot train "+
             "you in "+sk+" to "+(i+lvl)+", it would have cost you "+
             MONEY_HAND->money_value_string(tmp/COST_DIV)+".\n");
      }
      break;
    }
    total_xp += tmp;
    total_cost += tmp/COST_DIV;
  }
  this_player()->adjust_xp(-total_xp);
  this_player()->pay_money(MONEY_HAND->create_money_array(total_cost));
  this_player()->add_skill_level(skill_name, i);
  event(this_object(), "guild_advance", bits, lvl, lvl+i);
  check_spells_commands(bits, lvl+i);
  write("You advance your skill in " + sk + " from " + lvl + " to " +
        (lvl + i) + " for " + total_xp + " xp and " +
        MONEY_HAND->money_value_string(total_cost) + ".\n");
  say(this_player()->query_cap_name()+" advances "+
      this_player()->query_possessive()+" skills.\n");
  this_player()->reset_all();
  return 1;
} /* train()  */


int do_join(string str) 
{
  string guild;
  string race;
  int mainskill;

  guild = (string)this_player()->query_guild_ob();
  race  = (string)this_player()->query_race();

  if(guild == our_guild) 
  {
    notify_fail("You're already in this guild.\n");
    return 0;
  }

  /* Adding a check to find parent guild.. they can join upwards.. */
  /* Not needed yet.. B.
  */
  if(guild)
    //if (our_guild->query_parent_guild() != guild->query_parent_guild())
    {
    notify_fail("You cannot join a guild while a member of another.\n");
    return 0;
    }

  if(!our_guild->query_legal_race(race))
  {
    notify_fail("Sorry, but a "+race+" can't become a "+
     our_guild->query_name()+".\n");
    return 0;
  }

  /* Adding a simple main skill limit.
   * The players shall have at least 13 in the main skill to be allowed to
   * join a guild.
   * Baldrick, dec '94
   * Hrmf, ugly code, not exactly effective, but it works.
   */

  switch((string)our_guild->query_main_skill())
    {
   case "cha":
      mainskill = this_player()->query_cha();
    case "str":
      mainskill = this_player()->query_str();
      break;
    case "dex":
      mainskill = this_player()->query_dex();
      break;
    case "con":
      mainskill = this_player()->query_con();
      break;
    case "int":
      mainskill = this_player()->query_int();
      break;
    case "wis":
      mainskill = this_player()->query_wis();
      break;
    }

  if (mainskill<13)
    {
    notify_fail("You are not skilled enogh for this guild, try another that"+
                " utilizes your skills better.\n");
    return 0;
    } 
   if(!this_object()->check_before_join()) return 0;

  if (guild)
    write("You will only ever specialize yourself once. Are you sure? ");
   else
    write("You will only ever get to join one guild.  Are you sure? ");
  input_to("join2");
  return 1;
} /* do_join() */

/*  Not quite finished converting this.  Waiting for Dank's skills system */
int join2(string str) 
  {
  mixed skills;
  int i;

  str = lower_case(str);
  if (str[0] != 'n' && str[0] != 'y') {
    write("I do not understand.  Yes or no? ");
    input_to("join2");
    return 1;
  }
  if (str[0] == 'n') {
    write("Ok, not joining the "+ our_guild->query_name()+" guild.\n");
    return 1;
  }
  this_player()->set_guild_ob(our_guild);
  this_player()->race_guild_commands();

  /* Adding this..:=) Baldrick. */
  if ( our_guild->query_extr_str() && 
       this_player()->query_str()>=18 )
    {
    tell_object(this_player(), "Rolled extreme strenght.\n");
    this_player()->set_extreme_str(roll(1,10));
    }

  write("You are now a member of the " +
          our_guild->query_cap_name()+"'s guild.\n");

  say(this_player()->query_cap_name()+" joins the "+our_guild->query_name()+
          " guild.\n");

  event(this_object(), "guild_join");
  event(users(), "inform", this_player()->query_cap_name()+" is now a member "+
            "of "+our_guild->query_name(), "join");

  skills = (mixed *)this_player()->query_skills();
  for (i=0;i<sizeof(skills);i+=SKILL_ARR_SIZE) {

/* This will only set up the outer skill-bits (str, dec, con etc.) */

    check_spells_commands(skills[i+SKILL_NAM..i+SKILL_NAM],
                          skills[i+SKILL_LVL]);
  }
// Taniwha 14/09/1995. Not needed, they get to L5 before they join now
  //this_player()->adjust_level(1);
  this_player()->reset_spheres();
  this_player()->reset_spellarray();
  this_player()->add_spheres(our_guild->query_legal_spheres());
  return 1;
} /* join2() */

/* Moved from the guild objects and into here for memory saving */
/* Baldrick november '93 */

mixed query_legal_spells()
  {
  mixed list;
  list = ({ });

  list = SPELL_TABLE->query_spellist();
  return list;
  }

int query_legal_spell(string spell)
  {
  int tin;

  if (tin = member_array(spell, query_legal_spells()) != -1)
    return 1;
  return 0;
  }

void set_teaching_person(string bing)
  {
  teaching_person = bing;
  }

int do_learn(string str)
{
  mixed spells;
  string guild;

  spells = ({ });

  if(!sizeof(find_match(teaching_person, environment(this_player()))))
  {
    notify_fail("There is noone here that can teach you any spells.\n");
    return 0;
  }

  guild = (string)this_player()->query_guild_ob();
  if (our_guild != guild)
    {
    notify_fail("You are not a member of this guild.\n");
    return 0;
    }

  //spells = guild->query_legal_spells();
  spells = query_legal_spells();

  if(!str)
  {
   if(spells)
   {
    printf("You can learn these spells:\n%-#*s\n", 
       this_player()->query_cols(),implode(spells, "\n"));
    return 1;
   }
   else
   {
  notify_fail("You can learn no more spells until you reach a higher level.\n");
    return 0;
   }
  }

  else if(!query_legal_spell(str)) 
  {
    notify_fail("You can't learn that spell here, sorry.\n");
    return 0;
  }

  /* this just can't be done... */
  /* have to find another method, or find out the smartest way of getting the 
     directory and filename from the spell_table */ 
  this_player()->add_spell(str,
		 SPELL_TABLE->query_spellfilename(str));
  write("You learn " + str + ".\n");
  return 1;
}

/* This is not supposed to be possible until we allow for dual-classes.
 * I moved the leave code here since I felt you should have to be in the 
 * room of your guild when you leave.  It's easily moved back to the guild-
 * object if most of you prefer it that way.  
 */
int do_leave(string str) 
{
  if(str != "guild") {
    notify_fail("Syntax : leave guild\n");
    return 0;
  }
  if ((string)this_player()->query_guild_ob() != our_guild) {
    notify_fail("How can you leave a guild if you aren't in it.\n");
    return 0;
  }
  if ((int)this_player()->query_level() > 5) {
    notify_fail("You are too high a level to leave this guild.\n");
    return 0;
  }
  write("Are you sure you want to leave the guild (Y/N) : ");
  input_to("confirm_leave");
  return 1;
} /* do_leave() */

void confirm_leave(string str) {
  str = lower_case(str);
  if(str != "y") {
    write("You are still in the guild.\n");
    return;
  }
  write("You left your guild.\n");
  call_other(our_guild, "leaving_guild");
  this_player()->set_guild_ob(0);
  this_player()->set_guild_data(0);
  this_player()->guild_commands();
  this_player()->save_me();
} /* confirm_leave() */

/*  Will have to be rewritten a lot if we choose tell players how much xp 
 * they'll need to advance in each skill/subskill
 */
int do_cost(string str)
{
  string guild, cost;
  int lvl, i;
  int xp_cost;
  float tmp_xp_cost;
  mixed *arr;

  guild = (string)this_player()->query_guild_ob();
  xp_cost = (int)our_guild->query_xp_cost();
  lvl = (int)this_player()->query_level();
  cost = MONEY_HAND->money_value_string(((int)our_guild->query_advance_cost()
                                             * (lvl +1)));
  arr = (mixed *)SKILL_OB->query_skills();

/* Nope, this will be put back later
 * 
if(str && str !=""){
 printf("%-*'='s\n",this_player()->query_cols(),"======SKILLS=======Cur/Max==For Next");
 printf("%#*-s\n",this_player()->query_cols(),rec_cost(arr,"",1,our_guild));
 printf("%*'='|s\n",this_player()->query_cols(),"> You have " 
  +this_player()->query_xp()+" points to spend <");
}
 */
  if(!guild)
  {
    notify_fail("If you join this guild you will have to earn "+
     xp_cost+" XP, and expect to pay "+cost+" to reach 2nd level.\n");
    return 0;
  }
    
  if (!this_guild()) 
  {
    notify_fail("You are not a member of this guild.\n");
    return 0;
  }

/* Checks for racial max levels not yet implemented   *************
  max_lvl = (int)my_race_ob->query_max_level(guild);
  if (lvl == max_lvl)
  {
    notify_fail("You can't advance higher than "+lvl+" because you're a "+
                 my_race+".\n");
    return 0;
  }
*/
  /* Exponential xp cost... this method should be simplified!
   * Baldrick.. */

  tmp_xp_cost = xp_cost;
  for (i=2;i<=lvl;i++)
    {
    if (i <= 5)
      tmp_xp_cost *= 1.9;
     else 
      {
      if (i <= 10)
        tmp_xp_cost *= 1.5;
       else
        tmp_xp_cost *= 1.1;
      }
    }

  xp_cost = tmp_xp_cost;
  write("You will need "+xp_cost+" XP and "+cost+
        " to advance to level "+(lvl+1)+".\n");
  return 1;
} /* do_cost() */

/* The same goes for do_info() as for do_cost() of course */
int do_info() 
{
  write(our_guild->long());
  do_cost("");
  return 1;
} /* do_info() */

/*
 * From here on are the changes to make level gaining hopefully more
 * realistic...  (Note the more :)
 */
void add_spell(string name, string *path, int lvl) {
  spells += ({ name, path, lvl });
} /* add_spell() */

void add_command(string name, string *path, int lvl) {
  commands += ({ name, path, lvl });
} /* add_command() */

int query_specialization(string name)
{ 
  if(member_array(name,spec) != -1)
    return 1;
  return 0;
}

void add_specialization(string name) 
{ 
    spec += ({ name });
}  /* add_specialization() */

int do_specialize(string name)
{
  string path;

  if (!name) 
    {
    notify_fail("You have to specialize to a certain God.\n");
    return 0;
    }
  if((string)this_player()->query_guild_ob() != our_guild) 
  {
    notify_fail("You can't specialize in this guild since you're not a "+
                "member.\n");
    return 0;
  }

  if((int)this_player()->query_level() != 1)
  {
    notify_fail("You can't specialize after you've already advanced in "+
                "level.\n");
    return 0;
  }

  if (query_specialization(name))
  {
    path = "/std/race"->query_guild_path(name);
    tell_room(this_player(), this_player()->query_cap_name()+" specialices "+
      "and becomes a "+name+".\n", this_player());
    write("You're accepted as a "+name+" specialist.  CONGRATULATIONS!!!\n");
    this_player()->set_guild_ob(path); 
    return 1;
  }
  notify_fail("That's not a valid specialization.\n");
  return 0;
}  /* do_specialize() */

string query_teaching_person() { return teaching_person; }

void check_spells_commands(string *path, int lvl) {
  int i, j;

  if ((!find_match(teaching_person, environment(this_player())) 
      || (member_array(this_player(), 
	(object *)find_living(teaching_person)->query_attacker_list()) != -1)))
    return ;

  for (i=0;i<sizeof(spells);i+=3)
    for (j=0;j<sizeof(spells[i+1]);j++)
      if (j >= sizeof(path)) { // got through the skill path ok. 
        if (spells[i+2] <= lvl)
           teaching_person->init_command("teach "+spells[i]+" to "+
                                         this_player()->query_name());
      } else
        if (spells[i+1][j] != path[j])
          break;

  for (i=0;i<sizeof(commands);i+=3)
    for (j=0;j<sizeof(commands[i+1]);j++)
      if (j >= sizeof(path)) {  // got through the skill path ok. 
        if (commands[i+2] <= lvl)
           teaching_person->init_command("teach "+commands[i]+" to "+
                                         this_player()->query_name());
      } else
        if (commands[i+1][j] != path[j])
          break;
}  /* check_spell_commands() */

query_spells() { return spells + ({ }); }
query_commands() { return commands + ({ }); }

/* This is not pretty, but I added it in case Dank feel like giving the players
 * some info of how much xp it will cost to advance in skills.
 */
string rec_cost_old(mixed *arr, string path, int depth) {
  int i;
  int cost;
  string str, lpath;

  str = "";
  for (i=0;i<sizeof(arr);i+=SKILL_ARR_SIZE) {
    lpath = path + "." + arr[i];
    cost = (int)SKILL_OB->query_skill_cost((lpath)[1..500]);
    cost *= (int)our_guild->query_skill_cost((lpath)[1..500]);
    str += sprintf("%*'| 's%-*'.'s costs %d xp.\n", (depth-1)*2, "",
             20-(depth-1)*2, arr[i],
             cost*STD_COST*(((int)this_player()->query_skill(lpath)
                  /LEVEL_DIV)+1));
    if (this_player()->query_skill(lpath) >= depth*5)
      str += rec_cost_old(arr[i+SKILL_BIT], path+"."+arr[i], depth+1);
  }
  return str;
} /* rec_cost_old() */

string rec_cost(mixed *arr, string path, int depth, string g_o)
{ /* use lots of variables...so we only work things out minimum times */
  int i, depth_gap, ndots;
  int cost, lvl, max_lvl;
  string str, lpath;

  str = "";
  depth_gap = (depth - 1) * 2;
  ndots = 18 - depth_gap;

  for (i=0;i<sizeof(arr);i+=SKILL_ARR_SIZE) {
    if (path != "")
      lpath = path + "." + arr[i];
    else
      lpath = arr[i];
    lvl = (int)this_player()->query_skill(lpath);
    if (!g_o)
      max_lvl = 5;
    else
      max_lvl = (int)g_o->query_max_skill_level(lpath);
    if(lvl >= max_lvl) {
      str += sprintf("%*'| 's%-*'.'s %3d/%3d  mastered\n", depth_gap, "",
                     ndots, arr[i], lvl, max_lvl);
    } else {
      if (!g_o)
        cost = DEFAULT_COST;
      else
        cost = (int)g_o->query_skill_cost(lpath);
      cost *=  (int)SKILL_OB->query_skill_cost(lpath);
      cost *= (STD_COST/5)*((lvl/LEVEL_DIV)+1);
      str += sprintf("%*'| 's%-*'.'s %3d/%3d %6d xp\n", depth_gap, "",
               ndots, arr[i], lvl, max_lvl, cost);
    }
    if (lvl >= depth*5)
      str += rec_cost(arr[i+SKILL_BIT], lpath, depth+1, g_o);
  }
  return str;
} /* rec_cost() */

