//.oO JaDe Oo.  Noviembre'02
inherit "/std/guildroom";

object guildmaster;

void setup()
{
  set_short("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala Principal");
  set_long("%^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^%^BLACK%^Caos%^RESET%^: Sala Principal\n\n"
           "Te encuentras en la sala principal del gremio, donde se alistan y se entrenan "
           "a los Sacerdotes del Caos. En la habitaci�n reina un inquietante silencio, "
           "ocasionalmente roto por alg�n c�ntico de los sacerdotes. "
           "La iluminaci�n de la sala proviene de una llama azul en el centro creada m�gicamente. "
           "Al fondo observas un peque�o altar de m�rmol.\n\n");
  add_item(("altar"),"Hecho enteramente de m�rmol gris oscuro, con el s�mbolo del guild tallado en �l.");
  add_item(("llama"),"El s�mbolo del gremio. Una incombustible llama azulada");
  add_sign("Un signo rojizo preside la pared.\n",
  	   "\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n"
           "\t|                                      | \n"
           "\t|  Gremio de los %^BOLD%^%^RED%^H%^RESET%^%^RED%^echiceros %^RESET%^del %^BOLD%^BLACK%^Caos%^RESET%^   | \n"
           "\t|                                      | \n"
           "\t|   -- Escribe 'alistarse' para unirte | \n"
           "\t|      al gremio.                      | \n"
           "\t|   -- Para mas informaci�n acerca del | \n"
           "\t|      del gremio, escribe 'info'.     | \n"
           "\t|   -- Para ver las habilidades        | \n"
           "\t|      disponibles escribe 'skills'.   | \n"
           "\t|   -- Para ver lo que te cuesta       | \n"
           "\t|      entrenar una habilidad          | \n"
           "\t|      escribe 'coste'.                | \n"
           "\t|                                      | \n"
           "\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n");
          
 
  set_exit_color("red");
  set_guild("magos/hechicerocaos");
  set_teaching_person("riya");

  add_exit ("noroeste", "/d/asgard/room/hechiceros/esc4-5.c", "door");
  
}

void reset()
{
	if (!guildmaster) {
		guildmaster = clone_object("/d/asgard/npc/riya.c");
		guildmaster->move(this_object());
	}
}

int do_join(string str)
{
	if (!guildmaster) {
		notify_fail("No hay nadie que te pueda alistar al gremio en este momento.\n");
		return 0;
	}
	if (guildmaster->query_fighting()) {
		notify_fail("La guildmaster no te puede alistar, est� ocupada pensando en sus enemigos.\n");
		return 0;
	}
	this_player()->set_kill_xp((this_player()->query_level() / 2) * 1000000);
	return ::do_join(str);
}

int do_advance(string str)
{
	if (!guildmaster) {
		notify_fail("No has notado que tu maestra... NO est�?\n");
		return 0;
	}
	if (guildmaster->query_fighting()) {
		notify_fail("Tu guildmaster esta mas preocupada en matar a sus enemigos.\n");
		return 0;
	}
//	if (::do_advance(str)) {
//		this_player()->set_kill_xp((this_player()->query_level() / 2) * 1000000);
//		return 1;
//	}
//	return 0;
}

int sacerdote_test()
{

        if (!guildmaster) {
                notify_fail("Ahora que Riya no esta, nada te impide entrar en las estancias privadas de los Sacerdotes del Caos.\n");
                return 1;
        }
	else
	{
		if((string)(this_player()->query_guild_ob()) != "/d/gremios/clerigo/sacerdotecaos")
		{
		notify_fail("Riya te impide la entrada a las estancias privadas.\n");
		return 0;
		}
		else
		{
//                notify_fail("Bienvenido al gremio.\n");
                return 1;

		}
	}
}


