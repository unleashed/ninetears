//.oO JaDe Oo.  Noviembre'02
inherit "/std/room";

object guard;

void setup ()
{
set_short ("%^CYAN%^Sacerdotes %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Entrada");
set_long ("%^CYAN%^Sacerdotes %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Entrada\n\n"
          "Este es el recibidor del gremio de los Sacerdotes del Caos. Una sensaci�n de "
          "calma te invade por un momento, pero se disipa rapidamente al escuchar el incesante "
          "murmullo de los c�nticos que se filtran desde las habitaciones interiores. Por "
          "alguna extra�a raz�n te inquietan. Una gran columna central de m�rmol gris oscuro "
          "sostiene un orbe azulado que parece arder incombustiblemente.\n\n");
          
	add_item(("orbe"),"De un color azul intenso, parece recubierto de llamas azuladas.");
        set_exit_color("cyan");
//	add_exit ("noroeste", "/d/asgard/room/", "door"); 
        add_exit ("sudeste", "/d/asgard/room/sacerdotes/sala.c", "door");
}
       
void reset()
{
	if (!guard) {
		guard = clone_object("/d/asgard/npc/deckard.c");
		guard->move(this_object());
	}
}
       

         
