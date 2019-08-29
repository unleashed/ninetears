inherit "/std/guild";

string help()
{
    return "Los Trolls son unos seres que viven en los bosques, grandes y de mal olor, "
	    "son tremendamente violentos con todo lo que les rodea, a lo que ayuda el "
	    "ser extremadamente fuertes, y tener una complexion grande. Aunque les gustan las "
	    "armas, son bastante torpes usandolas, y las tienen mas como tesoro que como arma en si "
	    "lo que hace que no entrenen y no sepan usar la mayoria de ellas.\n";
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
    set_name("troll");
    set_short("Troll");
    set_long("Los Trolls son unos seres que viven en los bosques, grandes y de mal olor, "
	     "son tremendamente violentos con todo lo que les rodea, a lo que ayuda el "
	     "ser extremadamente fuertes, y tener una complexion grande. Aunque les gustan las "
	     "armas, son bastante torpes usandolas, y las tienen mas como tesoro que como arma en si "
	     "lo que hace que no entrenen y no sepan usar la mayoria de ellas.\n");
    set_main_skill("str");
    reset_get();

  add_guild_command("remolino",1);
  add_guild_command("cargar",1);
  add_guild_command("juzgar", 1);
  add_guild_command("centrar", 1);
  add_guild_command("fix", 1);
  }


//int query_dice()         { return 12;   }
int query_hp_dice(object myp) { return 3;   }
int query_hp_min(object myp)  { return 7;   }
int query_gp_dice(object myp) { return 5;   }
int query_gp_min(object myp)  { return 4;   }
int query_thac0_step()   { return 3;    }
/*int query_ac(int level) {
	 nada de multiplicar * 1.5 o cosas asi, q luego la
	 ac sale 23.0000 por ejemplo, aunq solo es estetico
	return level;
}*/
int query_extr_str()    { return 1;    }
int query_bing()    { return 1;    }
int query_extra_con_bonus() { return 1; }

int query_advance_cost() { return 2500; }


int query_xp_cost() { return 2500; }

int query_legal_race(string race)
{
    switch(race)
    {
    case "troll":
    case "Troll":
    case "Immortal":
    case "Inmortal":
	return 1;
    default:
	return 0;
    }
}



int query_legal_armour(string type) {
	        switch(type) {
	                case "banded mail":
	                case "banded":
	                //case "bracers":
	                case "chain mail":
	                case "chain":
	                case "chainmail":
		        case "bronze plate":
                        case "elfin chain":
	                case "field plate":
	                case "dwarf plate":
	                case "full plate":
	                case "plate mail":
	                case "plate":
	                case "ring mail":
	                case "helm":
	                //case "helmet":
	                //case "basinet":
	                case "cowl":
 	                //case "great helm":
	                //case "full helm":
	                //case "visored helm":
	                case "gauntlets":
	                return 0;
	                default:
	                return 1;
          }
}






// ligeras restricciones por aqui...
//int query_legal_armour(string ignore) { return 1; }
int query_legal_weapon(string ignore) { return 1; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()*2;
  bon = ( bon<0 ? 0 : bon );

  return bon;
}

void on_death(object player, object killer) {

        write("Un troll ha sido derrotado!!! \n");
//        killer->add_timed_property("",2,300);

}

string query_title(object ob) {
//	if (ob->query_gender() == 1) {
		switch(ob->query_level()) {
			case 0..10:
                                return "el Pulidor de Rocas";
			case 11..15:
                                return "el Lanzador de Rocas";
			case 16..20:
                                return "el Guerrero Petreo";
			case 21..25:
                                return "el Adorador del Mehenir";
			case 26..30:
                                return "Troll 26-30";
			case 31..35:
				return "Troll 31-35";
			case 36..40:
				return "Troll 36-40";
			case 41..45:
				return "Troll 41-45";
			case 46..50:
				return "Troll 46-50";
			case 51..55:
			case 56..60:
			case 61..1000:
				return "%^BOLD%^%^RED%^Troll Muy tocho %^RESET%^";
			default:
				return "Troll Erroneo";
		}
/*	}
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
	*/
}
