#define HP_RESTORE 8
#define VALUE 500

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup()
{
   set_name("hongo azul");
   set_main_plural("hongos azules");
   add_alias("hongo");
   add_plural("hongos");
   set_short("Un hongo azul");
   set_long("Esta es una variedad de hongo muy pequenyo.  Es con mucho "
      "el mas minusculo de todos los tipos de hongo que has visto en Dendall"
      ".  En principo parece comestible, incluso apetitoso. Si al menos "
      "pudieras recordar si es del tipo venenoso.\n");
   set_value(VALUE);
   set_weight(2);
}
void init()
{  add_action("do_eat","comer");
   ::init();
}
int do_eat(string what)
{  if(what == "hongo")
   {   this_player()->adjust_hp(random(5)+10);
       write("\nLe das un mordisco al hongo. "
         "\nHummm, bastante bueno.\n");
      this_object()->dest_me();
      return(1);
   }
   return(0);
}
