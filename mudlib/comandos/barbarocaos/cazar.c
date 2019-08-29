int inicio(string str, object me) {
    int bonus, i, j, weap_type;
    string weap_name;
    object target;
    object* weap;
    object* list;
    if(!me) me=this_player();

    if(me->query_timed_property("cazado")) return notify_fail("Debes tomarte mas tiempo para estudiar a tu oponente antes de llevar a cabo una maniobra tan calculada.\n");
    
    if(me->query_ep()<5) return notify_fail("Te encuentras demasiado fatigad"+me->query_vocal()+". Seria mejor descansar un poco antes de intentar cazar a alguien.\n");

    weap=me->query_weapons_wielded();
    if(!sizeof(weap)) return notify_fail("Si tu enemigo es tan debil que puedes usar tus propias manos para matarlo, tal vez no sea necesaria una maniobra semejante.\n");

    for (j = 0;j<sizeof(weap);j++) if(weap[j]->query_property("nocazar")) return notify_fail("No podras cazar a nadie si no posees las armas apropiadas.\n");

    if(!str) return notify_fail("�Cazar a qui�n?\n");

    list=find_match(str,environment(me));
    if(!sizeof(list)) return  notify_fail("Tan solo puedes cazar alguien presente.\n");

    target=list[0];
    if(target->query_dead()) return notify_fail("Crees en espiritus? Bien, aun si existieran, usarias mejor tu talento si cazaras alguna otra cosa.\n");

    if(target->query_hidden()) return notify_fail("Tan solo puedes cazar alguien presente.\n");

    if(target==me) return notify_fail("Tus sentidos est�n alerta y te esquivas a ti mismo.\n");

    if(me->query_hidden()) bonus=(me->query_level())/(sizeof(weap));
    else bonus=((me->query_level())/(sizeof(weap))/2);
    
    bonus+=random(me->query_habilidad("cazar"));

    for(i=0;i<sizeof(weap);i++) {
	weap_name=weap[i]->query_short();
        weap_type=weap[i]->query_attack_type();
	switch(weap_type) {
            case 1:
    	    tell_object(me,"Cortas viciosamente a "+target->query_cap_name()+" con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te corta viciosamente con su "+weap_name+".\n");
            tell_room(environment(me), me->query_cap_name()+" corta viciosamente a "+target->query_cap_name()+" con su "+weap_name+".\n",({me,target}));
            break;
            case 2:
            tell_object(me,"Machacas brutalmente a "+target->query_cap_name()+" con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te machaca brutalmente con su "+weap_name+".\n");
            tell_room(environment(me),me->query_cap_name()+" machaca brutalmente a "+target->query_cap_name()+" con su "+weap_name+".\n",({me,target}));
            break;
            case 3:
            tell_object(me,"Empalas cruelmente a "+target->query_cap_name()+" con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te empala cruelmente con su "+weap_name+".\n");
            tell_room(environment(me),me->query_cap_name()+" empala cruelmente a "+target->query_cap_name()+" con su "+weap_name+".\n",({me,target}));
            break;
            default:
            tell_object(me,"Atacas a "+target->query_cap_name()+" con tu "+weap_name+".\n");
            tell_object(target,me->query_cap_name()+" te ataca con su "+weap_name+".\n");
            tell_room(environment(me),me->query_cap_name()+" ataca a "+target->query_cap_name()+" con su "+weap_name+".\n",({me,target}));
            break;
    	    }
	me->adjust_tmp_tohit_bon(bonus*3);
        me->adjust_tmp_damage_bon(bonus);
        weap[i]->weapon_attack(target,me);
        me->adjust_tmp_damage_bon(-bonus);
        me->adjust_tmp_tohit_bon(-bonus*3);
	}
    target->attack_by(me);
    me->adjust_ep(-5);
    me->add_timed_property("cazado",1,10);
    return 1;
    }

string help(string str) { // Arreglar
   return
      "Cazar:\n\n"
      "Coste EPs: 5\n"
      "When a Ranger is hunting a person, he/she studies his oponent "
      "in order to find a weakness in his/her defenses.  The ranger "
      "then attacks gaining a short advantage.  The ranger can get a "
      "better advantage if the target doesn't even know if the ranger is "
      "there, because the ranger is hidden.  "
      "Once a weakness is exploited, the target will usually take "
      "measures to protect that weakness.  It takes the ranger a "
      "certain amount of time to find another weakness to exploit.  "
      "\n\nSintaxis: cazar <objetivo>\n\n";
    }
