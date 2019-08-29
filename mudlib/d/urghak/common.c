#define DOM_TITLE "Dominio de Urghak"
#define DOM_LORD "Xerxes"
#define DOMAIN "urghak"
inherit "/std/dom/cmn_mas";
object board;

void setup() {
  set_dom(DOMAIN);
  add_property("luz_real",20);
  set_short("Habitacion comun del "+DOM_TITLE);
  set_long("Habitacion comun del "+DOM_TITLE+"\n\n"
             "     Te encuentras inmerso flotando en una enorme esfera rojiza de "
           "energia. De vez en cuando ves destellos de luz, seguidos de "
           "imagenes que asemejan lugares del "+DOM_TITLE+".\n     Quiza podrias "
           "viajar a lo ancho y largo del dominio entrando en alguna de"
           "esas imagenes. En el centro de la esfera, sobre una roca inmovil, "
           "se encuentra el trono del Thane del Dominio, %^RED%^"+
                DOM_LORD+"%^RESET%^.\n\n");

  board = clone_object("/obj/misc/board");
  board->set_datafile(DOMAIN);
  board->move(this_object());
  add_exit("bosque","/d/urghak/bosque/room/bosque/bosque1.c","path");
  add_exit("acantilado","/d/urghak/acantilado/room/acantilado001.c","path");
  add_exit("penumbra","/d/urghak/penumbra/room/puertas.c","path");
add_exit ("cienagas","/d/urghak/cienaga/room/01.c","door");
}

void dest_me()
{
  if(board) board->dest_me();
  ::dest_me();
}
