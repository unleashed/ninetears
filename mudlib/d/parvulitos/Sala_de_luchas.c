#include "path.h"

inherit "/std/room.c";

void setup()
{
   set_short("\nSala del reto de la muerte.\n\n");

   set_long("Aqui se encuentra ubicado tu inmortal amigo Estigio. Aquel al que tuviste que matar para beber de la "
		"fuente. La sala es pequenya pero cumple con su cometido. Probar a los futuros inmortales en combate."
		" Si no resisten no se merecen tal condicion y su alma errara por siempre sin rumbo.\n\n");

   set_light(40);

   add_clone(NPC+"estigio",1);
   add_clone(NPC+"perro",1);
   add_clone(OBJ+"cuerpo",random(10));// El random sirve por si quieres hacer un numero aleatorio de algo..en este caso de 
						  //gente muerta. Va desde 0 hasta 9 en este caso(0 hasta el numero_indicado-1).

   add_exit("norte",APRENDICES+"pasillo_2","door");   

}

void init()
{
  ::init();
  add_action("trampa",({"go","goback","goto","dest","ed","home"}));
}

int trampa()
{
 write("Nonono, Eso es trampa.\n");
 return 1;
}






