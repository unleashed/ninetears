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
   if(me->query_alignment()>1000)
   {
      notify_fail("Yvendur no concede este poder a gente malvada.\n");
      return 0;
   }
   
   if(who=="nadie")
    { tell_object(me,"Ok, parando de rastrear.\n");
      if(me->query_tracking()) me->clean_tracking();
      return 1;
    }
   who = me->expand_nickname(who);
   tmp = find_match(who,environment(me));
   if(!sizeof(tmp)||tmp[0]->query_hidden_shadow()||tmp[0]->query_hidden())
   {
      notify_fail("Rastrea a alguien que exista!\n");
      return(0);
   }
   vic = tmp[0];
   
   if(vic->query_dead())
   {
      notify_fail("Rastrea a alguien con vida!\n");
      return(0);
   }
   if(me->query_gp() < TRACK_COST)
   {
      notify_fail("Estas demasiado drenado mentalmente para rastrear a alguien.\n");
      return(0);
   }
   if(me->query_tracking()) me->clean_tracking();

   tell_object(me,"Ok, rastreando a "+capitalize(who)+".\n");
   load_shadows(me, vic);
   me->adjust_gp(-TRACK_COST);
   return 1;
}

load_shadows(object me, object vic)
{
   int time = ((int)me->query_level() / 5) * (int)me->query_wis();
   object tracker = clone_object(TRACKER_SHADOW);
   object tracked = clone_object(TRACKED_SHADOW);
   tracker->move(me);
   tracked->move(vic);
   tracker->start(me);
   tracked->start(vic);

   tracked->set_tracker(me);
   tracked->set_time_factor(time);
   vic->add_timed_property("being_tracked",1,time*3/2);
   me->set_victim(vic);
}
string help(string str)
{
   return
      "Comando: Rastrear\n\n"
      "Coste en Pg: 5\n"
      "Cuando un Ranger rastrea a una persona, el estudia su entorno "
      "y encuentra varias pisadas y senyales para determinar el lugar "
      "de un objetivo que ha salido en alguna direccion.  Para rastrear un "
      "objetivo, el ranger debe encontrar un origen, el objetivo debe "
      "estar presente.  Esto es usado cuando un objetivo escapa.  "
      "\n\nSintaxis: rastrear <objetivo>"
      "Para dejar de rastrear a alguien pon 'rastrar nadie'\n\n";
}
