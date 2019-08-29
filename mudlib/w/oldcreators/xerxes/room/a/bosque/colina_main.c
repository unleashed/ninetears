/* 
   Bosque de Urghak (sin ranitas)
   ------------------------------
   Xerxes, 2002
*/

inherit "/std/outside.c";

     string long = "%^ORANGE%^Colina en el %^GREEN%^bosque%^RESET%^\n\n"
      "Esta zona del bosque se encuentra configurando una ligera colina, "
	"libre de la maleza y los siniestros arboles que conforman el bosque. "
	"Aqui la tierra es mas oscura, ennegrecida por la ceniza que la cubre. "
	"Desde aqui puedes ver un poco mejor el cielo: oscuro y grisaceo, "
	"parece anunciar una inminente tormenta.\n\n";
	
     string short = "%^ORANGE%^Colina en el %^GREEN%^bosque%^RESET%^";

void do_desc(int do_short, int do_long)
{
    if (do_long)
	set_long(long);
    if (do_short)
        set_short(short);
    set_light(80);
  
    set_zone("bosque_urghak");
} /* do_dest */