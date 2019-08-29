/* Pagan and Taniwha 1996
   generic trap object
*/
inherit "/obj/monster";
static int detect_skill;
static int disarm_skill;
string myzot = "/std/spells/wizard/fireball";
string mylong = "A complex trap, partially hidden in the shadows.\n";
int detected;
int disarmed;
int target;
int trap_power; // 100 is damn good.
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
    int i;	
    set_gender(0);
    set_long("");
    i = 2+random(7);
    set_int(i);
    set_wis(i);
    set_level(i);
    trap_power = i * 10;
} /* setup() */

void set_trap(string spell,int targ,int power,int d,string xlong)
{
    if(power > 200) power = 200;
    if(power)
    {
	set_wis(power/10);
	set_int(power/10);
	set_level(power/10);
	trap_power = power/2;
    }
    target = targ;
    if(d) max_time = d;
    if(stringp(spell)) myzot = spell;
    if(stringp(xlong)) mylong = xlong;
}	
query_power()
{
   return trap_power;
}
void init() {

    add_action("do_search","search");
    add_action("do_disarm","disarm");
    ::init();

}

void trap_found(object ob)
{
    ob->add_timed_property("trap_aware",1,50);
    detected = 1;
    set_name("trap");
    set_short("trap");
    set_long(mylong);		
}

do_search(string str,object ob) // this IS correct, so NPC's can do it
{
    if(!ob) ob = TP;
    if(random(trap_power) < random(query_detect_skill(ob)*3)) // * 3 bonus for searching for it
    { 
	trap_found(ob);
    tell_object(ob,"You search around and come across a trap "
      "hidden in the shadows.\n");
	return 1;
    }
    // and if you are REALLY unlucky *BANG*
       if(random(ob->query_cha()) < 1) zotem(ob->query_name());
    return 0; 
}
do_disarm(string str,object ob)
{
   if(str != "trap") return 0;
    if(!detected) return 0;
    if(!ob) ob = TP;
    tell_object(ob,"You check the trap out carefully and with great skill ");
    tell_room(ETO,(string)ob->query_cap_name()+"attempts to disarm a trap and ",({ob}));
    if(random(trap_power) < random(query_disarm_skill(ob)))
    { 
	tell_object(ob,"suceed in disarming it.\n");
	tell_room(ETO,"succeds in disarming the trap.\n",({ob}));
	call_out("dest_me",0);
	return 1;
    }
    call_out("zotem",0,ob->query_name());
    tell_object(ob,"you succeed in setting it off.\n");
    tell_room(ETO,"succeeds in setting it off.\n",({ob}));
    return 1; 
}
int query_detect_skill(object ob)
{
    int bonus;
    string race;
    int level;
    string g_name;
    int stat_wis;
    stat_wis = ob->query_wis();
    g_name  = ob->query_guild_name();
    level  = ob->query_level();
    race = ob->query_race();
    bonus = (int)ob->query_property("detection"); // detect traps spell
    switch(g_name)
    {
    case "thief":
	detect_skill = level+20+stat_wis;
	break;
    case "wizthief":
	detect_skill = ((level*3)/2)+10+stat_wis;
	break;
    case "grimbrand":
	detect_skill = ((level*3)/4)+stat_wis;
	break;
    default:
	detect_skill = level/4+stat_wis;
	break;
    }
    switch(race)
    {
    case "gnome":
    case "halfling":
	bonus += 20;
	break;
    case "orc":
    case "troll":
	bonus -= 20;
	break;
    case "lizard_man":
	bonus -=20;
	break;
    }
    return (detect_skill+ bonus);
}
// all dex, needs steady hands
int query_disarm_skill(object ob)
{

    int level = ob->query_level();
    string g_name = ob->query_guild_name();
    string race = ob->query_race();
    int stat_dex = ob->query_dex();
    switch(g_name)
    {
    case "thief":
	disarm_skill = level+random(30)+stat_dex;
	break;
    case "wizthief":
	disarm_skill = (level*3/4)+random(30)+stat_dex;
	break;
    case"grimbrand":
	disarm_skill = (level*3/4)+random(30)+stat_dex;
	break;
    default:
	disarm_skill = (level/4)+random(20)+stat_dex;
	break;
    }
    switch(race)
    {
    case "dwarf":
    case "duegar":
      disarm_skill = disarm_skill +10;
	break;
    case "halfling":
    case "gnome":
      disarm_skill = disarm_skill +20;
	break;
    case "orc":
    case "lizard-man":
      disarm_skill = disarm_skill -20;
	break;
    case "goblin":
      disarm_skill = disarm_skill -10;
	break;
    }
    return disarm_skill;
}
/*
string long(string s, int dark)
{
    if(this_player()->query_timed_property("trap_aware"))
    {
		return "You see in complex trap hidden in front of you.\n  "
		"Caution should be used to keep it from going off.\n";
    }
    else
		return "You do not think that the trap is here.\n";
}
*/

void dest_me()
{
    if(ETO) tell_room(ETO,"A trap crumbles into dust, it's purpose served.\n");
    ::dest_me();
}

void zotem(string victim)
{
    if(!disarmed)
    {
	set_name("trap");
	set_short("Booby trap");
	call_other(myzot,"cast_spell",victim,this_object(),target);
    }
    call_out("dest_me",15);
}
event_enter(object ob)
{
    mixed str;
    if(this_object()->query_hb_counter() > max_time)
    {
	call_out("dest_me",0);
	return;
    }
    if(!ob->query_alive()) return;
    if(ob->query_property("trap_aware")) return;
   if(ob->query_level() < 10) return; // too easy otherwose
    str = query_property("player");
    if( stringp(str) && str != ob->query_name()) return;
    str = query_property("race");
    if( stringp(str) && str != ob->query_race()) return;
    str = query_property("guild");
    if(stringp(str) && str != ob->query_guild_name()) return;

    if(random(trap_power) < random(query_detect_skill(ob))) // just walk in
    {
	trap_found(ob);
      tell_object(ob,"You notice something hidden in the shadow....\n");
	return;
    }
    if(target > 1) call_out("zotem",0,"all");
    else
	call_out("zotem",0,ob->query_name());

}

