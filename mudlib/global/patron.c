inherit "/global/regente";

#define  O_TYPE "P"

string query_gtitle() {
    string patronage;
    patronage = "/secure/patrons"->query_patronage(name);
    if(query_female()) return "la Patrona de"+patronage;
    else return "el Patr�n de"+patronage;
    }
	    
string query_object_type() {
    return O_TYPE;
    }

int query_patron() { return 1; }
