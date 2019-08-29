// Made by Thalos  01/04/02
// Calle Pobre

inherit "/std/suboscuridad";
#include "../../path.h"
#define PROP_TEJADO "esc_tej_keroon"
#define TIEMPO_TEJADO 10800

void setup() {

   set_zone("keroon_pobre");
   set_exit_color("cyan");
   set_light(10);
   set_short("%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle del suicidio%^RESET%^");
   set_long("\n%^BOLD%^BLUE%^Ciudad de %^BLACK%^Keroon%^BLUE%^: Calle del suicidio%^RESET%^.\n\n""Estas en la calle del suicidio, una de las calles de la zona pobre de Keroon, esta calle es la preferida por aquellos duergars, que debido a sus desesperadas condiciones de vida deciden que la mejor solucion es acabar con ella, la eligen debido a que es muy facil trepar por los enrejados de las casa y desde el tejado de estas saltar a los hornos de las forjas donde se funde el metal.""\n\n");
add_item(({"reja","rejas","enrejado","enrejados"}),"Es el tipico enrejado de las casas duergars, no te costaria mucho escalarlo y alcanzar el tejado para saltar a los hornos pero tu no quieres suicidarte, verdad?.\n"); 

add_exit("oeste",KEROONPOBRE+"keroon_365.c","standard");
add_exit("este",KEROONPOBRE+"keroon_367.c","standard");
}
void init()
{
 ::init();
 add_action("escalar_enrejado","escalar");
}

int escalar_enrejado(string str)
{
  if(TP->query_property(PROP_TEJADO) ) {
  	notify_fail("Despues de la ultima vez, todavia no te ves con fuerzas de intentarlo de nuevo.\n");
  	return 0;
  }
  
  if(str=="enrejado")
  {
  TP->add_timed_property(PROP_TEJADO,1,TIEMPO_TEJADO);
  write("Con un gran esfuerzo escalas el enrejado y subes al tejado.\n");
  say(this_player()->query_cap_name()+" escala el enrejado.\n");
     this_player()->move(KEROONPOBRE+"tejado_5.c");
  
  return(1);
  }
  notify_fail("Escalar que?.\n");
  return(0);
}
