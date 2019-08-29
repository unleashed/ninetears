/* Likewise this is Hamlet's.  Perhaps worm isn't the word. */
inherit "/std/container";
#include "path.h"
static int x =0;
 
object pot;
object ladle;

void setup() {
  set_name("stove");
  set_long("Una gran estufa de madera.\n");
  set_short("Estufa de madera");
  add_alias("estufa");
  set_value(0);
  set_weight(10000);
set_max_weight(10000);
  reset_get();

//  set_prevent_insert();

  if(!pot) {
    pot = clone_object(ITEMS+"pot");
    pot->move(this_object());
  }
  if(!ladle) {
    ladle = clone_object(ITEMS+"ladle");
    ladle->move(this_object());
  }
}

void init() {
  add_action("ladle_me","servir");
  ::init();
}

void ladle_me(string what) {
  object *playerhas;
  object thestew, thebowl;
  int i, maxi;
  int hasladle = 0;
  int hasbowl = 0;

  if( what != "estofado" )   return 0;

  playerhas = all_inventory(this_player());
  maxi = sizeof(playerhas);
  for(i=0;i<maxi;i++) {
    if( (string) playerhas[i]->query_name() == "cucharon" )
      hasladle = 1;
    if( (string) playerhas[i]->query_name() == "cuenco" ) {
      hasbowl = 1;
      thebowl = playerhas[i];
    }
  }
  
  if(!hasladle) {
    tell_object(this_player(),"Tal vez debas tener un cucharon antes.\n");
    return ;
  }
  if(!hasbowl) {
    tell_object(this_player(),"Tal vez debas ponerlo en un cuenco antes.\n");
    return ;
  }

  if(x < 4) {
  tell_object(this_player(),"te sirves unas garcilladas de estofado "
               "de la olla.\n");
  tell_room(environment(this_object()),this_player()->query_cap_name() +
             " se sirve una buena porcion de estofado de la olla.  "
             "Y huele muy bien!\n",({this_player()}));
  thestew = clone_object(ITEMS+"stew");
  thestew->move(thebowl);
  x++;
  return ;
  }
 else
  {tell_object(this_player(),"Lo siento has cogido la ultima porcion "
	"de estofado.\n");
   tell_room(environment(this_object()),this_player()->query_cap_name() +
	" ha comido la ultima porcion de estofado.....que gloton!.\n");
return ;
  }
}
         
