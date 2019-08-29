inherit "/obj/armour";

#define DANYO 3

int extr = 0;

void setup()
  {
  set_base_armour("bracers"); // poner a cinturon

  set_name("cinturon prisma");
  add_alias(({"cinturon","prisma"}));
  set_short("Cinturon Prisma");

  set_main_plural("Cinturones Prisma");
  add_plural(({"cinturones","prismas"}));
  set_long("Observas el cinturon, y la luz se divide a traves "
	"forma prismatica. Hueles poder, sientes poder.\n");
  set_armour_type_name("cintura");
	//set_enchant(1);
}

void set_owner(object pl)
{
	//add_property("duenyo", pl->QCN);
	// en las omiqs continuas no mola tener que ir a por
	// tu ogro otra vez cada vez que te lo quitan
	// por ahora deja de ser personal
}

int set_in_use(int i, object miamo)
{
	if (!miamo) {
		tell_object(TP, "Avisa a un inmortal sobre el objeto "+query_short()+".\n");
		return ::set_in_use(i);
	}
	if (i) {
	// si ponemos esto en un npc y entramos en su room,
	// SI no estaba cargado y DEBIDO a nuestra entrada se equipa,
	// TP es el player no el npc.
	// por ello habra que usar el parametro extra de set_in_use()
	// que sera el objeto que esta haciendo el equip realmente.

	/* DEJA DE SER PERSONAL
	if (query_property("duenyo") != miamo->QCN) {
		tell_object(miamo, "El "+TO->query_short()+" arde en tu brazo.\n");
		miamo->really_adjust_hp(-random(10) - 2);
		return 0;
	}
	*/
		miamo->adjust_tmp_damage_bon(DANYO);
	}
	else
	{
		miamo->adjust_tmp_damage_bon(-DANYO);
	}
	return ::set_in_use(i, miamo);
}
