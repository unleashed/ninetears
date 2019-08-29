#define DOM_LORD "tyrael"
#define DOMAIN "gremios"
inherit "/secure/dom/domain.c";

mapping patronajes;

void
create() {
	patronajes=([]);
   	::create();
   	set_domain_lord(DOM_LORD);
   	set_domain(DOMAIN);
   	set_open_read(0);
   	set_open_write(0);
   	set_finger_info("\nEl dominio que se encarga de las habilidades de los heroes.\n\n");

   	save_me();
	}

string *query_patronages(string quien) {
	return patronajes[quien];
	}

void add_patronaje(string quien,string gremio) {
	int i;
	mixed *gremios=values(patronajes);
	quien=lower_case(quien);
	gremio=lower_case(gremio);
	for (i=0;i<sizeof(gremios);i++) if(member_array(gremio,gremios[i])!=-1) patronajes[keys(patronajes)[i]]-=({gremio});
	if(!patronajes[quien]) patronajes[quien]=({gremio});
	else patronajes[quien]+=({gremio});
	save_me();
	}

void remove_patronaje(string gremio) {
	int i;
	mixed *gremios=values(patronajes);
	gremio=lower_case(gremio);
	for (i=0;i<sizeof(gremios);i++) if(member_array(gremio,gremios[i])!=-1) patronajes[keys(patronajes)[i]]-=({gremio});
	save_me();
	}

string query_patron(string gremio) {
	int i;
	mixed *gremios=values(patronajes);
	gremio=lower_case(gremio);
	for (i=0;i<sizeof(gremios);i++) if(member_array(gremio,gremios[i])!=-1) return keys(patronajes)[i];
	}
