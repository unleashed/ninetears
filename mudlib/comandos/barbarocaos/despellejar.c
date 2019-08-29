//Vilat 20.08.2002
//Despellejar pieles para barbaros caoticos

#define PIEL "/comandos/items/piel.c"
#define EPS 10

string help() {
	return "Nombre del comando: Despellejar\nCoste EPs: "+EPS+"\nSintaxis: despellejar <cadaver>\nDescripcion:\n    Utilizando esta habilidad y un instrumento cortante, puedes arrancarle su piel a la victima. La piel puede ser curtida para crear capas mediante el comando \"curtir\". Por supuesto, no puedes arrancar la piel de algo que aun este vivo.";
    	}

int despellejar(string str,object x) {
  	object me;
  	object ob;
  	object* armas;
  	int valido=0;
  	int dosmanos=0;
  	object piel;
	object* presentes;
	int haycuerpo=0;
	
  	if(!x) x = TP;
  	me = x;
  	if(!str || str == "") str = "cuerpo";

  	if(me->query_dead()) return notify_fail("Tus manos etereas no son capaces de arrancar la piel de la victima.\n");
  	if (me->query_ep() < EPS ) return notify_fail("Estas demasiado cansado como para hacer salvajadas.\n");

  	armas = me->query_held_ob();
  	if ( armas[0] && armas[0]->query_attack_type() != 2 ) valido=1;
  	if ( armas[1] && armas[1]->query_attack_type() != 2 ) valido=1;
  	if (!valido) return notify_fail("�No crees que es dificil despellejar un cuerpo sin algo cortante?\n");
  	
  	if (armas[0] && armas[0]->query_twohanded()) dosmanos=1;
  	if (armas[1] && armas[1]->query_twohanded()) dosmanos=1;
  	if (dosmanos) return notify_fail("Despellejar un cuerpo con un arma a dos manos seria una autentica chapuza.\n");

  	presentes=all_inventory(environment(me));
	for (int i=0;i<sizeof(presentes);i++){
		if (presentes[i]->query_cap_name() == capitalize(str)) haycuerpo=1;
  		continue;
  		}
	if (!haycuerpo) return notify_fail("Imposible despellejar algo que no esta aqui.\n");
	
  	ob=find_match(str,environment(me))[0];
  	   
  	if(living(ob)) {
    		tell_object(ob,me->query_cap_name()+" se acerca a ti con la sana intencion de despellejarte, por suerte se da cuenta de que aun no has muerto justo antes de arrancarte la piel a tiras y se aparta de ti.\n");
    		return notify_fail("Probablemente "+ob->query_cap_name()+" no este de acuerdo con que le despellejes, pero puedes preguntarselo.\n");
    	}
 
  	if (!ob->query_corpse()) return notify_fail("Oye, oye, �no crees que te estas pasando intentando despellejar eso?\n");
  
   	if (ob->query_property("despellejado")) return notify_fail("Este cuerpo ya ha sido horriblemente despellejado por algun loco psicopata como tu!\n");
 
   	if(random(100)<=random(50+me->query_habilidad("despellejar"))) {
	    tell_object(me, "Despellejas a "+ob->query_short()+".\n");
  	    tell_room(environment(me), me->query_cap_name()+" despelleja a "+ob->short()+".\n", me);
  	    piel = clone_object(PIEL);
  	    piel->set_piel_name(ob->query_owner());
  	    piel->move(environment(me));
	    me->adjust_sp(1);
	    }
	else tell_object(me,"Intentas despellejar "+ob->query_short()+", pero destrozas la piel.\n");

   	ob->add_property("despellejado",1);
  	ob->set_long(ob->query_long()+"\nHa sido horriblemente despellejado.\n");
   	me->adjust_ep(-EPS);
 
  	return 1;
	}