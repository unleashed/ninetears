
inherit "/obj/container.c";
#include "/std/basic/item_misc.c"
string update_long();
#define MAXARROWS 20
string desc = "A leather quiver.\n";

string arrow = "quarrel";
int query_armour_type() {return 10;}
int query_size() {  return 7;  }
int query_wearable() { return 1; }

void setup() {
    set_name("quiver");
    set_short("quiver");
    set_main_plural("quivers");
    set_value(300);
    set_weight(50);
    set_max_weight(250);
}
void set_long(string l) { desc = l; }

string long(string str, int dark)
{
   string temp;
   temp = desc + "the quiver contains:\n"+TO->query_property("QUARRELS")+
   " "+arrow+"s.\n";
return temp;
}


int test_add(object ob, int flag)
{
    int quarrels;
    quarrels = this_object()->query_property("QUARRELS");
   if(quarrels >= MAXARROWS) return 0;
    if(ob->query_name() == arrow) 
    {
	// none in here when it loads
	if(!sizeof(all_inventory(TO)) || !quarrels)
	{
	    if(!quarrels) TO->add_property("QUARRELS",1);
	    return 1;
	}

	if(quarrels)
	{
	    quarrels++;
	    this_object()->add_property("QUARRELS", quarrels);
	    call_out("dest_it", 1, ob);
	    return 1;
	}
    }
    else return 0;
}


void dest_it(object ob)
{
    ob->dest_me();
}

int test_remove(object ob, int flag) 
{
    object it;
    int quarrels;
    quarrels = this_object()->query_property("QUARRELS");
    if(ob->query_name() == arrow) 
    {
	if(quarrels) {
	    quarrels--;
	    this_object()->add_property("QUARRELS", quarrels);
	    if(quarrels)
	    {
		it = clone_object(explode(file_name(ob),"#")[0]);
		it->move(ETO);
		tell_object(ETO, "You take one "+arrow+
		  "and try to get another one.  ");
		return 0;
	    }
	    return 1;
	}
    }
}
