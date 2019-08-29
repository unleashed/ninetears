// Tracker shadow for Rangers, Radix 1996
object hunted, me;
string victim;

start(object ob)
{
   me = ob;
   shadow(ob,1);
}

void destruct_tracker_shadow() { destruct(this_object()); }

void set_victim(object ob)
{
   hunted = ob;
   victim = ob->query_short();
}

int query_tracking() { return(1); }

varargs mixed move_player(string dir, string dest, mixed message,
                          object follower, mixed enter)
{
   if(hunted && !hunted->query_timed_property("being_tracked"))
      call_out("destruct_tracker_shadow",0);
   call_out("find_tracks",0);
   return me->move_player(dir,dest,message,follower,enter);
}

void find_tracks()
{
   string dir;
   if(!me || !environment(me)) return;
   if(hunted && environment(hunted))
   {
      if(environment(hunted) == environment(me))
      {
         hunted->dest_hide_shadow();
         // Renew the shadows...
         hunted->destruct_tracked_shadow();
         me->destruct_tracker_shadow();
         "/d/gremios/comandos/track.c"->load_shadows(me, hunted);
         return;
      }
   }
   dir = environment(me)->query_timed_property("track_"+victim);
   if(dir)
      tell_object(me,"El rastro de "+victim+" se va a "+dir+".\n");
   return;
}
void clean_tracking()
{
   if(hunted)
      hunted->destruct_tracked_shadow();
   call_out("destruct_tracker_shadow",0);
   if(me)
      tell_object(me,"Paras de rastrear a "+victim+".\n");
   return;
}

really_quit()
{
   clean_tracking();
   me->really_quit();
   return;
}
