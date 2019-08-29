#define DOM_LORD "vilat"
#define DOMAIN "ciudades"
inherit "/secure/dom/domain.c";
mapping regencias;
void

create() {
	regencias=([]);
   	::create();
   	set_domain_lord(DOM_LORD);
   	set_domain(DOMAIN);
   	set_open_read(1);
   	set_open_write(0);
   	set_finger_info("\nEl dominio donde se definen las relaciones de las ciudades.\n\n");

   	save_me();
	}

string *query_regencias(string quien) {
	return regencias[quien];
	}

void add_regencia(string quien,string ciudad) {
	int i;
	mixed *ciudades=values(regencias);
	quien=lower_case(quien);
	ciudad=lower_case(ciudad);
	for (i=0;i<sizeof(ciudades);i++) if(member_array(ciudad,ciudades[i])!=-1) regencias[keys(regencias)[i]]-=({ciudad});
	if(!regencias[quien]) regencias[quien]=({ciudad});
	else regencias[quien]+=({ciudad});
	save_me();
	}

void remove_regencia(string ciudad) {
	int i;
	mixed *ciudades=values(regencias);
	ciudad=lower_case(ciudad);
	for (i=0;i<sizeof(ciudades);i++) if(member_array(ciudad,ciudades[i])!=-1) regencias[keys(regencias)[i]]-=({ciudad});
	save_me();
	}

string query_regente(string ciudad) {
	int i;
	mixed *ciudades=values(regencias);
	ciudad=lower_case(ciudad);
	for (i=0;i<sizeof(ciudades);i++) if(member_array(ciudad,ciudades[i])!=-1) return keys(regencias)[i];
	}
