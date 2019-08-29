#define HP_RESTORE 8
#define VALUE 250

#include "/std/object.c"

 int query_auto_load() { return 1; }
void setup()
{
   set_name("hongo verde");
   set_main_plural("hongos verdes");
   add_alias("hongo");
   add_plural("hongos");
   set_short("Un hongo verde");
   set_long("Esta es una rara variedad de grandes hongos, ciertamente "
      "es de los mas grandes ke hayas visto.  Es de color verde parecido "
      "al tono de una manzana, e igual de apetitoso. Si al menos pudieras "
      "recordar si este es de los comestibles.\n");
   set_value(VALUE);
   set_weight(5);
}
void init()
{  add_action("do_eat","comer");
   ::init();
}
int do_eat(string what)
{  if(what == "hongo")
   {   this_player()->adjust_hp(5+random(5));
       write("\n Muerdes con decision el hongo verde y te lo tragas. "
         "\nHummm, fresco y vigorizante.\n");
      this_object()->dest_me();
      return(1);
   }
   return(0);
}
