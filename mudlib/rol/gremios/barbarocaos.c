//Vilat 30.01.2003

inherit "/std/guild";

string help() {
    	return "Sin ayuda por el momento.\n";
	}

void setup() {
    	set_name("barbarocaos");
    	set_short("Barbaro del Caos");
	set_long(help());
    	reset_get();

	set_needed_align(({ ({-1,-1}) , ({0,-1}) })) ; // Caotico malvado o Neutral malvado

    	add_guild_command("curtir",1);
    	add_guild_command("despellejar", 1);
  	add_guild_command("furia", 1);
  	add_guild_command("cazar", 1);
  	add_guild_command("aplastar", 1);

	set_xp_cost(2200); // Coste basico de guerrero
	set_clase("guerrero");
	}

int query_legal_race(string race) {
	race=capitalize(race);
    	switch(race) {
    		case "Humano":
    		case "Dios":
    		case "Inmortal":
		return 1;
    		default:
		return 0;
    		}
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la raza '"+race+"'.\n");
	return 0;
	}

//Aki las restricciones
int query_legal_armour(string str) { // Se las tengo ke poner aun
	return 1;
	}

int query_legal_weapon(string str) { return 1; }


string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Servidor de la Tribu";
			case 11..15:
				return "Soldado de la Tribu";
			case 16..20:
				return "Guardian de la Tribu";
			case 21..25:
				return "Portador del estandarte de la Tribu";
			case 26..30:
				return "Jefe de la Tribu";
			case 31..35:
				return "Gran Jefe de la Tribu";
			case 36..40:
				return "Caudillo de la Tribu";
			case 41..45:
				return "Rey de la Tribu";
			case 46..50:
				return "Se�or de la Estepa";
			case 51..1000:
				return "%^BOLD%^BLACK%^Caudillo Oscuro%^RESET%^ de las %^BOLD%^Estepas%^RESET%^";
			default:
				return "Bug";
			}
		}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Servidora de la Tribu";
			case 11..15:
				return "Soldado de la Tribu";
			case 16..20:
				return "Guardiana de la Tribu";
			case 21..25:
				return "Portadora del Estandarte de la Tribu";
			case 26..30:
				return "Jefa de la Tribu";
			case 31..35:
				return "Gran Jefa de la Tribu";
			case 36..40:
				return "Caudilla de la Tribu";
			case 41..45:
				return "Reina de la Tribu";
			case 46..50:
				return "Se�ora de la Estepa";
			case 51..1000:
				return "%^BOLD%^BLACK%^Caudilla Oscura%^RESET%^ de las %^BOLD%^Estepas%^RESET%^";
			default:
				return "Bug";
			}
		}
	}