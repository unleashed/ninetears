#define DOM_LORD "tyrael"
#define DOMAIN "anduar"
inherit "/secure/dom/domain.c";

void
create()
{
   ::create();
   set_domain_lord(DOM_LORD);
   set_domain(DOMAIN);
   set_open_read(0);
   set_open_write(0);
   set_finger_info("\nAnduar fue levantada por los humanos nada mas ser "
   "creados por los Dioses, y desde entonces es considerada el centro de las "
   "tierras conocidas. En ella se levanta la mas poderosa de las torres de "
   "hechiceria, y la rodean las llanuras de Dendara y Orgoth y las "
   "montanyosas regiones del oeste. En sus limites al sur se situa la Grieta "
   "del Olvido, de la cual antiguas leyendas hablan de que se abrio durante "
   "una cruenta lucha entre el bien y el mal, y que en el fondo de la misma "
   "todabia quedan diabolicas criaturas contra las cuales luchar y que en el "
   "fondo de la misma fue donde Oskuro derroto al anterior dios del Bien y al "
   "dios de la justicia. Mientras que En sus limites al norte se situa La "
   "Torre Negra una gigantesca construccion de obsidiana, de la cual las "
   "mismas leyendas dicen que fue levantada por el mismisimo Oskuro, para "
   "desde alli mandar ataques ha las fortalezas del bien. \n");

set_read_perms(([ ]));
save_me();

   // Look at /secure/dom/README for more info
}
/*int valid_read(string *path, string euid, string funct)
{
    return 1;
}*/   
