#define HP_RESTORE 8
#define VALUE 3

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup()
{
   set_name("hongo naranja");
   set_main_plural("hongos naranja");
   add_alias("hongo");
   add_plural("hongos");
   set_short("Un hongo naranja");
   set_long("El color y la forma de el hongo te recuerda a las naranjas de "
      "las que segun cuentan crecen en la superficie.  Aunque aquellas  "
      "cuelgan de los arboles, y estos se encuentran en los humedos suelos. "
      "Tienen una pinta realmente apetitosa y saludable.\n");
   set_value(VALUE);
   set_weight(4);
}
void init()
{  add_action("do_eat","comer");
   ::init();
}
int do_eat(string what)
{  if(what == "hongo")
   {   this_player()->adjust_hp(-15);
       write("\n Le das un mordisco al hongo naranja y te asombra su sabor "
 	 "fuerte. Continuas saboreando el hongo hasta que empiezas a notar "
	 "alguna nausea y te sientes debilitado.\n");
      this_object()->dest_me();
      return(1);
   }
   return(0);
}
