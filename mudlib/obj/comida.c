// Vilat 29.10.2002 - Comida
// Comiendo por etapas

#define TIPOS ({"comida","bebida","alcohol"})

inherit "/std/item";

int curacion=1;
int mal_estado;
string tipo="comida";
object digestion;

int query_comida() { return 1; }

void init() {
	::init();
	if(tipo=="comida") add_action("comer","comer");
	else add_action("comer","beber");
	}

void mostrar_mensajes(object me) {
	string verbo="bebe";
	if(tipo=="comida") verbo="come";
	tell_object(me,"Te "+verbo+"s "+TO->query_short()+".\n");
	tell_room(ENV(me),me->query_cap_name()+" se "+verbo+" "+TO->query_short()+".\n",me);
	}

int comer(string str) {
	if (member_array(str,TO->query_alias()+({TO->query_name()}))==-1) return 0;
	if(TP->query_dead()) return notify_fail("Los espiritus no pueden "+query_verb()+".\n");
	if(sizeof(TP->query_attacker_list())) return notify_fail("No parece el mejor momento para pararse a "+query_verb()+".\n");
	switch(tipo) {
		case "comida":
		if (mal_estado) {
			TP->adjust_hp(-random(curacion/10)-1);
			tell_object(TP,"Al comerte "+TO->query_short()+" le notas un saborcillo desagradable.\n");
			tell_room(ENV(TP),TP->query_cap_name()+" esboza una mueca de asco al comerse "+TO->query_short()+".\n",TP);
			TO->dest_me();
			return 1;
			}
		TO->init_digestion(TP);
		return 1;
		case "bebida":
		curacion=-curacion;
		case "alcohol":
		TP->adjust_volume(0,curacion);
		mostrar_mensajes(TP);
		TO->dest_me();
		return 1;
		}
	}

void set_curacion(int i) { if(i>1) curacion=i; }
int query_curacion() { return curacion; }

void corromper() { mal_estado=1; }

void set_tipo(string str) {
	str=lower_case(str);
	if (member_array(str,TIPOS)==-1) {
		log_file("errores_objetos","Tipo incorrecto de plato en "+file_name(TO)+"\n");
		return;
		}
	tipo=str;
	}
string query_tipo() { return tipo; }

void init_digestion(object me) {
	if(sizeof(me->query_call_outed()+me->query_attacker_list())) {
		tell_object(me,"Engulles rapidamente "+TO->query_short()+" por si se acercan tus enemigos.\n");
		tell_room(ENV(me),"Con una velocidad inaudita, "+me->query_cap_name()+" se mete "+TO->query_short()+" en el buche y engulle el alimento sin apenas masticar!\n",me);
		me->adjust_ep(random(curacion/2)+1);
		TO->dest_me();
		return;
		}
	tell_object(me,"Te sientas y empiezas a comerte "+TO->query_short()+".\n");
	tell_room(ENV(me),me->query_cap_name()+" se sienta y empieza a comerse "+TO->query_short()+".\n",me);
	digestion=clone_object("/obj/shadows/comiendo.c");
    	digestion->init_rutina(me,TO);
    	me->add_extra_look(digestion);
	}