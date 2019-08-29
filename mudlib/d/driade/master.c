#define DOM_LORD "jade"
#define DOMAIN "driade"
inherit "/secure/dom/domain.c";

void create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(0);
   set_open_write(0);
   set_finger_info("\nDriade, la ciudad sobre la que se levantaran "
	"los nuevos reinos.\n");

set_read_perms(([ ]));
save_me();

   // Look at /secure/dom/README for more info
}
/*int valid_read(string *path, string euid, string funct)
{
    return 1;
}*/   
