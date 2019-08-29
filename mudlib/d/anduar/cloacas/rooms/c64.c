// Cloaca.

#include "../../path.h" 

inherit CLOACAS+"bichos";

void setup()
{
   set_short("Cloacas de Anduar");
   set_long("Tus pies chapotean en el agua cenagosa de debajo de tus pies, "
   "llegando hasta las rodillas. Un olor nauseabundo similar al de un cadaver "
   "en descomposicion penetra por tu nariz, dandote arcadas y ganas de "
   "vomitar, por todos lados multitud de insectos se mueven, saltando entre "
   "las fangosas aguas.\n" 
   "Las paredes estan llenas de fango y moho por los cuales bajan chorros de "
   "agua mezclada con bichos en avanzado estado de descomposicion, ademas un "
   "pequenyo riachuelo de distintos colores, compuesto a saber por que "
   "materia circula lentamente por debajo de ti. Del techo cuelgan largos "
   "hilos de porqueria.\n");
   add_item("suelo", "El suelo es cochambroso.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas."
   "\n");
// add_exit("sudoeste", CLOACAS+"c63", "corridor");
   add_exit("fuera",  "/d/anduar/anduar/ciudad/cruce0813", "corridor");
   add_exit("este",  CLOACAS+"c65", "corridor");
   set_light(20);
   crea_bichos();
}

void init()
{
  ::init();
  add_action("girar","girar");
}

int girar(string str)
{
 if (str == "rueda")
  {
  write("Giras la rueda y escuchas como algo se vacia.\n");
  tell_room(environment(TP),TP->query_cap_name()+" gira una rueda y escuchas "
   "como algo se vacia.\n",TP);
   "/d/anduar/cloacas/rooms/c57.c"->add_exit( "norte", CLOACAS+"c58",
"corridor");
  return 1;
  }
 notify_fail("Que pretendes girar?.\n");
 return 0;
}
