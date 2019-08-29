#define DOM_TITLE "Dominio de Faeleen"
#define DOM_LORD "flangerant"
#define DOMAIN "faeleen"
inherit "/std/dom/cmn_mas";
object board;

void setup() {
  set_dom(DOMAIN);
  set_light(50);
  add_exit("cielo", "/w/common.c", "door");
  add_exit("ciudad","/d/faeleen/rooms/ciudad/puerta_norte.c", "door");
  set_short("Asamblea del Dominio de Faeleen.");
  set_long("Asamblea del Dominio de Faeleen.\n\n Una room por encima de la "
           "ciudad de Faeleen, flotando en el cielo. Desde aqui se divisa todo "
           "el dominio desde el suelo transparente. El clima no afecta aqui, asi como "
           "tampoco el dia y la noche.\n  "
           "Aqui se reunen los creadores del dominio para discutir algunas cosas " 
           "sin importancia.\n\n");
  

  board = clone_object("/obj/misc/board");
  board->set_datafile(DOMAIN);
  board->move(this_object());
}

void dest_me()
{
  if(board) board->dest_me();
  ::dest_me();
}
