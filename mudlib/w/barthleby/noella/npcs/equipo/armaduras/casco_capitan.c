
inherit "/obj/armour"; 

void setup()  
 { 
   set_base_armour("helm");
   set_base_armour("yelmo");
   add_alias("casco");
   add_adjective("noella");
   add_alias("casco noella");
   set_short("casco de Noella");
   set_main_plural("cascos de Noella");
   add_plural("cascos");
   set_long("En su centro el casco lleva una insignia de Noella. S�mbolo"
            " de poder de aquellos que lo usan.\n");
   set_genero(0);
}
