#define DOM_LORD "god"
#define DOMAIN "newbie"
inherit "/secure/dom/domain.c";

create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(1);
   set_open_write(0);
   set_finger_info("\nOur homelands, no matter our race. The place of new "
      "beginnings, and first adventuring, where we learn something "
      "of how our future lives will be, yet free from attack by other peoples. "
      "\n\n");
   set_write_perms(([
      "/d/newbie/logs" : 2 
      ]));
   save_me();
}
