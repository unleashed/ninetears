inherit "std/underground";

#include "caverna.h"

object drider1, drider2;

setup() 
{
  set_short("%^RED%^Caverna Oscura%^RESET%^");
  set_long("%^RED%^Caverna Oscura%^RESET%^\n\n" +
	   "La oscuridad reina en esta cueva excavada por manos expertas " +
           "sobre la roca. No parece haber ningun indicio de a donde va " +
           "o de donde viene, solo sabes que este sitio puede ser peligroso " +
           "para quien no esta habituado a el.\n\n");

	set_exit_color("red");
   add_exit("noreste","/room/caverna/cav02","corridor");
   add_exit("este","/room/caverna/cav04","corridor");
	modify_exit("noreste", ({"function", "pirarse"}));
	modify_exit("este", ({"function", "pirarse"}));
}

int pirarse()
{
	if (TP->query_race() != "drow") {
		if (TP->query_alive() && (drider1 || drider2)) {
			notify_fail("Un Drider te tapona la salida!\n");
			/*tell_room(TO, TP->QCN() + 
			" intenta huir, pero un Drider tapona su camino.\n", TP);
			*/
			return 0;
		}
	}
	return 1;
}

void reset() {
	if (!drider1) {
		drider1 = clone_object("/room/caverna/npcs/drider.c");
		drider1->add_property("NO_BUDGE",1);
		drider1->move(TO);
	}
	if (!drider2) {
		drider2 = clone_object("/room/caverna/npcs/drider.c");
		drider2->add_property("NO_BUDGE",1);
		drider2->move(TO);
	}
	::reset();
}
