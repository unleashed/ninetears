#define DOM_LORD "tyrael"
#define DOMAIN "fuckin-fic"
inherit "/secure/dom/domain.c";

void
create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(0);
   set_open_write(0);
   set_finger_info("\nLa Fuckin-Fic fue levantada a finales del siglo XX "
   "para el horror y terror de los gurus de la informatica, los cuales "
   "deberian ser sodomizados profundamente en esta organizacion marxista "
   "para poder aspirar a chachos de la limpieza de la informatica.\n");

set_read_perms(([ ]));
save_me();

   // Look at /secure/dom/README for more info
}
/*int valid_read(string *path, string euid, string funct)
{
    return 1;
}*/   
