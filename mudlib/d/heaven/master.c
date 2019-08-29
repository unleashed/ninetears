#define DOM_LORD "tyrael"
#define DOMAIN "heaven"
inherit "/secure/dom/domain.c";

void
create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(1);
   set_open_write(0);
   set_finger_info("\nUn dominio de acceso restringido a los inmortales que mas han hecho por Ninetears, mas que un dominio como tal es un Hall de Fama.\n");
   set_write_perms(([
      "/d/heaven/logs" : 2
      ]));

   save_me();
}
