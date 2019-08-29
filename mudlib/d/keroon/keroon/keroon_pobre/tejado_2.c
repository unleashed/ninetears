// Made by Thalos  26/03/02
#include "../../path.h"
inherit "/std/suboscuridad";
#include "tejado.h"

void setup() {

  set_exit_color("CYAN");
  set_light(50);
  set_short("%^BOLD%^BLUE%^Tejados de %^BLACK%^Keeroon%^RESET%^");
  set_long("\n%^BOLD%^BLUE%^Tejados de %^BLACK%^Keeroon%^RESET%^.\n\n""Te encuentras en el resbaladizo tejado de una de las casa de la calle del suicidio de Keroon,ves algunas manchas de musgo y liquenes, desde aqui es donde acostumbran a saltar los duergars que acaban con su vida, tal vez puedas rebuscar entre las tejas y encontrar algo que hayan dejado antes del salto. ""\n\n");
	add_item(({"musgo","musgos"}),"Es un musgo verdoso, que hace que el tejado se convierta en una trampa mortal por lo resbaladizo que es, muevete con cuidado.\n"); 
	add_item(({"liquen","liquenes"}),"Es un liquen blanquecino, que hace que el tejado se convierta en una trampa mortal por lo resbaladizo que es, muevete con cuidado.\n"); 
}

void init(){
 ::init();
 add_action("rebuscar","rebuscar");
}

int rebuscar() {     
	int rebuscar=random(8);
	object premio;      
      
	switch (rebuscar) {
		case 0:
    	premio = new(ITEMSKEROONPOBRE+"capa_capitan.c");
		break;
    
    case 1:
    	premio = new(ITEMSKEROONPOBRE+"capa_capitan.c");
    break;
    
    case 2:
    	premio = new(ITEMSKEROONPOBRE+"capa_capitan.c");
    break;
    
    case 3:
    	premio = new(ITEMSKEROONPOBRE+"capa_capitan.c");         	                 
    break;
    
    case 4: 
    	premio = new(ITEMSKEROONPOBRE+"capa_capitan.c");
    break;
	}
  if(premio) {
  	premio->move(TP);
  	tell_object(TP,"Encuentras "+premio->query_short()+ " y lo coges rapido antes "
  	"saltar a la calle.\n");
  } 
  else {
  	tell_object(TP,"No encuentras nada y decides descender antes de caerte.\n");
  }
  
  TP->move(KEROONPOBRE+"keroon_362.c");
  if( TP->query_verbose() )
  	TP->look_me();
  else
    TP->glance();
    
  return 1;
}

