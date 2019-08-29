#include "../../path.h"
inherit "/std/room.c";

object board, flores, enanos, osucaru;

void setup()
{
 int i;
 
set_short("%^YELLOW%^Ciudad de Anduar: Monumento de Osucaru.%^RESE
T%^");
 set_long("Esta es plaza en recuerdo de del Dios OSUCARU. Sin duda un gran "
   "amigo para todos nosotros, que nunca olvidaremos. Su facil sonrisa y la "
   "gran ilusion que mostraba al crear algo como el mud es la prueba de que "
   "sin duda era una persona querida por todos aquellos que lo conocian. "
   "Absurdo, su dominio llenaba de carisma a todos los jugadores. Y es un "
   "honor dedicar esta plaza en memoria de aquel que un dia nos dio su "
   "amistad y esfuerzo. Siempre te recordaremos en el bien de todos aquellos "
   "que te rodean. Intentaremos no defraudarte nunca, y llevaremos acabo con "
   "toda ilusion aquello que te recuerda y te honra como persona y amigo, un "
   "mud para Osucaru, un mundo de posibilidades y fantasias para el, sin duda "
   "ahora esta formando parte de aquellas estrellas que narran las hazanyas "
   "de los heroes y dioses de fantasia. Siempre miraremos arriba, cuando el "
   "sol se ponga y te recordaremos como la estrella mas brillante de nuestro "
   "mundo. Porque tu has formado parte de el, y nosotros estamos orgullosos "
   "de ello. Osucaru, este mud es en honor a ti. Nunca te olvidaremos.\n");

set_light(50);
   add_sign("Es un cartel metalico puesto en una de las paredes.\n", 
            "\n"+
            "/---------------------------------------------\\\n" +
            "|                                             |\n" +
            "|                                             |\n" +
            "|               Monumento a Osucaru           |\n" +
            "|                                             |\n" +
            "|                                             |\n" +
            "|  Monumento en memoria de Oscar, Osucaru, un |\n" +
            "|  gran amigo, una gran persona, un gran      |\n" +
            "|  programador, Osucaru nunca te olvidaremos  |\n" +
            "|  que descanses en paz.                      |\n" +
            "|                                             |\n" +
            "|  Los inmortales del mud, companyeros de     |\n" +
            "|  clase, amigos.                             |\n" +
            "|                                             |\n" +
            "|                                             |\n" +
            "| Sabado, 12 de junio de 1999                 |\n" +
            "|                                             |\n" +
            "\\---------------------------------------------/\n" );
   add_clone(ANDUAR"templo/corona.c",35);
   add_clone(ANDUAR"templo/osucaru.c",1);
   add_clone(ANDUAR"templo/enanos.c",4);
   add_exit("fuera", ANDUAR+"cruce1313", "road");
set_light(50);
if(!osucaru)
{
   osucaru=clone_object(ANDUAR"templo/osucaru.c");
   osucaru->move(TO);
}

for(i=0;i<35;i++)
{
   flores=clone_object(ANDUAR"templo/corona.c");
   flores->move(TO);
}

for(i=0;i<4;i++)
{
   flores=clone_object(ANDUAR"templo/enanos.c");
   flores->move(TO);
}


if(!board)
{
    board=clone_object("/obj/misc/board");
    board->set_datafile("osucaru");
    board->move(TO);
}


}

void reset()
{
  if(!board)
  {
  
  }

}
