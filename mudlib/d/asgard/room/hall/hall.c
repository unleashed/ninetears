//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Hall de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Recibidor");
set_long ("Hall de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Recibidor\n\n"
          "Aqui se atiende a los ciudadanos de Asgard, as� como a los forasteros "
          "que buscan alg�n tipo de informaci�n. Ves una peque�a mesa a modo de "
          "recepci�n y una vieja silla. Un gran candelabro colgando del techo "
          "ilumina la sala.\n\n");
	set_light (60);
        set_exit_color("blue");
	add_exit("oeste","/d/asgard/room/hall/entrada.c","corridor");
	add_exit("sur","/d/asgard/room/hall/pasillo.c","corridor");
	
	add_item("mesa","Bastante peque�a. Encima hay un libro de registro y un set de escritura.\n");
	add_item("silla","De madera corriente. Parece bastante vieja.\n");
}
