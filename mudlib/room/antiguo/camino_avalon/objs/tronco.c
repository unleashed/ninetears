inherit "/obj/weapon";

void setup() {
	set_base_weapon("club");
	set_weight(4000);
	set_name("tronco de arbol");
	set_short("Tronco de arbol");
	set_long("Un enorme tronco de arbol, pesado y grueso, necesita "
	         "de una fuerza inimaginable para ser usado como arma, "
		 "en cuyo caso seria algo que temer.\n");
	add_alias("tronco");
	set_main_plural("Troncos de arbol");
	add_plural("troncos");
	set_twohanded(1);
	add_property("nosteal", 1); // esto si ke no puede ser robado :)
}

int query_damage_roll()
{
	return roll(5, 10) + 5;
}

/*
mixed *calcular_critico(int danio, object me, object him)
{
	tell_object(me, "calculando critico\n");
	tell_object(TP, "calculando critico\n");
	return ({danio*2, "critical",});
}
*/

void write_message(string happen, int dam, string w_type, object me, object him)
{
	if (happen == "miss")
	{
		tell_room(ENV(me), me->QCN + " no consigue impactar en "+him->QCN+" con su gran "+w_type+".\n", ({me,him}));
		tell_object(me, "# "+him->QCN+" esquiva habilmente tu ataque.\n");
		tell_object(him, "* Esquivas habilmente el ataque de "+me->QCN+".\n");
		return;
	}

	if (dam < 0) {
		tell_room(ENV(me), me->QCN+" no produce danyo a "+him->QCN+".\n", ({me,him}));
		tell_object(me, "# No produces danyo a "+him->QCN+".\n");
		tell_object(him, "* "+me->QCN+" no te provoca danyos con su golpe.\n");
		return;
	}

	if (happen == "critical")
	{
		tell_room(ENV(me), me->QCN+" eleva con furia su "+w_type+" para descargarlo mortalmente sobre "+him->QCN+".\n",({me,him}));
		tell_object(me, "Elevas tu "+w_type+" furiosamente para descargarlo con todas tus fuerzas sobre "+him->QCN+".\n");
		tell_object(him, "Los musculos de "+me->QCN+" parecen agrandarse al elevar su "+w_type+" para descargarlo sobre ti!\n");
	}
	
	
	switch(dam) {
		case 0:
		tell_room(ENV(me), me->QCN + " golpea con su "+w_type+" a "+him->QCN+" sin producirle danyo.\n", ({me,him}));
		tell_object(me, "# Golpeas a "+him->QCN+" sin producirle danyo.\n");
		tell_object(him, "* "+me->QCN+" te golpea con su "+w_type+" sin romperte nada.\n");
		break;
		case 1..15:
		tell_room(ENV(me), me->QCN + " golpea levemente a "+him->QCN+" con su "+w_type+".\n", ({me,him}));
		tell_object(me, "# Golpeas levemente a "+him->QCN+" con tu "+w_type+".\n");
		tell_object(him, "* * "+me->QCN+" te alcanza con un pequenyo golpe con su "+w_type+".\n");
		break;
		case 16..25:
		tell_room(ENV(me), me->QCN + " golpea el brazo de "+him->QCN+" con su "+w_type+" dejandoselo dolorido.\n", ({me,him}));
		tell_object(me, "# Golpeas el brazo de "+him->QCN+" dejandoselo dolorido.\n");
		tell_object(him, "* * "+me->QCN+" te golpea el brazo con su "+w_type+" dejandotelo dolorido.\n");
		break;
		case 26..38:
		tell_room(ENV(me), me->QCN + " golpea fuertemente la pierna de "+him->QCN+" con su "+w_type+".\n", ({me,him}));
		tell_object(me, "# Llevas tu "+w_type+" a golpear fuertemente la pierna de "+him->QCN+".\n");
		tell_object(him, "* * "+me->QCN+" guia su "+w_type+" hacia tu pierna golpeandotela con fuerza.\n");
		break;
		case 39..49:
		tell_room(ENV(me), me->QCN + " impacta brutalmente con su "+w_type+" en el pecho de "+him->QCN+" cortandole la respiracion.\n", ({me,him}));
		tell_object(me, "# Dejas sin respiracion a "+him->QCN+" al impactar brutalmente en su pecho.\n");
		tell_object(him, "* * "+me->QCN+" te corta la respiracion al impactar con su "+w_type+" en tu pecho.\n");
		break;
		case 50..59:
		tell_room(ENV(me), "El "+w_type+" de "+me->QCN + " golpea con furia la espalda de "+him->QCN+" provocandole una fuerte conmocion.\n", ({me,him}));
		tell_object(me, "# Tu "+w_type+" golpea con furia la espalda de "+him->QCN+" provocandole una fuerte conmocion.\n");
		tell_object(him, "* * El "+w_type+" de "+me->QCN+" te golpea furiosamente en la espalda provocandote un enorme dolor.\n");
		break;
		case 60..70:
		tell_room(ENV(me), "Escuchas el sonido que producen algunas de las costillas de "+him->QCN+" al quebrarse bajo el impacto de "+me->QCN+".\n", ({me,him}));
		tell_object(me, "# Las costillas de "+him->QCN+" ceden bajo la presion de tu "+w_type+" en su costado.\n");
		tell_object(him, "* * Escuchas alguna de tus costillas quebrar cuando "+me->QCN+" te golpea salvajemente en el costado.\n");
		break;
		case 71..90:
		tell_room(ENV(me), me->QCN+" impacta de manera brutal en el craneo de "+him->QCN+" hundiendoselo entre los hombros.\n", ({me,him}));
		tell_object(me, "# Hundes bestialmente el craneo de "+him->QCN+" entre sus hombros.\n");
		tell_object(him, "* * Tu cabeza parece estallar cuando "+me->QCN+" impacta de lleno sobre ella hundiendotela entre los hombros.\n");
		break;
		default:
		tell_room(ENV(me), "Un horror pocas veces imaginado te asalta al observar como "+me->QCN+" por poco arranca la cabeza de "+him->QCN+" de un poderoso y mortal golpe de su "+w_type+".\n", ({me,him}));
		tell_object(me, "# La cabeza de "+him->QCN+" se tambalea y su cuello quiebra al golpearle mortifera y rabiosamente.\n");
		tell_object(him, "* * Tu cuello quiebra, tu cabeza se tambalea, y ves la muerte de cerca al recibir el salvaje impacto de "+me->QCN+".\n");
	}
}
