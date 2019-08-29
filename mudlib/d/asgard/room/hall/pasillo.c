//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("Hall de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Pasillo");
set_long ("Hall de %^BOLD%^%^BLACK%^Asgard%^RESET%^: Pasillo\n\n"
          "Un amplio pasillo sobriamente decorado. Una alfombra morada cubre el suelo, "
          "en las paredes hay colgados un par de cuadros a un lado y el emblema de "
          "Asgard en el otro. Unos peque�os candelabros sobre una c�moda iluminan el "
          "pasillo. Una escalera de madera en espiral lleva hacia arriba.\n\n");
	set_light (60);
        set_exit_color("blue");
	add_exit("norte","/d/asgard/room/hall/hall.c","corridor");
	add_exit("sur","/d/asgard/room/hall/sala.c","corridor");
	add_exit("arriba","/d/asgard/room/hall/biblio1.c","corridor");
	
	add_item("emblema","El Ojo Esmeralda de Asgard.\n");
	add_item(({"cuadro","cuadros"}),"Representaciones de un enorme drag�n negro.\n"); 
}
