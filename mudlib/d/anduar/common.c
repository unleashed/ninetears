inherit "/std/dom/cmn_mas";
object board;

void setup() {
  set_dom("Anduar");
  set_light(50);
  add_exit("taberna", "/d/anduar/anduar/ciudad/taberna.c", "door");
add_exit("torre_negra", "/d/anduar/torre_negra/tn_9.c", "door");
  add_exit("cruce", "/d/anduar/anduar/ciudad/cruce1313.c", "door");
  add_exit("eloras", "/d/anduar/senda/rooms/taberna.c", "door");
  add_exit("laberinto", "/d/anduar/laberinto/senda50.c", "door");
  add_exit("cloacas", "/d/anduar/cloacas/rooms/c35.c", "door");
  add_exit("cantera", "/d/anduar/cantera/cantera/n1.c", "door");
  add_exit("comellas", "/d/anduar/carretera/rooms/pos.c", "door");
  set_short("Cuarto comun de Anduar");
  set_long("Una gran mesa de roble ocupa el centro de la habitacion, rodeada "
           "por multiples sillas, encima de la mesa una inmensa maqueta del "
           "dominio, cubriendo la practica totalidad de la misma. En las "
           "paredes diversas puertas que se dirigen a diferentes zonas del "
           "domino de Anduar, en el tablon, unos planos muestran planes "
           "futuros para la gran urbe, asi como para sus habitantes en lo "
           "alto de la sala un globo simulando el sol ilumina el cuarto.\n");
  add_item("mesa","una gran mesa de roble, reforzada por runas en todo su "
  "perimentro.");
  add_item("sillas","un grupo de sillas de roble.");
  add_item("maqueta","una maqueta representando el dominio hasta el mas "
  "minimo detalle.");
  add_item("globo","parece el sol, es una replica tan real que da hasta calor "
  "no te gustaria estar horas debajo de el");

  board = clone_object("/obj/misc/board");
  board->set_datafile("anduar");
  board->move(this_object());
}

void dest_me()
{
  if(board) board->dest_me();
  ::dest_me();
}
