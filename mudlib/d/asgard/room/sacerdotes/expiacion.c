//.oO JaDe Oo.  Noviembre'02
inherit "/std/room";

void setup ()
{
set_short ("%^CYAN%^Sacerdotes %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala de Expiaci�n");
set_long ("%^CYAN%^Sacerdotes %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala de Expiaci�n\n\n"
          "La funci�n de esta sala es la de proporcionar a los miembros del gremio un "
          "lugar de confesi�n y penitencia. Al fondo de la sala observas un cub�culo "
          "de madera para las confesiones de los fieles. A ambos lados de la habitaci�n "
          "ves una especie de apoyaderos para los penitentes que deben arrodillarse para "
          "cumplir su castigo.\n\n");
	
        set_exit_color("cyan");
	add_exit ("oeste", "/d/asgard/room/sacerdotes/sala.c", "door");
	add_exit ("sur", "/d/asgard/room/sacerdotes/baul.c", "door");

}
