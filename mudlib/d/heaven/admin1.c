inherit"/std/room.c";

void setup() {
	set_short("Pasillo de la %^RED%^BOLD%^Zona Administrativa%^RESET%^");
	set_long(query_short()+"\nEstas en el pasillo de la Zona Administrativa, donde varios criados corretean llevando papeles de unas oficinas a otras. Al norte se encuentra la Oficina Postal del Paraiso. Una puerta al este conduce a la Biblioteca de los Dioses, mientras que otra al sur lleva a la concurrida Oficina de Quests.\n");

	add_exit("norte","/room/admin/mail_room","door");
	add_exit("sur","/room/admin/quests","door");
	add_exit("este","/d/heaven/admin2","corridor");
	add_exit("oeste","/d/heaven/biblioteca","door");
	set_light(100);
	}

