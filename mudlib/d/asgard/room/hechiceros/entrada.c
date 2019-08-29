//.oO JaDe Oo.  Noviembre'02
inherit "/std/room";

object guard;

void setup ()
{
set_short ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Entrada");
set_long ("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Entrada\n\n"
          "Un enorme arco cubierto de runas de un centelleante azul oscuro te da la "
          "bienvenida al gremio de los Caballeros de JaDe. O quiz� te esta advirtiendo "
          "del peligro? Observas un port�n a cada lado de la sala y un estrecho pasillo "
          "que se extiende delante tuya. S�mbolos her�ldicos y tapices decoran las "
          "paredes de la sala, iluminada por peque�os braseros colgantes en cada una "
          "de las esquinas.\n\n");
	
        set_exit_color("red");
	add_exit ("fuera", "/room/camino_avalon/camino16", "door"); 
        add_exit ("arriba", "/d/asgard/room/hechiceros/esc1-0.c", "stairs");
        modify_exit("arriba", ({"function", "sorc_test"}));
          
 }
       
void reset()
{
	if (!guard) {
		guard = clone_object("/d/asgard/npc/deckard.c");
		guard->move(this_object());
	}
}
       
int sorc_test()
{

        if (!guard) {
                notify_fail("Ahora que Deckard no est�, nada te impide entrar en las estancias privadas de los Caballeros de Jade.\n");
                return 1;
        }
	else
	{
		if((string)(this_player()->query_guild_ob()) != "/d/gremios/magos/hechicerocaos")
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