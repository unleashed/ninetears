/* SEGURO Q ESTO SE PUEDE HACER MAS LIMPIO */
/* FALTA HACER LA PARTE PARA SALIR
	QUE LOS GUARDIAS SE PROTEJAN ENTRE SI
	UNA IDEA SERIA PILLAR LA ACCION KILL Y COMPROBAR Q ES
	GUARDIA, USANDO EL EXPAND_NICKNAME POR LOS PILLINES */
/*	NO TIRA NI PA EL ADD_ACTION KILL YA Q SI USAMOS UN COMANDO... */
/*	TENEMOS UNA SOLUSION, USAR ATTACK_OB EN UN WARDIA PA ALERTAR
	A LOS DEMAS */

inherit "/std/outside";

object guardia1,guardia2,guardia3,guardia4;

void setup()
{
  set_short("%^GREEN%^Castillo sobre la Nada: Entrada%^RESET%^");
  set_long("%^GREEN%^Castillo sobre la Nada: Entrada%^RESET%^\n\n"
           "     Te encuentras ante la fastuosa entrada de este -aparentemente- "
           "pequenyo castillo.  Al oeste observas el camino que lleva hacia "
           "la civilizacion.  Esta entrada suele estar cubierta por guardias "
           "de la corona, cuya unica mision es no permitir la entrada ni "
           "la salida de nadie, tal vez para salvaguardar los secretos del "
           "interior... o tal vez para salvaguardar la vida del exterior\n\n");
  add_item("fachada", "De fastuosa factura, puedes observar ornamentos"
           " romanicos a traves de la tenue aura oscura que rodea el "
	   "edificio.\n");
  add_item("entrada", "De fastuosa factura, puedes observar ornamentos"
           " romanicos a traves de la tenue aura oscura que rodea el "
	   "edificio.\n");
  add_item("castillo", "Una voz retumba en tu mente: \"Tal vez sea "
	   "peligroso entrar ahi\".\n");
  add_sign("Un gran signo clavado en la pared.\n"
           "Parece que tiene algo escrito.\n",
           "\t ________________________________________  \n"
           "\t|\\______________________________________/| \n"
           "\t||                                      || \n"
           "\t||          %^RED%^POR ORDEN DEL REY%^RESET%^           || \n"
           "\t||                                      || \n"
           "\t||   -- Se prohibe el acceso a este     || \n"
           "\t||      castillo so pena de muerte.     || \n"
           "\t||                                      || \n"
           "\t||   -- Cualquier ser que intente       || \n"
           "\t||      salir del castillo sera         || \n"
           "\t||      aniquilado sin piedad.          || \n"
           "\t||______________________________________|| \n"
           "\t|/______________________________________\\| \n\n");
  set_light (50);
  set_exit_color("red");
  add_exit("oeste", "/room/camino/caminito02", "road");
  add_exit("dentro", "/room/castillo_drakull/castillo00", "door");
  modify_exit("dentro", ({"function", "go_entrar"}));
	/* si usamos "function", "fn", "message", "$N no seke" sale What? 
	   cuando dewelve 0 la fn */
  //modify_exit("oeste", ({"function", "go_salir"}));
}

void reset()
{
	if (!guardia1) {
		guardia1 = clone_object("/room/castillo_drakull/npcs/guardia.c");
		guardia1->add_property("NO_BUDGE", 1);
		guardia1->move(this_object());
	}
	if (!guardia2) {
		guardia2 = clone_object("/room/castillo_drakull/npcs/guardia.c");
		guardia2->add_property("NO_BUDGE", 1);
		guardia2->move(this_object());
	}
	if (!guardia3) {
		guardia3 = clone_object("/room/castillo_drakull/npcs/guardia.c");
		guardia3->add_property("NO_BUDGE", 1);
		guardia3->move(this_object());
	}
	if (!guardia4) {
		guardia4 = clone_object("/room/castillo_drakull/npcs/guardia.c");
		guardia4->add_property("NO_BUDGE", 1);
		guardia4->move(this_object());
	}
	/* NO RULA, lo q tendria ke ser es ke
	TODOS atakasen a la vez, no esperar a proteger */
	/* do_protect es como usar el comando directamente,
	pa estos casos /std/living/protect.c, add_protecting(ob) 
	SIGUE SIN RULAR
	guardia1->add_protecting(guardia2);
	guardia1->add_protecting(guardia3);
	guardia1->add_protecting(guardia4);
	guardia2->add_protecting(guardia1);
	guardia2->add_protecting(guardia3);
	guardia2->add_protecting(guardia4);
	guardia3->add_protecting(guardia1);
	guardia3->add_protecting(guardia2);
	guardia3->add_protecting(guardia4);
	guardia4->add_protecting(guardia1);
	guardia4->add_protecting(guardia2);
	guardia4->add_protecting(guardia3);*/
}

void event_enter(object enterer, string message)
{
	// CHAPUCERO
	/* LOS PUTOS ZORRONES SIGUEN SIN DEFENDERSE
	if (guardia1) {
	if (guardia2)
	guardia1->add_protecting(guardia2);
	if (guardia3)
	guardia1->add_protecting(guardia3);
	if (guardia4)
	guardia1->add_protecting(guardia4);
	}
	if (guardia2) {
	if (guardia1)
	guardia2->add_protecting(guardia1);
	if (guardia3)
	guardia2->add_protecting(guardia3);
	if (guardia4)
	guardia2->add_protecting(guardia4);
	}
	if (guardia3) {
	if (guardia1)
	guardia3->add_protecting(guardia1);
	if (guardia2)
	guardia3->add_protecting(guardia2);
	if (guardia4)
	guardia3->add_protecting(guardia4);
	}
	if (guardia4) {
	if (guardia1)
	guardia4->add_protecting(guardia1);
	if (guardia2)
	guardia4->add_protecting(guardia2);
	if (guardia3)
	guardia4->add_protecting(guardia3);
	}
	AHORA RULA ESTO, NO HE PROBADO EL RESTO,
	PERO guardia.c ES MUY LISTO Y BUSCA A SUS
	COMPIS EN LA ROOM PARA AVISARLES DE QUE
	LE ATACAN, Y ELLOS SE AYUDAN.
	if (guardia1) {
	guardia1->do_command("proteger guardia 1");
	guardia1->do_command("proteger guardia 2");
	guardia1->do_command("proteger guardia 3");
	guardia1->do_command("proteger guardia 4");
	}
	if (guardia2) {	
	guardia2->do_command("proteger guardia 1");
	guardia2->do_command("proteger guardia 2");
	guardia2->do_command("proteger guardia 3");
	guardia2->do_command("proteger guardia 4");
	}
	if (guardia3) {
	guardia3->do_command("proteger guardia 1");
	guardia3->do_command("proteger guardia 2");
	guardia3->do_command("proteger guardia 3");
	guardia3->do_command("proteger guardia 4");
	}
	if (guardia4) {
	guardia4->do_command("proteger guardia 1");
	guardia4->do_command("proteger guardia 2");
	guardia4->do_command("proteger guardia 3");
	guardia4->do_command("proteger guardia 4");
	}*/
}

/* habria q modificar pa tener en cuenta lo de si ta escondido */

int go_entrar()
{
	/* suponemos q los wardias no se moveran, usar la property esa */
	if(guardia1 || guardia2 || guardia3 || guardia4) {
		notify_fail("Un Guardia Imperial se interpone en tu camino.\n");
		if (this_player()->query_hide_shadow()) {
			tell_room(this_object(), "Un Guardia Imperial descubre a "+this_player()->QCN+
			" intentando colarse en el castillo, pero le cierra el paso.\n", this_player());
			this_player()->dest_hide_shadow();
		}
		else
			tell_room(this_object(), "Cuando "+this_player()->QCN+
			" se dispone a entrar al castillo, un guardia se interpone en su camino.\n", this_player());
		return 0;
	}
	tell_object(this_player(), "Una oscura aura te rodea al entrar en el castillo.\n");
	tell_room(this_object(), this_player()->QCN+
		" es envuelto en una oscura aura al entrar en el castillo.\n", this_player());
	/*
	this_player()->move("/room/castillo_drakull/castillo00");
	this_player()->look_me();
	tell_room(ENV(this_player()), this_player()->query_short() +
		" llega desde fuera del castillo.\n", this_player());
	return 0; pa ke no haga lo q ia hemos fecho nos */
	return 1;
}

/* POR JASER */
int go_salir()
{
	return 1;
}
