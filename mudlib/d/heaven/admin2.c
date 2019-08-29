inherit"/std/room.c";

void setup() {
	set_short("Pasillo de la %^RED%^BOLD%^Zona Administrativa%^RESET%^");
	set_long(query_short()+"\nEstas en el pasillo de la Zona Administrativa, donde varios criados corretean llevando papeles de unas oficinas a otras. Al norte se encuentra la sala comun, mientras que una puerta al sur conduce al Despacho de Desarrollo, donde estan las novedades de la mudlib. Vilat ha excavado un nuevo despacho, que controla las Regencias y Patronajes, hacia abajo.\n");

	add_exit("norte","/w/common","corridor");
	add_exit("sur","/room/admin/development","door");
	add_exit("este","/d/heaven/admin3","corridor");
	add_exit("oeste","/d/heaven/admin1","corridor");
	add_exit("abajo","/room/admin/pat-reg_control","stair");
	}

