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

string query_main_skill() { return "str"; }

int query_skill_cost(string skill)
{
    return 0;
}

int query_ac(int level);

void start_player(object ob)
{
//    if(!ob->query_creator())
//    {
	object boo;
	boo = clone_object("/d/gremios/comandos/shadows/barbaros.c");
	boo->move(ob);
	//ob->remove_property("fear");
	//ob->remove_timed_property("fear");
	//ob->add_static_property("psionic",(int)ob->query_level()*5);
	call_out("setup_gob",0,boo,ob);
//    }
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
    set_name("barbaro");
    set_short("Barbaro");
    set_long("Los Paladines son los nobles artesanos de la lucha entre caballeros, "
             "su vida la dedican a proteger a los indefensos y ayudar a los desvalidos. "
             "En este gremio aprendes a formular conjuros protectores ya que los Lores "
             "tienen algunos poderes de Clerigo y saben luchar como el mas poderoso "
             "guerrero, pueden usar toda clase de armas y armaduras.\n");
    set_main_skill("str");
    reset_get();

    add_guild_command("golpear",1);
    // debere considerar si dejar que el golpear no se rompa en movimiento
  add_guild_command("juzgar", 1);
  add_guild_command("centrar", 1);
  add_guild_command("fix", 1);
//  add_guild_command("jugadasucia", 1); aun no esta lista
}

/* ES NECESARIO?
void create()
  {
  ::create();
  set_main_skill("str");
}*/

//int query_dice()         { return 12;   }
int query_hp_dice(object myp) { return 4;   }
int query_hp_min(object myp)  { return 7;   }
int query_gp_dice(object myp) { return 6;   }
int query_gp_min(object myp)  { return 6;   }
int query_thac0_step()   { return 6;    }
/*int query_ac(int level) {
	 nada de multiplicar * 1.5 o cosas asi, q luego la
	 ac sale 23.0000 por ejemplo, aunq solo es estetico
	return level;
}*/
int query_extr_str()    { return 1;    }
int query_bing()    { return 1;    }
int query_extra_con_bonus() { return 1; }

int query_advance_cost() { return 2000; }

//string query_spell_directory() { return "/std/spells/paladin/"; }

int query_xp_cost() { return 2200; }

int query_legal_race(string race)
{
    switch(race)
    {
    case "Orco":
	case "Orc":
	case "orco":
	case "orc":
    case "Immortal":
    case "Inmortal":
	return 1;
    default:
	return 0;
    }
}

/*
mixed query_legal_spheres()
{
    return ({ ({"paladin","mayor"}),
              ({"proteccion","mayor"}),
              ({"proteccion","menor"}),
              ({"resistencia","neutral"}),
              ({"tiempo","neutral"}),
             
           });
}
*//*
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
*/

// ligeras restricciones por aqui...
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
				return "Esclavo de Clan";
			case 11..15:
				return "Soldado de Clan";
			case 16..20:
				return "Guardian de Clan";
			case 21..25:
				return "Lider de Patrulla";
			case 26..30:
				return "Triturador de Enanos";
			case 31..35:
				return "Aniquilador de Cohortes";
			case 36..40:
				return "Temido Barbaro del Norte";
			case 41..45:
				return "Senyor de la Guerra del Norte";
			case 46..50:
				return "Conquistador de Reinos";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^%^RED%^Caudillo Sangriento %^RESET%^del %^BOLD%^Norte%^RESET%^";
			default:
				return "Barbaro Erroneo";
		}
	}
	else {
		switch(ob->query_level()) {
			case 0..10:
				return "Esclava de Clan";
			case 11..15:
				return "Soldado de Clan";
			case 16..20:
				return "Guardiana de Clan";
			case 21..25:
				return "Lider de Patrulla";
			case 26..30:
				return "Trituradora de Enanos";
			case 31..35:
				return "Aniquiladora de Cohortes";
			case 36..40:
				return "Temida Barbaro del Norte";
			case 41..45:
				return "Senyora de la Guerra del Norte";
			case 46..50:
				return "Conquistadora de Reinos";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^%^RED%^Caudilla Sangrienta %^RESET%^del %^BOLD%^Norte%^RESET%^";
			default:
				return "Barbara Erronea";
		}
	}
}
