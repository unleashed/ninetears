inherit "/global/patron";

#define  O_TYPE "T"

string query_gtitle() {
    string patronage;
    patronage = "/secure/thanes"->query_of(name);
    if(query_female()) return "la Thane de"+patronage;
    else return "el Thane de"+patronage;
    }

int query_thane() { return 1; }
	    
string query_object_type() { return O_TYPE; }

void move_player_to_start(string bong,int np, int gi) {
    ::move_player_to_start(bong,np,gi);
    add_action("dar_regencia","nregente");
    add_action("dar_patron","npatron");
    add_action("dar_thane","nthane");
    add_action("dar_lord","nlord");
    add_action("dar_alquimista","nalquimista");
    add_action("dar_semidios","nsemidios");
    add_action("dar_dios","ndios");    
    }
    
int dar_regencia(string str) {
    string nombre,titulo;
    if(!str) return notify_fail("Uso: nregente <nombre> <titulo>\n");
    sscanf(str,"%s %s",nombre,titulo);
    if(!titulo) return notify_fail("Uso: nregente <nombre> <titulo>\n");
    notify_fail("Por alguna raz�n no has podido nombrar Regente a "+CAP(nombre)+".\n");
    return "/secure/rango"->regente(nombre,titulo,TO);
    }
    
int dar_patron(string str) {
    string nombre,titulo;
    if(!str) return notify_fail("Uso: npatron <nombre> <titulo>\n");
    sscanf(str,"%s %s",nombre,titulo);
    if(!titulo) return notify_fail("Uso: npatron <nombre> <titulo>\n");
    notify_fail("Por alguna raz�n no has podido nombrar Patr�n a "+CAP(nombre)+".\n");
    return "/secure/rango"->patron(nombre,titulo,TO);
    }

int dar_thane(string str) {
    string nombre,titulo;
    if(!str) return notify_fail("Uso: nthane <nombre> <titulo>\n");
    sscanf(str,"%s %s",nombre,titulo);
    if(!titulo) return notify_fail("Uso: nthane <nombre> <titulo>\n");
    notify_fail("Por alguna raz�n no has podido nombrar Thane a "+CAP(nombre)+".\n");
    return "/secure/rango"->thane(nombre,titulo,TO);
    }

int dar_lord(string str) {
    string nombre,titulo;
    if(!str) return notify_fail("Uso: nlord <nombre> <titulo>\n");
    sscanf(str,"%s %s",nombre,titulo);
    if(!titulo) return notify_fail("Uso: nlord <nombre> <titulo>\n");
    notify_fail("Por alguna raz�n no has podido nombrar Lord/Lady a "+CAP(nombre)+".\n");
    return "/secure/rango"->lord(nombre,titulo,TO);
    }
    
int dar_alquimista(string str) {
    string nombre,titulo;
    if(!str) return notify_fail("Uso: nalquimista <nombre> <titulo>\n");
    sscanf(str,"%s %s",nombre,titulo);
    if(!titulo) return notify_fail("Uso: nalquimista <nombre> <titulo>\n");
    notify_fail("Por alguna raz�n no has podido nombrar Alquimista a "+CAP(nombre)+".\n");
    return "/secure/rango"->alquimista(nombre,titulo,TO);
    }

int dar_semidios(string str) {
    string nombre,titulo;
    if(!str) return notify_fail("Uso: nsemidios <nombre> <titulo>\n");
    sscanf(str,"%s %s",nombre,titulo);
    if(!titulo) return notify_fail("Uso: nsemidios <nombre> <titulo>\n");
    notify_fail("Por alguna raz�n no has podido nombrar Semidios a "+CAP(nombre)+".\n");
    return "/secure/rango"->semidios(nombre,titulo,TO);
    }

int dar_dios(string str) {
    string nombre,titulo;
    if(!str) return notify_fail("Uso: ndios <nombre> <titulo>\n");
    sscanf(str,"%s %s",nombre,titulo);
    if(!titulo) return notify_fail("Uso: ndios <nombre> <titulo>\n");
    notify_fail("Por alguna raz�n no has podido nombrar Dios a "+CAP(nombre)+".\n");
    return "/secure/rango"->dios(nombre,titulo,TO);
    }
    