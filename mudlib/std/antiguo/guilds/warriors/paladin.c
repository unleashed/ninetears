// mirar el tema de cargar y formular a la vez.
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

string query_main_skill() { return "cha"; }

int query_skill_cost(string skill)
{
    return 0;
}

int query_ac(int level);

void start_player(object ob)
{
    if(!ob->query_creator())
    {
	object boo;
	boo = clone_object("/d/gremios/comandos/shadows/gob.c");
	boo->move(ob);
	ob->remove_property("fear");
	ob->remove_timed_property("fear");
	ob->add_static_property("psionic",(int)ob->query_level()*5);
	call_out("setup_gob",0,boo,ob);
    }
	// los paladines son tanketas! hay q hacerlo d forma q se
	// ponga tb al subir nivel -> query_ac(lvl)
	// mirar en parte ya que tb son tanketas por llevar escudos del 15
	ob->set_ac(query_ac(ob->query_level())); // pone la body_ac
	// ahora, que sientan la vida
//	if (!ob->query_static_property("sense_life"))
//		ob->add_static_property("sense_life", 1);
	// OLVIDAR HECHIZO SANAR/CURACION, ANYADIR COMANDO SANAR
	if (ob->query_spell("sanar")) {
		tell_object(ob, "Olvidas el hechizo Sanar.\n");
		ob->remove_spell("sanar");
	}
	if (ob->query_spell("palabra sagrada")) {
		tell_object(ob, "Olvidas el hechizo Palabra Sagrada.\n");
		ob->remove_spell("palabra sagrada");
	}
	if (!ob->query_known_command("sanar")) {
		tell_object(ob, "Aprendes el comando Sanar.\n");
		ob->add_known_command("sanar");
	}
	if (!ob->query_property("shield_hits")) {
		// palatas pegan con escudo
		ob->add_property("shield_hits", 1);
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
//    ::setup();
    set_name("paladin");
    set_short("Paladin");
    set_long("Los Paladines son los nobles artesanos de la lucha entre caballeros, "
             "su vida la dedican a proteger a los indefensos y ayudar a los desvalidos. "
             "En este gremio aprendes a formular conjuros protectores ya que los Lores "
             "tienen algunos poderes de Clerigo y saben luchar como el mas poderoso "
             "guerrero, pueden usar toda clase de armas y armaduras.\n");
    set_main_skill("cha");
    reset_get();

    add_guild_command("cargar",1);
  add_guild_command("juzgar", 1);
  add_guild_command("centrar", 1);
  add_guild_command("fix", 1);
  add_guild_command("sanar", 1);
  add_guild_command("repeler", 1);
}

/* ES NECESARIO?
void create()
  {
  ::create();
  set_main_skill("cha");
}*/

//int query_dice()         { return 12;   }
int query_hp_dice(object myp) { return 4;   }
int query_hp_min(object myp)  { return 6;   }
int query_gp_dice(object myp) { return 6;   }
int query_gp_min(object myp)  { return 5;   }
int query_thac0_step()   { return 6;    }
int query_ac(int level) {
	// nada de multiplicar * 1.5 o cosas asi, q luego la
	// ac sale 23.0000 por ejemplo, aunq solo es estetico
	return level;
}
int query_extr_str()    { return 1;    }
int query_bing()    { return 1;    }
int query_extra_con_bonus() { return 1; }

int query_advance_cost() { return 2000; }

string query_spell_directory() { return "/std/spells/paladin/"; }

int query_xp_cost() { return 2200; }

int query_legal_race(string race)
{
    switch(race)
    {
    case "Humano":
	case "Human":
	case "human":
	case "humano":
    case "Immortal":
    case "Inmortal":
	return 1;
    default:
	return 0;
    }
}


mixed query_legal_spheres()
{
    return ({ ({"paladin","mayor"}),
              ({"proteccion","mayor"}),
              ({"proteccion","menor"}),
              ({"resistencia","neutral"}),
              ({"tiempo","neutral"}),
             
           });
}

void set_gp(object ob)
{
    ob->set_max_gp(level+(int)ob->query_str()+(int)ob->query_con()/2+
      ob->query_wis());
}

void init()
{
    add_action("prohibit_attack","kill");
    add_action("prohibit_attack","matar");
    
    ::init();
}

int prohibit_attack(object arg)
{
    if(!arg) {return 0;}
    if(!find_living(arg)) {return 0;}
    if(find_living(arg)->query_alignment()<=0)
    {
	write("No puedes atacar!! Esto seria una deshonra al gremio!\n");
	return 1;
    }
    else return 0;
}

int query_legal_armour(string ignore) { return 1; }
int query_legal_weapon(string ignore) { return 1; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()*2;
  bon = ( bon<0 ? 0 : bon );

  return bon;
}

void on_death(object player, object killer) {
}

string query_title(object ob) {
	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
				return "Paje de la Luz";
			case 11..15:
				return "Heraldo de la Luz";
			case 16..20:
				return "Campeon de la Luz";
			case 21..25:
				return "Caballero de la Luz";
			case 26..30:
				return "Paladin de la Luz";
			case 31..35:
				return "Guardia Final de los Paladines";
			case 36..40:
				return "Senescal de la Luz";
			case 41..45:
				return "Alto Paladin de la Verdad";
			case 46..50:
				return "Evangelista del Bien";
			case 51..55:
				return "%^BOLD%^%^CYAN%^Arcangel %^RESET%^de la %^BOLD%^Luz%^RESET%^";
			case 56..60:
				return "%^BOLD%^%^CYAN%^Angel %^RESET%^de la %^BOLD%^Luz%^RESET%^";
			case 61..1000:
				return "%^BOLD%^%^CYAN%^Mesias %^RESET%^de la %^BOLD%^Luz %^RESET%^y la %^YELLOW%^Verdad%^RESET%^";
			default:
				return "Paladin Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Paje de la Luz";
			case 11..15:
				return "Heraldo de la Luz";
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
				return "Paladin Erronea";
		}
	}
}
