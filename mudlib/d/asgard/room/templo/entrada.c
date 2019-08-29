//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^BLACK%^Templo de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Entrada");
set_long ("%^BOLD%^%^BLACK%^Templo de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Entrada\n\n"
          "Te encuentras en la entrada de la que sin duda es la mayor de las construcciones "
          "de Asgard: el Templo de JaDe. Un escalofr�o recorre tu espinazo haci�ndote estremecer. "
          "Sientes que a pesar del macabro silencio que reina en el lugar, algo acecha en la "
          "oscuridad.\n\n");
	
        set_exit_color("magenta");
	add_exit ("este", "/d/asgard/room/templo/altar.c", "corridor");
	add_exit ("noroeste", "/d/asgard/room/templo/columna1.c", "corridor");
	add_exit ("noreste", "/d/asgard/room/templo/columna2.c", "corridor");
	add_exit ("sudoeste", "/d/asgard/room/templo/columna3.c", "corridor");
	add_exit ("sudeste", "/d/asgard/room/templo/columna4.c", "corridor");

}
