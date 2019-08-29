inherit "/obj/monster";
static int detect_skill;
static int disarm_skill;
string myzot = "/std/spells/wizard/fireball";
int max_time = 500;
int query_alive() { return 0; }
int query_dead() { return 1; }
void attack_by(object ob)
{
   if(ob)
   {
      ob->stop_fight(this_object());
   }
}

void setup() {
    add_alias("trap");
    set_long("");
    set_level(10+random(8));
    set_random_stats(6, 18);
    set_int(roll(1, 4)+14);

} /* setup() */
void init() {

    add_action("do_search","search");

    ::init();

}
// Not quite, give them a chance which is guild dpendent
// theives shoudl be excellent, and I'll add a "detect traps"
// spell to give a bonus

do_search(string str)
{
    this_player()->add_timed_property("trap_aware",1,50);
    write("You search around and come across a trap "
      "hidden in the shadows.\n");
    return 1;
}
int query_detect_skill()
{
   object ob = this_player();
   int level = ob->query_level();
   string g_name = ob->query_guild_name();
   int stat_wis = ob->query_wis();
      switch(g_name)
      {
         case "thief":
            detect_skill = level+20+stat_wis;
            break;
         case "wizthief":
            detect_skill = level*3/4+20+stat_wis;
            break;
         case "grimbrand":
            detect_skill = level*3/4+20+stat_wis;
            break;
         default:
            detect_skill = level/2+20+stat_wis;
            break;
      }
   return detect_skill;
}

int query_disarm_skill()
{
   object ob = this_player();
   int level = ob->query_level();
   string g_name = ob->query_guild_name();
   string race = ob->query_race();
   int stat_dex = ob->query_dex();
   int stat_wis = ob->query_wis();
   switch(g_name)
   {
      case "thief":
         disarm_skill = level+random(30)+stat_dex+stat_wis;
         break;
      case "wizthief":
         disarm_skill + level*3/4+random(30)+stat_dex+stat_wis;
         break;
      case"grimbrand":
         disarm_skill = level*3/4+random(30)+stat_dex+stat_wis;
         break;
      default:
         disarm_skill = level/2+random(20)+stat_dex+stat_wis;
         break;
   }
   if(race == "dwarf")
      disarm_skill = disarm_skill + 10;
   if(race == "gnome")
      disarm_skill = disarm_skill + 5;
   if(race == "halfling")
      disarm_skill = disarm_skill + random(5);
   return disarm_skill;
}
string long(string s, int dark)
{
    if(this_player()->query_timed_property("trap_aware"))
    {
	return "You see in complex trap hidden in front of you.  "
	"Caution should\nbe used to keep it from going off.\n";
    }
    else
	return "You do not think that the trap is here.\n";
}
add_spell(string spell)
{
    myzot = spell;
}
void dest_me()
{
    if(ETO) tell_room(ETO,"A trap crumbles into dust, it's purpose served.\n");
    ::dest_me();
}
void failure()
/*not sure how to get my hands on
   the caster to blow it up on him */
{
   if(random(50+level)<5)
   {
       do_damage->caster ??
   }
void zotem(string victim)
{
   call_other(myzot,"cast_spell",victim,this_object(),1);
    call_out("dest_me",15);
}
event_enter(object ob)
{
   mixed str;
   int safe = lock_str-skill;
   if(this_object()->query_hb_counter() > max_time)
   {
      call_out("dest_me",0);
      return;
   }
    if(!ob->query_alive()) return;
    if(ob->query_property("trap_aware")) return;
    str = query_property("player");
    if( stringp(str) && str != ob->query_name()) return;
    str = query_property("race");
    if( stringp(str) && str != ob->query_race()) return;
    str = query_property("guild");
    if(stringp(str) && str != ob->query_guild_name()) return;
   if(safe>=10)
    {
      tell_object(ob,"You notice a small trap hidden in the shadows.\n);
      ob->add_timed_propety("trap_aware",1,50);
      return;
    }
if(safe>0 && safe<10)  {return};
    call_out("zotem",0,ob->query_name());
    /*
       if(ob fails some saving throw do some damage
	 or a spell or something)
    */
}
