/* The rearranging of stats.. A once per player thingie..
 * Hmm, this should be a command? could that save memory?
 * Baldrick.
 * Added some neat stuff, and fixed some bugs.
 * This is the command version of the Rearrange. 
 */

#define MIN 6
static int me_str, me_int, me_dex, me_con, me_wis, me_cha;
static int pool;
object me;

void do_save();
void get_stat_bit(string str);

static private string b(int i) 
  {
  return (string)me->stat_string(i);
}

void display_stats() 
  {
  /* Changed this to (hopefully) fix rearrange (again) 
   * Baldrick, aug '94.
   */
  printf("Str: %d Dex: %d Con: %d Int: %d Wis: %d Cha: %d Pool: %d\n", 
   me_str, me_dex, me_con, me_int, me_wis, me_cha, pool);
   // b(me_str), b(me_dex), b(me_con), b(me_int), b(me_wis), b(me_cha), pool);
}

int do_rearrange(string str, object foo) 
  {
  if (!foo)
    foo = this_player();
   else
    me = foo; 
  /*
  if (me->query_property("stats_rearranged")) 
    {
    notify_fail("You have already arranged your stats.\n");
    return 0;
    }
  */
  write("\nYour Racial bonuses are:\n""str: "+me->query_bonus_str()+" dex: " +
        me->query_bonus_dex() + " con: " + me->query_bonus_con() + " int: " +
        me->query_bonus_int() + " wis: " + me->query_bonus_wis() + " cha: " +
        me->query_bonus_cha() + "\n");
  write("These bonuses will be added to the stats you make here.\n");
  me_str = (int)me->query_real_str();
  me_dex = (int)me->query_real_dex();
  me_int = (int)me->query_real_int();
  me_con = (int)me->query_real_con();
  me_wis = (int)me->query_real_wis();
  me_cha = (int)me->query_real_cha();
  pool = 0;
  if (me_str > MIN) {
    pool += me_str-MIN;
    me_str = MIN;
  }
  if (me_int > MIN) {
    pool += me_int-MIN;
    me_int = MIN;
  }
  if (me_wis > MIN) {
    pool += me_wis-MIN;
    me_wis = MIN;
  }
  if (me_con >MIN) {
    pool += me_con-MIN;
    me_con = MIN;
  }
  if (me_dex > MIN) {
    pool += me_dex-MIN;
    me_dex = MIN;
  }
  if (me_cha > MIN) {
    pool += me_cha-MIN;
    me_cha = MIN;
  }
  write("Entry...\n");
  write("Type \"d 8\" to add 8 points to your dexterity from the pool.  "
        "or \"d -8\" to remove 8 points from dextreity and add them to "
        "the pool. \"Save\" will save and quit at the current position, "
        "\"reset\" will reset you back to your starting position "
        "and \"quit\" will quit and not save your changes.\n");
  get_stat_bit("");
  return 1;
}

int get_stat_bit(string str) 
  {
  string stat;
  int num;

  if (lower_case(str) == "save") {
    if (pool) {
      write("You still have some points in your pool are you sure you "
            "want to save [y/n]? ");
      input_to("get_check");
      return 1;
    }
    write("Ok saving...\n");
    do_save();
    return 1;
  }
  if (lower_case(str) == "quit") {
    write("Ok... Quiting.\n");
    return 1;
  }
  if (lower_case(str) == "reset") {
    write("Ok, reseting back to defaults.\n");
    return do_rearrange("fog", me);
  }
  sscanf(str, "%s %d", str, num);
  stat = lower_case(implode(explode(str, " "), ""));
  if (num > pool)
    if (!pool) {
      write("Cannot add to stat.. Need to put things into the pool first.\n");
      stat = "";
    } else {
      write("Pool has only "+pool+" points in it.. adding these to stat.\n");
      num = pool;
    }
  switch (stat[0]) {
    case 'd' :
      if ((me_dex-6) <= -num) {
        write("Cannot set your stats to less than "+MIN+".\n");
        num = 0;
      } else
        me_dex += num;
      if (me_dex > 18) {
        num -= me_dex-18;
        me_dex = 18;
      }
      break;
    case 'c' :
      if ((me_con-6) <= -num) {
        write("Cannot set your stat to less than "+MIN+".\n");
        num = 0;
      } else
        me_con += num;
      if (me_con > 18) {
        num -= me_con-18;
        me_con = 18;
      }
      break;
    case 'i' :
      if ((me_int-6) <= -num) {
        write("Cannot set your stat to less than "+MIN+".\n");
        num = 0;
      } else
        me_int += num;
      if (me_int > 18) {
        num -= me_int-18;
        me_int = 18;
      }
      break;
    case 'w' :
      if ((me_wis-6) <= -num) {
        write("Cannot set your stat to less than "+MIN+".\n");
        num = 0;
      } else
        me_wis += num;
      if (me_wis > 18) {
        num -= me_wis-18;
        me_wis = 18;
      }
      break;
    case 's' :
      if ((me_str-6) <= -num) {
        write("Cannot set your stat to less than "+MIN+".\n");
        num = 0;
      } else
        me_str += num;   
      if (me_str > 18) { 
        num -= me_str-18;
        me_str = 18;
      }
      break;  
    case 'h' :       /* Put this in here so rearrange works for charm. also*/
      if ((me_cha-6) <= -num) {    /* Lagg 11 feb. 1994 */
        write("Cannot set your stat to less than "+MIN+".\n");
        num = 0;
      } else
        me_cha += num;
      if (me_cha > 18) {
        num -= me_cha-18;
        me_cha = 18;
      }
      break;

    default :
      num = 0;
      break;
  }
  pool -= num;
  display_stats();
  write("Entry [d|c|i|w|s|h|save|reset|quit] <num> : ");
  input_to("get_stat_bit");
  return 1;
}

void get_check(string str) 
  {
  str = lower_case(str);
  if (str[0] != 'y') {
    write("Ok going back to stat entering.\n");
    get_stat_bit("");
    return;
  }
  do_save();
  write("Ok saved.\n");
  return ;
}

void do_save() {
  me->set_con(me_con);
  me->set_dex(me_dex);
  me->add_property("stats_rearranged", 1);
  me->set_int(me_int);
  me->set_wis(me_wis);
  me->set_str(me_str);
  me->set_cha(me_cha);
}
