// henchman.c - Radix, June 1996
/* Added settable protect and follow functions 
 * rewrote check_for_owner to incorporate
 * query_no_clean_up so instead of leaving players helpless w/o 
 * henchman after a reset the room just doesnt dest if the henchman is
 * there and the player is logged in but somewhere else.
 * the only time house_clean should EVER get called is if there is an 
 * error.
 * Raskolnikov Oct 96
 */

inherit "/obj/monster.c";

object owner;
string join_room_mess;
string join_me_mess;
string leave_room_mess;
mixed my_data;
int follow_owner;
int protect_owner;

/* dont dest the room im in */
int query_no_clean_up() { return 1; }

int query_follow_owner() { return follow_owner; }
int query_protect_owner() { return protect_owner; }
int query_henchman() { return 1; }
object query_owner() { return owner; }

void house_clean();
void save_my_data();
void load_my_data();

create()
{
    monster::create();
    call_out("find_owner", 1);
    join_room_mess = "The pet finds its owner quickly.";
    join_me_mess = "The pet finds you cute, and cuddles you happily.";
    leave_room_mess = "The pet vanishes in a puff of octarine smoke!";
    my_data = ([ ]);
}

void set_join_room_mess(string str)
{
    join_room_mess = str;
}

void set_leave_room_mess(string str)
{
    leave_room_mess = str;
}

void set_join_me_mess(string str)
{
    join_me_mess = str;
}

void set_owner(object ob)
{
    owner = ob;
    save_my_data();
}
void set_follow_owner(int i) { follow_owner = i; }

void set_protect_owner(int i)
{
    protect_owner = i;
    if(protect_owner == 1) {
	call_out("do_protect", 0,
	  this_object()->query_owner()->query_name());
    }
}

void find_owner()
{
    load_my_data();
    tell_room(environment(),join_room_mess+"\n",owner);
    tell_object(owner,join_me_mess+"\n");
}

house_clean()
{
    tell_room(environment(),leave_room_mess+"\n");
    dest_me();
}

void owner_left()
{
    if(short(0))
	tell_room(this_object(),short(0)+" (henchman) left the game.\n");
    dest_me();
}

void reset()
{
    if(!environment() || !owner || !environment(owner))
    {
	house_clean();
	return;
    }
    remove_call_out("check_for_owner");
    if(environment() != environment(owner))
    {
	call_out("check_for_owner",10);
	return;
    }
    save_my_data();
    return;
}

/** rewrote this...Raskolnikov **/
void check_for_owner()
{
    if(!environment() || !owner || !environment(owner))
    {
	house_clean();
	return;
    }
    save_my_data();
    return;
}

void load_my_data()
{
    string s;
    object ob;
    my_data = query_property("my_data");
// Taniwha, in the vaugue hope it'll stop spamming the logs
   if(!mappingp(my_data)) return;
    s = my_data["owner"];
    if(s) ob = find_player(s);
    if(!ob || environment() != environment(ob))
    {
	house_clean();
	return;
    }
    owner = ob;
    set_level(my_data["level"]);
    set_thac0(my_data["thac0"]);
    adjust_tmp_str(my_data["tmp_str"]);
    adjust_tmp_con(my_data["tmp_con"]);
    adjust_tmp_dex(my_data["tmp_dex"]);
    adjust_tmp_int(my_data["tmp_int"]);
    adjust_tmp_wis(my_data["tmp_wis"]);
    adjust_tmp_cha(my_data["tmp_cha"]);
    set_max_hp(my_data["max_hp"]);
    set_max_gp(my_data["max_gp"]);
    set_hp(my_data["hp"], this_object());
    set_gp(my_data["gp"]);
    adjust_volume(0,my_data["volume"]);
    adjust_align(my_data["align"]);
    set_gender(my_data["gender"]);
    total_xp = my_data["total_xp"];
    xp = my_data["xp"];
    set_wimpy(my_data["wimpy"]);
    godalign = my_data["godalign"];
    ethics = my_data["ethics"];
    return;
}

void save_my_data()
{
    my_data["owner"] = owner->query_name();
    my_data["level"] = query_level();
    my_data["thac0"] = query_thac0();
    my_data["tmp_str"] = query_tmp_str();
    my_data["tmp_con"] = query_tmp_con();
    my_data["tmp_dex"] = query_tmp_dex();
    my_data["tmp_int"] = query_tmp_int();
    my_data["tmp_wis"] = query_tmp_wis();
    my_data["tmp_cha"] = query_tmp_cha();
    my_data["max_hp"] = query_max_hp();
    my_data["max_gp"] = query_max_gp();
    my_data["hp"] = query_hp();
    my_data["gp"] = query_gp();
    my_data["volume"] = query_volume(0);
    my_data["align"] = query_align();
    my_data["gender"] = query_gender();
    my_data["total_xp"] = query_total_xp();
    my_data["xp"] = query_xp();
    my_data["wimpy"] = query_wimpy();
    my_data["godalign"] = godalign;
    my_data["ethics"] = ethics;
    add_property("my_data",my_data);
    return;
}

void heart_beat()
{
    object me = this_object();
    if(!me->query_owner()) return ::heart_beat();
    if(me->query_follow_owner() != 1) return ::heart_beat();
    if(environment(me) == environment(me->query_owner()))
	return ::heart_beat();
    tell_room(environment(me), me->query_cap_name()+" follows "
      ""+me->query_owner()->query_cap_name()+".\n");
    me->move(environment(me->query_owner()));
    tell_room(environment(me), me->query_cap_name()+" arrives with "
      ""+me->query_owner()->query_cap_name()+".\n");
    return ::heart_beat();
}
