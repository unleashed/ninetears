//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Hall de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Entrada");
set_long ("Hall de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Entrada\n\n"
          "Esta es la entrada al edificio gubernamental de Asgard. En su interior "
          "se encuentran la prisi�n y la biblioteca. Aqu� se realizan las gestiones "
          "meramente civiles de la ciudad.\n\n");
	set_light (60);
        set_exit_color("blue");
	add_exit ("este", "/d/asgard/room/hall/hall.c", "corridor");
	add_exit ("oeste", "/d/asgard/room/callexxx.c", "corridor");

}
