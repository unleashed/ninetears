inherit "/obj/armour";

string pretty_short(int dark)
{
    string ret;
    object me;
    int x;
    string *where;

    me = environment(this_object());

    if(!me) return ::pretty_short(dark);
    if("/global/omiq.c"->flag_in_progress())  return ::pretty_short(dark);
    if(me->query_loading() || me->query_property("loading")) 
	return ::pretty_short(dark);
    if(me->query_item_container())  return ::pretty_short(dark);
    if(!environment(me)) return ::pretty_short(dark);

    where = explode(file_name(environment(me)), "/");

    if(sizeof(where) > 2) {

	// Quark feb.97
	if(where[0] != "d") return ::pretty_short(dark); 

	if(!(where[1]=="bf") && !(where[1]=="newbie") && !(where[1]=="aprior")
	  && !environment(me)->query_underground()) {
	    x = this_object()->query_property("ROTCOUNTER");
	    this_object()->remove_property("ROTCOUNTER");
	    x--;
	    this_object()->add_property("ROTCOUNTER",x);
	}
    }
    ret = ::pretty_short(dark);
    return ret;
}

int query_ac() {
    int ret;
    if(this_object()->query_property("ROTCOUNTER") <= 0 &&
      !this_object()->query_property("DESTED")) {
	write("\n     Your "+this_object()->query_short()+" has "
	  "been drained of all magic and vanishes into "
	  "nothingness.\n\n");
	this_object()->add_property("DESTED",1);
	call_out("my_dest", 1);
	return(0);
    }
    ret = ::query_ac();
    return ret;
}
void my_dest() {
    if(this_object()->query_property("DESTED"))
	this_object()->dest_me();
}
