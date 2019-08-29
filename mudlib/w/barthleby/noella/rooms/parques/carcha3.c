#include "/w/barthleby/path.h"

inherit PARQUES"std_parques.c";

void setup()
{


   base_desc();
   set_exit_color("cyan");
   set_short("%^GREEN%^Parques de Carchan�m%^RESET%^");
   long_desc_carchanim();



add_item("fuente", "Es una fuente redonda de piedra y muy poco profunda que al llegar el " +
        "oto�o suele estar cubierta por las ojas ceidas de los magnolios.\n");

add_item(({"estatua","carchanim","Carchanim","carchan�m","Carchan�m"}),"Contemplas la estatua de Carchan�m en " +
        "medio de la fuente. Puedes ver como el agua surge de la boca del lobo blanco " +
        "que, seg�n cuenta la leyenda, salv� a los ni�os de la ciudad durante una " +
        "antigua batalla.\n");

add_exit("norte", PARQUES+"carcha1","road");
add_exit("este", PARQUES+"carcha4","road");
add_exit("sur", CALLE+"calle7","road");

}


