//      /adm/daemon/postal_d.c
//      from the Nightmare Mudlib
//      the postal daemon... handles all mail sending and receiving
	// "radix",
//      Added retire_user and age_mail : Radix - March 6, 1997

#include <post.h>

mapping *box_info;
mapping my_groups;
nosave mapping mud_groups;
nosave string file;

string *expand_list(string *who);
string *expand_group(string grp);
void add_post(string *local, mapping borg);
void notify_online(string *who, string from, string sub);
int get_post_number(string id);
void remove_post(string, string);
void retire_user(string);
void age_mail(string);

void create() {
    seteuid("Root");
    box_info = ({});
    my_groups = ([]);

    mud_groups = ([
      "dioses" :
      ({ "barthleby",
         "jade",
         "tyrael",
	 "vilat"
      }),
      "mudlib" :
      ({
         "barthleby",
         "jade",
         "tyrael",
	 "vilat"
      }),
      "thanes" :
	({
         "barthleby",
         "jade",
         "tyrael",
	 "vilat"
         "thalos",
         "flangerant",
         "xerxes",
      }),
      "bugs" :
      ({
         "tyrael",
	 "vilat"
      }),
   ]);
//    catch(mud_groups["patrons"] = "/d/aprior/master"->query_patrons());

}

int valid_access(string func) {
    if(geteuid(previous_object()) == "Root") return 1;
    if(member_array(base_name(previous_object()), TRUSTED_MAILERS) != -1)
	return 1;
    log_file("illegal", "attempt to access postal daemon function "+func+" by "+
      (this_player() ? this_player()->query_name() : getuid(previous_object()))+
      " from file "+file_name(previous_object())+"\n");
    log_file("illegal", ctime(time())+"\n");
    return 0;
}

void update_post_box(string who) {
    if(file == DIR_POSTAL+"/"+who) return;
    if(file && file != "") {
	if(!sizeof(box_info) && !sizeof(my_groups)) rm(file+".o");
	else save_object(file);
    }
    box_info = ({});
    my_groups = ([]);
    file =  DIR_POSTAL+"/" +who;
    restore_object(file);
}

// Radix : March 5, 1997
void retire_user(string who)
{
    mapping m;
    if(!who) return;
    who = lower_case(who);
//  if(this_player() && !this_player()->query_lord() &&
//    this_player()->query_name() != who)
         ///return;
    update_post_box(who);
    if(find_player(who))
	tell_object(find_player(who),"Borrando tu correo.\n");
    foreach(m in box_info)
    remove_post(who, m["id"]);
    return;
}

string *post_mail(mapping borg) {
    string *local, *remote;

    if(!valid_access("post mail")) return ({});
    if(!borg["from"]) return ({});
    update_post_box(borg["from"]);
    local = uniq_array(expand_list(borg["to"])+expand_list(borg["cc"]));
    if(!sizeof(local -= (remote=filter_array(local, "remote_mail",this_object(), borg))))
	return remote;
    add_post(local, borg);
    notify_online(local, borg["from"], borg["subject"]);
    return local+remote;
}

int remote_mail(string who, mapping borg) {
    string pl, mud;

    if(sscanf(who, "%s@%s", pl, mud) != 2) return 0;
    MAIL_S->remote_mail(pl, mud, borg);
    return 1;
}

string *expand_list(string *who) {
    string *full;
    string a,b;
    int i;

    full = ({});
    if(!(i=sizeof(who))) return ({});
    while(i--) {
	if(!who[i] || who[i] == "" || !stringp(who[i])) continue;
	if(sscanf((who[i]=lower_case(who[i])), "%s@%s", a, b) == 2)
	    full += ({ who[i] });
	else if(user_exists(who[i])) full += ({ who[i] });
	else if(mud_groups[who[i]] ||
	  my_groups[who[i]])
	    full += expand_group(who[i]);
	else write("No such user or group: "+capitalize(who[i])+".\n");
    }
    return full;
}

string *expand_group(string grp) {
    string *ret, *g;
    string a, b;
    int i;

    if(mud_groups[grp]) g = mud_groups[grp];
    else if(my_groups[grp]) g = my_groups[grp];
    else return ({});
    i = sizeof(g);
    ret = ({});
    while(i--) {
	if(sscanf(g[i], "%s@%s", a, b) ==2) ret += ({ g[i] });
	else if(user_exists(g[i])) ret += ({ g[i] });
	else write("No such user: "+capitalize(g[i])+".\n");
    }
    return ret;
}

void add_post(string *local, mapping borg) {
    int i;

    if(!valid_access("add post")) return;
    if(!(i=sizeof(local))) return;
    borg["id"] = (string)LETTER_D->create_message(borg["message"],local);
    borg["read"] = 0;
    map_delete(borg, "message");
    while(i--) {
	update_post_box(local[i]);
	box_info += ({ borg });
    }
}

void remove_post(string who, string id) {
    int x;

    if(!valid_access("remove post")) return;
    update_post_box(who = lower_case(who));
    if((x=get_post_number(id)) == -1) return;
    LETTER_D->delete_message(id, who);
    box_info = exclude_array(box_info, x);
}

nomask int get_post_number(string id) {
    int i;

    i = sizeof(box_info);
    while(i--) if(box_info[i]["id"] == id) return i;
    return -1;
}

mapping mail_status(string who) {
    int un, tot, i;

    update_post_box(who = lower_case(who));
    i = sizeof(box_info);
    while(i--) {
	tot++;
	if(!box_info[i]["read"]) un++;
    }
    return ([ "unread":un, "total":tot ]);
}

void notify_online(string *who, string from, string sub) {
    object ob, mail;
    string str;
    int i;

    i = sizeof(who);
    while(i--) {
	if(!(ob = find_player(who[i])) ||
	  ((str=(string)ob->getenv("MAIL_MSG")) == "ignore"))
	    continue;
	if(!str || str == "")
	    str = "    New mail has arrived from $N\n    Subject: $S";
	str = replace_string(str, "$N", capitalize(from));
	str = replace_string(str, "$S", sub);
	//tell_object(ob,str);
	tell_object(ob,wrap(str,(int)ob->query_cols()) );
	//tell_object(ob, wrap(str, (int)ob->getenv("screen")));
	if(mail=present(POST_ID, ob)) mail->reset_post();
    }
}

mapping add_group(string who, string group, string *in_group) {
    string a, b;
    int i;

    if(!valid_access("add group")) return ([]);
    update_post_box(who = lower_case(who));
    if(!my_groups) my_groups = ([]);
    if(!my_groups[group]) my_groups[group] = ({});
    i = sizeof(in_group);
    while(i--) {
	if(user_exists(in_group[i] = lower_case(in_group[i])))
	    my_groups[group] += ({ in_group[i] });
	if(sscanf(in_group[i], "%s@%s", a, b) == 2)
	    my_groups[group] += ({ in_group[i] });
    }
    return my_groups;
}

mapping remove_group(string who, string group, string *out_group) {
    int i;

    if(!valid_access("remove group")) return ([]);
    update_post_box(who = lower_case(who));
    if(!my_groups) return ([]);
    if(!my_groups[group]) return my_groups;
    i = sizeof(my_groups[group]);
    while(i--) my_groups[group] -= ({ my_groups[group][i] });
    if(!sizeof(my_groups)) map_delete(my_groups, group);
    return my_groups;
}

void mark_read(string who, string id) {
    int i;

    if(!valid_access("mark read")) return;
    update_post_box(who = lower_case(who));
    i = sizeof(box_info);
    while(i--) if(id == box_info[i]["id"]) box_info[i]["read"] = 1;
}

// Radix : March 7, 1997
void age_mail(string who)
{
    int low, high;
    mapping m;
    if(!valid_access("age mail")) return;
    update_post_box(who);
    foreach(m in box_info)
    if(m["date"] + AGED < time())
    {
	high = get_post_number(m["id"]);
	if(!low)
	    low = high;
	remove_post(who, m["id"]);
    }
    if(low)
    {
	if(low == high)
	    tell_object(find_player(who),"Aged letter #"+low+"\n");
	else
	if(low + 1 == high)
	    tell_object(find_player(who),"Aged letters #"+low+" and "
	      "#"+high+"\n");
	else
	    tell_object(find_player(who),"Aged letters #"+low+" through"
	      " #"+high+"\n");
    }
    return;
}

mapping query_mud_groups() { return mud_groups; }
int query_mailing_list(string which) {
    if(!which)  return 1;
    if(mud_groups[which])  return 1;

    return 0;
}

void flush_files() {
    if(!sizeof(box_info) && !sizeof(my_groups)) rm(file+".o");
    else save_object(file);
}

string read_sig(string who) {
    if(file_exists("/w/"+who+"/.sig")) return read_file("/w/"+who+"/.sig");
    else return "";
}

int valid_shadow() { return 1; }
