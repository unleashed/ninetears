#define HP_RESTORE 8
#define VALUE 100

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup()
{
   set_name("hongo rojo");
   set_main_plural("hongos rojos");
   add_alias("hongo");
   add_plural("hongos");
   set_short("Un hongo rojo");
   set_long("Al parecer, este debe de ser el hongo mas comun de todos. "
      "Esta lleno de ellos por todo alrededor. Si al menos pudieras "
      "recordar si es del tipo venenoso.\n");
   set_value(VALUE);
   set_weight(3);
}
void init()
{  add_action("do_eat","comer");
   ::init();
}
int do_eat(string what)
{  if(what == "mushroom")
   {   this_player()->adjust_hp(-18);
       write("\n Te hechas a la boca un poco del hongo rojo y lo tragas "
	     "con decision.  Sientes un ligero regustillo picante al "
	     "instante.\n");
      this_object()->dest_me();
      return(1);
   }
   return(0);
}
