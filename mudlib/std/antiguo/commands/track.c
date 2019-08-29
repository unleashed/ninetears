// Track skill for Rangers : Radix - July 18, 1995

#define TRACKED_SHADOW "/d/gremios/comandos/shadows/tracked.c"
#define TRACKER_SHADOW "/d/gremios/comandos/shadows/tracker.c"
#define TRACK_COST 5

void clean_tracking();
void load_shadows(object me, object vic);

int track(string who, object me)
{
   object *tmp, vic;
   if(!who)
   {
      notify_fail("Sintaxis: rastrear <alguien>\n");
      return(0);
   }
   if(!me) me = this_player();
   /*if(me->query_alignment()>1000)
   {
      notify_fail("Mielikki grants no powers to those whom are evil.\n");
      return 0;
   }*/
   who = me->expand_nickname(who);
   tmp = find_match(who,environment(me));
   if(!sizeof(tmp)||tmp[0]->query_hidden_shadow()||tmp[0]->query_hidden())
   {
      notify_fail("Para rastrear a alguien tiene que estar aqui!\n");
      return(0);
   }
   vic = tmp[0];
   
   if(vic->query_dead())
   {
      notify_fail("Los seres etereos no dejan rastros!\n");
      return(0);
   }
   if(me->query_gp() < TRACK_COST)
   {
      notify_fail("Tu mente esta demasiado drenada para rastrear.\n");
      return(0);
   }
   if(me->query_tracking()) me->clean_tracking();

   tell_object(me,"Ok, rastreando a "+capitalize(who)+".\n");
   load_shadows(me, vic);
   me->adjust_gp(-TRACK_COST);
   return(1);
}

load_shadows(object me, object vic)
{
   int time = ((int)me->query_level() / 5) * (int)me->query_wis();
   object tracker = clone_object(TRACKER_SHADOW);
   object tracked;
   tracker->move(me);
   tracker->start(me);
	if (!vic->query_being_tracked()) {
   		tracked = clone_object(TRACKED_SHADOW);
   		tracked->move(vic);
   		tracked->start(vic);
		// mirar lo del time y tal
   		tracked->set_time_factor(time);
	}

   // tracked->set_tracker(me); no existe
   vic->add_timed_property("being_tracked",1,time*3/2);
   me->set_victim(vic);
}
string help(string str)
{
   return
      "Track:\n\n"
      "GP Cost: NA\n"
      "When a ranger is tracking a person, he studies the environment "
      "and finds various footprints and other signs to determine the "
      "path of a target that has long sense departed.  In order to track "
      "a target, the ranger must find an origin, thus the target must "
      "first be present.  This is most useful when a target flees.  "
      "\n\nSyntax: track <target>\n\n";
}
