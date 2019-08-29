//.oO JaDe Oo.  Enero'03

inherit "/std/guild";

string help() {
    	return "Los Caballeros de JaDe son poderosos guerreros cuya �nica misi�n es servir "
             "y proteger a su Diosa, ya sea con su vida o con su muerte. No s�lo son "
             "diestros con las armas, tienen la habilidad de canalizar el poder de su "
             "fe y usarlo a modo de ataque mediante devastadores conjuros y c�nticos. "
             "Como caballeros se rigen por un c�digo de honor y lealtad, pero no lo "
             "olvides... Son avatares del Caos.\n";
	}

void setup() {
    	set_name("caballero de jade");
    	set_short("Caballero de JaDe");
	set_long("Los Caballeros de JaDe son poderosos guerreros cuya �nica misi�n es servir "
             "y proteger a su Diosa, ya sea con su vida o con su muerte. No s�lo son "
             "diestros con las armas, tienen la habilidad de canalizar el poder de su "
             "fe y usarlo a modo de ataque mediante devastadores conjuros y c�nticos. "
             "Como caballeros se rigen por un c�digo de honor y lealtad, pero no lo "
             "olvides... Son avatares del Caos.\n");
    	reset_get();

	set_needed_align(({ ({1,-1}),({1,-1}) })) ; // Legal malvado 

    	add_guild_command("reparar",1);
    	add_guild_command("juzgar", 1);
  	add_guild_command("cargar", 1);
  	add_guild_command("golpeescudo", 1);
  	add_guild_command("drenar", 1);

	set_xp_cost(2200); // Coste b�sico de guerrero
	set_clase("guerrero");
	}

int query_legal_race(string race) {
	race=capitalize(race);
    	switch(race) {
    		case "Humano":
    		case "Immortal":
    		case "Inmortal":
		return 1;
    		default:
		return 0;
    		}
	log_file("fallos_gremios","Error en el Gremio "+TO->query_name()+": No se pudo procesar la raza '"+race+"'.\n");
	return 0;
	}

//Aqu� las restricciones
int query_legal_armour(string str) {
	return 1;
	}

int query_legal_weapon(string str) { return 1; }


string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Caballero de las Sombras";
			case 11..15:
				return "Campe�n de la Oscuridad";
			case 16..20:
				return "Heraldo de las Tormentas";
			case 21..25:
				return "Portador de la Muerte";
			case 26..30:
				return "Protector de Vingardtur";
			case 31..35:
				return "Guardi�n del Trono del Caos";
			case 36..40:
				return "Senescal de las Tinieblas";
			case 41..45:
				return "Corruptor de Almas";
			case 46..50:
				return "%^BOLD%^%^BLUE%^Cardenal %^RESET%^de la %^BOLD%^%^BLACK%^Misa Negra%^RESET%^";
			case 51..55:
				return "%^BOLD%^%^BLACK%^Mal�fico %^WHITE%^Se�or %^RESET%^de la %^BOLD%^%^BLACK%^Oscuridad%^RESET%^";
			case 56..60:
				return "%^BOLD%^%^RED%^Principe %^RESET%^de las %^BOLD%^%^BLACK%^Tinieblas%^RESET%^";
			case 61..1000:
				return "Elegido de %^BOLD%^%^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^";
			default:
				return "BUG";
			}
		}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Lady de las Sombras";
			case 11..15:
				return "Campeona de la Oscuridad";
			case 16..20:
				return "Heraldo de las Tormentas";
			case 21..25:
				return "Portadora de la Muerte";
			case 26..30:
				return "Protectora de Vingardtur";
			case 31..35:
				return "Guardiana del Trono del Caos";
			case 36..40:
				return "Senescal de las Tinieblas";
			case 41..45:
				return "Corruptora de Almas";
			case 46..50:
				return "%^BOLD%^%^BLUE%^Cardenal %^RESET%^de la %^BOLD%^%^BLACK%^Misa Negra%^RESET%^";
			case 51..55:
				return "%^BOLD%^%^BLACK%^Mal�fica %^WHITE%^Senyora %^RESET%^de la %^BOLD%^%^BLACK%^Oscuridad%^RESET%^";
			case 56..60:
				return "%^BOLD%^%^RED%^Princesa %^RESET%^de las %^BOLD%^%^BLACK%^Tinieblas%^RESET%^";
			case 61..1000:
				return "Elegida de %^BOLD%^%^GREEN%^J%^RESET%^%^GREEN%^aDe%^RESET%^";
			default:
				return "BUG";
			}
		}
	}