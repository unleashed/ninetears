
#define SHIELDPATH "/std/spells/wizard/shield.c"

inherit "/obj/armour";

int DURATION;
int damage;
int RESIST;
object player;
string TYPE="none";
string SUB_TYPE="none";
int query_duration(){ return DURATION;}
void set_dest_shield();

void setup()
{
    set_base_armour("small shield");
    set_name("shield");
    set_short("Shield");
    set_long("This is a small shield, about 14 or 15 inches wide and 20 "
      "inches long.  It's made out of primarily wood with a metal edge"
      "to hold it together.  In the middle, there are many scratch "
      "marks from sword fights and battles.  This seems to work well "
      "at stopping swords or other weapons from hitting any vital "
      "parts of the body.\n\n");
    reset_drop();
    set_value(0);
    set_enchant(1);
}

void set_dest_shield()
{
    if(SUB_TYPE == "fire")
    {
	set_short("Shield of Fire");
	add_alias("shield");
	add_alias("shield of fire");
	add_alias("fire shield");
	set_long("This is a relatively small shield.  Only about 14 to 15 "
	  "inches wide and maybe 20 inches long.  The center of the "
	  "shield seems to be made out of a solid wood, with a brass "
	  "band around the edge.  The would has many scratches and in "
	  "some places big chunks of wood missing from previous battles"
	  " it has been in.  The shield seems to be circled by a streak "
	  " of "+SUB_TYPE+".\n\n");
    }
    if(SUB_TYPE == "cold")
    {
	set_short("Shield of Ice");
	add_alias("shield");
	add_alias("shield of ice");
	set_long("This is a relatively small shield.  Only about 14 to 15 "
	  "inches wide and maybe 20 inches long.  The center of the "
	  "shield seems to be made out of a solid wood, with a brass "
	  "band around the edge.  The would has many scratches and in "
	  "some places big chunks of wood missing from previous battles"
	  " it has been in.  The shield seems to be circled by a streak "
	  " of something that looks like ice.\n\n");
    }
}

void ifheld()
{
    if(!this_object()) return;
    if(this_object()->query_in_use())
    {
	player->do_command("unhold shield");
	call_out("dest_shield",1);
	return 1;
    }
    else
    {
	call_out("dest_shield",0);
	return 1;
    }
}

dest_shield()
{
    this_object()->dest_me();
    return 1;
}

void init()
{
    ::init();
}

int set_in_use(int i)
{
    if(!player)
    {
	call_out("dest_me",0);
	return;
    }
    if(TYPE == "none"||!TYPE)
    {
	tell_object(player, "Your shield turns to dust.\n");
	call_out("ifheld",0);
	return 0;
    }
    if(i==1)
    {
	tell_object(player,"You wield the shield and a streak of "+SUB_TYPE+" "
	  "seems to circle around it.\n");
	tell_room(environment(player),(string)player->query_cap_name()+" firmly"
	  " wields a shield and a streak of "+
	  SUB_TYPE+" begins to circle around it."
	  "\n",player);
	if(!player->query_static_property(TYPE))
	    player->add_static_property(TYPE, RESIST);
	in_use = 1;
	return 1;
    }
    else if(i==0)
    {
	tell_object(player, "As you lower your shield, you feel more vulnerable"
	  " to "+TYPE+" attacks.\n");
	tell_room(environment(player), player->query_cap_name()+" lowers "+
	  player->query_possessive()+" shield and "
	  " the circle of "+SUB_TYPE+" disappears."
	  "\n",player);
	player->remove_property(TYPE);
	in_use = 0;
	return 0;
    }
    return 1;
}

void setup_spell(object obj,int duration,string type,string sub_type,
  int resist)
{
    if(!obj) return;
    player=obj;
    tell_room(environment(obj), (string)obj->query_cap_name()+" moves "+
      (string)obj->query_possessive()+" hands "
      "slowly, forming a little group of stars. "
      " The stars slowly take the form of a "
      "shield.\n",obj);
    tell_object(obj, "You move your hand slowly, forming a group of stars in "
      "front of you.  The stars slowly take the form of a "
      "shield.\n");
    this_object()->move(obj);
    DURATION=duration;
    TYPE=type;
    RESIST=resist;
    SUB_TYPE=sub_type;
    set_dest_shield();
    call_out("test",0);
    call_out("check_damage",0);
}

void test()
{
    if(!player) return;
    call_out("check",0);
    player->add_timed_property("shielding",1,DURATION);
    return 1;
}

void check()
{
    if(!player) return;
    if((player->query_timed_property("shielding") == 0) ||
      (player->query_time_remaining("shielding") == 0))
    {
	tell_object(player, "Your shield turns to dust.\n");
	call_out("ifheld",0);
	return 1;
    }
    else
    {
	call_out("check",0);
	return 1;
    }
}

void check_damage()
{
    int i;
    object victim;
    object *att;
    att = player->query_attacker_list();
    damage = random(player->query_level())/2+10;
    if(!player) return;
    if(!victim) return;
    if(!this_object()->query_in_use())
    {
	call_out("check_damage",0);
	return 1;
    }
    if(player->query_dead())
    {
	call_out("check_damage",0);
	return 1;
    }
    if(!sizeof(player->query_attacker_list()))
    {
	call_out("check_damage",0);
	return 1;
    }
    if(random(10) > 7)
    {
	for(i=0; i<sizeof(att); i++)
	{
	    victim = att[i];
	    if(victim->query_dead())
	    {
		call_out("check_damage",0);
		return 1;
	    }
	    if(victim->query_environment() != player->query_environment())
	    {
		call_out("check_damage",0);
		return 1;
	    }
	    if(player->query_dead())
	    {
		call_out("check_damage",0);
		return 1;
	    }
	    else
	    {
		tell_object(player, victim->query_cap_name()+" is slightly hit by "
		  "your shield, causing grievous pain and "
		  "suffering.\n");
		tell_object(victim, "You are slightly hit by "+
		  player->query_cap_name()+"'s shield, causing you to "
		  "wince from the grevious pain.\n");
		tell_room(environment(player), victim->query_cap_name()+" winces in"
		  " pain as he is slightly hit by "+
		  player->query_cap_name()+"'s shield.\n",
		  ({player, victim}));
		victim->adjust_hp(-damage, player);
		call_out("check_damage",0);
		return 1;
	    }
	}
    }
    else
    {
	call_out("check_damage",0);
	return 1;
    }
}
