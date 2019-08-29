#include "/w/barthleby/path.h"

inherit "/std/outside.c";


void setup()

{
    set_short("%^BOLD%^%^GREEN%^Plaza del Tapal%^RESET%^");
     set_long("%^BOLD%^%^GREEN%^Plaza del Tapal%^RESET%^\n\n"+
      "Es la plaza m�s grande de toda la ciudad. El suelo est� completamente cubierto " +
      "con piedras rugosas y unas grandes losas m�s lisas a modo de caminos en direcci�n " +
      "a los puntos cardinales, que parten del centro de la plaza donde se encuentra una " +
      "escultura dedicada a Barthleby. La vista de la catedral es perfecta desde aqu�.\n\n");

    set_light(70);

add_item("escultura","La escultura dedicada a Barthleby representa una especie de bast�n " +
        "casi plano invertido de unos tres metros y medio de alto, que termina en una " +
        "curva de cincuenta centimetros formando un �ngulo recto.\n");

add_item(({"piedras","losas","suelo"}),"Grandes piedras y losas bien asentadas cubren por " +
        "completo el suelo de la plaza.\n");

add_item("catedral","Contemplas la fachada oeste de la catedral. Unas escaleras rodeadas por " +
        "una alta verja met�lica conducen a su entrada principal.\n");
	
add_item("verja","Esta es la verja met�lica que rodea la entrada oeste de la catedral.\n");

//add_clone(NPC+"MINIATO", 1);
//add_clone(NPC+"crea_ciudadanos", 5);
//add_clone(NPC+"guardia_noella", 1);

add_exit("oeste", CALLEJONES+"callejon_D1","road");
add_exit("norte", CALLE+"calle11","road");
add_exit("este", CALLEJONES+"callejon_G4","road");
add_exit("sur", CALLE+"calle12","road");
add_exit("catedral", PRINCIPALES+"catedral","road");
add_exit("dentro", PRINCIPALES+"trabuk","road");

set_zone("noella");
}
