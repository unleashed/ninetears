inherit "/std/guild";

string help()
{
    return "Los Paladines son los nobles artesanos de la lucha entre caballeros, "
           "su vida la dedican a proteger a los indefensos y ayudar a los desvalidos. "
           "En este gremio aprendes a formular conjuros protectores ya que los Lores "
           "tienen algunos poderes de Clerigo y saben luchar como el mas poderoso "
           "guerrero, pueden usar toda clase de armas y armaduras.\n";
    reset_get();
}

string query_main_skill() { return "wis"; }

int query_skill_cost(string skill)
{
    return 0;
}

void start_player(object ob)
{
    if(!ob->query_creator()) {
	if (ob->query_race() == "orco")
    	{
	object boo;
	boo = clone_object("/d/gremios/comandos/shadows/barbaro.c");
	boo->move(ob);
	call_out("setup_gob",0,boo,ob);
    	}
	else if (ob->query_race() == "hombre-lagarto")
    	{
	object boo;
	boo = clone_object("/d/gremios/comandos/shadows/lagarto.c");
	boo->move(ob);
	call_out("setup_gob",0,boo,ob);
    	}
    }
    ::start_player(ob);
    return ;
}

void setup_gob(object it, object him)
{
    if(it && him)
    {
	it->move(him);
	it->init();
    }
}

void setup()
{
//    ::setup(); ??
    set_name("shaman");
    set_short("Shaman");
    set_long("Los Paladines son los nobles artesanos de la lucha entre caballeros, "
             "su vida la dedican a proteger a los indefensos y ayudar a los desvalidos. "
             "En este gremio aprendes a formular conjuros protectores ya que los Lores "
             "tienen algunos poderes de Clerigo y saben luchar como el mas poderoso "
             "guerrero, pueden usar toda clase de armas y armaduras.\n");
    set_main_skill("wis");
    reset_get();

  add_guild_command("juzgar", 1);
  add_guild_command("fix", 1);
}

//int query_dice()         { return 12;   }
int query_hp_dice(object myp) { return 4;   }
int query_hp_min(object myp)  { return 6;   }
int query_gp_dice(object myp) { return 8;   }
int query_gp_min(object myp)  { return 5;   }
int query_thac0_step()   { return 3;    }
// int query_extr_str()    { return 1;    }
// int query_bing()    { return 1;    } pa ke esto?
// int query_extra_con_bonus() { return 1; }

int query_advance_cost() { return 1600; }

string query_spell_directory() { return "/d/gremios/hechizos/shaman/"; }

int query_xp_cost() { return 1600; }

int query_legal_race(string race)
{
    switch(race)
    {
    case "Orco":
	case "orco":
	case "Orc":
	case "orc":
	case "Goblin":
	case "goblin":
	case "Lizard-man":
	case "lizard-man":
	case "Hombre-lagarto":
	case "hombre-lagarto":
    case "Immortal":
    case "Inmortal":
	return 1;
    default:
	return 0;
    }
}


/*mixed query_legal_spheres()
{
    return ({ ({"paladin","mayor"}),
              ({"proteccion","mayor"}),
              ({"proteccion","menor"}),
              ({"resistencia","neutral"}),
              ({"tiempo","neutral"}),
             
           });
}*/

int query_legal_armour(string ignore) { return 1; }
int query_legal_weapon(string ignore) { return 1; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level();
  bon = ( bon<0 ? 0 : bon );

  return bon;
}

void on_death(object player, object killer) {
}

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Esclavo de los Espiritus";
			case 11..15:
				return "Invocador de Almas";
			case 16..20:
                                return "que Habla con los Espiritus";
			case 21..25:
                                return "Senyor de los Espectros y los Demonios";
			case 26..30:
                                return "Portador del Caos";
			case 31..35:
                                return "que Camina entre los Planos";
			case 36..40:
                                return "Guardian de los Ancestros";
			case 41..45:
                                return "Custodio del Libro Maldito de los Espectros";
			case 46..50:
                                return "Enviado del %^RED%^Infierno%^RESET%^";
                        case 51..1000:
                                return "%^BLACK%^BOLD%^Morbido %^RESET%^RED%^Demonio %^BLACK%^BOLD%^de los Dias Antiguos%^RESET%^";
			default:
				return "Shaman Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Esclava de los Espiritus";
			case 11..15:
				return "Invocadora de Almas";
			case 16..20:
				return "Campeona de la Luz";
			case 21..25:
				return "Amazona de la Luz";
			case 26..30:
				return "Paladin de la Luz";
			case 31..35:
				return "Guardia Final de los Paladines";
			case 36..40:
				return "Senescal de la Luz";
			case 41..45:
				return "Alta Paladin de la Verdad";
			case 46..50:
				return "Evangelista del Bien";
			case 51..55:
				return "%^BOLD%^%^CYAN%^Arcangel %^RESET%^de la %^BOLD%^Luz%^RESET%^";
			case 56..60:
				return "%^BOLD%^%^CYAN%^Angel %^RESET%^de la %^BOLD%^Luz%^RESET%^";
			case 61..1000:
				return "%^BOLD%^%^CYAN%^Mesias %^RESET%^de la %^BOLD%^Luz %^RESET%^y la %^YELLOW%^Verdad%^RESET%^";
			default:
				return "Shaman Erronea";
		}
	}
}
