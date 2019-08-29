inherit "/std/room";

mapping estado;

int clean_up(int i){ return 1; }

void poner_guardia(string file) {
	if(file_size(file)<1&&file_size(file+".c")<1) {
		log_file("ciudadanias","El cuerpo de guardia "+file_name(TO)+" tiene un guardia inexistente: "+file+" .\n");
		return;
		}
	if(!estado[file]) estado[file]=({0,1});
	else estado[file][1]++;
	}

void he_muerto(string file) {
	if(!estado[file]) {
		log_file("ciudadanias","El archivo "+file+" mando una notificacion de muerte sin pertenecer a este cuerpo.\n");
		return;
		}
	estado[file][0]--;
	}

void create() {
	estado=([]);
	::create();
	call_out("ciclo",0);
	}

void ciclo() {
	int i;
	object tmp;
	for (i=0;i<sizeof(keys(estado));i++) if(estado[keys(estado)[i]][0]<estado[keys(estado)[i]][1]) {
		tmp=clone_object(keys(estado)[i]);
		if(!tmp) continue;
		tmp->set_cuerpo(TO);
		tmp->move(TO,tmp->QCN+" sale a hacer la ronda.\n");
		estado[keys(estado)[i]][0]++;
		}
	call_out("ciclo",100);
	}
