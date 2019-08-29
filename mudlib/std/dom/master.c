inherit "/secure/dom/domain.c";

create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(1);
   set_open_write(0);
   set_finger_info("\nA domain of Final Realms Mud, "
      "ask the Thane for more information.\n\n");

   save_me();

   // Look at /secure/dom/README for more info
}
