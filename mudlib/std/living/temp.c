void domain_death(object killed_by,object *attacker_list)
{
   string *x;
    string domain;
    if(!environment(this_object()))
	return;
    if(!interactive(this_object())) return;
   x = explode(file_name(environment()),"/");
   domain = "/"+x[0]+"/"+x[1]+"/master.c";
   //tell_room(environment(),"Bing... "+domain+"\n");
    catch(domain->event_player_death(this_object(),killed_by,attacker_list));
}
