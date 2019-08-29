#define DOM_LORD "leviathan"
#define DOMAIN "parvulitos"
inherit "/secure/dom/domain.c";

void
create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(1);
   set_open_write(0);
   set_finger_info("\n%^BOLD%^WHITE%^El dominio destinado a la iniciacion de los creadores con menos conocimientos, "
		   "el lugar mas adecuado para dar los primeros pasitos sin tener que pedir ayuda, a modo "
		   "de quest.\n\n%^RESET%^");

   save_me();

   // Look at /secure/dom/README for more info
}
