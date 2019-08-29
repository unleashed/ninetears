//.oO JaDe Oo.  Junio'02
inherit "/std/room";

object guard;

void setup ()
{
set_short ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Entrada");
set_long ("%^BOLD%^%^BLACK%^Caballeros de %^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^: Entrada\n\n"
          "Un enorme arco cubierto de runas de un centelleante azul oscuro te da la "
          "bienvenida al gremio de los Caballeros de JaDe. O quiz� te esta advirtiendo "
          "del peligro? Observas un port�n a cada lado de la sala y un estrecho pasillo "
          "que se extiende delante tuya. S�mbolos her�ldicos y tapices decoran las "
          "paredes de la sala, iluminada por peque�os braseros colgantes en cada una "
          "de las esquinas.\n\n");
	
        set_exit_color("magenta");
	add_exit ("norte", "/room/camino_avalon/camino16", "door"); 
        add_exit ("sur", "/d/asgard/room/caballeros/pasillo.c", "door");
        add_exit ("este", "/d/asgard/room/caballeros/capilla.c", "door");
        add_exit ("oeste", "/d/asgard/room/caballeros/reflexion.c", "door");
        modify_exit("sur", ({"function", "knight_test"}));
        modify_exit("este", ({"function", "knight_test"}));
        modify_exit("oeste", ({"function", "knight_test"}));
  
 }
       
void reset()
{
	if (!guard) {
		guard = clone_object("/d/asgard/npc/deckard.c");
		guard->move(this_object());
	}
}
       
int knight_test()
{

        if (!guard) {
                notify_fail("Ahora que Deckard no est�, nada te impide entrar en las estancias privadas de los Caballeros de Jade.\n");
                return 1;
        }
	else
	{
		if((string)(this_player()->query_guild_ob()) != "/d/gremios/guerreros/caballerojade")
		{
		notify_fail("Deckard te impide la entrada a las estancias privadas.\n");
		return 0;
		}
		else
		{
//                notify_fail("Bienvenido al gremio.\n");
                return 1;
                }
         }
         
}