inherit "/std/room";
#include "path.h"
#include "config.h"
object board;

void setup ()
{
set_short("%^GREEN%^Hall de Casa Sharka%^RESET%^.");

set_long("%^GREEN%^Hall de Casa Sharka%^RESET%^.\n\nNo sabes la suerte "
" que tienes al poner acceder al exclusivo hall del poderoso inmortal "
" Sharka que gracias a sus extraordinarios poderes creo este recinto\n\n");

set_light (60);

add_sound("Deckard","Bienvenidos a la casa del inmortal Sharka\n");

set_exit_color("magenta");

add_exit("norte","/w/sharka/casa/tablon.c","door");
add_exit("sur","/w/sharka/casa/puertas.c","door");
modify_exit("norte", ({"function", "go_entrar"}));
}

void reset()

{
if (!guard) {
            guard = clone_object("/d/asgard/npc/deckard.c");
            guard->move(this_object());
            }
}

/*int knight_test()
{

if (!guard) {
            notify_fail("Ahora que Deckard no esta, nada te impide entrar en las estancias privadas de Sharka.\n");
            return 1;
            }
   else
      {
      if((string)(TP->query_race() != "/d/inmo") //falta arreglo
        {
        notify_fail("Deckard te impide la entrada a la casa de Sharka.\n");
        return 0;
        }
        else
           {
           notify_fail("Bienvenido a casa de Sharka.\n");
           return 1;
           }
      }
}
*/

int go_entrar()

{
string *razas_si = ({"inmortal"});
string mi_raza = TP->query_race();

if(!guard) {
           tell_object(TP,"Ahora que Deckard no esta, nada te impide entrar en las estancias privadas de Sharka.\n");
           return 1;
           }

if( member_array(mi_raza,razas_si)==-1 )
     {
     tell_object(TP,"Deckard se interpone en tu camino.\n");
     tell_room(ENV(TP),"Deckard se interpone en el camino de " +TP->query_cap_name()+".\n" ) ;
     return 0;
     }

return 1;
}
