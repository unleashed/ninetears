#define DOM_LORD "god"
#define DOMAIN "heaven"
inherit "/secure/dom/domain.c";

create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(1);
   set_open_write(0);
   set_finger_info("\nThe place when the elders rest.\n");
   set_write_perms(([
      "/d/heaven/logs" : 2 
      ]));

   save_me();
}
