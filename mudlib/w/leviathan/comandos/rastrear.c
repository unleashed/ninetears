// tradusio por errante
// Track skill for Rangers : Radix - July 18, 1995
/* Cambiado casi completamente por Iolo. 
   Esta es la version que he preparado para probar con los asesinos.
   La antigua version, la de rangers, esta en rastrear.iolo
   5-2000
*/


#define TRACKED_SHADOW "/std/commands/shadows/tracked.c"
#define TRACKER_SHADOW "/std/commands/shadows/tracker.c"
#define TRACKING_SHADOW "/std/commands/shadows/tracking.c"
#define TRACK_COST 2
// tiempo que se mantedran las huellas
#define TIEMPO 160 

/* Tenemos por lo tanto 3 shadows:
    TRACKED_SHADOW: La tiene la victima y es lo que hace que deje huellas.
    TRACKER_SHADOW: La tiene el perseguidor, y es la que hace que salga hacia
      donde se fue la victima.
    TRACKING_SHADOW: La tiene el perseguidor cuando mira en el suelo. Es la que
      hace se que destruya la anterior si hacemos algun comando o entramos en
      combate.
*/
// la propiedad no_track hace que no se deje huellas en una room

void load_shadows(object me, object vic);
string tiempo_huellas(int x);

int track(string who, object me)
{
   object *tmp, vic;
   object shing;
   int velocidad;
   
   if(!me) me = this_player();
   
   if(me->query_gp() < TRACK_COST)
   {
      notify_fail("No tienes suficiente concentracion para rastrear.\n");
      return(0);
   }

   if(!who)
   {
      // no podemos rastrear escondidos.
      // quemaba muchos gps.. por el momento lo comento
//      if (me->query_hide_shadow()) me->dest_hide_shadow();
   
      // si estamos rastreando no podemos volver a rastrear
      if (me->query_tracking()) {
        tell_object(TP,"Ya estas rastreando.\n");
	return 1;
      }
   
      tell_object(TP,"Comienzas a rastrear el suelo en busca de huellas.\n");
      tell_room(ENV(TP),TP->query_cap_name()+" comienza a rastrear el suelo en "
       "busca de huellas.\n",TP);            
      
      shing = clone_object(TRACKING_SHADOW);
      shing->move(me);
      shing->start(me);
      me->adjust_gp(-TRACK_COST);
      // este es el caso en que vemos todas las huellas
      call_out("rastrea_solo",8);
      return (1);
   }

   who = me->expand_nickname(who);
   
   if (who==me->query_name()) {
     tell_object(me,"Enhorabuena, has logrado encontrarte a ti mismo.\n");
     return(1);
   }
   
   tmp = find_match(who,environment(me));
   if(!sizeof(tmp)||tmp[0]->query_hidden_shadow()||tmp[0]->query_hidden())
   {
//      if (me->query_hide_shadow()) me->dest_hide_shadow();
   
      if (me->query_tracking()) {
        tell_object(TP,"Ya estas rastreando.\n");
	return 1;
      }
   
      tell_object(TP,"Comienzas a rastrear el suelo en busca de huellas de "
       +capitalize(who)+".\n");
      
      tell_room(ENV(TP),TP->query_cap_name()+" comienza a rastrear el suelo en "
       "busca de huellas.\n",TP);            
      
      shing = clone_object(TRACKING_SHADOW);
      shing->move(me);
      shing->start(me);
      if (!me->query_tracker()) me->adjust_gp(-TRACK_COST);
      if (me->query_tracker()) me->destruct_tracker_shadow();
      
      velocidad = 1;
      
      switch (me->query_level()) {
        case 0..20: velocidad = 6; break;
	case 21..27: velocidad = 5; break;
	case 28..34: velocidad = 4; break;
	case 35..43: velocidad = 3; break;
	case 44..49: velocidad = 2; break;
      }
      // el caso en el que buscamos a alguien en concreto
      call_out("rastrea_alguien",velocidad,who);
      return (1);
   }
   vic = tmp[0];

   // el caso en que que 'reconocemos' a alguien para buscar sus huellas
   
   if(vic->query_dead())
   {
      notify_fail("No puedes rastrear a un muerto.\n");
      return(0);
   }

   if (!me->query_tracker()) {
     tell_object(me,"Rastreando a "+capitalize(who)+".\n");
     load_shadows(me,vic);
     me->adjust_gp(-TRACK_COST);
   }
   else {   // encontramos la victima que rastreabamos  
     tell_object(me,"Encontraste lo que buscabas!!.\n");
     me->destruct_tracker_shadow();
   }

   return(1);
}

// en esta funcion pegamos a la victima la shadow para que empiece a dejar huellas

load_shadows(object me, object vic)
{
   int time ;
   object shed;

// lo voy a partir por 3, me parece demasiado poco 5 (son asesinos(wis))   
// por lo menos hasta que haya rangers
   time = ((int)me->query_level() / 3) * (int)me->query_wis();

   if (vic->query_being_tracked()) vic->destruct_tracked_shadow();

   shed = clone_object(TRACKED_SHADOW);
   shed->move(vic);
   shed->start(vic);

   shed->set_time_factor(TIEMPO);
   vic->add_timed_property("being_tracked",1,time*3/2);
}

string help(string str)
{
   return
      "Rastrear:\n\n"
      "GP Coste: 2\n"
      "El asesino tiene la habilidad de seguir los rastros de sus victimas para "
      "asi mantenerse a distancia de ellas. Para poder usar el comando deberas "
      "primero reconocer las huellas de tu victima. Para ello deberas estar en la "
      "misma habitacion que el y poner:\n"
      "\tRastrear <victima>.\n"
      "Para poder seguir a tu objetivo puedes hacer dos cosas:\n"
      "- Usar el comando rastrear a secas, con lo que veras todas las huellas de "
      "la habitacion.\n"
      "- Usar rastrear <victima> con lo que te centraras en un solo un objetivo. "
      "De esta forma tan solo tendras que seguir las direcciones que te marquen, con "
      "el consiguiente ahorro de tiempo y energias.\n";
}


// rastreamos el suelo en busca de todas las huellas

void rastrea_solo()
{
  int i;
  string *huellas;
  string victim;
  int none;
  
  if (!TP->query_tracking()) return;
  if (ENV(TP)->query_property("no_track")) {
    tell_object(TP,"Te sera imposible encontrar huellas de alguien en este "
     "tipo de terreno.\n");
    if (TP->query_tracking()) TP->dest_tracking_shadow();
    return;
  }
    
  huellas = keys(ENV(TP)->query_timed_properties());
  
  none = 1;
  for (i=0;i<sizeof(huellas);i++) {
   if (strsrch(huellas[i],"track")>-1) {
     victim = extract(huellas[i],6,strlen(huellas[i]));
     if (ENV(TP)->query_timed_property("track_"+capitalize(victim)) &&
         ENV(TP)->query_timed_property("track_"+capitalize(victim))!="nowhere" &&
	 ENV(TP)->query_timed_property("track_"+capitalize(victim))!="."
        ) {

       tell_object(TP,"Encontradas huellas de "+capitalize(victim)+" "
       +tiempo_huellas(ENV(TP)->query_time_remaining("track_"+capitalize(victim)))
       +" en direccion "+ENV(TP)->query_timed_property("track_"+capitalize(victim))+".\n");

       none = 0;
     }
   }
  }


  if (none) tell_object(TP,"No encontraste huellas de nadie por aqui.\n");
  if (TP->query_tracking()) TP->dest_tracking_shadow();
}

// rastreamos el suelo en busca de las huellas de una sola persona

void rastrea_alguien(string victim)
{
  int i;
  string *huellas;
  int none;
  object sher;
  
  if (!TP->query_tracking()) return;

  if (ENV(TP)->query_property("no_track")) {
    tell_object(TP,"Te sera imposible encontrar huellas de alguien en este "
     "tipo de terreno.\n");
    if (TP->query_tracker()) {
      TP->dest_tracker_shadow();
      tell_object(TP,"Parece que has perdido su rastro.\n");
    }
    if (TP->query_tracking()) TP->dest_tracking_shadow();
    return;
  }

  
  huellas = keys(ENV(TP)->query_timed_properties());
  
  none = 1;
  for (i=0;i<sizeof(huellas);i++) {
   if (strsrch(huellas[i],"track")>-1) {

     if (ENV(TP)->query_timed_property("track_"+capitalize(victim)) &&
         ENV(TP)->query_timed_property("track_"+capitalize(victim))!="nowhere" &&
	 ENV(TP)->query_timed_property("track_"+capitalize(victim))!="."
        ) {
       tell_object(TP,"Encontradas huellas de "+capitalize(victim)+" "
       +tiempo_huellas(ENV(TP)->query_time_remaining("track_"+capitalize(victim)))
       +" en direccion "+ENV(TP)->query_timed_property("track_"+capitalize(victim))+".\n");

       none = 0;
     }
   }
  }

  if (none) {
    tell_object(TP,"No encontraste huellas de "+capitalize(victim)+" por aqui.\n");
    if (TP->query_tracker()) {
      TP->dest_tracker_shadow();
      tell_object(TP,"Parece que has perdido su rastro.\n");
    }
  }
  else if (!TP->query_tracker()) {
      sher = clone_object(TRACKER_SHADOW);
      sher->move(TP);
      sher->start(TP);
      sher->set_victim(victim);
  }
  
  if (TP->query_tracking()) TP->dest_tracking_shadow();
  
}

string tiempo_huellas(int x)
{
  string mess;
  int aux;

  mess = "de ";
  
  aux = TIEMPO - x;
  aux *= 4;
  if (aux >= 0) {
    switch (aux) {
      case 0..10 : mess += "unos 10 segundos"; break;
      case 11..20: mess += "unos 20 segundos"; break;
      case 21..30: mess += "unos 30 segundos"; break;
      case 31..60: mess += "menos de 1 minuto"; break;
      case 61..90: mess += "menos de minuto y medio"; break;
      default: mess += "menos de "+(int)((aux/60)+1)+" minutos"; break;
       
    }
  }
  else mess = "";
  
  return (mess);
}
  