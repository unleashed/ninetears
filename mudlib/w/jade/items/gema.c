//.oO JaDe Oo.  Junio'01
inherit "/std/item.c";
void setup()
{
   set_short("Gema de Cios");
   set_name("gema");
   set_main_plural("Gemas de Cios");
   add_plural("gemas");
   add_alias("gema");
   add_alias("cios");
   add_alias("gema de cios");
   set_long("Una bonita gema de colores irisados.\n");                    set_weight(5);
   set_value(100000);
}
   int query_gema_sacrificio() 
{
 return 1;
}
