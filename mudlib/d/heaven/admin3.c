inherit "/std/room.c";

void setup() {
	set_short("Pasillo de la %^RED%^BOLD%^Zona Administrativa%^RESET%^");
	set_long(query_short()+"\nEstas en el pasillo de la Zona Administrativa, donde varios criados corretean llevando papeles de unas oficinas a otras. Al norte esta la Oficina de Dominios, al sur una puerta lleva a la Oficina de Admisiones, y por ultimo otra al este conduce a la Oficina de Permisos.\n");

	add_exit("norte","/room/admin/domain_control","door");
	add_exit("sur","/room/admin/site_control","door");
	add_exit("este","/room/admin/access_control","door");
	add_exit("oeste","/d/heaven/admin2","corridor");
	}

