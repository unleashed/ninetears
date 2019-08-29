#ifdef INSIDE
inherit "/std/room";
#else
inherit "/std/outside.c";
#endif

string drown_room;
string death_room;

#define MOVE_DELAY 10
// Taniwha, mask this for ponds ?
int query_ocean() { return 1; }
void event_enter(object target, string MESG, object FROM)
{
    if(!target) return;
    if(target->query_corpse()){
	call_out("destem",0,target);
	return;
    }
   if( !interactive(target) )
   {
      if(  target->query_material_name() == "metal" ||
           target->query_material_name() == "unknown" )
      {
         call_out("destem",2,target);
         return;
      }
   }
   if( interactive(target) && target->query_dead() )
   {
      write("Since you are ghost you cannot swim.\n");
      target->move(death_room);
   }
    if(!target->query_property("free_action"))
    {
	target->add_static_property("nocast",1);
	target->add_static_property("noguild",1);
      target->add_static_property("seatmp",1);  //For players entering at ships.
      target->set_wetness(300);
    }
}
void destem(object target)
{
    if(!target) return;
    write("The " + target->query_short() + " dissapears into "
      "the deep sea waters to be never seen again.\n");
    target->dest_me();
}
void init()
{
    ::init();
    add_action("no_can_do", "say");
    add_action("no_can_do", "shout");
    add_action("no_can_do", "lsay");
    add_action("no_can_do", "'");
}
int no_can_do(string str)
{
    write("You cough as you swallow some water.\n");
    say(TP->query_cap_name()+" swallows some water and coughs.\n",TP);
    return 1;
}

int do_exit_command(string str, mixed verb, object ob, object foll)
{
    int delay;
    if(!ob && this_player() ) ob = this_player();

    if(!verb)
	verb = query_verb();
    if(ob->query_property("IS_SWIMMING"))
    {
	notify_fail("You are already swimming to the "+verb+".\n");
	return 0;
    }
    tell_object(ob,"You start swimming "+verb+".\n");
    switch((ob->query_race_ob())->
      query_swim_stamina(ob))
    {
    case 11..50 : delay = MOVE_DELAY -1; break;
    case 51..100 : delay = MOVE_DELAY -2; break;
    case 101..200 : delay = MOVE_DELAY -3; break;
    case 201..400 : delay = MOVE_DELAY -4; break;
    case 401..100000: delay = 0; break;
    default : delay = MOVE_DELAY; break;
    }

    if( ob->query_property("free_action") )
	delay = 0;
    call_out("really_do_exit_command", delay, str, verb, ob, foll);
    ob->add_timed_property("IS_SWIMMING",1,MOVE_DELAY);
    return 1;
}

int really_do_exit_command(string str, mixed verb, object ob, object foll)
{
    if(!ob && this_player() ) ob = this_player();
    if(!ob) return;
    ob->remove_timed_property("IS_SWIMMING");
   ob->remove_timed_property("wolfbane"); // washes off dunnit
    ob->remove_static_property("nocast");
    ob->remove_static_property("noguild");
    ob->remove_static_property("seatmp");  
    if(!::do_exit_command(str, verb, ob, foll))
    {
	notify_fail("You can't seem to get anywhere in "
	  "that direction.\n");
	return 0;
    }
    tell_object(ob,"You swim "+verb+".\n");
    return 1;
}

void set_death_location(mixed str)
{
    if(stringp(str))
	death_room = str;
    if(pointerp(str))
	death_room = str[random(sizeof(death_room))];
}

string query_death_location(string str)
{
    return death_room;
}




/* The above is common for sea.c and uwater.c */
void create()
{
    set_light(100);
    set_long("Wet and watery, looks like you are all at sea.\n");
    ::create();
    add_property("location","sea_surface");
}
int set_uwater_location(string where)
{
    drown_room = where;
    add_exit("down",where,"hidden");
}

void DO_SINK(object player,object from)
{
   if(player->query_property("free_action"))
   {
      tell_object(player, "%^CYAN%^Strange, you haven't the urge or need "+
                  "to breathe.%^RESET%^\n");
      return;
   }
    if(drown_room && load_object(drown_room))
    {
	tell_object(player,"Your strength fails you and you slip beneath the waves.\n");
	really_do_exit_command(" ","down",player,0);
	tell_room(from,player->query_cap_name()+" disappears below the waves.\n");
    }
    else
    {
	tell_object(player,"It seems your fears were unfounded, you sink a little and find yourself standing on the sea bed.\n");
    }
}

