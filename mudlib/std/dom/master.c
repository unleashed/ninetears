inherit "/secure/dom/domain.c";

void create() {
   	::create();
   	set_domain_lord(DOM_LORD);
   	set_domain(DOMAIN);
   	set_open_read(1);
   	set_open_write(0);
   	set_finger_info("\nUn dominio de Ninetears, Pregunta a su Thane para mas informacion.\n\n");

   	save_me();
	}
