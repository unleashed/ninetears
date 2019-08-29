//Vilat 24.08.2002
//Curtir pieles para barbaros caoticos

#define CAPA "/d/gremios/comandos/capa.c"
#define GPS 20

string help() {
	return "Nombre del comando: Curtir\nCoste GPs: "+GPS+"\nSintaxis: curtir\nDescripcion:\n    Con el equipo adecuado y una piel debidamente despellejada, el barbaro puede fabricarse su propio equipo. Actualemente solo se pueden curtir capas, pero mas adelante se crearan nuevos objetos curtibles.\n";
    	}

int curtir(string str,object x) {
  	object me;
  	object piel;
  	object capa;
  	object* inventario;
  	int haypiedra=0;
  	int haypiel=0;
  	
  	if(!x) x = TP;
  	me = x;

  	if(me->query_dead()) return notify_fail("Un fantasma no puede trabajar pieles.\n");
  	if (me->query_gp() < GPS ) return notify_fail("El cansancio te vence mientras intentas curtir pieles.\n");

  	inventario=all_inventory(me);
	for (int i=0;i<sizeof(inventario);i++){
		if (inventario[i]->query_cap_name() == "Piedra de curtir") haypiedra=1;
		if (inventario[i]->query_piel()) piel=inventario[i];
		if (piel) haypiel=1;
  		continue;
  		}
	if (!haypiel) return notify_fail("No dispones de ninguna piel para curtir.\n");
	if (!haypiedra) return notify_fail("Necesitas las herramientas necesarias para curtir pieles.\n");
	
  	if (random(20)>random(me->query_dex())) {
  		tell_room(environment(me),me->query_cap_name()+" rompe la piel de "+piel->query_property("origen")+" mientras la trabajaba.\n");
  		return notify_fail("No eres capaz de curtir adecuadamente la piel de "+piel->query_property("origen")+".\n");;
  		piel->dest_me();
  		}
  	tell_object(me, "Curtes la piel de "+piel->query_property("origen")+", fabricandote una bonita capa con ella.\n");
  	tell_room(environment(me), me->query_cap_name()+" curte la piel de "+piel->query_property("origen")+" fabricando una bonita capa.\n", me);
  	 
  	capa = clone_object(CAPA,1);
  	capa->set_capa_name(piel->query_property("origen"));
  	capa->move(me);
  	
  	piel->dest_me();
  	me->adjust_gp(-GPS);
 
  	return 1;
	}