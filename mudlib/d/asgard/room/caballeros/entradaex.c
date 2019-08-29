//.oO JaDe Oo.  Junio'02
inherit "/std/room";

void setup ()
{
set_short ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Entrada");
set_long ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Entrada\n\n"
          "Este es el gran port�n de entrada al gremio de los Caballeros de JaDe. "
          "Est� hecho de adamantita pura al igual que las dos enormes columnas que "
          "hay a cada lado de �l. Como es obvio, no hay fuerza humana capaz de "
          "moverlo, as� que deduces que se abrir� mediante algun tipo de "
          "mecanismo... Quiz� magico? En cualquier caso algo te dice que no ser� "
          "tarea f�cil.\n");
	add_item(({"columna","columnas"}),"Hechas de adamantita pura, toda una obra de artesan�a. Mirando m�s de cerca observas "
	"multitud de grabados y en especial unas runas que parecen emitir pulsos de energ�a.\n");
	
        set_exit_color("magenta");
	add_exit ("norte", "/d/asgard/room/caballeros/", "door"); 
        add_exit ("sur", "/d/asgard/room/caballeros/pasillo.c", "door");

}
