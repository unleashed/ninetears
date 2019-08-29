//Vilat 30.01.2003

inherit "/std/guild";

string help() {
    	return "Los Khurgars son un gremio de guerreros Duergar "
    		"famosos por su fiereza en las batallas, aunque "
    		"mas de una vez un duergar, inmerso en su furia,"
    		" ha herido a un compa�ero. Los miembros del gremio"
    		" tienen la costumbre de seccionar la cabeza de "
    		"los enemigos mas duros que consiguen vencer, y "
    		"guardarla a modo de trofeo, o depositarla en la"
    		" sala de trofeos del guild.\n";
	}

void setup() {
    	set_name("turkhun");
    	set_short("Guerrero de Turkhun");
	set_long("Los Guerreros de Turkhun son un gremio de guerreros humanos, "
    		"famosos por su fiereza en las batallas, aunque "
    		"mas de una vez un humano, inmerso en su furia,"
    		" ha herido a un compa�ero. Los miembros del gremio"
    		" tienen la costumbre de seccionar la cabeza de "
    		"los enemigos mas duros que consiguen vencer, y "
    		"guardarla a modo de trofeo, o depositarla en la"
    		" sala de trofeos del guild.\n");
    	reset_get();

	set_needed_align(({ ({1,-1}),({0,-1}) })) ; // Legal malvado o Neutral malvado

    	add_guild_command("reparar",1);
    	add_guild_command("juzgar", 1);
  	add_guild_command("decapitar", 1);

	set_xp_cost(2200); // Coste basico de guerrero
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

//Aki las restricciones
int query_legal_armour(string str) {
	return 1;
	}

int query_legal_weapon(string str) { return 1; }


string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Khurgar novato";
			case 11..15:
				return "Khurgar iniciado";
			case 16..20:
				return "Khurgar avanzado";
			case 21..25:
				return "Khurgar de �lite";
			case 26..30:
				return "Capit�n Khurgar";
			case 31..35:
				return "H�roe Khurgar";
			case 36..40:
				return "Comandante Khurgar";
			case 41..45:
				return "General Khurgar";
			case 46..50:
				return "Se�or de los Khurgars";
			case 51..1000:
				return "%^BOLD%^BLACK%^Comandante Supremo%^RESET%^ de %^BOLD%^RED%^Keroon%^RESET%^";
			default:
				return "Bug";
			}
		}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Khurgar novata";
			case 11..15:
				return "Khurgar iniciada";
			case 16..20:
				return "Khurgar avanzada";
			case 21..25:
				return "Khurgar de �lite";
			case 26..30:
				return "Capitana Khurgar";
			case 31..35:
				return "Hero�na Khurgar";
			case 36..40:
				return "Comandante Khurgar";
			case 41..45:
				return "General Khurgar";
			case 46..50:
				return "Se�ora de los Khurgars";
			case 51..1000:
				return "%^BOLD%^BLACK%^Comandante Supremo%^RESET%^ de %^BOLD%^RED%^Keroon%^RESET%^";
			default:
				return "Bug";
			}
		}
	}


void new_levels(int lvl,object ob) {
  if(lvl==5) 
  {
     add_guild_command("esconderse", 1);
     tell_object(ob,"Tu experiencia te permite utilizar la habilidad de esconderse.");
   }
  else if(lvl==15)
  {
     add_guild_command("sigilar", 1);
     tell_object(ob,"Sientes como has adquirido la habilidad para sigilar.");
  }
      ::new_levels(lvl,ob);
}
                                       




