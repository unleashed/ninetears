//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Paseo");
set_long ("%^BOLD%^%^YELLOW%^M%^RESET%^%^ORANGE%^ercado %^RESET%^de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Paseo\n\n"
	  "Paseando por el mercado observas multitud de tiendecillas y puestos de mercaderes ambulantes. "
	  "El ritmo aqui es mucho mas ajetreado que en el resto de Asgard. Gente yendo y viniendo, ni�os " 
	  "correteando, clientes examinando las mercancias y por supuesto los trabajadores y mercaderes "
          "trabajando sin parar.\n\n");
	set_light (60);
        set_exit_color("yellow");
        
	add_exit ("noreste", "/d/asgard/room/mercado/entrada.c", "path"); 
        add_exit ("oeste", "/d/asgard/room/mercado/comida.c", "path");
      
}
