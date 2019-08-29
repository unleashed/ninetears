// Vilat 30.01.2003
// Furia para Khurgars

#define FURIA_SHADOW "/comandos/shadows/furia_sh.c"

void attack_all(object ob);
int allow_attack(object who, object me);
void end_furia(object ob); 
object shad;

int furia(object x) {
	object me; 
   	int BONUS;
   	int ACBONUS;
   	int COUNT;
   	int TIME;
   	if(!x) x = TP;
   	me = x;

   	COUNT = me->query_property("furioso");
   
   	if(me->query_gp() <= 1) return notify_fail("Estas demasiado cansado para desatar tu furia.\n");

   	switch(COUNT) {
   		case 0:
       		BONUS=((int)me->query_habilidad("furia")/3)+1;
    		ACBONUS = (BONUS - ((me->query_dex())/3));
    		me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    		me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    		me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
      		me->adjust_tmp_damage_bon(BONUS);
      		me->adjust_tmp_tohit_bon(BONUS*2);
      		me->adjust_tmp_ac_bon(-ACBONUS);
		if(me->query_ep() >= 25) {
   			me->adjust_ep(-25);
   			TIME = 25;
  			}
		else {
  			TIME = me->query_ep();
   			me->adjust_ep(-TIME);
 			}
      		me->add_timed_property("furioso",1,TIME);
      		tell_object(me,"Te enfureces contra tus enemigos.\n");
      		tell_room(environment(me),me->query_cap_name()+" se enfurece contra sus enemigos.\n",me);
		shad = clone_object(FURIA_SHADOW);
   		shad->setup_shadow(me);
      		attack_all(me);
      		break;
   		
   		case 1:
   		if (me->query_ep() < 50) return notify_fail("Tu cuerpo esta demasiado cansado para incrementar tu furia.\n");
   		if (me->query_habilidad("furia") < 15) return notify_fail("Aun no eres lo suficientemente experimentado como para llevar tu furia mas alla.\n");
   		BONUS=((int)me->query_habilidad("furia")/2)+2;
    		ACBONUS = (BONUS - ((me->query_dex())/2));
    		me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    		me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    		me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
       		me->adjust_ep(-50);
       		me->adjust_tmp_damage_bon(BONUS);
       		me->adjust_tmp_tohit_bon((int)BONUS*2);
       		me->adjust_tmp_ac_bon(-ACBONUS);
       		me->add_timed_property("furioso",2,40);
       		tell_object(me,"Alcanzas una furia moderada.\n");
       		tell_room(environment(me),me->query_cap_name()+" alcanza una furia moderada.\n",me);
    		break;
    		
    		case 2:
    		if (me->query_ep() < 100) return notify_fail("Tu cuerpo esta demasiado cansado para incrementar tu furia.\n");
    		if (me->query_habilidad("furia") < 35) return notify_fail("Deberas aprender un poco mas para desatar una furia mayor.\n");
		BONUS=((int)me->query_habilidad("furia")/1.75)+5;
		ACBONUS = (BONUS - (me->query_dex()) );
    		me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    		me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    		me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
        	me->adjust_ep(-100);
        	me->adjust_tmp_damage_bon(BONUS);
        	me->adjust_tmp_tohit_bon(BONUS*2);
        	me->adjust_tmp_ac_bon(-ACBONUS);
        	me->add_timed_property("furioso",3,100);
        	tell_object(me,"\n%^RED%^Tu furia te domina y atacas incluso a tus amigos.%^RESET%^\n");
		tell_room(environment(me),"\nLa furia de "+me->query_cap_name()+" es tal que deja de distinguir a amigos de enemigos.  %^BOLD%^%^RED%^Deberias escapar mientras todavia puedas!%^RESET%^\n",me);
    		break;
    		
    		case 3:
		if(!interactive(me)) return 0; // Para que los npcs no entren en el nivel 4
		if (me->query_habilidad("furia") < 70) return notify_fail("Solo los mas fuertes pueden alcanzar la Furia Definitiva.\n");
		BONUS=((int)me->query_habilidad("furia")*2)+5;
		ACBONUS = (BONUS - (me->query_dex()) );
    		me->adjust_tmp_ac_bon(-(me->query_tmp_ac_bon()));
    		me->adjust_tmp_damage_bon(-(me->query_tmp_damage_bon()));
    		me->adjust_tmp_tohit_bon(-(me->query_tmp_tohit_bon()));
		TIME = me->query_ep();
   		me->adjust_ep(-TIME);
   		me->add_property("exhausto_furia",1);
        	me->adjust_tmp_damage_bon(BONUS);
        	me->adjust_tmp_tohit_bon(BONUS*1.25);
        	me->adjust_tmp_ac_bon(-ACBONUS);
        	me->add_timed_property("furioso",4,TIME);
        	tell_object(me,"\n%^RED%^Tu furia alcanza su cenit! Pierdes la nocion de la realidad y tus fibras se estremecen mientras golpeas freneticamente..%^RESET%^\n");
		tell_room(environment(me),"\n"+me->query_cap_name()+" %^BOLD%^%^RED%^se ha vuelto loco!%^RESET%^\n",me);
    		break;
    		
    		default:
        	tell_object(me,"Estas golpeando con la fuerza de un dios, ya no puedes enfurecerte mas.\n");
    		break;
    		}
	return 1;
	}

int allow_attack(object who, object me) {
     	if(who == me) return 0;
     	if(!who->query_alive() ) return 0;
     	if(me->query_property("furioso") == 0 ) return 0;
    	if(who->query_pacify_spell()) return 0;
     	if(who->query_invis()) return 0;
     	if( who->query_hide_shadow() > (me->query_level()/2 + me->query_int()) ) return 0;
     	if(me->query_property("furioso") >= 3 ) return 1;
     	if(who->query_protector() == me) return 0;
     	return 1;
	}

void attack_all(object ob) {
  	object *gentuza;
  	int x;

   	if(!ob) return;
	ob->set_wimpy(0);

   	if(environment(ob)->query_property("noguild"));
   	if(ob->query_dead()) return;
 
   	gentuza=all_inventory(environment(ob));
 
   	for(x=0; x <sizeof(gentuza); x++) {
        	if(allow_attack(gentuza[x],ob)) ob->attack_ob(gentuza[x]);
        	continue;
   		}
   
   	if (!(ob->query_property("furioso")==0)) {
   		call_out("attack_all",5,ob);
   		return;
   		}
	end_furia(ob);
	return;
	}

void end_furia(object ob) {
   	shad->dest_furia_shadow();
	}
 
