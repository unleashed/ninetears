inherit "/std/object";
string stat();
inherit "/global/auto_load";
mixed auto_string;
string file; //Raskolnikov
#define ETP this_player()
void setup()
{
    set_name("iou");
    add_alias("IOU");
    set_short("IOU");
    set_long("This is an IOU for an item that went missing for some unknown reason, probably something obscure to do with gods meddling with things wat man is not meant to know of. (The buggers have been messing with the fabric of reality again.). "
      "Hang onto it, and you never know, it might be reclaimed.\n"
      "\"reclaim\" to try to reclaim on the IOU.\n"+
      "\"inspect iou\" to try to read the fine print on the IOU.\n"+
      ""
    );
}
string stat()
{
    string *path;
    if(!sizeof(auto_string)) return "Nothing, totally useless, throw it away";
    path = explode(auto_string[1],"/");
    if(sizeof(path) < 3) return "Something wierd wat mortal man was not meant to mess with.\n";
    switch(path[0] )
    {
    case "w":
	call_out("dest_me",2,0);
	return "Some gods toy, which aught not be in the hands of mortals.\n";
	break;
    case "d":
	return "It's for an item from the domain of "+path[1]+" and it's called "+path[sizeof(path)-1]+"\n";
    default:
	return "It's for some generic object know as "+path[sizeof(path)-1]+"\n";
	break;
    }
    return "Damned if I know really.\n";
}
mapping query_static_auto_load()
{
    return (["auto_string":auto_string]);
}
void init_static_arg(mapping stuff)
{
    auto_string = stuff["auto_string"];
}
void init()
{
    add_action("try_loading","reclaim");
    add_action("inspect","inspect");
}
mixed add_auto_string(mixed str)
{
    auto_string = str;
    return auto_string;
}
mixed add_object(object ob)
{
    auto_string = create_auto_load( ({ob }) );
    return auto_string;
}
int inspect(string str)
{
    if(str == "iou" || str == "IOU") 
    {
	write(stat());
    }
    notify_fail("O.K. you've looked at everything closely now.\n");
    return 0;
}
int try_loading(string str)
{
    object *olist;
    notify_fail("Nothing happens.\n");
    if(auto_string)
    {
	olist = load_auto_load(auto_string,ETP);
	if(sizeof(olist))
	{
	    write("A small demon hands you something and runs off with the IOU\n");
	}
    }
    dest_me();
    return 1;
}

// By Radix
int query_iou_object() { return 1; }

//Raskolnikov added the next 2
string query_path() {
    string *old_path;
    old_path = explode(auto_string[1], "/");
    file = old_path[sizeof(old_path)-1];
    old_path -= ({ file });
    return "/"+implode(old_path, "/");
}

string query_file() {
    query_path();
    return file;
}
