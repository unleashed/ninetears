#define DOM_LORD  "aokromes"
#define DOMAIN  "aokromes"
inherit "/secure/dom/domain.c";

create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(0);
   set_open_write(0);

   save_me();

}
