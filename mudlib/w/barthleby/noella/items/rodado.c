inherit "/std/item.c";
void setup()
{
   set_short("Canto rodado");
   set_name("rodado");
   set_main_plural("Cantos rodados");
   add_plural("cantos");
   add_alias("canto");
   add_alias("rodado");
   add_alias("canto rodado");
   set_long("La tipica piedra lisa y redonda que puedes encontrate en la orilla de cualquier rio.\n");
   set_weight(5);
   set_value(1);
}
   int query_rodado_sacrificio()
{
 return 1;
}
