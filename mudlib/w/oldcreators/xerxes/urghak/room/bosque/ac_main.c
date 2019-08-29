/* 
   Bosque de Urghak (sin ranitas)
   ------------------------------
   Xerxes, 2002
*/

inherit "/std/outside.c";

     string long = "%^ORANGE%^Alrededores de la colina de %^BLACK%^BOLD%^Urghak%^RESET%^\n\n"
      "La colina de Urghak fue el lugar escogido por los ancestros goblinoides "
	"para levantar el poblado con el mismo nombre. Se trata de un lugar "
	"bastante estrategico que facilita la defensa de la ciudad. Dirigiendo "
	"tu mirada hacia arriba, puedes ver los atisbos de las atalayas de Urghak, "
	"desde las cuales cualquier tirador goblin podria hacer de ti un blanco sencillo.\n\n ";
	
     string short = "%^ORANGE%^Alrededores de la colina de %^BLACK%^BOLD%^Urghak%^RESET%^\n\n";

void do_desc(int do_short, int do_long)
{
    if (do_long)
	set_long(long);
    if (do_short)
        set_short(short);
    set_light(80);
  
    set_zone("bosque_urghak");
} /* do_dest */